//Java
//���push��pop����������о�Ϊint
/*
˼·��
��pushֱ����1��ջ��push
��5���� ��
��4���� ��
��3���� ��
��2���� ��
��1���� ��
��-����-��
��popʱ1��ջ��ջ��Ԫ��ӦΪ���е�ͷ�������Ȱ�1��ջ���Ԫ����һ������ѹ��2��ջ
�� ����1��
�� ����2��
�� ����3��
�� ����4��
�� ����5��
��-����-��
�ٰ�2��ջջ��������Ϊ�����2��ջʣ��Ԫ�ذ�˳��ѹ��1��
�� ���� ��
��5���� ��
��4���� ��
��3���� ��
��2���� ��
��-����-��  pop() return 1

*/

import java.util.Stack;

public class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    
    public void push(int node) {
        stack1.push(node);
    }
    
    public int pop() {
        while(stack1.isEmpty()==false){stack2.push(stack1.pop());}
        int res = stack2.pop();
        while(stack2.isEmpty()==false){stack1.push(stack2.pop());}
        return res;
    }
}