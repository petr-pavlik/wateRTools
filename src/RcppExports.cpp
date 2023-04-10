// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// HBV
S4 HBV(NumericVector date, NumericVector streamflow);
RcppExport SEXP _wateRTools_HBV(SEXP dateSEXP, SEXP streamflowSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type date(dateSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type streamflow(streamflowSEXP);
    rcpp_result_gen = Rcpp::wrap(HBV(date, streamflow));
    return rcpp_result_gen;
END_RCPP
}
// degree_day
NumericVector degree_day(NumericVector x);
RcppExport SEXP _wateRTools_degree_day(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(degree_day(x));
    return rcpp_result_gen;
END_RCPP
}
// sacsma
NumericVector sacsma(NumericVector& parameters, Function objective, NumericVector& precipitation, NumericVector& pet);
RcppExport SEXP _wateRTools_sacsma(SEXP parametersSEXP, SEXP objectiveSEXP, SEXP precipitationSEXP, SEXP petSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type parameters(parametersSEXP);
    Rcpp::traits::input_parameter< Function >::type objective(objectiveSEXP);
    Rcpp::traits::input_parameter< NumericVector& >::type precipitation(precipitationSEXP);
    Rcpp::traits::input_parameter< NumericVector& >::type pet(petSEXP);
    rcpp_result_gen = Rcpp::wrap(sacsma(parameters, objective, precipitation, pet));
    return rcpp_result_gen;
END_RCPP
}
// CFD
double CFD(NumericVector x);
RcppExport SEXP _wateRTools_CFD(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(CFD(x));
    return rcpp_result_gen;
END_RCPP
}
// FD0
double FD0(NumericVector& x);
RcppExport SEXP _wateRTools_FD0(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(FD0(x));
    return rcpp_result_gen;
END_RCPP
}
// SU25
double SU25(NumericVector& x);
RcppExport SEXP _wateRTools_SU25(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(SU25(x));
    return rcpp_result_gen;
END_RCPP
}
// ID0
double ID0(NumericVector& x);
RcppExport SEXP _wateRTools_ID0(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(ID0(x));
    return rcpp_result_gen;
END_RCPP
}
// TR20
double TR20(NumericVector& x);
RcppExport SEXP _wateRTools_TR20(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(TR20(x));
    return rcpp_result_gen;
END_RCPP
}
// WD
double WD(NumericVector& x);
RcppExport SEXP _wateRTools_WD(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(WD(x));
    return rcpp_result_gen;
END_RCPP
}
// TXx
double TXx(NumericVector& x);
RcppExport SEXP _wateRTools_TXx(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(TXx(x));
    return rcpp_result_gen;
END_RCPP
}
// RX1day
double RX1day(NumericVector& x);
RcppExport SEXP _wateRTools_RX1day(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(RX1day(x));
    return rcpp_result_gen;
END_RCPP
}
// RX5day
double RX5day(NumericVector& x);
RcppExport SEXP _wateRTools_RX5day(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(RX5day(x));
    return rcpp_result_gen;
END_RCPP
}
// PRCPTOT
double PRCPTOT(NumericVector& x);
RcppExport SEXP _wateRTools_PRCPTOT(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(PRCPTOT(x));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_wateRTools_HBV", (DL_FUNC) &_wateRTools_HBV, 2},
    {"_wateRTools_degree_day", (DL_FUNC) &_wateRTools_degree_day, 1},
    {"_wateRTools_sacsma", (DL_FUNC) &_wateRTools_sacsma, 4},
    {"_wateRTools_CFD", (DL_FUNC) &_wateRTools_CFD, 1},
    {"_wateRTools_FD0", (DL_FUNC) &_wateRTools_FD0, 1},
    {"_wateRTools_SU25", (DL_FUNC) &_wateRTools_SU25, 1},
    {"_wateRTools_ID0", (DL_FUNC) &_wateRTools_ID0, 1},
    {"_wateRTools_TR20", (DL_FUNC) &_wateRTools_TR20, 1},
    {"_wateRTools_WD", (DL_FUNC) &_wateRTools_WD, 1},
    {"_wateRTools_TXx", (DL_FUNC) &_wateRTools_TXx, 1},
    {"_wateRTools_RX1day", (DL_FUNC) &_wateRTools_RX1day, 1},
    {"_wateRTools_RX5day", (DL_FUNC) &_wateRTools_RX5day, 1},
    {"_wateRTools_PRCPTOT", (DL_FUNC) &_wateRTools_PRCPTOT, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_wateRTools(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
