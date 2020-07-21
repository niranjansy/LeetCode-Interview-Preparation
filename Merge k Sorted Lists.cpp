// https://leetcode.com/problems/merge-k-sorted-lists/

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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        
        int n = lists.size();
        for(int i=0; i<n; i++)
        {
            if(lists[i] != NULL)
                PQ.push(make_pair(lists[i]->val, i));
        }
        
        ListNode* final_list = NULL, *temp = NULL;
        
        if(!PQ.empty())
        {
            pair<int, int> p = PQ.top();
            PQ.pop();
            int idx = p.second;
            temp = lists[idx];
            final_list = temp;
            temp = temp->next;
            lists[idx] = temp;
            if(temp != NULL)
                PQ.push(make_pair(temp->val, idx));
            final_list->next = NULL;
        }
        
        ListNode* node = final_list;
        while(!PQ.empty())
        {
            pair<int, int> p = PQ.top();
            PQ.pop();
            int idx = p.second;
            temp = lists[idx];
            node->next = temp;
            node = temp;
            temp = temp->next;
            node->next = NULL;
            lists[idx] = temp;
            if(temp != NULL)
                PQ.push(make_pair(temp->val, idx));
        }
        
        return final_list;
        
    }
};