//
//  ExerciseTemplate.h
//  Workout Log
//
//  Created by Harrison Cooley on 7/19/20.
//  Copyright © 2020 Harrison Cooley. All rights reserved.
//

#ifndef ExerciseTemplate_h
#define ExerciseTemplate_h

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

using namespace std;

class exercise_template
{
public:
    string name;
    string muscleArea;
        
    int oneRepMax;
        
    int sets;
    int reps;
    int weight;
        
    float restTime; //in minutes
        
    bool hasWeight = false; //options should be yes which prompts amount or no with option for bodyweight
    
    bool hasDuration = false; //option for runs or interval training
    
    int duration; //this is like if the exercise has a time component, like split swuat jumps
    
    void setName(string newName);
    void assignSetNumber(int num);
    void assignReps(int num); //might want to add feature to do varying reps if like you don't complete the reps or want to do like a pyramid
        
    void setWeight(int newWeight);
    
    void setRestTime(float time);
    
    exercise_template();
    ~exercise_template();
    
private:
    //This was from before when I was gonna make the list of exercises a linked list
    exercise_template *next;
    exercise_template *previous;
    
    
};

void exercise_template::setName(string newName)
{
    
    //here add a portion that searches through the current exercise template, if one with the same name already exists then give the option to use that exercise template
    
    cout << "Setting the new name of this exercise to ";
    cout << newName << endl;
    
    name = newName;
    
    cout << "The new name of this exercise is ";
    cout << name << endl;
}

void exercise_template::assignSetNumber(int num)
{
    
    cout << "Setting the number of sets in this exercise to ";
    cout << num << endl;
    
    sets = num;
    
    cout << "The new number of sets in this exercise is ";
    cout << sets << endl;
}

void exercise_template::assignReps(int num)
{
    
    cout << "Setting the reps per set in this exercise to ";
    cout << num << endl;
    
    reps = num;
    
    cout << "The new number of reps per set is ";
    cout << reps << endl;
}

void exercise_template::setWeight(int newWeight)
{
    
    cout << "Setting the new weight of this exercise to ";
    cout << newWeight << endl;
    
    weight = newWeight;
    
    if (weight == 0)
    {
        hasWeight = false;
    }
    else
    {
        hasWeight = true;
    }
    
    cout << "The bool hasWeight is ";
    cout << hasWeight << endl;
    
    cout << "The new weight of this exercise is ";
    cout << weight << endl;
    
}

void exercise_template::setRestTime(float time)
{
    
    cout << "Setting the new rest time of this exercise to ";
    cout << time << endl;
    
    restTime = time;
    
    cout << "The new rest time of this exercise is ";
    cout << restTime << endl;
    
}

//Constructor
exercise_template::exercise_template()
{
    
}

//Constructor with params
//exercise_template::exercise_template()
//{
//    //Making the name
//    string inName;
//    cout << "Enter the name of this exercise: ";
//    cin >> inName;
//    cout << endl;
//    setName(inName);
//
//    //Assigning # of sets
//    int inSets;
//    cout << "Enter how many sets this exercise will have: ";
//    cin >> inSets;
//    cout << endl;
//    assignSetNumber(inSets);
//
//}

//Destructor
exercise_template::~exercise_template()
{
    
}
#endif /* ExerciseTemplate_h */
