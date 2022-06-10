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
        
    workout_template();
    ~workout_template();
    
    void setName(string newName);
    void setXciseNumber(int num);
    
    void addXrcise(exercise_template addOn);
    
    void getDate();
    
    void setDate(int m, int d, int y, string dStr);
    
    void resetWkt();
        
    string name;
    int numXcises;
    int xciseCount = 0;
    
    int timesCompleted; //this will be incremented every time a workout is logged, will help with reading the info to and from the file for saving
    
    string dateStr;
    
    exercise_template *exerciseList ; //this stores each exercise for this specific workout
    
private:
    
    int month, day, year;
    
    void initXciseList(int sz);

};

//Constructor
workout_template::workout_template()
{
    
}//END constructor

//Constructor with params
//workout_template::workout_template()
//{
//    cout << "Enter the name of this workout here: ";
//    cin >> name;
//    cout << endl;
//    cout << "Enter the number of excersises in this workout here: ";
//    cin >> numXcises;
//
//    exerciseList = new exercise_template[numXcises];
//}//END constructor

//Destructor
workout_template::~workout_template()
{
    numXcises = 0;
    //need to delete the dynamically allocated memory in order to prevent memory leak
    //delete [] exerciseList;
}//END destructor

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
    
    numXcises = num;
    
    cout << "The number of exercises in this workout is ";
    cout << numXcises << endl;
    
    //call the initialization function for the dynamic array
    initXciseList(num);
}



//change this so the added xrcise is created in this funciton, not passed as param
void workout_template::addXrcise(exercise_template addOn)
{
    
    if (xciseCount > numXcises-1)
    {
        throw logic_error("Can't add an exercise to this workout, max number of exercises for this workout reached");
        
        //add a part that asks whether you want to expand number of xrcises in workout
    }
    
    cout << "Going to insert the exercise " << addOn.name << " to the exercise list" << endl;
    
    //exerciseList.insert(addOn);
    
    exerciseList[xciseCount] = addOn;
    
    xciseCount++;
}

void workout_template::getDate()
{
    cout << month << "/" << day << "/" << year << endl;
}

void workout_template::setDate(int m, int d, int y, string dStr)
{
    cout << "Setting date to " << m << "/" << d << "/" << y << endl;
    
    month = m;
    day = d;
    year = y;
    
    string testBlank = " ";
    //if no date string is given, create it
    if (testBlank.compare(dStr) == 0)
    {
        //transform ints to strings
        
        string mStr = to_string(m);
        string dStr = to_string(d);
        string yStr = to_string(y);
        
        dateStr = mStr;
        dateStr = dateStr + "/";
        dateStr = dateStr + dStr;
        dateStr = dateStr + "/";
        dateStr = dateStr + yStr;
        cout << "the dateStr is " << dateStr << endl;
    }
    else
    {
        dateStr = dStr;
    }
    
    
}

void workout_template::initXciseList(int sz)
{
    int size = sz;
    exerciseList = new exercise_template[size];
}

void workout_template::resetWkt()
{
    numXcises = 0;
    //need to delete the dynamically allocated memory in order to prevent memory leak
    delete [] exerciseList;
}

#endif /* workoutTemplate_h */
