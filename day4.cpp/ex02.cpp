#include<iostream>
#include<vector>
using namespace std;

//criteria: 2 digit the same(adjacent end not more than 2) - ->never decrease
bool meetCriteria(int psw) {
    vector<int> pswVec;
    while(psw >0) {
        pswVec.insert(pswVec.begin(), psw%10);
        psw= psw/10;
    }

    bool dd=false, grow=true;
    //checking if grow
    for(int i=1; i<6; i++) {
        if(pswVec[i-1] > pswVec[i]) return false;
    }

    //checking double digit
    for(int i=0; i<5; i++) {
        if(pswVec[i] == pswVec[i+1]) {
            if(!pswVec[i+2] || pswVec[i+2] != pswVec[i]) dd=true;
            else{
                int y= i+2;
                while(pswVec[i] == pswVec[y]) y++;
                i=y-1; //levo 1 perchè il for aumenta alla fine
            }
        }
    }

    if(dd) return true;
    else return false;
}

main() {
    int possiblePsw=0;
    for(int psw =271973; psw<=785961; psw++) {
        if(meetCriteria(psw)) possiblePsw ++;
    }
    cout<<"Possible password: "<<possiblePsw<<endl;
}