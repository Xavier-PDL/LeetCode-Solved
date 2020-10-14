#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        size_t pos = 0;
        while((pos = address.find(".", pos)) != string::npos) 
        {
            address.replace(pos, 1, "[.]");
            pos += 3;
        }
        return address;
    }
};

void test(string ip, string expected)
{
    Solution s;
    string res = s.defangIPaddr(ip);
    cout << (res == expected ? "[SUCCESS]" : "[FAILURE]") << endl;
}

int main()
{
    string ip = "1.1.1.1";
    string expected = "1[.]1[.]1[.]1";
    test(ip, expected);
    ip = "255.100.50.0";
    expected = "255[.]100[.]50[.]0";
    test(ip, expected);
    return 0;
}
