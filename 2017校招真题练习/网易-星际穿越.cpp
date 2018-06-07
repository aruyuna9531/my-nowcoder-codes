//C++,8ms,480kB
/*
航天飞行器是一项复杂而又精密的仪器，飞行器的损耗主要集中在发射和降落的过程，科学家根据实验数据估计，如果在发射过程中，产生了 x 程度的损耗，那么在降落的过程中就会产生 x2 程度的损耗，如果飞船的总损耗超过了它的耐久度，飞行器就会爆炸坠毁。问一艘耐久度为 h 的飞行器，假设在飞行过程中不产生损耗，那么为了保证其可以安全的到达目的地，只考虑整数解，至多发射过程中可以承受多少程度的损耗？

思路：实际上题目就是求满足x^2+x<=h的最大x，一个数学问题。
由于x^2<h<(x+2)^2，可以把范围缩小到根号h~根号h+1这2个数之间，然后分别判一下就行
*/

#include<cstdio>
#include<cmath>
int main(){
    long h;
    scanf("%ld",&h);
    long x = (long)sqrt(h);
    if(x*x+x<=h)printf("%ld\n",x);
    else printf("%ld\n",x-1);
    return 0;
}