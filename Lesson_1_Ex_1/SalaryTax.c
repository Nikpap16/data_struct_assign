#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()


{
 
    float sal;
    float tax;
    
    do{
    
    printf("enter salary");
    scanf("%f", &sal);
    
    if(sal<0){
        printf("invalid answer, please try again\n");
        
    }
    
    }
    while (sal<0);
    
     
     

     if(sal==0){
        printf("tax = 0");
    }
    
    else if (sal<10000){
        tax=0.09*sal;
        printf("tax = %.2f\n" , tax);
    }
    
    else if (sal<20000){
        tax=0.22*sal;
        printf("tax = %.2f\n" , tax);
    }
    
    else if (sal<40000){
        tax= 0.3*sal;
        printf("tax = %.2f\n" , tax);
    }
    
    else {
        tax=0.5*sal;
       printf("tax = %.2f\n" , tax);
    }
    
    
    char answer[4];
    double final;
   
printf("Did you pay the first month? (Answer Yes/No)\n" );

scanf("%s", answer);

if (strcmp(answer, "Yes") == 0){
    final=tax - tax*0.1;
    printf("Final tax amount = %.2f\n" , final);
    
} else {
        printf("Final tax amount = %.2f\n", tax);
    }
    

  return 0;
}