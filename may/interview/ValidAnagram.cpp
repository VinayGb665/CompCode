// ValidAnagram.cpp
// https://leetcode.com/explore/featured/card/top-interview-questions-easy/127/strings/882/
/*
    * First basic check is for size, not the same size return false
    * Make a hashmap/hashset 
    * Insert all chars from one and traverse through other to check if there or not
    * Since unicodes are also there make hashmap key to be like { int(char-'a') : count } 
*/

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> hashMap; 
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }

        // Traverse throught the first string
        for(int i=0; i<s.size(); i++){
            hashMap[s[i]-'a']++;
        }
        // Traverse through second string check count in hashmap
        for(int i=0; i<t.size(); i++){
            if(hashMap[t[i]-'a']==0) {
                std :: cout << "False" << endl;
                return false;
            }
            
            hashMap[t[i]-'a']--; // Found it pop it
        }

        std :: cout << "True" << endl;
        return true;
    }
};

 int main(){
     Solution S;
     S.isAnagram("anagram", "nagaram");
     S.isAnagram("rat", "car");
 }
 