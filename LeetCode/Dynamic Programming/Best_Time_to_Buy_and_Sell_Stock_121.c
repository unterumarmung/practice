//LeetCode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int min(int val1, int val2) {
    return (val1 < val2) ? val1 : val2;
}

int max(int val1, int val2) {
    return (val1 > val2) ? val1 : val2;
}

int maxProfit(int* prices, int prices_size) {
    int min_price = prices[0];
    int max_profit = 0;
    
    for (int i = 1; i < prices_size; ++i) {
        min_price = min(min_price, prices[i]);
        int current_profit = prices[i] - min_price;
        max_profit = max(max_profit, current_profit);
    }
    
    return max_profit;
}