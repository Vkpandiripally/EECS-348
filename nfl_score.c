#include <stdio.h>

void printCombinations(int score) {
    printf("Possible combinations of scoring plays:");
    
    for (int touchdowns = 0; touchdowns <= score / 6; ++touchdowns) {
        for (int fieldGoals = 0; fieldGoals <= (score - touchdowns * 6) / 3; ++fieldGoals) {
            for (int safeties = 0; safeties <= (score - touchdowns * 6 - fieldGoals * 3) / 2; ++safeties) {
                int remainingScore = score - touchdowns * 6 - fieldGoals * 3 - safeties * 2;
                if (remainingScore == 0) {
                    printf("%d TD(s), %d FG(s), %d Safety(s)\n", touchdowns, fieldGoals, safeties);
                } else if (remainingScore == 1) {
                    printf("%d TD(s), %d FG(s), %d Safety(s), 1 Extra Point\n", touchdowns, fieldGoals, safeties);
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);
        
        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }
        
        printCombinations(score);
    }
    
    return 0;
}
