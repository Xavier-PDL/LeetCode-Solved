#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time complexity: O(2*n) == O(n)
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        int maxIdx = 0;
        int n = candies.size();
        vector<bool> res;
        // find kid with greatest amount of candies
        for(int i = 0; i < n; i++)
        {
            if(candies[i] > max)
            {
                max = candies[i];
                maxIdx = i;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(candies[i] + extraCandies >= max)
                res.push_back(true);
            else 
                res.push_back(false);
        }
        return res;
    }
};

void test(vector<int>& candies, int extraCandies, vector<bool> expected)
{
    static int nTest = 0;
    nTest++;

    Solution s;
    auto r = s.kidsWithCandies(candies, extraCandies);
    for(int i = 0; i < expected.size(); i++)
    {
        if(r[i] != expected[i])
            printf("Test case #%d - [FAILURE]\n", nTest);
    }
    printf("Test case #%d - [SUCCCESS]\n", nTest);
}

int main()
{
    vector<int> candies;
    int extraCandies = 0;
    vector<bool> expected;
    candies = {2,3,5,1,3};
    extraCandies = 3;
    expected = {true,true,true,false,true};
    test(candies, extraCandies, expected);
    candies = {4,2,1,1,2};
    extraCandies = 1;
    expected = {true,false,false,false,false};
    test(candies, extraCandies, expected);
    candies = {12,1,12};
    extraCandies = 10;
    expected = {true, false, true};
    test(candies, extraCandies, expected);

    return 0;
}
