#include <iostream>
#include <vector>
#include <cstdlib> // srand, rand
#include <cstdio> // NULL
#include <time.h> // time
#include <chrono> // high_resolution_clock

using namespace std;

void solve(vector<int> vect) {

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

    // print results
    // if all elements are equal
    if (longestLen == 0) {
        cout << "All elements are equal or passed vector is empty!" << endl;

    } else {
        int start;
        cout << "---------------------" << endl;
        for (int i = 0; i < longestStart.size(); i++) {
            cout << "Podciag no. " << i << ": ";
            start = longestStart[i];

            for (int j = 0; j < longestLen + 1; j++) {
                cout << vect[start + j] << " ";
            }
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

    solve(vect);

    t = clock() - t;

    cout << endl << "Function with " << vect.size() << " elements was performed for ~" << ((float)t/CLOCKS_PER_SEC) << " sec." << endl;
}

int main()
{
    srand(time(NULL));

    vector<int> emptyArr {};
    vector<int> arr {-10, 5, 8, 1, -4, -4, 10, 3, -1, 1};
    vector<int> arr1 = generateVector(1);
    vector<int> arr10 = generateVector(10);
    vector<int> arr100 = generateVector(100);
    vector<int> arr1000 = generateVector(1000);
    vector<int> arr10000 = generateVector(10000);
    vector<int> arr100000 = generateVector(100000);
    vector<int> arr1000000 = generateVector(1000000);
    vector<int> arr10000000 = generateVector(10000000);
    vector<int> arr100000000 = generateVector(100000000);

    executionTime(emptyArr);
    executionTime(arr);
    executionTime(arr1);
    executionTime(arr10);
    executionTime(arr100);
    executionTime(arr1000);
    executionTime(arr10000);
    executionTime(arr100000);
    executionTime(arr1000000);
    executionTime(arr10000000);
    executionTime(arr100000000);
    return 0;
}
