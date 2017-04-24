#include "Genome.h"
#include <algorithm>
#include <stdlib.h> 
#include <time.h>
#include <assert.h>
#include <iostream>

Genome::Genome() {
    Init(POPULATION_SIZE);
}

void Genome::Init(int popsize) {
    mSum = 0;
    #ifndef __RAND_SEED__
    #define __RAND_SEED__
    srand(time(NULL));
    #endif
    mC.resize(popsize);
}

void Genome::FillGenome() {
    for(int i = 0; i < POPULATION_SIZE; ++i) {
        mC[i] = Chromosome(CHROMOSOME_SIZE, START_VAL);
    }
    
    for (int i = 0; i < POPULATION_SIZE; ++i)
        std::random_shuffle(mC[i].mG.begin(), mC[i].mG.end());
}

void Genome::CalcPopFitness(Domain &domain) {
    mSum = 0;
    float min = 0;
    for (int i = 0; i < POPULATION_SIZE; ++i) {
    	Chromosome& c = mC[i];
        domain.CalculateFitness(c);
        if (c.mFitness < min || min == 0) min = c.mFitness;
        mSum += c.mFitness;
    }
    mBest = min;
    SortGenome();
    /*std::cout << "\nResult of fitness: ";
    for (int i = 0; i < mC.size(); ++i)
    {
        std::cout << "\nfitness of individual nr";
        if (i < 10) std::cout << ' ';
        std::cout << i <<" = " << mC[i].mFitness;
    }*/    
}

void Genome::SortGenome() {
    std::sort(mC.begin(), mC.end());
}
