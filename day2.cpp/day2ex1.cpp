#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string line;
    ifstream myfile("input.txt");
    int x;
    vector<int> vec;

    if (myfile.is_open())
    {
        while (myfile.good())
        {
            getline(myfile, line, ',');
            x = std::stoi(line);
            vec.push_back(x);
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";

    vec[1] = 12;
    vec[2] = 2;

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

    cout << vec[0];

    return 0;
}