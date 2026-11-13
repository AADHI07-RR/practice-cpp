class Solution(object):
    def kidsWithCandies(self, candies, ex):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        ans=[]
        mx=max(candies)
        for i in candies:
            if i+ex >=mx:
                ans.append(True)
            else:
                ans.append(False)
        return ans