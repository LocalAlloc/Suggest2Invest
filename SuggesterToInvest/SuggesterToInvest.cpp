#include <stdio.h>
#include <math.h>
#include <Windows.h>

// Function to calculate the cumulative normal distribution (N(d))
double N(double x) {
    return 0.5 * (1.0 + erf(x / sqrt(2.0)));
}

// Black-Scholes function to calculate the call option price
double blackScholesCall(double S, double K, double T, double r, double sigma) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return S * N(d1) - K * exp(-r * T) * N(d2);
}

int main() {
    double S, K, T, r, sigma, marketPrice, predictedPrice;

    // User inputs
    printf("Enter the current stock price (S): ");
    scanf_s("%lf", &S);

    printf("Enter the strike price (K): ");
    scanf_s("%lf", &K);

    printf("Enter the time to expiration (in years, T): ");
    scanf_s("%lf", &T);

    printf("Enter the risk-free interest rate (r) (as a decimal): ");
    scanf_s("%lf", &r);

    printf("Enter the volatility (sigma) (as a decimal): ");
    scanf_s("%lf", &sigma);

    // Call Black-Scholes function to calculate the predicted option price
    predictedPrice = blackScholesCall(S, K, T, r, sigma);

    // Display the predicted option price
    printf("The predicted call option price is: $%.2f\n", predictedPrice);

    // Ask the user for the current market price of the option
    printf_s("Enter the current market price of the call option(In decimals : eg 0.68 for $68 as one call option is a 100 shares.): ");
    scanf_s("%lf", &marketPrice);

    // Suggest investment decision based on the comparison of market price and predicted price
    if (marketPrice > predictedPrice) {
        printf("The option is overpriced. It is better not to invest.\n");
        system("pause");
    }
    else {
        printf("The option is underpriced. It might be a good investment opportunity.\n");
        system("pause");
    }

    return 0;
}
