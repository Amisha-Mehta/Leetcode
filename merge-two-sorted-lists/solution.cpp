class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* tmp = list1;
        while (tmp != NULL && tmp->next != NULL) {
            tmp = tmp->next;
        }

        tmp->next = list2;

        for (ListNode* p1 = list1; p1 != NULL; p1 = p1->next) {
            for (ListNode* p2 = p1->next; p2 != NULL; p2 = p2->next) {
                if (p1->val > p2->val) {
                    swap(p1->val, p2->val);
                }
            }
        }
        return list1;
    }
};