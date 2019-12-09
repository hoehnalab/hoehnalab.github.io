#include "Statistics.h"

#include "Math.h"

#include <cmath>
#include <iostream>

//#include "DistributionChisq.h"
//#include "DistributionGamma.h"
//#include "DistributionNormal.h"
//#include "RbStatisticsHelper.h"
//#include "RbConstants.h"
//#include "RbMathFunctions.h"
//#include "RbMathLogic.h"


/*!
 * This function calculates the quantiles of a standard normal distribution.
 *
 * \brief Quantile of a standard normal distribution.
 * \param prob is the probability up to the quantile.
 * \return Returns quantile value.
 * \throws Does not throw an error.
 * \see Odeh, R. E. and J. O. Evans. 1974. The percentage points of the normal
 *      distribution. Applied Statistics, 22:96-97.
 * \see Wichura, M. J.  1988. Algorithm AS 241: The percentage points of the
 *      normal distribution. 37:477-484.
 * \see Beasley, JD & S. G. Springer. 1977. Algorithm AS 111: The percentage
 *      points of the normal distribution. 26:118-121.
 */
double Statistics::Normal::quantile(double p) {
    
    double a0 = -0.322232431088;
    double a1 = -1.0;
    double a2 = -0.342242088547;
    double a3 = -0.0204231210245;
    double a4 = -0.453642210148e-4;
    double b0 = 0.0993484626060;
    double b1 = 0.588581570495;
    double b2 = 0.531103462366;
    double b3 = 0.103537752850;
    double b4 = 0.0038560700634;
    double p1 = ( p < 0.5 ? p : 1.0 - p);
    if (p1 < 1e-20)
        return (-9999.0);
    double y = sqrt( log(1.0/(p1*p1)) );
    double z = y + ((((y*a4+a3)*y+a2)*y+a1)*y+a0) / ((((y*b4+b3)*y+b2)*y+b1)*y+b0);
    return ( p < 0.5 ? -z : z );
}

/*!
 * This function returns the quantile of a normal probability
 * distribution.
 *
 * \brief Natural quantile.
 * \param mu is the mean parameter of the normal.
 * \param sigma is the variance parameter of the normal.
 * \param p is the probability up to the quantile.
 * \return Returns the quantile.
 * \throws Does not throw an error.
 */
double Statistics::Normal::quantile(double mu, double sigma, double p)
{
    
    double z = Normal::quantile(p);
    double x = z * sigma + mu;
    return x;
}


/*!
 * This function calculates the probability density
 * for a gamma-distributed random variable.
 *
 * \brief Gamma probability density.
 * \param shape is the shape parameter of the gamma.
 * \param rate is the rate parameter of the gamma.
 * \param x is the gamma random variable.
 * \return Returns the probability density.
 * \throws Does not throw an error.
 */
double Statistics::Gamma::pdf(double shape, double rate, double x)
{
    
    return (pow(rate, shape) / Math::gamma(shape)) * pow(x, shape - 1.0) * exp(-x * rate);
}


/*!
 * This function calculates the probability density
 * for a gamma-distributed random variable.
 *
 * \brief Gamma probability density.
 * \param shape is the shape parameter of the gamma.
 * \param rate is the rate parameter of the gamma.
 * \param x is the gamma random variable.
 * \return Returns the probability density.
 * \throws Does not throw an error.
 */
double Statistics::Gamma::pdf(double shape, double rate, double x, bool isLog)
{
    
    return isLog ? pdf(shape, rate, exp(x)) : pdf(shape, rate, x);
}

/*!
 * This function calculates the natural log of the probability density
 * for a gamma-distributed random variable.
 *
 * \brief Natural log of gamma probability density.
 * \param shape is the shape parameter of the gamma.
 * \param rate is the rate parameter of the gamma.
 * \param x is the gamma random variable.
 * \return Returns the natural log of the probability density.
 * \throws Does not throw an error.
 */
double Statistics::Gamma::lnPdf(double shape, double rate, double x)
{
    
    return shape * log(rate) - Math::lnGamma(shape) + (shape - 1.0) * log(x) - x * rate;
}

/*!
 * This function calculates the cumulative probability
 * for a gamma-distributed random variable.
 *
 * \brief Gamma cumulative probability.
 * \param shape is the shape parameter of the gamma.
 * \param rate is the rate parameter of the gamma.
 * \param x is the gamma random variable.
 * \return Returns the cumulative probability.
 * \throws Does not throw an error.
 */
double Statistics::Gamma::cdf(double shape, double rate, double x)
{
    
    return Math::incompleteGamma( rate*x, shape, Math::lnGamma(shape) );
}

/*!
 * This function returns the quantile of a gamma probability
 * distribution.
 *
 * \brief Gamma quantile.
 * \param shape is the shape parameter.
 * \param rate is the rate parameter.
 * \param p is the probability up to the quantile.
 * \return Returns the quantile.
 * \throws Does not throw an error.
 */
double Statistics::Gamma::quantile(double shape, double rate, double p)
{
    
    //    return RbStatistics::ChiSquare::quantile(p, 2.0 * shape) / (2.0 * rate);
    return Statistics::Helper::pointChi2(p, 2.0 * shape) / (2.0 * rate);
}


//double Distribution::Gamma::rv(double shape, double rate, RandomNumberGenerator& rng)
//{
//
//    return (RbStatistics::Helper::rndGamma(shape, rng) / rate);
//}



double Statistics::Helper::pointChi2(double prob, double v)
{
    // Returns z so that Prob{x<z}=prob where x is Chi2 distributed with df
    // = v
    // RATNEST FORTRAN by
    // Best DJ & Roberts DE (1975) The percentage points of the
    // Chi2 distribution. Applied Statistics 24: 385-388. (AS91)
    
    double e = 0.5e-6, aa = 0.6931471805, p = prob;
    double ch, a, q, p1, p2, t, x, b, s1, s2, s3, s4, s5, s6;
    double epsi = .01;
    if ( p < 0.000002 || p > 1 - 0.000002)  {
        epsi = .000001;
    }
    // if (p < 0.000002 || p > 0.999998 || v <= 0) {
    //      throw new IllegalArgumentException("Arguments out of range p" + p + " v " + v);
    //  }
    double g = Math::lnGamma(v / 2);
    double xx = v / 2;
    double c = xx - 1;
    if (v < -1.24 * log(p)) {
        ch = pow((p * xx * exp(g + xx * aa)), 1 / xx);
        if (ch - e < 0) {
            return ch;
        }
    } else {
        if (v > 0.32) {
            x = Statistics::Normal::quantile(p, 0, 1);
            p1 = 0.222222 / v;
            ch = v * pow((x * sqrt(p1) + 1 - p1), 3.0);
            if (ch > 2.2 * v + 6) {
                ch = -2 * (log(1 - p) - c * log(.5 * ch) + g);
            }
        } else {
            ch = 0.4;
            a = log(1 - p);
            
            
            do {
                q = ch;
                p1 = 1 + ch * (4.67 + ch);
                p2 = ch * (6.73 + ch * (6.66 + ch));
                t = -0.5 + (4.67 + 2 * ch) / p1
                - (6.73 + ch * (13.32 + 3 * ch)) / p2;
                ch -= (1 - exp(a + g + .5 * ch + c * aa) * p2 / p1)
                / t;
            } while (fabs(q / ch - 1) - epsi > 0);
        }
    }
    do {
        q = ch;
        p1 = 0.5 * ch;
        t = Math::incompleteGamma(p1, xx, g);
        if ( t < 0 ) {
//            throw new RbException("Arguments out of range: t < 0");
            std::cout << "Arguments out of range: t < 0" << std::endl;
        }
        p2 = p - t;
        t = p2 * exp(xx * aa + g + p1 - c * log(ch));
        b = t / ch;
        a = 0.5 * t - b * c;
        
        s1 = (210 + a * (140 + a * (105 + a * (84 + a * (70 + 60 * a))))) / 420;
        s2 = (420 + a * (735 + a * (966 + a * (1141 + 1278 * a)))) / 2520;
        s3 = (210 + a * (462 + a * (707 + 932 * a))) / 2520;
        s4 = (252 + a * (672 + 1182 * a) + c * (294 + a * (889 + 1740 * a))) / 5040;
        s5 = (84 + 264 * a + c * (175 + 606 * a)) / 2520;
        s6 = (120 + c * (346 + 127 * c)) / 5040;
        ch += t
        * (1 + 0.5 * t * s1 - b
           * c
           * (s1 - b
              * (s2 - b
                 * (s3 - b
                    * (s4 - b * (s5 - b * s6))))));
    } while (fabs(q / ch - 1) > e);
    
    return (ch);
    
}

