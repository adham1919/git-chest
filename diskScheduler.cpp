#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int head = 140;

void  calculateMinimalSeekTime(int cylinders[],int lenght){

        int  * cylindersTime = cylinders;
        for (int i=0; i < lenght; i++){
            cylindersTime[i] = cylinders[i] - head;
        }
        sort(cylindersTime,cylindersTime+lenght);
        int differenceUp = abs( cylindersTime[0]);
        int differenceDown = abs(cylindersTime[lenght - 1]);
        int sleekTime = 0;
        if (differenceUp < differenceDown){
            sleekTime+= cylindersTime[0] + (cylindersTime[0] + head) -  (cylindersTime[lenght -1] + head);
        }else if (differenceUp > differenceDown){
            sleekTime+= cylindersTime[lenght - 1] + (cylindersTime[lenght - 1] + head) - (cylindersTime[0] + head);
        }
        else{sleekTime+= (cylindersTime[0]*2) + cylindersTime[0];}
        sleekTime= abs(sleekTime);
        cout<<"Minimal seek time "<<sleekTime;
    }

    int main(){
        int Cylinders[] = {100,50,190};
        int s=sizeof(Cylinders)/sizeof(Cylinders[0]);
        calculateMinimalSeekTime(Cylinders,s);
    }




/*
int main()
{ int n;
  cin>>n;


}


void deleteArraies(int n,int m,Edge * edges[], Vertex * vertcies[])
{
    for(int i=0;i<n;i++)
        delete vertcies[i];
    for(int i=0;i<n;i++)
        delete edges[i];
}*/
