package Problems.Problem1;

import java.util.Arrays;
import java.util.Collections;

public class DiskSchedulerProblem {
    
    int head = 140;
    
    void calculateMinimalSeekTime(Integer cylinders[]){
        
        Integer[] cylindersTime = new Integer[cylinders.length]; 
        for (int i=0; i < cylinders.length; i++){
            cylindersTime[i] = cylinders[i] - head;
        }
        Arrays.sort(cylindersTime, Collections.reverseOrder());
        int differenceUp = Math.abs(head - cylindersTime[0]);
        int differenceDown = Math.abs(head - cylindersTime[cylindersTime.length - 1]);
        int sleekTime = 0;
        if (differenceUp < differenceDown){
            sleekTime+= cylindersTime[0] + (cylindersTime[0] + head) -  (cylindersTime[cylindersTime.length -1] + head);
        }else if (differenceUp > differenceDown){
            sleekTime+= cylindersTime[cylindersTime.length - 1] + (cylindersTime[cylindersTime.length - 1] + head) - (cylindersTime[0] + head);
        }
        else{sleekTime+= (cylindersTime[0]*2) + cylindersTime[0];}
        System.out.println("Minimal sleek time: " + sleekTime);
    }
    
    public static void main(String[] args){
        Integer[] Cylinders = {100, 50, 190};
        DiskSchedulerProblem dsp = new DiskSchedulerProblem();
        dsp.calculateMinimalSeekTime(Cylinders);
    }
}
