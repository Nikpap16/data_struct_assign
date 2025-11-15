
 #include <stdio.h>   
    
    float min( float arr[], int N){
    
    float min = arr[0];
    
    for( int i=0; i<N; i++){
        if (arr[i]<min){
            min= arr[i];
        }
    }
    return min;
 }
 
    float max( float arr[], int N){
      
      float max = arr[0];
      
    for (int i=0; i<N; i++){
        if( arr[i]> max){
            max= arr[i];
        }
    }
    
    return max;
        
    }
    
    void minmax(float arr[], int N){
    
     float   x_min = min(arr, N);
     float   x_max = max(arr, N);
     
     for (int i=0; i<N; i++){
         
         arr[i] = (arr[i]-x_min)/(x_max-x_min);
     }
    
    }
    
int main()
{
   int N;
   
   printf("Enter the number of elements: ");
   scanf("%d", &N);
   
   float arr[N];
   
   for(int i=0; i<N; i++){
       printf("Enter element %d :", i+1);
       scanf("%f", &arr[i]);
   }
   
    printf("The original array is :\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", arr[i]);
        
    }
    printf("\n");
   
   minmax(arr, N);
   
   printf("Normalized array:\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", arr[i]);
    }

   system("pause");


    return 0;
}