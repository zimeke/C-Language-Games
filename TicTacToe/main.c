#include <stdio.h>
#include <stdlib.h>

#define STRING_LIMIT 150

char data[9] = {'1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
int stepsMade[9] = {0};

void display()
{
    system("clear"); 
    printf("\n\tTic Tac Toe\n");
    printf("\nPlayer 1 (X) - Player 2 (O)\n");
    printf("\n\n     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", data[0], data[1], data[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", data[3], data[4], data[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", data[6], data[7], data[8]);
    printf("     |     |     \n");
}

int validStep(int step)
{
    int valid = 1;
    for(int i=0; i<9; i++)
    {
        if(stepsMade[i]==step)
        {
            valid = 0;
        }
    }
    return valid;
}
int playerStep(int player)
{       
    
        int step = 0;
        char stepChar[STRING_LIMIT];
        for(int i=0; i<STRING_LIMIT; i++)
                    {
                        stepChar[i] = '\0';
                    }
                    
        printf("\nPlayer %d enter a valid move: ", player);
        
        scanf(" ");
        gets(stepChar);
        
        while(  stepChar[1] != '\0' ||
                stepChar[0] == '\0' ||
                (stepChar[0] != '1' &&
                 stepChar[0] != '2' &&
                 stepChar[0] != '3' &&
                 stepChar[0] != '4' &&
                 stepChar[0] != '5' &&
                 stepChar[0] != '6' &&
                 stepChar[0] != '7' &&
                 stepChar[0] != '8' &&
                 stepChar[0] != '9'))
                {
                    for(int i=0; i<STRING_LIMIT; i++)
                    {
                        stepChar[i] = '\0';
                    }
                        
                        display();
                        printf("\nInvalid option!");
                        printf(" Player %d enter a valid move: ", player);
                        scanf(" ");
                        gets(stepChar);
                    }
        
        switch(stepChar[0])
        {
            case '1' :
                step = 1;
                break;
            case '2' : step = 2; break;
            case '3' : step = 3; break;
            case '4' : step = 4; break;
            case '5' : step = 5; break;
            case '6' : step = 6; break;
            case '7' : step = 7; break;
            case '8' : step = 8; break;
            case '9' : step = 9; break;
        }
        
        if(validStep(step)==1)
        {
            if(player == 1)
                {
                    data[step-1]='X';
                    stepsMade[step-1]=step;
                    return 1;
                }
            else
                {
                    data[step-1]='O';
                    stepsMade[step-1]=step;
                    return 1;
                }
        }
        return 0;
        
}

int ifWin(int player)
{
    char XO;
    if(player==1)
    {
        XO = 'X';
    }
    else
    {
        XO = 'O';
    }
    
    if( (data[0] == XO && data[1] == XO && data[2] == XO) ||
        (data[3] == XO && data[4] == XO && data[5] == XO) ||
        (data[6] == XO && data[7] == XO && data[8] == XO) ||
        (data[0] == XO && data[4] == XO && data[8] == XO) ||
        (data[0] == XO && data[3] == XO && data[6] == XO) ||
        
        (data[1] == XO && data[4] == XO && data[7] == XO) ||
        (data[2] == XO && data[5] == XO && data[8] == XO) ||
        (data[2] == XO && data[4] == XO && data[6] == XO) )
        {
            return 1;
        }
        return 0;
}

int main()
{
    
    int leftSteps = 9;
    display();
    while(leftSteps != 0)
    {
        display();
        while(playerStep(1) == 0)
        {
            display();
            display();
            
            printf("\nInvalid move!");
        }
        if(ifWin(1) == 1)
        {
            break;
        }
        leftSteps--;
        if(leftSteps == 0)
            continue;
        display();
         while(playerStep(2) == 0)
        {
            display(); 
            display();
           
            printf("\nInvalid move!");
        }
        if(ifWin(2) == 1)
        {
            break;
        }
        leftSteps--;
    }
    display();
    
    if(leftSteps==0 && (ifWin(1) == 0 && ifWin(2) == 0))
    {
        printf("\n\tDRAW");
    }
    else
    {
        
        if(ifWin(1)==1)
        {
            printf("\n\tPLAYER 1 WON");
        }
        else
        {
            printf("\n\tPLAYER 2 WON");
        }

    }
    
    return 0;
}
