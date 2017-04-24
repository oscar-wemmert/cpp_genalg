#pragma once
#include <vector>

class Chromosome {
public:
    Chromosome(unsigned int size);
    Chromosome(unsigned int size, int start);
    void Init(unsigned int size);
    Chromosome(){mFitness = -1.0;};
    
    std::vector<int> mG;
    float mFitness;
    bool operator<(const Chromosome & right) const;
    bool operator==(const Chromosome& right) const;
};
