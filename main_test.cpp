#include <gtest/gtest.h>
#include "main.hpp"

// Test class for MC/DC coverage
class MCDCTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Tests for isValidUser function - targeting MC/DC coverage
TEST_F(MCDCTest, IsValidUser_MCDC_Coverage) {
    // Test case 1: age < 18, hasLicense = false, hasInsurance = false
    // Expected: false (age condition fails)
    EXPECT_FALSE(isValidUser(17, false, false));
    
    // Test case 2: age >= 18, hasLicense = false, hasInsurance = false
    // Expected: false (license OR insurance condition fails)
    EXPECT_FALSE(isValidUser(18, false, false));
    
    // Test case 3: age >= 18, hasLicense = true, hasInsurance = false
    // Expected: true (age AND (license OR insurance) succeeds)
    EXPECT_TRUE(isValidUser(18, true, false));
    
    // Test case 4: age >= 18, hasLicense = false, hasInsurance = true
    // Expected: true (age AND (license OR insurance) succeeds)
    EXPECT_TRUE(isValidUser(18, false, true));
    
    // Test case 5: age >= 18, hasLicense = true, hasInsurance = true
    // Expected: true (all conditions true)
    EXPECT_TRUE(isValidUser(25, true, true));
    
    // Test case 6: age < 18, hasLicense = true, hasInsurance = true
    // Expected: false (age condition fails despite others being true)
    EXPECT_FALSE(isValidUser(16, true, true));
}

// Tests for canProcessTransaction function
TEST_F(MCDCTest, CanProcessTransaction_MCDC_Coverage) {
    // Test case 1: All conditions true
    EXPECT_TRUE(canProcessTransaction(5000.0, true, true, true));
    
    // Test case 2: Amount invalid (negative)
    EXPECT_FALSE(canProcessTransaction(-100.0, true, true, true));
    
    // Test case 3: Amount invalid (too large)
    EXPECT_FALSE(canProcessTransaction(15000.0, true, true, true));
    
    // Test case 4: No account
    EXPECT_FALSE(canProcessTransaction(5000.0, false, true, true));
    
    // Test case 5: No balance
    EXPECT_FALSE(canProcessTransaction(5000.0, true, false, true));
    
    // Test case 6: Not verified
    EXPECT_FALSE(canProcessTransaction(5000.0, true, true, false));
    
    // Test case 7: Valid amount, but account conditions fail
    EXPECT_FALSE(canProcessTransaction(5000.0, false, false, true));
    
    // Test case 8: Edge case - minimum valid amount
    EXPECT_TRUE(canProcessTransaction(0.01, true, true, true));
    
    // Test case 9: Edge case - maximum valid amount
    EXPECT_TRUE(canProcessTransaction(10000.0, true, true, true));
}

// Tests for isAdult function
TEST_F(MCDCTest, IsAdult_MCDC_Coverage) {
    // Test case 1: Below adult age
    EXPECT_FALSE(isAdult(17));
    
    // Test case 2: Exactly adult age
    EXPECT_TRUE(isAdult(18));
    
    // Test case 3: Above adult age
    EXPECT_TRUE(isAdult(25));
}

// Tests for isEligibleForLoan function
TEST_F(MCDCTest, IsEligibleForLoan_MCDC_Coverage) {
    // Test case 1: High credit score and sufficient income (first OR condition true)
    EXPECT_TRUE(isEligibleForLoan(750, 60000, false, false));
    
    // Test case 2: Low credit score but has collateral and guarantor (second OR condition true)
    EXPECT_TRUE(isEligibleForLoan(600, 40000, true, true));
    
    // Test case 3: High credit score but insufficient income
    EXPECT_FALSE(isEligibleForLoan(750, 40000, false, false));
    
    // Test case 4: Sufficient income but low credit score
    EXPECT_FALSE(isEligibleForLoan(600, 60000, false, false));
    
    // Test case 5: Has collateral but no guarantor
    EXPECT_FALSE(isEligibleForLoan(600, 40000, true, false));
    
    // Test case 6: Has guarantor but no collateral
    EXPECT_FALSE(isEligibleForLoan(600, 40000, false, true));
    
    // Test case 7: Neither condition satisfied
    EXPECT_FALSE(isEligibleForLoan(600, 40000, false, false));
    
    // Test case 8: Both OR conditions satisfied
    EXPECT_TRUE(isEligibleForLoan(750, 60000, true, true));
}

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}