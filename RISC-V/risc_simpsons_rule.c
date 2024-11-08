#include <stdio.h>

#define MAX_COEFFICIENTS 16

double pow(double n,int power)
{
        if(power==0)
                return 1;
        else
        {
                return n*pow(n,power-1);
        }
}


// Function to evaluate the polynomial at a given x value
double evaluatePolynomial(double coefficients[], int degree, double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
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

void main() {
    double coefficients_matrix[5][MAX_COEFFICIENTS] = {
    {3.0,-2.0,5.0,-7.0,1.0},
    {0.0,0.0,1.0,1.0,1.0},
    {0.0,1.0,2.0,3.0,4.0},
    {0.0,1.0,1.0,1.0,1.0},
    {5.0,4.0,3.0,2.0,1.0}};

    double limits[6][2]={
        {0.0,5.0},
        {1.0,8.0},
        {2.0,4.0},
        {3.0,11.0},
        {10.0,100.0},
        {285.0,1020.0}};

    int degree = 4; // Degree of the polynomial

    // Integration limits and number of intervals
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
  
        double lowerLimit = limits[j][0];
        double upperLimit = limits[j][1];
        int numIntervals = 128;

        // Perform numerical integration without approximation
        double result = simpsonsRule(coefficients_matrix[i], degree, lowerLimit, upperLimit,numIntervals);

        // Output the result
        printf("Result of numerical integration with simpsons rule : %lf\n", result);
        }
    }
}
