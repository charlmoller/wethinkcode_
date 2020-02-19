#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>
#include "Brain.hpp"
#include "Human.hpp"

class Human {

    public:

        const Brain brain;

        Human(void);
        ~Human(void);
        std::string identify(void);
        Brain getBrain(void);

};

#endif // HUMAN_HPP
