
#include <iostream>

int main(int c, char **v) {
    for (v++; **v || *(++v); std::cout << (char) toupper( *((*v)++) ) );
    std::cout << (c == 1 ? "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" : "\n");
}
