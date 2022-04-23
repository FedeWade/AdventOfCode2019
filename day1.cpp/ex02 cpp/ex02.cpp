#include <iostream>
#include <fstream>
using namespace std;

int fuel(int x) {
    x=(x/3)-2;
    if (x<=0) return 0;
    return fuel(x) + x;
}

main () {
    ifstream file("input.txt");   
    int x, sum=0;
    for( int i=0; file>>x; i++)
        sum+=fuel(x);
    cout << sum << endl;
    return 0;
}