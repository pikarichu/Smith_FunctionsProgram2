// FunctionsProgram2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This program takes prices over three years as input and outputs the rate of inflation and the trend of whether the amount of inflation has increased or decreased
#include <iostream>
#include <stdio.h>
using namespace std;


struct priceYears
{
    double current{ 0.0 };
    double one{ 0.0 };
    double two{ 0.0 };
};

struct inflationRates
{
    double rateOne{ 0.0 };
    double rateTwo{ 0.0 };
};

//Gets the current price of an item and the prices for the last year and the last two years
//Preconditions - None
//Postconditions - Returns the price inputs
priceYears getInput();

//Takes the input values and calculates the rate of inflation
//Preconditions - getInput
//Postconditions - Returns the rate of inflation
inflationRates calculateResults(double current, double one, double two);

//Outputs the results from the other two functions
//Preconditions - getInput and calculateResults
//Postconditions - Prfloated output
void outputResults(priceYears prices, inflationRates rates);

int main()
{
    priceYears prices;
    prices = getInput();
    inflationRates rates;
    rates = calculateResults(prices.current, prices.one, prices.two);
    outputResults(prices, rates);

    return 0;
}


priceYears getInput()
{
    double currentPrice = 0.0;
    double oneYearPrice = 0.0;
    double twoYearPrice = 0.0;
    cout << "Current Price of item: $";
    cin >> currentPrice;
    cout << "Price of item one year ago: $";
    cin >> oneYearPrice;
    cout << "Price of item two years ago: $";
    cin >> twoYearPrice;
    return { currentPrice, oneYearPrice, twoYearPrice };
}

inflationRates calculateResults(double current, double one, double two)
{
    double rateOne = ((one - current) / one) * -100;
    double rateTwo = ((two - one) / two) * -100;
    return { rateOne, rateTwo };
}

void outputResults(priceYears prices, inflationRates rates)
{
    double currentPrice = prices.current;
    double oneYearPrice = prices.one;
    double twoYearPrice = prices.two;
    double oneYearRate = rates.rateOne;
    double twoYearRate = rates.rateTwo;
    cout << "Inflation Rate from a year ago to now: " << oneYearRate << "%" << endl;
    cout << "Inflation Rate from two years ago to one year ago: " << twoYearRate << "%" << endl;
    if (oneYearRate > twoYearRate)
        cout << "The rate of inflation has increased" << endl;
    else if (oneYearRate < twoYearRate)
        cout << "The rate of inflation has decreased" << endl;
    else
        cout << "The rate of inflation has not changed" << endl;
}