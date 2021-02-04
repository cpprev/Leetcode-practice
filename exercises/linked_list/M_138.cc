/// <summary>
/// Time complexity : O(n)
/// Space complexity : O(n)
/// https://leetcode.com/problems/copy-list-with-random-pointer/
/// </summary>
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (not head) return nullptr;
        
        unordered_map<Node*, Node*> m;
        
        Node *tracer = head;
        Node *copy = new Node(tracer->val);
        m[tracer] = copy;
        tracer = tracer->next;

        Node *result = copy;
        while (tracer) {
            copy->next = new Node(tracer->val);
            
            m[tracer] = copy->next;
            
            copy = copy->next;
            tracer = tracer->next;
        }
        
        tracer = head;
        copy = result;
        while (tracer) {
            copy->random = m[tracer->random];
            
            copy = copy->next;
            tracer = tracer->next;
        }
        
        return result;
    }
};