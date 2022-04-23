#include <iostream>
#include <fstream>
using namespace std;

int leggi(int*X, int dimX) {
    int n;
    bool valueValid=false;
    while(!valueValid) {
        cin>>n;
        if(n>1 && n<dimX)
            valueValid=true;
    }
    for(int i=0; i<n; i++)
    
        cin>>X[i];
    return n;
}

void stampa(int*X, int dim) {
    for(int i=0; i<dim; i++) {
        cout<<X[i]<<" ";
    };
}

main () {
    /*
    ifstream file("input.txt");   
    int x, sum=0;
    for( int i=0; file>>x; i++)
        sum+=(x/3)-2;
    cout << sum << endl;
    return 0;
    */
   int A[30];
   int nelemA= leggi(A,30);

   int y;//
   cout<<"dai valore da eliminare:";
   cin>>y;

   int okFino=0;

   for(okFino; okFino<nelemA; okFino++) {
       if(A[okFino] == y) {

           for(int i=okFino; i<nelemA-1; i++){
               A[i]=A[i+1];
           }
           nelemA--;
           okFino--;
       }
       
   }

}