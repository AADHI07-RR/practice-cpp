class Node{
    int val;int minv;
}
class MinStack {
    Stack<Node> st;


    public MinStack() {
        st=new Stack<>();
    }
    
    public void push(int value) {
        Node n=new Node();
        n.val=value;int mini=value;
        if(!st.isEmpty()){
            mini=Math.min(mini,st.peek().minv);
        }    
        n.minv=mini;
        st.push(n);
    }
    
    public void pop() {
        st.pop();
    }
    
    public int top() {
        return st.peek().val;
    }
    
    public int getMin() {
        return st.peek().minv;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */