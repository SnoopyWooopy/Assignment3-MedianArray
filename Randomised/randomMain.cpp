#include <gtest/gtest.h>
#include <iostream>
#include "random_QuickSelect.h"

TEST(Random, BasicTwo) {
    EXPECT_EQ(baicTest(), 2);
}

//Basic test used to track current values
TEST(Trash, basicCheck) {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int answer = quickSelect(array,array.size()/2);
    system("clear"); // remove when I don't want clarifications
    std::cout << "Median Value = " << answer << std::endl;
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}