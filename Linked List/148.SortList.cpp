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
    ListNode* mergeList(ListNode* list1,ListNode* list2){

        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;

        while(list1 != NULL && list2 != NULL){

            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next; 
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if(list1 != NULL){
            curr->next = list1;
            list1 = list1->next;
            // curr = curr->next;
        }
        if(list2 != NULL){
            curr->next = list2;
            list2 = list2->next;
            // curr = curr->next;
        }

        return ptr->next;
    }

    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;

        
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(slow);

        return mergeList(list1,list2);
    }
};