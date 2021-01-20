/// <summary>
/// Time complexity : O(n)
/// Space complexity : O(1)
/// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
/// </summary>
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tracer = head;
        int size = 0, i = 1;
        while (tracer) {
            ++size;
            tracer = tracer->next;
        }

        ListNode* first = nullptr, * last = nullptr;
        tracer = head;
        while (tracer) {
            if (i == k) first = tracer;
            if (i == size - k + 1) last = tracer;

            ++i;
            tracer = tracer->next;
        }

        int sw = first->val;
        first->val = last->val;
        last->val = sw;

        return head;
    }
};