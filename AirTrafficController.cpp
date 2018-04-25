//
// Created by uauser on 4/25/18.
//

#include "AirTrafficController.h"

AirTrafficController::AirTrafficController(const std::string &_name) : _name(_name) {
    _initcheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}


bool AirTrafficController::properlyInitialised() {
    return _initcheck == this;

}
void AirTrafficController::landing(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't initialised when claling landing");

    if(airplane->get_height() == 10000){
        std::cout << airplane->get_callsign() << " asking permission to land" << std::cout;

    }
    else if(airplane->get_height() == 5000){

    }
    else if(airplane->get_height() < 3000){

    }
    else if(airplane->get_status() == JustLanded){

    }

}

