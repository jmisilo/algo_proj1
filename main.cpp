#include <iostream>
#include <vector>

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
    int start;

    for (int i = 0; i < longestStart.size(); i++) {
        cout << endl << "Podciag no. " << i << ": ";
        start = longestStart[i];

        for (int j = 0; j < longestLen + 1; j++) {
            cout << vect[start + j] << " ";
        }
    }
}

int main()
{
    vector<int> arr {-10, 5, 8, 1, -4, -4, 10, 3, -1, 1, -1, -2, -3};

    solve(arr);

    return 0;
}
