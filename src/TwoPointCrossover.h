#pragma once

#include "Crosser.h"

class TwoPointCrossover : public Crosser {
public:
    TwoPointCrossover();
    ~TwoPointCrossover(){};

    std::vector<Chromosome> Cross(Chromosome c1, Chromosome c2);
};