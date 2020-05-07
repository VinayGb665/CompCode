// FirstUniqueChar.cpp
// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/

#include<bits/stdc++.h>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashMap;
        queue<pair<char,int>> charQ;
        for(int i=0;i<s.size();i++){
            if(hashMap[s[i]]!=0){
                hashMap[s[i]]++;
            }
            else{
                pair<char, int> vec(s[i], i);
                charQ.push(vec);
                hashMap[s[i]]=1;
            }
        }

        while (!charQ.empty()) 
        { 
            pair<char , int> mori;
            mori = charQ.front();
            cout << '\t' << mori.first << endl ; 
            if(hashMap[mori.first]==1){
                std :: cout << "Found first unique char " << mori.first << " at " << mori.second << endl;
                return mori.second;
            }
            charQ.pop(); 
        }
        
        return -1; 
    }
};

int main(){
    Solution S;
    S.firstUniqChar("leetcode");
}