`%out%` <- Negate(`%in%`)


#' Proxy function for downloading MOPEX data from the new.noaa website
#' @description This function downloads and prepares MOPEX datasets. 
#' it automatically changes -99 to NA as they are known to mark not assigned 
#' values.
#' @param id An 8-digits station number
#'
#' @return
#' @export
#'
#' @examples
mopex <- function(id = 12413500, product = "series") {
  
  switch (product,
    "series" = {
      require(tidyr)
      require(dplyr)
      require(readr)
      require(tidyselect)
      readr::read_fwf(file = paste("https://hydrology.nws.noaa.gov/pub/gcip/mopex/US_Data/Us_438_Daily/", 
                                   id, ".dly",
                                   sep = ""),
                        col_types = "cccddddd",
                        col_positions = readr::fwf_widths(
                          widths = c(4, 2, 2, rep(10, 5))),
                         na = c("", "NA", "-99")) |>  

        #tidyr::replace_na(replace = list(X4 = -99, X5 = -99, X6 = -99, X7 = -99, X8 = -99)) |>
        dplyr::mutate(X2 = if_else(nchar(X2) == 1, paste0("0", X2), paste(X2)),
                      X3 = if_else(nchar(X3) == 1, paste0("0", X3), paste(X3))) |> 
        dplyr::rename(year       = X1,
                      month      = X2,
                      day        = X3,
                      precip     = X4,
                      pet        = X5,
                      streamflow = X6,
                      tmax       = X7,
                      tmin       = X8) |> 
        tidyr::unite("date", year, month, day, sep = "-") |> 
        dplyr::mutate(date = as.Date(date))  |> 
        #mutate(across(where(is.character), as.numeric)) |> 
        #mutate_all(~ assign(tidyselect:::where(`==`(., -99)), 0)) |> 
        `attr<-`("class", c("mopex", "tbl_df", "tbl", "data.frame"))
      },
    "shapefile" = {
      require(sf)
      temp <- tempfile()
      download.file("https://hydrology.nws.noaa.gov/pub/gcip/mopex/US_Data/Basin_Boundaries/bdy.zip", temp)
      x <- sf::st_read(unz(temp, "temp.bdy"))
      unlink(temp)
      rm(temp)
    }
  )
}


# summary.mopex <- function(x = dt) {
#   dt |> 
#     mean(precip)
# }


#' List of MOPEX stations retrieval function
#'
#' @return
#' @export
#'
#' @examples
mopex_stations_list <- function() {
  require(httr)
  require(XML)
  require(dplyr)
  require(tidyr)
  require(purrr)
  
  XML::readHTMLTable(header = TRUE, 
    httr::content(as = "text",
      httr::GET("https://hydrology.nws.noaa.gov/pub/gcip/mopex/US_Data/Us_438_Daily/"))) |> 
    purrr::flatten() |> 
    tidyr::as_tibble(.name_repair = "unique") |> 
    dplyr::select(c(-1, -5)) |> 
    dplyr::filter(!dplyr::row_number() %in% c(1:2, dplyr::n())) |> 
    dplyr::rename(id = Name, origin = `Last modified`, size = Size)
}

#' Coefficients de Parde
#'
#' @param .data 
#' @param date 
#' @param discharge 
#'
#' @return
#' @export
#'
#' @examples
parde_coeff.data.frame <- function(.data, date, discharge) {
  require(tidyr)
  require(dplyr)
  .data |> 
    group_by(month(!!(date))) |> 
    mutate(mean(!!(discharge)))
}