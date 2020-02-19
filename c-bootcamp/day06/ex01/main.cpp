
# include <cmath>
# include <string>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdlib>
# include <climits>
# include <iostream>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

void * serialize( void ) {
    
    Data* data = new Data();

    data->s1 = "randstr0";
    data->n = 543212345;
    data->s2 = "randstr1";
    return (void*) data;
}

Data * deserialize( void * raw ) {
    return (Data*) raw;
}

int main(void)
{

    void* create = serialize();

    Data* get = deserialize(create);
    std::cout << get->s1 << "\n";
    std::cout << get->n << "\n";
    std::cout << get->s2 << "\n";
}