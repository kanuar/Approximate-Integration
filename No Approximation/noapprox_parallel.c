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

// Function to perform numerical integration using the definite integral formula (parallel version)
double integrate(double coefficients[], int degree, double lowerLimit, double upperLimit) {
    int numIntervals = 10000; // Number of intervals for integration
    double deltaX = (upperLimit - lowerLimit) / numIntervals;
    double integral = 0.0;

    #pragma omp parallel for reduction(+:integral)
    for (int i = 0; i < numIntervals; ++i) {
        double x1 = lowerLimit + i * deltaX;
        double x2 = x1 + deltaX;
        double y1 = evaluatePolynomial(coefficients, degree, x1);
        double y2 = evaluatePolynomial(coefficients, degree, x2);
        integral += 0.5 * (y1 + y2) * deltaX;
    }

    return integral;
}


int main() {
    // Example coefficients for the polynomial: 
    double coefficients[MAX_COEFFICIENTS] = {5,8,0,1,6,0,9};
    int degree = 6; // Degree of the polynomial

    // Integration limits and number of intervals
    double lowerLimit = 0.0;
    double upperLimit = 3.0;
    int numIntervals = 10000;

    // Perform numerical integration without approximation (parallel version)
        double t1=omp_get_wtime();
    double result = integrate(coefficients, degree, lowerLimit, upperLimit);
        double t2=omp_get_wtime();
	double t=t2-t1;

    // Output the result
    printf("Result of numerical integration without approximation (parallel): %lf\n", result);
        printf("time taken for integration wihtout approximation: %f",t);


    return 0;
}
