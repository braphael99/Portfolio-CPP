#include "Planet.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>

using namespace std;

int maxRadius(Planet planet_array[], const int PLANET_ARRAY_SIZE){
    int maxSize = 0;
    int retIndex = 0;

    for(int i = 0; i < PLANET_ARRAY_SIZE; i++){
        if(planet_array[i].getRadius() > maxSize){
            maxSize = planet_array[i].getRadius();
            retIndex = i;
        }
    }


    return retIndex;
}

int main(){
    Planet Mars = Planet();
    Mars.setName("Mars");
    Mars.setRadius(3390);
    Mars.getName();
    Mars.getRadius();
    Mars.getVolume();

    Planet MarsTwo = Planet("Mars", 3390);
    Planet Earth = Planet("Earth",6378);
    Planet planets[2] = {Earth, MarsTwo};
    Planet planetsTie[4] = {Earth, Earth, MarsTwo, Mars};

    int maximumRadIndex = maxRadius(planetsTie, 4);

    return 0;
}