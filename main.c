#include "header.h"

void print_menu() 
{
    printf("YOOOO welcome to Yahtzee twiinnnn\n");
  
    printf("1. Let's start new Game\n");
    
    printf("2. Tryna see rules\n");
    
    printf("3. Exit\n");
}

void print_rules()
{
    printf("The Rules of Yahtzee: "
        "The scorecard used for Yahtzee is composed of two sections.A upper section and a"
        "lower section.A total of thirteen boxes or thirteen scoring combinations are divided"
        "amongst the sections.The upper section consists of boxes that are scored by summing"
        "the value of the dice matching the faces of the box.If a player rolls four 3's, then the"
        "score placed in the 3's box is the sum of the dice which is 12. Once a player has"
        "chosen to score a box, it may not be changed and the combination is no longer in play"
        "for future rounds.If the sum of the scores in the upper section is greater than or"
        "equal to 63, then 35 more points are added to the players overall score as a bonus.");
}

int user_choice()
{
    char input[5];

    printf("What's the choice twin: ");

    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        int choice;

        if (sscanf(input, "%d", &choice) == 1)
        {
            return choice;
        }
    }
    return -1;
} 

void roll_dice(int dice[]) 
{
    for (int i = 0; i < 5; i++) 
    {
        dice[i] = (rand() % 6) + 1;
    
        printf("Dice %d: %d\n", i + 1, dice[i]);
    }
}

void reroll_dice(int dice[]) 
{
    char choice;
    for (int i = 0; i < 2; i++) 
    {
        printf("U wanna reroll a dice? (y/n): ");
      
        scanf(" %c", &choice);
        
        clear_input_buffer();
        
        if (choice == 'n') break;

        int index;
        
        printf("Enter ur dice number (1-5) to reroll: ");
        
        scanf("%d", &index);
        
        clear_input_buffer();

        if (index >= 1 && index <= 5) 
        {
            dice[index - 1] = (rand() % 6) + 1;
        
            printf("Dice %d: %d\n", index, dice[index - 1]);
        }
    }
}
int select_combination() 
{
    int combo;
 
    printf("Choose a combination (1-13): ");
    
    scanf("%d", &combo);
    
    clear_input_buffer();
    
    return combo;
}
int calculate_score(int combo, int dice[]) 
{
    int score = 0;

    switch (combo) 
    {
    case 1:
    
    case 2:
    
    case 3:
    
    case 4:
    
    case 5:
    
    case 6:
    
        for (int i = 0; i < 5; i++)
        
            if (dice[i] == combo) score += combo;
        
        break;
    
    case 7:
    
        score = 0;
        
        for (int i = 0; i < 5; i++) 
        {
            if (dice[i] == 3) score += 3;
        
            if (dice[i] == 4) score += 4;
            
            if (dice[i] == 5) score += 5;
        }
        break;
    
    case 8:
        score = 0;
    
        for (int i = 0; i < 5; i++) 
        {
            if (dice[i] == 2) score += 2;
        
            if (dice[i] == 3) score += 3;
            
            if (dice[i] == 4) score += 4;
            
            if (dice[i] == 5) score += 5;
            
            if (dice[i] == 6) score += 6;
        }
        break;
  
    case 9: score = 25; break;
    
    case 10: score = 30; break;
    
    case 11: score = 40; break;
    
    case 12: score = 50; break;
    
    case 13:
    
        for (int i = 0; i < 5; i++) score += dice[i];
        
        break;
    default: score = 0; break;
    }
    return score;
}

int yahtzee_game(int player) 
{
    int dice[5], total_score = 0;
   
    printf("Player %d's Turn\n", player);

    roll_dice(dice);
    
    reroll_dice(dice);

    int combo = select_combination();
    
    total_score += calculate_score(combo, dice);

    printf("Player %d's Score: %d\n", player, total_score);
    
    return total_score;
}

void clear_screen() 
{

#ifdef _WIN32

    system("cls");

#else

    system("clear");

#endif
}
void clear_input_buffer() 
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}
