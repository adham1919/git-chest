package Problems.Problem4;

import java.util.Scanner;

public class IlyaProjectProblem {
    int[] win(){ int[] scores = new int[2]; scores[0] = 1; scores[1] = 0; return scores;}
    int[] draw(){int[] scores = new int[2]; scores[0] = 0; scores[1] = 0; return scores;}
    int[] lose(){int[] scores = new int[2]; scores[0] = 0; scores[1] = 1; return scores;}
    int[] compareGames(int a, int b){
        int[] scores = null;
        switch (a){
            case 1:
                if (b == 1){
                   scores = draw(); 
                }else if (b == 2){
                    scores = lose();
                }
                else {
                    scores = win();
                }
            break;
            case 2:
                if (b == 1){
                    scores = win();
                }else if (b == 2){
                    scores = draw();
                }else{
                    scores = lose();
                }
            break;
            case 3:
                if (b == 1){
                    scores = lose();
                }else if (b == 2){
                    scores = win();
                }else {
                    scores = draw();
                }
            break;
        }
        return scores;
    }
    void calculateScore(int k, int a[], int b[]){
        int aliceScore = 0;
        int bobScore = 0;
       for (int i=0; i < k; i++){
               int[] tempScores = compareGames(a[i], b[i]);
               aliceScore+= tempScores[0];
               bobScore+= tempScores[1];
       }
       System.out.println(aliceScore + " " + bobScore);
    }
    
    
    
    public static void main(String[] args){
        //- k = number of games;
        //- a = Alice's first game;
        //- b = Bob's first game;
        int k, a, b;
        Scanner scan = new Scanner(System.in);
        k = scan.nextInt();
        a = scan.nextInt();
        b = scan.nextInt();
        int alice[] = new int[k];
        int bob[] = new int[k];
        alice[0] = a;
        bob[0] = b;
        for (int i = 1; i < k; i++){
                int play = scan.nextInt();
                alice[i] = play;
        }
        for (int i=1; i < k; i++){
                int play = scan.nextInt();
                bob[i] = play;
            
        }
        IlyaProjectProblem ilp = new IlyaProjectProblem();
        ilp.calculateScore(k, alice, bob);
    }
}
