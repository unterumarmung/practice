//LeetCode link: https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool success = true;
        unsigned short int five = 0;
        unsigned short int ten = 0;
        
        for(unsigned short int i = 0; i < bills.size() && success; ++i){
            if(bills[i] == 5) { five += 1; }
            
            else if(bills[i] == 10){
                if(five == 0) { success = false; }
                five -= 1;
                ten += 1;
            }
            
            else{
                if(ten > 0 && five > 0){
                    five -= 1;
                    ten -= 1;
                }
                else if(five >= 3) { five -= 3; } 
                else { success = false; }
            }
        }
        
        return success;
    }
};
