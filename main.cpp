#include "analytics.h"

using namespace std;

int main(){
    GradEmploymentData temp;
    vector<GradEmploymentData> gradVect;
    ifstream file("graduates2015.csv");
    if(!file){
        cout<<"Error opening file."<<endl;
        exit(1);
    }

    loadVector(file, gradVect);

    file.close();
    //Causes segmentation fault
    for(int i = 0; i < 45; i++){
        cout<<"Education Major for vector "<<i<<": "<<gradVect[i].educationMajor<<endl;
    }
    

    // int menuNum = -1;
    // menu();
    // cin>>menuNum;
    // if(!validMenuImput(menuNum)){
    //     cout<<"Invalid menu imput"<<endl;
    // } else {
    //     switch (menuNum){
    //         case '1': highMeanSalary();
    //             break;
    //         case '2': lowMeanSalary();
    //             break;
    //         case '3': highMedianSalary();
    //             break;
    //         case '4': lowMedianSalary();
    //             break;
    //         case '5':
    //             break;
    //         case '6':
    //             break;
    //         case '7':
    //             break;
    //         case '8':
    //             break;
    //         case '9':
    //             break;
    //         case '10':
    //             break;
    //         case '11':
    //             break;
    //         case '12':
    //             break;
    //     }
    // }
    //cout<<"Total demographics for vector 1: "<<gradVect[1].demographicsTotal<<endl;

    return 0;
}
