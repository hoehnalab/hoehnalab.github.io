#ifndef Math_h
#define Math_h

#include <stdio.h>
#include <vector>

namespace Math {
    

    double                      chebyshev_eval(double x, const double *a, const int n);
    double                      gamma(double x);                                                                //!< Calculate the Gamma function
    double                      incompleteGamma(double x, double alpha, double scale);                          //!< Xxx
    double                      lnGamma_sign(double a, int *sgn);                                               //!< Calculate the log of the Gamma function
    double                      lnGamma(double a);                                                              //!< Calculate the log of the Gamma function
    double                      lnGammacor(double x);
    double                      stirlerr(double n);
    double                      trunc(double x);                                                                //!< Truncate x
    
}


#endif /* Math_h */
