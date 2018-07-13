//LeetCode Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
int max(int val1, int val2) {
    return (val1 > val2) ? val1 : val2;
}

int lengthOfLongestSubstring(char* str) {
    const int str_length = strlen(str); //length of string
    
    if (str_length == 0) { return 0; }
    if (str_length == 1) { return 1; }
    
    int max_substring_length = 1; //length of the longest substring without repeating characters
    int current_begin = 0; 
    
    for (int char_index = 1; char_index < str_length; ++char_index) {
        char current_char = str[char_index];
        int current_length; //length of the longest required substring for current character
        
        for (int i = current_begin; i < char_index; ++i) {
            if (str[i] == current_char) { current_begin = i + 1; }
        }
        
        current_length = char_index - current_begin + 1;
        max_substring_length = max(max_substring_length, current_length);
    }
    
    return max_substring_length;
}
