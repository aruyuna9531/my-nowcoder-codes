//Java
//��һ���ǵݼ������ǰ����Ԫ�����ں��棬�����������СԪ�ء�

//˼·���Ӻ���ǰ�Ƚϣ��鵽�б�ǰ��Ԫ��С�ķ���

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