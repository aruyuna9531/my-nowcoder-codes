//C++,5ms,488kB
/*
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。

思路：设置2个标志，初始true，一个记录是否按字典排序，一个记录是否按长度排序
每两个串比较，是字典排序的，字典标记不动，否则置为false。长度同理。
之后两个布尔值组合一下
*/

#include<cstdio>
#include<cstring>
int main(){
    int n;
    scanf("%d",&n);
    if(n==0){
        printf("none\n");
        return 0;
    }
    if(n==1){
        printf("both\n");
        return 0;
    }
    char pre[101],cur[101];
    bool lexi=true;
    bool lent=true;
    scanf("%s",pre);
    n--;
    while(n>0){
        scanf("%s",cur);
        if(strcmp(pre,cur)>0)lexi=false;
        if(strlen(pre)>strlen(cur))lent=false;
        if(lexi==false && lent==false){
            printf("none\n");
            return 0;
        }
        strcpy(pre,cur);
        n--;
    }
    if(lexi==true && lent==true)printf("both\n");
    else if(lexi==true)printf("lexicographically\n");
    else printf("lengths\n");
    return 0;
}