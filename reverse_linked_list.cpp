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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;

        while (curr != nullptr){

            next = curr->next;  // To store the next link

            curr->next = prev;  // To reverse the list by changing the flow direction

            prev = curr;    // Doing this first so we don't lose link to other nodes
            curr = next;    // Traversing through every node to change direction
        }
        return prev;    // Returning the now head of the list
    }
};