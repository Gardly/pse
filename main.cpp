#include <iostream>
#include "Airplane.h"
#include "Runway.h"

int main() {
    Airplane* airplane = new Airplane("1","EF566","Winchester",Approaching);
    std::cout<< airplane->get_callsign() << std::endl;
    std::cout<< airplane->get_number() << std::endl;
    std::cout<< airplane->get_model() << std::endl;
    std::cout<< airplane->get_status() << std::endl;
    airplane->set_status(StandingAtGate);
    airplane->set_callsign("sdfj");
    airplane->set_number("2");
    airplane->set_model("blo");
    std::cout<< airplane->get_callsign() << std::endl;
    std::cout<< airplane->get_number() << std::endl;
    std::cout<< airplane->get_model() << std::endl;
    std::cout<< airplane->get_status() << std::endl;

    Runway runway(1,"boo", "blau", "donau");
    runway.addAirplane(airplane);
    runway.removeAirplane();
    std::cout<< runway.get_type() << std::endl;
    std::cout<< runway.get_airport() << std::endl;
    std::cout<< runway.get_name() << std::endl;
    std::cout<< runway.get_length() << std::endl;
    std::cout<< runway.get_airplane() << std::endl;

    return 0;
}