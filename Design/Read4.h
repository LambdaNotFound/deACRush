#ifndef ACRUSH_READ4_H
#define ACRUSH_READ4_H

#include "StandardLibrary.h"

int read4(char *buf);

class Read4 {
/*
 * 158. Read N Characters Given Read4 II - Call multiple times
 *
 *
 * Example 1:
 * File file("abc");
 * Solution sol;
 * // Assume buf is allocated and guaranteed to have enough space for storing all characters from the file.
 * sol.read(buf, 1); // After calling your read method, buf should contain "a". We read a total of 1 character from the file, so return 1.
 * sol.read(buf, 2); // Now buf should contain "bc". We read a total of 2 characters from the file, so return 2.
 * sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.
 * Example 2:

 * File file("abc");
 * Solution sol;
 * sol.read(buf, 4); // After calling your read method, buf should contain "abc". We read a total of 3 characters from the file, so return 3.
 * sol.read(buf, 1); // We have reached the end of file, no more characters can be read. So return 0.
 *
 */

public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0)
                    return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }

private:
    int readPos = 0, writePos = 0;
    char buff[4];
};

#endif //ACRUSH_READ4_H
