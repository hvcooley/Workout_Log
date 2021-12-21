//
//  workoutTemplate.h
//  Workout Log
//
//  Created by Harrison Cooley on 7/19/20.
//  Copyright © 2020 Harrison Cooley. All rights reserved.
//

#ifndef workoutTemplate_h
#define workoutTemplate_h

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

#include "ExerciseTemplate.h"
#include "MTFList.h"

using namespace std;

class workout_template
{
    public:
        void setName(string newName);
        void setXciseNumber(int num);
    
        void addXrcise(exercise_template addOn);
        
        string name;
        int numberOfExercises;
        int xciseCount = 0;
    
        int timesCompleted; //this will be incremented every time a workout is logged, will help with reading the info to and from the file for saving
    
        //MTFL<exercise_template> exerciseList;
        //can no longer use this one because the MTFL of the workouts in the program gets confused with the interal MTFL of each workout for the exercises, probably because each will have same identifiers such as header, etc.
    
        exercise_template exerciseListTwo[10]; //this stores each exercise for this specific workout
    
    private:
        
        
    
        
    
    
};


void workout_template::setName(string newName)
{
    
    //here I need to add a portion that searches the databse to see if a workout with the name already exists. Then it will give the option to either overwrite the workout completely or edit it.
    
    cout << "Setting the new name of this workout to ";
    cout << newName << endl;
    
    name = newName;
    
    cout << "The new name of this workout is ";
    cout << name << endl;
}


void workout_template::setXciseNumber(int num)
{
    
    cout << "Setting the number of exercises in this workout to ";
    cout << num << endl;
    
    numberOfExercises = num;
    
    cout << "The number of exercises in this workout is ";
    cout << numberOfExercises << endl;
}



void workout_template::addXrcise(exercise_template addOn)
{
    
    if (xciseCount > numberOfExercises-1)
    {
        throw logic_error("Can't add an exercise to this workout, max number of exercises for this workout reached");
    }
    
    cout << "Going to insert the exercise " << addOn.name << " to the exercise list" << endl;
    
    //exerciseList.insert(addOn);
    
    exerciseListTwo[xciseCount] = addOn;
    
    xciseCount++;
}

#endif /* workoutTemplate_h */
