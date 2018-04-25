//
// Created by uauser on 4/23/18.
//

#ifndef PSE_AIRPORT_H
#define PSE_AIRPORT_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Gate.h"
#include "Runway.h"
#include "Airplane.h"


/*
 *
 * REQUIRES EN ENSURES IN HEADERS ZETTE ALS COMMENT
 *
 *
 *
 */

class AirTrafficController;
class Airport
{
private:
    Airport* _initcheck;

    std::vector<Gate*> _gates;
    std::vector<Runway*> _runways;

    unsigned int _gatesize;
    unsigned int _amountRunways;

    std::string _name;
    std::string _iata;
    std::string _callsign;

    void addAirplaneToGate(Airplane* airplane);
    void addAirplaneToRunway(Airplane* airplane);

    void removeAirplaneOfGate(Airplane* airplane);
    void removeAirplaneOfRunway(Airplane* airplane);

public:
    Airport(unsigned int _gatesize, unsigned int _amountRunways, const std::string &_name, const std::string &_iata,
            const std::string &_callsign);

    bool properlyInitialised();

    void gateprotocol(Airplane* airplane, unsigned int passengers);

    //
    void landingprotocol(Airplane* airplane);
    void takeoffprotocol(Airplane* airplane);
};


#endif //PSE_AIRPORT_H
