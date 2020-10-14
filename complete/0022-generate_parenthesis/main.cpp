#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(int n, int open, int closed, string str, vector<string>& res)
    {
        if(n == open && n == closed)
        {
            res.push_back(str);
            return;
        }
        if(open < n)
            generate(n, open+1, closed, str + "(", res);
        if(closed < n && closed < open)
            generate(n, open, closed+1, str + ")", res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 1, 0, "(", result);
        return result;
    }
};

void test(int n, vector<string> expected)
{
    Solution s;
    auto result = s.generateParenthesis(n);
    auto nRows = expected.size();
    
    for(int i = 0; i < nRows; i++)
    {
        if(result[i] != expected[i])
        {
            printf("[FAILURE]\n");
        }
    }
    printf("[SUCCESS]\n");
}

int main()
{
    int n = 3;
    vector<string> expected = {"((()))","(()())","(())()","()(())","()()()"};
    test(n, expected);

    return 0;
}
