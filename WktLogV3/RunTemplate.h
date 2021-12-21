//
//  RunTemplate.h
//  run Log
//
//  Created by Harrison Cooley on 7/23/20.
//  Copyright © 2020 Harrison Cooley. All rights reserved.
//

#ifndef RunTemplate_h
#define RunTemplate_h

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

using namespace std;

class run_template
{
    public:
        void setName(string newName);
        void setTime(int num);
        void setDist(int num);
        
        string name;
    
        int runtime = 0; //in minutes
        int distance = 0; //in miles
    
    
    private:
    
    
};


void run_template::setName(string newName)
{
    
    //here I need to add a portion that searches the databse to see if a run with the name already exists. Then it will give the option to either overwrite the run completely or edit it.
    
    cout << "Setting the new name of this run to ";
    cout << newName << endl;
    
    name = newName;
    
    cout << "The new name of this run is ";
    cout << name << endl;
}


void run_template::setTime(int num)
{
    
    cout << "Setting the time of this run to ";
    cout << num << endl;
    
    runtime = num;
    
    cout << "The time of this run is ";
    cout << runtime << endl;
}

void run_template::setDist(int num)
{
    
    cout << "Setting the distance of this run to ";
    cout << num << endl;
    
    distance = num;
    
    cout << "The distance of this run is ";
    cout << distance << endl;
}



#endif /* RunTemplate_h */
