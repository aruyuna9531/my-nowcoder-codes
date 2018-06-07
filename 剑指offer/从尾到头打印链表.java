//Java
//输入链表，逆向打印节点值

//思路：用堆栈拆链然后弹出

import java.util.*;
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        
        Stack<Integer> st = new Stack<Integer>();
	ArrayList<Integer> s = new ArrayList<Integer>();
        ListNode l = listNode;
        while(l!=null){
        	st.push(l.val);
        	l=l.next;
        }
        while(st.empty()!=true)s.add(st.pop());
        return s;
    }
}