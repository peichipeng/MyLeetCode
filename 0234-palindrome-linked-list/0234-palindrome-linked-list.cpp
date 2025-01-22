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
    bool isPalindrome(ListNode* head) {
        ListNode* current = head;
        vector<int> values;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }
        int left = 0, right = values.size() - 1;
        while (left <= right) {
            if (values[left] != values[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};