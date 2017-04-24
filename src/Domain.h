#pragma once

#include "Chromosome.h"

class Domain {
public:
    Domain(){};
    virtual ~Domain(){};
    virtual void CalculateFitness(Chromosome& c){};
};
