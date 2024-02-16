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
    bool isPalindrome(ListNode* head) {

        vector<int> temp;
        ListNode* curr = head;

        while(curr != NULL){

            temp.push_back(curr->val);
            curr = curr->next;
        }

        for(int left=0,right=temp.size()-1;left<=right;left++,right--){

            if(temp[left] != temp[right]) return false;
        }
        
        return true;
    }
};