//
//  main.cpp
//  Workout Log
//
//  Created by Harrison Cooley on 12/20/21
//  Copyright © 2020 Harrison Cooley. All rights reserved.
//

#include <iostream>
#include "main.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    try
    {
        //Testing of the workout plan constructor
        //wktPlan cooleyPlan;
            
        string password;
        string password_check = "Titties";

        cout  << "Welcome to Mr. Cooley's Workout Log. Please insert password to access control: ";

        cin >> password;

        cout  << endl;

        if (password == password_check) //program started
        {
            //Display menu here.

            int option;
            int menuOption = 1;
            int logWorkoutOption = 2;
            int newWorkoutOption = 3;
            int quitOption = 4;

            cout << "What would you like to do?" << endl;
            cout << "1. Display Menu" << endl;
            cout << "2. Log a workout" << endl;
            cout << "3. Create a new workout" << endl;
            cout << "4. Quit" << endl;
            cout << endl;

            cout << "Enter a number: ";

            cin >> option;

            cout << endl;

            if (option == menuOption)
            {
                displayMenu();
            }

            else if (option == logWorkoutOption)
            {
                logWorkout();
            }

            else if (option == newWorkoutOption)
            {
                newWorkout();
            }

            else if (option == quitOption)
            {
                cout << "Quitting..." << endl;
                cout << endl;
            }

        }//end if statement password check
        else
        {
            cout << "Incorrect password program quitting." << endl;
            //return 0; //maybe try break statement

        }//end else ending program wrong password
        
    }//end try

    catch (no_such_object &e)
    {
        cout << e.what() << endl;
        cout << "no objects in the list" << endl;
    }

    catch (out_of_range &e)
    {

        cout << "caught out_of_range in function main()\n";
        cout << e.what() << endl;

    }

    catch(invalid_argument &e)
    {
        cout << "caught invalid_argument in function main()\n" << endl;
        cout << e.what() << endl;
    }

    catch(logic_error &e)
    {
        cout << "caught logic_error in function main()\n" << endl;
        cout << e.what() << endl;
    }

    catch (std::bad_alloc &e)
    {

        cout << "caught bad_alloc in function main()\n";
        cout << e.what() << endl;

    }

    catch (...)
    {
        cout << "unknown exception caught in function main()\n";
    }
    

    return 0;
    
}//end function main
