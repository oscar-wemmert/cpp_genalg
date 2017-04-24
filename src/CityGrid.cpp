#include "CityGrid.h"
#include <stdlib.h> 
#include <time.h>
#include <math.h>
#include <assert.h>
#include <iostream>

CityGrid::CityGrid() {
    #ifndef __RAND_SEED__
    #define __RAND_SEED__
    srand(time(NULL));
    #endif
    AddRandomCity(DEFAULT_N_CITIES);
}

void CityGrid::AddRandomCity(int nCities) {
    for (int i = 0; i < nCities; ++i) AddRandomCity();
}

void CityGrid::AddRandomCity() {
    int x = rand() % MAX_X;
    int y = rand() % MAX_Y;
    Point2d p = Point2d(x,y);
    mCities.push_back(p);
}

void CityGrid::AddCity(const Point2d& coords) {
    mCities.push_back(coords);
}

void CityGrid::AddCity(int x, int y) {
    Point2d p = Point2d(x,y);
    AddCity(p);
}

float CityGrid::DistFromCity(int city1, int city2) const {
    assert(city1 >= 0 && city1 < DEFAULT_N_CITIES);
    assert(city2 >= 0 && city2 < DEFAULT_N_CITIES);

    const Point2d& c1 = mCities.at(city1);
    const Point2d& c2 = mCities.at(city2);
    /*std::cout << "\nChecking from city "<< city1+1<<" at (" << c1.x << "," << c1.y;
    std::cout <<") to city "<<city2+1<<" (" << c2.x << "," << c2.y <<")";
    std::cout << "\nDistance was: " << sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));*/
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

void CityGrid::CalculateFitness(Chromosome& c) {
    //std::cout << "\nNew chromosome!";
    float total = 0;
    total += DistFromCity(0, c.mG.at(0)-1);
    for (std::vector<int>::iterator it = c.mG.begin()+1; it != c.mG.end(); ++it) {
    	int city1 = *it; int city2 = *(it-1);
    	total += DistFromCity(city1-1, city2-1);
    }
     total += DistFromCity(mCities.size()-1, 0);
     c.mFitness = total;
     //std::cout << "\nTotal (fitness) was: " << c.mFitness;

}

int CityGrid::GetNCities() {
    return mCities.size();
}
