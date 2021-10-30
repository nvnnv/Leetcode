# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        idx = 41
        while idx > 40:
            c = rand7()
            r = rand7()
            idx = c + (r-1)*7
        return 1+(idx-1)%10
