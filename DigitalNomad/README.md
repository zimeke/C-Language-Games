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

