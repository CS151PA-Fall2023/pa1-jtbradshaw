#include "analytics.h"

using namespace std;

int main(){
    GradEmploymentData temp;
    vector<GradEmploymentData> gradVect;

    //vector<GradEmploymentData> sortedTemp;

    ifstream file("graduates2015.csv");
    if(!file){
        cout<<"Error opening file."<<endl;
        exit(1);
    }

    loadVector(file, gradVect);

    file.close();
    //To test that vector is full
    // for(int i = 0; i < 45; i++){
    //     cout<<"Education Major for vector "<<i<<": "<<gradVect[i].educationMajor<<endl;
    // }
    


    menu(gradVect);
    

    return 0;
}
