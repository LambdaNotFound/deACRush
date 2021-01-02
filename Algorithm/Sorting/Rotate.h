#ifndef ACRUSH_ROTATE_H
#define ACRUSH_ROTATE_H

#include "StandardLibrary.h"

/**
 * std::rotate is a common building block in many algorithms
 *
 * simple rotation to the left by swapping items (bubbling to left)
 *
 * rotate(begin, new_begin, end) -> (new_begin, ... begin, ... end, ... new_end)
 *
 * time complexity: O(n)
 *
 */

template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last) {
    if(first == n_first)
        return last;
    if(n_first == last)
        return first;

    ForwardIt read      = n_first;
    ForwardIt write     = first;
    ForwardIt next_read = first;

    while(read != last) {
        if(write == next_read)
            next_read = read;
        std::iter_swap(write++, read++);
    }

    (rotate)(write, next_read, last);
    return write;
}

// debug
template<class ForwardIt>
ForwardIt rotate_debug(ForwardIt first, ForwardIt n_first, ForwardIt last) {
    if(first == n_first) return last;
    if(n_first == last) return first;

    ForwardIt read      = n_first;
    ForwardIt write     = first;
    ForwardIt next_read = first; // needed as n_first' in recursion

    while(read != last) {
        cout_green("current range: ");
        for (ForwardIt it = first; it != last; ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        if(write == next_read) {
            cout_red("move next_read from");
            std::cout << next_read - first;
            cout_red("to");
            std::cout << read - first << std::endl;

            next_read = read; // tracks where previous read started
        }

        cout_cyan("swap");
        std::cout << *write;
        cout_cyan("with");
        std::cout << *read << std::endl;

        std::iter_swap(write++, read++);
    }

    cout_red("call into rotate:") << std::endl;
    (rotate_debug)(write, next_read, last); // [write -> next_read), to be swapped
    return write;
}

#endif //ACRUSH_ROTATE_H
