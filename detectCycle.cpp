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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // 第一阶段：快慢指针相遇
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            // 快慢相遇，存在环
            if(slow == fast){
                // fast放到头，两者同速前进
                fast = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // 再次相遇就是环入口
            }
        }
        // 走到末尾，无环
        return nullptr;
    }
};
