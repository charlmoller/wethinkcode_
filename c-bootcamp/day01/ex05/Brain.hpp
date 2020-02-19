#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {

    public:

        std::string address;

        Brain(void);
        ~Brain(void);
        std::string identify(void);

};

#endif // BRAIN_HPP
