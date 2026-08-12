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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        // 后面至少有两个节点才需要交换
        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* first = cur->next;
            ListNode* second = cur->next->next;
            // 三步交换
            first->next = second->next;
            second->next = first;
            cur->next = second;
            // cur移动到下一组的前一个节点
            cur = first;
        }
        return dummy->next;
    }
};
