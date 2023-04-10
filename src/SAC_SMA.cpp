#include <Rcpp.h>
#include <string>
using namespace Rcpp;

//[[Rcpp::export]]
NumericVector sacsma(NumericVector &parameters, 
                     Function objective, 
                     NumericVector &precipitation, 
                     NumericVector &pet) {
  NumericVector pars(parameters);
  NumericVector _pars = NumericVector::create(_["uztwm"] = pars[1],  // Upper zone tension water capacity [mm]
                                              _["uzfwm"] = pars[2],  // Upper zone free water capacity [mm]
                                              _["lztwm"] = pars[3],  // Lower zone tension water capacity [mm]
                                              _["lzfpm"] = pars[4],  // Lower zone primary free water capacity [mm]
                                              _["lzsfm"] = pars[5],  // Lower zone supplementary free water capacity [mm]
                                              _["uzk"]   = pars[6],  // Upper zone free water lateral depletion rate [1/day]
                                              _["lzpk"]  = pars[7],  // Lower zone primary free water depletion rate [1/day]
                                              _["lzsk"]  = pars[8],  // Lower zone supplementary free water depletion rate [1/day]
                                              _["zperc"] = pars[9],  // Percolation demand scale parameter [-]
                                              _["rexp"]  = pars[10], // Percolation demand shape parameter [-]
                                              _["pfree"] = pars[11], // Percolating water split parameter (decimal fraction) 
                                              _["pctim"] = pars[12], // Impervious fraction of the watershed area (decimal fraction)
                                              _["adimp"] = pars[13], // Additional impervious areas (decimal fraction)
                                              _["riva"]  = pars[14], // Riparian vegetation area (decimal fraction)
                                              _["side"]  = pars[15], // The ratio of deep recharge to channel base flow [-]
                                              _["rserv"] = pars[16]);// Fraction of lower zone free water not transferrable (decimal fraction)
  NumericVector TR(precipitation); // total runoff
  NumericVector SR; // surface runoff
  NumericVector BF; // baseflow
  double pr;
  double edmnd;
  double et1;
  double uztwc;
  double red;
  
  for(int i = 0;  i < precipitation.size(); i++) {
    pr = precipitation[i];
    edmnd = pet[i];
    et1 = edmnd * uztwc/parameters[0]; //uztwm
    red = edmnd - et1;  // residual ET demand
    uztwc = uztwc - et1;
    TR[i] = 1.15 * precipitation[i];
  }
  
  
  List L = List::create(_["pars"] = pars);
  return TR;
}

/*
 double uztwm  =  par[1];   // Upper zone tension water capacity [mm]
 double uzfwm  =  par[2];   // Upper zone free water capacity [mm]
 double lztwm  =  par[3];   // Lower zone tension water capacity [mm]
 double lzfpm  =  par[4];   // Lower zone primary free water capacity [mm]
 double lzfsm  =  par[5];   // Lower zone supplementary free water capacity [mm]
 double uzk    =  par[6];   // Upper zone free water lateral depletion rate [1/day]
 double lzpk   =  par[7];   // Lower zone primary free water depletion rate [1/day]
 double lzsk   =  par[8];   // Lower zone supplementary free water depletion rate [1/day]
 double zperc  =  par[9];   // Percolation demand scale parameter [-]
 double rexp   =  par[10];  // Percolation demand shape parameter [-]
 double pfree  =  par[11];  // Percolating water split parameter (decimal fraction)
 double pctim  =  par[12];  // Impervious fraction of the watershed area (decimal fraction)
 double adimp  =  par[13];  // Additional impervious areas (decimal fraction)
 double riva   =  par[14];  // Riparian vegetation area (decimal fraction)
 double side   =  par[15];  // The ratio of deep recharge to channel base flow [-]
 double rserv  =  par[16];  // Fraction of lower zone free water not transferrable (decimal fraction)
 */