#include "RouletteSelector.h"
#include <stdlib.h> 
#include <assert.h>
#include <iostream>


RouletteSelector::RouletteSelector(float mutChance, float croChance,
                                    Mutator &mutate, Crosser &cross) 
    : Selector(mutChance, croChance, mutate, cross) {

}

std::vector<Chromosome> RouletteSelector::SelectN(const Genome& oldG, int n) {
    std::vector<Chromosome> ret;
    float rnd;
    float addSum;

    //std::cout << "\nmSum: " << oldG.mSum;
    for (int i = 0; i < n; ++i) {
        rnd = float(rand())/float(RAND_MAX)*oldG.mSum;
        //std::cout << "\nrand: " << rnd;
        addSum = 0.0;
        for(std::vector<Chromosome>::const_iterator it = oldG.mC.begin(); it != oldG.mC.end(); ++it) {
            Chromosome c = *it;
            //std::cout << "\nfitness: " << c.mFitness + addSum;
            if (rnd <= c.mFitness+addSum) {
                //std::cout << "\nselecting because " << rnd << " <= " << c.mFitness+addSum;
                ret.push_back(c);
                break;
            }
            addSum += c.mFitness;
        }        
    }
    return ret;
}
