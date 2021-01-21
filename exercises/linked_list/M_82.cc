/// <summary>
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
/// </summary>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int SIZE = 201;
        bool seen[SIZE];
        ListNode* firstOccPrevs[SIZE];
        for (int i = 0; i < SIZE; ++i) seen[i] = false;
        for (int i = 0; i < SIZE; ++i) firstOccPrevs[i] = nullptr;

        ListNode* tracer = head, * prev = nullptr;
        while (tracer) {
            int val = tracer->val + SIZE / 2;
            if (seen[val]) {
                if (firstOccPrevs[val]) {
                    firstOccPrevs[val]->next = tracer->next;
                    prev = firstOccPrevs[val];
                    tracer = firstOccPrevs[val]->next;
                }
                else {
                    head = tracer->next;
                    prev = nullptr;
                    tracer = head;
                }
            }
            else {
                seen[val] = true;
                firstOccPrevs[val] = prev;
                prev = tracer;
                tracer = tracer->next;
            }
        }

        return head;
    }
};