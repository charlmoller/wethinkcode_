
#include <string>
#include <iostream>
#include <map>
#include "Human.hpp"

// pointer to a void (std::string &) member function 
typedef void (Human::*HumanAction)(std::string const &);

void Human::meleeAttack(std::string const & target) {
    std::cout << "Melee attack on " << target << "\n";
}

void Human::rangedAttack(std::string const & target) {
    std::cout << "Ranged attack on " << target << "\n";
}

void Human::intimidatingShout(std::string const & target) {
    std::cout << "Shout at " << target << "\n";
}

void Human::action(std::string const & action_name, std::string const & target) {

    /* Apparently we're not allowed to use map
    // create map of function pointers
    std::map<std::string, HumanAction> actions;
    
    // assign references to member function
    actions["melee"] = &Human::meleeAttack;
    actions["ranged"] = &Human::rangedAttack;
    actions["shout"] = &Human::intimidatingShout;

    // check whether key exists to prevent segfault
    if (actions.count(action_name)) {
        HumanAction selected = actions[action_name];
        // dereference and call a pointer to non-static member function
        (this->*selected)(target);
    }
    */
    // create array of function pointers
    std::string actions_str[3] = {
        "melee",
        "ranged",
        "shout"
    };

    HumanAction actions[3] = {
        &Human::meleeAttack,
        &Human::rangedAttack,
        &Human::intimidatingShout
    };

    for (int i = 0; i < 3; ++i)
    {
        if ( actions_str[i] == action_name ) {
            HumanAction selected = actions[i];
            (this->*selected)(target);    
        }
    }
}
