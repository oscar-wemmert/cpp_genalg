#include "Mutator.h"
#include <stdlib.h> 
#include <time.h>

Mutator::Mutator() {
    #ifndef __RAND_SEED__
    #define __RAND_SEED__
    srand(time(NULL));
    #endif
}

void Mutator::Mutate(Chromosome& c, int n, bool randn) {
    if (randn) n = (rand() % n) + 1;
    int size = c.mG.size();
    for (int k = 0; k < n; ++k) {        
        int i1 = (rand() % (size));
        int i2 = (rand() % (size));
        while (i2 == i1 && size > 1) i2 = (rand() % size);
        int tmp;
        tmp = c.mG[i1];
        c.mG[i1] = c.mG[i2];
        c.mG[i2] = tmp;
    }
}
