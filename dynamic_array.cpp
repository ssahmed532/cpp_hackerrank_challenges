#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class DynamicArray
{
public:

    DynamicArray(int paramN)
    : N(paramN)
    {
        initSequences(paramN);
    }

    void query1(int x, int y)
    {
        int seqIdx = (x ^ lastAnswer) % N;

        sequences[seqIdx].push_back(y);
    }

    void query2(int x, int y)
    {
        int seqIdx = (x ^ lastAnswer) % N;

        int elemIdx = (y % sequences[seqIdx].size());

        lastAnswer = sequences[seqIdx][elemIdx];

        cout << lastAnswer << '\n';
    }

    void initSequences(int numSequences)
    {
        sequences.clear();
        sequences.resize(numSequences);
    }

    vector<vector<int>> sequences;
    int lastAnswer = 0;
    int N;
};


/**
 * This is a driver method for the HackerRank solution submission program
 * so that my DynamicArray solver class can be used to test my solution code.
 */
vector<int> dynamicArray(int n, vector<vector<int>> queries)
{
    DynamicArray dynArraySolver(n);

    vector<int> results;

    for (const auto &query: queries)
    {
        if (query[0] == 1)
        {
            dynArraySolver.query1(query[1], query[2]);
        }
        else
        {
            dynArraySolver.query2(query[1], query[2]);
            results.push_back(dynArraySolver.lastAnswer);
        }
    }

    return results;
}


int main(void)
{
    DynamicArray dynArray(2);
    dynArray.query1(0, 5);
    dynArray.query1(1, 7);
    dynArray.query1(0, 3);
    dynArray.query2(1, 0);
    dynArray.query2(1, 1);

    return 0;
}
