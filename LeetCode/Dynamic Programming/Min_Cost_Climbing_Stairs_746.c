//LeetCode Link: 

int min(int val1, int val2) {
    return (val1 < val2) ? val1 : val2;
}

/*
Complexity analysis:
* Time: O(cost_size)
* Space: O(cost_size)
*/
int minCostClimbingStairs(int* cost, int cost_size) {
    int* each_cost = (int*)malloc(cost_size * sizeof(int));
    each_cost[0] = cost[0];
    each_cost[1] = cost[1];
    
    for (int i = 2; i < cost_size; ++i) {
        each_cost[i] = min(each_cost[i-1] + cost[i], each_cost[i-2] + cost[i]);
    }

    return min(each_cost[cost_size - 1], each_cost[cost_size - 2]);
}