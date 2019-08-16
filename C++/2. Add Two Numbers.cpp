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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode pre_head(-1);
        ListNode *ptr = &pre_head;
        
        int carry = 0;
        int sum = 0;
        
        while(l1 or l2 or carry){
            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            if(carry){
                sum += carry;
                carry = 0;
            }
        
            carry = sum / 10;
            sum = sum % 10;
        
        ptr -> next = new ListNode(sum);
        ptr = ptr -> next;
        sum = 0;
        }
        
        ptr -> next = nullptr;
        ptr = pre_head.next;
            
        return ptr;
            
                
    }
};