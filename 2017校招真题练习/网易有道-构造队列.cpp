//C++
/*
小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：
while(!Q.empty())              //队列不空，执行循环

{

    int x=Q.front();            //取出当前队头的值x

    Q.pop();                 //弹出当前队头

    Q.push(x);               //把x放入队尾

    x = Q.front();              //取出这时候队头的值

    printf("%d\n",x);          //输出x

    Q.pop();                 //弹出这时候的队头

}

做取出队头的值操作的时候，并不弹出当前队头。
小明同学发现，这段程序恰好按顺序输出了1,2,3,...,n。现在小明想让你构造出原始的队列，你能做到吗？[注：原题样例第三行5有错，应该为3，以下已修正]

思路：上述程序就是把第1个数放到后面，然后把第2个数输出出来并退队，如此循环直到结束。
当队列中所有数都输出了时，结果是1到n的序列。那么可以分析一下原始序列的构成。
对于输入的数n，首先原始序列我假设是a1,a2,a3,……,an。
以n=10为例。
那么对所有数一轮操作后，留在队列里的是a1,a3,a5,……，an(n奇)或a(n-1)（n偶），输出的是a2,a4,……,a(n-1)（n奇）或an（n偶）
那么第一轮，最小那几个数就在它们的2倍的下标-1位置，如1在x[1],2在x[3],3在x[5]，每次跳过1个空格在下一个空格依次填上数字。
[ _ 1 _ 2 _ 3 _ 4 _ 5 ]
第2轮，剩下一半的空位，继续规律，跳过一个空格在下一个填上数字，如果到头了就返回第1个。于是有
[ _ (1) 6 (2) _ (3) 7 (4) _ (5) ]
第3轮，第9个空格被跳过，于是从第1个开始填
[ 8 (1) (6) (2) _ (3) (7) (4) 9 (5) ]
第4轮
[ (8) (1) (6) (2) 10 (3) (7) (4) (9) (5) ]
完毕。
*/

#include<cstdio>
void trans(int x, int *s){
    for(int i=0;i<x;i++)s[i]=100001;
    int pointer=0;
    int ins = 0;
    int used= 0;
    while(used<x){
		if(s[pointer]==100001){
			if(ins==1){
				s[pointer]=used+1;
				used++;
				ins=0;
			}
			else{
				ins=1;
			}
		}
        pointer=(pointer+1)%x;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int *s=new int[n];
        trans(n,s);
        bool first=true;
        for(int j=0;j<n;j++){
            if(first==false)printf(" ");
            else first=false;
            printf("%d",s[j]);
        }
        printf("\n");
    }
    return 0;
}
