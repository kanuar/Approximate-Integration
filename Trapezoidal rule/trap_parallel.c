#include <stdio.h>
#include <math.h>
#include <omp.h>

#define MAX_COEFFICIENTS 10

// Function to evaluate the polynomial at a given x value
double evaluatePolynomial(double coefficients[], int degree, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

// Trapezoidal rule for numerical integration (parallel version)
double trapezoidalRule(double coefficients[], int degree, double lowerLimit, double upperLimit, int numIntervals) {
    double deltaX = (upperLimit - lowerLimit) / numIntervals;
    double integral = 0.0;

    #pragma omp parallel for reduction(+:integral)
    for (int i = 1; i < numIntervals; ++i) {
        double x = lowerLimit + i * deltaX;
        integral += evaluatePolynomial(coefficients, degree, x);
    }

    // Add the endpoints
    integral += (evaluatePolynomial(coefficients, degree, lowerLimit) + evaluatePolynomial(coefficients, degree, upperLimit)) / 2.0;

    // Multiply by delta x
    integral *= deltaX;

    return integral;
}

double error(double pred, double actual)
{
	double err=pred>actual?pred-actual:actual-pred;
	return err/pred;
}

int main() {
    // Example coefficients for the polynomial: 2x^3 - 3x^2 + 4x - 5
    double coefficients[MAX_COEFFICIENTS] = {5,8,0,1,6,0,9};
    int degree = 6; // Degree of the polynomial

    // Integration limits and number of intervals
    double lowerLimit = 0.0;
    double upperLimit = 3.0;
    int numIntervals = 10000;


    // Perform numerical integration using the trapezoidal rule (parallel version)
        double t1=omp_get_wtime();
    double result_trapezoidal = trapezoidalRule(coefficients, degree, lowerLimit, upperLimit, numIntervals);
        double t2=omp_get_wtime();
	double t=t2-t1;

    // Output the result
    printf("Result of numerical integration using the trapezoidal rule (parallel): %lf\n", result_trapezoidal);
        printf("time taken for integration using trapezoidal: %f\n",t);

        double actual= 73791/28;;
    double err = error(result_trapezoidal, actual);
    printf("Error is %f", err);
    return 0;
}
