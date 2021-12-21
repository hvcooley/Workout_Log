//
//  WorkoutPlan.h
//  Workout Log
//
//  Created by Harrison Cooley on 12/20/21.
//  Copyright © 2021 Harrison Cooley. All rights reserved.
//

#ifndef WorkoutPlan_h
#define WorkoutPlan_h

#include "workoutTemplate"
#include "ExerciseTemplate"

#include <iostream>
#include <string>

using namespace std;

class wktPlan
{
public:
    
    //general information
    string name;
    string goalCat;
    string goalSubCat;
    int timePeriod;
    int daysPerWeek;
    int hrsPerWkt;
    
    //need a dynamically allocated array for the number of workouts in the regular repertoire
    
    //for longer workouts have a list of workouts that are interchanged for the regular ones
    // every like 2 weeks to spice it up (like test day or just diff wkt)
    
    wktPlan();
    ~wktPlan();
    
    //function that populates the plan's general information and the progress made
    populatePlan();
        
    
private:
    
    
};


#endif /* WorkoutPlan_h */
