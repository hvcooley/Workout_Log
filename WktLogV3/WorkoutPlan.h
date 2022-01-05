//
//  WorkoutPlan.h
//  Workout Log
//
//  Created by Harrison Cooley on 12/20/21.
//  Copyright © 2021 Harrison Cooley. All rights reserved.
//

#ifndef WorkoutPlan_h
#define WorkoutPlan_h

#include "workoutTemplate.h"
#include "ExerciseTemplate.h"

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
    int numWkts;
    
    //string goals[4];
    
    //array of all workouts
    workout_template *wkouts;
    
    //need a dynamically allocated array for the number of workouts in the regular repertoire
    
    //for longer workouts have a list of workouts that are interchanged for the regular ones
    // every like 2 weeks to spice it up (like test day or just diff wkt)
    
    wktPlan();
    ~wktPlan();
    
    //function that populates the plan's general information and the progress made
    void populatePlan();
        
    
private:
    
    
};

wktPlan::wktPlan(){
    
    string planName;
    int goalNum;
    
    cout << "Enter the name of the workout plan:" << endl;
    cin >> planName;
    cout << endl;
    
    name = planName;
    
    
    
    string goals[5];
    goals[0] = "Lose weight";
    goals[1] = "Gain muscle";
    goals[2] = "Improve fitness";
    goals[3] = "Gain weight";
    goals[4] = "Create your own";
    //= ["Lose weight", "Gain muscle", "Improve fitness", "Gain weight"];
    
    int numOptions = sizeof(goals)/sizeof(goals[0]);
    //cout << "The numoptions is " << numOptions << endl;
    
    cout << "Select from: " << endl;
    
    //when I figure out how to get the length of the array use that for the cap
    for (int i = 0; i < numOptions; i++)
    {
        cout << i+1 << ". " << goals[i] << endl;
    }
    cout << endl;
    cout << "to be the goal of this workout plan." << endl << endl;
    
    cout << "Enter the number of the goal you want:";
    cin >> goalNum;
    goalNum = goalNum-1;
    cout << endl;
    
    if (goals[goalNum] == "Create your own")
    {
        string custGoal;
        cout << "Please enter the custom goal you wish to achieve here: " << endl;
        cin >> custGoal;
        goalCat = custGoal;
    }
    else
    {
        goalCat = goals[goalNum];
    }
    
    cout << "goalCat is " << goalCat << endl;
    
    
    cout << "Enter how many workouts you want to be in the plan initially:" << endl;
    cin >> numWkts;
    cout << endl;
    
    wkouts = new workout_template[numWkts];
    
    for (int i = 0; i < numWkts; i++)
    {
        //cout << "Hello";
        cout << "Workout " << i << " is "; //<< wkouts[i] << endl;
    }
}

wktPlan::~wktPlan(){
    
}

#endif /* WorkoutPlan_h */
