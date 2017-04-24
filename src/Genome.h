#pragma once

#include "Domain.h"
#include "Chromosome.h"


class Genome {
public:
    static const int POPULATION_SIZE = 30;
    static const int CHROMOSOME_SIZE = 19;
    static const int START_VAL = 2;
    Genome();
    void Init(int popsize);
    ~Genome(){};
    void FillGenome();
    float mBest;
    void CalcPopFitness(Domain &domain);
    std::vector<Chromosome> mC;
    void SortGenome();
    float mSum;
};
