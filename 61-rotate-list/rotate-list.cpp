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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;
        ListNode *temp=head;int n=1;
        ListNode *last=temp;
        
        while(temp->next!=nullptr){
            
            
                
            
            temp=temp->next;
            last=temp;
            n++;
            
        }
        if(n==k || k%n==0) return head;
        temp=head;
        k=k%n;
        int ctr=1;
        ListNode *temp2;
        while(temp->next!=nullptr){
            if(n-k==ctr){
                temp2=temp->next;
                temp->next=nullptr;
                last->next=head;
                
                break;
            }
            temp=temp->next;
            ctr++;
        }
        return  temp2;
        

    }
};