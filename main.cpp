#include <iostream>
#include <vector>
#include <cstdlib> // srand, rand
#include <cstdio> // NULL
#include <time.h> // time

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

        for (int i = 0; i < longestStart.size(); i++) {
            cout << endl << "Podciag no. " << i << ": ";
            start = longestStart[i];

            for (int j = 0; j < longestLen + 1; j++) {
                cout << vect[start + j] << " ";
            }
        }
    }
}

// generate n el. vector
vector<int> generateVector(int n) {
    vector<int> new_vect;

    for(int i = 0; i < n; i++) {
        new_vect.push_back(rand() % 10);
    }

    return new_vect;
}

int main()
{
    srand(time(NULL));
    // vector<int> arr {-10, 5, 8, 1, -4, -4, 10, 3, -1, 1, -1, -2, -3};
    // vector<int> x = generateVector(50);
    /*
    for (int i = 0; i < 50; i++) {
        cout << x[i] << endl;
    }
    */
    // solve(generateVector(500));

    vector <int> a = {};
    solve(a);

    return 0;
}
