
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
//#include <conio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
//#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


#ifndef _VARIB
#define _VARIB

char board[3][3];
const char player='x';
const char compyuter='o';
#endif

// void clear_screen();
// void print_rule();
// void reset_board();
// void print_board();
// int check_free_space();
// void player_move();
// char check_winner();
// void print_winner(char winner);
// void computer_move();
// void score_count(int score_player, int score_compyuter);

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void print_rule(){
    printf(ANSI_COLOR_RED "\t\t\t------------REMEBER------------" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN "\t\t------------|| MAIN RULES OF GAME ||------------\n\n\n" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN "-------------------------------------------------------------------------------------------------------------------------------------------------------\n" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN "\t\t1) enter your name: payaler_1\n\n" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN "\t\t1.1) enter the number of rounds\n\n" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_GREEN "\t\t2) confirm that you are ready to play. if you are ready y/Y otherwise n/N \n\t\t \tIf you sent a wrong answer or you are not ready, the game will stop and you will have to start over\n\n" ANSI_COLOR_RESET "\n");
   // printf( ANSI_COLOR_GREEN "\t\t3) Your scores will be write.\n\t\t \tif you want to see your scores you should wait will end game or you should sent ||show_score|| command for see your score.\n" ANSI_COLOR_RESET "\n");
   // printf( ANSI_COLOR_GREEN "\t\t3.1) After the game is over, you need to send the ||exit|| command to exit the game, if you want to see your story score, you need to send the ||show_score|| command.\n" ANSI_COLOR_RESET "\n");
    printf( ANSI_COLOR_GREEN "\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n" ANSI_COLOR_RESET "\n");
}
void reset_board(){
    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
           board[i][j]=' ';
       }
    }

}
void print_board(){
    printf(ANSI_COLOR_YELLOW" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
    printf("\n---|---|---\n");

    printf("\n");
}
int check_free_space(){
    int free_sp=9;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]!=' '){
                free_sp--;
            }
        }
    }
    return free_sp;
}
void player_move(){
    int x;
    int y;
    int valid_input = 0;

    do {
        printf(ANSI_COLOR_YELLOW "Enter row #(1-3): " ANSI_COLOR_RESET "\n");
        if (scanf("%d", &x) != 1) {
            printf(ANSI_COLOR_YELLOW "Invalid input! Please enter a number between 1 and 3.\n" ANSI_COLOR_RESET "\n");
            while (getchar() != '\n');
            continue;
        }
        x--;

        printf( ANSI_COLOR_YELLOW "Enter column #(1-3): " ANSI_COLOR_RESET "\n");
        if (scanf("%d", &y) != 1) {
            printf( ANSI_COLOR_YELLOW "Invalid input! Please enter a number between 1 and 3.\n" ANSI_COLOR_RESET "\n");
            while (getchar() != '\n');
            continue;
        }
        y--;

        if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == ' ') {
            valid_input = 1;
        } else {
            printf(ANSI_COLOR_RED "Invalid move! Please choose a valid cell within the range 1-3.\n" ANSI_COLOR_RESET "\n");
        }
    } while (!valid_input);

    board[x][y] = player;
    clear_screen();
}

char check_winner(){
    for(int i=0; i<3; i++){
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2]){
            return board[i][0];
        }
    }
    for(int i=0; i<3; i++){
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i]){
            return board[0][i];
        }
    }
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2]){
            return board[0][0];
    }
    if(board[0][2]==board[1][1] && board[0][2]==board[2][0]){
            return board[0][2];
    }
    return ' ';
}
void print_winner(char winner){
    if(winner==player){
        printf(ANSI_COLOR_BLUE "you winner\n" ANSI_COLOR_RESET "\n");
    }
    else if (winner==compyuter) {
    printf(ANSI_COLOR_RED "you lose\n" ANSI_COLOR_RESET "\n");
    }
    else {
    printf("it's a TIE\n");
    }
}
void computer_move(){

    srand(time(0));
    int x,y;

    if(check_free_space()>0){
        do {
        x=rand()%3;
        y=rand()%3;
        }while (board[x][y]!=' ');
        board[x][y]=compyuter;
        clear_screen();
    }
    else {
        print_winner(' ');
    }
}
void score_count(int score_player, int score_compyuter){
if (score_player > score_compyuter) {
            printf(ANSI_COLOR_GREEN "You won the game!\n" ANSI_COLOR_GREEN "\n");
        } else if (score_player < score_compyuter) {
            printf(ANSI_COLOR_RED "You lost the game.\n" ANSI_COLOR_RESET "\n");
        } else {
            printf("It's a tie!\n");
        }
}