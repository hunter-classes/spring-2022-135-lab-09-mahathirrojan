#include <iostream>
#include "funcs.h"
#include <cmath>
#include <string> 
#include <sstream>

// Task A: Length and distance in 3d space 

double length(Coord3D *p){
    return sqrt((pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2)));

}
// Task B: 
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    return length(p1) < length(p2) ? p2 : p1;
}
// Task C: 
void move(Coord3D * ppos, Coord3D *pvel, double dt){

    ppos->x = ppos->x + pvel->x * dt; 
    ppos->y = ppos->y + pvel->y * dt; 
    ppos->z = ppos->z + pvel->z * dt; 
}

// Task E: 

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *points = new Coord3D;
    *points = {x,y,z};

    return points; 
}

void deleteCoord3D(Coord3D *p){
    delete p; 
}
