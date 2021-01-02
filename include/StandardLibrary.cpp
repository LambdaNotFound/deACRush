#include "StandardLibrary.h"

std::ostream& cout_red(const std::string &msg) {
    return std::cout << "\033[1;31m" << msg << "\033[0m ";
}

std::ostream& cout_green(const std::string &msg) {
    return std::cout << "\033[1;32m" << msg << "\033[0m ";
}

std::ostream& cout_blue(const std::string &msg) {
    return std::cout << "\033[1;34m" << msg << "\033[0m ";
}

std::ostream& cout_magenta(const std::string &msg) {
    return std::cout << "\033[1;35m" << msg << "\033[0m ";
}

std::ostream& cout_cyan(const std::string &msg) {
    return std::cout << "\033[1;36m" << msg << "\033[0m ";
}
