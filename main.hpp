#ifndef MAIN_HPP
#define MAIN_HPP

// Function to demonstrate MC/DC coverage with multiple conditions
bool isValidUser(int age, bool hasLicense, bool hasInsurance);

// Function with nested conditions for more complex MC/DC testing
bool canProcessTransaction(double amount, bool hasAccount, bool hasBalance, bool isVerified);

// Simple function with single condition
bool isAdult(int age);

// Function with multiple logical operators
bool isEligibleForLoan(int creditScore, int income, bool hasCollateral, bool hasGuarantor);

#endif // MAIN_HPP