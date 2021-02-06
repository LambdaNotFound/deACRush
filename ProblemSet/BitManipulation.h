#ifndef ACRUSH_BITMANIPULATION_H
#define ACRUSH_BITMANIPULATION_H

#include "StandardLibrary.h"

using namespace std;

class BitManipulation {
/*
 * 89. Gray Code
 *
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 */
public:
    vector<int> grayCode(int n);

    unsigned int binaryToGray(unsigned int num);

    unsigned int grayToBinary(unsigned int num);

/*
 * 169. Majority Element
 *
 * i. BitManipulation
 * ii. DivideAndConquer
 */
public:
    int majorityElement(vector<int>& nums);

};

#endif //ACRUSH_BITMANIPULATION_H
