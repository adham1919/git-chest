#include <iostream>
using namespace std;
struct Robot
{
    int64_t totScore;
    int64_t choice;
};

struct Round{
    int64_t robot1Score;
    int64_t robot2Score;
    int64_t robot1Choice;
    int64_t robot2Choice;
    int64_t roundNumber;

};
void playRound(Robot * a, Robot * b)
{
    if((a->choice==1 && b->choice==3) || (a->choice==2 && b->choice==1) || (a->choice==3 && b->choice==2) )
        a->totScore++;
    else if((b->choice==1 && a->choice==3) || (b->choice==2 && a->choice==1) || (b->choice==3 && a->choice==2))
        b->totScore++;
}

int64_t repeat(Round r[11])
{   int64_t r1=r[10].robot1Choice;
    int64_t r2=r[10].robot2Choice;
    for(int64_t i=9;i>=1;i--)
    {
        if(r[i].robot1Choice==r1 && r[i].robot2Choice==r2)
            return i;

    }
    return -1;
}



int64_t r1inc(Round r[11],int64_t cp)

{      int64_t x;
       x=r[10].robot1Score-r[cp].robot1Score;
      return x;
}


int64_t r2inc(Round r[11],int64_t cp)
{
        int64_t x;
       x=r[10].robot2Score-r[cp].robot2Score;
      return x;
}

void playGame(Robot * a,Robot * b,int ac[3][3], int bc[3][3] ,int64_t k)
{
     Round rounds[11];
     playRound(a,b);
     k--;
     int64_t s;
     if(k<=9) s=k;
     else s=10;
     int64_t i;
    for(i=1;i<=s;i++)
    {
        Round round;
        int64_t ach=a->choice;
        int64_t bch=b->choice;
        a->choice=ac[ach-1][bch-1];
        b->choice=bc[ach-1][bch-1];
        round.robot1Choice=a->choice;
        round.robot2Choice=b->choice;
        playRound(a,b);
        round.roundNumber=i;
        round.robot1Score=a->totScore;
        round.robot2Score=b->totScore;
        rounds[i]=round;
        k--;
        if(i==10) break;

    }

    if(i>=10)
    {

        int64_t inde=repeat(rounds);
       int64_t rep=10-inde;
       int64_t ainc=r1inc(rounds,inde);
       int64_t binc=r2inc(rounds,inde);
       int64_t countLeft=k%rep;
       int64_t countSkipped=k/rep;
       a->totScore+=(ainc*countSkipped);
       b->totScore+=(binc*countSkipped);
       for(int64_t i=0;i<countLeft;i++)
       {

           int64_t ach=a->choice;
           int64_t bch=b->choice;
           a->choice=ac[ach-1][bch-1];
           b->choice=bc[ach-1][bch-1];
           playRound(a,b);
       }
    }
}

int main()
{
    Robot *Alice = new Robot();
    Robot *Bob = new Robot();
    int64_t k;
    int  aChoice [3][3];
    int bChoice [3][3];
    cin>>k>>Alice->choice>>Bob->choice;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        cin>>aChoice[i][j];
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        cin>>bChoice[i][j];
    Alice->totScore=0;
    Bob->totScore=0;
    playGame(Alice,Bob,aChoice,bChoice,k);
    cout<<Alice->totScore<<" "<<Bob->totScore;
    delete Alice;
    delete Bob;
}
