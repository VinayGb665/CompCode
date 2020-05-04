// ReverseStringRecursion.cpp
// https://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1440/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void print(vector<char>&s){
        for(vector<char> :: iterator it = s.begin(); it!=s.end(); it++){
            std::cout << *it ;
        }
    }

    void reverseString(vector<char>& s, int i=0) {
        int n = s.size();
        if (i == n/2){
            print(s);
            return;
        }
        swap(s[i], s[n-i-1]);
        reverseString(s, i+1);
    }
};


int main(){
    Solution S;
    std :: vector<char> Stri{'a','b','c'};
    S.reverseString(Stri);

}