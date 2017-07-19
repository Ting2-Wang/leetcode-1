//
// Created by Fennnnng on 2017/7/14.
//



struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(0) {}
};

#define NULL 0

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head;
        while (cur) {
            if (cur->next && cur->next->val == cur->val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};

int main83() {
    Solution s;
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(1);
    ListNode l3 = ListNode(1);
    ListNode l4 = ListNode(2);
    ListNode l5 = ListNode(2);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    ListNode *r = s.deleteDuplicates(&l1);


    return 0;
}