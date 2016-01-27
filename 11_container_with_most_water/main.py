"""
Set two pointers left and right
starting at left = 0, right = n-1
V = min(h[left],h[right]) * (right-left)

Move the pointer on the shorter bar inner, and keep updating V

Time Complexity : O(n)
"""
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height)-1

        max_volume = 0
        
        while left < right:
            min_height = min([height[left],height[right]])
            if max_volume < min_height * (right - left):
                max_volume = min_height * (right - left)
            if height[left] == min_height:
                left += 1
            if height[right] == min_height:
                right -= 1

        return max_volume


