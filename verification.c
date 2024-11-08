#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_COEFFICIENTS 16

double test_coeff[5][5]={
	{3,-2,5,-7,1},
	{0,0,1,1,1},
	{0,1,2,3,4},
	{0,1,1,1,1},
	{5,4,3,2,1}};
double test_limits[6][2]={{0,5},{1,5},{2,4},{3,8},{10,100},{285,1020}};

double error(double pred, double actual)
{
	double err=pred>actual?pred-actual:actual-pred;
	return err/pred;
}

double evaluatePolynomial(double coefficients[], int degree, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

// Midpoint rule for numerical integration
double midpointRule(double coefficients[], int degree, double lowerLimit, double upperLimit, int numIntervals) {
    double deltaX = (upperLimit - lowerLimit) / numIntervals;
    double integral = 0.0;

    // Evaluate the function at the midpoints of the intervals and sum up
    for (int i = 0; i < numIntervals; ++i) {
        double midpoint = lowerLimit + (i + 0.5) * deltaX;
        integral += evaluatePolynomial(coefficients, degree, midpoint);
    }

    // Multiply by delta x
    integral *= deltaX;

    return integral;
}

// Trapezoidal rule for numerical integration
double trapezoidalRule(double coefficients[], int degree, double lowerLimit, double upperLimit, int numIntervals) {
    double deltaX = (upperLimit - lowerLimit) / numIntervals;
    double integral = 0.0;

    // Evaluate the function at the endpoints
    integral += evaluatePolynomial(coefficients, degree, lowerLimit) / 2.0;
    integral += evaluatePolynomial(coefficients, degree, upperLimit) / 2.0;

    // Evaluate the function at the interior points and sum up
    for (int i = 1; i < numIntervals; ++i) {
        double x = lowerLimit + i * deltaX;
        integral += evaluatePolynomial(coefficients, degree, x);
    }

    // Multiply by delta x
    integral *= deltaX;

    return integral;
}

// Simpson's rule for numerical integration
double simpsonsRule(double coefficients[], int degree, double lowerLimit, double upperLimit, int numIntervals) {
    double deltaX = (upperLimit - lowerLimit) / numIntervals;
    double integral = 0.0;

    // Evaluate the function at the endpoints
    integral += evaluatePolynomial(coefficients, degree, lowerLimit);
    integral += evaluatePolynomial(coefficients, degree, upperLimit);

    // Evaluate the function at the interior points and sum up
    for (int i = 1; i < numIntervals; ++i) {
        double x = lowerLimit + i * deltaX;
        if (i % 2 == 0) {
            integral += 2 * evaluatePolynomial(coefficients, degree, x);
        } else {
            integral += 4 * evaluatePolynomial(coefficients, degree, x);
        }
    }

    // Multiply by delta x / 3
    integral *= deltaX / 3.0;

    return integral;
}

double actual_cacl(double coefficients[], int degree, double lowerLimit, double upperLimit) 
{
    int numIntervals = 10000; // Number of intervals for integration
    double deltaX = (upperLimit - lowerLimit) / numIntervals;
    double integral = 0.0;

    for (int i = 0; i < numIntervals; ++i) {
        double x1 = lowerLimit + i * deltaX;
        double x2 = x1 + deltaX;
        double y1 = evaluatePolynomial(coefficients, degree, x1);
        double y2 = evaluatePolynomial(coefficients, degree, x2);
        integral += 0.5 * (y1 + y2) * deltaX;
    }

    return integral;
}


int main()
{
	for (int i = 0; i < 5; ++i)
	{
		int coeff[MAX_COEFFICIENTS]={0};
		for (int k = 0; k < 5; ++k)
		{
			coeff[MAX_COEFFICIENTS-i-1]=test_coeff[i][k];
		}
		for (int k = 0; k < 6; ++k)
		{
			double res=0;
			int l1=test_limits[k][0],l2=test_limits[k][1];
			for (int j = 0; j < 7; ++j)
			{
				int depth=(int)(pow(2,j+1));
				double actual=actual_cacl(coeff,4,l1,l2);
				double pred_simpson=simpsonsRule(coeff,4,l1,l2,depth);
				double pred_midpoint=midpointRule(coeff,4,l1,l2,depth);
				double pred_trap=trapezoidalRule(coeff,4,l1,l2,depth);
				double err_simpson=error(pred_simpson,actual);
				double err_midpoint=error(pred_midpoint,actual);
				double err_trap=error(pred_trap,actual);
				printf("[+] i= %d k = %d depth of approximation = %d\n",i,k,depth);
				printf("actual integral value = %lf \n",actual);
				printf("error for simpsons rule = %lf \n",err_simpson);
				printf("error for midpoint rule = %lf \n",err_midpoint);
				printf("error for trapezoidal rule = %lf \n",err_trap);
			}

		}
	}
	return 0;
}