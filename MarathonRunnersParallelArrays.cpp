#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

/*
* There are no direct inputs, just the runners.txt file. Basically the program reads the
* file, it then prints the names from the file, then the Calculate() function will print the data.
* The output is the names, the amount they ran each day, the total they ran, and the average per day.
*/ 

using namespace std;


// Preconditions: The file has to exist
// Post conditions, RunnersNames and MilesRun will be defined
void Data(string RunnersNames[5], int MilesRun[5][7]) {
    ifstream file("runners.txt");

    if (file.is_open()) {
        for (int index = 0; index < 5; ++index) {
            string line;
            if (getline(file, line)) {
                size_t spacePos = line.find(' ');
                RunnersNames[index] = line.substr(0, spacePos);

                stringstream stringstream(line.substr(spacePos + 1));
                for (int j = 0; j < 7; ++j) {
                    stringstream >> MilesRun[index][j];
                }
            }
        }
    }
}


// Preconditions: RunnersNames and MilesRun must be defined
// Postconditions: The data will be output
void Calculate(string RunnersNames[5], int MilesRun[5][7]) {
    
    const int Width = 15;

    for (int day = 0; day < 7; day++) {
        cout << "Day " << day + 1 << ":" << setw(Width);
        for (int runner = 0; runner < 5; runner++) {
            cout << MilesRun[runner][day] << setw(Width);
        }
        cout << endl;
    }

    cout << "Total:" << setw(Width);
    for (int i = 0; i < 5; ++i) {
        int totalMiles = 0;

        for (int j = 0; j < 7; ++j) {
            totalMiles += MilesRun[i][j];
        }
        cout << totalMiles << setw(Width);
    }
    cout << endl;
    cout << "Average:" << setw(Width);

    for (int i = 0; i < 5; ++i) {
        int totalMiles = 0;

        for (int j = 0; j < 7; ++j) {
            totalMiles += MilesRun[i][j];
        }
        cout << totalMiles / 7 << setw(Width);
    }
}


// Preconditions: RunnersNames and MilesRun must be definied
// Postconditions: The names will be outputted
int main() {
    string RunnersNames[5];
    int MilesRun[5][7];

    Data(RunnersNames, MilesRun);

    cout << "OUTPUT" << endl;

    const int Width = 15;

    cout << setw(Width) <<  "Names:" << setw(Width);
    for (int index = 0; index < 5; index++) {
        cout << RunnersNames[index] << setw(Width);
    }

    cout << endl;

    Calculate(RunnersNames, MilesRun);

    return 0;
}