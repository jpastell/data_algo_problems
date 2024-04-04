/*
 *  https://leetcode.com/problems/rotate-list/
 *  
 *  Close the loop, determine the number of iterations where the loop is ciclical
 *  int iterations = (k % list_length)
 *  
 *  Asumme is a cricular buffer then tail +1 == head
 *  Find the off set of the tail jumps
 * 
 *  
 */

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //empty list
        if(head != nullptr)
        {
            //we need to find the tail to close the loop
            ListNode* tail = head;
            int list_length = 1;
            while(tail->next != nullptr)
            {
                tail = tail->next;
                list_length ++;
            }
            //Close the loop
            tail->next = head;
            //Afte rthis everything is a loop
            //Case that covers only one element in the list
            int iterations = (k % list_length);
            //Lets find the head
            for(int i = 1; i <= list_length-iterations; i++)
            {
                tail = tail->next;
            }
            //Move the head to tail + 1
            head = tail->next;
            tail->next = nullptr;

        }
        return head;
    }
};