/**
 * @file analytics.h
 * @author Justin Bradshaw
 * @brief .h file for main.cpp for PA1
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ANALYTICS_H
#define ANALYTICS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;



struct GradEmploymentData
{
    int demographicsTotal;     // The estimated total of people awarded degrees in this major during 2005
    string educationMajor;     // The name of the major for these graduated students
    float meanSalary;          // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;        // The median recorded salary reported for employed people with this degree
    int demographicsAsian;     // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;  // The estimated number of people identifying as minority 
                               // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;     // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;   // The estimate number of women awarded degrees in this major
    int demographicsMales;     // The estimate number of men awarded degrees in this major
    int educationBachelor;     // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;    // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;      // The estimated number of Masters awarded in this for major

    //vector<GradEmploymentData> gradVect;
};

void loadVector(ifstream &file, vector<GradEmploymentData> &vector);
void menu(vector<GradEmploymentData> &gradVect);
bool validMenuImput(int num);

void highMeanSalary(vector<GradEmploymentData> &vector);
void lowMeanSalary(vector<GradEmploymentData> &vector);
void highMedianSalary(vector<GradEmploymentData> &vector);
void lowMedianSalary(vector<GradEmploymentData> &vector);
void highNumAsians(vector<GradEmploymentData> &vector);
void lowNumAsians(vector<GradEmploymentData> &vector);
void highNumMinority(vector<GradEmploymentData> &vector);
void lowNumMinority(vector<GradEmploymentData> &vector);
void highestFemale(vector<GradEmploymentData> &vector);
void highestMale(vector<GradEmploymentData> &vector);
void specMajor(vector<GradEmploymentData> &vector);

void sort(vector<GradEmploymentData> &vector);


#endif