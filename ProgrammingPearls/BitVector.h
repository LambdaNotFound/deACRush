#ifndef ACRUSH_BITVECTOR_H
#define ACRUSH_BITVECTOR_H

#include "StandardLibrary.h"

// size of int
#define SIZEPERWORD 32

// 2^5 is 32 and shifting a int by 5 to the right is to divide it by 32
// which will be helpful when converting bit index to index in bit vector's int array
#define SHIFT 5

// 0x1f is 00011111 == 31
#define MASK 0x1f

// How would you implement bit vectors using bitwise logical operations
// implement: set, clr, test
class BitVector {
public:
    BitVector(const size_t& sz) : size(sz >> SHIFT) {
        // sz >> SHIFT: how many 32-bit are needed in the bit vector
        array = new int[size + 1];
        memset(array, 0, sizeof array);
    }

    ~BitVector() {
        delete array;
    }

    void set(const size_t& i);

    void clr(const size_t& i);

    bool test(const size_t& i);

private:
    int* array;
    size_t size;
};

#endif //ACRUSH_BITVECTOR_H
