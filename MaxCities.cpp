#include <iostream>
using namespace std;
int const tankCapcity=4;
int getStartMax(int r[],int c[],int s,int st)
{
    int tank=0;
    int cities=0;
    int start=st;
    int returned=0;
    int i=start;
    while(true)
    {   if(i==start)
          returned++;
        if(returned==2)
        {   cities--;
            break;
        }
        tank+=r[i];
        if(tank>tankCapcity) tank=tankCapcity;
        if(c[i]<=tank)
          {

            cities++;
            tank-=c[i];
          }
        else break;
        if(i==s-1) i=-1;
        i++;
    }
    return cities;
}

int getAllMax(int r[],int c[],int s)
{
    int maxVal=-1;
    for(int i=0;i<s;i++)
    {
        int tmp=getStartMax(r,c,s,i);
        if(maxVal<tmp) maxVal=tmp;
    }
    return maxVal;
}
int main()
{
    int refill[]={8,3,1,0};
    int consum[]={1,4,3,3};
    int s=sizeof(refill)/sizeof(refill[0]);
    cout<<getAllMax(refill,consum,s);


}

