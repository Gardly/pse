/*Dit is de runway waar de vliegtuigen in kunnen geplaatst worden
 *Author: Thimoty
 *Date: 23/04/2018
 *Version: 2.0
 */


#ifndef PSE_RUNWAY_H
#define PSE_RUNWAY_H

#include "Airplane.h"
#include "DesignByContract.h"
class Runway
{
private:
    Runway* _initcheck;

    Airplane* _airplane;

    unsigned int _length;

    bool _status;

    std::string _name;
    std::string _type;
    std::string _airport;
public:
    Runway(int _length, const std::string &_name, const std::string &_type, const std::string &_airport);

    bool properlyInitialised();

    void addAirplane(Airplane* airplane);
    void removeAirplane();

    bool is_status();
    unsigned int get_length();
    Airplane *get_airplane();
    const std::string &get_name();
    const std::string &get_type();
    const std::string &get_airport();

    void set_length(unsigned int _length);
    void set_name(const std::string &_name);
    void set_type(const std::string &_type);
    void set_airport(const std::string &_airport);
};


#endif //PSE_RUNWAY_H
