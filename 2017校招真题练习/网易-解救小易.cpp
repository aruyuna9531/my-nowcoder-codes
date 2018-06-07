//C++,5ms,484kB
/*
有一片1000*1000的草地，小易初始站在(1,1)(最左上角的位置)。小易在每一秒会横向或者纵向移动到相邻的草地上吃草(小易不会走出边界)。大反派超超想去捕捉可爱的小易，他手里有n个陷阱。第i个陷阱被安置在横坐标为xi ，纵坐标为yi 的位置上，小易一旦走入一个陷阱，将会被超超捕捉。你为了去解救小易，需要知道小易最少多少秒可能会走入一个陷阱，从而提前解救小易。

思路：从(1,1)到(x,y)的最小步数就是不走回头路的横x-1步纵y-1步，共x+y-2步。要求的就是给定的(xi,yi)中xi+yi-2的最小值。
*/
#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int *x=new int[n];
    int *y=new int[n];
    for(int i=0;i<n;i++)scanf("%d",&x[i]);
    for(int i=0;i<n;i++)scanf("%d",&y[i]);
    int min=x[0]+y[0]-2;
    for(int i=1;i<n;i++){
        if(x[i]+y[i]-2<min)min=x[i]+y[i]-2;
    }
    printf("%d\n",min);
    delete []x;
    delete []y;
    return 0;
}