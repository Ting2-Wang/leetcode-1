struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//ListNode* start = l1->val < l2->val ? l1 : l2;
		//ListNode* temp = start;
		// 注意这里新开辟一个节点，上述方式会混乱！！
		ListNode dummy(-100);
		ListNode *temp = &dummy;
		while (l1&&l2) {
			if (l1->val < l2->val) {
				temp->next = l1;
				l1 = l1->next;
			}
			else {
				temp->next = l2;
				l2 = l2->next;
			}
			temp = temp->next;

		}
		temp->next = l1 > l2 ? l1 : l2;
		return dummy.next;
	}
};

int main21() {
	Solution s;
	ListNode m1 = ListNode(1);
	ListNode m2 = ListNode(3);
	ListNode m3 = ListNode(5);
	ListNode n1 = ListNode(2);
	ListNode n2 = ListNode(4);
	m1.next = &m2;
	m2.next = &m3;
	n1.next = &n2;
	s.mergeTwoLists(&m1, &n1);
	return 0;
}