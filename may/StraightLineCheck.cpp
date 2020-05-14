// StraightLineCheck.cpp
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/

#include<bits/stdc++.h>
#include <cmath>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int  xDiff, yDiff;
        float currentSlope, prevSlope;
        
        // auto tmp = coordinates.begin();
        for(int i=0; i< coordinates.size()-1; i++){
            
            if(i==0){

                xDiff = coordinates[i+1][0]-coordinates[i][0];
                yDiff = coordinates[i+1][1]-coordinates[i][1];
                if (xDiff==0) prevSlope = 1;
                else {
                    prevSlope = abs(float(yDiff))/abs(float(xDiff));
                    
                }

            }
            else{
                xDiff = coordinates[i+1][0]-coordinates[i][0];
                yDiff = coordinates[i+1][1]-coordinates[i][1];
                if (xDiff==0) currentSlope = 1.0;
                else {
                    currentSlope = yDiff/xDiff;
                }

                if(prevSlope!=currentSlope){
                    return false;
                }


            }
        }
        return true;
    }
};

int main(){
 Solution S;
 vector<vector<int>> coords {
     {1,2},{2,3},{3,4},{4,5},{5,6},{6,7}
 };
 std:: cout << S.checkStraightLine(coords) <<endl;
}