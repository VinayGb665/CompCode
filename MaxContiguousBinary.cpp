// MaxContiguousBinary.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3298/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print(std::vector<pair <int, int>> &input){
        for (int i = 0; i < input.size(); i++) {
            std::cout << input[i].first << input[i].second << ' ';
        }
        std:: cout << '\n';
    }
    
    int findMaxLengthFromIndex(vector<int>& nums, int startIndex) {
        vector < pair <int, int>> countVec(0, make_pair(0,0));
        int oneCounter, zeroCounter = 0; 
        int len = 0;
        for(int i=startIndex; i<nums.size(); ++i){
            if( nums[i] == 0 ){
                oneCounter++;
            }
            else
            {
                zeroCounter++;
            }
            if (oneCounter == zeroCounter && 2*oneCounter>len){
                len = 2*oneCounter;
            }
            countVec.push_back(make_pair(zeroCounter, oneCounter));
            
        }
        // Solution :: print(countVec);
        // std:: cout << "\t " << len << "\n";

        // std :: cout << countVec << '\n';
        return len;
    }

    int findMaxLength(vector<int>& nums){
        Solution S;
        int maxLen = 0;
        int temp;
        for(int i=0; i<nums.size();i++){
            temp = findMaxLengthFromIndex(nums, i);
            cout << "OK " << nums.size()-i << '\n';
            if (temp == nums.size()-i){
                cout << "a,aaaaaa" ;
                maxLen = temp;
                break;
            }
            else if (temp > maxLen) {
                maxLen = temp;
            }
            std :: cout << i << " " << temp << " " << maxLen << '\n';
        }
        std :: cout << "returning " << maxLen << '\n';
        return maxLen;
    }
};

int main(){
    vector <int> vect {0,1,1,0,1,1,1,0};
    Solution S;
    int maxLen;
    maxLen = S.findMaxLength(vect);
    std :: cout << "Max sub shit is " << maxLen << '\n';

}