#include <iostream>
#include <vector>
#include <cstdlib> // srand, rand
#include <cstdio> // NULL
#include <time.h> // time
#include <fstream> //fstream
using namespace std;

void solve(vector<int> vect, string pathToOutput) {

    int curSeqStart = 0;
    int curSeqLen = 0;

    int longestLen = 0;
    vector<int> longestStart{};

    for (int i = 0; i < vect.size() ; i++) {
        if (vect[i] > vect[i + 1]) {

            if (curSeqStart == 0) curSeqStart = i;
            curSeqLen++;

        } else {
            // check if previous seq is the longest
            // 1. it is
            if (curSeqLen > longestLen) {
                // clear arr
                longestStart.clear();

                longestStart.push_back(curSeqStart);
                longestLen = curSeqLen;
            // 2. it is equal
            } else if (curSeqLen == longestLen) {
                longestStart.push_back(curSeqStart);
            }
            // 3. else - skip

            // restart variables
            curSeqStart = 0;
            curSeqLen = 0;
        }
    }

    fstream out;
    out.open(pathToOutput, ios::out);

    // print results
    // if all elements are equal
    if (longestLen == 0) {
        string outputStr = "All elements are equal or passed vector is empty!";

        cout << outputStr << endl;
        out << outputStr;
    } else {
        int start;
        cout << "---------------------" << endl;
        cout << "Ciag: ";
        for(int i = 0; i < vect.size(); i++) {
            cout << vect[i] << ", ";
        }

        cout << endl;

        for (int i = 0; i < longestStart.size(); i++) {
            cout << "Podciag no. " << i << ": ";
            start = longestStart[i];

            for (int j = 0; j < longestLen + 1; j++) {
                cout << vect[start + j] << " ";
                out << vect[start + j] << " ";
            }
            out << endl;
        }
        cout << endl << "---------------------" << endl;
    }
}

// generate n el. vector
vector<int> generateVector(int n) {
    vector<int> new_vect;

    for(int i = 0; i < n; i++) {
        new_vect.push_back(rand() % 1000);
    }

    return new_vect;
}

// function to check execution time of function
void executionTime(vector<int> vect) {

    clock_t t = clock();

    solve(vect, "wyjscie.txt"); // funkcja wykonujaca dane zadanie

    t = clock() - t;

    long double fullTime = (float)t/CLOCKS_PER_SEC;

    cout << endl << "Function with " << vect.size() << " elements was performed for ~" << fullTime << " sec." << endl;
}

int main()
{
    srand(time(NULL));

    int input;
    vector<int> arr;

    cout << "Czy chcesz wczytaæ dane z pliku czy losowaæ tablicê?" << endl << "1 - z pliku" << endl << "2 - losowanie" << endl;
    cin >> input;

    switch(input) {

    // read data from file
    case 1: {
        fstream in;

        in.open("wejscie.txt", ios::in);

        int a;
        while(!in.eof()) {
            in >> a;
            arr.push_back(a);
        }

        in.close();
        break;
    }
    // work on data from code
    case 2: {
        arr = {-10, 5, 8, 1, -4, -4, 10, 3, -1, 1};

        vector<int> arr100 = generateVector(100);
        vector<int> arr200 = generateVector(200);
        vector<int> arr300 = generateVector(300);
        vector<int> arr50 = generateVector(50);
        vector<int> arr20 = generateVector(20);
        vector<int> arr15 = generateVector(15);

        solve(arr15, "wyjscie.txt");
        solve(arr20, "wyjscie.txt");
        solve(arr50, "wyjscie.txt");
        solve(arr100, "wyjscie.txt");
        solve(arr200, "wyjscie.txt");
        solve(arr300, "wyjscie.txt");
        break;
    }
    default:
        cout << "Powinienes podac 1 lub 2!!!";
        exit(0);
    };


    solve(arr, "wyjscie.txt");

    /*
    vector<int> arr10000 = generateVector(10000);
    vector<int> arr50000 = generateVector(50000);
    vector<int> arr100000 = generateVector(100000);
    vector<int> arr500000 = generateVector(500000);
    vector<int> arr1000000 = generateVector(1000000);
    vector<int> arr5000000 = generateVector(5000000);
    vector<int> arr10000000 = generateVector(10000000);
    vector<int> arr15000000 = generateVector(15000000);
    vector<int> arr20000000 = generateVector(20000000);
    vector<int> arr25000000 = generateVector(25000000);

    executionTime(arr10000);
    executionTime(arr50000);
    executionTime(arr100000);
    executionTime(arr500000);
    executionTime(arr1000000);
    executionTime(arr5000000);
    executionTime(arr10000000);
    executionTime(arr15000000);
    executionTime(arr20000000);
    executionTime(arr25000000);
    */

    return 0;
}
