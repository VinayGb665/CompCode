// FloodFill.cpp
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void floodFillUtil(vector<vector<int>>& image, int x, int y, int prevC, int newC) 
    { 
        // Base cases 
        if (x < 0 || x >= image.size() || y < 0 || y >= image.at(0).size()) 
            return; 
        if (image.at(x).at(y) != prevC) 
            return; 
        if (image.at(x).at(y) == newC)  
            return;  
    
        // Replace the color at (x, y) 
        image[x][y] = newC; 
    
        // Recur for north, east, south and west 
        floodFillUtil(image, x+1, y, prevC, newC); 
        floodFillUtil(image, x-1, y, prevC, newC); 
        floodFillUtil(image, x, y+1, prevC, newC); 
        floodFillUtil(image, x, y-1, prevC, newC); 
    } 

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevC = image.at(sr).at(sc); 
        floodFillUtil(image, sr, sc, prevC, newColor);

        return image;
    }
};


int main(){
    vector<vector<int>> image {{1,1,1},{1,1,0},{1,0,1}};
    Solution S;
    S.floodFill(image, 1, 1, 2);
}

