//Java
//�������������ӡ�ڵ�ֵ

//˼·���ö�ջ����Ȼ�󵯳�

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