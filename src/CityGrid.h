#pragma once
#include "Point2d.h"
#include "Domain.h"
#include "Chromosome.h"
#include <vector>

class CityGrid : public Domain {
public:
    static const int DEFAULT_N_CITIES = 20;
    static const int MAX_X = 1000;
    static const int MAX_Y = 500;
    CityGrid();
    ~CityGrid(){};

    void AddRandomCity(int nCities);
    void AddRandomCity();
    void AddCity(const Point2d& coords);
    void AddCity(int x, int y);
    float DistFromCity(int c1, int c2) const;
    void CalculateFitness(Chromosome& c);
    int GetNCities();

private:
    std::vector<Point2d> mCities;
};
