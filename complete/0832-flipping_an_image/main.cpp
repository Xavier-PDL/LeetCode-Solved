#include <bits/stdc++.h>
using namespace std;

#define plf() printf("[FAILURE]\n")
#define pls() printf("[SUCCESS]\n")

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        auto nRows = A.size();
        auto nCols = A[0].size();
        vector<vector<int>> res(nRows);
        for(int i = 0; i < nRows; i++)
        {
            for(int j = nCols-1; j >= 0; j--)
            {
                res[i].push_back(!A[i][j]);
            }
        }
        return res;
    }
};

void test(vector<vector<int>> in, vector<vector<int>> expected)
{
    Solution s;
    auto out = s.flipAndInvertImage(in);
    auto nRows = in.size();
    auto nCols = in[0].size();
    if(out.size() != nRows)
    {
        plf();
        return;
    }
    if(out[0].size() != nCols)
    {
        plf();
        return;
    }

    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            if(out[i][j] != expected[i][j])
            {
                plf();
                return;
            }
        }
    }
    pls();
}

int main()
{
    vector<vector<int>> in = {{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> expected = {{1,0,0},{0,1,0},{1,1,1}};
    test(in, expected);
    in = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    expected = {{1,1,0,0},{0,1,1,0},{0,0,0,1},{1,0,1,0}};
    test(in, expected);
    return 0;
}
