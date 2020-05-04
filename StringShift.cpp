// StringShift.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3299/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        for(auto it = shift.begin(); it!= shift.end(); ++it  ){
            if (it.first == 0) {
                std :: rotate(s.begin(), s.begin()+it.second, s.end());
                std :: cout << s << '\n'; 
            }
            else{
                std :: rotate(s.rbegin(), s.rbegin()+it.second, s.rend());
                std :: cout << s << '\n'; 
            }
            
        }
        return s;
    }
};

int main(){
    string s = "abcd";
    vector<vector<int>> vec(10, vector<int>(10, 100));
    Solution S;
    S.stringShift(s, vec);


}