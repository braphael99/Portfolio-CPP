#include "Planet.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;

Planet::Planet(){
    _planet_name = "";
    _planet_radius = 0.0;
}

Planet::Planet(string name, double radius){
    _planet_name = name;
    _planet_radius = radius;
}

string Planet::getName(){
    return _planet_name;
}

void Planet::setName(string name){
    _planet_name = name;
}

double Planet::getRadius(){
    return _planet_radius;
}

void Planet::setRadius(double radius){
    _planet_radius = radius;
}

double Planet::getVolume(){
    const double pi = 3.14159;

    return ((4/3)* pi * (_planet_radius * _planet_radius * _planet_radius));
}