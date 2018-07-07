# LeetCode link: https://leetcode.com/problems/lemonade-change/

class Solution:
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        five = ten = 0
        for bill in bills:
            if bill == 5:
                five += 1
            
            elif bill == 10:
                if five == 0: 
                    return False
                ten += 1
                five -= 1
            
            else:
                if five > 0 and ten > 0:
                    five -= 1
                    ten -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        return True