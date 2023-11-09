#ifndef PLANET_H
#define PLANET_H
#include <iostream>
#include <string.h>
using namespace std;
class Planet
{
    public:
        Planet();
        Planet(string name, double radius);
        string getName();
        void setName(string name);
        double getRadius();
        void setRadius(double radius);
        double getVolume();
    private:
        string _planet_name;
        double _planet_radius;
};
#endif