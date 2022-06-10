//
//  loadWktData.h
//  WktLogV3
//
//  Created by Harrison Cooley on 1/14/22.
//

#ifndef loadWktData_h
#define loadWktData_h

#include "ExerciseTemplate.h"
#include "workoutTemplate.h"
#include "WorkoutPlan.h"

void loadData(string fP, vector<workout_template> &data)
{
    ifstream loadData;
    
    string filePath = fP;
    loadData.open(fP);
    
    //loadData.open("/Users/harrisoncooley/Desktop/WktLogV3/savedData.txt");
    
    if (!loadData)
    {
        throw invalid_argument("file did not open");
    }//END if
    
    //the data storage is a vector passed as reference into the function
    
    char garbage; //to get rid of underscores and other chars
    
    //reusable variables for the workout to populate
    string wktName;
    int numXrcises;
    
    //for the date of the workout
    int m;
    int d;
    int y;
    
    //this is for the /s in the date
    char ch;
    
    //this will be the exercise template I use to populate each workout
    exercise_template reUsableExercise;
    
    //reusable variables for each exercise inserted
    string XrciseName;
    int XrciseSets;
    int XrciseReps;
    float XrciseRest; //should add a conversion later for minutes vs seconds
    int XrciseWeight;
    
    bool goodToInsert; //lets the program know to insert the workout template as a new one
    
    int increment = 0; //the increment for how many workouts are added
    
    cout << "Will now read file" << endl;
    
    loadData.ignore(5, '\n');
    loadData.ignore(1, '\n');
    
    //Here start loading in each line at a time into a workout
    
    while (loadData >> m >> ch >> d >> ch >> y >> wktName >> numXrcises)
    {
        goodToInsert = false;
        
        //this will be the workout template I repeatedly put data into then insert into the list
        workout_template reUsableWorkout;
        
        goodToInsert = true;
        
        cout << endl << endl;
        
        cout << "The workout name is: " << wktName << endl;
        
        //loadData >> garbage; //get rid of underscore
        
        //loadData >> numXrcises;
        
        cout << "The number of exercises is: " << numXrcises << endl;
        
        //loadData >> garbage; //get rid of underscore
        
        //set name of the workout to be inserted into list of all workouts
        reUsableWorkout.setName(wktName);
        
        reUsableWorkout.setDate(m, d, y, " ");
        
        //set how may exercises are in this workout and initialize the array
        reUsableWorkout.setXciseNumber(numXrcises);
        
        for (int h = 0; h < numXrcises; h++)
        {
            cout << "Inside for loop loading each workout" << endl;
            
            loadData >> garbage; //get rid of the *
            
            loadData >> XrciseName; //get name of exercise
            reUsableExercise.setName(XrciseName); //set name of exercise into reusable
            
            loadData >> XrciseSets; //get number of sets for this exercise
            reUsableExercise.assignSetNumber(XrciseSets); //set number of sets into reusable
            
            loadData >> XrciseReps; //get reps per set for exercise
            reUsableExercise.assignReps(XrciseReps); //set reps for the reusable
            
            loadData >> XrciseRest;
            reUsableExercise.setRestTime(XrciseRest);
            
            loadData >> XrciseWeight;
            reUsableExercise.setWeight(XrciseWeight);
            
            reUsableWorkout.addXrcise(reUsableExercise); //add the reusable exercise to the wkt, which will then repeat for every exercise
            
        }//end for loop for number of exercises
            
        
        if (goodToInsert == true)
        {
            
            cout << "About to insert the re-usable workout named: " << reUsableWorkout.name << endl;
            
            //listOfWorkouts.insert(reUsableWorkout);
            
            //listOfWorkouts[increment] = reUsableWorkout;
            
            data.push_back(reUsableWorkout);
            
            //reUsableWorkout.resetWkt();
            //increment++;
            
        }//end if goodToInsert == true
        
    }//end while loadData
    
    cout << "Just completed insertion..." << endl << endl;
    
    cout << endl << endl << endl;
    
    //end of loading data from the file
    
    loadData.close();
    
}

#endif /* loadWktData_h */
