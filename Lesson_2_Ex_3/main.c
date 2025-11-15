#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int* rand_init(int N, int low, int high){
    
    int*arr = (int*) malloc(N*sizeof(int));
    
    for (int i=0; i <N; i++){
        arr[i]= low + rand() % (high - low + 1);
    }
    
    return arr;
}

int product ( int n, int u[], int v[]){
    
    int sum = 0;
    
    for (int i =0; i<n; i++){
        sum += u[i]*v[i];
    }
    return sum;
    
}



int main() {
    int N;
    
    printf("Enter the size of the arrays: ");
    scanf("%d", &N);

    
    srand(time(NULL));

   
    int* arr1 = rand_init(N, 1, 10); 
    int* arr2 = rand_init(N, 1, 10);

 
    
    int result = product(N, arr1, arr2);

    printf("arr1 = [");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr1[i]);
        
    }
    printf("]\n");

    printf("arr2 = [");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr2[i]);
        
    }
    printf("]\n");

   
    printf("Dot product: %d\n", result);

  
    free(arr1);
    free(arr2);

    return 0;
}

