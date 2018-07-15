//LeetCode Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/

void swap_chars_in_string(char* str, int first_index, int second_index) {
    char temp_char = str[first_index];
    str[first_index] = str[second_index];
    str[second_index] = temp_char;
}

bool find_word(char* str, int* start, int* end) {
    int s = *(start); //stands for start
    int e; //stands for end
    
    while (isspace(str[s]) && str[s] != '\0') s += 1;
    
    if (str[s] == '\0') return false; //there's no word in the str
    
    e = s;
    
    while (!isspace(str[e]) && str[e] != '\0') e += 1;
    e -= 1; 
    
    (*start) = s;
    (*end) = e;
    return true;
}

char* reverse_substring(char* str, int start, int end) {
    const int length = (end - start + 1);
    for (int i = 0; i < length / 2; ++i) {
		int left = i + start;
		int right = end - i;
        swap_chars_in_string(str, left, right);
    }
    return str;
}

char* reverseWords(char* str) {
    const int str_length = strlen(str);
    
    if (str_length == 0 || str_length == 1) {
        return str;
    }
    
    int start_index = 0;
    int end_index = 0;
    
    bool word_found = find_word(str, &start_index, &end_index);
    
    while (word_found) {
        reverse_substring(str, start_index, end_index);
        start_index = end_index + 1;
        word_found = find_word(str, &start_index, &end_index);
    }
    
    return str;
}