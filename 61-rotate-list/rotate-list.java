/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null || head.next==null || k==0 ) return head;
        ListNode first=head;
        ListNode temp=head; 
        ListNode last=head;
        ListNode temp2=head;
        int n=1;
        while(temp.next!=null) {temp=temp.next;last=temp; ; n++;}
        if(n==k || k%n==0) return head;
        temp=head;
        int ctr=1;
        k=k%n;
        while(temp.next!=null){
            if(n-k==ctr){
                temp2=temp.next;
                temp.next=null;
                
                last.next=first;

                break;

            }
            temp=temp.next;
            ctr++;
        }
        
        return temp2;
    }
    
}