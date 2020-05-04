// MiniStack.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3292/
using namespace std;
#include <bits/stdc++.h>
#include <limits.h>

class MinStack {
public:
    list <int> stack_arr;
    list <int> minstack_arr;
    int size;
    int minVal;
    int headPosition;
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
        headPosition = -1;
    }
    
    void push(int x) {
        // minVal = minstack_arr.front()
        headPosition++;
        if (headPosition == 0) {
            minstack_arr.push_front(x);
        }
        else if (x<=minstack_arr.front()){
            
            minVal = x;
            MinStack :: minstack_arr.push_front(x);
            // x = 2*x - minVal;
        }
        MinStack:: stack_arr.push_front(x);
    }
    
    void pop() {
        int topVal = stack_arr.front();
        int minVal = minstack_arr.front();

        if (topVal == minVal){
            MinStack :: minstack_arr.pop_front();
        }
        
        headPosition --;
        MinStack :: stack_arr.pop_front();

    }
    
    int top() {
        int topVal = stack_arr.front();
        std:: cout << topVal;
        return topVal;
    }
    
    int getMin() {
        int minval  = minstack_arr.front();
        std:: cout << minval;
        return minval;
    }
};


int main(){
    MinStack M;
    M.push(2);
    M.top();
}