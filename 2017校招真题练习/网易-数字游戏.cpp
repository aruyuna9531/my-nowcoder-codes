//C++
/*
小易邀请你玩一个数字游戏，小易给你一系列的整数。你们俩使用这些整数玩游戏。每次小易会任意说一个数字出来，然后你需要从这一系列数字中选取一部分出来让它们的和等于小易所说的数字。 例如： 如果{2,1,2,7}是你有的一系列数，小易说的数字是11.你可以得到方案2+2+7 = 11.如果顽皮的小易想坑你，他说的数字是6，那么你没有办法拼凑出和为6 现在小易给你n个数，让你找出无法从n个数中选取部分求和的数字中的最小数。

思路：先让系列整数升序排列，从头开始算，统计累积和为前n个数（n>=0）的和。
如果累积和比后面元素小了2以上，那么这个累积和+1就是第一个无法求得的数，输出即可。
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[20],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    //排序。10万个数可以使用快速排序，代码暂略
    sort(a,a+n);
    int tot=0;
    for(int i=0;i<n;i++){
        if(a[i]-tot>1){
            printf("%d\n",tot+1);
            return 0;
        }
        else tot=tot+a[i];
    }
    printf("%d\n",tot+1);
    return 0;
}