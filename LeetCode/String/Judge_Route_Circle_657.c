//LeetCode Link: https://leetcode.com/problems/judge-route-circle/
bool judgeCircle(char* moves) {
    const int size = strlen(moves);
    
    int x = 0;
    int y = 0;
    
    for (int move_index = 0; move_index < size; ++move_index){
        char move = moves[move_index];
        
        if (move == 'U') { x += 1; }
        if (move == 'D') { x -= 1; }
        if (move == 'R') { y += 1; }
        if (move == 'L') { y -= 1; }
    }
    
    return (x == 0) && (y == 0);
}