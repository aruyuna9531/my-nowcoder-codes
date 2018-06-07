/*
小易喜欢的单词具有以下特性：
1.单词每个字母都是大写字母
2.单词没有连续相等的字母
3.单词没有形如“xyxy”(这里的x，y指的都是字母，并且可以相同)这样的子序列，子序列可能不连续。
例如：
小易不喜欢"ABBA"，因为这里有两个连续的'B'
小易不喜欢"THETXH"，因为这里包含子序列"THTH"
小易不喜欢"ABACADA"，因为这里包含子序列"AAAA"
小易喜欢"A","ABA"和"ABCBA"这些单词
给你一个单词，你要回答小易是否会喜欢这个单词。

思路：
（1）存在非大写字母的输出不喜欢，结束
（2）存在连续双字母的输出不喜欢，结束
（3）xyxy子序列，由于x和y可以一致，那么首先
[1]有同一个字母出现过4次的输出不喜欢，结束
[2]没有同一个字母出现过4次，那么建个map保存这个字母，及其出现过的次数、存在的下标列表（下标按小到大排列）
建立好后，有
{1}如果某字母只出现过1次，那么不会构成xyxy子序列
{2}剩下的全部是出现过2~3次的字母，就分析这两个字母会不会构成xyxy子序列（like函数）
分情况讨论：
x出现2次，y出现2次：有下标x1<y1<x2<y2时不喜欢（或x,y对调）
x出现2次，y出现3次：x1<y1<x2<y2;x1<y1<x2<y3;y1<x1<y2<x2时不喜欢
x出现3次，y出现2次：类似上面，x,y对调
x出现3次，y出现3次：x1<y1<x2<y2(y3);x1<y1<x3<y2(y3);x1<y2<x2(x3)<y3;x2<y2<x3<y3
*/

#include<cstdio>
#include<cstring>
bool like(int *alist, int *blist){
    //两个字母分别出现在的位置map，判断是否是xyxy型
    int anum=alist[0],bnum=blist[0];
    if(anum==2 && bnum==2){
        if(alist[1]<blist[1] && blist[1]<alist[2] && alist[2]<blist[2])return false;
        if(blist[1]<alist[1] && alist[1]<blist[2] && blist[2]<alist[2])return false;
    }
    if(anum==2 && bnum==3){
        if(alist[1]<blist[1] && blist[1]<alist[2] && alist[2]<blist[2])return false;
        if(alist[1]<blist[1] && blist[1]<alist[2] && alist[2]<blist[3])return false;
        if(blist[1]<alist[1] && alist[1]<blist[2] && blist[2]<alist[2])return false;
        if(blist[1]<alist[1] && alist[1]<blist[3] && blist[3]<alist[2])return false;
    }
    if(anum==3 && bnum==2){
        if(alist[1]<blist[1] && blist[1]<alist[2] && alist[2]<blist[2])return false;
        if(blist[1]<alist[1] && alist[1]<blist[2] && blist[2]<alist[2])return false;
        if(alist[1]<blist[1] && blist[1]<alist[3] && alist[3]<blist[2])return false;
        if(blist[1]<alist[1] && alist[1]<blist[2] && blist[2]<alist[3])return false;
    }
    if(anum==3 && bnum==3){
        //1,1,2,2
        if(alist[1]<blist[1] && blist[1]<alist[2] && alist[2]<blist[2])return false;
        if(blist[1]<alist[1] && alist[1]<blist[2] && blist[2]<alist[2])return false;
        //1,1,3,3
        if(alist[1]<blist[1] && blist[1]<alist[3] && alist[3]<blist[3])return false;
        if(blist[1]<alist[1] && alist[1]<blist[3] && blist[3]<alist[3])return false;
        //2,2,3,3
        if(alist[2]<blist[2] && blist[2]<alist[3] && alist[3]<blist[3])return false;
        if(blist[2]<alist[2] && alist[2]<blist[3] && blist[3]<alist[3])return false;
        //1,1,2,3
        if(alist[1]<blist[1] && blist[1]<alist[2] && alist[2]<blist[3])return false;
        if(blist[1]<alist[1] && alist[1]<blist[3] && blist[3]<alist[2])return false;
        //1,1,3,2
        if(alist[1]<blist[1] && blist[1]<alist[3] && alist[3]<blist[2])return false;
        if(blist[1]<alist[1] && alist[1]<blist[2] && blist[2]<alist[3])return false;
        //1,2,2,3
        if(alist[1]<blist[2] && blist[2]<alist[2] && alist[2]<blist[3])return false;
        if(blist[1]<alist[2] && alist[2]<blist[2] && blist[2]<alist[3])return false;
        //1,2,3,3
        if(alist[1]<blist[2] && blist[2]<alist[3] && alist[3]<blist[3])return false;
        if(blist[1]<alist[2] && alist[2]<blist[3] && blist[3]<alist[3])return false;
    }
    return true;
}
int main(){
    char s[101];
    scanf("%s",s);
    //排除1,2条件
    for(int i=0;i<strlen(s);i++){
        if(s[i]<'A' || s[i]>'Z'){
            printf("Dislikes\n");
            return 0;
        }
        if(i!=strlen(s)-1 && s[i]==s[i+1]){
            printf("Dislikes\n");
            return 0;
        }
    }
    //3
    char ite[100];
    int G[100][4],usedChar=0;
    for(int i=0;i<100;i++){
        ite[i]=64;
        G[i][0]=0;
        for(int j=1;j<4;j++)G[i][j]=-1;
    }
    for(int i=0;i<strlen(s);i++){
        bool used=false;
        for(int j=0;j<usedChar;j++){
            if(ite[j]==s[i]){
                G[j][0]++;
                //出现4次以上的字母不喜欢
                if(G[j][0]>3){
                    printf("Dislikes\n");
                    return 0;
                }
                G[j][G[j][0]]=i;
                used=true;
                break;
            }
        }
        if(used==false){
            ite[usedChar]=s[i];
            G[usedChar][0]++;
            G[usedChar][1]=i;
            usedChar++;
        }
    }
    for(int i=0;i<usedChar;i++){
        if(G[i][0]==1)continue;    //只出现1次的字母不会构成xyxy
        for(int j=i+1;j<usedChar;j++){
            if(G[j][0]==1)continue;
            if(like(G[i],G[j])==false){
                printf("Dislikes\n");
                return 0;
            }
        }
    }
    printf("Likes\n");
    return 0;
}