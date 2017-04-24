#pragma once
#include "Chromosome.h"

class Mutator
{
public:
    Mutator();
    ~Mutator(){};

    void Mutate(Chromosome& c, int n=1, bool randn=false);
};
