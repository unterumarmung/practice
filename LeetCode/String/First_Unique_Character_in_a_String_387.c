//LeetCode Link: https://leetcode.com/problems/first-unique-character-in-a-string/
#define LETTERS_COUNT 26

int firstUniqChar(char* s) {
    const int size = strlen(s);
    
    int letters_count[LETTERS_COUNT] = {0};
    int location[LETTERS_COUNT] = {0};
    
    for (int i = 0; i < size; ++i) {
        int index = s[i] - 'a';
        letters_count[index] += 1;
        location[index] = i;
    }
    
    int min_location = INT_MAX;
    
    for (int i = 0; i < LETTERS_COUNT; ++i) {
        if (letters_count[i] == 1 && location[i] < min_location) { min_location = location[i]; } 
    }
    
    if (min_location == INT_MAX) { min_location = -1; }
    
    return min_location;
}