
#include "Pony.hpp"

void ponyOnTheHeap(void) {
    
    Pony *pony = new Pony("heap", 15);
    
    pony->neigh();
    
    delete pony;
}

void ponyOnTheStack(void) {
    
    Pony pony = Pony("stack", 20);

    pony.neigh();

}

int main() {
    ponyOnTheStack();
    ponyOnTheHeap();
    return (0);
}