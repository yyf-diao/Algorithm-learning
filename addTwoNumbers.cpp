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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); //虚拟头节点
        ListNode* cur = dummy;
        int carry = 0; //进位

        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            int sum = v1 + v2 + carry;
            carry = sum / 10;       //计算进位
            int digit = sum % 10;   //当前位数字

            cur->next = new ListNode(digit);
            cur = cur->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return dummy->next;
    }
};
