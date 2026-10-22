/*
Modify the main function in the program of ex. 1 so that it uses N independent streams of random numbers.
In particular:
• Instantiate N=2 instances of LcgRng and seed them with the appropriate initial values
• Hint: compute them using the formula at the bottom of this slide
• Generate N streams of k=8 random numbers each
*/

#include <iostream>
#include <cmath>
using namespace std;

#define P 32
#define C 2


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
    int N=2;
    LcgRng gen_1 (5);
    LcgRng gen_2 (((9^5)*5 +(3*(9^5-1))/(8))%P);
    int k=30;
    for(int i = 0;i<k;i++){
        cout<<gen_1.generateExp(5)<<"--"<<gen_2.generateExp(5)<<endl;        
    }
    return 0;
}