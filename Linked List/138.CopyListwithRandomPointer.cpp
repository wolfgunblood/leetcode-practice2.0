/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*,Node*> nodes;
        
        Node* curr = head;

        while(curr){
            nodes[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr){
            Node* newNode = nodes[curr];
            newNode->next = nodes[curr->next];
            newNode->random = nodes[curr->random];

            curr = curr->next;
        }

        return nodes[head];
    }
};