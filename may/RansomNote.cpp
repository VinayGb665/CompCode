// RansomNote.cpp
// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
#include<bits/stdc++.h>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    unordered_set<char> charSet;
    unordered_map<char, int> charMap;
    bool canConstruct(string ransomNote, string magazine) {
        for(int i=0; i<magazine.size(); i++){ // Insert everything into a set
            // charSet.insert(magazine[i]);
            charMap[magazine[i]] +=1;
        }
        for(int i=0; i<ransomNote.size(); i++){
            if(charMap[ransomNote[i]]==0){
                std :: cout << "False" << endl;
                return false;
            }
            else{
                // charSet.erase(ransomNote[i]);
                charMap[ransomNote[i]]--;
            }
        }
        std :: cout << "True" << endl;
        return true;
    }
};

int main(){
    Solution S;
    S.canConstruct("a", "b");
    S.canConstruct("aa", "ab");
    S.canConstruct("aa", "aab");
}