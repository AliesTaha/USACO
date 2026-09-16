class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        new_s=[]
        for c in s:
            if c.isalnum():
                new_s.append(c)
        ret=''.join(new_s)
        ret=ret.lower()
        return ret==ret[::-1]