"""
N rounds, N bulbs, therefore, for any bulb i, it will be toggled at each factor of i if number of factors are even, the light will be turned off finally.

To find all i that has odd number of factors, consider the fact that factors are always in pairs, therefore, only square numbers can have odd number of factors 
"""
from math import sqrt
class Solution(object):

    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int(sqrt(n)) 
