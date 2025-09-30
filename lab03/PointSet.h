//
// Created by Lehel on 2025-09-30.
//

#ifndef POINTSET_H
#define POINTSET_H

#include "Point.h"
#include <vector>
using namespace std;
class PointSet{
    //különböző pontok
    vector<Point> points;
    //különböző pontok száma
    int n{};
    //pontok kozotti tavolsagok
    vector<double> distances;
    //segédfüggvény, amely feltölti a distances vektort
    void computeDistances();
public:
    //konstruktor: előállítja a points vektort
    //kiszámítja a pontok közötti távolságokat (distances vektor),
    explicit PointSet( int n = 100 );
    //maximum kiválasztás a tavolsag vektorból
    [[nodiscard]] double maxDistance() const;
    //minimum kiválasztás a tavolsag vektorból
    [[nodiscard]] double minDistance() const;
    //összesen hány távolság értelmezhető n
    //különböző pont között
    [[nodiscard]] int numDistances() const;
    //a pontok vektor kiíratása
    void printPoints() const;
    //a tavolsagok vektor kiíratása
    void printDistances() const;
    //növekvő sorrendbe rendezi a pontokat x koordináta szerint
    void sortPoint();
    //u. a. y koordináta szerint
    void sortPointsY();
    //a tavolsagok vektor rendezése
    void sortDistances();
    //hány darab különböző távolságot tartalmaz a tavolsagok vektor
    int numDistinctDistances();
};

#endif //POINTSET_H
