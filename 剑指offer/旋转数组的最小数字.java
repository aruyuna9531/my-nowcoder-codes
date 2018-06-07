//Java
//把一个非递减数组的前几个元素置于后面，输出该数组最小元素。

//思路：从后往前比较，查到有比前面元素小的返回

import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] array) {
        if(array.length==0)return 0;
        if(array.length==1)return array[0];
        int i=array.length-1;
        while(true){
            if(array[i]<array[i-1])break;
            i--;
        }
        return array[i];
    }
}