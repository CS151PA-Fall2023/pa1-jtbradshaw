/**
 * @file analytics.cpp
 * @author Justin Bradshaw
 * @brief The file containing all of the functions for main.cpp for PA1
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "analytics.h"

/**
 * @brief Loads vector full of data from .csv file
 * 
 * @param file the .csv file
 * @param vector Vector of the structure
 */
void loadVector(ifstream &file, vector<GradEmploymentData> &vector){
    GradEmploymentData temp;
    string firstLine;
    getline(file, firstLine);
    //cin.ignore();
    do{
        //cout<<"Start of do-while loop. ";
        char hold;
        file>>temp.demographicsTotal;
        file>>hold;
        if(file.peek()=='"'){
            file>>hold;
            getline(file, temp.educationMajor, '"');
            file>>hold;
        } else {
           getline(file, temp.educationMajor, ','); 
        }
        file>>temp.meanSalary;
        file>>hold;
        file>>temp.medianSalary;
        file>>hold;
        file>>temp.demographicsAsian;
        file>>hold;
        file>>temp.demographicsMinority;
        file>>hold;
        file>>temp.demographicsWhite;
        file>>hold;
        file>>temp.demographicsFemales;
        file>>hold;
        file>>temp.demographicsMales;
        file>>hold;
        file>>temp.educationBachelor;
        file>>hold;
        file>>temp.educationDoctorate;
        file>>hold;
        file>>temp.educationMasters;
        vector.push_back(temp);


    } while(file.peek()!=EOF);

}



/**
 * @brief displays the menu and redirects it to another function depending upon the input
 * 
 * @param gradVect Vector of the structure
 */
void menu(vector<GradEmploymentData> &gradVect){
    int menuNum = -1;
    do{
        cout<<"2015 National Survey of Recent College Graduate\n"
            "1. Top 10 Majors with the Highest Mean Salary\n"
            "2. Top 10 Majors with the Lowest Mean Salary\n"
            "3. Top 10 Majors with the Highest Median Salary\n"
            "4. Top 10 Majors with the Lowest Median Salary\n"
            "5. What are the Top 5 Majors with the Highest Number of Asians\n"
            "6. What are the Top 5 Majors with the Lowest Number of Asians\n"
            "7. What are the Top 5 Majors with the Highest Number of Minorities\n"
            "8. What are the Top 5 Majors with the Lowest Number of Minorities\n"
            "9. What is the Major with the Highest Number of Females\n"
            "10. What is the Major with the Highest Number of Males\n"
            "11. Display Information for a Specific Major\n"
            "12. Exit\n"
            "\nSelect a Menu: ";
        cin>>menuNum;
        if(!validMenuImput(menuNum)){
            cout<<"Invalid menu imput\n"<<endl;
        }
    }while(!validMenuImput(menuNum));
        //Takes the input from user and redireccts to desired function
    switch (menuNum){
        case 1: highMeanSalary(gradVect);
            break;
        case 2: lowMeanSalary(gradVect);
            break;
        case 3: highMedianSalary(gradVect);
            break;
        case 4: lowMedianSalary(gradVect);
            break;
        case 5: highNumAsians(gradVect);
            break;
        case 6: lowNumAsians(gradVect);
            break;
        case 7: highNumMinority(gradVect);
            break;
        case 8: lowNumMinority(gradVect);
            break;
        case 9: highestFemale(gradVect);
            break;
        case 10: highestMale(gradVect);
            break;
        case 11: specMajor(gradVect);
            break;
        case 12: exit(1);
            break;
    }
}

/**
 * @brief determines if the value input by user is within the range of 1-13
 * 
 * @param num the number that the user input
 * @return true It is within the range of 1-13
 * @return false It is not within the range of 1-13
 */
bool validMenuImput(int num){
    bool valid = false;
    if(num > 0 && num < 13){
        valid = true;
    }
    return valid;
}

/**
 * @brief Outputs the top 10 majors with the highest mean salary
 * 
 * @param vector Vector of the structure
 */
void highMeanSalary(vector<GradEmploymentData> &vector){
    //sorts vector by mean salary
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].meanSalary;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].meanSalary > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    //Outputs result
    cout<<"Education Major                       Mean Salary"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = (int)vector.size()-1; i > (int)vector.size()-11; i--){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<setprecision(2)<<fixed<<vector[i].meanSalary<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the top 10 majors with the lowest mean salary
 * 
 * @param vector Vector of the structure
 */
void lowMeanSalary(vector<GradEmploymentData> &vector){
    //sorts vector by mean salary
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].meanSalary;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].meanSalary > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    //Outputs result
    cout<<"Education Major                       Mean Salary"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = 0; i < 10; i++){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<setprecision(2)<<fixed<<vector[i].meanSalary<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the top 10 majors with the highest median salary
 * 
 * @param vector Vector of the structure
 */
void highMedianSalary(vector<GradEmploymentData> &vector){
    //Sorts vector according to median salary
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].medianSalary;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].medianSalary > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    //Outputs result
    cout<<"Education Major                       Median Salary"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = (int)vector.size()-1; i > (int)vector.size()-11; i--){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<setprecision(2)<<fixed<<vector[i].medianSalary<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the top 10 majors with the lowest median salary
 * 
 * @param vector Vector of the structure
 */
void lowMedianSalary(vector<GradEmploymentData> &vector){
    //sorts vector by meadian salary
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].medianSalary;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].medianSalary > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    //Outputs result
    cout<<"Education Major                       Median Salary"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = 0; i < 10; i++){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<setprecision(2)<<fixed<<vector[i].medianSalary<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the top 5 majors with the highest number of Asians
 * 
 * @param vector Vector of the structure
 */
void highNumAsians(vector<GradEmploymentData> &vector){
    //Sorts vector according to number of asians
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].demographicsAsian;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].demographicsAsian > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    //Outputs result
    cout<<"Education Major                       Number of Asians"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = (int)vector.size()-1; i > (int)vector.size()-6; i--){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<vector[i].demographicsAsian<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the top 5 majors with the lowest number of Asians
 * 
 * @param vector Vector of the structure
 */
void lowNumAsians(vector<GradEmploymentData> &vector){
    //Sorts vector according to number of asians
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].demographicsAsian;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].demographicsAsian > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    //Outputs result
    cout<<"Education Major                       Number of Asians"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = 0; i < 5; i++){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<vector[i].demographicsAsian<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the top 5 majors with the highest number of minorities
 * 
 * @param vector Vector of the structure
 */
void highNumMinority(vector<GradEmploymentData> &vector){
    //Sorts vector according to number of Minorities
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].demographicsMinority;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].demographicsMinority > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    //Outputs result
    cout<<"Education Major                       Number of Minorities"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = (int)vector.size()-1; i > (int)vector.size()-6; i--){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<vector[i].demographicsMinority<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the top 5 majors with the lowest number of minorities
 * 
 * @param vector Vector of the structure
 */
void lowNumMinority(vector<GradEmploymentData> &vector){
//Sorts vector according to number of Minorities
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].demographicsMinority;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].demographicsMinority > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    //Outputs result
    cout<<"Education Major                       Number of Minorities"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = 0; i < 5; i++){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<vector[i].demographicsMinority<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the major with the highest number of females
 * 
 * @param vector Vector of the structure
 */
void highestFemale(vector<GradEmploymentData> &vector){
    //Finds major with highest number of females
    int max = 0;
    for(int i = 0; i < (int)vector.size(); i++){
        if(vector[i+1].demographicsFemales > vector[i].demographicsFemales){
            max = i+1;
        }
    }
    //Outputs data
    cout<<"Education Major                Number of Females"<<endl;
    cout<<"---------------------------------------------------\n";
    cout<<left<<setw(34)<<vector[max].educationMajor<<right<<setw(9)<<vector[max].demographicsFemales<<endl;
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs the major with the highest number of males
 * 
 * @param vector Vector of the structure
 */
void highestMale(vector<GradEmploymentData> &vector){
    //Finds major with highest number of males
    int max = 0;
    for(int i = 0; i < (int)vector.size(); i++){
        if(vector[i+1].demographicsFemales > vector[i].demographicsMales){
            max = i+1;
        }
    }
    //Outputs data
    cout<<"Education Major                Number of Males"<<endl;
    cout<<"---------------------------------------------------\n";
    cout<<left<<setw(34)<<vector[max].educationMajor<<right<<setw(9)<<vector[max].demographicsMales<<endl;
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}

/**
 * @brief Outputs all of the data for a particular major that is entered by the user
 * 
 * @param vector Vector of the structure
 */
void specMajor(vector<GradEmploymentData> &vector){
    //Insertion sort by major
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        string key = vector[startScan].educationMajor;
        GradEmploymentData temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].educationMajor > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }

    string major = " ";
    int num = -1; //number used to track where in vector desired data is.
    cout<<"Please enter a specific major: ";
    cin.ignore();
    getline(cin, major);

    //Binary search for desired major
    int first = 0, // First array element
    last = (int)vector.size() - 1, // Last array element
    middle; // Midpoint of search
    bool found = false; // Flag
    while (!found && first <= last){
        middle = (first + last) / 2; // Calculate midpoint
        if (vector[middle].educationMajor == major) // If major is found at mid
        {
            found = true;
            num = middle;
        }
            else if (vector[middle].educationMajor > major) // If major is in lower half
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1; // If major is in upper half
        }
    }
    //While loop for if they do not enter a Major in the data
    while(num == -1){
        if(num == -1){
        cout<<"\nThat major is not in the data.\n"<<endl;
        }
        major = " ";
        cout<<"Please enter a specific major: ";

        getline(cin, major);

        //Binary search for desired major
        int first = 0, // First array element
        last = (int)vector.size() - 1, // Last array element
        middle; // Midpoint of search
        bool found = false; // Flag
        while (!found && first <= last)
        {
            middle = (first + last) / 2; // Calculate midpoint
            if (vector[middle].educationMajor == major) // If major is found at mid
            {
                found = true;
                num = middle;
            }
                else if (vector[middle].educationMajor > major) // If major is in lower half
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1; // If major is in upper half
            }
        }
    }
    //Output
    cout<<"\n"<<left<<setw(10)<<"Major"<<right<<setw(20)<<major<<endl;
    cout<<"----------------------------------\n";
    cout<<left<<setw(20)<<"Total Demographics"<<right<<setw(12)<<vector[num].demographicsTotal<<endl;
    cout<<left<<setw(20)<<"Mean Salary"<<"   $"<<right<<setw(8)<<setprecision(2)<<fixed<<vector[num].meanSalary<<endl;
    cout<<left<<setw(20)<<"Median Salary"<<"   $"<<right<<setw(8)<<setprecision(2)<<fixed<<vector[num].medianSalary<<endl;
    cout<<left<<setw(20)<<"Demographics Asian"<<right<<setw(12)<<vector[num].demographicsAsian<<endl;
    cout<<left<<setw(20)<<"Demographics Minorities"<<right<<setw(9)<<vector[num].demographicsMinority<<endl;
    cout<<left<<setw(20)<<"Demographics White"<<right<<setw(12)<<vector[num].demographicsWhite<<endl;
    cout<<left<<setw(20)<<"Females"<<right<<setw(12)<<vector[num].demographicsFemales<<endl;
    cout<<left<<setw(20)<<"Males"<<right<<setw(12)<<vector[num].demographicsMales<<endl;
    cout<<left<<setw(20)<<"Bachelor's Degree"<<right<<setw(12)<<vector[num].educationBachelor<<endl;
    cout<<left<<setw(20)<<"Master's Degree"<<right<<setw(12)<<vector[num].educationMasters<<endl;
    cout<<left<<setw(20)<<"Doctorate"<<right<<setw(12)<<vector[num].educationDoctorate<<endl;

    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.get();
    //returns to menu
    menu(vector);
}