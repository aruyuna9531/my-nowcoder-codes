//C++,6ms,608kB
/*
牛牛拿到了一个藏宝图，顺着藏宝图的指示，牛牛发现了一个藏宝盒，藏宝盒上有一个机关，机关每次会显示两个字符串 s 和 t，根据古老的传说，牛牛需要每次都回答 t 是否是 s 的子序列。注意，子序列不要求在原字符串中是连续的，例如串 abc，它的子序列就有 {空串, a, b, c, ab, ac, bc, abc} 8 种。

测试用例长度不超过10，不包括空格。

思路：双指针指向两个字符串第一个元素，串1指针一直往下走，遇到和串2指针对应元素一致时串2也指向下一个，否则串2指针不动。
如果结果串2指针指到了最后一个字符的后面则表示匹配成功，否则失败。
*/

#include<cstdio>
#include<cstring>
int main(){
    char a[11],b[11];
    scanf("%s%s",a,b);
    int count=0;
    for(int i = 0;count<strlen(b) && i<strlen(a);i++){
        if(a[i]==b[count])count++;
    }
    if(count==strlen(b))printf("Yes\n");
    else printf("No\n");
    return 0;
}