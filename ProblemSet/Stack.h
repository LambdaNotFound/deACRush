#ifndef ACRUSH_STACK_H
#define ACRUSH_STACK_H

#include "StandardLibrary.h"

using namespace std;

class Stack {
/*
 * 1249. Minimum Remove to Make Valid Parentheses
 *
 * i. stack to keep tracking index of '(' and help mark unmatched ')'
 */
public:
    string minRemoveToMakeValid(string str);
private:
    void removeSpace(string& str);

};

#endif //ACRUSH_STACK_H
