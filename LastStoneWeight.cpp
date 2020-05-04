// LastStoneWeight.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3297/
using namespace std;
#include <bits/stdc++.h>
#include <limits.h>

class Solution {
public:
    void print(std::vector<int> const &input){
        for (int i = 0; i < input.size(); i++) {
            std::cout << input.at(i) << ' ';
        }
    }

    int lastStoneWeight(vector<int> stones) {
        int maxIndex;
        int diff;
        while(stones.size()>1){
            sort(stones.begin(), stones.end());
            maxIndex = stones.size();
            diff = stones.at(maxIndex-1) - stones.at(maxIndex-2);
            if (diff == 0){
                stones.pop_back();
                stones.pop_back();
                // stones.erase()
                // stones.erase(maxIndex-1, stones.end());
                // stones.erase(maxIndex-2, stones.end());
                
            }
            else{
                // stones.erase(stones.end());
                // stones.erase(stones.end());
                stones.pop_back();
                stones.pop_back();
                stones.push_back(diff);
            }
        }
        // print(stones);
        // std :: cout << stones << '\n';
        if (stones.size() == 0){
            return 0;
        }
        return stones[0];
    }
};

int main(){
     vector<int> v {2,7,4,1,8,1};

    Solution S;
    S.lastStoneWeight(v);
}