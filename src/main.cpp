#include <iostream>
#include "Genome.h"
#include "CityGrid.h"
#include "Chromosome.h"
#include "Mutator.h"
#include "TwoPointCrossover.h"
#include "RouletteSelector.h"
#include <stdlib.h>

using std::cout;

enum Onetwo {ONE, BOTH};

float test(int generations, RouletteSelector& s, Domain& domain, int printLevel=0, int nElite=1, bool onetwo=1) {
	std::vector<Genome> gVec;
	Genome g = Genome();
	g.FillGenome();
	g.CalcPopFitness(domain);
	gVec.push_back(g);
	if (printLevel > 0) {cout << "Initial best = " << g.mBest;cout.flush();}
	for (int i = 0; i < generations; ++i) {
	        gVec.push_back(Genome());
	        s.NewGeneration(gVec[i], gVec[i+1], nElite, 0, onetwo);
	        gVec[i+1].CalcPopFitness(domain);
	        if (printLevel > 1) cout << "\nGeneration " << i+1 << " best = " << gVec[i+1].mBest;
	}
	float end = gVec[gVec.size()-1].mBest;
	float init = gVec[0].mBest;
	if (printLevel > 0) {
		cout << "\nFinal best = " << end;
		cout << "\nImproved: " << (1.0-end/init)*100 << "%";
		cout << "\nPath: 1 ";
		for (unsigned int i = 0; i < gVec[gVec.size()-1].mC[0].mG.size(); ++i)
		{
			cout << gVec[gVec.size()-1].mC[0].mG[i] << ' ';
		}
		cout << "1" <<std::endl;
	}
	return (1.0-end/init)*100;
}

void bruteIt(int generations, int steps, int crostart, int mutstart, int times) {
	Mutator mutator = Mutator();
	TwoPointCrossover tpc = TwoPointCrossover();
	RouletteSelector s = RouletteSelector(0, 0, mutator, tpc);
	CityGrid domain = CityGrid(); // TSP
	float maxImprove = 0;
	float maxMut = 0;
	float maxCro = 0;
	float res;
	float cro; float mut;
	for (int i = crostart; i <= steps;++i) {
			for (int j = mutstart; j <= steps;++j) {
				cro = (1.0/float(steps))*i;
				mut = (1.0/float(steps))*j;
				float total = 0;
				cout << "\nWorking on cro: " << cro << ", mut: " << mut;
				for (int k = 0; k < times;++k) {
					s.mCroChance = cro;
					s.mMutChance = mut;
					total += test(generations, s, domain, 0);
				}
				res = total/float(times);
				cout << " and it got a total of " << res;
				cout.flush();
				if (res > maxImprove) {
					maxImprove = res;
					maxCro = cro;
					maxMut = mut;
				}
		}
	}
	cout << "\nWith mutation of " << maxMut << " and cross of " << maxCro;
	cout << " an average improvement of " << maxImprove << " was gotten!";
}


int main(int argc, char const *argv[]) {
	int printLevel = 1;
	int generations = 10000;
	for (int i = 1; i < argc; ++i) {
		if (i == 1) printLevel = atoi(argv[i]);
		if (i == 2) generations = atoi(argv[i]);
	}
	//bruteIt(20000, 20, 14, 15, 10);

	float mutationChance = 0.75;
	float crossoverChance = 0.70;
	Mutator mutator = Mutator();
	TwoPointCrossover tpc = TwoPointCrossover();
	RouletteSelector s = RouletteSelector(mutationChance, crossoverChance, mutator, tpc);
	CityGrid domain = CityGrid();

	test(generations, s, domain, printLevel, 1, BOTH);

    return 0;
}



