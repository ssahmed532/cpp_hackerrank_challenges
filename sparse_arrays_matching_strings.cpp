//
// https://www.hackerrank.com/challenges/sparse-arrays/problem
// 

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) 
{
    std::vector<int> results(queries.size(), 0);

    for (int i = 0; i < queries.size(); i++)
    {
        for (const auto &inputStr: strings)
        {
            if (inputStr == queries[i])
            {
                results[i] = ++results[i];
            }
        }
    }

    return results;
}


int main(void)
{
    {
        std::vector<string> inputStr = { "aba", "baba", "aba", "xzxb" };
        std::vector<string> queries = { "aba", "xzxb", "ab" };

        auto results = matchingStrings(inputStr, queries);
        cout << "String match results are:" << '\n';
        for (int i = 0; i < queries.size(); i++)
        {
            cout << queries[i] << ": " << results[i] << '\n';
        }
        cout << '\n';
    }

    {
        std::vector<string> inputStr = { "def", "de", "fgh" };
        std::vector<string> queries = { "de", "lmn", "fgh" };

        auto results = matchingStrings(inputStr, queries);
        cout << "String match results are:" << '\n';
        for (int i = 0; i < queries.size(); i++)
        {
            cout << queries[i] << ": " << results[i] << '\n';
        }
        cout << '\n';
    }

    {
        std::vector<string> inputStr = { "abcde", "sdaklfj", "asdjf", "na",
                                         "basdn", "sdaklfj", "asdjf", "na",
                                         "asdjf", "na", "basdn", "sdaklfj",
                                         "asdjf" };
        std::vector<string> queries = { "abcde", "sdaklfj", "asdjf", "na", "basdn" };

        auto results = matchingStrings(inputStr, queries);
        cout << "String match results are:" << '\n';
        for (int i = 0; i < queries.size(); i++)
        {
            cout << queries[i] << ": " << results[i] << '\n';
        }
        cout << '\n';
    }

    return 0;
}
