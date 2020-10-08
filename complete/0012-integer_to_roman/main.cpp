#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string roman;
        while(num >= 1000)
        {
            roman += "M";
            num -= 1000;
        }

        if(num >= 900)
        {
            roman += "CM";
            num -= 900;
        }

        while(num >= 500)
        {
            roman += "D";
            num -= 500;
        }

        if(num >= 400)
        {
            roman += "CD";
            num -= 400;
        }

        while(num >= 100)
        {
            roman += "C";
            num -= 100;
        }

        if(num >= 90)
        {
            roman += "XC";
            num -= 90;
        }

        while(num >= 50)
        {
            roman += "L";
            num -= 50;
        }

        if(num >= 40)
        {
            roman += "XL";
            num -= 40;
        }

        while(num >= 10)
        {
            roman += "X";
            num -= 10;
        }

        if(num == 9)
        {
            roman += "IX";
            num -= 9;
        }

        if(num >= 5)
        {
            roman += "V";
            num -= 5;
        }

        if(num == 4)
        {
            roman += "IV";
            num -= 4;
        }

        while(num > 0)
        {
            roman += "I";
            num -= 1;
        }

        return roman;
    }
};

void test(int i, string e)
{
    Solution s;
    auto r = s.intToRoman(i);
    printf("[%s] Input: %d, Output: %s, Expected: %s\n", 
        r == e ? "SUCCESS" : "FAILURE",
        i, r.c_str(), e.c_str());
}

int main()
{
    test(0, "");
    test(3, "III");
    test(4, "IV");
    test(5, "V");
    test(9, "IX");
    test(10, "X");
    test(144, "CXLIV");
    test(149, "CXLIX");
    test(58, "LVIII");
    test(1994, "MCMXCIV");
    return 0;
}