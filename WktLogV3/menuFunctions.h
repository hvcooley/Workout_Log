//
//  menuFunctions.h
//  WktLogV3
//
//  Created by Harrison Cooley on 1/15/22.
//

#ifndef menuFunctions_h
#define menuFunctions_h

#include "ExerciseTemplate.h"
#include "workoutTemplate.h"
#include "RunTemplate.h"
#include "WorkoutPlan.h"
#include "loadWktData.h"

#include <sstream>

void printWkts(vector<workout_template> data)
{
    int dataSize = data.size();
    cout << "Workouts: \n";
    for (int f = 0; f < dataSize; f++)
    {
        
        cout << f+1 << ". " << data[f].name << " (Contains " << data[f].numXcises << " exercises in it)" << endl;
        
    }
}

void displayMenu(vector<workout_template> data)
{
    //at very begining here I will load in all the workouts with their exercises as well as compose a master list of all the exercises while it is loading in each exercise to the workout (so it will load the exercise into the workout then also add it to the master list of exercises and see if it is alread present)
    
    //vector<workout_template> data;
    //loadData("/Users/harrisoncooley/Desktop/WktLogV3/WktLogV3/savedData.txt", data);
    
    int dataSize = data.size();
    
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
            
            bool viewWktDone = false;
            
            while (viewWktDone == false)
            {
                
                cout << "Workouts: \n";
                for (int f = 0; f < dataSize; f++)
                {
                    
                    cout << f+1 << ". " << data[f].name << " (Contains " << data[f].numXcises << " exercises in it)" << endl;
                    
                }
                
                int wktDec; //where the user will input the number of the workout they want to see or 0 for menu
                
                cout << "Enter the number of the workout you wish to view or 0 to return to menu: ";
                
                cin >> wktDec;
                
                cout << endl;
                
                //cout << "the variable wktDec is: " << wktDec << endl;
                
                if (wktDec != 0)
                {
                    
                    cout << wktDec << ". " << data[wktDec-1].name << " (Contains " << data[wktDec-1].numXcises << " exercises in it)" << endl;
                    
                    //need an if statement here to see if a wkt was selected properly
                    // and whether to continue
                    
                    cout << "Exercises in " << data[wktDec-1].name << ": " << endl;
                
                    for (int i = 0; i < data[wktDec-1].numXcises; i++)
                    {
                        cout << i+1 << ". " << data[wktDec-1].exerciseList[i].name << endl;
                    }//end for loop 0 to numberOfExercises
                    
                    //now ask if they want to return to workouts or main menu
                    cout << endl << endl;
                    cout << "Enter 1 to view workouts again, 0 to return to main menu: ";
                    
                    bool contDec;
                    
                    cin >> contDec;
                    cout << endl << endl;
                    
                    if (contDec == 0) //end the loop displaying the wkts
                    {
                        viewWktDone = true;
                    }
                    
                    
                }//end if yes
                else if (wktDec == 0)
                {
                    
                    viewWktDone = true;
                    
                }//end if no
                else
                {
                    cout << "Please re-enter your answer as a number from 1 to ";
                    cout << dataSize << ": ";
                    cin >> wktDec;
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


workout_template logWorkout(string fP)
{
    //this is the section I will use to add data of a workout I have created already but performed again. So I will need to make lists of sets and reps. (Maybe have a new list for completed sets or completed reps?...That could get complicated)
    
    //first create a workout object
    workout_template newWkt;
    
    //ask for the data of the workout
    
    //enter the date
    cout << "Enter the date in the form mm/dd/yyyy:";
    string newDate;
    cin >> newDate;
    string monStr = newDate.substr(0,2);
    cout << "The monStr is " << monStr << endl;
    string dayStr = newDate.substr(3,2);
    cout << "The dayStr is " << dayStr << endl;
    string yrStr = newDate.substr(6,4);
    cout << "The yrStr is " << yrStr << endl;
    
    //transform the strings into ints
    int dayNum;
    int monNum;
    int yrNum;
    stringstream ss;
    ss << monStr;
    ss >> monNum;
    ss.clear();
    cout << "The monNum is " << monNum << endl;
    ss << dayStr;
    ss >> dayNum;
    ss.clear();
    cout << "The dayNum is " << dayNum << endl;
    ss << yrStr;
    ss >> yrNum;
    ss.clear();
    cout << "The yrNum is " << yrNum << endl;
    
    //set the date in the wkt object
    newWkt.setDate(monNum, dayNum, yrNum, newDate);
    
    //Create the workout name
    string wktName;
    cout << "Enter the name of this workout:";
    cin >> wktName;
    //set wkt name in the wkt object
    newWkt.setName(wktName);
    
    //Ask for the number of exercises
    int numXcises;
    cout << "Enter the number of exercises in this workout: ";
    cin >> numXcises;
    cout << endl;
    //set number exerceises
    newWkt.setXciseNumber(numXcises);
    
    //defaut exercise to edit and be repeatedly inserted
    exercise_template reUseXcise;
    
    //use for loop to create exercises and ask for info in each
    for (int i = 0; i < numXcises; i++)
    {
        //ask for exercise name
        string xCiseName;
        cout << "Enter exercise " << i << "'s name: ";
        cin >> xCiseName;
        //set the name
        reUseXcise.setName(xCiseName);
        
        //ask for number of sets in the exercise
        int numSets;
        cout << "Enter " << xCiseName << "'s number of sets: ";
        cin >> numSets;
        //assign the number of sets
        reUseXcise.assignSetNumber(numSets);
        
        //ask for the number of reps in a set
        int numReps;
        cout << "Enter " << xCiseName << "'s number of reps per set: ";
        cin >> numReps;
        //assign the reps per set
        reUseXcise.assignReps(numReps);
        
        //ask if there is weight in the exercise and if so how much
        bool bodyWght;
        cout << "Is " << xCiseName << " a bodyweight exercise? Enter 1 for yes, 0 for no: ";
        cin >> bodyWght;
        if (bodyWght == 0) //has weight
        {
            //get how much weight is used
            int wght;
            cout << "Enter the weight used in " << xCiseName << ": ";
            cin >> wght;
            reUseXcise.setWeight(wght);
            
        }
        else //is a bodyweight exercise
        {
            reUseXcise.setWeight(0);
        }
        
        //ask for the rest time between sets
        float restTime;
        cout << "Enter the rest time between sets in seconds: ";
        cin >> restTime;
        reUseXcise.setRestTime(restTime);
        
        //add new exercise to the workout
        newWkt.addXrcise(reUseXcise);
        
    }//end for loop over all exercises
    
    
    //add data to the file
    //ofstream loadData;
    
    //string filePath = fP;
    //loadData.open(fP);
    
    
    //should add another line in the file with same name of workout right under it, then have the appropriate numbers for sets, weight, etc.
    
    return newWkt;
}

workout_template newWorkout(string fP)
{
    workout_template newWkt;
    
    //enter the date
    cout << "Enter the date in the form mm/dd/yyyy:";
    string newDate;
    cin >> newDate;
    string monStr = newDate.substr(0,2);
    cout << "The monStr is " << monStr << endl;
    string dayStr = newDate.substr(3,2);
    cout << "The dayStr is " << dayStr << endl;
    string yrStr = newDate.substr(6,4);
    cout << "The yrStr is " << yrStr << endl;
    
    //transform the strings into ints
    int dayNum;
    int monNum;
    int yrNum;
    stringstream ss;
    ss << monStr;
    ss >> monNum;
    ss.clear();
    cout << "The monNum is " << monNum << endl;
    ss << dayStr;
    ss >> dayNum;
    ss.clear();
    cout << "The dayNum is " << dayNum << endl;
    ss << yrStr;
    ss >> yrNum;
    ss.clear();
    cout << "The yrNum is " << yrNum << endl;
    
    //set the date in the wkt object
    newWkt.setDate(monNum, dayNum, yrNum, newDate);
    
    //Create the workout name
    string wktName;
    cout << "Enter the name of this workout:";
    cin >> wktName;
    //set wkt name in the wkt object
    newWkt.setName(wktName);
    
    //Ask for the number of exercises
    int numXcises;
    cout << "Enter the number of exercises in this workout: ";
    cin >> numXcises;
    cout << endl;
    //set number exerceises
    newWkt.setXciseNumber(numXcises);
    
    cout << "Will now start logging your exercises..." << endl;
    
    for (int i = 1; i < newWkt.numXcises +1; i++)
    {
        exercise_template *inputXrcise = new exercise_template;
        
        int weight;
        string bWeightDecision;
        
        //ask for exercise name
        string xCiseName;
        cout << "Enter exercise " << i << "'s name: ";
        cin >> xCiseName;
        //set the name
        inputXrcise -> setName(xCiseName);
        
        //ask for number of sets in the exercise
        int numSets;
        cout << "Enter " << xCiseName << "'s number of sets: ";
        cin >> numSets;
        //assign the number of sets
        inputXrcise -> assignSetNumber(numSets);
        
        //ask for the number of reps in a set
        int numReps;
        cout << "Enter " << xCiseName << "'s number of reps per set: ";
        cin >> numReps;
        //assign the reps per set
        inputXrcise -> assignReps(numReps);
        
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
        
        //ask for the rest time between sets
        float restTime;
        cout << "Enter the rest time between sets in seconds: ";
        cin >> restTime;
        inputXrcise -> setRestTime(restTime);
        
        newWkt.addXrcise(*inputXrcise);
        //at the end of setting everything the template needs to be added to some sort of storage
        
    }//end for loop adding each exercise to the workout
    
    //now need a way to store the workout so it can be displayed in the menu
    
    cout << "About to start editing the data file" << endl;
    
    ofstream file;
    
    file.open(fP, ios::app);
    
    if (!file)
    {
        throw invalid_argument("file did not open");
    }//END if
    
    string place;
    
    string data;
    
    file << newWkt.dateStr << " " << newWkt.name << " " << newWkt.numXcises << " ";
    
    //cout << "The number of exercises is: " << newWkt.numberOfExercises << endl;
    
    for (int j = 0; j < newWkt.numXcises; j++) //(int j = newWkt.numberOfExercises -1; j > -1; j--)
    {
        
        //cout << newWkt.exerciseList[j].name << endl;
        file << "*" << newWkt.exerciseList[j].name << " ";
        
        //cout << newWkt.exerciseList[j].sets << endl;
        file << newWkt.exerciseList[j].sets << " ";
        
        //cout << newWkt.exerciseList[j].reps << endl;
        file << newWkt.exerciseList[j].reps << " ";
        
        //cout << newWkt.exerciseList[j].restTime << endl;
        file << newWkt.exerciseList[j].restTime << " ";
        
        //cout << newWkt.exerciseList[j].restTime << endl;
        file << newWkt.exerciseList[j].weight << " ";
        //will have 0s for bodyweight exercises, computer will realize this later and fill in for bodyweight when reading the data again to load at different time
        
    }

    file << endl;
    
    file.close();
    
    return newWkt;
    
}




#endif /* menuFunctions_h */
