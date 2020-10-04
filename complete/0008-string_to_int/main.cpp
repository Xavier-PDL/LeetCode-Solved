#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        bool bParsing = false;
        bool bNegative = false;
        bool bHasPositive = false;
        for(auto c : str)
        {
            if((c >= '0' && c <= '9') || c == '-' || c == '+')
            {
                
                if(c == '-')
                {
                    if(bParsing || bNegative || bHasPositive)
                        break;
                    else
                    {
                        bNegative = true;
                        bParsing = true;
                    }
                }
                else if(c == '+')
                {
                    if(bParsing || bHasPositive || bNegative)
                        break;
                    else
                    {
                        bHasPositive = true;
                        bParsing = true;
                    }
                }
                else
                {
                    bParsing = true;
                    result *= 10;
                    if(INT_MAX - result >= c - 0x30)
                        result += (c - 0x30);
                    else 
                    {
                        if(bNegative) return INT_MIN;
                        else return INT_MAX;
                    }
                }
            }
            else if(c == ' ' && !bParsing)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        
        return bNegative ? result*-1 : result;
    }
};

int main()
{
    Solution s;
    int result = s.myAtoi("-5-");
    printf("%d\n", result);
    return 0;
}