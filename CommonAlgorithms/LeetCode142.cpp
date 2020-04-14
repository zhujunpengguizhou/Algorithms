//解法一：hash table 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* current = head;
        int pos = 0;
        ListNode* ans = nullptr;
        unordered_map<ListNode*, int> m;
        while(current != nullptr){
            if(m.find(current) != m.end()){
                ans = current;
                break;
            }
            m[current] = pos;
            current = current->next;
            pos++;
        }
        if(ans == nullptr){
            return NULL;
        }
        return ans;
    }
};