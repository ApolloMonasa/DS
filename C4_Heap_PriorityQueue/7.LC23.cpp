/*************************************************************************
	> File Name: 7.LC23.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 16 Feb 2025 11:41:40 PM CST
 ************************************************************************/
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
        typedef pair<int, int> PII;
        set<PII> s;
        int n = lists.size();
        for (int i = 0; i < n; i++) {
            if (lists[i] == nullptr) continue;
            s.insert(PII(lists[i]->val, i));
        }
        ListNode new_head, *p = &new_head, *q;
        new_head.next = nullptr;
        while (s.size()) {
            PII a = *s.begin();
            s.erase(s.begin());
            q = lists[a.second];
            lists[a.second] = lists[a.second]->next;
            p->next = q;
            q->next = nullptr;
            p = q;
            if (lists[a.second]) {
                s.insert(PII(lists[a.second]->val, a.second));
            }
        }
        return new_head.next;
    }
};
