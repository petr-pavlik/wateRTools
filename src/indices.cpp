#include <Rcpp.h>
using namespace Rcpp;

/**
 * A number of consecutive frost days
 */
// [[Rcpp::export]]
double CFD(NumericVector x) {
  double longest(0);
  double helper(0);
  
  for (int i = 0; i < x.length(); i++) {
    if (x[i] < 1) {
      helper++;
      if(helper > longest) longest = helper;
    } else {
      helper = 0;
    }
  }
  return longest;
}

/**
 * Annual count of frost days when TN(daily minimum temperature < 0 \circ C)
 */
// [[Rcpp::export]]
double FD0(NumericVector &x) {
  double count(0);
  
  for (int i{0}; i < x.size(); i++) {
    if (x[i] < 0) {
      count++;
    }
  }
  return count;
}



/**
 * Count of summer days when TX(daily maximum temperature > 25 \circ C)
 */
// [[Rcpp::export]]
double SU25(NumericVector &x) {
  double count(0);
  
  for (int i{0}; i < x.size(); i++) {
    if (x[i] < 0) {
      count++;
    }
  }
  return count;
}


/**
 * Count of ice days when TX(daily maximum temperature < 0 \circ C)
 */
// [[Rcpp::export]]
double ID0(NumericVector &x) {
  double count(0);
  
  for (int i{0}; i < x.size(); i++) {
    if (x[i] < 0) {
      count++;
    }
  }
  return count;
}

/**
 * Count of summer days when TN(daily maximum temperature > 20 \circ C)
 */
// [[Rcpp::export]]
double TR20(NumericVector &x) {
  double count(0);
  
  for (int i{0}; i < x.size(); i++) {
    if (x[i] < 0) {
      count++;
    }
  }
  return count;
}


/**
 * A number of wet days (Precipitation is more than 1)
 */
// [[Rcpp::export]]
double WD(NumericVector &x) {
  double count(0);
  
  for (int i{0}; i < x.size(); i++) {
    if (x[i] > 1) {
      count++;
    }
  }
  return count;
}

/**
 * Monthly maximum value of daily maxmimum temp C
 */
// [[Rcpp::export]]
double TXx(NumericVector &x) {
  double count(0);
  
  for (int i{0}; i < x.size(); i++) {
    if (x[i] > 1) {
      count++;
    }
  }
  return count;
}


/**
 * Monthly maximum value of 1-day maxmimum precipitation
 */
// [[Rcpp::export]]
double RX1day(NumericVector &x) {
  double max{x[0]};
  
  for (int i{0}; i < x.size(); i++) {
    if (x[i] > max) {
      max = x[i];
    }
  }
  return max;
}


/**
 * Monthly maximum value of 5-day maxmimum precipitation
 */
// [[Rcpp::export]]
double RX5day(NumericVector &x) {
  double max{0};
  double temp{0};
  
  for (int i{4}; i < x.size(); i++) {
    temp = x[i - 4] + x[i - 3] + x[i - 2] + x[i - 1] + x[i];
    if(temp > max) max = temp;
  }
  return max;
}


/**
 * Annual total wet-day precipitation
 */
// [[Rcpp::export]]
double PRCPTOT(NumericVector &x) {
  double sum(0);
  
  for (int i{0}; i < x.size(); i++) {
    if (x[i] > 1) {
      sum += x[i];
    }
  }
  return sum;
}
