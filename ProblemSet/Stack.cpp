#include "Stack.h"

string Stack::minRemoveToMakeValid(string str) {
    stack<int> s;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(')
            s.push(i);
        else if (str[i] == ')') {
            if (!s.empty())
                s.pop();
            else
                str[i] = ' ';
        }
    }

    while (!s.empty()) {
        int i = s.top(); s.pop();
        str[i] = ' ';
    }

    removeSpace(str);

    return str;
}

void Stack::removeSpace(string& str) {
    int n = str.size(), cur = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ')
            str[cur++] = str[i];
    }
    str = str.substr(0, cur);
}
