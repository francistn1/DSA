class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0
        roman = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}

        for a, b in zip(s, s[1:]):
            if roman[a] < roman[b]:
                res -= roman[a] #This for numbers represented by two numerals for example IV is 1 and 5, 1<5 therefore the result should be 5-1 = 4
            else:
                res += roman[a]
        return res + roman[s[-1]]
       



