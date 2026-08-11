/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 保证fast和fast->next不为空，避免空指针访问
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            // 相遇说明有环
            if(slow == fast){
                return true;
            }
        }
        // 跳出循环代表走到链表末尾，无环
        return false;
    }
};
