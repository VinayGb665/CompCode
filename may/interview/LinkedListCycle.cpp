// LinkedListCycle.cpp
// https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/773/
/*
    * Floyd's Tortoise and Hare Algorithm for cycle detection
    * Get 2 pointers to the start, tortoise jumps by one and hare jumps by two ( till null )
    * If they are same at some point then cycle
    * If someone reaches null no cycle
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *tortoise = head;
        ListNode *hare = head;
        while(tortoise!=NULL && tortoise->next!=NULL && hare->next!=NULL && hare->next->next!=NULL){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(hare == tortoise){
                return true;
            }
        }

        return false;
    }
};