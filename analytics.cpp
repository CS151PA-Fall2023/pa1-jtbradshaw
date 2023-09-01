#include "analytics.h"

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
        file>>hold;
        vector.push_back(temp);


    } while(file.peek()!=EOF);

}

void menu(vector<GradEmploymentData> &gradVect){
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

    int menuNum = -1;
    cin>>menuNum;
    if(!validMenuImput(menuNum)){
        cout<<"Invalid menu imput"<<endl;
    } else {
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
}

bool validMenuImput(int num){
    bool valid = false;
    if(num > 0 && num < 13){
        valid = true;
    }
    return valid;
}


void highMeanSalary(vector<GradEmploymentData> &vector){
    //sorts vector by mean salary
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].meanSalary;
        int index = startScan - 1;
        while (index >= 0 && vector[index].meanSalary > key)
    {
        vector[index+1].meanSalary = vector[index].meanSalary;
        --index;
    }
        vector[index+1].meanSalary = key;
    }
    //Outputs result
    cout<<"Education Major                       Mean Salary"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = (int)vector.size()-1; i > (int)vector.size()-11; i--){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<vector[i].meanSalary<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}


void lowMeanSalary(vector<GradEmploymentData> &vector){
    //sorts vector by mean salary
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].meanSalary;
        int index = startScan - 1;
        while (index >= 0 && vector[index].meanSalary > key)
    {
        vector[index+1].meanSalary = vector[index].meanSalary;
        --index;
    }
        vector[index+1].meanSalary = key;
    }
    //Outputs result
    cout<<"Education Major                       Mean Salary"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = 0; i < 10; i++){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<vector[i].meanSalary<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}


void highMedianSalary(vector<GradEmploymentData> &vector){
    //Sorts vector according to median salary
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].medianSalary;
        int index = startScan - 1;
        while (index >= 0 && vector[index].medianSalary > key)
    {
        vector[index+1].medianSalary = vector[index].medianSalary;
        --index;
    }
        vector[index+1].medianSalary = key;
    }
    //Outputs result
    cout<<"Education Major                       Median Salary"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = (int)vector.size()-1; i > (int)vector.size()-11; i--){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<vector[i].medianSalary<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}


void lowMedianSalary(vector<GradEmploymentData> &vector){
    //sorts vector by meadian salary
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].medianSalary;
        int index = startScan - 1;
        while (index >= 0 && vector[index].medianSalary > key)
    {
        vector[index+1].medianSalary = vector[index].medianSalary;
        --index;
    }
        vector[index+1].medianSalary = key;
    }
    //Outputs result
    cout<<"Education Major                       Median Salary"<<endl;
    cout<<"---------------------------------------------------\n";
    for(int i = 0; i < 10; i++){
        cout<<left<<setw(34)<<vector[i].educationMajor<<setw(3)<<"$"<<right<<setw(9)<<vector[i].medianSalary<<endl;
    }
    cout<<"\n\nPress enter to continue...\n"<<flush;
    cin.ignore();
    cin.get();
    //returns to menu
    menu(vector);
}


void highNumAsians(vector<GradEmploymentData> &vector){
    //Sorts vector according to number of asians
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].demographicsAsian;
        int index = startScan - 1;
        while (index >= 0 && vector[index].demographicsAsian > key)
    {
        vector[index+1].demographicsAsian = vector[index].demographicsAsian;
        --index;
    }
        vector[index+1].demographicsAsian = key;
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


void lowNumAsians(vector<GradEmploymentData> &vector){
    //Sorts vector according to number of asians
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].demographicsAsian;
        int index = startScan - 1;
        while (index >= 0 && vector[index].demographicsAsian > key)
    {
        vector[index+1].demographicsAsian = vector[index].demographicsAsian;
        --index;
    }
        vector[index+1].demographicsAsian = key;
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


void highNumMinority(vector<GradEmploymentData> &vector){
    //Sorts vector according to number of Minorities
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].demographicsMinority;
        int index = startScan - 1;
        while (index >= 0 && vector[index].demographicsMinority > key)
    {
        vector[index+1].demographicsMinority = vector[index].demographicsMinority;
        --index;
    }
        vector[index+1].demographicsMinority = key;
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


void lowNumMinority(vector<GradEmploymentData> &vector){
//Sorts vector according to number of Minorities
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        int key = vector[startScan].demographicsMinority;
        int index = startScan - 1;
        while (index >= 0 && vector[index].demographicsMinority > key)
    {
        vector[index+1].demographicsMinority = vector[index].demographicsMinority;
        --index;
    }
        vector[index+1].demographicsMinority = key;
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


void highestFemale(vector<GradEmploymentData> &vector){
    //Fines major with highest number of females
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


void highestMale(vector<GradEmploymentData> &vector){
    //Fines major with highest number of males
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


void specMajor(vector<GradEmploymentData> &vector){
    string major = " ";
    int num = -1; //number used to track where in vector desired data is.
    cout<<"Please enter a specific major: ";
    cin.ignore();
    getline(cin, major);

    //Linear search for desired major
    for(int i = 0; i < (int)vector.size(); i ++){
        if(vector[i].educationMajor == major){
            num = i;
            break;
        }
    }
    if(num == -1){
        cout<<"\nThat major is not in the data.\n"<<endl;
    }

    while(num == -1){
        major = " ";
        cout<<"Please enter a specific major: ";

        getline(cin, major);

        //Linear search for desired major
        for(int i = 0; i < (int)vector.size(); i ++){
            if(vector[i].educationMajor == major){
                num = i;
                break;
            }
        }
        if(num == -1){
            cout<<"\nThat major is not in the data.\n"<<endl;
        } else {
            break;
        }
    }
    //Output
    cout<<"\n"<<left<<setw(10)<<"Major"<<right<<setw(20)<<major<<endl;
    cout<<"----------------------------------\n";
    cout<<left<<setw(20)<<"Total Demographics"<<right<<setw(12)<<vector[num].demographicsTotal<<endl;
    cout<<left<<setw(20)<<"Mean Salary"<<"   $"<<right<<setw(8)<<vector[num].meanSalary<<endl;
    cout<<left<<setw(20)<<"Median Salary"<<"   $"<<right<<setw(8)<<vector[num].medianSalary<<endl;
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