//Java
//完成push和pop，假设队列中均为int
/*
思路：
①push直接往1号栈里push
│5││ │
│4││ │
│3││ │
│2││ │
│1││ │
└-┘└-┘
②pop时1号栈的栈底元素应为队列的头，所以先把1号栈里的元素逐一弹出来压入2号栈
│ ││1│
│ ││2│
│ ││3│
│ ││4│
│ ││5│
└-┘└-┘
再把2号栈栈顶弹出即为结果。2号栈剩余元素按顺序压回1号
│ ││ │
│5││ │
│4││ │
│3││ │
│2││ │
└-┘└-┘  pop() return 1

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