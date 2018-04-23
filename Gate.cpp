//
// Created by uauser on 4/23/18.
//

#include "Gate.h"

Gate::Gate(int _name, bool _occupied) : _name(_name), _occupied(_occupied) {
    _initcheck = this;
    _airplane = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_airplane == NULL, "Airplane must point to nullptr");
}

bool Gate::properlyInitialised() {
    return _initcheck == this;
}