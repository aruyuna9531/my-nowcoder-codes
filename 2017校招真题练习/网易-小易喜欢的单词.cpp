/*
С��ϲ���ĵ��ʾ����������ԣ�
1.����ÿ����ĸ���Ǵ�д��ĸ
2.����û��������ȵ���ĸ
3.����û�����硰xyxy��(�����x��yָ�Ķ�����ĸ�����ҿ�����ͬ)�����������У������п��ܲ�������
���磺
С�ײ�ϲ��"ABBA"����Ϊ����������������'B'
С�ײ�ϲ��"THETXH"����Ϊ�������������"THTH"
С�ײ�ϲ��"ABACADA"����Ϊ�������������"AAAA"
С��ϲ��"A","ABA"��"ABCBA"��Щ����
����һ�����ʣ���Ҫ�ش�С���Ƿ��ϲ��������ʡ�

˼·��
��1�����ڷǴ�д��ĸ�������ϲ��������
��2����������˫��ĸ�������ϲ��������
��3��xyxy�����У�����x��y����һ�£���ô����
[1]��ͬһ����ĸ���ֹ�4�ε������ϲ��������
[2]û��ͬһ����ĸ���ֹ�4�Σ���ô����map���������ĸ��������ֹ��Ĵ��������ڵ��±��б��±갴С�������У�
�����ú���
{1}���ĳ��ĸֻ���ֹ�1�Σ���ô���ṹ��xyxy������
{2}ʣ�µ�ȫ���ǳ��ֹ�2~3�ε���ĸ���ͷ�����������ĸ�᲻�ṹ��xyxy�����У�like������
��������ۣ�
x����2�Σ�y����2�Σ����±�x1<y1<x2<y2ʱ��ϲ������x,y�Ե���
x����2�Σ�y����3�Σ�x1<y1<x2<y2;x1<y1<x2<y3;y1<x1<y2<x2ʱ��ϲ��
x����3�Σ�y����2�Σ��������棬x,y�Ե�
x����3�Σ�y����3�Σ�x1<y1<x2<y2(y3);x1<y1<x3<y2(y3);x1<y2<x2(x3)<y3;x2<y2<x3<y3
*/

#include<cstdio>
#include<cstring>
bool like(int *alist, int *blist){
    //������ĸ�ֱ�����ڵ�λ��map���ж��Ƿ���xyxy��
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
    //�ų�1,2����
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
                //����4�����ϵ���ĸ��ϲ��
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
        if(G[i][0]==1)continue;    //ֻ����1�ε���ĸ���ṹ��xyxy
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