/*Dit zijn de airplanes, deze hebben een take off en een landing sequence die men kan oproepen
 *@author: Thimoty
 *@date: 23/04/2018
 *version: 2.0
 */


#ifndef PSE_AIRPLANE_H
#define PSE_AIRPLANE_H

#include "DesignByContract.h"
#include <iostream>

enum Status {StandingAtGate, StandingAtRunway, InTheAir, Approaching};

class Airplane
{
private:
    Airplane* _initcheck;

    unsigned int _status;
    unsigned int _fuel;
    unsigned int _height;
    unsigned int _passengers;

    std::string _model;
    std::string _number;
    std::string _callsign;
public:
    Airplane(std::string number,std::string callsign, std::string model, unsigned int status);

    bool properlyInitialised();

    unsigned int get_fuel();
    unsigned int get_status();
    unsigned int get_height();
    unsigned int get_passengers();
    const std::string &get_model();
    const std::string &get_number();
    const std::string &get_callsign();

    void set_fuel(unsigned int _fuel);
    void set_status(unsigned int _status);
    void set_height(unsigned int _height);
    void set_passengers(unsigned int _passengers);
    void set_model(const std::string &_model);
    void set_number(const std::string &_number);
    void set_callsign(const std::string &_callsign);
};


#endif //PSE_AIRPLANE_H
