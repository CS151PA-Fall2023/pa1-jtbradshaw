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

void menu(){
    cout<<"2015 National Survey of Recent College Graduate\n"
        "1. Top 10 Majors with the Highest Mean Salary\n"
        "2. Top 10 Majors with the Lowest Mean Salary\n"
        "3. Top 10 Majors with the Highest Median Salary\n"
        "4. Top 10 Majors with the Lowest Median Salary\n"
        "5. What are the Top 5 Majors with the Highest Number of Asians\n"
        "6. What are the Top 5 Majors with the Lowest Number of Asians\n"
        "7. What are the Top 5 Majors with the Highest Number of Minorities\n"
        "8. What are the Top 5 Majors with the Lowest Number of Minorities\n"
        "9. <Design and implement a menu item that provides information through the data>\n"
        "10. <Design and implement a menu item that provides information through the data>\n"
        "11. Display Information for a Specific Major\n"
        "12. Exit\n"
        "\nSelect a Menu: ";
}

bool validMenuImput(int num){
    bool valid = false;
    if(num > 0 && num < 13){
        valid = true;
    }
    return valid;
}
