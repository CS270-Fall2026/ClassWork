#include "unity/unity.h"
#include "../reverse/reverse.h"

// setUp runs before EVERY single test function
void setUp(void) {
    // Leave blank for now
}

// tearDown runs after EVERY single test function
void tearDown(void) {
    // Leave blank for now
}

// This is our actual unit tests
void test_reverseBuffer_withNewLineAtTheEnd() {
    char input[SIZE]={"Line 1\nLine 2\nLine 3\n"};
    char actual[SIZE];
    reverseBuffer(input, actual, 256);
    char expected[SIZE] = {"Line 3\nLine 2\nLine 1\n"};
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}


int main(void) {
    UNITY_BEGIN(); // Start Unity testing
    
    RUN_TEST(test_reverseBuffer_withNewLineAtTheEnd); // Run our test

    
    return UNITY_END(); // End Unity testing and print results
}
