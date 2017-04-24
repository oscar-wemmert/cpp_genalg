#pragma once

#include "Selector.h"

class RouletteSelector : public Selector {
public:
    RouletteSelector(float mutChance, float croChance, Mutator &mutate, Crosser &cross);

    std::vector<Chromosome> SelectN(const Genome& oldG, int n);
    virtual ~RouletteSelector(){};

};
