#include <iostream>
#include <cmath>
#include "Event.h"

ClassImp(Event)

// defailt constructor - ROOT needs the default one where everything is set to 0
Event::Event() :
// initialize all members to null
px{0},
py{0},
pz{0}
{
}
// another constructor
Event::Event(Double_t px, Double_t py, Double_t pz) :
// something should go here
px{px},
py{py},
pz{pz}
{
    Magnitude();
}
// destructor
Event::~Event(){
    // right now I am empty
}

Double_t Event::Magnitude() {
    return sqrt( (px*px) + (py*py) + (pz*pz) );
}