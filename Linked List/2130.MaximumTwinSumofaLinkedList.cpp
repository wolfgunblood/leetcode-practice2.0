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
    int pairSum(ListNode* head) {

        ListNode* slow = head; 
        ListNode* fast = head;

        //Find the Middle of Linked List

        while(fast && fast->next){ 
            slow = slow->next;
            fast = fast->next->next;
        }

        //Reverse a Linked List
        ListNode* curr = slow;
        ListNode* prev =NULL;
        
        while(curr){
            //Store the next address
            ListNode* temp = curr->next;
            //Reverse the next address
            curr->next = prev;

            //Move or Shift the pointers/addresses
            prev = curr;
            curr = temp;
        } 
        ListNode* list1 = head;
        ListNode* list2 = prev;
        int maxP = 0;
        

        while( head && list2){

            maxP = max(list1->val + list2->val,maxP);

            list1 = list1->next;
            list2 = list2->next;
        }
       
        return maxP;
        
    }

};