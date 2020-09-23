class Solution:
    def lengthOfLongestSubstring(self, s:str) -> int:
        i = 0
        result = 0
        lastIdx = [-1]*256
        for j in range(len(s)):
            i = max(i, lastIdx[ord(s[j])] + 1)
            lastIdx[ord(s[j])] = j
            result = max(result, j - i + 1)
        return result

def test(c, s, expected):
    n = c.lengthOfLongestSubstring(s)
    if n == expected:
        print("[SUCCESS] s = \"{}\", n = {}, expected = {}".format(s, n,
            expected))
    else:
        print("[FAILED] s = \"{}\", n = {}, expected = {}".format(s, n,
            expected))
        

c = Solution()
s = "abcabcbb"
test(c, s, 3)
s = "bbbbb"
test(c, s, 1)
s = "pwwkew"
test(c, s, 3)
s = ""
test(c, s, 0)
s = "au"
test(c, s, 2)
s = "dvdf"
test(c, s, 3)