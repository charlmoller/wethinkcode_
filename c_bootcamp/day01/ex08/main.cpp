
#include <string>
#include <iostream>
#include "Human.hpp"

int main()
{
    Human big_meenie;
    big_meenie.action("melee", "cat");
    big_meenie.action("ranged", "cat");
    big_meenie.action("shout", "cat");
    big_meenie.action("melee", "dog");
    big_meenie.action("rnged", "dog");
    big_meenie.action("shout", "dog");
    big_meenie.action("meee", "horse");
    big_meenie.action("ranged", "horse");
    big_meenie.action("shout", "horse");
    return 0;
}
