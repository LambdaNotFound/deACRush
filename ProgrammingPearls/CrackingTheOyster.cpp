#include "CrackingTheOyster.h"

#include "BitVector.h"

int int_compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void problem_1_qsort(int array[], size_t size) {
    qsort(array, size, sizeof(int), int_compare);
}

vector<int> problem_1_set(vector<int>& nums) {
    vector<int> res;
    std::set<int> s;
    for (size_t i = 0; i < nums.size(); ++i)
        s.insert(nums[i]);

    for (auto it: s)
        res.push_back(it);

    return res;
}

void BitVector::set(const size_t& i) {
    // first find the index in array using i (as a positive integer)
    // array[i >> SHIFT] is the location of 32-bit which will set the bit
    //
    // second find the bit inside of this integer, mod i by 32
    // i & MASK will mod i by 32, the set the bit by shifting 1 to left

    array[i >> SHIFT] |= (1 << (i & MASK));
}

void BitVector::clr(const size_t& i) {
    // opposite to set operation
    array[i >> SHIFT] &= ~(1 << (i & MASK));
}

bool BitVector::test(const size_t& i) {
    // see if the ith bit is turned on
    return array[i >> SHIFT] & (1 << (i & MASK));
}
