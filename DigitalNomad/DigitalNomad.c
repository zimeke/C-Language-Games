#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#define STRING_LIMIT 150
#define MAX_NUMBER 20
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

/*
 * Az inventory tömbben az egyes elemek tárgyakat számát jelentik. 
 * 
 * inventory[0]: DIRT
 * inventory[1]: STONE
 * inventory[2]: FOOD
 * inventory[3]: GOLD
 * inventory[4]: SHIELD
 * 
 * Az weapons tömbben az egyes elemek fegyvereket jelentik.
 * 
 * weapons[0]: STICK
 * weapons[1]: STAFF
 * weapons[2]: CLUB
 * weapons[3]: KNIFE
 * weapons[4]: MACE
 * weapons[5]: SWORD
 * weapons[6]: TWO-HANDED SWORD
 * weapons[7]:
 * weapons[8]:
 * weapons[9]: 
 * 
 */
struct status
{
    double HP;
    double STR;
    double INT;
    double AGI;
    int inventory[10];
    int weapons[10];
    int rounds;
    double maxHP;
    int charFace;
};

struct riddle
{
    char question[STRING_LIMIT];
    char answer [STRING_LIMIT];
};

//A displayMenu kirajzolja a játék indítása során megjelenő menü-t
//mode bemenettel lehet jelezni helytelen menü választást
//mode=0 -> nincs hibaüzenet mode=1 van hibaüzenet 
void displayMenu(int mode)
{
	if (mode == 0)
	{
		system("clear");
		printf("\n\t\t\t██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░  ███╗░░██╗░█████╗░███╗░░░███╗░█████╗░██████╗░\n");
          printf("\t\t\t██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░  ████╗░██║██╔══██╗████╗░████║██╔══██╗██╔══██╗\n");
		  printf("\t\t\t██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░  ██╔██╗██║██║░░██║██╔████╔██║███████║██║░░██║\n");
		  printf("\t\t\t██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░  ██║╚████║██║░░██║██║╚██╔╝██║██╔══██║██║░░██║\n");
		  printf("\t\t\t██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗  ██║░╚███║╚█████╔╝██║░╚═╝░██║██║░░██║██████╔╝\n");
		  printf("\t\t\t╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ╚═╝░░╚══╝░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░\n\n\n");
        
        printf("\t\t\t\t\t\t\t\t█▀▄▀█ █▀▀ █▀▀▄ █░░█\n");
        printf("\t\t\t\t\t\t\t\t█░▀░█ █▀▀ █░░█ █░░█\n");
        printf("\t\t\t\t\t\t\t\t▀░░░▀ ▀▀▀ ▀░░▀ ░▀▀▀\n\n\n");
        
        printf("\t\t\t\t\t█▀▀█ █──█ █── █▀▀ █▀▀ ▄    ▄█─\n"); 
        printf("\t\t\t\t\t█▄▄▀ █──█ █── █▀▀ ▀▀█ ─    ─█─\n");
        printf("\t\t\t\t\t▀─▀▀ ─▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀    ▄█▄\n\n");

        printf("\t\t\t\t\t█▀▀█ █── █▀▀█ █──█ ▄    █▀█─\n"); 
        printf("\t\t\t\t\t█──█ █── █▄▄█ █▄▄█ ─    ─▄▀─\n"); 
        printf("\t\t\t\t\t█▀▀▀ ▀▀▀ ▀──▀ ▄▄▄█ ▀    █▄▄─\n\n");

        printf("\t\t\t\t\t█▀▀ █▀▀ ▀▀█▀▀ ▀▀█▀▀ ─▀─ █▀▀▄ █▀▀▀ █▀▀ ▄    █▀▀█\n"); 
        printf("\t\t\t\t\t▀▀█ █▀▀ ──█── ──█── ▀█▀ █──█ █─▀█ ▀▀█ ─    ──▀▄\n"); 
        printf("\t\t\t\t\t▀▀▀ ▀▀▀ ──▀── ──▀── ▀▀▀ ▀──▀ ▀▀▀▀ ▀▀▀ ▀    █▄▄█\n\n");
        
        printf("\t\t\t\t\t█▀▀█ █──█ ─▀─ ▀▀█▀▀    █▀▀▀ █▀▀█ █▀▄▀█ █▀▀ ▄    ─█▀█─\n"); 
        printf("\t\t\t\t\t█──█ █──█ ▀█▀ ──█──    █─▀█ █▄▄█ █─▀─█ █▀▀ ─    █▄▄█▄\n"); 
        printf("\t\t\t\t\t▀▀▀█ ─▀▀▀ ▀▀▀ ──▀──    ▀▀▀▀ ▀──▀ ▀───▀ ▀▀▀ ▀    ───█─\n\n");
        
        printf("\n\n\n");
        printf("Select a MENU option and press ENTER: ");
	}
	if (mode == 1)
	{
				system("clear");
        printf("\n\t\t\t██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░  ███╗░░██╗░█████╗░███╗░░░███╗░█████╗░██████╗░\n");
		  printf("\t\t\t██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░  ████╗░██║██╔══██╗████╗░████║██╔══██╗██╔══██╗\n");
		  printf("\t\t\t██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░  ██╔██╗██║██║░░██║██╔████╔██║███████║██║░░██║\n");
          printf("\t\t\t██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░  ██║╚████║██║░░██║██║╚██╔╝██║██╔══██║██║░░██║\n");
		  printf("\t\t\t██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗  ██║░╚███║╚█████╔╝██║░╚═╝░██║██║░░██║██████╔╝\n");
		  printf("\t\t\t╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ╚═╝░░╚══╝░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░\n\n\n");
        
        printf("\t\t\t\t\t\t\t\t█▀▄▀█ █▀▀ █▀▀▄ █░░█\n");
        printf("\t\t\t\t\t\t\t\t█░▀░█ █▀▀ █░░█ █░░█\n");
        printf("\t\t\t\t\t\t\t\t▀░░░▀ ▀▀▀ ▀░░▀ ░▀▀▀\n\n\n");
        
        printf("\t\t\t\t\t█▀▀█ █──█ █── █▀▀ █▀▀ ▄    ▄█─\n"); 
        printf("\t\t\t\t\t█▄▄▀ █──█ █── █▀▀ ▀▀█ ─    ─█─\n");
        printf("\t\t\t\t\t▀─▀▀ ─▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ▀    ▄█▄\n\n");

        printf("\t\t\t\t\t█▀▀█ █── █▀▀█ █──█ ▄    █▀█─\n"); 
        printf("\t\t\t\t\t█──█ █── █▄▄█ █▄▄█ ─    ─▄▀─\n"); 
        printf("\t\t\t\t\t█▀▀▀ ▀▀▀ ▀──▀ ▄▄▄█ ▀    █▄▄─\n\n");

        printf("\t\t\t\t\t█▀▀ █▀▀ ▀▀█▀▀ ▀▀█▀▀ ─▀─ █▀▀▄ █▀▀▀ █▀▀ ▄    █▀▀█\n"); 
        printf("\t\t\t\t\t▀▀█ █▀▀ ──█── ──█── ▀█▀ █──█ █─▀█ ▀▀█ ─    ──▀▄\n"); 
        printf("\t\t\t\t\t▀▀▀ ▀▀▀ ──▀── ──▀── ▀▀▀ ▀──▀ ▀▀▀▀ ▀▀▀ ▀    █▄▄█\n\n");
        
        printf("\t\t\t\t\t█▀▀█ █──█ ─▀─ ▀▀█▀▀    █▀▀▀ █▀▀█ █▀▄▀█ █▀▀ ▄    ─█▀█─\n"); 
        printf("\t\t\t\t\t█──█ █──█ ▀█▀ ──█──    █─▀█ █▄▄█ █─▀─█ █▀▀ ─    █▄▄█▄\n"); 
        printf("\t\t\t\t\t▀▀▀█ ─▀▀▀ ▀▀▀ ──▀──    ▀▀▀▀ ▀──▀ ▀───▀ ▀▀▀ ▀    ───█─\n\n");
        
        printf("\nInvalid input!\n\n");
        printf("Select a MENU option and press ENTER: ");
        
	}
}


//A characterChoose kirajzolja a karakter választásnál megjelenő képet
//mode bemenettel lehet jelezni helytelen menu választást
//mode=0 -> nincs hibaüzenet mode=1 van hibaüzenet 
void characterChoose(int mode)
{
    if(mode == 0)
    {
        system("clear");
		printf("\n\t\t\t██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░  ███╗░░██╗░█████╗░███╗░░░███╗░█████╗░██████╗░\n");
		printf("\t\t\t██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░  ████╗░██║██╔══██╗████╗░████║██╔══██╗██╔══██╗\n");
		printf("\t\t\t██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░  ██╔██╗██║██║░░██║██╔████╔██║███████║██║░░██║\n");
		printf("\t\t\t██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░  ██║╚████║██║░░██║██║╚██╔╝██║██╔══██║██║░░██║\n");
		printf("\t\t\t██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗  ██║░╚███║╚█████╔╝██║░╚═╝░██║██║░░██║██████╔╝\n");
		printf("\t\t\t╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ╚═╝░░╚══╝░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░\n\n\n");
        
        printf("\t\t\t█▀▀ █──█ █▀▀█ █▀▀█ █▀▀ █▀▀    █──█ █▀▀█ █──█ █▀▀█    █▀▀ █──█ █▀▀█ █▀▀█ █▀▀█ █▀▀ ▀▀█▀▀ █▀▀ █▀▀█\n");
        printf("\t\t\t█── █▀▀█ █──█ █──█ ▀▀█ █▀▀    █▄▄█ █──█ █──█ █▄▄▀    █── █▀▀█ █▄▄█ █▄▄▀ █▄▄█ █── ──█── █▀▀ █▄▄▀\n");
        printf("\t\t\t▀▀▀ ▀──▀ ▀▀▀▀ ▀▀▀▀ ▀▀▀ ▀▀▀    ▄▄▄█ ▀▀▀▀ ─▀▀▀ ▀─▀▀    ▀▀▀ ▀──▀ ▀──▀ ▀─▀▀ ▀──▀ ▀▀▀ ──▀── ▀▀▀ ▀─▀▀\n\n\n");
        
        printf("\t\t\t    ▄▄▄▄▄▄▄▄                SCHERIFF: 1                                   ROGUE: 2  \n");
        printf("\t\t\t    █      █                                        █      █    \n");
        printf("\t\t\t ▀▀▀█▀▀▀▀▀▀█▀▀▀     STATS        INVENTORY          █▀▀▀▀▀▀█       STATS        INVENTORY\n");      
        printf("\t\t\t    ▌ ═  ═ ▐                                        ▌██  ██▐ \n");
        printf("\t\t\t    ▌  ══  ▐        HP:  50      KNIFE              ▌  ██  ▐       HP:  40      DIRT\n");
        printf("\t\t\t    █▄▄▄▄▄▄█        INT: 30      GOLD               ████████       INT: 65      KNIFE\n");
        printf("\t\t\t      │  │          STR: 60                           ████         STR: 40\n");
        printf("\t\t\t  ████████████      AGI: 40                       ████████████     AGI: 65\n\n\n");
        
        printf("\t\t\t     ██████                  STONE MAN: 3                                 KNIGHT: 4  \n");
        printf("\t\t\t   ██▀▀▀▀▀▀██                                       ███████     \n");
        printf("\t\t\t   █▌ ─  ─ ▐█        STATS        INVENTORY         █  │  █        STATS       INVENTORY\n");      
        printf("\t\t\t   █▌  ══  ▐█                                       █──┼──█    \n");
        printf("\t\t\t   ██▄    ▄██        HP:  70      STONE             █  │  █        HP:  65      SWORD\n");
        printf("\t\t\t    ████████         INT: 15      DIRT              ███ ███        INT: 30      SHIELD\n");
        printf("\t\t\t    █      █         STR: 60      STICK              │   │         STR: 55\n");
        printf("\t\t\t  ████████████       AGI: 20                      ███████████      AGI: 30\n\n\n");
        
        printf("\t\t\t       ███                   WIZARD: 5                                    THE BUG: 6  \n");
        printf("\t\t\t      █   █                                         █     █     \n");
        printf("\t\t\t  ▄▄▄█▄▄▄▄▄█▄▄▄     STATS        INVENTORY          █▄▄▄▄▄█        STATS       INVENTORY\n");      
        printf("\t\t\t      ▌▄ ▄▐                                        ▐       ▌     \n");
        printf("\t\t\t      ▌ ═ ▐         HP:  40        STAFF           ▌ █ █ █ ▐       HP:  45      DIRT\n");
        printf("\t\t\t      ▀███▀         INT: 85        GOLD            ▌  ▄▄▄  ▐       INT: 25      FOOD\n");
        printf("\t\t\t     ███████        STR: 40                        ▀▀█▀ ▀█▀▀       STR: 60      STICK\n");
        printf("\t\t\t     ███████        AGI: 40                       ▄▄▄█▄▄▄█▄▄▄      AGI: 75\n\n\n");
        
        printf("\t\t\tSelect a character and press ENTER: ");
    }
    if(mode == 1)
    {
        system("clear");
		printf("\n\t\t\t██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░  ███╗░░██╗░█████╗░███╗░░░███╗░█████╗░██████╗░\n");
		printf("\t\t\t██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░  ████╗░██║██╔══██╗████╗░████║██╔══██╗██╔══██╗\n");
		printf("\t\t\t██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░  ██╔██╗██║██║░░██║██╔████╔██║███████║██║░░██║\n");
		printf("\t\t\t██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░  ██║╚████║██║░░██║██║╚██╔╝██║██╔══██║██║░░██║\n");
		printf("\t\t\t██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗  ██║░╚███║╚█████╔╝██║░╚═╝░██║██║░░██║██████╔╝\n");
		printf("\t\t\t╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ╚═╝░░╚══╝░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░\n\n\n");
        
        printf("\t\t\t█▀▀ █──█ █▀▀█ █▀▀█ █▀▀ █▀▀    █──█ █▀▀█ █──█ █▀▀█    █▀▀ █──█ █▀▀█ █▀▀█ █▀▀█ █▀▀ ▀▀█▀▀ █▀▀ █▀▀█\n");
        printf("\t\t\t█── █▀▀█ █──█ █──█ ▀▀█ █▀▀    █▄▄█ █──█ █──█ █▄▄▀    █── █▀▀█ █▄▄█ █▄▄▀ █▄▄█ █── ──█── █▀▀ █▄▄▀\n");
        printf("\t\t\t▀▀▀ ▀──▀ ▀▀▀▀ ▀▀▀▀ ▀▀▀ ▀▀▀    ▄▄▄█ ▀▀▀▀ ─▀▀▀ ▀─▀▀    ▀▀▀ ▀──▀ ▀──▀ ▀─▀▀ ▀──▀ ▀▀▀ ──▀── ▀▀▀ ▀─▀▀\n\n\n");
        
        printf("\t\t\t    ▄▄▄▄▄▄▄▄                SCHERIFF: 1                                   ROGUE: 2  \n");
        printf("\t\t\t    █      █                                        █      █    \n");
        printf("\t\t\t ▀▀▀█▀▀▀▀▀▀█▀▀▀     STATS        INVENTORY          █▀▀▀▀▀▀█       STATS        INVENTORY\n");      
        printf("\t\t\t    ▌ ═  ═ ▐                                        ▌██  ██▐ \n");
        printf("\t\t\t    ▌  ══  ▐        HP:  50      KNIFE              ▌  ██  ▐       HP:  40      DIRT\n");
        printf("\t\t\t    █▄▄▄▄▄▄█        INT: 30      GOLD               ████████       INT: 65      KNIFE\n");
        printf("\t\t\t      │  │          STR: 60                           ████         STR: 40\n");
        printf("\t\t\t  ████████████      AGI: 40                       ████████████     AGI: 65\n\n\n");
        
        printf("\t\t\t     ██████                  STONE MAN: 3                                 KNIGHT: 4  \n");
        printf("\t\t\t   ██▀▀▀▀▀▀██                                       ███████     \n");
        printf("\t\t\t   █▌ ─  ─ ▐█        STATS        INVENTORY         █  │  █        STATS       INVENTORY\n");      
        printf("\t\t\t   █▌  ══  ▐█                                       █──┼──█    \n");
        printf("\t\t\t   ██▄    ▄██        HP:  70      STONE             █  │  █        HP:  65      SWORD\n");
        printf("\t\t\t    ████████         INT: 15      DIRT              ███ ███        INT: 30      SHIELD\n");
        printf("\t\t\t    █      █         STR: 60      STICK              │   │         STR: 55\n");
        printf("\t\t\t  ████████████       AGI: 20                      ███████████      AGI: 30\n\n\n");
        
        printf("\t\t\t       ███                   WIZARD: 5                                    THE BUG: 6  \n");
        printf("\t\t\t      █   █                                         █     █     \n");
        printf("\t\t\t  ▄▄▄█▄▄▄▄▄█▄▄▄      STATS        INVENTORY         █▄▄▄▄▄█        STATS       INVENTORY\n");      
        printf("\t\t\t      ▌▄ ▄▐                                        ▐       ▌     \n");
        printf("\t\t\t      ▌ ═ ▐          HP:  40      STAFF            ▌ █ █ █ ▐       HP:  45      DIRT\n");
        printf("\t\t\t      ▀███▀          INT: 85      GOLD             ▌  ▄▄▄  ▐       INT: 25      FOOD\n");
        printf("\t\t\t     ███████         STR: 40                       ▀▀█▀ ▀█▀▀       STR: 60      STICK\n");
        printf("\t\t\t     ███████         AGI: 40                      ▄▄▄█▄▄▄█▄▄▄      AGI: 75\n\n");
        
        printf("Invalid input!\n");
        printf("\t\t\tSelect a character and press ENTER: ");
    }
}

void displayGameOver()
{
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t░██████╗░░█████╗░███╗░░░███╗███████╗  ░█████╗░██╗░░░██╗███████╗██████╗░\n");
        printf("\t\t\t\t██╔════╝░██╔══██╗████╗░████║██╔════╝  ██╔══██╗██║░░░██║██╔════╝██╔══██╗\n");
        printf("\t\t\t\t██║░░██╗░███████║██╔████╔██║█████╗░░  ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝\n");
        printf("\t\t\t\t██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░  ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗\n");
        printf("\t\t\t\t╚██████╔╝██║░░██║██║░╚═╝░██║███████╗  ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║\n");
        printf("\t\t\t\t░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝  ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n\n\n\n");
        printf("\t\t\t\tPress ENTER to get back to MENU!");
}

//EOTR: End Of The Round

void displayPlayerStats(struct status tempIN)
{

        char heroWeapon[STRING_LIMIT];
        for(int i=0; i<STRING_LIMIT; i++)
        {
            heroWeapon[i]='\0';
        }
        
        int bestWeapon = 0;
        for(int i=0; i<10; i++)
        {
            if(tempIN.weapons[i] == 1)
            { 
                bestWeapon = i;
            }
        }
        switch(bestWeapon)
        {
            case 0:
            {
                heroWeapon[0] = 'S';
                heroWeapon[1] = 'T';
                heroWeapon[2] = 'I';
                heroWeapon[3] = 'C';
                heroWeapon[4] = 'K';
                heroWeapon[5] = '\0';
            }
            break;
            case 1:
            {
                heroWeapon[0] = 'S';
                heroWeapon[1] = 'T';
                heroWeapon[2] = 'A';
                heroWeapon[3] = 'F';
                heroWeapon[4] = 'F';
                heroWeapon[5] = '\0';
            }
            break;
            case 2:
            {
                heroWeapon[0] = 'C';
                heroWeapon[1] = 'L';
                heroWeapon[2] = 'U';
                heroWeapon[3] = 'B';
                heroWeapon[4] = '\0';
            }            
            break;
            case 3:
            {
                heroWeapon[0] = 'K';
                heroWeapon[1] = 'N';
                heroWeapon[2] = 'I';
                heroWeapon[3] = 'F';
                heroWeapon[4] = 'E';
                heroWeapon[5] = '\0';
            }            
            break;
            case 4:
             {
                heroWeapon[0] = 'M';
                heroWeapon[1] = 'A';
                heroWeapon[2] = 'C';
                heroWeapon[3] = 'E';
                heroWeapon[4] = '\0';
            }           
            break;
            case 5:
            {
                heroWeapon[0] = 'S';
                heroWeapon[1] = 'W';
                heroWeapon[2] = 'O';
                heroWeapon[3] = 'R';
                heroWeapon[4] = 'D';
                heroWeapon[5] = '\0';
            }            
            break;
            case 6:
            {
                heroWeapon[0] = 'T';
                heroWeapon[1] = 'W';
                heroWeapon[2] = 'O';
                heroWeapon[3] = '-';
                heroWeapon[4] = 'H';
                heroWeapon[5] = 'A';
                heroWeapon[6] = 'N';
                heroWeapon[7] = 'D';
                heroWeapon[8] = 'E';
                heroWeapon[9] = 'D';
                heroWeapon[10] = ' ';
                heroWeapon[11] = 'S';
                heroWeapon[12] = 'W';
                heroWeapon[13] = 'O';
                heroWeapon[14] = 'R';
                heroWeapon[15] = 'D';
                heroWeapon[16] = '\0';
            }            
            break;
        }
        
        
        
        if(tempIN.charFace == 1)
        {
        system("clear");
        printf("\n\n\n\n");
        printf("\t\t\t                             ROUND: %d                        \n",tempIN.rounds);
        printf("\t\t\t    ▄▄▄▄▄▄▄▄                                                  \n");
        printf("\t\t\t    █      █                                                  \n");
        printf("\t\t\t ▀▀▀█▀▀▀▀▀▀█▀▀▀     STATS        INVENTORY        WEAPON      \n");        
        printf("\t\t\t    ▌ ═  ═ ▐                                                  \n");
        printf("\t\t\t    ▌  ══  ▐        HP:  %.2lf     DIRT: %d         %s        \n",tempIN.HP,tempIN.inventory[0],heroWeapon);
        printf("\t\t\t    █▄▄▄▄▄▄█        INT: %.2lf     STONE:%d                   \n",tempIN.INT,tempIN.inventory[1]);
        printf("\t\t\t      │  │          STR: %.2lf     FOOD: %d                   \n",tempIN.STR,tempIN.inventory[2]);
        printf("\t\t\t  ████████████      AGI: %.2lf     GOLD: %d                   \n",tempIN.AGI,tempIN.inventory[3]);
        printf("\t\t\t                                   SHIELD: %d                 \n",tempIN.inventory[4]);
        }
        if(tempIN.charFace == 2)
        {
        system("clear");
        printf("\n\n\n\n");
        printf("\t\t\t                             ROUND: %d                        \n",tempIN.rounds);
        printf("\t\t\t                                                              \n");
        printf("\t\t\t    █      █                                                  \n");
        printf("\t\t\t    █▀▀▀▀▀▀█        STATS        INVENTORY        WEAPON      \n");        
        printf("\t\t\t    ▌██  ██▐                                                  \n");
        printf("\t\t\t    ▌  ██  ▐        HP:  %.2lf     DIRT: %d         %s          \n",tempIN.HP,tempIN.inventory[0],heroWeapon);
        printf("\t\t\t    ████████        INT: %.2lf     STONE: %d                    \n",tempIN.INT,tempIN.inventory[1]);
        printf("\t\t\t      ████          STR: %.2lf     FOOD: %d                     \n",tempIN.STR,tempIN.inventory[2]);
        printf("\t\t\t  ████████████      AGI: %.2lf     GOLD: %d                     \n",tempIN.AGI,tempIN.inventory[3]);
        printf("\t\t\t                                   SHIELD: %d                   \n",tempIN.inventory[4]);
        }
        if(tempIN.charFace == 3)
        {
        system("clear");
        printf("\n\n\n\n");
        printf("\t\t\t                             ROUND: %d                        \n",tempIN.rounds);
        printf("\t\t\t     ██████                                                   \n");
        printf("\t\t\t   ██▀▀▀▀▀▀██                                                 \n");
        printf("\t\t\t   █▌ ─  ─ ▐█       STATS        INVENTORY        WEAPON      \n");        
        printf("\t\t\t   █▌  ══  ▐█                                                 \n");
        printf("\t\t\t   ██▄    ▄██       HP:  %.2lf     DIRT: %d         %s          \n",tempIN.HP,tempIN.inventory[0],heroWeapon);
        printf("\t\t\t    ████████        INT: %.2lf     STONE: %d                    \n",tempIN.INT,tempIN.inventory[1]);
        printf("\t\t\t    █      █        STR: %.2lf     FOOD: %d                     \n",tempIN.STR,tempIN.inventory[2]);
        printf("\t\t\t  ████████████      AGI: %.2lf     GOLD: %d                     \n",tempIN.AGI,tempIN.inventory[3]);
        printf("\t\t\t                                   SHIELD: %d                   \n",tempIN.inventory[4]);
        }
        if(tempIN.charFace == 4)
        {
        system("clear");
        printf("\n\n\n\n");
        printf("\t\t\t                             ROUND: %d                        \n",tempIN.rounds);
        printf("\t\t\t                                                              \n");
        printf("\t\t\t    ███████                                                   \n");
        printf("\t\t\t    █  │  █         STATS        INVENTORY        WEAPON      \n");        
        printf("\t\t\t    █──┼──█                                                   \n");
        printf("\t\t\t    █  │  █         HP:  %.2lf     DIRT: %d         %s          \n",tempIN.HP,tempIN.inventory[0],heroWeapon);
        printf("\t\t\t    ███ ███         INT: %.2lf     STONE: %d                    \n",tempIN.INT,tempIN.inventory[1]);
        printf("\t\t\t     │   │          STR: %.2lf     FOOD: %d                     \n",tempIN.STR,tempIN.inventory[2]);
        printf("\t\t\t  ███████████       AGI: %.2lf     GOLD: %d                     \n",tempIN.AGI,tempIN.inventory[3]);
        printf("\t\t\t                                   SHIELD: %d                   \n",tempIN.inventory[4]);
        }
        if(tempIN.charFace == 5)
        {
        system("clear");
        printf("\n\n\n\n");
        printf("\t\t\t                             ROUND: %d                        \n",tempIN.rounds);
        printf("\t\t\t      ███                                                     \n");
        printf("\t\t\t     █   █                                                    \n");
        printf("\t\t\t ▄▄▄█▄▄▄▄▄█▄▄▄      STATS        INVENTORY        WEAPON      \n");        
        printf("\t\t\t     ▌▄ ▄▐                                                    \n");
        printf("\t\t\t     ▌ ═ ▐          HP:  %.2lf     DIRT: %d         %s          \n",tempIN.HP,tempIN.inventory[0],heroWeapon);
        printf("\t\t\t     ▀███▀          INT: %.2lf     STONE: %d                    \n",tempIN.INT,tempIN.inventory[1]);
        printf("\t\t\t    ███████         STR: %.2lf     FOOD: %d                     \n",tempIN.STR,tempIN.inventory[2]);
        printf("\t\t\t    ███████         AGI: %.2lf     GOLD: %d                     \n",tempIN.AGI,tempIN.inventory[3]);
        printf("\t\t\t                                   SHIELD: %d                   \n",tempIN.inventory[4]);
        }
        if(tempIN.charFace == 6)
        {
        system("clear");
        printf("\n\n\n\n");
        printf("\t\t\t                             ROUND: %d                        \n",tempIN.rounds);
        printf("\t\t\t                                                              \n");
        printf("\t\t\t     █     █                                                  \n");
        printf("\t\t\t     █▄▄▄▄▄█        STATS        INVENTORY        WEAPON      \n");        
        printf("\t\t\t    ▐       ▌                                                 \n");
        printf("\t\t\t    ▌ █ █ █ ▐       HP:  %.2lf     DIRT: %d         %s          \n",tempIN.HP,tempIN.inventory[0],heroWeapon);
        printf("\t\t\t    ▌  ▄▄▄  ▐       INT: %.2lf     STONE: %d                    \n",tempIN.INT,tempIN.inventory[1]);
        printf("\t\t\t    ▀▀█▀ ▀█▀▀       STR: %.2lf     FOOD: %d                     \n",tempIN.STR,tempIN.inventory[2]);
        printf("\t\t\t   ▄▄▄█▄▄▄█▄▄▄      AGI: %.2lf     GOLD: %d                     \n",tempIN.AGI,tempIN.inventory[3]);
        printf("\t\t\t                                   SHIELD: %d                   \n",tempIN.inventory[4]);
        }
                    
}


struct status endOfRound(struct status tempIN)
{
                struct status tempOUT = tempIN;
                char foodChoise[STRING_LIMIT];
                for(int i=0; i<STRING_LIMIT; i++)
                {
                    foodChoise[i] = '\0';
                }
                foodChoise[0] = '1';
                
displayStats:
                displayPlayerStats(tempOUT);
                printf("\n\n\n\t\t\t\t\tPress ENTER to continue...");
        
                getchar();  
                
                

                
                
                if(tempOUT.inventory[2] > 0 && foodChoise[0] != '2')
                {
                system("clear");
                printf("\n\n\n");
                printf("\n\n\n");
                printf("\t\t\t\tDo you want to eat?\n\n");
                printf("\t\t\t\t\t(Eating heals you 30 HP)\n\n\n");
                printf("\t\t\t\t\tYES: 1\t\tNO:2\n\n");
                printf("\t\t\t\tSelect an option and then press ENTER: ");
        
                
        
                scanf(" ");
                gets(foodChoise);
        
                while(  foodChoise[1] != '\0' ||
                        foodChoise[0] == '\0' ||
                       (foodChoise[0] != '1'  &&
                        foodChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                foodChoise[i] = '\0';
                            }
                        system("clear");
                        printf("\n\n\n");
                        printf("\n\n\n");
                        printf("\t\t\t\tDo you want to eat?\n\n");
                        printf("\t\t\t\t\t(Eating heals you 30 HP)\n\n\n");
                        printf("\t\t\t\t\tYES: 1\t\tNO:2\n\t\t\t\t\tInvalid input!\n");
                        printf("\t\t\t\tSelect an option and then press ENTER: ");
                        scanf(" ");
                        gets(foodChoise);
                    }
                    if(foodChoise[0] == '1')
                    {
                        tempOUT.inventory[2]--;
                        if(tempOUT.maxHP < tempOUT.HP + 30.0)
                        {
                            tempOUT.HP = tempOUT.maxHP;
                        }
                        else
                        {
                            tempOUT.HP = tempOUT.HP+30.0;
                        }
                    }
                    if(foodChoise[0] == '2')
                        return tempOUT;
                    goto displayStats;
                 }
    
    
    return tempOUT;
}


struct status golemRound(struct status tempIN)
{
        struct status tempOUT = tempIN;
        double golemHP = 80.0;
        double golemDMG = 5.0;
       
        system("clear");
        printf("\n\n\n");
        printf("\t\t█▄█ █▀█ █░█   ▄▀█ █▀█ █▀▀   █░█░█ ▄▀█ █░░ █▄▀ █ █▄░█ █▀▀   ▄▀█ █░░ █▀█ █▄░█ █▀▀   ▀█▀ █░█ █▀▀   █▀█ ▄▀█ ▀█▀ █░█ ░\n");
        printf("\t\t░█░ █▄█ █▄█   █▀█ █▀▄ ██▄   ▀▄▀▄▀ █▀█ █▄▄ █░█ █ █░▀█ █▄█   █▀█ █▄▄ █▄█ █░▀█ █▄█   ░█░ █▀█ ██▄   █▀▀ █▀█ ░█░ █▀█ █\n\n");

        printf("\t\t█░█░█ █░█ █▀▀ █▄░█   ▄▀█   █▄▄ █ █▀▀   █▀ ▀█▀ █▀█ █▄░█ █▀▀   █▀▄▀█ ▄▀█ █▄░█   █▀ ▀█▀ ▄▀█ █▄░█ █▀▄ █▀   █ █▄░█\n");
        printf("\t\t▀▄▀▄▀ █▀█ ██▄ █░▀█   █▀█   █▄█ █ █▄█   ▄█ ░█░ █▄█ █░▀█ ██▄   █░▀░█ █▀█ █░▀█   ▄█ ░█░ █▀█ █░▀█ █▄▀ ▄█   █ █░▀█\n\n");

        printf("\t\t█▀▀ █▀█ █▀█ █▄░█ ▀█▀   █▀█ █▀▀   █▄█ █▀█ █░█ ░\n");
        printf("\t\t█▀░ █▀▄ █▄█ █░▀█ ░█░   █▄█ █▀░   ░█░ █▄█ █▄█ ▄ ▄ ▄\n\n\n\n");
        printf("\t\tPress ENTER to continue...");

        getchar();
       
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█─░─█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▀█▀█▀░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██▀▀▀▀▀░▀▀▀▀▀██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░█░░░░░░░░░░░█░█░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░███████░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░██░░░░░██░░░░░░░░░░░░░\n\n\n");
        
        printf("\t\t\t\tGOLEM: Must please Dormammu.\n\n");
        printf("\t\t\t\tGOLEM: Me smash you.\n\n");
        
        printf("\t\t\t\tPress ENTER to continue...");
        getchar();
        
        if(tempOUT.inventory[4] == 1)
        {
            golemDMG = golemDMG*0.8;
        }
        
        if(tempOUT.inventory[0] > 0)
        {
            system("clear");
            printf("\n\n\n");
            printf("\n\n\n");
            printf("\t\t\t\tDo you want to use dirt in the next battle?\n\n");
            printf("\t\t\t\t\t(The enemy will have 2 less damage)\n\n\n");
            printf("\t\t\t\t\tYES: 1\t\tNO:2\n\n");
            printf("\t\t\t\tSelect an option and then press ENTER: ");
        
            char dirtChoiseG[STRING_LIMIT];
        
            scanf(" ");
            gets(dirtChoiseG);
        
            while(  dirtChoiseG[1] != '\0' ||
                    dirtChoiseG[0] == '\0' ||
                   (dirtChoiseG[0] != '1'  &&
                    dirtChoiseG[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                        {
                            dirtChoiseG[i] = '\0';
                        }
                        
                        system("clear");
                        printf("\n\n\n");
                        printf("\n\n\n");
                        printf("\t\t\t\tDo you want to use dirt in the next battle?\n\n");
                        printf("\t\t\t\t\t(The enemy will have 2 less damage)\n\n\n");
                        printf("\t\t\t\t\tYES: 1\t\tNO:2\n\t\t\t\tInvalid input!\n");
                        printf("\t\t\t\tSelect an option and then press ENTER: ");
                        scanf(" ");
                        gets(dirtChoiseG);
                    }
        
        
        
                if(dirtChoiseG[0] == '2')
                goto stoneThrowGolem;
        
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░█░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        system("clear");
        delay(0.1);
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░█░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░█░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        system("clear");
        delay(0.1);
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        golemDMG=golemDMG-2.0;
        tempOUT.inventory[0]--;
        }
        
        
stoneThrowGolem:
        
        
        
        if(tempOUT.inventory[1] > 0)
        {
                system("clear");
                printf("\n\n\n");
                printf("\n\n\n");
                printf("\t\t\t\tDo you want to use a stone in the next battle?\n\n");
                printf("\t\t\t\t\t(Enemy suffers 20 DMG)\n\n\n");
                printf("\t\t\t\t\tYES: 1\t\tNO:2\n\n");
                printf("\t\t\t\tSelect an option and then press ENTER: ");
        
                char stoneChoiseG[STRING_LIMIT];
        
                scanf(" ");
                gets(stoneChoiseG);
        
                while(  stoneChoiseG[1] != '\0' ||
                        stoneChoiseG[0] == '\0' ||
                       (stoneChoiseG[0] != '1'  &&
                        stoneChoiseG[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                stoneChoiseG[i] = '\0';
                            }
                system("clear");
                printf("\n\n\n");
                printf("\n\n\n");
                printf("\t\t\t\tDo you want to use a stone in the next battle?\n\n");
                printf("\t\t\t\t\t(Enemy suffers 20 DMG)\n\n\n");       
                printf("\t\t\t\t\tYES: 1\t\tNO:2\n\t\t\t\tInvalid input!\n");
                printf("\t\t\t\tSelect an option and then press ENTER: ");
                scanf(" ");
                gets(stoneChoiseG);
                    } 

      
        if(stoneChoiseG[0] == '2')
            goto golemBattle;
            
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░█░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        system("clear");
        delay(0.1);
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░█░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░█░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        system("clear");
        delay(0.1);
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        golemHP=golemHP-20;
        tempOUT.inventory[1]--;
        }


double weaponG = 0; 
      
golemBattle:

        //alapesetben, ha nincs semmi fegyvere a karakternek 0.1et sebez
         //weapon = a fegyver sebzésének 10szerese
        //ha van fegyvere, akkor a legerősebbet hasznalja mindig
        for(int i=0; i<10; i++)
        {
            if(tempOUT.weapons[i] == 1)
            {
                weaponG = i+2.0;
            }
        }
        double heroGDMG = tempOUT.STR*(weaponG/10.0);
        
        while(tempOUT.HP > 0 && golemHP > 0)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░██░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░██░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░██░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░██░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        golemHP = golemHP-heroGDMG;
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███████████░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        if(golemHP <= 0.0)
        goto heroKillGolem;
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        tempOUT.HP = tempOUT.HP-golemDMG;
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░█████████████████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░████░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        if(tempOUT.HP <= 0.0)
        goto golemKillHero;
        }

heroKillGolem:
        if(golemHP <= 0.0)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░██████████░░░░░███░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░█████████████████████████░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\tYou defeated the Golem!\n\n");
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
        system("clear");
        printf("\n\n\n");
        printf("\t\t█▄█ █▀█ █░█   █▀▀ █ █▄░█ █▀▄   ▄▀█   █▀ ▀█▀ █▀█ █▄░█ █▀▀   ▄▀█ ▀█▀   █░█ █ █▀   █▀█ █░░ ▄▀█ █▀▀ █▀▀ ░\n");
        printf("\t\t░█░ █▄█ █▄█   █▀░ █ █░▀█ █▄▀   █▀█   ▄█ ░█░ █▄█ █░▀█ ██▄   █▀█ ░█░   █▀█ █ ▄█   █▀▀ █▄▄ █▀█ █▄▄ ██▄ ▄\n\n");

        printf("\t\t█▄█ █▀█ █░█   █▀ ▀█▀ █▀▀ █▀█   █▀█ █░█ █▀▀ █▀█   ▀█▀ █░█ █▀▀   █▀▀ █▀█ █▀█ █▀█ █▀ █▀▀   ▄▀█ █▄░█ █▀▄\n");
        printf("\t\t░█░ █▄█ █▄█   ▄█ ░█░ ██▄ █▀▀   █▄█ ▀▄▀ ██▄ █▀▄   ░█░ █▀█ ██▄   █▄▄ █▄█ █▀▄ █▀▀ ▄█ ██▄   █▀█ █░▀█ █▄▀\n\n");

        printf("\t\t█▀▀ █▀█ █▄░█ ▀█▀ █ █▄░█ █░█ █▀▀   █▀█ █▄░█   █▄█ █▀█ █░█ █▀█   █░█░█ ▄▀█ █▄█ ░ \n");
        printf("\t\t█▄▄ █▄█ █░▀█ ░█░ █ █░▀█ █▄█ ██▄   █▄█ █░▀█   ░█░ █▄█ █▄█ █▀▄   ▀▄▀▄▀ █▀█ ░█░ ▄ ▄ ▄\n\n\n\n");
        printf("\t\tPress ENTER to continue...");
        getchar();
        tempOUT.inventory[1]++;
        
        }


golemKillHero:
        if(tempOUT.HP <= 0.0)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tGOLEM HP: %.2lf\n", tempOUT.HP, golemHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░██████████░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\tGOLEM defeated you!\n\n");
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
        }
tempOUT.rounds++;
return tempOUT;
}

struct status treeRound(struct status tempIN)
{
        time_t t;
        srand((unsigned)time(&t));
        int randNUM = rand() % (MAX_NUMBER+1);
        struct status tempOUT = tempIN;
        system("clear");
        printf("\n\n\n");

        printf("\t\t█▀█ █▄░█   █▄█ █▀█ █░█ █▀█   █░█░█ ▄▀█ █▄█   █▄█ █▀█ █░█   █▀ █▀▀ █▀▀   ▄▀█   ▀█▀ █▀█ █▀▀ █▀▀   █░█░█ █ ▀█▀ █░█   ▄▀█\n");
        printf("\t\t█▄█ █░▀█   ░█░ █▄█ █▄█ █▀▄   ▀▄▀▄▀ █▀█ ░█░   ░█░ █▄█ █▄█   ▄█ ██▄ ██▄   █▀█   ░█░ █▀▄ ██▄ ██▄   ▀▄▀▄▀ █ ░█░ █▀█   █▀█\n\n");

        printf("\t\t█▀ █ █▄░█ █▀▀ █░░ █▀▀   ▄▀█ █▀█ █▀█ █░░ █▀▀   █▀█ █▄░█   █ ▀█▀ ░   █ ▀█▀   █▀ █▀▀ █▀▀ █▀▄▀█ █▀\n");
        printf("\t\t▄█ █ █░▀█ █▄█ █▄▄ ██▄   █▀█ █▀▀ █▀▀ █▄▄ ██▄   █▄█ █░▀█   █ ░█░ ▄   █ ░█░   ▄█ ██▄ ██▄ █░▀░█ ▄█\n\n");

        printf("\t\t█▀▄ ▄▀█ █▄░█ █▀▀ █▀▀ █▀█ █▀█ █░█ █▀   ▀█▀ █▀█   █▀▀ █░░ █ █▀▄▀█ █▄▄   █░█ █▀█   ▀█▀ █▀█   █▀▀ █▀▀ ▀█▀   ▀█▀ █░█ █▀▀\n");
        printf("\t\t█▄▀ █▀█ █░▀█ █▄█ ██▄ █▀▄ █▄█ █▄█ ▄█   ░█░ █▄█   █▄▄ █▄▄ █ █░▀░█ █▄█   █▄█ █▀▀   ░█░ █▄█   █▄█ ██▄ ░█░   ░█░ █▀█ ██▄\n\n");

        printf("\t\t▄▀█ █▀█ █▀█ █░░ █▀▀ ░   █▄▄ █░█ ▀█▀   █ █▀▀   █▄█ █▀█ █░█   █▀▀ █░░ █ █▀▄▀█ █▄▄\n");
        printf("\t\t█▀█ █▀▀ █▀▀ █▄▄ ██▄ █   █▄█ █▄█ ░█░   █ █▀░   ░█░ █▄█ █▄█   █▄▄ █▄▄ █ █░▀░█ █▄█\n\n");

        printf("\t\t█▀ █▄▀ █ █░░ █░░ █▀▀ █░█ █░░ █░░ █▄█   █▄█ █▀█ █░█   █▀▀ ▄▀█ █▄░█   █▀▀ █▀▀ ▀█▀   ▀█▀ █░█ █▀▀   █▀▀ █▀█ █▀█ █▀▄ ░\n");
        printf("\t\t▄█ █░█ █ █▄▄ █▄▄ █▀░ █▄█ █▄▄ █▄▄ ░█░   ░█░ █▄█ █▄█   █▄▄ █▀█ █░▀█   █▄█ ██▄ ░█░   ░█░ █▀█ ██▄   █▀░ █▄█ █▄█ █▄▀ ▄\n\n\n\n");

        printf("\t\tPress ENTER to continue...");

        getchar();
        
        system("clear");
        printf("\n\n\n");;
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░█░░░░░░████░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░█░░░░██░░░░░░░░█░░░░█░░░█░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░█░░░░░░█░░░░░░░░████░░░███░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░░░░█░░░░░░░█░░░░░░███░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░██░░░░█░░░░░█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█░░░█░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█░░█░░█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█░████░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█████████░░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\t\tAre you trying to climb up for food?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER!");
        
                char treeChoise[STRING_LIMIT];
        
                scanf(" ");
                gets(treeChoise);
        
                while(  treeChoise[1] != '\0' ||
                        treeChoise[0] == '\0' ||
                       (treeChoise[0] != '1'  &&
                        treeChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                treeChoise[i] = '\0';
                            }
        system("clear");
        printf("\n\n\n");;
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░█░░░░░░████░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░█░░░░██░░░░░░░░█░░░░█░░░█░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░█░░░░░░█░░░░░░░░████░░░███░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░░░░█░░░░░░░█░░░░░░███░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░██░░░░█░░░░░█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█░░░█░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█░░█░░█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█░████░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█████████░░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\t\tAre you trying to climb up for food?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\t\t\t\t\t\tInvalid input!\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER!");
                scanf(" ");
                gets(treeChoise);
                    } 
        if(treeChoise[0] == '1')
        {
            if((tempOUT.AGI+(double)randNUM) >= 60)
            {
                system("clear");
                printf("\n\n\n"); 
                printf("\t\t█▄█ █▀█ █░█   █░█ ▄▀█ █░█ █▀▀   █▀ █░█ █▀▀ █▀▀ █▀▀ █▀ █▀ █▀▀ █░█ █░░ █░░ █▄█   █▀▀ █░░ █ █▀▄▀█ █▄▄ █▀▀ █▀▄   █░█ █▀█\n");
                printf("\t\t░█░ █▄█ █▄█   █▀█ █▀█ ▀▄▀ ██▄   ▄█ █▄█ █▄▄ █▄▄ ██▄ ▄█ ▄█ █▀░ █▄█ █▄▄ █▄▄ ░█░   █▄▄ █▄▄ █ █░▀░█ █▄█ ██▄ █▄▀   █▄█ █▀▀\n\n");

                printf("\t\t▄▀█ █▄░█ █▀▄   ▄▀█ █▀▄ █▀▄ █▀▀ █▀▄   ▄▀█   █▀▀ █▀█ █▀█ █▀▄   ▀█▀ █▀█   █▄█ █▀█ █░█ █▀█\n");
                printf("\t\t█▀█ █░▀█ █▄▀   █▀█ █▄▀ █▄▀ ██▄ █▄▀   █▀█   █▀░ █▄█ █▄█ █▄▀   ░█░ █▄█   ░█░ █▄█ █▄█ █▀▄\n\n");

                printf("\t\t█ █▄░█ █░█ █▀▀ █▄░█ ▀█▀ █▀█ █▀█ █▄█\n");
                printf("\t\t█ █░▀█ ▀▄▀ ██▄ █░▀█ ░█░ █▄█ █▀▄ ░█░\n\n\n\n");
                
                printf("\t\tPress ENTER to continue...");
                getchar();
                tempOUT.inventory[2]++;
            }
            else if((tempOUT.AGI+(double)randNUM) < 60)
            {
                system("clear");
                printf("\n\n\n");
                printf("\t\t█▄█ █▀█ █░█   ▀█▀ █▀█ █ █▀▀ █▀▄   ▀█▀ █▀█   █▀▀ █░░ █ █▀▄▀█ █▄▄   █░█ █▀█ ░   █▄▄ █░█ ▀█▀   █▄█ █▀█ █░█ █▀█\n");
                printf("\t\t░█░ █▄█ █▄█   ░█░ █▀▄ █ ██▄ █▄▀   ░█░ █▄█   █▄▄ █▄▄ █ █░▀░█ █▄█   █▄█ █▀▀ █   █▄█ █▄█ ░█░   ░█░ █▄█ █▄█ █▀▄\n\n");

                printf("\t\t█░█ ▄▀█ █▄░█ █▀▄   █▀ █░░ █ █▀█ █▀█ █▀▀ █▀▄   █▀█ █▄░█   █▀█ █▄░█ █▀▀   █▀█ █▀▀   ▀█▀ █░█ █▀▀   █▀▀ █▀█ █ █▀█ █▀\n");
                printf("\t\t█▀█ █▀█ █░▀█ █▄▀   ▄█ █▄▄ █ █▀▀ █▀▀ ██▄ █▄▀   █▄█ █░▀█   █▄█ █░▀█ ██▄   █▄█ █▀░   ░█░ █▀█ ██▄   █▄█ █▀▄ █ █▀▀ ▄█\n\n");

                printf("\t\t▄▀█ █▄░█ █▀▄   █▄█ █▀█ █░█   █▀▀ █▀▀ █░░ █░░ ░\n");
                printf("\t\t█▀█ █░▀█ █▄▀   ░█░ █▄█ █▄█   █▀░ ██▄ █▄▄ █▄▄ ▄\n\n\n\t\tYou suffered 10 DMG.\n");
                
                printf("\t\tPress ENTER to continue...");
                getchar();
                tempOUT.HP=tempOUT.HP-10.0;
            }
                
        }
tempOUT.rounds++;
return tempOUT;
        
}

struct status mineRound(struct status tempIN)
{

        struct status tempOUT = tempIN;
        double skeletonHP = 50.0;
        double skeletonDMG = 3.0;
        
        if(tempOUT.inventory[4] == 1)
        {
            skeletonDMG = skeletonDMG*0.8;
        }
        system("clear");
        printf("\n\n\n");        
        
        printf("\t\t█▄█ █▀█ █░█   █▀ █▀▀ █▀▀   ▄▀█   █▀▄ ▄▀█ █▀█ █▄▀   █▀▀ ▄▀█ █░█ █▀▀ ░   █▄█ █▀█ █░█   █▀▀ █▀█\n");
        printf("\t\t░█░ █▄█ █▄█   ▄█ ██▄ ██▄   █▀█   █▄▀ █▀█ █▀▄ █░█   █▄▄ █▀█ ▀▄▀ ██▄ ▄   ░█░ █▄█ █▄█   █▄█ █▄█\n\n");

        printf("\t\t█▀▀ █░░ █▀█ █▀ █▀▀ █▀█   ▀█▀ █▀█   █░█ ▄▀█ █░█ █▀▀   ▄▀█   █▄▄ █▀▀ ▀█▀ ▀█▀ █▀▀ █▀█   █░░ █▀█ █▀█ █▄▀   ▄▀█ █▄░█ █▀▄\n");
        printf("\t\t█▄▄ █▄▄ █▄█ ▄█ ██▄ █▀▄   ░█░ █▄█   █▀█ █▀█ ▀▄▀ ██▄   █▀█   █▄█ ██▄ ░█░ ░█░ ██▄ █▀▄   █▄▄ █▄█ █▄█ █░█   █▀█ █░▀█ █▄▀\n\n");

        printf("\t\t█▀ █▀▀ █▀▀   ▄▀█   █▀▀ █▀█ █░░ █▀▄   █▄░█ █░█ █▀▀ █▀▀ █▀▀ ▀█▀ ░\n");
        printf("\t\t▄█ ██▄ ██▄   █▀█   █▄█ █▄█ █▄▄ █▄▀   █░▀█ █▄█ █▄█ █▄█ ██▄ ░█░ ▄\n\n\n\n");

        printf("\t\tPress ENTER to continue...");

        getchar();



        
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░███░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░██████████████░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███░░░░░\n");
        printf("\t\t\t\t\t\t░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░\n");
        printf("\t\t\t\t\t\t░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░\n");
        printf("\t\t\t\t\t\t░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒╬▒▒▒▒▒▒▒▒█░░\n\n\n");
        printf("\t\t\t\t\t\tAre you going to pick it up?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER!:");
        
                char goldChoise[STRING_LIMIT];
        
                scanf(" ");
                gets(goldChoise);
        
                while(  goldChoise[1] != '\0' ||
                        goldChoise[0] == '\0' ||
                       (goldChoise[0] != '1'  &&
                        goldChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                goldChoise[i] = '\0';
                            }
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░███░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░██████████████░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███░░░░░\n");
        printf("\t\t\t\t\t\t░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░\n");
        printf("\t\t\t\t\t\t░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░\n");
        printf("\t\t\t\t\t\t░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒╬▒▒▒▒▒▒▒▒█░░\n\n\n");
        printf("\t\t\t\t\t\tAre you going to pick it up?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\t\t\t\t\t\tInvalid input!\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER: ");
                scanf(" ");
                gets(goldChoise);
                    } 
        
        if(goldChoise[0] == '1')
    {
        //alapesetben, ha nincs semmi fegyvere a karakternek 0.1et sebez
            double weaponS = 0; //weapon = a fegyver sebzésének 10szerese
        //ha van fegyvere, akkor a legerősebbet hasznalja mindig
            for(int i=0; i<10; i++)
            {
                if(tempOUT.weapons[i] == 1)
                {
                    weaponS = i+2.0;
                }
            }
        double heroSDMG = tempOUT.STR*(weaponS/10.0);
        system("clear");
        printf("\n\n\n");          
        printf("\t\t▄▀█ █▀   █▀ █▀█ █▀█ █▄░█   ▄▀█ █▀   █▄█ █▀█ █░█   █▀▀ █▄░█ ▀█▀ █▀▀ █▀█   ▀█▀ █░█ █▀▀   █▀▀ ▄▀█ █░█ █▀▀   █▄█ █▀█ █░█\n");
        printf("\t\t█▀█ ▄█   ▄█ █▄█ █▄█ █░▀█   █▀█ ▄█   ░█░ █▄█ █▄█   ██▄ █░▀█ ░█░ ██▄ █▀▄   ░█░ █▀█ ██▄   █▄▄ █▀█ ▀▄▀ ██▄   ░█░ █▄█ █▄█\n\n");
        
        printf("\t\t█▄░█ █▀█ ▀█▀ █ █▀▀ █▀▀   ▄▀█   █▄░█ █▀█ █ █▀ █▀▀   ▄▀█ █▄░█ █▀▄   ▀█▀ █░█ █▀█ █▄░█   ▄▀█ █▀█ █▀█ █░█ █▄░█ █▀▄\n");
        printf("\t\t█░▀█ █▄█ ░█░ █ █▄▄ ██▄   █▀█   █░▀█ █▄█ █ ▄█ ██▄   █▀█ █░▀█ █▄▀   ░█░ █▄█ █▀▄ █░▀█   █▀█ █▀▄ █▄█ █▄█ █░▀█ █▄▀ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();

        while(skeletonHP > 0 && tempOUT.HP > 0)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░█╛┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░█░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░█░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░█░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        tempOUT.HP=tempOUT.HP-skeletonDMG;
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░███░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);

        if(tempOUT.HP < 0)
            goto skeletonKillHero;
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░█╛┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░██░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░██░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░██░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░██░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        skeletonHP = skeletonHP-heroSDMG;
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███████████░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        if(skeletonHP<0)
            goto heroKillSkeleton;
    }
heroKillSkeleton:
        if(skeletonHP <= 0)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼┼┼░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\tYou defeated the Skeleton!\n\n");
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
        tempOUT.inventory[3]++;
        }
skeletonKillHero:
        if(tempOUT.HP <= 0)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tSKELETON HP: %.2lf\n", tempOUT.HP, skeletonHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┼┼┼░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░███░░░░░░░░░░░░░░░░░░░░│┼│░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░┼░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░──░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\tSkeleton defeated you!\n\n");
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
        }
  
    } 
tempOUT.rounds++;
return tempOUT;
}

struct status gamblingRound(struct status tempIN)
{
        system("clear");
        printf("\n\n\n"); 
        printf("\t\t█▀█ █▄░█   ▀█▀ █░█ █▀▀   █▀█ ▄▀█ ▀█▀ █░█   █▄█ █▀█ █░█   █▄░█ █▀█ ▀█▀ █ █▀▀ █▀▀   ▄▀█   █░█ █▀█ █▀█ █▀▄ █▀▀ █▀▄\n");
        printf("\t\t█▄█ █░▀█   ░█░ █▀█ ██▄   █▀▀ █▀█ ░█░ █▀█   ░█░ █▄█ █▄█   █░▀█ █▄█ ░█░ █ █▄▄ ██▄   █▀█   █▀█ █▄█ █▄█ █▄▀ ██▄ █▄▀\n\n");

        printf("\t\t█▀▀ █ █▀▀ █░█ █▀█ █▀▀   █▄▄ █▀▀ █░█ █ █▄░█ █▀▄   ▄▀█   ▀█▀ ▄▀█ █▄▄ █░░ █▀▀ ░   █▀█ █▄░█   ▀█▀ █░█ █▀▀\n");
        printf("\t\t█▀░ █ █▄█ █▄█ █▀▄ ██▄   █▄█ ██▄ █▀█ █ █░▀█ █▄▀   █▀█   ░█░ █▀█ █▄█ █▄▄ ██▄ ▄   █▄█ █░▀█   ░█░ █▀█ ██▄\n\n");

        printf("\t\t▀█▀ ▄▀█ █▄▄ █░░ █▀▀   ▀█▀ █░█ █▀▀ █▀█ █▀▀   ▄▀█ █▀█ █▀▀   ▀█▀ █░█ █▀█ █▀▀ █▀▀   █▀▀ ▄▀█ █▀█ █▀▄ █▀   █▀▀ ▄▀█ █▀▀ █▀▀\n");
        printf("\t\t░█░ █▀█ █▄█ █▄▄ ██▄   ░█░ █▀█ ██▄ █▀▄ ██▄   █▀█ █▀▄ ██▄   ░█░ █▀█ █▀▄ ██▄ ██▄   █▄▄ █▀█ █▀▄ █▄▀ ▄█   █▀░ █▀█ █▄▄ ██▄\n\n");

        printf("\t\t█▀▄ █▀█ █░█░█ █▄░█ ░   █▄█ █▀█ █░█   ▄▀█ █▀█ █▀█ █▀█ █▀█ ▄▀█ █▀▀ █░█   ▄▀█ █▄░█ █▀▄   ▀█▀ ▄▀█ █▄▀ █▀▀   ▄▀█\n");
        printf("\t\t█▄▀ █▄█ ▀▄▀▄▀ █░▀█ ▄   ░█░ █▄█ █▄█   █▀█ █▀▀ █▀▀ █▀▄ █▄█ █▀█ █▄▄ █▀█   █▀█ █░▀█ █▄▀   ░█░ █▀█ █░█ ██▄   █▀█\n\n");

        printf("\t\t█░░ █▀█ █▀█ █▄▀ ░\n");
        printf("\t\t█▄▄ █▄█ █▄█ █░█ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");

        getchar();
        
        struct status tempOUT = tempIN;
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██║████║████║██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\tGambler: If you guess which card has a cross on it, you win a gold.\n\n");
        printf("\t\t\t\t\tGambler: But if you miss, I'll take away 5 of your health.\n\n");
        printf("\t\t\t\t\tGambler: Do you want to play a game?\n\n");
        printf("\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\tSelect an option and then press ENTER!");
        
        char gamblingChoise[STRING_LIMIT];
        for(int i=0; i<STRING_LIMIT; i++)
        {
            gamblingChoise[i] = '\0';
        }
        
                scanf(" ");
                gets(gamblingChoise);
        
                while(  gamblingChoise[1] != '\0' ||
                        gamblingChoise[0] == '\0' ||
                       (gamblingChoise[0] != '1'  &&
                        gamblingChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                gamblingChoise[i] = '\0';
                            }
                            
                                    system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██║████║████║██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\tGambler: If you guess which card has a cross on it, you win.\n\n");
        printf("\t\t\t\t\tGambler: But if you miss, I'll take away 5 of your health.\n\n");
        printf("\t\t\t\t\tGambler: Do you want to play a game?\n\t\t\t\t\t\tInvalid input!\n");
        printf("\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\tSelect an option and then press ENTER!");
                                    scanf(" ");
                                    gets(gamblingChoise);
                    }
                    
        if(gamblingChoise[0] == '1')
    {
gamblingStart:
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██║████║████║██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\tGambler: Pick your card!\n\n");
        printf("\t\t\t\t\tLEFT: 1\t\tMIDDLE: 2\tRIGHT: 3\n\n");
        printf("\t\t\t\t\tSelect an option and then press ENTER!");
        
        char cardChoise[STRING_LIMIT];
        for(int i=0; i<STRING_LIMIT; i++)
        {
            cardChoise[i] = '\0';
        }
                scanf(" ");
                gets(cardChoise);
        
                while(  cardChoise[1] != '\0' ||
                        cardChoise[0] == '\0' ||
                       (cardChoise[0] != '1'  &&
                        cardChoise[0] != '2'  &&
                        cardChoise[0] != '3'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                cardChoise[i] = '\0';
                            }
                                system("clear");
                                printf("\n\n\n");;
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░██║████║████║██░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
                                printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
                                printf("\t\t\t\t\t\tGambler: Pick your card!\n\n");
                                printf("\t\t\t\t\t\tLEFT: 1\tMIDDLE: 2\tRIGHT: 3\n\t\t\t\t\t\tInvalid input!\n");
                                printf("\t\t\t\t\t\tSelect an option and then press ENTER!");
                        scanf(" ");
                        gets(cardChoise);
                    }
        time_t t;
        srand((unsigned)time(&t));
        int randNUM = rand() % (2+1);
        randNUM++;
        if(randNUM == 1)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██┼████─████─██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
            if((cardChoise[0] == '2') || (cardChoise[0] == '3'))
            {
                printf("\t\t\t\t\tGambler: HAHAHA! You didn't win this time!\n\n");
                tempOUT.HP=tempOUT.HP-5;
            }
            if(cardChoise[0] == '1')
            {
                printf("\t\t\t\t\tGambler: You were lucky this time!\n\n");
                tempOUT.inventory[3]++;
            }
        printf("\n\n\t\t\t\t\t\t\tHERO HP: %.2lf\n", tempOUT.HP);
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
                    if(tempOUT.HP <= 0)
                goto gamblingEnd;
        }
        if(randNUM == 2)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██─████┼████─██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
            if((cardChoise[0] == '1') || (cardChoise[0] == '3'))
            {
                printf("\t\t\t\t\tGambler: HAHAHA! You didn't win this time!\n\n");
                tempOUT.HP=tempOUT.HP-5;
                
            }
            if(cardChoise[0] == '2')
            {
                printf("\t\t\t\t\tGambler: You were lucky this time!\n\n");
                tempOUT.inventory[3]++;
            }
        printf("\n\n\t\t\t\t\t\t\tHERO HP: %.2lf\n", tempOUT.HP);
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
            if(tempOUT.HP <= 0)
                goto gamblingEnd;
        }
        if(randNUM == 3)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██─████─████┼██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
            if((cardChoise[0] == '1') || (cardChoise[0] == '2'))
            {
                printf("\t\t\t\t\tGambler: HAHAHA! You didn't win this time!\n\n");
                tempOUT.HP=tempOUT.HP-5;
            }
            if(cardChoise[0] == '3')
            {
                printf("\t\t\t\t\tGambler: You were lucky this time!\n\n");
                tempOUT.inventory[3]++;
            }
        printf("\n\n\t\t\t\t\t\t\tHERO HP: %.2lf\n", tempOUT.HP);
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
                    if(tempOUT.HP <= 0)
                goto gamblingEnd;
        }   
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██║████║████║██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\tGambler: Another round?\n\n");
        printf("\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\tSelect an option and then press ENTER!");
        
        char gamblingChoise2[STRING_LIMIT];
        for(int i=0; i<STRING_LIMIT; i++)
        {
            gamblingChoise2[i] = '\0';
        }
                scanf(" ");
                gets(gamblingChoise2);
        
                while(  gamblingChoise2[1] != '\0' ||
                        gamblingChoise2[0] == '\0' ||
                       (gamblingChoise2[0] != '1'  &&
                        gamblingChoise2[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                gamblingChoise2[i] = '\0';
                            }
                            
                                    system("clear");
                    system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼▒┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██║████║████║██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░███████████████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█░░░░░░░░░░░░░█░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\t\tGambler: Another round?!\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\t\t\t\t\t\t\tInvalid input!\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER!");
                                    scanf(" ");
                                    gets(gamblingChoise2);
                    }
                    
                if(gamblingChoise2[0] == '1')
                    goto gamblingStart;
    }


gamblingEnd:    
            
tempOUT.rounds++;
return tempOUT;
}

struct status shopRound(struct status tempIN)
{
    
        struct status tempOUT = tempIN;
        int firstTime = 1;
        system("clear");
        printf("\n\n\n");
        printf("\t\t█▄█ █▀█ █░█   █░█ █▀▀ ▄▀█ █▀█   █▀ █▀█ █▀▄▀█ █▀▀   █▀▄▀█ █░█ █▀ █ █▀▀  ░█▄█ █▀█ █░█   █░░ █▀█ █▀█ █▄▀   ▄▀█ █▀█ █▀█ █░█ █▄░█ █▀▄\n");
        printf("\t\t░█░ █▄█ █▄█   █▀█ ██▄ █▀█ █▀▄   ▄█ █▄█ █░▀░█ ██▄   █░▀░█ █▄█ ▄█ █ █▄▄ █ ░█░ █▄█ █▄█   █▄▄ █▄█ █▄█ █░█   █▀█ █▀▄ █▄█ █▄█ █░▀█ █▄▀\n\n");

        printf("\t\t▄▀█ █▄░█ █▀▄   █▀ █▀▀ █▀▀   ▄▀█   █▀ █▀▄▀█ ▄▀█ █░░ █░░   █▄▄ █░█ █ █░░ █▀▄ █ █▄░█ █▀▀   █░█░█ █ ▀█▀ █░█\n");
        printf("\t\t█▀█ █░▀█ █▄▀   ▄█ ██▄ ██▄   █▀█   ▄█ █░▀░█ █▀█ █▄▄ █▄▄   █▄█ █▄█ █ █▄▄ █▄▀ █ █░▀█ █▄█   ▀▄▀▄▀ █ ░█░ █▀█\n\n");

        printf("\t\t█░░ █ █▀▀ █░█ ▀█▀   █▀ █░█ █ █▄░█ █ █▄░█ █▀▀   ▀█▀ █░█ █▀█ █▀█ █░█ █▀▀ █░█   █ ▀█▀ █▀\n");
        printf("\t\t█▄▄ █ █▄█ █▀█ ░█░   ▄█ █▀█ █ █░▀█ █ █░▀█ █▄█   ░█░ █▀█ █▀▄ █▄█ █▄█ █▄█ █▀█   █ ░█░ ▄█\n\n");

        printf("\t\t█░█░█ █ █▄░█ █▀▄ █▀█ █░█░█ █▀ ░   █▄█ █▀█ █░█   ▄▀█ █▀█ █▀█ █▀█ █▀█ ▄▀█ █▀▀ █░█   █ ▀█▀   ▄▀█ █▄░█ █▀▄   █▀▀ █▀█\n");
        printf("\t\t▀▄▀▄▀ █ █░▀█ █▄▀ █▄█ ▀▄▀▄▀ ▄█ ▄   ░█░ █▄█ █▄█   █▀█ █▀▀ █▀▀ █▀▄ █▄█ █▀█ █▄▄ █▀█   █ ░█░   █▀█ █░▀█ █▄▀   █▄█ █▄█\n\n");

        printf("\t\t▀█▀ █░█ █▀█ █▀█ █░█ █▀▀ █░█   ▀█▀ █░█ █▀▀   █▀▄ █▀█ █▀█ █▀█ ░\n");
        printf("\t\t░█░ █▀█ █▀▄ █▄█ █▄█ █▄█ █▀█   ░█░ █▀█ ██▄   █▄▀ █▄█ █▄█ █▀▄ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();
        
shopStart:
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╔═══════════╗░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║┌──┬┐┌┬─┬─┐║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t═══════════╣│──┤└┘│││┼│╠═══════════\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║├──│┌┐│││┌┘║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║└──┴┘└┴─┴┘ ║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╚═══════════╝░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░╔════════════╗░░\n");
        printf("\t\t\t\t\t\t░█▄░▄█░█▄░▄█░░░░░░░║FOOD: 2 GOLD║░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░║SWORD:3 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░░█░░░░░█░░░░░░░░░║DIRT: 1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░██████████░░░█░░░║STONE:1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░███░░░░╚════════════╝░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t███████████████████████████████████\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒┼▒┼▒▒▒▒█▒▒█▒▒▒▒▒▒▒▒────────├──▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n");
        if(firstTime == 1)
        {
        printf("\t\t\t\t\tShopkeeper: Welcome! Don't be scared that I have two heads!\n\n");
        printf("\t\t\t\t\tShopkeeper: You don't have to pay double price for the items.\n\n");
        printf("\t\t\t\t\tShopkeeper: You can see the price list there.\n\n");
        }
        if(firstTime == 0)
        {
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\tShopkeeper: Anything else?\n\n");
        printf("\t\t\t\t\t\n\n");   
        }
        printf("\t\t\t\t\t\t\tYou have %d gold.\n\n",tempOUT.inventory[3]);
        printf("\t\t\t\t\t\t\t\tFOOD: 1\n\n");
        printf("\t\t\t\t\t\t\t\tSWORD:2\n\n");
        printf("\t\t\t\t\t\t\t\tDIRT: 3\n\n");
        printf("\t\t\t\t\t\t\t\tSTONE:4\n\n");
        printf("\t\t\t\t\t\t\t\tEXIT: 5\n\n");
        printf("\t\t\t\t\tSelect an option and then press ENTER: ");
        
        char shopChoise[STRING_LIMIT];
        for(int i=0; i<STRING_LIMIT; i++)
        {
            shopChoise[i] = '\0';
        }
        
                scanf(" ");
                gets(shopChoise);
        
                while(  shopChoise[1] != '\0' ||
                        shopChoise[0] == '\0' ||
                       (shopChoise[0] != '1'  &&
                        shopChoise[0] != '2'  &&
                        shopChoise[0] != '3'  &&
                        shopChoise[0] != '4'  &&
                        shopChoise[0] != '5'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                shopChoise[i] = '\0';
                            }
                            
                                    system("clear");
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╔═══════════╗░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║┌──┬┐┌┬─┬─┐║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t═══════════╣│──┤└┘│││┼│╠═══════════\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║├──│┌┐│││┌┘║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║└──┴┘└┴─┴┘ ║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╚═══════════╝░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░╔════════════╗░░\n");
        printf("\t\t\t\t\t\t░█▄░▄█░█▄░▄█░░░░░░░║FOOD: 2 GOLD║░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░║SWORD:3 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░░█░░░░░█░░░░░░░░░║DIRT: 1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░██████████░░░█░░░║STONE:1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░███░░░░╚════════════╝░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t███████████████████████████████████\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒┼▒┼▒▒▒▒█▒▒█▒▒▒▒▒▒▒▒────────├──▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n");
        if(firstTime == 1)
        {
        printf("\t\t\t\t\tShopkeeper: Welcome! Don't be scared that I have two heads!\n\n");
        printf("\t\t\t\t\tShopkeeper: You don't have to pay double price for the items.\n\n");
        printf("\t\t\t\t\tShopkeeper: You can see the price list there.\n\n");
        }
        if(firstTime == 0)
        {
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\tShopkeeper: Anything else?\n\n");
        printf("\t\t\t\t\t\n\n");   
        }
        printf("\t\t\t\t\t\t\tYou have %d gold.\n\n",tempOUT.inventory[3]);
        printf("\t\t\t\t\t\t\t\tFOOD: 1\n\n");
        printf("\t\t\t\t\t\t\t\tSWORD:2\n\n");
        printf("\t\t\t\t\t\t\t\tDIRT: 3\n\n");
        printf("\t\t\t\t\t\t\t\tSTONE:4\n\n");
        printf("\t\t\t\t\t\t\t\tEXIT: 5\n\t\t\t\t\tInvalid input!\n");
        printf("\t\t\t\t\tSelect an option and then press ENTER: ");
        scanf(" ");
        gets(shopChoise);
        }
                    
        if(shopChoise[0] == '1')
        {
        if(tempOUT.inventory[3] < 2)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╔═══════════╗░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║┌──┬┐┌┬─┬─┐║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t═══════════╣│──┤└┘│││┼│╠═══════════\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║├──│┌┐│││┌┘║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║└──┴┘└┴─┴┘ ║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╚═══════════╝░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░╔════════════╗░░\n");
        printf("\t\t\t\t\t\t░█▄░▄█░█▄░▄█░░░░░░░║FOOD: 2 GOLD║░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░║SWORD:3 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░░█░░░░░█░░░░░░░░░║DIRT: 1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░██████████░░░█░░░║STONE:1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░███░░░░╚════════════╝░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t███████████████████████████████████\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒┼▒┼▒▒▒▒█▒▒█▒▒▒▒▒▒▒▒────────├──▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n");
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\tShopkeeper: You will need more gold for that.\n\n");
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\t\t\tYou have %d gold.\n\n",tempOUT.inventory[3]);
        printf("\t\t\t\t\t\t\t\tFOOD: 1\n\n");
        printf("\t\t\t\t\t\t\t\tSWORD:2\n\n");
        printf("\t\t\t\t\t\t\t\tDIRT: 3\n\n");
        printf("\t\t\t\t\t\t\t\tSTONE:4\n\n");
        printf("\t\t\t\t\t\t\t\tEXIT: 5\n\t\t\t\t\n");
        printf("\t\t\t\t\tPress ENTER to select something else.");
        firstTime = 0;
        getchar();
        goto shopStart;
        }
        
        tempOUT.inventory[3]--;
        tempOUT.inventory[3]--;
        tempOUT.inventory[2]++;
        firstTime = 0;
        goto shopStart;
        
        }
        if(shopChoise[0] == '2')
        {
        if(tempOUT.inventory[3] < 3)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╔═══════════╗░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║┌──┬┐┌┬─┬─┐║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t═══════════╣│──┤└┘│││┼│╠═══════════\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║├──│┌┐│││┌┘║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║└──┴┘└┴─┴┘ ║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╚═══════════╝░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░╔════════════╗░░\n");
        printf("\t\t\t\t\t\t░█▄░▄█░█▄░▄█░░░░░░░║FOOD: 2 GOLD║░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░║SWORD:3 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░░█░░░░░█░░░░░░░░░║DIRT: 1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░██████████░░░█░░░║STONE:1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░███░░░░╚════════════╝░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t███████████████████████████████████\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒┼▒┼▒▒▒▒█▒▒█▒▒▒▒▒▒▒▒────────├──▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n");
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\tShopkeeper: You will need more gold for that.\n\n");
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\t\t\tYou have %d gold.\n\n",tempOUT.inventory[3]);
        printf("\t\t\t\t\t\t\t\tFOOD: 1\n\n");
        printf("\t\t\t\t\t\t\t\tSWORD:2\n\n");
        printf("\t\t\t\t\t\t\t\tDIRT: 3\n\n");
        printf("\t\t\t\t\t\t\t\tSTONE:4\n\n");
        printf("\t\t\t\t\t\t\t\tEXIT: 5\n\n");
        printf("\t\t\t\t\tPress ENTER to select something else.");
        firstTime = 0;
        getchar();
        goto shopStart;
        }
        
        tempOUT.inventory[3]--;
        tempOUT.inventory[3]--;
        tempOUT.inventory[3]--;
        tempOUT.weapons[5]=1;
        firstTime = 0;
        goto shopStart;
        
        }
        if(shopChoise[0] == '3')
        {
        if(tempOUT.inventory[3] < 1)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╔═══════════╗░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║┌──┬┐┌┬─┬─┐║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t═══════════╣│──┤└┘│││┼│╠═══════════\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║├──│┌┐│││┌┘║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║└──┴┘└┴─┴┘ ║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╚═══════════╝░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░╔════════════╗░░\n");
        printf("\t\t\t\t\t\t░█▄░▄█░█▄░▄█░░░░░░░║FOOD: 2 GOLD║░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░║SWORD:3 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░░█░░░░░█░░░░░░░░░║DIRT: 1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░██████████░░░█░░░║STONE:1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░███░░░░╚════════════╝░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t███████████████████████████████████\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒┼▒┼▒▒▒▒█▒▒█▒▒▒▒▒▒▒▒────────├──▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n");
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\tShopkeeper: You will need more gold for that.\n\n");
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\t\t\tYou have %d gold.\n\n",tempOUT.inventory[3]);
        printf("\t\t\t\t\t\t\t\tFOOD: 1\n\n");
        printf("\t\t\t\t\t\t\t\tSWORD:2\n\n");
        printf("\t\t\t\t\t\t\t\tDIRT: 3\n\n");
        printf("\t\t\t\t\t\t\t\tSTONE:4\n\n");
        printf("\t\t\t\t\t\t\t\tEXIT: 5\n\n");
        printf("\t\t\t\t\tPress ENTER to select something else.");
        firstTime = 0;
        getchar();
        goto shopStart;
        }
        
        tempOUT.inventory[3]--;
        tempOUT.inventory[0]++;
        firstTime = 0;
        goto shopStart;
        
        }
        if(shopChoise[0] == '4')
        {
        if(tempOUT.inventory[3] < 1)
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╔═══════════╗░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║┌──┬┐┌┬─┬─┐║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t═══════════╣│──┤└┘│││┼│╠═══════════\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║├──│┌┐│││┌┘║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░║└──┴┘└┴─┴┘ ║░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░╚═══════════╝░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░╔════════════╗░░\n");
        printf("\t\t\t\t\t\t░█▄░▄█░█▄░▄█░░░░░░░║FOOD: 2 GOLD║░░\n");
        printf("\t\t\t\t\t\t░█████░█████░░░░░░░║SWORD:3 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░░█░░░░░█░░░░░░░░░║DIRT: 1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░██████████░░░█░░░║STONE:1 GOLD║░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░███░░░░╚════════════╝░░\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒▒▒▒█░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t███████████████████████████████████\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒┼▒┼▒▒▒▒█▒▒█▒▒▒▒▒▒▒▒────────├──▒▒▒\n");
        printf("\t\t\t\t\t\t▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n");
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\tShopkeeper: You will need more gold for that.\n\n");
        printf("\t\t\t\t\t\n\n");
        printf("\t\t\t\t\t\t\tYou have %d gold.\n\n",tempOUT.inventory[3]);
        printf("\t\t\t\t\t\t\t\tFOOD: 1\n\n");
        printf("\t\t\t\t\t\t\t\tSWORD:2\n\n");
        printf("\t\t\t\t\t\t\t\tDIRT: 3\n\n");
        printf("\t\t\t\t\t\t\t\tSTONE:4\n\n");
        printf("\t\t\t\t\t\t\t\tEXIT: 5\n\n");
        printf("\t\t\t\t\tPress ENTER to select something else.");
        firstTime = 0;
        getchar();
        goto shopStart;
        }
        
        tempOUT.inventory[3]--;
        tempOUT.inventory[1]++;
        firstTime = 0;
        goto shopStart;
        
        }
        if(shopChoise[0] == '5')
        {
            tempOUT.rounds++;
            return tempOUT;
        }
                           
tempOUT.rounds++;
return tempOUT;                                 
}

struct status bigSwordRound(struct status tempIN)
{
        struct status tempOUT = tempIN;

        system("clear");
        printf("\n\n\n");
    
        printf("\t\t█▄█ █▀█ █░█   █▀▀ █▀█ █▀▄▀█ █▀▀   ▀█▀ █▀█   ▄▀█   █▀█ █▀█ █▀▀ █▄▀ █▄█   █▀█ █▀█ ▄▀█ █▀▄ ░   █▄█ █▀█ █░█   █▀ █▀▀ █▀▀\n");
        printf("\t\t░█░ █▄█ █▄█   █▄▄ █▄█ █░▀░█ ██▄   ░█░ █▄█   █▀█   █▀▄ █▄█ █▄▄ █░█ ░█░   █▀▄ █▄█ █▀█ █▄▀ ▄   ░█░ █▄█ █▄█   ▄█ ██▄ ██▄\n\n");

        printf("\t\t▄▀█   ▀█▀ █░█░█ █▀█ ▄▄ █░█ ▄▀█ █▄░█ █▀▄ █▀▀ █▀▄   █▀ █░█░█ █▀█ █▀█ █▀▄   █▀ ▀█▀ █░█ █▀▀ █▄▀   █ █▄░█   ▀█▀ █░█ █▀▀   █░█░█ ▄▀█ █░░ █░░ ░\n");
        printf("\t\t█▀█   ░█░ ▀▄▀▄▀ █▄█ ░░ █▀█ █▀█ █░▀█ █▄▀ ██▄ █▄▀   ▄█ ▀▄▀▄▀ █▄█ █▀▄ █▄▀   ▄█ ░█░ █▄█ █▄▄ █░█   █ █░▀█   ░█░ █▀█ ██▄   ▀▄▀▄▀ █▀█ █▄▄ █▄▄ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();
        
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░╤░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░╟──┼──╢░░░░░░░█░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░███░░░║░░░░░░░████░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░██▒▒█░░░║░░░░░░██▒▒▒█░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒█░░║░░░░░██▒▒▒▒▒█░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█▒▒▒▒▒▒██░║░░░░██▒▒▒▒▒▒▒█░░░░\n");
        printf("\t\t\t\t\t\t░░░░░█░░██▒▒▒▒▒▒▒▒█░║░░░░█▒▒▒▒▒▒▒▒▒█░░░\n");
        printf("\t\t\t\t\t\t░░░░████▒▒▒▒███▒▒▒█░║░░░██▒▒▒▒▒▒▒▒▒▒█░░\n");
        printf("\t\t\t\t\t\t░░░█▒▒█▒▒▒▒████▒▒▒██║████▒▒▒▒▒▒▒▒▒▒▒▒█░\n");
        printf("\t\t\t\t\t\t░░██▒▒██▒▒▒█▒▒█▒▒▒▒▒██▒▒▒▒▒██▒▒▒▒▒▒▒▒▒█\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒██▒▒█▒▒▒█▒▒▒█▒▒▒▒▒█████▒▒▒▒▒▒▒▒█\n");
        printf("\t\t\t\t\t\t░█▒▒▒▒▒▒█▒██▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n");
        printf("\t\t\t\t\t\tAre you trying to pull it out?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER!");
        
        char swordChoise[STRING_LIMIT];
        
                scanf(" ");
                gets(swordChoise);
        
                while(  swordChoise[1] != '\0' ||
                        swordChoise[0] == '\0' ||
                       (swordChoise[0] != '1'  &&
                        swordChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                swordChoise[i] = '\0';
                            }
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░╤░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░╟──┼──╢░░░░░░░█░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░███░░░║░░░░░░░████░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░██▒▒█░░░║░░░░░░██▒▒▒█░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒█░░║░░░░░██▒▒▒▒▒█░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░█▒▒▒▒▒▒██░║░░░░██▒▒▒▒▒▒▒█░░░░\n");
        printf("\t\t\t\t\t\t░░░░░█░░██▒▒▒▒▒▒▒▒█░║░░░░█▒▒▒▒▒▒▒▒▒█░░░\n");
        printf("\t\t\t\t\t\t░░░░████▒▒▒▒███▒▒▒█░║░░░██▒▒▒▒▒▒▒▒▒▒█░░\n");
        printf("\t\t\t\t\t\t░░░█▒▒█▒▒▒▒████▒▒▒██║████▒▒▒▒▒▒▒▒▒▒▒▒█░\n");
        printf("\t\t\t\t\t\t░░██▒▒██▒▒▒█▒▒█▒▒▒▒▒██▒▒▒▒▒██▒▒▒▒▒▒▒▒▒█\n");
        printf("\t\t\t\t\t\t░░█▒▒▒▒██▒▒█▒▒▒█▒▒▒█▒▒▒▒▒█████▒▒▒▒▒▒▒▒█\n");
        printf("\t\t\t\t\t\t░█▒▒▒▒▒▒█▒██▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n");
        printf("\t\t\t\t\t\tAre you trying to pull it out?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER!");
                scanf(" ");
                gets(swordChoise);
                    } 

        if(tempOUT.INT >= 60)
        {
        system("clear");
        printf("\n\n\n");    
        printf("\t\t█▄█ █▀█ █░█   █░█ ▄▀█ █░█ █▀▀   █▀▀ █░░ █▀▀ █░█ █▀▀ █▀█ █░░ █▄█   █▀ █▀█ █▀█ ▀█▀ ▀█▀ █▀▀ █▀▄   █░█░█ █░█ █ █▀▀ █░█\n");
        printf("\t\t░█░ █▄█ █▄█   █▀█ █▀█ ▀▄▀ ██▄   █▄▄ █▄▄ ██▄ ▀▄▀ ██▄ █▀▄ █▄▄ ░█░   ▄█ █▀▀ █▄█ ░█░ ░█░ ██▄ █▄▀   ▀▄▀▄▀ █▀█ █ █▄▄ █▀█\n\n");

        printf("\t\t█▀ ▀█▀ █▀█ █▄░█ █▀▀   █▀▀ ▄▀█ █░█ █▀ █▀▀ █▀▄   ▀█▀ █░█ █▀▀   █▀ █░█░█ █▀█ █▀█ █▀▄   ▀█▀ █▀█   █▀▀ █▀▀ ▀█▀\n");
        printf("\t\t▄█ ░█░ █▄█ █░▀█ ██▄   █▄▄ █▀█ █▄█ ▄█ ██▄ █▄▀   ░█░ █▀█ ██▄   ▄█ ▀▄▀▄▀ █▄█ █▀▄ █▄▀   ░█░ █▄█   █▄█ ██▄ ░█░\n\n");

        printf("\t\t█▀ ▀█▀ █░█ █▀▀ █▄▀ ░   █▄█ █▀█ █░█   █▀▄▀█ █▀█ █░█ █▀▀   ▀█▀ █░█ █▀▀   █▀ ▀█▀ █▀█ █▄░█ █▀▀   ▄▀█ █▄░█ █▀▄\n");
        printf("\t\t▄█ ░█░ █▄█ █▄▄ █░█ ▄   ░█░ █▄█ █▄█   █░▀░█ █▄█ ▀▄▀ ██▄   ░█░ █▀█ ██▄   ▄█ ░█░ █▄█ █░▀█ ██▄   █▀█ █░▀█ █▄▀\n\n");

        printf("\t\t█▀▄ █▀█ ▄▀█ █░█░█   ▀█▀ █░█ █▀▀   █░█░█ █▀▀ ▄▀█ █▀█ █▀█ █▄░█ ░\n");
        printf("\t\t█▄▀ █▀▄ █▀█ ▀▄▀▄▀   ░█░ █▀█ ██▄   ▀▄▀▄▀ ██▄ █▀█ █▀▀ █▄█ █░▀█ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();
        tempOUT.weapons[6] = 1;
        }
        if(tempOUT.INT < 60)
        {
        system("clear");
        printf("\n\n\n");   
        printf("\t\t█▄█ █▀█ █░█   ▀█▀ █▀█ █▄█   █░█ ▄▀█ █▀█ █▀▄ ░   █▄▄ █░█ ▀█▀   █▄█ █▀█ █░█   █▀▀ ▄▀█ █▄░█ ▀ ▀█▀   █▀█ █░█ █░░ █░░\n");
        printf("\t\t░█░ █▄█ █▄█   ░█░ █▀▄ ░█░   █▀█ █▀█ █▀▄ █▄▀ █   █▄█ █▄█ ░█░   ░█░ █▄█ █▄█   █▄▄ █▀█ █░▀█ ░ ░█░   █▀▀ █▄█ █▄▄ █▄▄\n\n");

        printf("\t\t█ ▀█▀   █▀█ █░█ ▀█▀ ░\n");
        printf("\t\t█ ░█░   █▄█ █▄█ ░█░ ▄\n\n\n\n");
        printf("\t\tPress ENTER to continue...");
        getchar();
        }


tempOUT.rounds++;
return tempOUT;
    
}

struct status blessingSTRRound(struct status tempIN)
{
    
        struct status tempOUT = tempIN;

        system("clear");
        printf("\n\n\n");
    
        printf("\t\t█▄█ █▀█ █░█   █░█ █▀▀ ▄▀█ █▀█   ▄▀█   █░█░█ █░█ █ █▀ █▀█ █▀▀ █▀█ █ █▄░█ █▀▀   █▀ █▀█ █░█ █▄░█ █▀▄   ▄▀█ █▀\n");
        printf("\t\t░█░ █▄█ █▄█   █▀█ ██▄ █▀█ █▀▄   █▀█   ▀▄▀▄▀ █▀█ █ ▄█ █▀▀ ██▄ █▀▄ █ █░▀█ █▄█   ▄█ █▄█ █▄█ █░▀█ █▄▀   █▀█ ▄█\n\n");

        printf("\t\t█▄█ █▀█ █░█   █░█░█ ▄▀█ █░░ █▄▀ ░   ▀█▀ █░█ █▀▀   █▀▀ █▀█ █▀▄ █▀   ▄▀█ █▀█ █▀▀   █▀ █ █▀▀ █▄░█ ▄▀█ █░░ █░░ █ █▄░█ █▀▀\n");
        printf("\t\t░█░ █▄█ █▄█   ▀▄▀▄▀ █▀█ █▄▄ █░█ ▄   ░█░ █▀█ ██▄   █▄█ █▄█ █▄▀ ▄█   █▀█ █▀▄ ██▄   ▄█ █ █▄█ █░▀█ █▀█ █▄▄ █▄▄ █ █░▀█ █▄█\n\n");

        printf("\t\t█▄█ █▀█ █░█   █▄▄ █▀▀ █▀▀ ▄▀█ █░█ █▀ █▀▀   ▀█▀ █░█ █▀▀ █▄█   █░█░█ ▄▀█ █▄░█ ▀█▀   ▀█▀ █▀█   █░█ █▀▀ █░░ █▀█\n");
        printf("\t\t░█░ █▄█ █▄█   █▄█ ██▄ █▄▄ █▀█ █▄█ ▄█ ██▄   ░█░ █▀█ ██▄ ░█░   ▀▄▀▄▀ █▀█ █░▀█ ░█░   ░█░ █▄█   █▀█ ██▄ █▄▄ █▀▀\n\n");

        printf("\t\t█▄█ █▀█ █░█ ░   █░░ █▀█ █▀█ █▄▀ █ █▄░█ █▀▀   █▀▀ █▀█ █▀█   ▀█▀ █░█ █▀▀   █▀ █▀█ █░█ █▀█ █▀▀ █▀▀   █▀█ █▀▀\n");
        printf("\t\t░█░ █▄█ █▄█ ▄   █▄▄ █▄█ █▄█ █░█ █ █░▀█ █▄█   █▀░ █▄█ █▀▄   ░█░ █▀█ ██▄   ▄█ █▄█ █▄█ █▀▄ █▄▄ ██▄   █▄█ █▀░\n\n");

        printf("\t\t▀█▀ █░█ █▀▀   █▀ █▀█ █░█ █▄░█ █▀▄ ░   █▄█ █▀█ █░█   █░░ █▀█ █▀█ █▄▀   █▄▄ █▀▀ █░█ █ █▄░█ █▀▄   ▄▀█   █▄▄ █░█ █▀ █░█\n");
        printf("\t\t░█░ █▀█ ██▄   ▄█ █▄█ █▄█ █░▀█ █▄▀ █   ░█░ █▄█ █▄█   █▄▄ █▄█ █▄█ █░█   █▄█ ██▄ █▀█ █ █░▀█ █▄▀   █▀█   █▄█ █▄█ ▄█ █▀█\n\n");

        printf("\t\t▄▀█ █▄░█ █▀▄   █▀ █▀▀ █▀▀   ▄▀█   █▀▄▀█ ▄▀█ █▀█ █▄▄ █░░ █▀▀   █▀ ▀█▀ ▄▀█ ▀█▀ █░█ █▀▀   █░█ █▀█ █░░ █▀▄ █ █▄░█ █▀▀   ▄▀█\n");
        printf("\t\t█▀█ █░▀█ █▄▀   ▄█ ██▄ ██▄   █▀█   █░▀░█ █▀█ █▀▄ █▄█ █▄▄ ██▄   ▄█ ░█░ █▀█ ░█░ █▄█ ██▄   █▀█ █▄█ █▄▄ █▄▀ █ █░▀█ █▄█   █▀█\n\n");

        printf("\t\t█▀▀ █▀█ █▄▄ █░░ █▀▀ ▀█▀ ░\n");
        printf("\t\t█▄█ █▄█ █▄█ █▄▄ ██▄ ░█░ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();
    
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▀░░▒▒░░░▒▒░░▒▒▒░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░▒░░▒▀░▒░░░▒▀░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░▒▒░░░▒░░▒░░▒▒░░░▒░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░▒▒▄░▒░▒░░░░▒░░▒▒░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▒░░▒▒░░░▒▒▄░░▒░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▒░░░▒▒░▄▒░░░░▒░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█████░░▒░░░▒░█████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t█░░░░░░░░░░█▒▒▒▒████████▒▒▒▒█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t█░░░░░░░░░░████▒▒▒▒▒▒▒▒▒▒████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░█████░░░░░░░░████▒▒▒▒████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░█████░░░░░░░█▒▒▒▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t█░░░░░░░░██████████▒▒██░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t███░░░░░░░░░░░░░░░█▒▒█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░██████░░░░░░░░░██▒▒██░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░████████████████████░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\t\tThe liquid in the cup starts to smoulder as you get closer.\n\n");
        printf("\t\t\t\t\t\tDrinking the strange liquid?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER!");
        

        char drinkChoise[STRING_LIMIT];
        
                scanf(" ");
                gets(drinkChoise);
        
                while(  drinkChoise[1] != '\0' ||
                        drinkChoise[0] == '\0' ||
                       (drinkChoise[0] != '1'  &&
                        drinkChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                drinkChoise[i] = '\0';
                            }
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▀░░▒▒░░░▒▒░░▒▒▒░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░▒░░▒▀░▒░░░▒▀░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░▒▒░░░▒░░▒░░▒▒░░░▒░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░▒▒▄░▒░▒░░░░▒░░▒▒░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▒░░▒▒░░░▒▒▄░░▒░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▒░░░▒▒░▄▒░░░░▒░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█████░░▒░░░▒░█████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t█░░░░░░░░░░█▒▒▒▒████████▒▒▒▒█░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t█░░░░░░░░░░████▒▒▒▒▒▒▒▒▒▒████░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░█████░░░░░░░░████▒▒▒▒████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░█████░░░░░░░█▒▒▒▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t█░░░░░░░░██████████▒▒██░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t███░░░░░░░░░░░░░░░█▒▒█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░██████░░░░░░░░░██▒▒██░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░████████████████████░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\t\t\tThe liquid in the cup starts to smoulder as you get closer.\n\n");
        printf("\t\t\t\t\t\tDrinking the strange liquid?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\t\t\t\t\t\t\tInvalid input!\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER!");
        scanf(" ");
        gets(drinkChoise);
                    } 

        if(drinkChoise[0] == '1')
        {
        system("clear");
        printf("\n\n\n");
        printf("\t\t█▄█ █▀█ █░█   █▀█ █░█ █░░ █░░   ▀█▀ █░█ █▀▀   █▀▄ █▀█ █ █▄░█ █▄▀   █▀▄ █▀█ █░█░█ █▄░█   ▄▀█ █▄░█ █▀▄   ▀█▀ █░█ █▀▀\n");
        printf("\t\t░█░ █▄█ █▄█   █▀▀ █▄█ █▄▄ █▄▄   ░█░ █▀█ ██▄   █▄▀ █▀▄ █ █░▀█ █░█   █▄▀ █▄█ ▀▄▀▄▀ █░▀█   █▀█ █░▀█ █▄▀   ░█░ █▀█ ██▄\n\n");

        printf("\t\t█▀█ █▀█ █░█░█ █▀▀ █▀█   █▀▀ █░░ █▀█ █░█░█ █▀   ▀█▀ █▀█   █▀▀ █░█ █▀▀ █▀█ █▄█   █▀█ ▄▀█ █▀█ ▀█▀   █▀█ █▀▀   █▄█ █▀█ █░█ █▀█\n");
        printf("\t\t█▀▀ █▄█ ▀▄▀▄▀ ██▄ █▀▄   █▀░ █▄▄ █▄█ ▀▄▀▄▀ ▄█   ░█░ █▄█   ██▄ ▀▄▀ ██▄ █▀▄ ░█░   █▀▀ █▀█ █▀▄ ░█░   █▄█ █▀░   ░█░ █▄█ █▄█ █▀▄\n\n");

        printf("\t\t█▄▄ █▀█ █▀▄ █▄█ ░\n");
        printf("\t\t█▄█ █▄█ █▄▀ ░█░ ▄\n\n\t\t(+20 STR)\n\n");
        tempOUT.STR=tempOUT.STR+20;
        printf("\t\tPress ENTER to continue...");
        getchar();
        }


tempOUT.rounds++;
return tempOUT;
           
        



}

struct status blessingINTRound(struct status tempIN)
{
    
        struct status tempOUT = tempIN;
        
//riddles and answers
        struct riddle riddle1;
        struct riddle riddle2;
        struct riddle riddle3;
        struct riddle riddle4;
        struct riddle riddle5;
        struct riddle riddle6;
        struct riddle riddle7;
        struct riddle riddle8;
        struct riddle riddle9;
        struct riddle riddle10;
        struct riddle riddleMain;
        int answerLength = 0;
        int goodAnswer = 1;
        char temp1q[] = "I exist in every moment, yet I am never seen. I can stretch infinitely, yet I never change. What am I?";
        char temp2q[] = "I travel across the universe without moving. I have no mass, yet I can illuminate a world. What am I?";
        char temp3q[] = "I unlock the secrets of the universe, yet I am as simple as can be. What am I?";
        char temp4q[] = "I move without legs, I push without arms. I follow you everywhere, but I'm not alive. What am I?";
        char temp5q[] = "I exist in two states at once, until observed. What am I?";
        char temp6q[] = "Born in fire, I dance in the cold void, illuminating the dark. What am I?";
        char temp7q[] = "I am the sound of the universe, a noise that can never be heard. What am I?";
        char temp8q[] = "I am a blue gem spinning in the void, teeming with life in a universe of silence. What am I?";
        char temp9q[] = "I have no beginning and no end, stretching beyond all comprehension, yet I fit within a single thought. What am I?";
        char temp10q[] = "I am the vast emptiness that holds all worlds, a canvas for stars and galaxies. What am I?";
        char temp1a[] = "time";
        char temp2a[] = "light";
        char temp3a[] = "atom";
        char temp4a[] = "gravity";
        char temp5a[] = "electron";
        char temp6a[] = "star";
        char temp7a[] = "silence";
        char temp8a[] = "earth";
        char temp9a[] = "infinity";
        char temp10a[] = "space";
        
        int theRandNumber = rand() % (10 - 0 + 1) + 0;

        theRandNumber++;
        
        for(int i=0; i<STRING_LIMIT; i++)
        {
            riddle1.answer[i] = '\0';
            riddle1.question[i] = '\0';
            riddle2.answer[i] = '\0';
            riddle2.question[i] = '\0';
            riddle3.answer[i] = '\0';
            riddle3.question[i] = '\0';
            riddle4.answer[i] = '\0';
            riddle4.question[i] = '\0';
            riddle5.answer[i] = '\0';
            riddle5.question[i] = '\0';
            riddle6.answer[i] = '\0';
            riddle6.question[i] = '\0';
            riddle7.answer[i] = '\0';
            riddle7.question[i] = '\0';
            riddle8.answer[i] = '\0';
            riddle8.question[i] = '\0';
            riddle9.answer[i] = '\0';
            riddle9.question[i] = '\0';
            riddle10.answer[i] = '\0';
            riddle10.question[i] = '\0';
        }
        for(int i=0; i<strlen(temp1q); i++)
        {
            riddle1.question[i] = temp1q[i];
        }
        for(int i=0; i<strlen(temp1a); i++)
        {
            riddle1.answer[i] = temp1a[i];

        }
        for(int i=0; i<strlen(temp2q); i++)
        {
            riddle2.question[i] = temp2q[i];
        }     
        for(int i=0; i<strlen(temp2a); i++)
        {
            riddle2.answer[i] = temp2a[i];
        }
        for(int i=0; i<strlen(temp3q); i++)
        {
            riddle3.question[i] = temp3q[i];
        }
        for(int i=0; i<strlen(temp3a); i++)
        {
            riddle3.answer[i] = temp3a[i];

        }
        for(int i=0; i<strlen(temp4q); i++)
        {
            riddle4.question[i] = temp4q[i];
        }     
        for(int i=0; i<strlen(temp4a); i++)
        {
            riddle4.answer[i] = temp4a[i];
        }
        for(int i=0; i<strlen(temp5q); i++)
        {
            riddle5.question[i] = temp5q[i];
        }
        for(int i=0; i<strlen(temp5a); i++)
        {
            riddle5.answer[i] = temp5a[i];

        }
        for(int i=0; i<strlen(temp6q); i++)
        {
            riddle6.question[i] = temp6q[i];
        }     
        for(int i=0; i<strlen(temp6a); i++)
        {
            riddle6.answer[i] = temp6a[i];
        }
        for(int i=0; i<strlen(temp7q); i++)
        {
            riddle7.question[i] = temp7q[i];
        }
        for(int i=0; i<strlen(temp7a); i++)
        {
            riddle7.answer[i] = temp7a[i];

        }
        for(int i=0; i<strlen(temp8q); i++)
        {
            riddle8.question[i] = temp8q[i];
        }     
        for(int i=0; i<strlen(temp8a); i++)
        {
            riddle8.answer[i] = temp8a[i];
        }
        for(int i=0; i<strlen(temp9q); i++)
        {
            riddle9.question[i] = temp9q[i];
        }
        for(int i=0; i<strlen(temp9a); i++)
        {
            riddle9.answer[i] = temp9a[i];

        }
        for(int i=0; i<strlen(temp10q); i++)
        {
            riddle10.question[i] = temp10q[i];
        }     
        for(int i=0; i<strlen(temp10a); i++)
        {
            riddle10.answer[i] = temp10a[i];
        }
        
        switch(theRandNumber)
        {
            case 1:
            riddleMain = riddle1;
            answerLength = strlen(riddle1.answer);
            break;
            case 2:
            riddleMain = riddle2;
            answerLength = strlen(riddle2.answer);
            break;
            case 3:
            riddleMain = riddle3;
            answerLength = strlen(riddle3.answer);
            break;
            case 4:
            riddleMain = riddle4;
            answerLength = strlen(riddle4.answer);
            break;
            case 5:
            riddleMain = riddle5;
            answerLength = strlen(riddle5.answer);
            break;
            case 6:
            riddleMain = riddle6;
            answerLength = strlen(riddle6.answer);
            break;
            case 7:
            riddleMain = riddle7;
            answerLength = strlen(riddle7.answer);
            break;
            case 8:
            riddleMain = riddle8;
            answerLength = strlen(riddle8.answer);
            break;
            case 9:
            riddleMain = riddle9;
            answerLength = strlen(riddle9.answer);
            break;
            case 10:
            riddleMain = riddle10;
            answerLength = strlen(riddle10.answer);
            break;
        }

        system("clear");
        printf("\n\n\n");   
        
        printf("\t\t█▄█ █▀█ █░█   █░█░█ █ █░░ █░░   █▄░█ █▀█ ▀█▀ █ █▀▀ █▀▀   ▄▀█   █░█ █░█ █▀▀ █▀▀   █▀▀ █░░ ▄▀█ █▀ █░█   █▀█ █▀▀\n");
        printf("\t\t░█░ █▄█ █▄█   ▀▄▀▄▀ █ █▄▄ █▄▄   █░▀█ █▄█ ░█░ █ █▄▄ ██▄   █▀█   █▀█ █▄█ █▄█ ██▄   █▀░ █▄▄ █▀█ ▄█ █▀█   █▄█ █▀░\n\n");

        printf("\t\t█░░ █ █▀▀ █░█ ▀█▀   █ █▄░█   ▀█▀ █░█ █▀▀   █▀ █▄▀ █▄█ ░   ▀█▀ █░█ █▀▀   █░░ █ █▀▀ █░█ ▀█▀   █ █▀\n");
        printf("\t\t█▄▄ █ █▄█ █▀█ ░█░   █ █░▀█   ░█░ █▀█ ██▄   ▄█ █░█ ░█░ ▄   ░█░ █▀█ ██▄   █▄▄ █ █▄█ █▀█ ░█░   █ ▄█\n\n");

        printf("\t\t▄▀█ █▀█ █▀█ █▀█ █▀█ ▄▀█ █▀▀ █░█ █ █▄░█ █▀▀ ░   ▄▀█ █▄░█ █▀▄   ▄▀█ █▀▀ ▀█▀ █▀▀ █▀█   ▄▀█   █░█░█ █░█ █ █░░ █▀▀\n");
        printf("\t\t█▀█ █▀▀ █▀▀ █▀▄ █▄█ █▀█ █▄▄ █▀█ █ █░▀█ █▄█ █   █▀█ █░▀█ █▄▀   █▀█ █▀░ ░█░ ██▄ █▀▄   █▀█   ▀▄▀▄▀ █▀█ █ █▄▄ ██▄\n\n");

        printf("\t\t▀█▀ █░█ █▀▀   █▀█ █▀█ █░█░█ █▀▀ █▀█   █▀█ █▀▀   ▀█▀ █░█ █▀▀   █░░ █ █▀▀ █░█ ▀█▀   █▄▄ █▀▀ █▀▀ █▀█ █▀▄▀█ █▀▀ █▀\n");
        printf("\t\t░█░ █▀█ ██▄   █▀▀ █▄█ ▀▄▀▄▀ ██▄ █▀▄   █▄█ █▀░   ░█░ █▀█ ██▄   █▄▄ █ █▄█ █▀█ ░█░   █▄█ ██▄ █▄▄ █▄█ █░▀░█ ██▄ ▄█\n\n");

        printf("\t\t█▄▄ █░░ █ █▄░█ █▀▄ █ █▄░█ █▀▀ ░   █▀ █▀█   █▄█ █▀█ █░█   █▀▀ █░░ █▀█ █▀ █▀▀   █▄█ █▀█ █░█ █▀█   █▀▀ █▄█ █▀▀ █▀ ░\n");
        printf("\t\t█▄█ █▄▄ █ █░▀█ █▄▀ █ █░▀█ █▄█ █   ▄█ █▄█   ░█░ █▄█ █▄█   █▄▄ █▄▄ █▄█ ▄█ ██▄   ░█░ █▄█ █▄█ █▀▄   ██▄ ░█░ ██▄ ▄█ ▄\n\n");

        printf("\t\t█▄█ █▀█ █░█   █░█░█ █ █░░ █░░   █▄░█ █▀█ ▀█▀ █ █▀▀ █▀▀   ▄▀█   █▀▄ █▀▀ █▀▀ █▀█ ░\n");
        printf("\t\t░█░ █▄█ █▄█   ▀▄▀▄▀ █ █▄▄ █▄▄   █░▀█ █▄█ ░█░ █ █▄▄ ██▄   █▀█   █▄▀ ██▄ ██▄ █▀▀ █\n\n");

        printf("\t\t█▀▄▀█ █▀█ █▄░█ █▀█ ▀█▀ █▀█ █▄░█ █▀█ █░█ █▀   █▀ █▀█ █░█ █▄░█ █▀▄ ░   ▀█▀ █░█ █▀▀   █░░ █ █▀▀ █░█ ▀█▀   █▀▀ ▄▀█ █▀▄ █▀▀ █▀\n");
        printf("\t\t█░▀░█ █▄█ █░▀█ █▄█ ░█░ █▄█ █░▀█ █▄█ █▄█ ▄█   ▄█ █▄█ █▄█ █░▀█ █▄▀ ▄   ░█░ █▀█ ██▄   █▄▄ █ █▄█ █▀█ ░█░   █▀░ █▀█ █▄▀ ██▄ ▄█\n\n");

        printf("\t\t▄▀█ █▄░█ █▀▄   █▄█ █▀█ █░█   █▀█ █▀█ █▀▀ █▄░█   █▄█ █▀█ █░█ █▀█   █▀▀ █▄█ █▀▀ █▀ ░   █ ▀█▀   █░█░█ ▄▀█ █▀   ▄▀█ █▄░█\n");
        printf("\t\t█▀█ █░▀█ █▄▀   ░█░ █▄█ █▄█   █▄█ █▀▀ ██▄ █░▀█   ░█░ █▄█ █▄█ █▀▄   ██▄ ░█░ ██▄ ▄█ ▄   █ ░█░   ▀▄▀▄▀ █▀█ ▄█   █▀█ █░▀█\n\n");

        printf("\t\t▄▀█ █░░ █ █▀▀ █▄░█   █░█░█ █░█ █▀█   █░░ ▄▀█ █▄░█ █▀▄ █▀▀ █▀▄   █░█ █ █▀   █▀ █▀█ ▄▀█ █▀▀ █▀▀ █▀ █░█ █ █▀█ ░\n");
        printf("\t\t█▀█ █▄▄ █ ██▄ █░▀█   ▀▄▀▄▀ █▀█ █▄█   █▄▄ █▀█ █░▀█ █▄▀ ██▄ █▄▀   █▀█ █ ▄█   ▄█ █▀▀ █▀█ █▄▄ ██▄ ▄█ █▀█ █ █▀▀ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();
        
        system("clear");
        printf("\n\n\n");    
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▐░░░░░░░░░▌░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▌░░░░░░░▐░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░██▒▒▒▒▒▒▒▒▒██░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█▒▒▒▒▒███▒▒▒▒▒█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒█░▄░█▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒█░░░█▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒▒███▒▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█▒▒▒▄▄░▄▄▒▒▒█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒█░▀░█▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▀▀▀▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░░░\n\n\n");
        printf("\t\tALIEN: %s\n\n",riddleMain.question);
        printf("\t\tWrtite your answer: ");
        

        char riddleChoise[STRING_LIMIT];
        
        scanf(" ");
        gets(riddleChoise);
        for(int i = 0; riddleChoise[i]; i++)
            {
            riddleChoise[i] = tolower(riddleChoise[i]);
            }
        for(int i=0; i<answerLength; i++)
        {
            if(riddleMain.answer[i] != riddleChoise[i])
            {
                goodAnswer = 0;

            }
        }

        if(goodAnswer == 0)
        {
        system("clear");
        printf("\n\n\n");    
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▐░░░░░░░░░▌░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▌░░░░░░░▐░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░██▒▒▒▒▒▒▒▒▒██░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█▒▒▒▒▒███▒▒▒▒▒█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒█░▄░█▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒█░░░█▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒▒███▒▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█▒▒▒▄▄░▄▄▒▒▒█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒█░▀░█▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▀▀▀▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░░░\n\n\n");
        printf("\t\tALIEN: Foolish creature! The answer was: %s\n\n",riddleMain.answer);
        printf("\t\tPress ENTER to continue...");
        getchar();
       
        }

        if(goodAnswer == 1)
        {
        system("clear");
        printf("\n\n\n");    
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▐░░░░░░░░░▌░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▌░░░░░░░▐░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░██▒▒▒▒▒▒▒▒▒██░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█▒▒▒▒▒███▒▒▒▒▒█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒█░▄░█▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒█░░░█▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░█▒▒▒▒▒▒███▒▒▒▒▒▒█░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█▒▒▒▄▄░▄▄▒▒▒█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█▒▒█░▀░█▒▒█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█▒▒▀▀▀▒▒█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░█▒▒▒▒▒█░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░█▒▒▒█░░░░░░░░░░░░░░░░░\n\n\n");
        printf("\t\t\t\tALIEN: Surprising, but correct!\n\n");
        printf("\t\t\t\tALIEN: You have proven your knowledge, so I will teach you the secrets of the universe!\n\t\t\t\t(+20 INT)\n");
        printf("\t\t\t\tPress ENTER to continue...");
        getchar();
        tempOUT.INT = tempOUT.INT+20;
        }
tempOUT.rounds++;
return tempOUT;
}

struct status blessingHPRound(struct status tempIN)
{
    struct status tempOUT = tempIN;
    time_t t;
    srand((unsigned)time(&t));
    int theNumber = rand() % (10+1);
    theNumber++;
    int leftGuess = 3;
    int guess = 0;
    char guessChoise[STRING_LIMIT];
    for(int i=0; i<STRING_LIMIT; i++)
        {
            guessChoise[i] = '\0';
        }
        
    
        system("clear");
        printf("\n\n\n");
    
        printf("\t\t█▄█ █▀█ █░█   ▄▀█ █▀█ █▀▀   █░█░█ ▄▀█ █░░ █▄▀ █ █▄░█ █▀▀   █ █▄░█   ▄▀█   █▀█ █░█ █ █▀▀ ▀█▀ ░   █▀▄▀█ █ █▀ ▀█▀ █▄█\n");
        printf("\t\t░█░ █▄█ █▄█   █▀█ █▀▄ ██▄   ▀▄▀▄▀ █▀█ █▄▄ █░█ █ █░▀█ █▄█   █ █░▀█   █▀█   ▀▀█ █▄█ █ ██▄ ░█░ █   █░▀░█ █ ▄█ ░█░ ░█░\n\n");

        printf("\t\t█▀▀ █▀█ █▀█ █▀▀ █▀ ▀█▀   █░█░█ █░█ █▀▀ █▄░█   █▄█ █▀█ █░█   █▀▀ █▀▀ █▀▀ █░░   ▀█▀ █░█ █▀▀   ▄▀█ █ █▀█\n");
        printf("\t\t█▀░ █▄█ █▀▄ ██▄ ▄█ ░█░   ▀▄▀▄▀ █▀█ ██▄ █░▀█   ░█░ █▄█ █▄█   █▀░ ██▄ ██▄ █▄▄   ░█░ █▀█ ██▄   █▀█ █ █▀▄\n\n");

        printf("\t\t█░█ █ █▄▄ █▀█ ▄▀█ ▀█▀ █▀▀ ░   █▄█ █▀█ █░█   █░█ █▀▀ ▄▀█ █▀█   ▄▀█   █░░ █▀█ █░█░█   █▀█ █░█ █▀▄▀█ █▄▄ █░░ █ █▄░█ █▀▀\n");
        printf("\t\t▀▄▀ █ █▄█ █▀▄ █▀█ ░█░ ██▄ ▄   ░█░ █▄█ █▄█   █▀█ ██▄ █▀█ █▀▄   █▀█   █▄▄ █▄█ ▀▄▀▄▀   █▀▄ █▄█ █░▀░█ █▄█ █▄▄ █ █░▀█ █▄█\n\n");

        printf("\t\t█ █▄░█   ▀█▀ █░█ █▀▀   ▀█▀ █▀█ █▀▀ █▀▀ █▀   ▄▀█ █▄░█ █▀▄   ▄▀█   █▀ ▀█▀ █▀█ ▄▀█ █▄░█ █▀▀ █▀▀ ░   █░█░█ ▄▀█ █▀█ █▀▄▀█\n");
        printf("\t\t█ █░▀█   ░█░ █▀█ ██▄   ░█░ █▀▄ ██▄ ██▄ ▄█   █▀█ █░▀█ █▄▀   █▀█   ▄█ ░█░ █▀▄ █▀█ █░▀█ █▄█ ██▄ █   ▀▄▀▄▀ █▀█ █▀▄ █░▀░█\n\n");

        printf("\t\t█░░ █ █▀▀ █░█ ▀█▀   █▀▄ █▀█ ▄▀█ █░█░█ █▀   █▄█ █▀█ █░█ █▀█   ▄▀█ ▀█▀ ▀█▀ █▀▀ █▄░█ ▀█▀ █ █▀█ █▄░█ ░   ▄▀█ █▀\n");
        printf("\t\t█▄▄ █ █▄█ █▀█ ░█░   █▄▀ █▀▄ █▀█ ▀▄▀▄▀ ▄█   ░█░ █▄█ █▄█ █▀▄   █▀█ ░█░ ░█░ ██▄ █░▀█ ░█░ █ █▄█ █░▀█ ▄   █▀█ ▄█\n\n");

        printf("\t\t█▄█ █▀█ █░█   █▀ ▀█▀ █▀▀ █▀█   █▀▀ █░░ █▀█ █▀ █▀▀ █▀█ ░   ▀█▀ █░█ █▀▀   █▀█ █░█ █ █▄░█ █▀   █▀█ █▀▀   ▄▀█ █▄░█\n");
        printf("\t\t░█░ █▄█ █▄█   ▄█ ░█░ ██▄ █▀▀   █▄▄ █▄▄ █▄█ ▄█ ██▄ █▀▄ █   ░█░ █▀█ ██▄   █▀▄ █▄█ █ █░▀█ ▄█   █▄█ █▀░   █▀█ █░▀█\n\n");

        printf("\t\t█▀█ █░░ █▀▄   ▄▀█ █▄▄ ▄▀█ █▄░█ █▀▄ █▀█ █▄░█ █▀▀ █▀▄   ▀█▀ █▀▀ █▀▄▀█ █▀█ █░░ █▀▀   █▀▀ █▀▄▀█ █▀▀ █▀█ █▀▀ █▀▀ ░   █░█░█ █ ▀█▀ █░█\n");
        printf("\t\t█▄█ █▄▄ █▄▀   █▀█ █▄█ █▀█ █░▀█ █▄▀ █▄█ █░▀█ ██▄ █▄▀   ░█░ ██▄ █░▀░█ █▀▀ █▄▄ ██▄   ██▄ █░▀░█ ██▄ █▀▄ █▄█ ██▄ █   ▀▄▀▄▀ █ ░█░ █▀█\n\n");

        printf("\t\t▄▀█   █░█ █░█ █▀▀ █▀▀   █▀▀ █▀█ █░░ █▀▄ █▀▀ █▄░█   █▀▄ █▀█ ▄▀█ █▀▀ █▀█ █▄░█   █▀ █ ▀█▀ ▀█▀ █ █▄░█ █▀▀   █ █▄░█\n");
        printf("\t\t█▀█   █▀█ █▄█ █▄█ ██▄   █▄█ █▄█ █▄▄ █▄▀ ██▄ █░▀█   █▄▀ █▀▄ █▀█ █▄█ █▄█ █░▀█   ▄█ █ ░█░ ░█░ █ █░▀█ █▄█   █ █░▀█\n\n");

        printf("\t\t▀█▀ █░█ █▀▀   █▀▄▀█ █ █▀▄ █▀▄ █░░ █▀▀ ░\n");
        printf("\t\t░█░ █▀█ ██▄   █░▀░█ █ █▄▀ █▄▀ █▄▄ ██▄ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");

        getchar();
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▀░░█▄▄█▌\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░▄██▄▄▄░░░░█\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░▄█▀▀▒▒▒▒▒▒▀█░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░▄▄▄█▀▒▒▒▒▒▒▒▒▒▒▒▒▒█▄\n");
        printf("\t\t\t\t\t\t░░░░░░░░▄█▀▀▀▀▀▀▀▒▒▒▒▒▒▒▒▀▒▒▒▐▒▒▒▒▒▒▐\n");
        printf("\t\t\t\t\t\t░░░░░░░█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░█▀▀█▀▀█▀▀█▀▀█▀▀█▒▒▒▒▒█▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░█▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▄▀▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀██▒▒▒▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░▀▄▒▒▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░▀█▒▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░█▒▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█▒▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▌▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█▒▒▒▒▒▒\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▐▒▒▒▒▒▒\n\n\n");
        printf("\t\t\t\t\t\tDRAGON: Greetings! I haven't seen anyone around here for a long time.\n\n");
        printf("\t\t\t\t\t\tDRAGON: You must be running from Dormammu.\n\n");
        printf("\t\t\t\t\t\tDRAGON: You found me in a good mood today.\n\n");
        printf("\t\t\t\t\t\tDRAGON: If you can guess how many thousands of years ago i was born, i'll help you on your way.\n\n");
        printf("\t\t\t\t\t\tDRAGON: I'll help you a little. I'm less than 10.\n\n");
        while(leftGuess > 0)
    {
        printf("\t\t\t\t\t\tDRAGON: You have %d tr%s left.\n\n", leftGuess, leftGuess == 1 ? "y" : "ies");
        printf("\t\t\t\t\t\tYou say: ");

        scanf(" ");
        gets(guessChoise);
        switch(guessChoise[0])
        {
            case '0': 
            guess = 0;
            break;
            case '1': 
            guess = 1;
            break;
            case '2': 
            guess = 2;
            break;
            case '3': 
            guess = 3;
            break;
            case '4': 
            guess = 4;
            break;
            case '5': 
            guess = 5;
            break;
            case '6': 
            guess = 6;
            break;
            case '7': 
            guess = 7;
            break;
            case '8': 
            guess = 8;
            break;
            case '9': 
            guess = 9;
            break;
            default:
            guess = 'a'; 
            break;
        }
        
                while(  leftGuess > 0 && (
                        guessChoise[1] != '\0' ||
                        guessChoise[0] == '\0' ||
                       (guessChoise[0] != '0'  &&
                        guessChoise[0] != '1'  &&
                        guessChoise[0] != '2'  &&
                        guessChoise[0] != '3'  &&
                        guessChoise[0] != '4'  &&
                        guessChoise[0] != '5'  &&
                        guessChoise[0] != '6'  &&
                        guessChoise[0] != '7'  &&
                        guessChoise[0] != '8'  &&
                        guessChoise[0] != '9'   )))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                guessChoise[i] = '\0';
                            }
                            leftGuess--;
                            printf("\n\t\t\t\t\t\tDRAGON: What? Are you stupid? I said less than 10.\n\n");
                            if(leftGuess > 0)
                            printf("\t\t\t\t\t\tDRAGON: You have %d tr%s left.\n\n", leftGuess, leftGuess == 1 ? "y" : "ies");
                                    if(leftGuess > 0)
                                    {
                                        printf("\t\t\t\t\t\tYou say: ");
                                        scanf(" ");
                                        gets(guessChoise);
                                        switch(guessChoise[0])
                                        {
            case '0': 
            guess = 0;
            break;
            case '1': 
            guess = 1;
            break;
            case '2': 
            guess = 2;
            break;
            case '3': 
            guess = 3;
            break;
            case '4': 
            guess = 4;
            break;
            case '5': 
            guess = 5;
            break;
            case '6': 
            guess = 6;
            break;
            case '7': 
            guess = 7;
            break;
            case '8': 
            guess = 8;
            break;
            case '9': 
            guess = 9;
            break;
            default:
            guess = 'a'; 
            break;
        }
        

                                    }
                                    if(leftGuess < 1)
                                    {
                                    goto endLabel;
                                    }

                     }
                    
        if(guess == theNumber)
        {
            printf("\n\t\t\t\t\t\tDRAGON: Congratulations! You guessed it!\n\n\t\t\t\t\t\t(+20 maxHP, +20 HP)\n\n");

            tempOUT.maxHP=tempOUT.maxHP+20;
            tempOUT.HP=tempOUT.HP+20;

            goto endLabel;
        }
        
        if(leftGuess<1)
        {

            goto endLabel;
        }
        else if(guess > theNumber)
        {
            printf("\n\t\t\t\t\t\tDRAGON: Wrong. I'm younger than that.\n\n");
        }
        else if(guess < theNumber)
        {
            printf("\n\t\t\t\t\t\tDRAGON: Wrong. I'm older than that.\n\n");                
        }
    
        leftGuess--;
    }

    
            
endLabel:      
if(leftGuess < 1)
printf("\t\t\t\t\t\tDRAGON: You have no tries left.\n\n");
printf("\t\t\t\t\t\tPress ENTER to continue...");
getchar();
tempOUT.rounds++;
return tempOUT;
}

struct status blessingAGIRound(struct status tempIN)
{
    
        struct status tempOUT = tempIN;
        system("clear");
        printf("\n\n\n");
        printf("\t\t█▄█ █▀█ █░█   █▀▀ █▀█ █▀▄▀█ █▀▀   ▀█▀ █▀█   ▄▀█   █░░ █▀█ █▄░█ █▀▀   █░█░█ █ █▄░█ █▀▄ █ █▄░█ █▀▀   █▀█ █▀█ ▄▀█ █▀▄ \n");
        printf("\t\t░█░ █▄█ █▄█   █▄▄ █▄█ █░▀░█ ██▄   ░█░ █▄█   █▀█   █▄▄ █▄█ █░▀█ █▄█   ▀▄▀▄▀ █ █░▀█ █▄▀ █ █░▀█ █▄█   █▀▄ █▄█ █▀█ █▄▀ ▄\n\n");

        printf("\t\t▄▀█ █▀   █▄█ █▀█ █░█   █▀▀ █▀█   ▄▀█ █░░ █▀█ █▄░█ █▀▀   ▀█▀ █░█ █▀▀   █▀█ █▀█ ▄▀█ █▀▄   █▄█ █▀█ █░█   █▀ █▀▀ █▀▀\n");
        printf("\t\t█▀█ ▄█   ░█░ █▄█ █▄█   █▄█ █▄█   █▀█ █▄▄ █▄█ █░▀█ █▄█   ░█░ █▀█ ██▄   █▀▄ █▄█ █▀█ █▄▀   ░█░ █▄█ █▄█   ▄█ ██▄ ██▄\n\n");

        printf("\t\t▄▀█ █▄░█   █▀█ █░░ █▀▄   █▀▄▀█ ▄▀█ █▄░█   █▀ ▀█▀ ▄▀█ █▄░█ █▀▄ █ █▄░█ █▀▀   █▀█ █▄░█   ▀█▀ █░█ █▀▀   █▀ █ █▀▄ █▀▀\n");
        printf("\t\t█▀█ █░▀█   █▄█ █▄▄ █▄▀   █░▀░█ █▀█ █░▀█   ▄█ ░█░ █▀█ █░▀█ █▄▀ █ █░▀█ █▄█   █▄█ █░▀█   ░█░ █▀█ ██▄   ▄█ █ █▄▀ ██▄\n\n");

        printf("\t\t█▀█ █▀▀   ▀█▀ █░█ █▀▀   █▀█ █▀█ ▄▀█ █▀▄ ░\n");
        printf("\t\t█▄█ █▀░   ░█░ █▀█ ██▄   █▀▄ █▄█ █▀█ █▄▀ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();
        
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░████░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░████████████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▐░▄░░▄░▌░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▌░░░░▐░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░████▒▒▒███░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░████░░░░░███▒▒▒▒▒██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░██░░░░░░░█▒▒▒▒▒██░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░█████████▒▒▒▒▒▒██░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░██▒▒▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░██▒▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░██▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░░█▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░░█▒▒▒▒█░░░░░░░░\n\n\n");
        printf("\t\t\t\t\t\tBEGGAR: Give one gold to an old man.\n\n");
        printf("\t\t\t\t\t\tDo you give him gold?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER: ");
        
        char beggarChoise[STRING_LIMIT];
        
                scanf(" ");
                gets(beggarChoise);
        
                while(  beggarChoise[1] != '\0' ||
                        beggarChoise[0] == '\0' ||
                       (beggarChoise[0] != '1'  &&
                        beggarChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                beggarChoise[i] = '\0';
                            }
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░████░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░████████████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▐░▄░░▄░▌░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▌░░░░▐░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░████▒▒▒███░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░████░░░░░███▒▒▒▒▒██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░██░░░░░░░█▒▒▒▒▒██░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░█████████▒▒▒▒▒▒██░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░██▒▒▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░██▒▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░██▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░░█▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░░█▒▒▒▒█░░░░░░░░\n\n\n");
        printf("\t\t\t\t\t\tBEGGAR: Give one gold to an old man.\n\n");
        printf("\t\t\t\t\t\tDo you give him gold?\n\n");
        printf("\t\t\t\t\t\t\tYES: 1\t\tNO:2\n\t\t\t\t\t\tInvalid input!\n");
        printf("\t\t\t\t\t\tSelect an option and then press ENTER: ");
        
        scanf(" ");
        gets(beggarChoise);
                    } 

        if(beggarChoise[0] == '1')
        {
            if(tempOUT.inventory[3] <= 0)
            {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░████░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░████████████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▐░▄░░▄░▌░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▌░░░░▐░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░████▒▒▒███░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░████░░░░░███▒▒▒▒▒██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░██░░░░░░░█▒▒▒▒▒██░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░█████████▒▒▒▒▒▒██░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░██▒▒▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░██▒▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░██▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░░█▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░░█▒▒▒▒█░░░░░░░░\n\n\n");
        printf("\t\t\t\t\t\t\n\n");
        printf("\t\t\t\t\t\t\n\n");
        printf("\t\t\t\t\t\tYou don't have gold.\n\n");
        
        printf("\t\t\t\t\t\tPress ENTER to continue...");
        getchar();
            }
        
        
            if(tempOUT.inventory[3] > 0)
            {
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░████░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░████████████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░▐░▄░░▄░▌░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▌░░░░▐░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░████▒▒▒███░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░████░░░░░███▒▒▒▒▒██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░██░░░░░░░█▒▒▒▒▒██░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░█████████▒▒▒▒▒▒██░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░██▒▒▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░██▒▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░██▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░░█▒▒▒▒█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░░░░░░░░░░░░░█▒▒▒▒█░░░░░░░░\n\n\n");
        printf("\t\t\tGOD OF SWIFTNESS: Thank you for your graciousness.\n\n");
        printf("\t\t\tGOD OF SWIFTNESS: It's unbelievable, but I was also captivated by Dormammu.\n\n");
        printf("\t\t\tGOD OF SWIFTNESS: As the god of swiftness, I was the only one who could escape from its grasp.\n\n");
        printf("\t\t\tGOD OF SWIFTNESS: It happened a thousand years ago. I've been wandering the world ever since.\n\n");
        printf("\t\t\tGOD OF SWIFTNESS: I've aged over time, but my magic hasn't completely faded.\n\n");
        printf("\t\t\tGOD OF SWIFTNESS: I give you the rest of my powers, use them on your journey\n\n");
        printf("\t\t\t\t\t\t(+20 AGI)\n\n");
        printf("\t\t\t\t\t\tPress ENTER to continue...");
        getchar();
        tempOUT.AGI = tempOUT.AGI+20;
            }
        }

tempOUT.rounds++;
return tempOUT;
}

/*
struct status curseSTRRound(struct status tempIN)
{
    
}
struct status curseINTRound(struct status tempIN)
{
    
}
struct status curseHPRound(struct status tempIN)
{
    
}
struct status curseAGIRound(struct status tempIN)
{
    
}

*/

/*
struct status memoryRound(struct status tempIN)
struct status reactionRound(struct status tempIN)
struct status trapRound(struct status tempIN)
struct status guessNumberRound(struct status tempIN)
*/


int main()
{
//Menü kirajzolása és bemenet kérés, majd ellenőrzés

menu:
	displayMenu(0); 
    char menuChoise[STRING_LIMIT];
    
    scanf(" ");
    gets(menuChoise);
    while(      menuChoise[1] != '\0' ||
                menuChoise[0] == '\0' ||
               (menuChoise[0] != '1'  &&
                menuChoise[0] != '2'  &&
                menuChoise[0] != '3'  &&
                menuChoise[0] != '4'  ))
            {
                for(int i=0; i<STRING_LIMIT; i++)
                {
                    menuChoise[i] = '\0';
                }
                displayMenu(1);        
                scanf(" ");
                gets(menuChoise);
            }
//RULES
    if(menuChoise[0] == '1')
    {
          system("clear");
		printf("\n\t\t\t██████╗░██╗░██████╗░██╗████████╗░█████╗░██╗░░░░░  ███╗░░██╗░█████╗░███╗░░░███╗░█████╗░██████╗░\n");
		  printf("\t\t\t██╔══██╗██║██╔════╝░██║╚══██╔══╝██╔══██╗██║░░░░░  ████╗░██║██╔══██╗████╗░████║██╔══██╗██╔══██╗\n");
		  printf("\t\t\t██║░░██║██║██║░░██╗░██║░░░██║░░░███████║██║░░░░░  ██╔██╗██║██║░░██║██╔████╔██║███████║██║░░██║\n");
		  printf("\t\t\t██║░░██║██║██║░░╚██╗██║░░░██║░░░██╔══██║██║░░░░░  ██║╚████║██║░░██║██║╚██╔╝██║██╔══██║██║░░██║\n");
		  printf("\t\t\t██████╔╝██║╚██████╔╝██║░░░██║░░░██║░░██║███████╗  ██║░╚███║╚█████╔╝██║░╚═╝░██║██║░░██║██████╔╝\n");
		  printf("\t\t\t╚═════╝░╚═╝░╚═════╝░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ╚═╝░░╚══╝░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░\n\n\n");
        
          printf("\t\t\t\t\t\t\t\t█▀▀█ █──█ █── █▀▀ █▀▀\n");
          printf("\t\t\t\t\t\t\t\t█▄▄▀ █──█ █── █▀▀ ▀▀█\n");
          printf("\t\t\t\t\t\t\t\t▀─▀▀ ─▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀\n\n\n");
        
        
          printf("\t\t\tThe game:\n\n");
          printf("\t\t\tDIGITAL NOMAD is an adventure game where the player will face different challenges.\n");
          printf("\t\t\tThe game consists of 10 rounds. Once the player has successfully completed 9 rounds,\n");
          printf("\t\t\the can fight the main villain in the 10th round. In each round, except for the 10th round,\n");
          printf("\t\t\tthe player has to complete 1 challenge, which can be a combat round, a puzzle, a riddle,\n");
          printf("\t\t\ta reaction game, a gift, a trap, etc. The challenges vary from game to game.\n");
          printf("\t\t\tDuring the game, you can get different items that you can use in challenges.\n");
          printf("\t\t\tThe player wins if they defeat the main villain, but if at any time their health drops to 0 or below, they lose. \n\n\n");
          
          printf("\t\t\tCombat rounds:\n\n");
          printf("\t\t\tDuring the game, when the player engages in combat with an enemy, a combat round begins. In combat,\n");
          printf("\t\t\tthe two sides take turns hitting each other. The player who takes the hit will have their life\n");
          printf("\t\t\treduced by the damage of the hit.  Damage calculation: player's strength * weapon's damage\n\n\n");
          
          printf("\t\t\tThe damage of weapons:\t\t\tList of items:\n\n\n");
          
          printf("\t\t\tSTICK 0.2 DMG\t\t\t\tSTONE: Deals 20 DMG to the enemy.\n");
          printf("\t\t\tSTAFF 0.3 DMG\t\t\t\tDIRT: Reduces the opponent's damage by 2. \n");
          printf("\t\t\tCLUB 0.4 DMG\t\t\t\tFOOD: Heals 20.\n");
          printf("\t\t\tKNIFE 0.5 DMG\t\t\t\tARMOUR: Enemy DMG is reduced. (DMG*0.8) \n");
          printf("\t\t\tMACE 0.6 DMG\t\t\t\tGOLD: You can buy items from the shop. \n");
          printf("\t\t\tSWORD 0.7 DMG\t\t\t\t\n");
          printf("\t\t\tTWO-HANDED SWORD 0.8 DMG\n\n");
          printf("\t\t\tThe character will always use his strongest weapon.\n\n\n");
          
          printf("\t\t\tPress ENTER to get back to MENU!");
          
          getchar();
          goto menu;
          
          
          
        
        
    }
//PLAY
    if(menuChoise[0] == '2')
    {
        characterChoose(0);
        char characterChoise[STRING_LIMIT];
        
        scanf(" ");
        gets(characterChoise);
        
        while(  characterChoise[1] != '\0' ||
                characterChoise[0] == '\0' ||
               (characterChoise[0] != '1'  &&
                characterChoise[0] != '2'  &&
                characterChoise[0] != '3'  &&
                characterChoise[0] != '4'  &&
                characterChoise[0] != '5'  &&
                characterChoise[0] != '6'  ))
            {
                for(int i=0; i<STRING_LIMIT; i++)
                {
                    characterChoise[i] = '\0';
                }
                characterChoose(1);        
                scanf(" ");
                gets(characterChoise);
            }

        struct status gameStatus;
        for(int i=0; i<10; i++)
        {
                gameStatus.inventory[i] = 0;
                gameStatus.weapons[i] = 0;
        }
        
//Kezdeti statok és tárgyak megadása
        switch(characterChoise[0])
        {
        case '1':
        {
                gameStatus.HP = 50;
                gameStatus.maxHP = 50;
                gameStatus.INT = 30;
                gameStatus.STR = 60;
                gameStatus.AGI = 40;
                gameStatus.inventory[3] = 1;
                gameStatus.weapons[3] = 1;
                gameStatus.rounds = 0;
                gameStatus.charFace = 1;
        }
        
        break;
        case '2':
                gameStatus.HP = 40;
                gameStatus.maxHP = 40;
                gameStatus.INT = 65;
                gameStatus.STR = 40;
                gameStatus.AGI = 65;
                gameStatus.inventory[0] = 1;
                gameStatus.weapons[3] = 1;
                gameStatus.rounds = 0;
                gameStatus.charFace = 2;
        break;
        case '3':
                gameStatus.HP = 70;
                gameStatus.maxHP = 70;
                gameStatus.INT = 15;
                gameStatus.STR = 60;
                gameStatus.AGI = 20;
                gameStatus.inventory[0] = 1;
                gameStatus.inventory[1] = 1;
                gameStatus.weapons[0] = 1;
                gameStatus.rounds = 0;
                gameStatus.charFace = 3;
        break;
        case '4':
                gameStatus.HP = 65;
                gameStatus.maxHP = 65;
                gameStatus.INT = 30;
                gameStatus.STR = 55;
                gameStatus.AGI = 30;
                gameStatus.inventory[4] = 1;
                gameStatus.weapons[5] = 1;
                gameStatus.rounds = 0;
                gameStatus.charFace = 4;
        break;
        case '5':
                gameStatus.HP = 40;
                gameStatus.maxHP = 40;
                gameStatus.INT = 85;
                gameStatus.STR = 40;
                gameStatus.AGI = 40;
                gameStatus.inventory[3] = 1;
                gameStatus.weapons[1] = 1;
                gameStatus.rounds = 0;
                gameStatus.charFace = 5;
        break;
        case '6':
                gameStatus.HP = 45;
                gameStatus.maxHP = 45;
                gameStatus.INT = 25;
                gameStatus.STR = 60;
                gameStatus.AGI = 75;
                gameStatus.inventory[0] = 1;
                gameStatus.inventory[2] = 1;
                gameStatus.weapons[0] = 1;
                gameStatus.rounds = 0;
                gameStatus.charFace = 6;
        break;
        }
        
//Kezdő story

        system("clear");
        printf("\n\n\n");
        printf("\t\t▀█▀ █░█ █▀▀   █░█░█ █▀█ █▀█ █░░ █▀▄   █░█ ▄▀█ █▀   ▀█▀ █░█ █▀█ █▄░█ █▀▀ █▀▄   █ █▄░█ █▀ █ █▀▄ █▀▀   █▀█ █░█ ▀█▀ ░\n");
        printf("\t\t░█░ █▀█ ██▄   ▀▄▀▄▀ █▄█ █▀▄ █▄▄ █▄▀   █▀█ █▀█ ▄█   ░█░ █▄█ █▀▄ █░▀█ ██▄ █▄▀   █ █░▀█ ▄█ █ █▄▀ ██▄   █▄█ █▄█ ░█░ ▄\n\n");

        printf("\t\t█▄█ █▀█ █░█   █▀▄ █▀█ █▄░█ ▀ ▀█▀   █░█ █▄░█ █▀▄ █▀▀ █▀█ █▀ ▀█▀ ▄▀█ █▄░█ █▀▄   █░█░█ █░█ ▄▀█ ▀█▀ ▀ █▀\n");
        printf("\t\t░█░ █▄█ █▄█   █▄▀ █▄█ █░▀█ ░ ░█░   █▄█ █░▀█ █▄▀ ██▄ █▀▄ ▄█ ░█░ █▀█ █░▀█ █▄▀   ▀▄▀▄▀ █▀█ █▀█ ░█░ ░ ▄█\n\n");

        printf("\t\t█░█ ▄▀█ █▀█ █▀█ █▀▀ █▄░█ █ █▄░█ █▀▀ ░   █▄█ █▀█ █░█   █▀█ █░█ █▀▀ █▀ ▀█▀ █ █▀█ █▄░█\n");
        printf("\t\t█▀█ █▀█ █▀▀ █▀▀ ██▄ █░▀█ █ █░▀█ █▄█ ▄   ░█░ █▄█ █▄█   ▀▀█ █▄█ ██▄ ▄█ ░█░ █ █▄█ █░▀█\n\n");

        printf("\t\t█▀▀ █░█ █▀▀ █▀█ █▄█ ▀█▀ █░█ █ █▄░█ █▀▀   ▄▀█ █▄░█ █▀▄   █▀▀ █░█ █▀▀ █▀█ █▄█ █▀█ █▄░█ █▀▀ ░   █▀█ █▀▀ █▀█ █▀█ █░░ █▀▀\n");
        printf("\t\t██▄ ▀▄▀ ██▄ █▀▄ ░█░ ░█░ █▀█ █ █░▀█ █▄█   █▀█ █░▀█ █▄▀   ██▄ ▀▄▀ ██▄ █▀▄ ░█░ █▄█ █░▀█ ██▄ ▄   █▀▀ ██▄ █▄█ █▀▀ █▄▄ ██▄\n\n");

        printf("\t\t█░░ █▀█ █▄░█ █▀▀   █▀▀ █▀█ █▀█ █▀▀ █▀█ ▀█▀ ▀█▀ █▀▀ █▄░█   ▀█▀ █░█ █▀▀ █ █▀█   █▀▀ █▀█ █▀▄ █▀ ░   █▀▀ █░█ █▀▀ █▄░█\n");
        printf("\t\t█▄▄ █▄█ █░▀█ █▄█   █▀░ █▄█ █▀▄ █▄█ █▄█ ░█░ ░█░ ██▄ █░▀█   ░█░ █▀█ ██▄ █ █▀▄   █▄█ █▄█ █▄▀ ▄█ ▄   ██▄ ▀▄▀ ██▄ █░▀█\n\n");

        printf("\t\t█ █▄░█   █▄█ █▀█ █░█   ▀█▀ █░█ █▀▀ █▀█ █▀▀   ▄▀█ █▀█ █▀▀   █▀█ █▄░█ █░░ █▄█   █▀▄▀█ █▀▀ █▀▄▀█ █▀█ █▀█ █ █▀▀ █▀   █▀█ █▀▀\n");
        printf("\t\t█ █░▀█   ░█░ █▄█ █▄█   ░█░ █▀█ ██▄ █▀▄ ██▄   █▀█ █▀▄ ██▄   █▄█ █░▀█ █▄▄ ░█░   █░▀░█ ██▄ █░▀░█ █▄█ █▀▄ █ ██▄ ▄█   █▄█ █▀░\n\n");

        printf("\t\t▄▀█   █░░ █▀█ █▄░█ █▀▀   █░░ █▀█ █▀ ▀█▀   ▄▀█ █▀▀ █▀▀ ░   █░█ █▀█ █░░ █▀▄ █ █▄░█ █▀▀   █ █▄░█ ▀█▀ █▀█\n");
        printf("\t\t█▀█   █▄▄ █▄█ █░▀█ █▄█   █▄▄ █▄█ ▄█ ░█░   █▀█ █▄█ ██▄ ▄   █▀█ █▄█ █▄▄ █▄▀ █ █░▀█ █▄█   █ █░▀█ ░█░ █▄█\n\n");

        printf("\t\t▀█▀ █░█ █ █▀   █▀▄▀█ █▀▀ █▀▄▀█ █▀█ █▀█ █▄█ ░   █▄█ █▀█ █░█   █▀▄ █▀▀ █▀▀ █ █▀▄ █▀▀   ▀█▀ █▀█   █▀ █▀▀ █▀▀ █▄▀\n");
        printf("\t\t░█░ █▀█ █ ▄█   █░▀░█ ██▄ █░▀░█ █▄█ █▀▄ ░█░ █   ░█░ █▄█ █▄█   █▄▀ ██▄ █▄▄ █ █▄▀ ██▄   ░█░ █▄█   ▄█ ██▄ ██▄ █░█\n\n");

        printf("\t\t█▀█ █░█ ▀█▀   ▀█▀ █░█ █▀▀   █▀▀ █▀█ █▀▄ █▀ ░   █▄█ █▀█ █░█   █░█░█ █ █░░ █░░   █▀▀ █▀█   ▀█▀ █▀█   ▀█▀ █░█ █▀▀\n");
        printf("\t\t█▄█ █▄█ ░█░   ░█░ █▀█ ██▄   █▄█ █▄█ █▄▀ ▄█ ▄   ░█░ █▄█ █▄█   ▀▄▀▄▀ █ █▄▄ █▄▄   █▄█ █▄█   ░█░ █▄█   ░█░ █▀█ ██▄\n\n");

        printf("\t\t█▀▄▀█ █▀█ █░█ █▄░█ ▀█▀ ▄▀█ █ █▄░█   █▀█ █▀▀   ▀█▀ █░█ █▀▀   █▀▀ █▀█ █▀▄ █▀\n");
        printf("\t\t█░▀░█ █▄█ █▄█ █░▀█ ░█░ █▀█ █ █░▀█   █▄█ █▀░   ░█░ █▀█ ██▄   █▄█ █▄█ █▄▀ ▄█ ▄ ▄ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        
        getchar();
        
        system("clear");
        printf("\n\n\n");
        printf("\t\t█▄█ █▀█ █░█   █▀ ▀█▀ ▄▀█ █▀█ ▀█▀   █▀█ █▄░█   █▄█ █▀█ █░█ █▀█   █░█░█ ▄▀█ █▄█ ░   █▄▄ █░█ ▀█▀\n");
        printf("\t\t░█░ █▄█ █▄█   ▄█ ░█░ █▀█ █▀▄ ░█░   █▄█ █░▀█   ░█░ █▄█ █▄█ █▀▄   ▀▄▀▄▀ █▀█ ░█░ █   █▄█ █▄█ ░█░\n\n");

        printf("\t\t█▀ █░█ █▀▄ █▀▄ █▀▀ █▄░█ █░░ █▄█   █▄█ █▀█ █░█   █▀▀ █▀▀ ▀█▀   ▄▀█   █▀ ▀█▀ █▀█ ▄▀█ █▄░█ █▀▀ █▀▀\n");
        printf("\t\t▄█ █▄█ █▄▀ █▄▀ ██▄ █░▀█ █▄▄ ░█░   ░█░ █▄█ █▄█   █▄█ ██▄ ░█░   █▀█   ▄█ ░█░ █▀▄ █▀█ █░▀█ █▄█ ██▄\n\n");

        printf("\t\t█▀▀ █▀▀ █▀▀ █░░ █ █▄░█ █▀▀ ░   █▀ █▀█ █▀▄▀█ █▀▀ █▀█ █▄░█ █▀▀   █ █▀   █░█░█ ▄▀█ ▀█▀ █▀▀ █░█ █ █▄░█ █▀▀   █▄█ █▀█ █░█ ░\n");
        printf("\t\t█▀░ ██▄ ██▄ █▄▄ █ █░▀█ █▄█ ▄   ▄█ █▄█ █░▀░█ ██▄ █▄█ █░▀█ ██▄   █ ▄█   ▀▄▀▄▀ █▀█ ░█░ █▄▄ █▀█ █ █░▀█ █▄█   ░█░ █▄█ █▄█ ▄\n\n");

        printf("\t\t█▄█ █▀█ █░█   █▀ ▀█▀ █▀█ █▀█   ▄▀█ █▄░█ █▀▄   █░░ █▀█ █▀█ █▄▀   █▄▄ █▀▀ █░█ █ █▄░█ █▀▄   █▄█ █▀█ █░█ ░\n");
        printf("\t\t░█░ █▄█ █▄█   ▄█ ░█░ █▄█ █▀▀   █▀█ █░▀█ █▄▀   █▄▄ █▄█ █▄█ █░█   █▄█ ██▄ █▀█ █ █░▀█ █▄▀   ░█░ █▄█ █▄█ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        
        getchar();
        
        
        
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░█░█░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼░┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▀█▀█▀░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██▀▀▀▀▀░▀▀▀▀▀██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░█░░░░░░░░░░░█░█░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░███████░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░██░░░░░██░░░░░░░░░░░░░\n\n\n");
        
        printf("\t\t\t\tTHE SHAPE: You should not have started. You will die with your world!\n\n");
        printf("\t\t\t\tTHE SHAPE: I'll make sure you don't get lonely on your journey.\n\n");
        printf("\t\t\t\t\t(The shape smiles and then dissapears into smoke.)\n\n\n\n");
        printf("\t\t\t\tPress ENTER to continue...");
        
        getchar();

        system("clear");
        printf("\n\n\n");
        
        printf("\t\t█▄█ █▀█ █░█   █▀▀ █▀█ █▄░█ ▀█▀ █ █▄░█ █░█ █▀▀   █▀█ █▄░█   █▄█ █▀█ █░█ █▀█   █░█░█ ▄▀█ █▄█   █▀▄ █▀▀ █▀ █▀█ █ ▀█▀ █▀▀\n");
        printf("\t\t░█░ █▄█ █▄█   █▄▄ █▄█ █░▀█ ░█░ █ █░▀█ █▄█ ██▄   █▄█ █░▀█   ░█░ █▄█ █▄█ █▀▄   ▀▄▀▄▀ █▀█ ░█░   █▄▀ ██▄ ▄█ █▀▀ █ ░█░ ██▄\n\n");

        printf("\t\t▀█▀ █░█ █▀▀   █▀ █▀▀ ▄▀█ █▀█ █▄█   █▀▀ █ █▀▀ █░█ █▀█ █▀▀\n");
        printf("\t\t░█░ █▀█ ██▄   ▄█ █▄▄ █▀█ █▀▄ ░█░   █▀░ █ █▄█ █▄█ █▀▄ ██▄  ▄ ▄ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        
        getchar();
        
        
        system("clear");
        printf("\n\n\n");
        
        printf("\t\t▄▀█ █▀▀ ▀█▀ █▀▀ █▀█   ▄█ █▀█   █▀▄ ▄▀█ █▄█ █▀   █▀█ █▀▀   █░█░█ ▄▀█ █░░ █▄▀ █ █▄░█ █▀▀ ░   █▄█ █▀█ █░█\n");
        printf("\t\t█▀█ █▀░ ░█░ ██▄ █▀▄   ░█ █▄█   █▄▀ █▀█ ░█░ ▄█   █▄█ █▀░   ▀▄▀▄▀ █▀█ █▄▄ █░█ █ █░▀█ █▄█ █   ░█░ █▄█ █▄█\n\n");

        printf("\t\t▄▀█ █▀█ █▀█ █ █░█ █▀▀   ▄▀█ ▀█▀   ▀█▀ █░█ █▀▀   █▀▄▀█ █▀█ █░█ █▄░█ ▀█▀ ▄▀█ █ █▄░█   █▀█ █▀▀   ▀█▀ █░█ █▀▀\n");
        printf("\t\t█▀█ █▀▄ █▀▄ █ ▀▄▀ ██▄   █▀█ ░█░   ░█░ █▀█ ██▄   █░▀░█ █▄█ █▄█ █░▀█ ░█░ █▀█ █ █░▀█   █▄█ █▀░   ░█░ █▀█ ██▄\n\n");

        printf("\t\t█▀▀ █▀█ █▀▄ █▀ ░   █▄█ █▀█ █░█   █▄░█ █▀█ ▀█▀ █ █▀▀ █▀▀   ▀█▀ █░█ ▄▀█ ▀█▀   ▀█▀ █░█ █▀▀ █▀█ █▀▀   ▄▀█ █▀█ █▀▀\n");
        printf("\t\t█▄█ █▄█ █▄▀ ▄█ ▄   ░█░ █▄█ █▄█   █░▀█ █▄█ ░█░ █ █▄▄ ██▄   ░█░ █▀█ █▀█ ░█░   ░█░ █▀█ ██▄ █▀▄ ██▄   █▀█ █▀▄ ██▄\n\n");

        printf("\t\t█▀▄ █ █▀▀ █▀▀ █▀▀ █▀█ █▀▀ █▄░█ ▀█▀   █▀▀ █▀█ █▀▀ ▄▀█ ▀█▀ █░█ █▀█ █▀▀ █▀   █▀█ █▄░█   ▀█▀ █░█ █▀▀   █▀█ ▄▀█ ▀█▀ █░█\n");
        printf("\t\t█▄▀ █ █▀░ █▀░ ██▄ █▀▄ ██▄ █░▀█ ░█░   █▄▄ █▀▄ ██▄ █▀█ ░█░ █▄█ █▀▄ ██▄ ▄█   █▄█ █░▀█   ░█░ █▀█ ██▄   █▀▀ █▀█ ░█░ █▀█\n\n");

        printf("\t\t▀█▀ █▀█   ▀█▀ █░█ █▀▀   ▀█▀ █▀█ █▀█   █▀█ █▀▀   ▀█▀ █░█ █▀▀   █▀▄▀█ █▀█ █░█ █▄░█ ▀█▀ ▄▀█ █ █▄░█ ░   █▄█ █▀█ █░█\n");
        printf("\t\t░█░ █▄█   ░█░ █▀█ ██▄   ░█░ █▄█ █▀▀   █▄█ █▀░   ░█░ █▀█ ██▄   █░▀░█ █▄█ █▄█ █░▀█ ░█░ █▀█ █ █░▀█ ▄   ░█░ █▄█ █▄█\n\n");

        printf("\t\t█▀▀ █▀▀ ▀█▀   █▀█ █▄░█   ▀█▀ █░█ █▀▀   █▀█ ▄▀█ ▀█▀ █░█   ▄▀█ █▄░█ █▀▄   █▀ ▀█▀ ▄▀█ █▀█ ▀█▀   █░█░█ ▄▀█ █░░ █▄▀ █ █▄░█ █▀▀   █░█ █▀█ \n");
        printf("\t\t█▄█ ██▄ ░█░   █▄█ █░▀█   ░█░ █▀█ ██▄   █▀▀ █▀█ ░█░ █▀█   █▀█ █░▀█ █▄▀   ▄█ ░█░ █▀█ █▀▄ ░█░   ▀▄▀▄▀ █▀█ █▄▄ █░█ █ █░▀█ █▄█   █▄█ █▀▀  ▄ ▄ ▄\n\n\n\n");

        printf("\t\tPress ENTER to continue...");
        
        getchar();
        
        
        gameStatus.rounds++;
        while(gameStatus.HP > 0 && gameStatus.rounds < 10)
    {
        time_t randomTime;
        
        srand((unsigned)time(&randomTime));
        int theRandNum = rand() % (8+1);
        theRandNum++;
        if(gameStatus.rounds == 5)
        {
                gameStatus = shopRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
                goto endRound;
        }
        else if(gameStatus.rounds == 3 || gameStatus.rounds == 6 || gameStatus.rounds == 9 )
        {
                gameStatus = golemRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
                goto endRound;
        }
        
        
        else
        {
            switch(theRandNum)
                {
            case 1:
                gameStatus = blessingHPRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
            break;
            case 2:
                gameStatus = blessingSTRRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
            break;
            case 3:
                gameStatus = blessingINTRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
            break;
            case 4:
                gameStatus = blessingAGIRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
            break;
            case 5:
                gameStatus = treeRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
            break;
            case 6:
                gameStatus = mineRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
            break;
            case 7:
                gameStatus = gamblingRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
            break;
            case 8:
                gameStatus = bigSwordRound(gameStatus);
                gameStatus = endOfRound(gameStatus);
            break;            
        }
endRound:
        }
    }
        
        
        
        if(gameStatus.HP <=0)
        {
            displayGameOver();
            getchar();
            goto menu;
        }
//FőBoss előtti story

        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░█░█░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█████░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█┼░┼█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░█░░░█░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░░▀█▀█▀░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░██▀▀▀▀▀░▀▀▀▀▀██░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░█░█░░░░░░░░░░░█░█░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░█░░█░░░░░░░░░░░█░░█░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░█░░░░░░░░░█░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░█░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░███████░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░█░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t\t░░░░░░░░░░░░░██░░░░░██░░░░░░░░░░░░░\n\n\n");
        
        printf("\t\t\t\tDORMAMMU: What? You again? How did you get this far?\n\n");
        printf("\t\t\t\tDORMAMMU: Anyway, I'm going to destroy you.\n\n");
        printf("\t\t\t\tDORMAMMU: You will die at the hands of the destroyer of worlds, Dormammu.\n\n");
        printf("\t\t\t\tDORMAMMU: Be thankful that your meaningless life is ended by my hand.\n\n");
        
        printf("\t\t\t\tPress ENTER to continue...");
        getchar();
        
//finalBOSS

        
        double dormammuHP = 150;
        double dormammuDMG = 10;
        if(gameStatus.inventory[4] == 1)
        {
            dormammuDMG = dormammuDMG*0.8;
        }
        
        
        if(gameStatus.inventory[0] > 0)
        {
            system("clear");
            printf("\n\n\n");
            printf("\n\n\n");
            printf("\t\t\t\tDo you want to use dirt in the next battle?\n\n");
            printf("\t\t\t\t\t(The enemy will have 2 less damage)\n\n\n");
            printf("\t\t\t\t\tYES: 1\t\tNO:2\n\n");
            printf("\t\t\t\tSelect an option and then press ENTER: ");
        
            char dirtChoise[STRING_LIMIT];
        
            scanf(" ");
            gets(dirtChoise);
        
            while(  dirtChoise[1] != '\0' ||
                    dirtChoise[0] == '\0' ||
                   (dirtChoise[0] != '1'  &&
                    dirtChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                        {
                            dirtChoise[i] = '\0';
                        }
                        
                        system("clear");
                        printf("\n\n\n");
                        printf("\n\n\n");
                        printf("\t\t\t\tDo you want to use dirt in the next battle?\n\n");
                        printf("\t\t\t\t\t(The enemy will have 2 less damage)\n\n\n");
                        printf("\t\t\t\t\tYES: 1\t\tNO:2\n\n");
                        printf("\t\t\t\tSelect an option and then press ENTER: ");
                        scanf(" ");
                        gets(dirtChoise);
                    }
        
        
                if(dirtChoise[0] == '2')
                goto stoneThrow;
        
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
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░█░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        system("clear");
        delay(0.1);
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
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░█░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
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
        printf("\t\t\t\t\t░░░░░░███░░░█░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        system("clear");
        delay(0.1);
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
        printf("\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
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
        printf("\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        dormammuDMG=dormammuDMG-2.0;
        }
        
        
stoneThrow:
        
        
        if(gameStatus.inventory[1] > 0)
        {
            //stone
                system("clear");
                printf("\n\n\n");
                printf("\n\n\n");
                printf("\t\t\t\tDo you want to use a stone in the next battle?\n\n");
                printf("\t\t\t\t\t(Enemy suffers 20 DMG)\n\n\n");
                printf("\t\t\t\t\tYES: 1\t\tNO:2\n\n");
                printf("\t\t\t\tSelect an option and then press ENTER: ");
        
                char stoneChoise[STRING_LIMIT];
        
                scanf(" ");
                gets(stoneChoise);
        
                while(  stoneChoise[1] != '\0' ||
                        stoneChoise[0] == '\0' ||
                       (stoneChoise[0] != '1'  &&
                        stoneChoise[0] != '2'  ))
                    {
                        for(int i=0; i<STRING_LIMIT; i++)
                            {
                                stoneChoise[i] = '\0';
                            }
                system("clear");
                printf("\n\n\n");
                printf("\n\n\n");
                printf("\t\t\t\tDo you want to use a stone in the next battle?\n\n");
                printf("\t\t\t\t\t(Enemy suffers 20 DMG)\n\n\n");       
                printf("\t\t\t\tYES: 1\t\tNO:2\nInvalid input!\n");
                printf("\t\t\t\tSelect an option and then press ENTER: ");
                scanf(" ");
                gets(stoneChoise);
                    } 

      
        if(stoneChoise[0] == '2')
            goto dormammuBattle;
            
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
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░█░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        system("clear");
        delay(0.1);
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
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░█░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
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
        printf("\t\t\t\t\t░░░░░░███░░░█░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        system("clear");
        delay(0.1);
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
        printf("\t\t\t\t\t░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
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
        printf("\t\t\t\t\t░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.1);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        dormammuHP=dormammuHP-20;
        }

double weapon = 0;
dormammuBattle:
        
        
        //alapesetben, ha nincs semmi fegyvere a karakternek 0.1et sebez
         //weapon = a fegyver sebzésének 10szerese
        //ha van fegyvere, akkor a legerősebbet hasznalja mindig
        for(int i=0; i<10; i++)
        {
            if(gameStatus.weapons[i] == 1)
            {
                weapon = i+2.0;
            }
        }
        double heroDMG = gameStatus.STR*(weapon/10.0);
        
        while(gameStatus.HP > 0 && dormammuHP > 0)
        {
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
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
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
        printf("\t\t\t\t\t░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░██░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░██░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
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
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░██░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░██░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.5);
        system("clear");
        dormammuHP = dormammuHP-heroDMG;
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
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███████████░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        if(dormammuHP <= 0.0)
        goto heroKillDormammu;
        delay(0.5);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░╬█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░╬─█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░╬──█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░╬───█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░╬───░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░╬───░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░╬───░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░╬───░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░╬───░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░╬───░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░╬───░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░╬───░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░╬───░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░╬───░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░╬───░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░╬───░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░╬───░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░╬───░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░╬───░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░╬───░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.05);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██╬───░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.15);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██▒░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.15);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██▒░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██▒▒░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██▒░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.15);
        system("clear");
        gameStatus.HP = gameStatus.HP-dormammuDMG;
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░▒░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██▒▒░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██▒▒▒░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██▒▒░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████▒░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.15);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        if(gameStatus.HP <= 0.0)
            goto dormammuKillHero;
        
heroKillDormammu:
        if(dormammuHP <= 0.0)
        {
        //hero győz
        delay(0.15);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.15);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.15);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░▒▒░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░░▒▒░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░▒░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░▒░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        delay(0.15);
        system("clear");
        printf("\n\n\n");
        printf("\t\t\t\t\t\tHERO HP: %.2lf\tDORMAMMU HP: %.2lf\n", gameStatus.HP, dormammuHP);
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░█░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░█░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
        printf("\t\t\t\t\t░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n\n");
        
        printf("\t\t\t\t\tYou defeated Dormammu!\n\n");
        printf("\t\t\t\t\tPress ENTER to continue...");
        getchar();
        
        system("clear");
        printf("\n\n\n");
        printf("\t\t█▄█ █▀█ █░█ █▀█   █░░ ▄▀█ █▀ ▀█▀   █▀ ▀█▀ █▀█ █ █▄▀ █▀▀   █▀ █░█ ▄▀█ ▀█▀ ▀█▀ █▀▀ █▀█ █▀▀ █▀▄\n");
        printf("\t\t░█░ █▄█ █▄█ █▀▄   █▄▄ █▀█ ▄█ ░█░   ▄█ ░█░ █▀▄ █ █░█ ██▄   ▄█ █▀█ █▀█ ░█░ ░█░ ██▄ █▀▄ ██▄ █▄▀\n\n");

        printf("\t\t█▀▄ █▀█ █▀█ █▀▄▀█ ▄▀█ █▀▄▀█ █░█   █ █▄░█ ▀█▀ █▀█   ▀█▀ █ █▄░█ █▄█   █▀█ █ █▀▀ █▀▀ █▀▀ █▀ ░   █▄█ █▀█ █░█\n");
        printf("\t\t█▄▀ █▄█ █▀▄ █░▀░█ █▀█ █░▀░█ █▄█   █ █░▀█ ░█░ █▄█   ░█░ █ █░▀█ ░█░   █▀▀ █ ██▄ █▄▄ ██▄ ▄█ ▄   ░█░ █▄█ █▄█\n\n");

        printf("\t\t█░█░█ ▄▀█ █░░ █▄▀   █▀█ █▄░█   ▄▀█ █▄░█ █▀▄   █▀▀ █▄░█ ▀█▀ █▀▀ █▀█   ▀█▀ █░█ █▀▀   █░█ ▄▀█ █░░ █░░   █▀█ █▀▀   ▀█▀ █░█ █▀▀\n");
        printf("\t\t▀▄▀▄▀ █▀█ █▄▄ █░█   █▄█ █░▀█   █▀█ █░▀█ █▄▀   ██▄ █░▀█ ░█░ ██▄ █▀▄   ░█░ █▀█ ██▄   █▀█ █▀█ █▄▄ █▄▄   █▄█ █▀░   ░█░ █▀█ ██▄\n\n");

        printf("\t\t█▀▀ █▀█ █▀▄ █▀ ░   █▄█ █▀█ █░█   █▀ █▀▀ █▀▀   ▀█▀ █░█ ▄▀█ ▀█▀   ▀█▀ █░█ █▀▀ █▄█   ▄▀█ █▀█ █▀▀\n");
        printf("\t\t█▄█ █▄█ █▄▀ ▄█ ▄   ░█░ █▄█ █▄█   ▄█ ██▄ ██▄   ░█░ █▀█ █▀█ ░█░   ░█░ █▀█ ██▄ ░█░   █▀█ █▀▄ ██▄\n\n");

        printf("\t\t█▀▀ █░█ ▄▀█ █ █▄░█ █▀▀ █▀▄ ░   █▄█ █▀█ █░█   █▀ ▀█▀ █▀█ █ █▄▀ █▀▀   ▄▀█ ▀█▀   ▀█▀ █░█ █▀▀   █▀▀ █░█ ▄▀█ █ █▄░█ █▀\n");
        printf("\t\t█▄▄ █▀█ █▀█ █ █░▀█ ██▄ █▄▀ ▄   ░█░ █▄█ █▄█   ▄█ ░█░ █▀▄ █ █░█ ██▄   █▀█ ░█░   ░█░ █▀█ ██▄   █▄▄ █▀█ █▀█ █ █░▀█ ▄█\n\n");

        printf("\t\t▄▀█ █▄░█ █▀▄   █░░ █ █▄▀ █▀▀   █▀▄ █▀█ █▀█ █▀▄▀█ ▄▀█ █▀▄▀█ █░█ ░   ▀█▀ █░█ █▀▀   █▀▀ █░█ ▄▀█ █ █▄░█ █▀   ▄▀█ █▀█ █▀▀\n");
        printf("\t\t█▀█ █░▀█ █▄▀   █▄▄ █ █░█ ██▄   █▄▀ █▄█ █▀▄ █░▀░█ █▀█ █░▀░█ █▄█ █   ░█░ █▀█ ██▄   █▄▄ █▀█ █▀█ █ █░▀█ ▄█   █▀█ █▀▄ ██▄\n\n");

        printf("\t\t█▀ █░█ ▄▀█ ▀█▀ ▀█▀ █▀▀ █▀█ █▀▀ █▀▄   █▄▄ █▄█   █▄█ █▀█ █░█ █▀█   █▀ ▀█▀ █▀█ █ █▄▀ █▀▀ \n");
        printf("\t\t▄█ █▀█ █▀█ ░█░ ░█░ ██▄ █▀▄ ██▄ █▄▀   █▄█ ░█░   ░█░ █▄█ █▄█ █▀▄   ▄█ ░█░ █▀▄ █ █░█ ██▄ ▄ ▄ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();
        
        system("clear");
        printf("\n\n\n");

        printf("\t\t▀█▀ █░█ █▀▀   █░░ █ █▄▄ █▀▀ █▀█ ▄▀█ ▀█▀ █▀▀ █▀▄   █▀▀ █▀█ █▀▄ █▀   █░█░█ ▄▀█ █░░ █▄▀   █░█ █▀█   ▀█▀ █▀█   █▄█ █▀█ █░█\n");
        printf("\t\t░█░ █▀█ ██▄   █▄▄ █ █▄█ ██▄ █▀▄ █▀█ ░█░ ██▄ █▄▀   █▄█ █▄█ █▄▀ ▄█   ▀▄▀▄▀ █▀█ █▄▄ █░█   █▄█ █▀▀   ░█░ █▄█   ░█░ █▄█ █▄█\n\n");

        printf("\t\t▄▀█ █▄░█ █▀▄   █▀▀ ▄▀█ █▀▀ █░█   █▀█ █▀▀   ▀█▀ █░█ █▀▀ █▀▄▀█   █▄▄ █▀█ █░█░█ █▀   █▄▄ █▀▀ █▀▀ █▀█ █▀█ █▀▀   █▄█ █▀█ █░█ ░\n");
        printf("\t\t█▀█ █░▀█ █▄▀   ██▄ █▀█ █▄▄ █▀█   █▄█ █▀░   ░█░ █▀█ ██▄ █░▀░█   █▄█ █▄█ ▀▄▀▄▀ ▄█   █▄█ ██▄ █▀░ █▄█ █▀▄ ██▄   ░█░ █▄█ █▄█ █\n\n");

        printf("\t\t▀█▀ █░█ █▀▀ █▄░█   ▀█▀ █░█ █▀▀ █▄█   ▀█▀ █▀▀ █░░ █░░   █▄█ █▀█ █░█   █░█ █▀█ █░█░█   ▀█▀ █░█ █▀▀ █▄█   █░█░█ █▀▀ █▀█ █▀▀\n");
        printf("\t\t░█░ █▀█ ██▄ █░▀█   ░█░ █▀█ ██▄ ░█░   ░█░ ██▄ █▄▄ █▄▄   ░█░ █▄█ █▄█   █▀█ █▄█ ▀▄▀▄▀   ░█░ █▀█ ██▄ ░█░   ▀▄▀▄▀ ██▄ █▀▄ ██▄\n\n");

        printf("\t\t▀█▀ ▄▀█ █▄▀ █▀▀ █▄░█   █░█ █▀█ █▀ ▀█▀ ▄▀█ █▀▀ █▀▀   █▄▄ █▄█   █▀▄ █▀█ █▀█ █▀▄▀█ ▄▀█ █▀▄▀█ █▀▄▀█ █░█ ░   ▀█▀ █░█ █▀▀\n");
        printf("\t\t░█░ █▀█ █░█ ██▄ █░▀█   █▀█ █▄█ ▄█ ░█░ █▀█ █▄█ ██▄   █▄█ ░█░   █▄▀ █▄█ █▀▄ █░▀░█ █▀█ █░▀░█ █░▀░█ █▄█ ▄   ░█░ █▀█ ██▄\n\n");

        printf("\t\t█▀▀ █▀█ █▀▄ █▀ ░   █▀▀ █▀█ █▀▀ █▀▀ █▀▄   █▀▀ █▀█ █▀█ █▀▄▀█   ▀█▀ █░█ █▀▀ █ █▀█   █▀█ █▀█ █ █▀ █▀█ █▄░█ ░\n");
        printf("\t\t█▄█ █▄█ █▄▀ ▄█ █   █▀░ █▀▄ ██▄ ██▄ █▄▀   █▀░ █▀▄ █▄█ █░▀░█   ░█░ █▀█ ██▄ █ █▀▄   █▀▀ █▀▄ █ ▄█ █▄█ █░▀█ █\n\n");

        printf("\t\t█▄▄ █▀▀ █▀▀ █ █▄░█   ▀█▀ █▀█   █▄▄ █▀█ █ █▄░█ █▀▀   ▀█▀ █░█ █▀▀ █ █▀█   █░█░█ █▀█ █▀█ █░░ █▀▄   █▄▄ ▄▀█ █▀▀ █▄▀\n");
        printf("\t\t█▄█ ██▄ █▄█ █ █░▀█   ░█░ █▄█   █▄█ █▀▄ █ █░▀█ █▄█   ░█░ █▀█ ██▄ █ █▀▄   ▀▄▀▄▀ █▄█ █▀▄ █▄▄ █▄▀   █▄█ █▀█ █▄▄ █░█\n\n");

        printf("\t\t▀█▀ █▀█   █░░ █ █▀▀ █▀▀ ░\n");
        printf("\t\t░█░ █▄█   █▄▄ █ █▀░ ██▄ ▄\n\n\n\n");
        
        printf("\t\tPress ENTER to continue...");
        getchar();
        
        system("clear");
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t██╗░░░██╗██╗░█████╗░████████╗░█████╗░██████╗░██╗░░░██╗\n");
        printf("\t\t\t\t██║░░░██║██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗╚██╗░██╔╝\n");
        printf("\t\t\t\t╚██╗░██╔╝██║██║░░╚═╝░░░██║░░░██║░░██║██████╔╝░╚████╔╝░\n");
        printf("\t\t\t\t░╚████╔╝░██║██║░░██╗░░░██║░░░██║░░██║██╔══██╗░░╚██╔╝░░\n");
        printf("\t\t\t\t░░╚██╔╝░░██║╚█████╔╝░░░██║░░░╚█████╔╝██║░░██║░░░██║░░░\n");
        printf("\t\t\t\t░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░\n\n\n\n");
        printf("\t\t\t\tPress ENTER to get back to MENU!");
        getchar();
        goto menu;
        
        }
        
        //dormammu győz
dormammuKillHero:
        if(gameStatus.HP <= 0.0)
        {
        delay(0.15);
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
        displayGameOver();
        getchar();
        goto menu;
        
        }

        
        }
        
    
    }






//SETTINGS
    if(menuChoise[0] == '3')
    {
        system("clear");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t▄\n");
        printf("Zoom in (ctrl+scroll) until the square in the top right corner just disappears from the screen, then press ENTER!\n");
        getchar();
        goto menu;
    }
//QUIT GAME
    if(menuChoise[0] == '4')
    {
        return 0;
    }
    

}

