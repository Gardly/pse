//
// Created by uauser on 4/25/18.
//

#ifndef PSE_AIRTRAFFICCONTROLLER_H
#define PSE_AIRTRAFFICCONTROLLER_H

#include <iostream>
#include "Airport.h"
#include "DesignByContract.h"
class Airport;

class AirTrafficController {
private:
    AirTrafficController* _initcheck;
    Airplane* _holdingpattern[2];
    std::string _name;
public:
    void landing(Airplane* airplane);

    AirTrafficController(const std::string &_name);
    bool properlyInitialised();
};


#endif //PSE_AIRTRAFFICCONTROLLER_H
