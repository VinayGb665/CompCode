// IsCousins.cpp
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
        pair<int, int> getlevel(TreeNode* root, int value, int level=0, int parentValue=-1){
            /*
                * Recursive function takes the value to be searched for and value of its parent
                * Returns a pair <int, int> where
                    * first is the level in which the value was found
                    * second is the immediate parent value of the found node 
                * Returns (-1,-1) if not found
            */
            TreeNode* movingPointer = root;
            
            
            if(movingPointer!=nullptr && movingPointer->val == value){
                pair<int, int> result;
                result = make_pair(level, parentValue);
                return result;
            }
            else if(movingPointer==nullptr ) {
                pair<int, int> result;
                result = make_pair(-1, -1);
                return result;
            }
            
            pair<int, int> foundRight = getlevel(movingPointer->right, value, level+1, movingPointer->val);
            
            pair<int, int> foundLeft = getlevel(movingPointer->left, value, level+1, movingPointer->val);

            if(foundRight.first!=-1){
                
                return foundRight;
            }
            else if (foundLeft.first!=-1)
            {
                return foundLeft;
            }
            
            return make_pair(-1,-1);
        }

    public:
        
        bool isCousins(TreeNode* root, int x, int y) {
            pair <int, int> xResult = getlevel(root, x);
            pair <int, int> yResult = getlevel(root, y);
            
            
            std:: cout << xResult.first << " " << xResult.second << endl;
            std:: cout << yResult.first << " " << yResult.second << endl;
            // Check if levels are same and parents are different
            return xResult.first==yResult.first && xResult.second!=yResult.second;
        }
};  