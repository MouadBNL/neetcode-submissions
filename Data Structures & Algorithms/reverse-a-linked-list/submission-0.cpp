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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        vector<ListNode*> s;
        ListNode* curr;
        s.push_back(head);
        while(head->next != nullptr) {
            head = head->next;
            s.push_back(head);
        }


        curr = s.back();
        s.pop_back();
        while(!s.empty()) {
            cout << "s.back->val:" << s.back()->val << ", " << "curr->val:" << curr->val << ".\n";
            curr->next = s.back();
            s.pop_back();
            curr= curr->next;
            curr->next = nullptr;
        }

        return head;
    }
};
