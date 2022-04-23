#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int evaluate(vector<int> vec, int noun, int verb) {
    vec[1] = noun;
    vec[2] = verb;

    bool ok = true;
    for (int i = 0; i <= vec.size() && ok;)
    {
        if (vec[i] == 1)
        {
            vec[vec[i + 3]] = vec[vec[i + 1]] + vec[vec[i + 2]];
        }
        else if (vec[i] == 2)
        {
            vec[vec[i + 3]] = vec[vec[i + 1]] * vec[vec[i + 2]];
        }
        else if (vec[i] == 99)
            ok = false;
        else
        {
            cout << "errore" << endl;
            ok = false;
        }
        i = i + 4;
    }
    return vec[0];
}

int main()
{
    string line;
    ifstream myfile("input.txt");
    int x;
    vector<int> inputVec;

    if (myfile.is_open())
    {
        while (myfile.good())
        {
            getline(myfile, line, ',');
            x = std::stoi(line);
            inputVec.push_back(x);
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    for(int noun=0; noun<100; noun++) {
        for(int verb=0; verb<100; verb++) {
            vector<int> testVec(inputVec);
            if(evaluate(testVec, noun, verb) == 19690720) {
                cout<<"noun = "<<noun<<endl;
                cout<<"verb = "<<verb<<endl;
                cout<<"result = "<<100*noun+verb<<endl;
                return 0;
            }
        }
    }
    cout<<"nessun input trovato";
    
    return 0;
}