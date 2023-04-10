library(wateRTools)
library(dplyr)
library(tidyr)
library(data.table)
library(rbenchmark)

.this <- `[`

x <- as.data.frame(mopex())
benchmark(replications = 1000,
  dt = {
    x <- as.data.table(x)
    x[, `:=`(precip = mean(precip), 
                   streamflow = mean(streamflow), 
                   tmax = mean(tmax), 
                   by = year(date))]
    x},
  mative_pipe_dt = {
    x <- as.data.table(x)
    x |> 
      .this(, `:=`(precip = mean(precip), 
                   streamflow = mean(streamflow), 
                   tmax = mean(tmax), 
                   by = year(date)))},
  magrittr_pipe_df = {
    x <- tidyr::as_tibble(x)
    x %>% 
      dplyr::select(precip, streamflow, date, tmax) %>% 
      dplyr::group_by(data.table::year(date)) %>% 
      dplyr::summarise(precip  = mean(precip), 
                       streamflow  = mean(streamflow), 
                       tmax  = mean(tmax))},
  native_pipe_dplyr = {
    x <- tidyr::as_tibble(x)
    x |> 
      dplyr::select(precip, streamflow, date, tmax) |> 
      dplyr::group_by(data.table::year(date)) |> 
      dplyr::summarise(precip  = mean(precip), 
                       streamflow  = mean(streamflow), 
                       tmax  = mean(tmax))}
)



x |> # native pipe operator is just faster than %>%, scoping does not work with ., _ only 
  group_by(date = data.table::year(date)) |> 
  wateRTools::indices(tmin = tmin, 
                      tmax = tmax, 
                      precipitation = precip, 
                      streamflow = streamflow)

x |> # native pipe operator is just faster than %>%, scoping does not work with ., _ only 
  as.data.table() |> 
  wateRTools::indices(daily_T_minimum = tmin, 
                      daily_T_maximum = tmax, 
                      precipitation = precip, 
                      streamflow = streamflow)


wateRTools::HBV()
