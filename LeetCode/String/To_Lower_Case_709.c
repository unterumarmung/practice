//LeetCode Link: https://leetcode.com/problems/to-lower-case/

/*
Complexity analysis:
* Time: O(str_length)
* Space: O(1)
*/
char to_lower(char letter) {
    const int difference = 'A' - 'a';
    return letter - difference;
}

bool is_upper(char letter) {
    return letter >= 'A' && letter <= 'Z';
}

char* toLowerCase(char* str) {
    const int str_length = strlen(str);
    for (int ch = 0; ch < str_length; ++ch) {
        if (is_upper(str[ch])) {
            str[ch] = to_lower(str[ch]);
        }
    }
    return str;
}