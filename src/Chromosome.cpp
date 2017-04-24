#include "Chromosome.h"

Chromosome::Chromosome(unsigned int size) {
    Init(size);
}

Chromosome::Chromosome(unsigned int size, int start) {
    Init(size);
    for (unsigned int i = 0; i < size; ++i) {
        mG[i] = i + start;
    }
}

void Chromosome::Init(unsigned int size) {
    mG.resize(size);
}

bool Chromosome::operator<(const Chromosome & right) const {
    return (mFitness < right.mFitness);
}

bool Chromosome::operator==(const Chromosome& right) const {
    if (mG.size() != right.mG.size()) return false;
        for (unsigned int i = 0; i < mG.size(); ++i){
            if (mG[i] != right.mG[i]) return false;
        }
        return true;
}
