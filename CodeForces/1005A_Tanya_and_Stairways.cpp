//CodeForces link: http://codeforces.com/problemset/problem/1005/A
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>

#define MAX_PRONOUNCED_COUNT 1000

int main() {
    int pronounced_count;
    int steps[MAX_PRONOUNCED_COUNT];
    int stairways_count = 0;
    int stairways[MAX_PRONOUNCED_COUNT];
    
    scanf("%d", &pronounced_count);

    for(int i = 0; i < pronounced_count; ++i)
    {
        scanf("%d", &steps[i]);
    }
    
    for(int step = 0; step < pronounced_count - 1; ++step)
    {
        while(steps[step] < steps[step + 1])
        {
            ++step;
        }
        stairways[stairways_count] = steps[step];
        stairways_count += 1;
    }
    
    if(steps[pronounced_count - 1] == 1)
    { //checking if the last stairway has length of 1
        stairways[stairways_count] = 1;
        stairways_count += 1;
    }
    
    printf("%d\n", stairways_count);
    
    for(int i = 0; i < stairways_count; ++i)
    {
        printf("%d ", stairways[i]);
    }
    return 0;
}