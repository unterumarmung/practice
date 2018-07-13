//LettCode Link: https://leetcode.com/problems/student-attendance-record-i/
bool checkRecord(char* s) {
    const int size = strlen(s);
    
    int absent_count = 0;
    int late_max_duration = 0;
    
    bool can_be_rewarded = true;
    
    for (int i = 0; i < size && can_be_rewarded; ++i) {
        if (s[i] == 'A') { absent_count += 1; }
        else if (late_max_duration == 0 && i != 0 && s[i - 1] == 'L' && s[i] == 'L') { late_max_duration = 2; }
        else if (late_max_duration != 0 && s[i] == 'L') { late_max_duration += 1; }
        if (s[i] != 'L') { late_max_duration = 0; }
        
        can_be_rewarded = (absent_count <= 1) && (late_max_duration <= 2);
    }
    
    return can_be_rewarded;
}
