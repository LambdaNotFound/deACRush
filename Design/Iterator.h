#ifndef ACRUSH_ITERATOR_H
#define ACRUSH_ITERATOR_H

#include "StandardLibrary.h"

using namespace std;

class Iterator {
/*
 * 281. Zigzag Iterator
 *
 * Given 2 1d vectors, implement an iterator to return their elements alternately
 *
 * Follow up: What if you are given k 1d vectors? clarify ambiguity, define what Zigzag is.
 */
    class ZigzagIterator {
    public:
        ZigzagIterator(vector<int>& v1, vector<int>& v2) {
            int len1 = v1.size(), len2 = v2.size(), len = max(len1, len2);
            for (int i = 0; i < len; ++i) {
                if (i < len1)
                    v.push_back(v1[i]);
                if (i < len2)
                    v.push_back(v2[i]);
            }
        }

        int next() {
            return v[i++];
        }

        bool hasNext() {
            return i < v.size();
        }

    private:
        vector<int> v;
        int i = 0;

    public:
        ZigzagIterator(vector<vector<int> >& v) {
            for (int i = 0; i < v.size(); ++i)
                q.push(make_pair(v[i].begin(), v[i].end()));
        }

        int nextFollowUp();

        bool hasNextFollowUp();

    private:
        queue<pair<vector<int>::iterator, vector<int>::iterator> > q;
    };

};

#endif //ACRUSH_ITERATOR_H
