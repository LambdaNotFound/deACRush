#ifndef ACRUSH_LOGGERRATELIMITER_H
#define ACRUSH_LOGGERRATELIMITER_H

#include "StandardLibrary.h"

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
    If this method returns false, the message will not be printed.
    The timestamp is in seconds granularity. */
    bool shouldPrintMesage(int timestamp, string message) {
        bool reset = false;

        if (!map.count(message) || timestamp - map[message] >= 10)
            reset = true;

        if (reset)
            map[message] = timestamp;

        return reset;
    }

private:
    unordered_map<string, int> map; // inverted index
};

#endif //ACRUSH_LOGGERRATELIMITER_H
