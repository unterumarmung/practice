#LeetCode Link:
class Solution:
    def to_morse_code(self, word):
        A_CODE = ord("a")
        
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        morse_word = ""
        
        for char in word:
            morse_word += morse[ord(char) - A_CODE]
        
        return morse_word
        
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        words_set = set()
        
        for word in words:
            words_set.add(self.to_morse_code(word))
            
        return len(words_set)