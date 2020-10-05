#include <bits/stdc++.h>
using namespace std;

/*
PAYPALISHIRING : r = 3; n = 14

P   A   H   N
A P L S I I G
Y   I   R

P | i = 0; i += r+1
A | i = 4; i += r+1
H | i = 8; i += r+1
N | i = 12; i += r+1; i > n


PAHNAPLSIIGYIR
*/

class Solution {
public:
    string convert(string s, int numRows) {
        std::map<int, string> z;
        int r = 0;
        bool bInc = true;
        for(char c : s)
        {
            z[r] += c;
            if(bInc)
            {
                r++;
                if(r == numRows-1) bInc = false;
            }
            else
            {
                r--;
                if(r == 0) bInc = true;
            }
            
        }
        string res;
        for(auto rs : z)
        {
            res += rs.second;
        }
        return res;
    }
};

int main()
{
    Solution s;
    string in = "PAYPALISHIRING";
    string out = "PAHNAPLSIIGYIR";
    string res = s.convert(in, 3);
    printf("\n%s\n", res == out ? "SUCCESS" : "FAILURE");
    return 0;
}