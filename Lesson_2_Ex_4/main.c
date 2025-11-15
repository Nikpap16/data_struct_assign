

#include <stdio.h>
#include <stdlib.h>



  int myArr[2];
  int N=2;
    
        int ArrCalc( int myArr[], int N) {
            
            int sum = 0;
            
            for(int i = 0; i<N; i++){
                sum +=myArr[i];    
            }
            return sum;
            
            
            
            }
            
         int ArrCalcRec(int arr[], int N) {
             
            if (N == 0)          
                 return 0;
             else
                 return arr[N-1] + ArrCalcRec(arr, N-1);  
}




int main(){

    int N;
    
    printf("Enter the number of elements :");
    scanf("%d", &N);
    
    int* myArr = (int*) malloc(N*sizeof(int));
        if(myArr==NULL){
            printf("Memory allocation failed!");
            return 1;
        }
        
        for (int i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &myArr[i]);
    }
    
    int sumFor= ArrCalc(myArr, N);
    int sumRec= ArrCalcRec(myArr, N);
    
    printf("Sum using for = %d\n", sumFor );
    printf("Sum using rec = %d", sumRec );
        
    free(myArr);
        
   
    
    
    
    
   return 0;
}
