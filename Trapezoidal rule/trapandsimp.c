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


    // Perform numerical integration using the trapezoidal rule
    double result_trapezoidal = trapezoidalRule(coefficients, degree, lowerLimit, upperLimit, numIntervals);

    // Perform numerical integration using Simpson's rule
    double result_simpsons = simpsonsRule(coefficients, degree, lowerLimit, upperLimit, numIntervals);

    // Output the results
    printf("Result of numerical integration using the trapezoidal rule: %lf\n", result_trapezoidal);
    printf("Result of numerical integration using Simpson's rule: %lf\n", result_simpsons);

        double actual= 73791/28;
    double err_trap = error(result_trapezoidal, actual);
    double err_simp = error(result_simpsons, actual);
    printf("Error for trapezoidal is %f\n", err_trap);
    printf("Error for simpson is %f\n", err_simp);
    return 0;
}
