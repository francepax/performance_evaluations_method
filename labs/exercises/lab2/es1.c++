/*
Realize a C++ class named LcgRng that implements a RNG based on the mixed Linear Congruential Generator
*/
#include <iostream>
#include <cmath>
using namespace std;

#define P 32
#define C 5


class LcgRng{
        int a,b,m,x;
    public:
        LcgRng(float seed);
        float generate();
        float generateExp(float t);
};

LcgRng::LcgRng(float seed){
    x=seed;
    m=P;
    a= 4*C+1;
    b=3;
}

float LcgRng::generate(){
    int rn=(a*x + b)%m;
    x = rn;
    return float(rn)/m;
}

float LcgRng::generateExp(float t){
    return (-1/t)*log(1-generate());

}

int main(){
    LcgRng gen(5);
    int k;
    cout<<"scegli un numero almeno uguale a 64"<<endl;
    cin>>k;
    for(int i = 0;i<k;i++){
        cout<<gen.generateExp(5)<<endl;;
    }
    return 0;
}