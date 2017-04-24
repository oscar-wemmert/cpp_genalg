#pragma once

#include "Genome.h"
#include "Mutator.h"
#include "Crosser.h"

class Crosser;
class Selector {
public:
    Selector(float mutChance, float croChance, Mutator &mutate, Crosser &cross);        
    
    virtual std::vector<Chromosome> SelectN(const Genome& oldG, int n){return std::vector<Chromosome>();}; // Implement in children!
    void NewGeneration(const Genome&oldG, Genome& newG, int elitism, int nnew, bool onetwo);

    Mutator mMutate;
    Crosser *mCross;
    float mCroChance;
    float mMutChance;
    virtual ~Selector(){};

};
