
#include <iostream>
#include <fstream>
#include <string>

void file_find_replace(std::string name, std::string f, std::string r)
{
    std::string name_replace = name + ".replace";

    // Giving streams a std::string is not available on clang++ compiler
    std::ifstream ifile ( name.c_str() );
    if (ifile.is_open()) {
        std::ofstream ofile ( name_replace.c_str() );

        std::string line;
        while (std::getline(ifile, line))
        {
            size_t pos = 0;
            while ((pos = line.find(f, pos)) != std::string::npos)
            {
                line.replace(pos, f.length(), r);
                pos += r.length();
            }
            ofile << line << "\n";
        }
        ofile.close();
        ifile.close();
    } else std::cout << "Could not open input file.\n";
}

int main(int argc, char const *argv[])
{ 
    if (argc == 4)
    {
        std::string n( argv[1] );
        std::string f( argv[2] );
        std::string r( argv[3] );

        file_find_replace(n, f, r);
    } else std::cout << "Invalid input. Usage:\n" << argv[0] << " file find replace\n";
    return 0;
}
