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

    ListNode* reverseList(ListNode* head){

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* temp = curr->next;
            // Reverse List
            curr->next = prev;
            //Move the pointer
            prev = curr;
            curr = temp;
        }

        return prev;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode();
        ListNode* temp = result;
        int carry = 0;

        // while(l1 != NULL) {
        // cout<<l1->val<<" ";
        // l1 = l1->next;
        // }
        // cout<<"\n";

        ListNode* list1 = reverseList(l1);
        ListNode* list2 = reverseList(l2);

        
        while(list1 != NULL || list2 != NULL || carry){
            int sum = 0;

            if(list1 != NULL){
                sum += list1->val;
                list1 = list1->next;
            }
            if(list2 != NULL){
                sum += list2->val;
                list2 = list2->next;
            }

            sum += carry;
            carry = sum/10;
            ListNode* newnode = new ListNode(sum%10);
            temp->next = newnode;
            temp = temp->next;
        }

        return reverseList(result->next);
        
    }
};