class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr){
            return true;
        } else if(head->next->next == nullptr){
            ListNode* future = head->next;
            if(head->val != future->val) return false;
            return true;
        } else {
            ListNode* curr = head;
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = nullptr;     
            while(fast != nullptr && fast->next != nullptr){
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prev->next = nullptr;
            ListNode* newhead = slow;
            ListNode* past = nullptr;
            while(newhead != nullptr){
                ListNode* future = newhead->next;
                newhead->next = past;
                past = newhead;
                newhead = future;
            }
            while(curr != nullptr && past != nullptr){
                if(curr->val != past->val) {
                    return false;
                }
                curr = curr->next;
                past = past->next;
            }
        }
        return true;
    }
};
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if(head->next==nullptr){
//             return true;
//         } else if(head->next->next==nullptr){
//             ListNode* future = head->next;
//             if(head->val != future->val) return false;
//             return true;
//         } else  {
//             ListNode* curr=head;
//             ListNode* slow=head;
//             ListNode* fast=head;
//             ListNode* prev=nullptr;
//             while(fast!=nullptr && fast->next!=nullptr){
//                 prev=slow;
//                 slow=slow->next;
//                 fast=fast->next->next;
//             }
//             prev->next=nullptr;
//             ListNode* newhead=slow;
//             ListNode* past=nullptr;
//             while(newhead!=nullptr){
//                 ListNode* future=newhead->next;
//                 newhead->next=past;
//                 past=newhead;
//                 newhead=future;
//             }
//             while(curr!=nullptr && past!=nullptr){
//                 if(curr->val != newhead->val) {
//                     return false;
//                 }
//                 curr=curr->next;
//                 newhead=newhead->next;
//             }
//         }
//             return true;
//     }
// };