// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return head;
        
        // First, check if there are atleast k nodes in the linked list. If not, return the current head
        ListNode* temp = head;
        int c = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            c++;
            if(c == k)
                break;
        }
        if(c < k)
            return head;
        
        ListNode *prev, *cur, *nex;
        prev = head;
        cur = head->next;
        if(cur != NULL)
            nex = cur->next;
        
        for(int i=1; i<k; i++)
        {
            cur->next = prev;
            prev = cur;
            cur = nex;
            if(nex != NULL)
                nex = nex->next;
        }
        
        head->next = reverseKGroup(cur, k);
        
        return prev;
        
    }
};