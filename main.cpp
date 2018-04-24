#include <iostream>
#include "Airplane.h"
#include "Runway.h"
#include "Airport.h"

int main() {
    Airplane* airplane = new Airplane("1","EF566","Winchester",Approaching);
    std::cout<< airplane->get_callsign() << std::endl;
    std::cout<< airplane->get_number() << std::endl;
    std::cout<< airplane->get_model() << std::endl;
    std::cout<< airplane->get_status() << std::endl;

    Airplane* airplane1 = new Airplane("556", "F16", "Win100", Approaching);

//    Runway runway(1,"boo", "blau", "donau");
//    runway.addAirplane(airplane);
//    runway.removeAirplane();
//    std::cout<< runway.get_type() << std::endl;
//    std::cout<< runway.get_airport() << std::endl;
//    std::cout<< runway.get_name() << std::endl;
//    std::cout<< runway.get_length() << std::endl;
//    std::cout<< runway.get_airplane() << std::endl;

    Airport airport(2,1,"Zaventem","f444","Echo");
    airport.landingprotocol(airplane);
    airport.landingprotocol(airplane1);
    airport.takeoffprotocol(airplane);
//    airplane->set_status(Approaching);
//    airplane->set_height(10000);
    airport.landingprotocol(airplane);
    return 0;
}