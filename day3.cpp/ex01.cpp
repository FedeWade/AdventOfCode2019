#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Point {
    public:
        Point(int a=0,int b=0): x(a), y(b) {};
        int x;
        int y;
        bool operator< (Point &alt) {
            if(x==alt.x) {
                if(y<alt.y) return true;
                else return false;
            }
            if(x<alt.x) return true;
            else return false;
        }
};

int distance(Point p1, Point p2) { return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y); }

void addLine(vector<Point> &vec, int len, char direction) {
    int lastX= vec[vec.size()-1].x;
    int lastY= vec[vec.size()-1].y;

    for(int i=1; i<=len; i++) {
        switch(direction) {
            case('U') : {
                Point nextP(lastX, lastY+i);
                vec.push_back(nextP);
                break;
            }
            case('D') : {
                Point nextP(lastX, lastY-i);
                vec.push_back(nextP);
                break;
            }
            case('R') : {
                Point nextP(lastX+i, lastY);
                vec.push_back(nextP);
                break;
            }
            case('L') : {
                Point nextP(lastX-i, lastY);
                vec.push_back(nextP);
                break;
            }
            default : cout<<"error, first letter wrong";
        }
    }
}


int main()
{
    string line;
    ifstream myfile("input.txt");
    string x;
    vector<string> vec1;
    vector<string> vec2;
    string cable1, cable2, delimiter(",");

    //divido il file input in 2 stringhe cable 1 e 2
    if (myfile.is_open()) {    
        myfile >> cable1;
        myfile >> cable2;     
        myfile.close();
    } else {
        cout<<"Unble to open file";
        return 0;
    }

    //leggo le stringhe dei 2 cable in input e inserisco ogni istruzione in un vector per ogni cable
    size_t pos = 0;
    std::string token;
    while ((pos = cable1.find(delimiter)) != std::string::npos) {
        token = cable1.substr(0, pos);
        vec1.push_back(token);
        cable1.erase(0, pos + delimiter.length());
    }
    vec1.push_back(cable1);
    //same for cable 2
    while ((pos = cable2.find(delimiter)) != std::string::npos) {
        token = cable2.substr(0, pos);
        vec2.push_back(token);
        cable2.erase(0, pos + delimiter.length());
    }
    vec1.push_back(cable2);

    //creo i 2 vector contenenti tutte le coordinate dei punti di un cable
    vector<Point> pointVec1;
    vector<Point> pointVec2;

    //inserisco il punto iniziale nei due array
    Point origin;
    pointVec1.push_back(origin);
    pointVec2.push_back(origin);

    //scorro ogni istruzione nel input del cable 1 e creo un vec con tutti i punti su cui passa il cavo
    for(int i=0; i<vec1.size(); i++) {
        string raw = vec1[i];
        char letter = raw[0];
        raw.erase(0,1);
        int lenght= stoi(raw);
        addLine(pointVec1, lenght, letter); //metodo che inserisce la linea presa dal comando nel vector del cavo
    }
    for(int i=0; i<vec2.size(); i++) {
        string raw = vec2[i];
        char letter = raw[0];
        raw.erase(0,1);
        int lenght= stoi(raw);
        addLine(pointVec2, lenght, letter); //metodo che inserisce la linea presa dal comando nel vector del cavo
    }

    //orino i vector per il metodo set_intersection
    std::sort(pointVec1.begin(), pointVec1.end());
    std::sort(pointVec2.begin(), pointVec2.end());

    vector<Point> collisions;
    set_intersection(pointVec1.begin(), 
                          pointVec1.end(), 
                          pointVec2.begin(), 
                          pointVec2.end(), 
                          back_inserter(collisions));

    int min_d = INT_MAX; // something big
    for (int i = 0; i < collisions.size(); i++) {
        int d = distance(origin, collisions[i]);
        if (d == 0) 
           continue; 
        min_d = (min_d < d) ? min_d : d;
    }
    cout<<"min: "<<min_d;  

    
}