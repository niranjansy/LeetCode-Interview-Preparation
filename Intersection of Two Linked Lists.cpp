// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode* temp = headA;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = headB; // Linking the end of list 1 to beginning of list 2
        // If there was an intersection, now there will be a loop in the linked list 
        
        ListNode *ptr1, *ptr2;
        ptr1 = headA->next;
        ptr2 = headA->next->next;
        
        int flag = 0; // To check for existence of loop in linked list
        while(ptr2!=NULL && ptr2->next != NULL)
        {
            if(ptr1 == ptr2)
            {
                flag = 1;
                break;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        
        if(flag == 0)
        {
            temp->next = NULL;
            return NULL;
        }
            
        
        int k = 0; // Length of the loop
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        k = 1;
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            k++;
        }
        
        ptr1 = headA;
        ptr2 = headA;
        for(int j=0; j<k; j++)
            ptr2 = ptr2->next;
        
        while(ptr1!=ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        temp->next = NULL;
        
        return ptr1;       
        
        
        
    }
};