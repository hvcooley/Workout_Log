//
//  Exceptions_v3.hpp
//  WktLogV3
//

#include <stdio.h>
#include "Exceptions_v3.h"

using namespace std;


//Bad vehicle exception
bad_vehicle_code::bad_vehicle_code(string msg): invalid_argument(msg)
{
    //cout << "In the bad_vehicle_code exception constructor" << endl;
}

no_such_object::no_such_object(string msg): logic_error(msg)
{
    //cout << "In the no_such_object exception constructor" << endl;
}


// Too many passengers exception
// too_many_passengers::too_many_passengers(string msg): invalid_argument(msg)
// {
//     cout << "In the too many passenger exception constructor" << endl;
// }
//
//
// Too much cargo exception
// too_much_cargo::too_much_cargo(string msg): invalid_argument(msg)
// {
//     cout << "In the too_much_cargo exception constructor" << endl;
// }
