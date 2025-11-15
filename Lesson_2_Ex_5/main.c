#include <stdio.h>
#include <stdlib.h>

typedef struct{
        char name[50];
        int age;
        int games;
        int goals;
    } Player;
    
    int N;
    
    Player* stats(Player players[], int N){
        
        Player *result = (Player*) malloc(2* sizeof(Player));
        
        Player maxGoals = players[0];
        Player maxAvg = players[1];
        
        for (int i = 0; i<N; i++){
            if(players[i].goals>maxGoals.goals)
                maxGoals= players[i];
            
            
            double avgCurrent = (double)players[i].goals / players[i].games;
            double avgStored = (double)maxAvg.goals / maxAvg.games;

        if (avgCurrent > avgStored)
            maxAvg = players[i];
    
        }
        
        result[0]= maxGoals;
        result[1]= maxAvg;
        
        return result;
        
    }
    
    
    void stats2(Player players[], int N, Player *maxGoals, Player *maxAvg) {
        
    *maxGoals = players[0];
    *maxAvg = players[0];

    for (int i = 1; i < N; i++) {
        if (players[i].goals > maxGoals->goals)
            *maxGoals = players[i];

        double avgCurrent = (double)players[i].goals / players[i].games;
        double avgStored  = (double)maxAvg->goals / maxAvg->games;

        if (avgCurrent > avgStored)
            *maxAvg = players[i];
    }
}
        
    



   
    

int main()
{
    int N;
    printf("Enter number of players: ");
    scanf("%d", &N);

    Player players[N];

    for (int i = 0; i < N; i++) {
        printf("\nPlayer %d name: ", i+1);
        scanf("%s", players[i].name);

        printf("Age: ");
        scanf("%d", &players[i].age);

        printf("Games: ");
        scanf("%d", &players[i].games);
        
        if (players[i].games <= 0) {
        printf("Error: Invalid number of games! Must be at least 1.\n");
        i--;
        continue;
        }
        printf("Goals: ");
        scanf("%d", &players[i].goals);
    }
    
    // 1ος Τρόπος
    Player *best = stats(players, N);
    printf("\n[First Option]");
    printf("\nMost Goals: %s (%d)", best[0].name, best[0].goals);
    printf("\nBest Average: %s (%.2f)\n",
           best[1].name,
           (double)best[1].goals / best[1].games);
    free(best); 

    // 2ος τροπος
    Player bestGoals, bestAvg;
    stats2(players, N, &bestGoals, &bestAvg);
    printf("\n[Second Option]");
    printf("\nMost Goals: %s (%d)", bestGoals.name, bestGoals.goals);
    printf("\nBest Average: %s (%.2f)\n",
           bestAvg.name,
           (double)bestAvg.goals / bestAvg.games);
           
    return 0;
}