#include "gtest/gtest.h"

#include "../ProgrammingPearls/BitVector.h"

using namespace std;

TEST(BitVector, BitVector) {
    // std::bitset<10> bs(42);
    BitVector bv(100);
    bv.set(32);

    bool result = bv.test(32);
    bool expected = true;
    EXPECT_EQ(result, expected);

    bv.clr(32);
    expected = false;
    result = bv.test(32);
    EXPECT_EQ(result, expected);
}
