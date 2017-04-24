#include "Selector.h"
#include <stdlib.h> 
#include <time.h>
#include <assert.h>
#include <iostream>

Selector::Selector(float mutChance, float croChance, Mutator &mutate, Crosser &cross) {
    mMutChance=mutChance;
    mCroChance=croChance;
    mMutate=mutate;
    mCross=&cross;
    #ifndef __RAND_SEED__
    #define __RAND_SEED__
    srand(time(NULL));
    #endif
}

void Selector::NewGeneration(const Genome& oldG, Genome& newG, int elitism, int nnew, bool both) {
    int size = oldG.mC.size();
    newG.mC.clear();
    newG.mC.resize(size);
    std::vector<Chromosome> tmp(2);
    for (int i = 0; i < size; ++i) {
        if (i < elitism) {
            newG.mC[i] = oldG.mC[i];
        } else if (i < elitism + nnew) {
            newG.mC[i] = Chromosome(Genome::CHROMOSOME_SIZE, Genome::START_VAL);
        } else if (i < size -1) {
            tmp = SelectN(oldG, 2);
            if (rand()/float(RAND_MAX) <= mCroChance) {
            	tmp = mCross->Cross(tmp[0], tmp[1]);
            	if (both) {
            		if ((rand()/float(RAND_MAX)) <= mMutChance) mMutate.Mutate(tmp[0]);
					if ((rand()/float(RAND_MAX)) <= mMutChance) mMutate.Mutate(tmp[1]);
            	}
            }
            else {
            	if ((rand()/float(RAND_MAX)) <= mMutChance) mMutate.Mutate(tmp[0]);
            	if ((rand()/float(RAND_MAX)) <= mMutChance) mMutate.Mutate(tmp[1]);
            }
            newG.mC[i+1] = tmp[0];
            newG.mC[i] = tmp[1];
            ++i;
        } else {
            tmp = SelectN(oldG, 1);
            if (rand()/float(RAND_MAX) <= mMutChance) mMutate.Mutate(tmp[0]);
            newG.mC[i] = tmp[0];
        }
    }
    if (elitism > 0) assert(oldG.mC[0] == newG.mC[0]);
}
