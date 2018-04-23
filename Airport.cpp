//
// Created by uauser on 4/23/18.
//

#include "Airport.h"

Airport::Airport(unsigned int _gatesize, unsigned int _amountRunways, const std::string &_name, const std::string &_iata,
                 const std::string &_callsign) : _gatesize(_gatesize), _amountRunways(_amountRunways), _name(_name),
                                                 _iata(_iata), _callsign(_callsign) {
    _initcheck = this;
    for(unsigned int x = 0;x < _gatesize;x++){
        _gates.push_back(new Gate(x + 1, false));
    }

    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_runways.size() == 0, "Runways has to be initialised correctly");
    ENSURE(_gates.size() == 0, "Gates has to be initialised correctly");
}

bool Airport::properlyInitialised() {
    return _initcheck == this;
}

void Airport::landingprotocol(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling landingprotocol()");
    REQUIRE(airplane->get_status() == Approaching, "Airplane must be approaching in order to land");

    unsigned int preheight = airplane->get_height();

    while(airplane->get_height() >= 10000){
        unsigned int postheight = airplane->get_height() - 1000;
        airplane->set_height(postheight);
        ENSURE(preheight < postheight, "Descending failure");
    }
    ENSURE(airplane->get_height() == 10000, "Airplane must be at 10000 ft in order to land");

    std::cout << airplane->get_callsign() << " is approaching " << _name << " at " << airplane->get_height();
    while(airplane->get_height() >= 1000){
        airplane->set_height(airplane->get_height() - 1000);
        std::cout<< airplane->get_callsign() << " descended to " << airplane->get_height() << std::endl;
    }

    ENSURE(airplane->get_height() == 1000, "Airplane must be at 1000 ft");

    addAirplaneToRunway(airplane);
    addAirplaneToRunway(airplane);
}

void Airport::runwayprotocol(Airplane *airplane) {
    REQUIRE(airplane->get_status() == StandingAtRunway, "Airplane must be at the runway");
}

void Airport::gateprotocol(Airplane *airplane) {
    REQUIRE(airplane->get_status() == StandingAtGate, "Airplane must be at gate");

}
void Airport::takeoffprotocol(Airplane *airplane) {
    REQUIRE(airplane->get_status() == StandingAtGate, "Airplane must be at gate");

}


void Airport::addAirplaneToGate(Airplane *airplane) {
    REQUIRE(airplane->get_status() == StandingAtRunway, "Airplane has to be standing at the runway in order to taxi");
    REQUIRE(_gates.size() <= _gatesize, "Amount of gates don't match with the given amount of gates");
    for(unsigned int x = 0; x < _runways.size(); x++) {
         if(_runways[x]->get_airplane()->get_model() == airplane->get_model() &&
            _runways[x]->get_airplane()->get_number() == airplane->get_number() &&
            _runways[x]->get_airplane()->get_callsign() == airplane->get_callsign()){
            _runways[x]->removeAirplane();
         }
    }
    for(unsigned int x = 0; x < _gates.size();x++){
        if(!_gates[x]->_occupied){
            std::cout << airplane->get_callsign() << " is taxiing to Gate" << _gates[x]->_name<< std::endl;
            _gates[x]->_airplane = airplane;
            ENSURE(_gates[x]->_airplane->get_model() == airplane->get_model() &&
                   _gates[x]->_airplane->get_number() == airplane->get_number() &&
                   _gates[x]->_airplane->get_callsign() == airplane->get_callsign(),
                   "Airplane in gate doesn't match added airplane");
            _gates[x]->_airplane->set_status(StandingAtGate);
            ENSURE(_gates[x]->_airplane->get_status() == StandingAtGate, "Airplane's status isn't standing at gate");
            std::cout << airplane ->get_callsign() << " is standing at Gate" << _gates[x]->_name << std::endl;
        }
    }
}

void Airport::addAirplaneToRunway(Airplane *airplane) {
    REQUIRE(_runways.size() <= _amountRunways, "Amount of runways don't match with the given amount of runways");
    for(unsigned int x = 0; x < _runways.size(); x++){
        if(!_runways[x]->is_status()){
            std::cout << airplane->get_callsign() << " is landing at Antwerp International Airport on runway "
                      << _runways[x]->get_name()  << std::endl;

            _runways[x]->addAirplane(airplane);

            std::cout << airplane->get_callsign() << " has landed at Antwerp International Airport on runway"
                      << _runways[x]->get_name()  << std::endl;
            break;
        }
    }
}

void Airport::removeAirplaneOfGate(Airplane *airplane) {

}

void Airport::removeAirplaneOfRunway(Airplane *airplane) {

}
