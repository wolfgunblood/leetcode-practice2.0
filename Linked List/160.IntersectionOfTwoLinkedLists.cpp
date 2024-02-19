/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_map<ListNode*,int> hashmap;

        while(headA != NULL){

            hashmap[headA]++;
            headA = headA->next;
        }

        while(headB != NULL){

            if(hashmap[headB] > 0){
                return headB;
            }
            headB = headB->next;
        }
        
        return NULL;
    }
};
//Two Pointer

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

       if(headA == NULL || headB == NULL) return NULL;

       ListNode* ptr1 = headA;
       ListNode* ptr2 = headB;

       while(ptr1 != ptr2){

           if(ptr1 == NULL){
               ptr1 = headB;
           }else {
               ptr1 = ptr1->next;
           }

           if(ptr2 == NULL){
               ptr2 = headA;
           }else{
               ptr2 = ptr2->next;
           }
       }

       return ptr1;
    }
};