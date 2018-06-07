//Java
//题目描述：二维数组中每行左到右递增，每列上到下递增
//请完成函数使得判断数组array中是否含有target

//思路：从左下角找起，如果相等返回true，如果比target大就往上走（较小值），否则往右走
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