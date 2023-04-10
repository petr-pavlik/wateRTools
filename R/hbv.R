#' HBV class 
#'
#' @slot values list. 
#' @slot parameters numeric. 
#'
#' @return
#' @export
#'
#' @examples
setClass("HBV", representation(values = "data.frame",
                               parameters = "numeric"))