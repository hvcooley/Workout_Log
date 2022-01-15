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

void displayMenu()
{
    //at very begining here I will load in all the workouts with their exercises as well as compose a master list of all the exercises while it is loading in each exercise to the workout (so it will load the exercise into the workout then also add it to the master list of exercises and see if it is alread present)
    
    loadData("/Users/harrisoncooley/Desktop/WktLogV3/savedData.txt");
    
    
    cout << "Mr. Cooley's Database:" << endl;
    cout << "A) Workouts" << endl;
    cout << "B) Exercises" << endl << endl;
    
    cout << "Which would you like to access: ";
    
    char menuInput;
    
    cin >> menuInput;
    
    cout << endl;
    
    bool menuDone = false;
    
    while (menuDone == false)
    {
        if (menuInput == 'a' || menuInput == 'A')
        {
            
            cout << "Dislaying workouts..." << endl;
            
            //Display Workouts
            
            cout << "Will now go through the list of all the workouts added to the workout list below" << endl << endl;
            
            cout << "Workouts: \n";
            for (int f = 0; f < increment; f++)
            {
                
                cout << f+1 << ". " << listOfWorkouts[f].name << " (Contains " << listOfWorkouts[f].numXcises << " exercises in it)" << endl;
                
            }
            
            string viewWktDec; //How the user selects to either view a wkt or not
            
            int wktDec; //where the user will input the number of the workout they want to see
            
            cout << "Would you like to select a workout to view? Enter yes or no: ";
            
            cin >> viewWktDec;
            
            cout << endl;
            
            bool viewWktDone = false;
            
            while (viewWktDone == false)
            {
                std::for_each(viewWktDec.begin(), viewWktDec.end(), [](char & yn)
                {
                    yn = ::tolower(yn); //this function makes the answer all lowercase
                
                });
                
                cout << "the variable viewWktDec is: " << viewWktDec << endl;
                
                if (viewWktDec == "yes")
                {
                    cout << "Which workout would you like to see? Enter the number: ";
                    
                    cin >> wktDec;
                    
                    cout << endl;
                    
                    cout << wktDec << ". " << listOfWorkouts[wktDec-1].name << " (Contains " << listOfWorkouts[wktDec-1].numXcises << " exercises in it)" << endl;
                    
                    //need an if statement here to see if a wkt was selected properly
                    // and whether to continue
                    
                    cout << "Exercises in " << listOfWorkouts[wktDec-1].name << ": " << endl;
                
                    for (int i = 0; i < listOfWorkouts[wktDec-1].numXcises; i++)
                    {
                        cout << i+1 << ". " << listOfWorkouts[wktDec-1].exerciseList[i].name << endl;
                    }//end for loop 0 to numberOfExercises
                    
                    viewWktDone = true;
                    
                }//end if yes
                else if (viewWktDec == "no")
                {
                    
                    
                    viewWktDone = true;
                    
                }//end if no
                else
                {
                    cout << "Please re-enter your answer only yes or no is accepted: ";
                    cin >> viewWktDec;
                    cout << endl;
                    
                }//end else
                
            }//end while loop that only will allow a yes or no answer to be accepted
            
            menuDone = true;
            
        }//end if statement taking user to workout display (Choice A)
        
        else if (menuInput == 'b' || menuInput == 'B')
        {
            
            cout << "Displaying exercises..." << endl;
            
            //Display Exercises
            
            menuDone = true;
            
        }//end if statement taking user to exercise display (Choice B)
        
        else
        {
            cout << "Invalid choice, please select a or b here: ";
            
            cin >> menuInput;
            
            cout << endl;
        }//end else
        
    }//end while menuDone == false
    
    cout << endl;
    
}//end function displayMenu


void logWorkout()
{
    //this is the section I will use to add data of a workout I have created already but performed again. So I will need to make lists of sets and reps. (Maybe have a new list for completed sets or completed reps?...That could get complicated)
    
    //should add another line in the file with same name of workout right under it, then have the appropriate numbers for sets, weight, etc.
}

void newWorkout()
{
    workout_template newWorkout;
    
    string wktName;
    int inputXciseCount;
    
    cout << "What is this workout called?: ";
    cin >> wktName;
    cout << endl;
    
    newWorkout.setName(wktName);
    
    cout << "How many exercises are in this workout?: ";
    cin >> inputXciseCount;
    
    newWorkout.setXciseNumber(inputXciseCount);
    
    cout << "Will now start logging your exercises..." << endl;
    
    for (int i = 1; i < newWorkout.numXcises +1; i++)
    {
        exercise_template *inputXrcise = new exercise_template;
        
        string xciseName;
        int numSets;
        int numReps;
        float inputTime;
        int weight;
        string bWeightDecision;
        
        cout << "What is the name of exercise " << i << "?: ";
        cin >> xciseName;
        inputXrcise -> setName(xciseName);
        cout << endl;
        
        cout << "How many sets are in exercise " << i << "?: ";
        cin >> numSets;
        inputXrcise -> assignSetNumber(numSets);
        cout << endl;
        
        cout << "How many reps are there per set in exercise " << i << "?: ";
        cin >> numReps;
        inputXrcise -> assignReps(numReps);
        cout << endl;
        
        cout << "How much rest is there between each set in exercise " << i << " in minutes ?: ";
        cin >> inputTime;
        inputXrcise -> setRestTime(inputTime);
        cout << endl;
        
        cout << "Is this a bodyweight exercise or no. Enter yes or no: ";
        cin >> bWeightDecision;
        cout << endl;
        
        bool weightFinished = false;
        
        while (weightFinished == false)
        {
            std::for_each(bWeightDecision.begin(), bWeightDecision.end(), [](char & c)
            {
                c = ::tolower(c); //this function makes the answer all lowercase
            
            });
            
            cout << "the variable bWeightDecision is: " << bWeightDecision << endl;
            
            if (bWeightDecision == "yes")
            {
                
                weight = 0; //since this is a body weight exercise the weight is 0 (even thought a person weighs some amount of weight, it is just 0 to distinguish from the exercises using some sort of freewight/bar/etc
                
                inputXrcise -> setWeight(weight); //this function also alerts the exercise to set bodyweight to true as well
                
                weightFinished = true;
            
            }//end if yes
            else if (bWeightDecision == "no")
            {
                
                cout << "Since this is not a bodyweight exercise what is the weight being used in pounds?: ";
                cin >> weight;
                cout << endl;
                
                inputXrcise -> setWeight(weight); //this funciton also alrts the exercise to set bodyweight to false
                
                weightFinished = true;
            }//end if no
            else
            {
                cout << "Please re-enter your answer only yes or no is accepted: ";
                cin >> bWeightDecision;
                cout << endl;
            }//end else
            
        }//end while loop that only will allow a yes or no answer to be accepted
        
        newWorkout.addXrcise(*inputXrcise);
        //at the end of setting everything the template needs to be added to some sort of storage
        
    }//end for loop adding each exercise to the workout
    
    //now need a way to store the workout so it can be displayed in the menu
    
    cout << "About to start editing the data file" << endl;
    
    ofstream file;
    
    file.open("/Users/harrisoncooley/Desktop/Workout Log/Workout Log/savedData.txt", ios::app);
    
    if (!file)
    {
        throw invalid_argument("file did not open");
    }//END if
    
    string place;
    
    string data;
    
    file << endl << "?" << newWorkout.name << " " << newWorkout.numXcises << " ";
    
    //cout << "The number of exercises is: " << newWorkout.numberOfExercises << endl;
    
    for (int j = 0; j < newWorkout.numXcises; j++) //(int j = newWorkout.numberOfExercises -1; j > -1; j--)
    {
        //cout << newWorkout.exerciseList[j].name << endl;
        file << "*" << newWorkout.exerciseList[j].name << " ";
        
        //cout << newWorkout.exerciseList[j].sets << endl;
        file << newWorkout.exerciseList[j].sets << " ";
        
        //cout << newWorkout.exerciseList[j].reps << endl;
        file << newWorkout.exerciseList[j].reps << " ";
        
        //cout << newWorkout.exerciseList[j].restTime << endl;
        file << newWorkout.exerciseList[j].restTime << " ";
        
        //cout << newWorkout.exerciseList[j].restTime << endl;
        file << newWorkout.exerciseList[j].weight << " ";
        //will have 0s for bodyweight exercises, computer will realize this later and fill in for bodyweight when reading the data again to load at different time
        
    }

    file.close();
    
}



int main(int argc, const char * argv[])
{
    
    try
    {
        //Testing of the workout plan constructor
        wktPlan cooleyPlan;
        
        //Testing writing into a file
            
//            string password;
//            string password_check = "Titties";
//
//            cout  << "Welcome to Mr. Cooley's Workout Log. Please insert password to access control: ";
//
//            cin >> password;
//
//            cout  << endl;
//
//            if (password == password_check) //program started
//            {
//                //Display menu here.
//
//                int option;
//                int menuOption = 1;
//                int logWorkoutOption = 2;
//                int newWorkoutOption = 3;
//                int quitOption = 4;
//
//                cout << "What would you like to do?" << endl;
//                cout << "1. Display Menu" << endl;
//                cout << "2. Log a workout" << endl;
//                cout << "3. Create a new workout" << endl;
//                cout << "4. Quit" << endl;
//                cout << endl;
//
//                cout << "Enter a number: ";
//
//                cin >> option;
//
//                cout << endl;
//
//                if (option == menuOption)
//                {
//                    displayMenu();
//                }
//
//                else if (option == logWorkoutOption)
//                {
//                    logWorkout();
//                }
//
//                else if (option == newWorkoutOption)
//                {
//                    newWorkout();
//                }
//
//                else if (option == quitOption)
//                {
//                    cout << "Quitting..." << endl;
//                    cout << endl;
//                }
//
//            }//end if statement password check
//            else
//            {
//                cout << "Incorrect password program quitting." << endl;
//                //return 0; //maybe try break statement
//
//            }//end else ending program wrong password
        
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
