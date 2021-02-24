#ifndef ACRUSH_WARGAME_H
#define ACRUSH_WARGAME_H

#include "StandardLibrary.h"

using namespace std;

vector<string> split(string s /* str */, string t /* token */) {
    vector<string> res;

    while (!s.empty()) {
        int idx = s.find(t);
        if (idx != string::npos) {
            string tmp = s.substr(0, idx);
            if (!tmp.empty())
                res.push_back(tmp);
            s = s.substr(idx + t.size());
        } else {
            res.push_back(s);
            s = "";
        }
    }

    return res;
}

#endif //ACRUSH_WARGAME_H
