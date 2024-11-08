#include <stdio.h>
#include <math.h>

#define MAX_COEFFICIENTS 10

// Function to evaluate the polynomial at a given x value
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

double error(double pred, double actual)
{
	double err=pred>actual?pred-actual:actual-pred;
	return err/pred;
}

int main() {
    // Example coefficients for the polynomial
    double coefficients[MAX_COEFFICIENTS] = {5,8,0,1,6,0,9};
    int degree = 6; // Degree of the polynomial

    // Integration limits and number of intervals
    double lowerLimit = 0.0;
    double upperLimit = 3.0;
    int numIntervals = 10000;

    // Perform numerical integration using the midpoint rule
    double result = midpointRule(coefficients, degree, lowerLimit, upperLimit, numIntervals);

    // Output the result
    printf("Result of numerical integration: %lf\n", result);

    double actual= 73791/28;
    double err = error(result, actual);
    printf("Error is %lf", err);
    return 0;
}