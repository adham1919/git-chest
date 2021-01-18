
package Problems.Problem2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import static jdk.nashorn.internal.objects.NativeArray.sort;

public class CarCityProblem {

    int N; //Number of cities
    int C; //Tank capacity
    Integer A[]; //The fuel amount you can fill from each city
    Integer B[]; //The fuel consumption to travel from city i and city i+1
    CarCityProblem(int N, int C, Integer A[], Integer B[]){
        this.N = N;
        this.C = C;
        this.A = A;
        this.B = B;
    }
    Integer[] calculateFuel(Integer fuelRefill[], Integer fuelConsumption[]){
        Integer differenceFuel[] = new Integer[fuelRefill.length]; 
        for (int i = 0; i < fuelRefill.length; i++){
            differenceFuel[i] = fuelRefill[i] - fuelConsumption[i];
        }
        return differenceFuel;
    }
    void calculateMaxNCities(Integer fuelRefill[], Integer fuelConsumption[]){
        Integer differenceFuel[] = calculateFuel(fuelRefill, fuelConsumption);
        Arrays.sort(differenceFuel, Collections.reverseOrder());
        int maxCities = 0;
        for (int i = 0; i < differenceFuel.length; i++){
                C = C >=0 && C+differenceFuel[i] > 0 ? C + differenceFuel[i] : 0;
                if(C == 0){break;}else{maxCities++;}
        }
        System.out.println("Max cities: " + maxCities);
    }
    public static void main(String[] args){
        Integer A[] = {10,20,5,1,0};
        Integer B[] = {15, 5, 3, 10, 30};
        // TRACE: A[], B[]:
        // -5, 15, 2, -9, -30
        // 15, 2, -5, -9, -30
        // TRACE: calculateMaxNCities[]:
        //- 10 + 15 = 25
        //- 25 + 2 = 27
        //- 27 + -5 = 22
        //- 27 + -9 = 18
        //- 18 + -30 = -12; maxCities = 4;
     CarCityProblem ccb = new CarCityProblem(5, 10, A, B);
     System.out.println("Test case 1: ");
     ccb.calculateMaxNCities(A, B);
     Integer C[] = {1, 5, 0, 2, 3, 4};
     Integer D[] = {10, 2, 5, 9, 8, 6};
     //Trace C[], D[]:
     // -9, 3, -5, -7, -5, -2
     // 3, -2, -5, -7, -9
     //TRACE: calculateMaxNCities[]:
     //- 2 + 3 = 5
     //- 5 + -2 = 3
     //- 3 + -5 = -2
     //- -2 + -7 = -9
     //- -9 + -9 = -18
     CarCityProblem ccb1 = new CarCityProblem(6, 2, C, D);
     System.out.println("Test case 2: ");
     ccb1.calculateMaxNCities(C, D);
     Scanner scan = new Scanner(System.in);
     System.out.println("Enter number of cities: ");
     int numberOfCities = scan.nextInt();
     Integer fill[] = new Integer[numberOfCities];
     Integer consume[] = new Integer[numberOfCities];
     System.out.println("Enter Tank capacity: ");
     int tankCapacity = scan.nextInt();
     System.out.println("Enter fuel amount that you can fill from each city: ");
     for (int i = 0; i < numberOfCities; i++){
         System.out.print("City[" + i + "]: ");
         int fillScanner = scan.nextInt();
         fill[i] = fillScanner;
     }
     System.out.println("Enter fuel consumption for each city: ");
     for (int i = 0; i < numberOfCities; i++){
         System.out.print("City[" + i + "]: ");
         int consumeScanner = scan.nextInt();
         consume[i] = consumeScanner;
     }
     CarCityProblem result = new CarCityProblem(numberOfCities, tankCapacity, fill, consume);
     result.calculateMaxNCities(fill, consume);
    }
}
