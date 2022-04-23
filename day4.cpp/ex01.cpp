#include<iostream>
#include<vector>
using namespace std;

//criteria: 2 digit the same - ->never decrease
bool meetCriteria(int psw) {
    vector<int> pswVec;
    while(psw >0) {
        pswVec.insert(pswVec.begin(), psw%10);
        psw= psw/10;
    }

    bool dd=false, grow=true;
    for(int i=1; i<6 && grow; i++) {
        if(pswVec[i-1] == pswVec[i]) dd=true;
        if(pswVec[i-1] > pswVec[i]) grow=false;
    }

    if(dd && grow) return true;
    else return false;
}

main() {
    int possiblePsw=0;
    for(int psw =271973; psw<=785961; psw++) {
        if(meetCriteria(psw)) possiblePsw ++;
    }
    cout<<"Possible password: "<<possiblePsw<<endl;
}