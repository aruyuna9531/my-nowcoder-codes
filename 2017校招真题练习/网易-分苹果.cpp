//C++，5ms，480kB
/*
题目：n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。

思路：
（1）输入时判：如果有两头牛持有苹果数奇偶性不一致（如一头有3个另一头有4个），则无论如何也无法通过转移2苹果使得它俩相等
（2）总体判：如果所有牛的苹果总数不能被奶牛数整除，则无法平分（肯定有牛多）
（3）单转移判：平分结果应为每牛x个苹果，然而牛现在持有苹果数和x奇偶性不一致，则无法通过转移2苹果使得自身达到x
（4）以上均不成立时，可以平分，移动次数计算
*/
#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int cows[100];
    scanf("%d",&cows[0]);//先输入第一个奶牛
    int oddeven=cows[0]%2;//给出1号奇偶性
    int total=cows[0];
    for(int i=1;i<n;i++){
        scanf("%d",&cows[i]);
        total+=cows[i];
        if(cows[i]%2!=oddeven){
            //有奶牛奇偶性与1号不一样直接可以判不存在
            printf("-1\n");
            return 0;
        }
    }
    //奇偶性都一样，可以溜一圈
    //先求一波平均值，不是整数的判不存在
    if(total%n!=0){
        printf("-1\n");
        return 0;
    }
    //平均值是整数的话，看每个奶牛减去平均值是否偶数，存在奇数的判不存在
    int avg=total/n;
    for(int i=0;i<n;i++){
        if((cows[i]-avg)%2==1){
            printf("-1\n");
            return 0;
        }
    }
    //都过关了就存在，求次数：各奶牛与平均值之差的绝对值之和除以4
    int moves=0;
    for(int i=0;i<n;i++){
        if(cows[i]>=avg)moves+=cows[i]-avg;
        else moves+=avg-cows[i];
    }
    printf("%d\n",moves/4);
    return 0;
}