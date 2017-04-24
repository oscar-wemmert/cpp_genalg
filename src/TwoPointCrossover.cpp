#include "TwoPointCrossover.h"
#include <stdlib.h> 
#include <time.h>
#include <algorithm>
#include <iostream>

using std::max;
using std::min;
using std::cout;


TwoPointCrossover::TwoPointCrossover() : Crosser() {
    #ifndef __RAND_SEED__
    #define __RAND_SEED__
    srand(time(NULL));
    #endif
}

std::vector<Chromosome> TwoPointCrossover::Cross(Chromosome c1, Chromosome c2) {
    int requireddist = 3;
    std::vector<Chromosome> ret;
    int size = c1.mG.size();
    int r1 = rand() % size;
    int r2 = rand() % size;
    int i1 = max(1,min(r1,r2));
    int i2 = max(r1,r2);
    while (i2 - i1 < requireddist && size > requireddist+1) {
        int r1 = rand() % size;
        int r2 = rand() % size;
        i1 = max(1,min(r1,r2));
        i2 = max(r1,r2);
    }
    /*cout << "\n\n\ni1: " << i1;
    cout << "\ni2: " << i2;
    cout << "\nStarting with:";
    cout <<"\nC1:\n"<<c1.mG[0];
    for (int i = 1; i < size; ++i) {
        if (i1 == i || i == i2) cout << '|';
        if (c1.mG[i] < 10) cout << ' ';        
        cout << ' ' << c1.mG[i];
    }
    cout <<"\nC2:\n"<<c2.mG[0];
    for (int i = 1; i < size; ++i) {
        if (i1 == i || i == i2) cout << '|';
        if (c1.mG[i] < 10) cout << ' ';        
        cout << ' ' << c2.mG[i];
    }*/

    std::vector<int> sub1(c1.mG.begin()+i1, c1.mG.begin()+i2);
    std::vector<int> sub2(c2.mG.begin()+i1, c2.mG.begin()+i2);
    std::vector<int>::iterator it = c1.mG.erase(c1.mG.begin()+i1, c1.mG.begin()+i2);
    c1.mG.insert(it, sub2.begin(), sub2.end());

    it = c2.mG.erase(c2.mG.begin()+i1, c2.mG.begin()+i2);
    c2.mG.insert(it, sub1.begin(), sub1.end());

    std::vector<int> holes1;
    std::vector<int> holes2;
    for (int i = i1; i < i2; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j < i1 || j >= i2) {
                if (c1.mG[j] == c1.mG[i]) holes1.push_back(j);
                if (c2.mG[j] == c2.mG[i]) holes2.push_back(j);
            }
        }
    }
    int tmp;
    for (int i = 0; i < holes1.size(); ++i) {
        tmp = c1.mG[holes1[i]];
        c1.mG[holes1[i]] = c2.mG[holes2[i]];
        c2.mG[holes2[i]] = tmp;
    }
    ret.push_back(c1);
    ret.push_back(c2);

    /*cout << "\nEnding with:";
    cout <<"\nC1:\n"<<c1.mG[0];
    for (int i = 1; i < size; ++i) {
        if (i1 == i || i == i2) cout << '|';
        if (c1.mG[i] < 10) cout << ' ';        
        cout << ' ' << c1.mG[i];
    }
    cout <<"\nC2:\n"<<c2.mG[0];
    for (int i = 1; i < size; ++i) {
        if (i1 == i || i == i2) cout << '|';
        if (c2.mG[i] < 10) cout << ' ';        
        cout << ' ' << c2.mG[i];
    }*/

    return ret;
}
