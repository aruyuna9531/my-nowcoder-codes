//C++,5ms,488kB
/*
������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
2.�����ַ����ĳ����������磺
"car" < "cats" < "koala" < "doggies" < "carriage"
������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��

˼·������2����־����ʼtrue��һ����¼�Ƿ��ֵ�����һ����¼�Ƿ񰴳�������
ÿ�������Ƚϣ����ֵ�����ģ��ֵ��ǲ�����������Ϊfalse������ͬ��
֮����������ֵ���һ��
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