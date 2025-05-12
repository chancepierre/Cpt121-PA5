#include "header.h"


int main()
{
	srand(time(NULL));

	int option;

	int round = 1;

	int scoreforplayer1 = 0;
	int scoreforplayer2 = 0;

	while (round <= 13){
		
		print_menu();

		option = user_choice();

		switch (option)
		{
		case 1: clear_screen();

			print_rules();

			break;

		case 2: clear_screen();

			printf("Game starts with Player 1\n");

			printf("press key to roll five dices");

			getchar();

			clear_screen();

			scoreforplayer1 += yahtzee_game(1);

			printf("Okay this the score for player 1 so far: %d\n", scoreforplayer1);

			round++;

			if (round == 14)
			{
				printf("First round is done wait after player 2 is done to get your total..\n");
			}

			break;

		case 3: clear_screen();

			printf("Aight look time for player 2 to go\n");

			clear_screen();

			scoreforplayer2 += yahtzee_game(2);

			printf("Now this is the score for player 2 is: %d\n", scoreforplayer2);

			round++;

			if (round == 14)
			{
				printf("Round 14 is done \n");
			}
			break;

		case 4: clear_screen();

			printf("Apprecite you for playing twin byeee\n");

			printf("Oh yeah and the winner isssss....");

			if (scoreforplayer1 > scoreforplayer2)
			{
				printf("Playerrrr numberrrrr 1 WINSSSS");
			}
			else if (scoreforplayer1 < scoreforplayer2)
			{
				printf("Number 2 got it in the bag youuu won EASY DUBSS");
			}
			else (scoreforplayer1 == scoreforplayer2);
			{
				printf("you bothhh TIEDDD no winner");
			}
			exit(0);

		default: break;

		}
		return 0;

	}
}
