# Digital Nomad

DIGITAL NOMAD is an adventure game where players will face a variety of challenges. The game consists of 10 rounds. After successfully completing 9 rounds, players can confront the main villain in the 10th round. In each round, except for the 10th, players must complete one challenge, which may include combat, puzzles, riddles, reaction games, gifts, traps, and more. The challenges differ from game to game. Throughout the game, players can collect various items to assist them in their challenges. The player wins if they defeat the main villain, but if at any time their health drops to 0 or below, they lose.

## Installing the compiler 

1. Download the setup file: https://cygwin.com/install.html (setup-x86_64.exe)
2. Run the file, install with default options
3. Packages to install: gcc-core (7.4.0-1), gdb (8.1.1-1), make (4.2.1-1)
4. Path setup:

   * Select cygwin64 path (C:\cygwin64\bin)

   * This PC -> Properites -> Advanced System Settings -> Enviromental Variables -> System Variables -> Path -> Edit -> New -> Paste cygwin path

5. Check with Command Line the if installation was succesful:

  ![image](https://github.com/user-attachments/assets/bac525c1-27c4-4a7a-84d0-67919be4a059)
  
## Compiling and running the game
1.  Place the C file (DigitalNomad.c) in Cygwin's home directory located at C:\cygwin64\home
2.  Open the Cygwin64 Terminal
3.  Enter the following commands in the terminal:
    * <code style="color : green"> cd /home </code>  (Navigate to the correct directory)
    * <code style="color : green"> ls </code> (Verify that the C file is present in the folder)
    * <code style="color : green"> gcc  DigitalNomad.c -o DigitalNomad </code>  (Compile the C file)
    * <code style="color : green"> ls </code> (Check if the executable file has been created)

![image](https://github.com/user-attachments/assets/05bf8308-3b89-4234-97bb-61c574e90c60)

4. Run the DigitalNomad.exe file

## Code Structure

At the beginning of the game, the player first selects an option from a menu.

![image](https://github.com/user-attachments/assets/c682dfd1-9150-4634-8192-fe308de24b00)

The game handles incorrect input as follows:

```c
displayMenu(0); 
char menuChoice[STRING_LIMIT];

scanf(" ");
gets(menuChoice);
while (menuChoice[1] != '\0' ||
       menuChoice[0] == '\0' ||
       (menuChoice[0] != '1' &&
        menuChoice[0] != '2' &&
        menuChoice[0] != '3' &&
        menuChoice[0] != '4')) {
    for (int i = 0; i < STRING_LIMIT; i++) {
        menuChoice[i] = '\0';
    }
    displayMenu(1);        
    scanf(" ");
    gets(menuChoice);
}
```
The displayMenu function is responsible for displaying the menu. It accepts a single input: if the input is 0, the menu is displayed normally; if the input is 1, the menu is displayed along with an error message indicating that the input was invalid. I used this method throughout the code in all instances where the player had to choose from multiple options. The <code style="color : green"> STRING_LIMIT </code> constant defines the maximum size of the string that the program can read.

The program generates a random number, which is used to determine the type of game event for the current round. There are specific fixed rounds (3, 5, 6, and 9) where predetermined events always occur. If the player's health points (HP) reach 0, the game displays a 'Game Over' message.

The main game loop operates as follows:
```c
while(gameStatus.HP > 0 && gameStatus.rounds < 10)
{
    time_t randomTime;
    
    srand((unsigned)time(&randomTime));
    int theRandNum = rand() % (8 + 1);
    theRandNum++;
    
    // Fixed round for shop
    if(gameStatus.rounds == 5)
    {
        gameStatus = shopRound(gameStatus);
        gameStatus = endOfRound(gameStatus);
        goto endRound;
    }
    // Fixed rounds for battling a golem
    else if(gameStatus.rounds == 3 || gameStatus.rounds == 6 || gameStatus.rounds == 9)
    {
        gameStatus = golemRound(gameStatus);
        gameStatus = endOfRound(gameStatus);
        goto endRound;
    }
    // Randomly selected game events for other rounds
    else
    {
        switch(theRandNum)
        {
            case 1:
                gameStatus = blessingHPRound(gameStatus);
                break;
            case 2:
                gameStatus = blessingSTRRound(gameStatus);
                break;
            case 3:
                gameStatus = blessingINTRound(gameStatus);
                break;
            case 4:
                gameStatus = blessingAGIRound(gameStatus);
                break;
            case 5:
                gameStatus = treeRound(gameStatus);
                break;
            case 6:
                gameStatus = mineRound(gameStatus);
                break;
            case 7:
                gameStatus = gamblingRound(gameStatus);
                break;
            case 8:
                gameStatus = bigSwordRound(gameStatus);
                break;            
        }
        gameStatus = endOfRound(gameStatus);
    }

endRound:
}
    
// Check for game over condition
if(gameStatus.HP <= 0)
{
    displayGameOver();
    getchar();
    goto menu;
}
```
In the game, the case statements within the switch represent different functions, each corresponding to a unique type of game event. These functions define the various gameplay scenarios the player can encounter.

The gameStatus variable is of type struct, defined as follows:
```c
struct status {
    double HP;          // Health Points
    double STR;         // Strength
    double INT;         // Intelligence
    double AGI;         // Agility
    int inventory[10];  // Array representing the player's inventory
    int weapons[10];    // Array representing the player's weapons
    int rounds;         // Number of rounds played
    double maxHP;       // Maximum Health Points
    int charFace;       // Character face identifier
};
```
This struct keeps important information about the player's current status, including health, attributes, items in inventory, and the number of rounds played. It is created at the start of each new game and filled with initial values. As the player goes through the game, this struct is updated to show any changes in the player's stats and inventory.

The display is created using special symbols, as shown below:
```c
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░██████████░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        
        printf("\t\t\t\t\tDormammu defeated you!\n\n");
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
```
## Some gameplay screenshots

![image](https://github.com/user-attachments/assets/74330bcb-7a87-4245-b565-acd8c051b306)

<p align="center">
  Character selection
</p>

![image](https://github.com/user-attachments/assets/5b9c351c-dec9-4804-a183-03a25934ee9b)

<p align="center">
  Storytelling
</p>

![image](https://github.com/user-attachments/assets/f6f1d295-8e1d-465a-83ba-383d0ea1a9bf)

<p align="center">
  Fighting
</p>

![image](https://github.com/user-attachments/assets/39cec205-cedb-488a-ab2f-bf61f065d5b4)

<p align="center">
  Shop round
</p>

![image](https://github.com/user-attachments/assets/9a12709f-e964-4ff2-9ac4-952b998f0f40)

<p align="center">
  Final boss
</p>
