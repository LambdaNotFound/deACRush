#include "Utility.h"

ostream& cout_red(const string &msg) {
    return cout << "\033[1;31m" << msg << "\033[0m ";
}

ostream& cout_green(const string &msg) {
    return cout << "\033[1;32m" << msg << "\033[0m ";
}

ostream& cout_blue(const string &msg) {
    return cout << "\033[1;34m" << msg << "\033[0m ";
}

ostream& cout_magenta(const string &msg) {
    return cout << "\033[1;35m" << msg << "\033[0m ";
}

ostream& cout_cyan(const string &msg) {
    return cout << "\033[1;36m" << msg << "\033[0m ";
}
