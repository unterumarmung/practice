//LeetCode Link: https://leetcode.com/problems/implement-strstr/

int strStr(char* string, char* substring) {
    //defining constants
    const char first_char = substring[0]; //first element of substring (needle)
    const unsigned str_length = strlen(string); //length of string (haystack)
    const unsigned sub_length = strlen(substring); //length of substring (needle)
    
    if (sub_length == 0) { return 0; } 
    if (sub_length > str_length) { return -1; }
    
    char* first_char_pointer = strchr(string, first_char); 
        //a pointer to the first element of substring (needle) in string (haystack)
    
    bool is_possible = first_char_pointer != NULL; 
        //a flag which means that there can be occurrences of substring (needle)
    
    while (is_possible) {
        int index = (int)(first_char_pointer - string); //extracting the index with pointer arithmetics
        
        if (index + sub_length - 1 < str_length) {
            bool equal = !strncmp(first_char_pointer, substring, sub_length);
            if (equal) { return index; }
        }
        
        first_char_pointer = strchr(string + index + 1, first_char);
        is_possible = (first_char_pointer != NULL) && (index + sub_length - 1 < str_length);
    }
    
    return -1;
}
