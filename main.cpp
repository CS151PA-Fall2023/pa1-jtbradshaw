/**
 * @file main.cpp
 * @author Justin Bradshaw
 * @brief main.cpp for PA1, which takes a .csv file, sorts it into a vector of structures,
 *  and outputs data based on a menu input from user.
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "analytics.h"

using namespace std;

int main(){
    vector<GradEmploymentData> gradVect; //vector of structures

    //Opens file
    ifstream file("graduates2015.csv");
    if(!file){
        cout<<"Error opening file."<<endl;
        exit(1);
    }

    //Loads file into vector
    loadVector(file, gradVect);

    //Closes file
    file.close();

    //Calls menu functon for first time
    menu(gradVect);
    
    return 0;
}
