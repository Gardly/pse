//
// Created by uauser on 4/23/18.
//

#ifndef PSE_GATE_H
#define PSE_GATE_H

#include <iostream>
#include "Airplane.h"

class Gate {
public:
    Gate* _initcheck;
    Airplane* _airplane;

    int _name;

    bool _occupied;

    Gate(int _name, bool _occupied);

    bool properlyInitialised();
};


#endif //PSE_GATE_H
