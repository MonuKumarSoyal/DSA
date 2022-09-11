#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    ofstream obj_output("sample.txt");
    for(int i = 1; i<=500; i++){
        float j = pow(i, 2)*(0.00500);
        float k = pow(i, 3)*(2.5);
        obj_output<<(i+5)<<" "<<j<<" "<<k<<endl;
    }
    obj_output.close();
    return 0;
}