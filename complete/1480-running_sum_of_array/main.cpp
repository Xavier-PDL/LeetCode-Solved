#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums;
        if(!n || n == 1)
            return nums;
        sums.push_back(nums[0]);
        for(int i = 1; i < n; i++)
        {
            sums.push_back(sums[i - 1] + nums[i]);
        }
        return sums;
    }
};

void test(vector<int>& nums, vector<int>& expected)
{
    static int nTest = 0;
    nTest++;

    Solution s;
    auto out = s.runningSum(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        if(out[i] != expected[i])
            printf("Test Case #%d - [FAILURE]\n", nTest);
    }
    
    printf("Test Case #%d - [SUCCESS]\n", nTest);
}

int main()
{
    vector<int> in;
    vector<int> out;
    in = {1,2,3,4};
    out = {1,3,6,10};
    test(in, out);
    in = {1,1,1,1,1};
    out = {1,2,3,4,5};
    test(in, out);
    in = {3,1,2,10,1};
    out = {3,4,6,16,17};
    test(in, out);

    return 0;
}
