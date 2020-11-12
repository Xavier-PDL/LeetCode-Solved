#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        
        bool flip = true;
        for(int x = 0; x < n; x++)
        {
            if(x && nums[x] == nums[x-1]) continue;
            int y = x+1;
            int z = n-1;
            while(y < z)
            {
                int sum = nums[x] + nums[y] + nums[z];
                if(sum == 0)
                {
                    result.push_back({nums[x], nums[y], nums[z]});
                    y++;
                    while(y < z && nums[y] == nums[y-1]) y++;
                }
                else if(sum < 0)
                {
                    y++;
                }
                else
                {
                    z--;
                }
                
            }
        }

        return result;
    }
    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3) return result;
        for(int i = 0; i < n-2; i++)
        {
            for(int j = i+1; j < n-1; j++)
            {
                for(int k = j+1; k < n; k++)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(!sum)
                    {
                        vector<int> buf(3);
                        bool push = true;
                        for(auto r : result)
                        {
                            if(r[0] == buf[0] &&
                                r[1] == buf[1] &&
                                r[2] == buf[2] )
                            {
                                push = false;
                                break;
                            }
                        }
                        if(push) result.push_back(buf);
                    }
                }
            }
        }
        return result;
    }
};

void test(vector<int>& nums, vector<vector<int>>& expected)
{
    Solution c;
    auto result = c.threeSum(nums);
    if(result.size() != expected.size())
    {
        printf("Failed\n");
        return;
    }

    for(int i = 0; i < expected.size(); i++)
    {
        for(int j = 0; j < expected[i].size(); j++)
        {
            if(result[i][j] != expected[i][j])
            {
                printf("Failed\n");
                return;
            }
        }
    }
    
    printf("Success\n");
    return;
}

int main()
{
    vector<int> in = {-1,0,1,2,-1,-4};
    vector<vector<int>> expected = {{-1,-1,2},{-1,0,1}};
    test(in, expected);

    in = {0};
    expected = {};
    test(in, expected);


    return 0;
}
