
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("goals.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }
        
        int N;
        fscanf(fp, "%d", &N);
        
        int *goals= malloc(N*sizeof(int));
        
    for (int i = 0; i < N; i++) {
        fscanf(fp, "%d", &goals[i]);
        }
        
    fclose(fp);
    
    float sum = 0;
    for (int i = 0; i < N; i++){
        sum += goals[i];
    }
    
    float avg = sum / N;

    printf("Number of games: %d\n", N);
    printf("Average goals: %.2f\n", avg);

    free(goals);
    
    return 0;
}