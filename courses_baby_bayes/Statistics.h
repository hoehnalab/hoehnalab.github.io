#ifndef Statistics_h
#define Statistics_h

#include <stdio.h>

namespace Statistics {
    
    
    namespace Normal {
        

        double                      quantile(double p);                                                     /*!< Normal(0,1) quantile */
        double                      quantile(double mu, double sigma, double p);                            /*!< Normal(mu,sigma) quantile */

    }
    
    
    namespace Gamma {
        
        double                      pdf(double a, double b, double x);                                    /*!< Gamma(a,b) probability density */
        double                      pdf(double a, double b, double x, bool isLog);                        /*!< Gamma(a,b) probability density */
        double                      lnPdf(double a, double b, double x);                                  /*!< Log of the Gamma(a,b) probability density */
        double                      cdf(double a, double b, double x);                                    /*!< Gamma(a,b) cumulative probability */
        double                      quantile(double a, double b, double p);                               /*!< Gamma(a,b) quantile */
        
    }
    
    namespace Helper {
        
        double                      pointChi2(double prob, double v);
    
    }
    
}

#endif /* Statistics_h */
