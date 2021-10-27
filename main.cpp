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

            // 2. it is equal

            // 3. else - skip

            // restart variables
            curSeqStart = 0;
            curSeqLen = 0;
        }
    }
}

int main()
{

    return 0;
}
