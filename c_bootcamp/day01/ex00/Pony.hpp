#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {

    public:

        std::string name;
        int top_speed;

        Pony(std::string, int); // name, top_speed
        ~Pony(void);
        void neigh(void);

};

#endif // PONY_HPP
