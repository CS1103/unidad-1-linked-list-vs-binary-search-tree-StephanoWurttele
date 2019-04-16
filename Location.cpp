//
// Created by ruben on 4/5/19.
//

#include "Location.h"

Location::Location(
    int _position_id,
    std::string _state_code,
    std::string _county,
    double _latitude,
    double _longitude,
    std::string _line,
    std::string _construction):position_id(_position_id),
    state_code(_state_code),
    county(_county),
    latitude(_latitude),
    longitude(_longitude),
    line(_line),
    construction(_construction){};

    int Location::getpos(){
        return position_id;
    };
// Defina los metodos que crea necesario
