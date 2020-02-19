
# include <cmath>
# include <string>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdlib>
# include <climits>
# include <iostream>


class Base {
public:
    virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base * generate(void) {
    int r = rand() % 3;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    return new C();
}

void identify_from_pointer( Base * p ) {
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A";
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B";
    else
        std::cout << "C";
    (void)p;
}

void identify_from_reference( Base & p ) {
    Base * ptr = &p;
    if (dynamic_cast<A*>(ptr) != nullptr)
        std::cout << "A";
    else if (dynamic_cast<B*>(ptr) != nullptr)
        std::cout << "B";
    else
        std::cout << "C";
}

int main(void)
{
    srand(time(0));

    for (int i = 0; i < 10; ++i)
    {
        Base * test1 = generate();
        std::cout << "Test " << i << " ";
        identify_from_reference(*test1);
        std::cout << " ";
        identify_from_pointer(test1);
        std::cout << "\n";
        delete test1;
    }
}
