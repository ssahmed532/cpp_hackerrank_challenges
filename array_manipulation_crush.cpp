//
// https://www.hackerrank.com/challenges/crush/problem
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


void printDataArray(const std::vector<long> &data)
{
    for (const auto &num: data)
    {
        cout << num << " ";
    }
    cout << '\n';
    cout << '\n';
}


void performAdditionOp(int fromIdx, int toIdx, long summand, std::vector<long> &data)
{
    for (int i = (fromIdx - 1); i < toIdx; i++)
    {
        data[i] += summand;
    }
}


// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries)
{
    std::vector<long> data(n, 0);
    cout << "Initial state of Data array :" << '\n';
    printDataArray(data);

    for (const auto &query: queries)
    {
        int a = query[0];
        int b = query[1];
        int k = query[2];
        cout << "a:" << a << ", b:" << b << ", k:" << k << '\n';

        performAdditionOp(a, b, k, data);

        cout << "Data array after this operation:" << '\n';
        printDataArray(data);
    }

    auto iter = std::max_element(data.begin(), data.end());
    return *iter;
}


int main(void)
{
    {
        const int ARRAY_SIZE = 5;
        vector<vector<int>> queries;
        queries.push_back({1, 2, 100});
        queries.push_back({2, 5, 100});
        queries.push_back({3, 4, 100});

        long maxValue = arrayManipulation(ARRAY_SIZE, queries);
        cout << "Max value is: " << maxValue << '\n';
    }

    cout << '\n';
    cout << '\n';

    {
        const int ARRAY_SIZE = 10;
        vector<vector<int>> queries;
        queries.push_back({1, 5, 3});
        queries.push_back({4, 8, 7});
        queries.push_back({6, 9, 1});

        long maxValue = arrayManipulation(ARRAY_SIZE, queries);
        cout << "Max value is: " << maxValue << '\n';
    }

    return 0;
}
