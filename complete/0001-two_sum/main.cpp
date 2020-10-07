#include <bits/stdc++.h>
#include <limits>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(j == i)
                    continue;
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {0};
    }
};

int main()
{
    int target = 9;
    vector<int> nums = {2,7,11,15};

    Solution s;
    auto v = s.twoSum(nums, target);

    printf("%d + %d = %d\n", nums[v[0]], nums[v[1]], target);

    return 0;
}
