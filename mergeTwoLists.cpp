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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 虚拟头节点
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        // 两个链表都不为空，选小的接在cur后面
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        // 剩下没走完的链表直接接上
        if(list1 != nullptr){
            cur->next = list1;
        }else{
            cur->next = list2;
        }
        // dummy的next才是真正链表头
        return dummy->next;
    }
};
