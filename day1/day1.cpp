#include <iostream>
#include <fstream>
#include <algorithm>    
#include <string>
#include <cctype>

using namespace std;

int main() {
    ifstream file;
    file.open("input.txt");
    string array1[1000][5] = {};
    string array2[1000][5] = {};

    int counter = 0;
    string line;


    while (getline(file, line)) {
        for (int i = 0; i<13;i++) {
            if (i < 5) {
                array1[counter][i] = line[i];
            }
            if (i > 7) {
                array2[counter][i-8] = line[i];                
            }
        }
        counter++;
    }

    string temp1[1000] = {};
    string temp2[1000] = {};
    int result1[1000] = {};
    int result2[1000] = {};

    for (int j = 0; j < 1000; j++) {
        for (int i = 0; i < 5; i++) { 
            temp1[j] += array1[j][i];
            temp2[j] += array2[j][i];
        }
    }

    for (int j = 0; j < 1000; j++) {
        result1[j] = stoi(temp1[j]);
        result2[j] = stoi(temp2[j]);
    }

    int n = sizeof(result1) / sizeof(result1[0]);
    std::sort(result1, result1 + n);
    n = sizeof(result2) / sizeof(result2[0]);
    std::sort(result2, result2 + n);


// Day 1
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += abs(result1[i]-result2[i]);
    }

    cout << sum;


// Day 2
    int sumx = 0;
    int counterx = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (result1[i] == result2[j]) {
                counterx++;
            }
        }
        sumx += result1[i]*counterx;
        counterx = 0;
    }    

    cout << sumx;
    
    file.close();
}

// separate input into two arrays, one for the left column and one for the right
// sort the two arrays
// get absolute value of array1[i] - array2[i]
// sum them all up 