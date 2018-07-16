#LeetCode Link: https://leetcode.com/problems/ransom-note/

#1st solution
class Solution:
    def count_letters(self, string:str) -> dict:
        result = dict()
        
        for char in string:
            if char not in result:
                result[char] = 1
            else:
                result[char] += 1
        
        return result
    def canConstruct(self, ransom_note:str, magazine:str) -> bool:
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        ransom_letters_count = self.count_letters(ransom_note)
        magazine_letters_count = self.count_letters(magazine)
        
        for key in ransom_letters_count.keys():
            if key not in magazine_letters_count:
                return False
            elif magazine_letters_count[key] < ransom_letters_count[key]:
                return False
        else:
            return True

#2nd solution
class Solution:
    def canConstruct(self, ransom_note:str, magazine:str) -> bool:
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        ransom_letters_count = collections.Counter(ransom_note)
        magazine_letters_count = collections.Counter(magazine)
        
        for key in dict(ransom_letters_count).keys():
            if key not in magazine_letters_count:
                return False
            elif magazine_letters_count[key] < ransom_letters_count[key]:
                return False
        else:
            return True