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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }

    // 在区间 [l, r] 范围内合并链表
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if(l > r) return nullptr;
        if(l == r) return lists[l];
        int mid = (l + r) / 2;
        ListNode* left = merge(lists, l, mid);
        ListNode* right = merge(lists, mid+1, r);
        return mergeTwo(left, right);
    }

    //合并两个有序链表
    ListNode* mergeTwo(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(a && b){
            if(a->val < b->val){
                cur->next = a;
                a = a->next;
            }else{
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        cur->next = a ? a : b;
        return dummy->next;
    }
};

