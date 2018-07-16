#LeetCode Link: https://leetcode.com/problems/detect-capital/

class Solution:
    def detectCapitalUse(self, word:str) -> bool:
        length = len(word)
        if length == 0 or length == 1:
            return True
        elif word.islower(): 
            return True
        elif word.isupper(): 
            return True
        else: 
            return word[0].isupper() and word[1:].islower()