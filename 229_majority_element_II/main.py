'''
instruction available in main.cpp
python implementation notice:
    dict CANNOT change size during iteration
'''
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        tetrix_tower = {} #the tetrix tower for clearing up the triplets
        
        for i in range(len(nums)):
            try:
                tetrix_tower[nums[i]] += 1
            except:
                #current element not found
                if len(tetrix_tower) < 2:
                    tetrix_tower[nums[i]] = 1
                else:
                    #reduce all counts in the tower by 1, and delete 0 elements
                    for key,val in tetrix_tower.iteritems():
                        tetrix_tower[key] -= 1
                    tetrix_tower = {key:val for key,val in tetrix_tower.iteritems() if val > 0}

        #clear counts in the dictionary
        tetrix_tower = {key:0 for key in tetrix_tower.iterkeys()}

        #counting occurences
        for i in range(len(nums)):
            try:
                tetrix_tower[nums[i]] += 1
            except:
                pass

        #collecting elements
        result = [key for key,val in tetrix_tower.iteritems() if val>(len(nums)/3)]
        return result


        
#test block
sls = Solution()
print sls.majorityElement([1,1,1,2,2,3,3,3])

