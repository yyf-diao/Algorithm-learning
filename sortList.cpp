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
    ListNode* sortList(ListNode* head) {
        // 递归终止：空节点 / 单个节点，本身有序
        if (!head || !head->next) return head;

        // 快慢指针找中点，slow是中点，pre记录slow前一个，用来断开链表
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // 断开前后两段

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }

    // 合并两个有序链表，虚拟头节点模板
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

