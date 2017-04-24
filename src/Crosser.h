#pragma once

#include "Chromosome.h"
#include <vector>

class Crosser {
public:
    Crosser(){};
    ~Crosser(){};

    virtual std::vector<Chromosome> Cross(Chromosome c1, Chromosome c2)= 0;
};