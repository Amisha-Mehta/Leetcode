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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr!=nullptr && curr->next!=nullptr){
            ListNode* future=curr->next;
            if(curr->val==future->val){
                curr->next=future->next;
                delete future;
            }
            else curr=curr->next;
        }
        return head;
    }
};