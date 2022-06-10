//
//  main.cpp
//  Workout Log
//
//  Created by Harrison Cooley on 12/20/21
//  Copyright © 2020 Harrison Cooley. All rights reserved.
//

#include <iostream>
#include "main.h"

const int menuOption = 1;
const int logWorkoutOption = 2;
const int newWorkoutOption = 3;
const int quitOption = 4;

using namespace std;

//base class to have a vector that never has to be reloaded with data
class wktLog
{
public:
    vector<workout_template> data;
    unordered_map<string, exercise_template> allXcises;
private:
};

int main(int argc, const char * argv[])
{
    
    try
    {
        //Testing of the workout plan constructor
        //wktPlan cooleyPlan;
            
        string password;
        string password_check = "Fitness";

        cout  << "Welcome to Mr. Cooley's Workout Log. Please insert password to access control: ";

        cin >> password;

        cout  << endl;

        if (password == password_check) //program started
        {
            
            wktLog myLog;
            
            string dataFile = "/Users/harrisoncooley/Desktop/WktLogV3/WktLogV3/savedData.txt";
            
            loadData(dataFile, myLog.data);
            
            //Display menu here.
            int option;
            
            bool done = false;
            
            while (done == false)
            {
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
                    displayMenu(myLog.data);
                }

                else if (option == logWorkoutOption)
                {
                    cout << "Before logging workout" << endl;
                    printWkts(myLog.data);
                    workout_template addedWkt = logWorkout(dataFile);
                    myLog.data.push_back(addedWkt);
                    cout << "After logging workout" << endl;
                    printWkts(myLog.data);
                }

                else if (option == newWorkoutOption)
                {
                    cout << "Before logging workout" << endl;
                    printWkts(myLog.data);
                    workout_template addedWkt = newWorkout(dataFile);
                    myLog.data.push_back(addedWkt);
                    cout << "After logging workout" << endl;
                    printWkts(myLog.data);
                }

                else if (option == quitOption)
                {
                    cout << "Quitting..." << endl;
                    cout << endl;
                    done = true;
                }
            }//end while done == false

        }//end if password is good
        else
        {
            cout << "Incorrect password program quitting." << endl;
            //return 0; //maybe try break statement

        }//end else wrong password
        
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
