#' Compute indicators based on hydroclimatic variables
#'
#' @description
#' Compute all climatological indices on a tsibble
#' 
#' @param data 
#' @param group 
#' @param daily_T_minimum 
#' @param daily_T_maximum 
#' @param precipitation 
#' @param streamflow 
#'
#' @import data.table
#' @importFrom rlang .data
#' @return data.frame of indices; grouped if provided
#' @export
#'
#' @examples
indices <- function(.data, 
                    group = NULL, 
                    daily_T_minimum = NULL, 
                    daily_T_maximum = NULL, 
                    precipitation = NULL, 
                    streamflow = NULL) {
  .data |> 
   .this(, `:=`(
     FD0    = FD0( !!(( daily_T_minimum )) ),
     CFD    = CFD( !!(( daily_T_minimum )) ),
     WD     = WD( !!(( precipitation )) ),
     TR20   = TR20( !!(( daily_T_maximum )) ),
     RX1day = RX1day( !!(( precipitation )) ),
     RX5day = RX5day( !!(( precipitation )) ),
     SU25   = SU25( !!(( daily_T_maximum )) ))
   )
  .data  
}



