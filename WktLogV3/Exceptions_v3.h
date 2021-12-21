//
//  Exceptions_v3.h
//  WktLogV3
//

#ifndef Exceptions_v2_h
#define Exceptions_v2_h

#include <iostream>
#include <stdexcept>
#include <exception>


using std::bad_alloc;
using std::out_of_range;
using std::exception;

using std::invalid_argument;
using std::string;

using namespace std;


/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class bad_vehicle_code declaration                     **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 FaMTFL 2019 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class bad_vehicle_code : public std::invalid_argument
{
public:
     bad_vehicle_code(string msg = "");
     
 }; // END class bad_vehicle_code
 
class no_such_object : public std::logic_error
{
public:
    no_such_object(std::string);
    
}; // END no_such_object
 
 

// ***************************************************************************
//  ****************************************************************************
//  **                                                                        **
//  **                 class too_many_passengers declaration                  **
//  **                                                                        **
//  **                 This code is provided to students                      **
//  **                 in COSC 052 FaMTFL 2019 to use in                        **
//  **                 part or in total for class projects.                   **
//  **                 Students may use this code as their                    **
//  **                 own, without any attribution.                          **
//  **                                                                        **
//  ****************************************************************************
//  ****************************************************************************/
//
// class too_many_passengers : public std::invalid_argument
// {
// public:
//      too_many_passengers(string msg = "");
//
//  }; // END class bad_vehicle_code
//
//
//
// ***************************************************************************
//  ****************************************************************************
//  **                                                                        **
//  **                 class too_much_cargo declaration                       **
//  **                                                                        **
//  **                 This code is provided to students                      **
//  **                 in COSC 052 FaMTFL 2019 to use in                        **
//  **                 part or in total for class projects.                   **
//  **                 Students may use this code as their                    **
//  **                 own, without any attribution.                          **
//  **                                                                        **
//  ****************************************************************************
//  ****************************************************************************/
//
// class too_much_cargo : public std::invalid_argument
// {
// public:
//      too_much_cargo(string msg = "");
//
// }; // END class bad_vehicle_code
//


#endif /* Exceptions_v2_h */
