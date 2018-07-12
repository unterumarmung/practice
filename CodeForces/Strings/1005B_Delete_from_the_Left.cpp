//CodeForces link: http://codeforces.com/problemset/problem/1005/B
#include <iostream>
#include <string>

using namespace std;

int main() {
    string first;
    string second;
    
    cin >> first;
    cin >> second;
    
    const size_t first_length = first.length();
    const size_t second_length = second.length();
    
    size_t common_suffix_length = 0;
    
    unsigned int moves = 0;
    
    if(first_length == 0) { moves = second_length; }
    else if(second_length == 0) { moves = first_length; }
    else if(first == second) { moves = 0; }
    else
    {
        while( first[first_length - common_suffix_length - 1] 
                == second[second_length - common_suffix_length - 1] &&
            common_suffix_length < first_length && 
            common_suffix_length < second_length)
        {
              common_suffix_length += 1;
        }
        
        moves = (first_length - common_suffix_length) + (second_length - common_suffix_length);
    }
    
    cout << moves;
    return 0;
}
