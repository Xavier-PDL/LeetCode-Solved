#include <vector>
#include <stdio.h>

void reverseString(std::vector<char>& s)
{
    for(int i = 0; i < s.size() / 2; i++)
    {
        char tmp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = tmp;
    }
}

int main()
{
    std::vector<char> s;
    //std::vector<char> s = {'h','e'};
    //std::vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    printf("{");
    for(int i = 0; i < s.size(); i++)
        printf(i < s.size() - 1 ?  "%c, " : "%c }\n", s[i]);
    return 0;
}
