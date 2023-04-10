// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Num.cpp: Rcpp R/C++ interface class library -- Rcpp Module example

#include <Rcpp.h>
#include <vector>

using namespace Rcpp;

//[[Rcpp::export]]
S4 HBV(NumericVector date, NumericVector streamflow) {
  S4 s4("HBV");
  
  s4.slot("values") = DataFrame::create( Named("date") = date, 
                                         Named("streamflow") = streamflow );
  
  NumericVector v = {1,2,3,4};
  
  
  // Set the number of rows and columns to attribute dim of the vector object.
  v.attr("dim") = Dimension(2, 2);
  
  
  // Return the vector to R
  return s4;
}

// [[Rcpp::export]]
NumericVector degree_day(NumericVector x) {
  NumericVector dd (x.length());
  return dd;
}
