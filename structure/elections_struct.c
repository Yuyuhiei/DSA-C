#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define NUM_CANDIDATES 4
#define NUM_PRECINCTS 5

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    
}

typedef struct {
    char name[20];
    int votes_per_precinct[NUM_PRECINCTS];
    int total_votes;
    float percent_votes;
} candidateRecord;

int main (){
    candidateRecord candidates[NUM_CANDIDATES];
    int total_votes_all_candidates = 0;
    int first_place_index = -1;
    int second_place_index = -1;
    float first_place_percent_votes = -1;
    float second_place_percent_votes = -1;

    // Input names and vote records of each candidate
    for (int j = 0; j < NUM_CANDIDATES; j++){
        gotoxy(30, 5);
        printf("Enter candidate %d's name: ", j + 1);
        scanf("%s", candidates[j].name);
        for (int p = 0; p < NUM_PRECINCTS; p++) {
            gotoxy(30, 7 + p);
            printf("Enter votes for precinct %d: ", p + 1);
            scanf("%d", &candidates[j].votes_per_precinct[p]);
        }
        system("cls");
    }

    system("cls"); // Clear the screen

    gotoxy(40,1);
    printf("TALLY OF VOTE PER PRECINCT");
    
    gotoxy(10, 5);
    printf("Precints");
    for(int i = 1; i < 6; i++){
        gotoxy(13,6+i+i);
        printf("%d",i);
    }
    
    for (int i = 30, j = 0; i < 110 && j < NUM_CANDIDATES; i = i + 20, j++){
        gotoxy(i,5);
        printf("Candidate");
    }
    
    // Display the table with candidates' names and vote records
    for (int i = 31, j = 0; i < 110 && j < NUM_CANDIDATES; i = i + 20, j++){
        gotoxy(i,6);
        printf("%s", candidates[j].name);
        
        // Display votes for each precinct
        for (int p = 0; p < NUM_PRECINCTS; p++) {
            gotoxy(i, 8 + 2 * p);
            printf("%d", candidates[j].votes_per_precinct[p]);
        }
    }

    for (int j = 0; j < NUM_CANDIDATES; j++) {
        candidates[j].total_votes = 0;
        candidates[j].percent_votes = 0;
    }

    for (int j = 0; j < NUM_CANDIDATES; j++) {
        for (int p = 0; p < NUM_PRECINCTS; p++) {
            candidates[j].total_votes += candidates[j].votes_per_precinct[p];
        }
        total_votes_all_candidates += candidates[j].total_votes;
    }

    for (int j = 0; j < NUM_CANDIDATES; j++) {
        candidates[j].percent_votes = (float) candidates[j].total_votes / total_votes_all_candidates * 100;
    }

    gotoxy(10, 7 + 2 * NUM_PRECINCTS);
    for (int i = 0; i < (20 * NUM_CANDIDATES + 10); i++) {
        printf("-");
    }

    gotoxy(10, 8 + 2 * NUM_PRECINCTS);
    printf("Total Votes");

    gotoxy(10, 10 + 2 * NUM_PRECINCTS);
    printf("Percent Votes");

    for (int i = 31, j = 0; i < 110 && j < NUM_CANDIDATES; i = i + 20, j++){
        gotoxy(i, 8 + 2 * NUM_PRECINCTS);
        printf("%d", candidates[j].total_votes);

        gotoxy(i, 10 + 2 * NUM_PRECINCTS);
        printf("%.2f%%", candidates[j].percent_votes);
    }

    for (int j = 0; j < NUM_CANDIDATES; j++) {
        if (candidates[j].percent_votes > first_place_percent_votes) {
            second_place_index = first_place_index;
            second_place_percent_votes = first_place_percent_votes;

            first_place_index = j;
            first_place_percent_votes = candidates[j].percent_votes;
        } else if (candidates[j].percent_votes > second_place_percent_votes) {
            second_place_index = j;
            second_place_percent_votes = candidates[j].percent_votes;
        }
    }

    gotoxy(10, 12 + 2 * NUM_PRECINCTS);

    if (first_place_percent_votes > 50) {
        printf("Winner: %s with %.2f%% of the total votes", candidates[first_place_index].name, first_place_percent_votes);
    } else {
        printf("Run-off between %s and %s", candidates[first_place_index].name, candidates[second_place_index].name);
    }

    getch();
    return 0;
}
