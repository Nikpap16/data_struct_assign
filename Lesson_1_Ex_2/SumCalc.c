#include <stdio.h>
#include <math.h>

int main(){
    
    float lamda, x , f;
    int N;
    int i;
    
    
    printf("Enter lamda value");
    scanf("%f", &lamda);
    
   do
   
   {
    printf("Enter N value (between 0 and 10)");
    scanf("%d", &N);
    
    if (N>=10 || N<=0){
        
    printf("Invalid N value \n");
    
    }
    
   }
    
    while (N>=10 || N<=0);
    
      
    printf("Enter x value: ");
    scanf("%f", &x);

    
    float sum = 0;
    for (i = 0; i <= N; i++) {
        sum += pow(x, i) + (i / (float)N);
    }

    f = lamda * sum;

    printf("The value of f(x) is: %f\n", f);

    system("pause");  // ⬅️ κρατάει το παράθυρο ανοιχτό

    return 0;
    
  
    
}