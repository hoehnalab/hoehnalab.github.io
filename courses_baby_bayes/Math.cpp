#include "Math.h"

#include "MathConstants.h"

#include <cmath>
#include <iostream>
#include <sstream>



double Math::chebyshev_eval(double x, const double *a, const int n)
{
    double b0, b1, b2, twox;
    int i;
    
    if (n < 1 || n > 1000)
    {
        std::cerr << "Cannot compute chebyshev function for n = " << n;
    }
    
    if (x < -1.1 || x > 1.1)
    {
        std::cerr << "Cannot compute chebyshev function for x = " << x;
    }
    
    twox = x * 2;
    b2 = b1 = 0;
    b0 = 0;
    for (i = 1; i <= n; i++)
    {
        b2 = b1;
        b1 = b0;
        b0 = twox * b1 - b2 + a[n - i];
    }
    return (b0 - b2) * 0.5;
}

/*!
 * This function calculates the gamma function for real x.
 *
 * \brief Gamma function.
 * \param x is the argument.
 * \return Returns the value of the gamma function.
 * \throws Does not throw an error.
 */
double Math::gamma(double x)
{
    const static double gamcs[42] = {
        +.8571195590989331421920062399942e-2,
        +.4415381324841006757191315771652e-2,
        +.5685043681599363378632664588789e-1,
        -.4219835396418560501012500186624e-2,
        +.1326808181212460220584006796352e-2,
        -.1893024529798880432523947023886e-3,
        +.3606925327441245256578082217225e-4,
        -.6056761904460864218485548290365e-5,
        +.1055829546302283344731823509093e-5,
        -.1811967365542384048291855891166e-6,
        +.3117724964715322277790254593169e-7,
        -.5354219639019687140874081024347e-8,
        +.9193275519859588946887786825940e-9,
        -.1577941280288339761767423273953e-9,
        +.2707980622934954543266540433089e-10,
        -.4646818653825730144081661058933e-11,
        +.7973350192007419656460767175359e-12,
        -.1368078209830916025799499172309e-12,
        +.2347319486563800657233471771688e-13,
        -.4027432614949066932766570534699e-14,
        +.6910051747372100912138336975257e-15,
        -.1185584500221992907052387126192e-15,
        +.2034148542496373955201026051932e-16,
        -.3490054341717405849274012949108e-17,
        +.5987993856485305567135051066026e-18,
        -.1027378057872228074490069778431e-18,
        +.1762702816060529824942759660748e-19,
        -.3024320653735306260958772112042e-20,
        +.5188914660218397839717833550506e-21,
        -.8902770842456576692449251601066e-22,
        +.1527474068493342602274596891306e-22,
        -.2620731256187362900257328332799e-23,
        +.4496464047830538670331046570666e-24,
        -.7714712731336877911703901525333e-25,
        +.1323635453126044036486572714666e-25,
        -.2270999412942928816702313813333e-26,
        +.3896418998003991449320816639999e-27,
        -.6685198115125953327792127999999e-28,
        +.1146998663140024384347613866666e-28,
        -.1967938586345134677295103999999e-29,
        +.3376448816585338090334890666666e-30,
        -.5793070335782135784625493333333e-31
    };
    
    int i, n;
    double y;
    double sinpiy, value;
    
    /* For IEEE double precision DBL_EPSILON = 2^-52 = 2.220446049250313e-16 :
     * (xmin, xmax) are non-trivial, see ./gammalims.c
     * xsml = exp(.01)*DBL_MIN
     * dxrel = sqrt(DBL_EPSILON) = 2 ^ -26
     */
# define ngam 22
# define xmin -170.5674972726612
# define xmax  171.61447887182298
# define xsml 2.2474362225598545e-308
# define dxrel 1.490116119384765696e-8
    
//    /* If the argument is exactly zero or a negative integer
//     * then return NaN. */
//    if (x == 0 || (x < 0 && x == (long)x))
//    {
//        std::ostringstream s;
//        s << "Cannot compute gamma function for x = " << x;
//        throw RbException(s.str());
//    }
    
    y = fabs(x);
    
    if (y <= 10) {
        
        /* Compute gamma(x) for -10 <= x <= 10
         * Reduce the interval and find gamma(1 + y) for 0 <= y < 1
         * first of all. */
        
        n = int(x);
        if (x < 0) --n;
        y = x - n;/* n = floor(x)  ==>    y in [ 0, 1 ) */
        --n;
        value = chebyshev_eval(y * 2 - 1, gamcs, ngam) + .9375;
        if (n == 0)
            return value;/* x = 1.dddd = 1+y */
        
        if (n < 0) {
            /* compute gamma(x) for -10 <= x < 1 */
            
            /* exact 0 or "-n" checked already above */
            
            /* The answer is less than half precision */
            /* because x too near a negative integer. */
            if (x < -0.5 && fabs(x - (int)(x - 0.5) / x) < dxrel) {
                std::cerr << "Cannot compute gamma function for x = " << x;
            }
            
            /* The argument is so close to 0 that the result would overflow. */
            if (y < xsml) {
                std::cerr << "Cannot compute gamma function for x = " << x;
            }
            
            n = -n;
            
            for (i = 0; i < n; i++) {
                value /= (x + i);
            }
            return value;
        }
        else {
            /* gamma(x) for 2 <= x <= 10 */
            
            for (i = 1; i <= n; i++) {
                value *= (y + i);
            }
            return value;
        }
    }
    else {
        /* gamma(x) for     y = |x| > 10. */
        
        if (x > xmax) {            /* Overflow */
            std::cerr << "Cannot compute gamma function for x = " << x;
        }
        
        if (x < xmin) {            /* Underflow */
            std::cerr << "Cannot compute gamma function for x = " << x;
        }
        
        if (y <= 50 && y == (int)y) { /* compute (n - 1)! */
            value = 1.;
            for (i = 2; i < y; i++) value *= i;
        }
        else { /* normal case */
            value = exp((y - 0.5) * log(y) - y + Constants::LN_SQRT_2PI +
                        ((2*y == (int)2*y)? stirlerr(y) : lnGammacor(y)));
        }
        if (x > 0)
            return value;
        
        if (fabs((x - (int)(x - 0.5))/x) < dxrel){
            
            /* The answer is less than half precision because */
            /* the argument is too near a negative integer. */
            std::cerr << "Cannot compute gamma function for x = " << x;
        }
        
        sinpiy = sin(Constants::PI * y);
        if (sinpiy == 0) {        /* Negative integer arg - overflow */
            std::cerr << "Cannot compute gamma function for x = " << x;
        }
        
        return -Constants::PI / (y * sinpiy * value);
    }
    
}



/*!
 * This function returns the incomplete gamma ratio I(x,alpha) where x is
 * the upper limit of the integration and alpha is the shape parameter.
 *
 * \brief Incomplete gamma function.
 * \param alpha is the shape parameter of the gamma.
 * \param x is the upper limit of integration.
 * \return Returns -1 if in error and the incomplete gamma ratio otherwise.
 * \throws Does not throw an error.
 * \see Bhattacharjee, G. P. 1970. The incomplete gamma integral. Applied
 *      Statistics, 19:285-287.
 */


double Math::incompleteGamma(double x, double alpha, double scale) {
    
    // (1) series expansion     if (alpha>x || x<=1)
    // (2) continued fraction   otherwise
    // RATNEST FORTRAN by
    // Bhattacharjee GP (1970) The incomplete gamma integral.  Applied Statistics,
    // 19: 285-287 (AS32)
    
    double accurate = 1e-8, overflow = 1e30;
    double factor, gin, rn, a, b, an, dif, term;
    double pn0, pn1, pn2, pn3, pn4, pn5;
    
    if (x == 0.0) {
        return 0.0;
    }
    if (x < 0.0 || alpha <= 0.0)
    {
        std::cerr << "Cannot compute incomplete gamma function for x = " << x << ", alpha = " << alpha << "and scale = " << scale;
    }
    
    factor = exp(alpha * log(x) - x - scale);
    
    if (x > 1 && x >= alpha) {
        // continued fraction
        a = 1 - alpha;
        b = a + x + 1;
        term = 0;
        pn0 = 1;
        pn1 = x;
        pn2 = x + 1;
        pn3 = x * b;
        gin = pn2 / pn3;
        
        do {
            a++;
            b += 2;
            term++;
            an = a * term;
            pn4 = b * pn2 - an * pn0;
            pn5 = b * pn3 - an * pn1;
            
            if (pn5 != 0) {
                rn = pn4 / pn5;
                dif = fabs(gin - rn);
                if (dif <= accurate) {
                    if (dif <= accurate * rn) {
                        break;
                    }
                }
                
                gin = rn;
            }
            pn0 = pn2;
            pn1 = pn3;
            pn2 = pn4;
            pn3 = pn5;
            if (fabs(pn4) >= overflow) {
                pn0 /= overflow;
                pn1 /= overflow;
                pn2 /= overflow;
                pn3 /= overflow;
            }
        } while (true);
        gin = 1 - factor * gin;
    } else {
        // series expansion
        gin = 1;
        term = 1;
        rn = alpha;
        do {
            rn++;
            term *= x / rn;
            gin += term;
        }
        while (term > accurate);
        gin *= factor / alpha;
    }
    return gin;
    
}

/*!
 * This function calculates the log of the gamma function, which is equal to:
 * Gamma(alp) = {integral from 0 to infinity} t^{alp-1} e^-t dt
 * The result is accurate to 10 decimal places. Stirling's formula is used
 * for the central polynomial part of the procedure.
 *
 * \brief Natural log of the gamma function.
 * \param alp is the parameter of the gamma function.
 * \return Returns the log of the gamma function.
 * \throws Does not throw an error.
 * \see Pike, M. C. and I. D. Hill. 1966. Algorithm 291: Logarithm of the gamma
 *      function. Communications of the Association for Computing Machinery, 9:684.
 *
 *    The new adoption from R 2.12.2:
 *
 *    The function lgammafn computes log|gamma(x)|.  The function
 *    lgammafn_sign in addition assigns the sign of the gamma function
 *    to the address in the second argument if this is not NULL.
 *
 *  NOTES
 *
 *    This routine is a translation into C of a Fortran subroutine
 *    by W. Fullerton of Los Alamos Scientific Laboratory.
 *
 *    The accuracy of this routine compares (very) favourably
 *    with those of the Sun Microsystems portable mathematical
 *    library.
 */
double Math::lnGamma_sign(double x, int *sgn)
{
    double ans, y, sinpiy;
    
#ifdef NOMORE_FOR_THREADS
    static double xmax = 0.;
    static double dxrel = 0.;
    
    if (xmax == 0) {/* initialize machine dependent constants _ONCE_ */
        xmax = d1mach(2)/log(d1mach(2));/* = 2.533 e305     for IEEE double */
        dxrel = sqrt (d1mach(4));/* sqrt(Eps) ~ 1.49 e-8  for IEEE double */
    }
#else
    /* For IEEE double precision DBL_EPSILON = 2^-52 = 2.220446049250313e-16 :
     xmax  = DBL_MAX / log(DBL_MAX) = 2^1024 / (1024 * log(2)) = 2^1014 / log(2)
     dxrel = sqrt(DBL_EPSILON) = 2^-26 = 5^26 * 1e-26 (is *exact* below !)
     */
#undef xmax
#define xmax  2.5327372760800758e+305
#define dxrel 1.490116119384765696e-8
#endif
    
    if (sgn != NULL) *sgn = 1;
    
    if (x < 0 && fmod(floor(-x), 2.) == 0)
        if (sgn != NULL) *sgn = -1;
    
    if (x <= 0 && x == Math::trunc(x)) { /* Negative integer argument */
        std::cerr << "Cannot compute log-gamma function for x = " << x;
    }
    
    y = fabs(x);
    
    if (y <= 10)
        return log(fabs(gamma(x)));
    /*
     ELSE  y = |x| > 10 ---------------------- */
    
    if (y > xmax) {
        std::cerr << "Cannot compute log-gamma function for x = " << x;
    }
    
    if (x > 0) { /* i.e. y = x > 10 */
#ifdef IEEE_754
        if (x > 1e17)
            return(x*(log(x) - 1.));
        else if (x > 4934720.)
            return(M_LN_SQRT_2PI + (x - 0.5) * log(x) - x);
        else
#endif
            return Constants::LN_SQRT_2PI + (x - 0.5) * log(x) - x + lnGammacor(x);
    }
    /* else: x < -10; y = -x */
    sinpiy = fabs(sin(Constants::PI * y));
    
    ans = Constants::LN_SQRT_PId2 + (x - 0.5) * log(y) - x - log(sinpiy) - lnGammacor(y);
    
    if (fabs((x - Math::trunc(x - 0.5)) * ans / x) < dxrel) {
        
        /* The answer is less than half precision because
         * the argument is too near a negative integer. */
        
        std::cerr << "Cannot compute log-gamma function for x = " << x;
    }
    
    return ans;
}

double Math::lnGamma(double x)
{
    return lnGamma_sign(x, NULL);
}

/*!
 *  Compute the log gamma correction factor for x >= 10 so that
 *
 *    log(gamma(x)) = .5*log(2*pi) + (x-.5)*log(x) -x + lgammacor(x)
 *
 *    [ lgammacor(x) is called    Del(x)    in other contexts (e.g. dcdflib)]
 *
 *  NOTES
 *
 *    This routine is a translation into C of a Fortran subroutine
 *    written by W. Fullerton of Los Alamos Scientific Laboratory.
 *
 *  SEE ALSO
 *
 *    Loader(1999)'s stirlerr() {in ./stirlerr.c} is *very* similar in spirit,
 *    is faster and cleaner, but is only defined "fast" for half integers.
 */
double Math::lnGammacor(double x)
{
    const static double algmcs[15] = {
        +.1666389480451863247205729650822e+0,
        -.1384948176067563840732986059135e-4,
        +.9810825646924729426157171547487e-8,
        -.1809129475572494194263306266719e-10,
        +.6221098041892605227126015543416e-13,
        -.3399615005417721944303330599666e-15,
        +.2683181998482698748957538846666e-17,
        -.2868042435334643284144622399999e-19,
        +.3962837061046434803679306666666e-21,
        -.6831888753985766870111999999999e-23,
        +.1429227355942498147573333333333e-24,
        -.3547598158101070547199999999999e-26,
        +.1025680058010470912000000000000e-27,
        -.3401102254316748799999999999999e-29,
        +.1276642195630062933333333333333e-30
    };
    
    double tmp;
    
    /* For IEEE double precision DBL_EPSILON = 2^-52 = 2.220446049250313e-16 :
     *   xbig = 2 ^ 26.5
     *   xmax = DBL_MAX / 48 =  2^1020 / 3 */
#define nalgm 5
#define xbig  94906265.62425156
#undef  xmax
#define xmax  3.745194030963158e306
    
    if (x < 10)
    {
        std::cerr << "Cannot compute log-gammacor function for x = " << x;
    }
    else if (x >= xmax) {
        std::cerr << "Cannot compute log-gammacor function for x = " << x;
        /* allow to underflow below */
    }
    else if (x < xbig) {
        tmp = 10 / x;
        return chebyshev_eval(tmp * tmp * 2 - 1, algmcs, nalgm) / x;
    }
    return 1 / (x * 12);
}


/* stirlerr(n) = log(n!) - log( sqrt(2*pi*n)*(n/e)^n )
 *             = log Gamma(n+1) - 1/2 * [log(2*pi) + log(n)] - n*[log(n) - 1]
 *             = log Gamma(n+1) - (n + 1/2) * log(n) + n - log(2*pi)/2
 *
 * see also lnGammacor() which computes almost the same!
 */
double Math::stirlerr(double n)
{
    
#define S0 0.083333333333333333333       /* 1/12 */
#define S1 0.00277777777777777777778     /* 1/360 */
#define S2 0.00079365079365079365079365  /* 1/1260 */
#define S3 0.000595238095238095238095238 /* 1/1680 */
#define S4 0.0008417508417508417508417508/* 1/1188 */
    
    /*
     error for 0, 0.5, 1.0, 1.5, ..., 14.5, 15.0.
     */
    const static double sferr_halves[31] = {
        0.0, /* n=0 - wrong, place holder only */
        0.1534264097200273452913848,  /* 0.5 */
        0.0810614667953272582196702,  /* 1.0 */
        0.0548141210519176538961390,  /* 1.5 */
        0.0413406959554092940938221,  /* 2.0 */
        0.03316287351993628748511048, /* 2.5 */
        0.02767792568499833914878929, /* 3.0 */
        0.02374616365629749597132920, /* 3.5 */
        0.02079067210376509311152277, /* 4.0 */
        0.01848845053267318523077934, /* 4.5 */
        0.01664469118982119216319487, /* 5.0 */
        0.01513497322191737887351255, /* 5.5 */
        0.01387612882307074799874573, /* 6.0 */
        0.01281046524292022692424986, /* 6.5 */
        0.01189670994589177009505572, /* 7.0 */
        0.01110455975820691732662991, /* 7.5 */
        0.010411265261972096497478567, /* 8.0 */
        0.009799416126158803298389475, /* 8.5 */
        0.009255462182712732917728637, /* 9.0 */
        0.008768700134139385462952823, /* 9.5 */
        0.008330563433362871256469318, /* 10.0 */
        0.007934114564314020547248100, /* 10.5 */
        0.007573675487951840794972024, /* 11.0 */
        0.007244554301320383179543912, /* 11.5 */
        0.006942840107209529865664152, /* 12.0 */
        0.006665247032707682442354394, /* 12.5 */
        0.006408994188004207068439631, /* 13.0 */
        0.006171712263039457647532867, /* 13.5 */
        0.005951370112758847735624416, /* 14.0 */
        0.005746216513010115682023589, /* 14.5 */
        0.005554733551962801371038690  /* 15.0 */
    };
    double nn;
    
    if (n <= 15.0) {
        nn = n + n;
        if (nn == (int)nn) return(sferr_halves[(int)nn]);
        return(lnGamma(n + 1.) - (n + 0.5)*log(n) + n - Constants::LN_SQRT_2PI);
    }
    
    nn = n*n;
    if (n>500) return((S0-S1/nn)/n);
    if (n> 80) return((S0-(S1-S2/nn)/nn)/n);
    if (n> 35) return((S0-(S1-(S2-S3/nn)/nn)/nn)/n);
    /* 15 < n <= 35 : */
    return((S0-(S1-(S2-(S3-S4/nn)/nn)/nn)/nn)/n);
}

/**
 * C++ version of the trunc function. We provide our own, since this
 * function is not available in the Microsoft cmath header
 *
 * Truncate a floating-point value.
 */
double Math::trunc(double x)
{
    return double( int( x ) );
}
