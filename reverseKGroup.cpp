class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        // 先找k个，不够直接返回
        for(int i=0; i<k; i++){
            if(!p) return head;
            p = p->next;
        }
        // 翻转前k个节点
        ListNode* prev = nullptr;
        ListNode* cur = head;
        for(int i=0; i<k; i++){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        // 递归处理后面的段，接到原head尾部
        head->next = reverseKGroup(cur, k);
        return prev;
    }
};

