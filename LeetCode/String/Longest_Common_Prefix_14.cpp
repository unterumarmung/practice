//LeetCode Link: https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const unsigned strs_size = strs.size();
        
        if (strs_size == 0) { return ""; }
        else if (strs_size == 1) { return strs[0]; }
        
        const unsigned first_size = strs[0].size();

        bool is_ok = true;
        string common_prefix = "";
        string temp_prefix = "";
        unsigned temp_prefix_size = 0;
        
        for (int i = 0; i < first_size && is_ok; ++i)
        {
            temp_prefix += strs[0][i];
            temp_prefix_size += 1;
            
            for (int str = 1; str < strs_size && is_ok; ++str)
            { is_ok = temp_prefix == strs[str].substr(0, temp_prefix_size); }
            
            if (is_ok) { common_prefix += strs[0][i]; }
        }
        
        return common_prefix;
    }
};