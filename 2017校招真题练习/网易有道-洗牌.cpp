//C++,9ms,612kB
/*
洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。

洗牌思路：把排平均分2堆，1~n张和n+1~2n张，看成2个队列，每次轮流从队头弹出元素进入洗牌后序列，弹完即可。
*/

#include<cstdio>
#include<iostream>
using namespace std;
void shuffleOnce(int *s, int n){
    //洗一次牌
    int *tmp,count;
    tmp = new int[2*n];
    for(int i=0;i<n;i++){
        tmp[2*i]=s[i];
        tmp[2*i+1]=s[n+i];
    }
    for(int i=0;i<2*n;i++)s[i]=tmp[i];
    delete []tmp;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,k;
        scanf("%d%d",&n,&k);
        int *s = new int[2*n];
        for(int j=0;j<2*n;j++)scanf("%d",&s[j]);
        for(int j=0;j<k;j++)shuffleOnce(s,n);
        bool first=true;
        for(int j=0;j<2*n;j++){
            if(first==false)printf(" ");
            else first=false;
            printf("%d",s[j]);
        }
        printf("\n");
    }
    return 0;
}
