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

    int menuNum = -1;
    menu();
    cin>>menuNum;
    if(!validMenuImput(menuNum)){
        cout<<"Invalid menu imput"<<endl;
    } else {
        switch (menuNum){
            case '1': //>>>
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case '10':
                break;
            case '11':
                break;
            case '12':
                break;
        }
    }

    return 0;
}
