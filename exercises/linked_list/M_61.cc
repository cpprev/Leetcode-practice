/// <summary>
/// O(N) linked list rotation
/// https://leetcode.com/problems/rotate-list/
/// </summary>
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tracer = head;
        int size = 0;
        while (tracer) {
            ++size;
            tracer = tracer->next;
        }
        if (size > 0)
            k = k % size;

        while (k > 0) {
            tracer = head;
            int previous = INT_MIN;
            while (tracer) {
                int temp = tracer->val;
                if (previous != INT_MIN)
                    tracer->val = previous;
                previous = temp;
                if (not tracer->next) {
                    head->val = previous;
                }
                tracer = tracer->next;
            }
            --k;
        }
        return head;
    }
};