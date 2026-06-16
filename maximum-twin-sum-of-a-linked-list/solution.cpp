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
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        ListNode* newhead=slow;
        ListNode* curr=newhead;
        ListNode* past=nullptr;
        while(curr!=nullptr){
            ListNode* future=curr->next;
            curr->next=past;
            past=curr;
            curr=future;
        }
        newhead = past;
        int maxsum=0;
        while(head!=nullptr && newhead!=nullptr){
            int currsum=head->val+newhead->val;
            maxsum=max(currsum,maxsum);
            head=head->next;
            newhead=newhead->next;
        }
        return maxsum;


    }
};