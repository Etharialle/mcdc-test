#include "main.hpp"

bool isValidUser(int age, bool hasLicense, bool hasInsurance) {
    // This condition has multiple parts for MC/DC testing
    return (age >= 18) && (hasLicense || hasInsurance);
}

bool canProcessTransaction(double amount, bool hasAccount, bool hasBalance, bool isVerified) {
    // Complex condition with multiple logical operators
    return (amount > 0.0 && amount <= 10000.0) && 
           (hasAccount && hasBalance) && 
           isVerified;
}

bool isAdult(int age) {
    // Simple condition
    return age >= 18;
}

bool isEligibleForLoan(int creditScore, int income, bool hasCollateral, bool hasGuarantor) {
    // Complex condition with OR and AND operators
    return (creditScore >= 700 && income >= 50000) || 
           (hasCollateral && hasGuarantor);
}

int main() {
    // Basic test calls to ensure functions work
    isValidUser(25, true, false);
    canProcessTransaction(5000.0, true, true, true);
    isAdult(20);
    isEligibleForLoan(750, 60000, false, false);
    
    return 0;
}