//Java
//��Ŀ��������ά������ÿ�����ҵ�����ÿ���ϵ��µ���
//����ɺ���ʹ���ж�����array���Ƿ���target

//˼·�������½����������ȷ���true�������target��������ߣ���Сֵ��������������
public class Solution {
    public boolean Find(int target, int [][] array) {
        int row=array.length-1;
        int column=0;
        while(row>=0 && column<array[0].length){
            if(array[row][column]==target)return true;
            else if(array[row][column]>target)row--;
            else column++;
        }
        return false;
    }
}