#include "libers_function.h"

int main()
{
    char choice;
    char name_player[15];
    int score_player=0;
    int score_compyuter=0;
    int round_pl;

    print_rule();
   // printf(ANSI_COLOR_YELLOW "the game consists of 5 rounds\n");
    printf(ANSI_COLOR_YELLOW "Enter your name: ");
    scanf(" %s",name_player);

    printf("how many rounds you want to play: ");
    scanf("%d",&round_pl);

    printf("'%s': send 'y' if ready ('n' otherwise):",name_player );
    scanf(" %c",&choice);

    if(choice=='y' || choice=='Y'){

        for(int i=1; i<=round_pl; i++){
           // clrscr();
            clear_screen();
            printf("\tRound %d\n\n", i);

            char winner=' ';
            reset_board();
            while(winner==' ' && check_free_space()!=0)
            {
                print_board();

                player_move();
                winner=check_winner();

                if(winner!=' '|| check_free_space()==0){
                    break;
                }

                computer_move();
                winner=check_winner();

                if(winner!=' '|| check_free_space()==0){
                    break;
                }
            }
            print_board();
            print_winner(winner);

            if (winner == player) {
                score_player ++;
            } else if (winner == compyuter) {
                score_compyuter ++;
            } else {
                score_player += 1;
                score_compyuter += 1;
            }
        }

        printf(ANSI_COLOR_GREEN "Final Scores:\n" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "Player: %d\n" ANSI_COLOR_RESET "\n" , score_player);
        printf(ANSI_COLOR_MAGENTA "Computer: %d\n" ANSI_COLOR_RESET "\n" , score_compyuter);

        score_count(score_player, score_compyuter);

        FILE* fp = fopen("data_player.txt", "a");
        if (fp != NULL) {
            fprintf(fp, "Name: %s, Score: %d\n", name_player, score_player);
            fclose(fp);
        } else {
            printf("Error: Unable to open data_player.txt\n");
        }
    } else if (choice=='n' || choice== 'N') {
        printf("Try it when you're ready ! ;) \n");
    } else {
        printf("your choice was wrong! :( \n");
    }

    return 0;
}
