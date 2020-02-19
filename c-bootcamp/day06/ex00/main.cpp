
# include <cmath>
# include <string>
# include <iomanip>
# include <cstring>
# include <cstdlib>
# include <climits>
# include <iostream>

void convert_char(double v) {
    std::cout << "char: ";
    char conv = static_cast<char>(v);
    if (v >= 0.0f && v <= 32.0f)
        std::cout << "Non displayable";
    else if (v < 0.0f || v > 126.0f || isnan(v))
        std::cout << "impossible";  
    else
        std::cout << "\'" << conv << "\'";
    std::cout << "\n";
}

void convert_int(double v) {
    std::cout << "int: ";
    int conv = static_cast<int>(v);
    if (isnan(v) || conv == INT_MIN)
        std::cout << "impossible\n";
    else
        std::cout << conv << "\n";
}

void convert_float(double v) {
    std::cout << "float: ";
    float conv = static_cast<float>(v);
    if (v == HUGE_VALF)
        std::cout << "impossible";
    else if (std::isinf(v))
        std::cout << conv << "f\n";
    else
        std::cout << std::setprecision(5) << conv << (conv == floor(conv) ? ".0" : "") << "f\n";
}

void convert_double(double v) {
    std::cout << "double: ";
    double conv = static_cast<double>(v);
    if (v == HUGE_VAL)
        std::cout << "impossible";
    else if (std::isinf(v))
        std::cout << conv << "\n";
    else
        std::cout << std::setprecision(5) << conv << (conv == floor(conv) ? ".0" : "") << "\n";
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 0;
    
    std::string cstr = "";
    std::string istr = "";
    std::string fstr = "";
    std::string dstr = "";
    try {
        double dd = std::stod(argv[1]);
        std::string argvstr = std::string(argv[1]);
        convert_char  ( dd );
        convert_int   ( dd );
        convert_float ( dd );
        convert_double( dd );
    } catch(const std::exception& e) {
        std::cout << e.what() << "\n";        
    }
}