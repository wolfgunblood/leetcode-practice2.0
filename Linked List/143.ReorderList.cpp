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
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        //Both Works
        ListNode* fast = head;
        //ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        
        while(second != NULL){
            ListNode* tmp = second->next;
            second->next = prev;
            //Shift both
            prev = second;
            second = tmp;
        }
        ListNode* first = head;
        second = prev;

        while(second != NULL){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        } 
    }
};