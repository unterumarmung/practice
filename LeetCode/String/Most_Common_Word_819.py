#LeetCode Link: https://leetcode.com/problems/most-common-word/

class Solution:
    def get_words(self, string:str) -> list:
        string = string.lower()
        return re.split(r'[^\w]', string)
    
    def mostCommonWord(self, paragraph:str, banned:list) -> str:
        words = self.get_words(paragraph)

        count = collections.Counter(words).most_common()

        for word, occur_times in count:
            if word not in banned and word != '':
                return word