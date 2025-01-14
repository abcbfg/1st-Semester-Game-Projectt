#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
// definition of colors
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define YELLOW 6
#define RESET 7

using namespace std;

const int WIDTH = 100; // Maze width
const int HEIGHT = 51; // Maze height
char maze[HEIGHT][WIDTH + 1] = {






    "####################################################################################################",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#   *               *                                  *                          *                #",
    "#              *          *          *        *                *         (!)                       #",
    "#                                *  ||                  *          *   ||             *            #",
    "#      *            (*)             ||  *         *                    ||                          #",
    "#                             *     ||                                 ||   *     *       *        #",
    "#                                             *                                                    #",
    "#                                                        (@)                *                      #",
    "#       *                                                                            *             #",
    "#                          *                                                 *                     #",
    "#   (*)         *                               *                                   (^)            #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#           *     ||       *            *           *             ||    *              *           #",
    "#                 ||                                              ||                               #",
    "#     (*)                           *                      *         (@)                           #",
    "#           *                                                                       *              #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#        *        ||             *                        *                  *        *            #",
    "#                 ||                                                                               #",
    "#           *              *            *           *                  *              *            #",
    "#                                                                                                  #",
    "#     (*)                           *      *            *                                          #",
    "#           *                                                     ||                *              #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "#                                                                                                  #",
    "####################################################################################################"
    
    
     
    
    };

// Player coordinates
int pX = 3, pY = 46; // Initial player position

// Enemy coordinates
int eX = 32, eY = 2;
int e2X = 24, e2Y = 2;
int e3X = 9, e3Y = 2;

// Game state variables
int score = 0;
int health = 5;

// Function prototypes
void clearGameInfo();
bool checkEnemyCollision();
void displayGameInfo();
void collectItems();
void printMazeAndInfo();
void displayGameTitle();
void gotoxy(int x, int y);
void printPlayer();
void removePlayer();
void movePlayerUp();
void movePlayerDown();
void movePlayerLeft();
void movePlayerRight();
void handleInputPlayers();
void gameInstruction();
void exitGame();
void playGame();
void fireByPlayer();
void fireByEnemy();
void removeEnemy1();
void removeEnemy2();
void removeEnemy3();
void printEnemy1Level0();
void printEnemy2Level0();
void printEnemy3Level0();
void moveEnemy1Level0Forward();
void moveEnemy2Level0Forward();
void moveEnemy3Level0Forward();
void moveEnemy2Level0Backward();
void moveEnemy3Level0Backward();
bool checkWinCondition();
void reverseEnemy1Direction();
void reverseEnemy2Direction();
void reverseEnemy3Direction();

// Menu for selecting game options
int menu(int option)
{
    if (option == 1)
    {
        playGame();
    }
    else if (option == 2)
    {
        gameInstruction();
    }
    else if (option == 3)
    {
        exitGame();
    }
    return 0;
}

int main()
{
    bool gameRunning = true;
    int option;
    while (gameRunning)
    {
        // Display main menu and get player choice
        cout << "1. Start Game" << endl;
        cout << "2. Game Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter option (1-3): ";
        cin >> option;

        switch (option)
        {

        case 1:                 // Start Game
            system("cls");      // Clear screen
            displayGameTitle(); // Show game title and wait for key press
            printMazeAndInfo(); // Print initial maze
            playGame();
            break;

        case 2: // Game Instructions
            gameInstruction();
            break;

        case 3: // Exit
            exitGame();
            gameRunning = false;
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }
    return 0;
}

void exitGame()
{
    cout << "Thanks for playing!" << endl;
    cout << "Exiting game..." << endl;
    exit(0);
}

void gameInstruction()
{
    system("cls");

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11);
    cout << "================================================================================\n\n";
    cout << "\n\n                            GAME INSTRUCTIONS\n";
    cout << "================================================================================\n\n";

    cout << "CONTROLS:\n";
    cout << "- Use Arrow keys to move your character\n";
    cout << "- Press Spacebar to fire\n\n";

    cout << "GAMEPLAY ELEMENTS:\n";
    cout << "1. Player Health:\n";
    cout << "   - Initial health: 5 points\n";
    cout << "   - Health boosters (+5): Collect these to increase your health\n\n";

    cout << "2. Enemies:\n";
    cout << "   - Enemy 1 (*): Deals 1 damage\n";
    cout << "   - Enemy 2 (<): Deals 2 damage\n";
    cout << "   - Enemy 3 (S): Deals 3 damage\n";
    cout << "   - Enemies move in straight lines and reverse direction when hitting obstacles\n\n";

    cout << "3. Scoring:\n";
    cout << "   - Collect stars to increase score (+1 per star)\n";
    cout << "   - Enemies cannot collect stars or boosters\n\n";

    cout << "4. WINNING CONDITIONS:\n";
    cout << "   - Reach the end of the maze\n";
    cout << "   - Maintain score > 20\n";
    cout << "   - Maintain health > 10\n\n";

    SetConsoleTextAttribute(h, 7);
    cout << "\nPress any key to return to menu...";
    _getch();
    system("cls");
}

void printPlayer()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BLUE);

    gotoxy(pY, pX);
    cout << " O ";
    gotoxy(pY, pX + 1); // Fixed vertical alignment
    cout << "/|\\";
    gotoxy(pY, pX + 2);
    cout << "/ \\   oo oo";

    SetConsoleTextAttribute(hConsole, RESET);
}

void removePlayer()
{
    gotoxy(pY, pX);
    cout << "   ";
    gotoxy(pY, pX + 1);
    cout << "   ";
    gotoxy(pY, pX + 2);
    cout << "                ";
}
void movePlayerUp()
{
    if (pX > 1 && maze[pX - 1][pY] != '#')
    {
        removePlayer();
        pX--;
        collectItems(); // New function to handle item collection
        printPlayer();
        displayGameInfo();
    }
}

void movePlayerDown()
{
    if (maze[pX + 1][pY] != '#') // Check if not wall
    {
        removePlayer();
        pX++;

        // Collect items
        if (maze[pX][pY] == '*')
        {
            score += 1;
            maze[pX][pY] = ' ';
        }

        if (maze[pX][pY] == '(' || maze[pX][pY] == ')')
        {
            health += 5;
            maze[pX][pY] = ' ';
        }
        printPlayer();
    }
}

void movePlayerLeft()
{
    if (maze[pX][pY - 1] != '#') // Check if not wall
    {
        removePlayer();
        pY--;

        // Collect items
        if (maze[pX][pY] == '*')
        {
            score += 1;
            maze[pX][pY] = ' ';
        }

        if (maze[pX][pY] == '(' || maze[pX][pY] == ')')
        {
            health += 5;
            maze[pX][pY] = ' ';
        }
        printPlayer();
    }
}

void movePlayerRight()
{
    if (maze[pX][pY + 1] != '#') // Check if not wall
    {
        removePlayer();
        pY++;

        // Collect items
        if (maze[pX][pY] == '*')
        {
            score += 1;
            maze[pX][pY] = ' ';
        }

        if (maze[pX][pY] == '(' || maze[pX][pY] == ')')
        {
            health += 5;
            maze[pX][pY] = ' ';
        }
        printPlayer();
    }
}

void handleInputPlayers()
{
    if (GetAsyncKeyState(VK_LEFT))
    {
        if (pY > 1 && maze[pX][pY - 1] != '#')
        {
            removePlayer();
            pY--;
            collectItems(); // Check for items after movement
            printPlayer();
        }
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        if (pY < WIDTH - 2 && maze[pX][pY + 1] != '#')
        {
            removePlayer();
            pY++;
            collectItems(); // Check for items after movement
            printPlayer();
        }
    }
    else if (GetAsyncKeyState(VK_UP))
    {
        if (pX > 1 && maze[pX - 1][pY] != '#')
        {
            removePlayer();
            pX--;
            collectItems(); // Check for items after movement
            printPlayer();
        }
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        if (pX < HEIGHT - 2 && maze[pX + 1][pY] != '#')
        {
            removePlayer();
            pX++;
            collectItems(); // Check for items after movement
            printPlayer();
        }
    }
}

// Enemy printing and movement functions will be similar to player functions
void printEnemy1Level0()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, RED);

    removeEnemy1();

    gotoxy(eY, eX);   // Corrected: gotoxy(x, y) where x = eY (horizontal), y = eX (vertical)
    cout << "  44  "; // Head
    gotoxy(eY, eX + 1);
    cout << "  /|\\  "; // Upper body
    gotoxy(eY, eX + 2);
    cout << " //|\\  >> >> "; // Lower body

    SetConsoleTextAttribute(hConsole, RESET);
}

void removeEnemy1()
{
    gotoxy(eY, eX);    // Corrected: gotoxy(x, y) where x = eY (horizontal), y = eX (vertical)
    cout << "       "; // Clear head line
    gotoxy(eY, eX + 1);
    cout << "       "; // Clear upper body line
    gotoxy(eY, eX + 2);
    cout << "       "; // Clear lower body line
}
void printEnemy2Level0()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, YELLOW);

    removeEnemy2();

    gotoxy(e2Y, e2X); // Corrected: gotoxy(x, y) where x = eY (horizontal), y = eX (vertical)
    cout << "  44  "; // Head
    gotoxy(e2Y, e2X + 1);
    cout << "  /|\\  "; // Upper body
    gotoxy(e2Y, e2X + 2);
    cout << " //|\\  >> >> "; // Lower body

    SetConsoleTextAttribute(hConsole, RESET);
}

void removeEnemy2()
{
    gotoxy(e2Y, e2X);  // Corrected: gotoxy(x, y) where x = eY (horizontal), y = eX (vertical)
    cout << "       "; // Clear head line
    gotoxy(e2Y, e2X + 1);
    cout << "       "; // Clear upper body line
    gotoxy(e2Y, e2X + 2);
    cout << "       "; // Clear lower body line
}
void printEnemy3Level0()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, MAGENTA);

    removeEnemy3();

    gotoxy(e3Y, e3X); // Corrected: gotoxy(x, y) where x = eY (horizontal), y = eX (vertical)
    cout << "  44  "; // Head
    gotoxy(e3Y, e3X + 1);
    cout << "  /|\\  "; // Upper body
    gotoxy(e3Y, e3X + 2);
    cout << " //|\\  >> >> "; // Lower body

    SetConsoleTextAttribute(hConsole, RESET);
}

void removeEnemy3()
{
    gotoxy(e3Y, e3X);  // Corrected: gotoxy(x, y) where x = eY (horizontal), y = eX (vertical)
    cout << "       "; // Clear head line
    gotoxy(e3Y, e3X + 1);
    cout << "       "; // Clear upper body line
    gotoxy(e3Y, e3X + 2);
    cout << "       "; // Clear lower body line
}
// Function to print the maze
void printMazeAndInfo()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << maze[i] << endl;
    }
}

void displayGameInfo()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, GREEN);

    // Position the info at the top of the screen
    gotoxy(WIDTH + 5, 2);
    cout << "Score: " << score;
    gotoxy(WIDTH + 5, 3);
    cout << "Health: " << health;

    SetConsoleTextAttribute(hConsole, RESET);
}

void moveEnemy1Level0Forward()
{

    if (eY < WIDTH - 15)
    {
        removeEnemy1();
        eY++; // Move forward
        printEnemy1Level0();
    }
    else
    {
        reverseEnemy1Direction();
    }
}

void reverseEnemy1Direction()
{
    removeEnemy1();
    eY = 5; // Reverse direction
    printEnemy1Level0();
}

void moveEnemy2Level0Forward()
{

    if (e2Y < WIDTH - 15)
    {
        removeEnemy2();
        e2Y++; // Move forward
        printEnemy2Level0();
    }
    else
    {
        reverseEnemy2Direction();
    }
}

void reverseEnemy2Direction()
{
    removeEnemy2();
    e2Y = 5; // Reverse direction
    printEnemy2Level0();
}

void moveEnemy3Level0Forward()
{

    if (e3Y < WIDTH - 15)
    {
        removeEnemy3();
        e3Y++; // Move forward
        printEnemy3Level0();
    }
    else
    {
        reverseEnemy3Direction();
    }
}

void reverseEnemy3Direction()
{
    removeEnemy3();
    e3Y = 5; // Reverse direction
    printEnemy3Level0();
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool checkWinCondition()
{
    if (score >= 20 && health > 10 )
    {
        clearGameInfo();
        displayGameInfo();
        gotoxy(40, 20);
        cout << "★ Congratulations! You won the game! ★";
        return true;
    }
    else if (health <= 0)
    {
        clearGameInfo();
        displayGameInfo();
        gotoxy(40, 20);
        cout << "Game Over! You ran out of health!";
        return true;
    }
    return false;
}

void collectItems()
{
    if (maze[pY][pX] == '*')
    {
        score += 1;
        maze[pY][pX] = ' '; // Remove the collected item
      
        clearGameInfo();

        displayGameInfo();
    }
    else if (maze[pY][pX] == '(' || maze[pY][pX] == ')')
    {
        health += 5;
        maze[pY][pX] = ' ';
        clearGameInfo();
        displayGameInfo();
    }
}


bool checkEnemyCollision()
{
    // Check collision with enemy 1
    if ((pX == eX || pX == eX + 1 || pX == eX + 2) &&
        (pY == eY || pY == eY + 1 || pY == eY + 2))
    {
        health--;
        clearGameInfo();
        displayGameInfo();
        return true;
    }

    // Check collision with enemy 2
    if ((pX == e2X || pX == e2X + 1 || pX == e2X + 2) &&
        (pY == e2Y || pY == e2Y + 1 || pY == e2Y + 2))
    {
        health -= 2;
        clearGameInfo();
        displayGameInfo();
        return true;
    }

    // Check collision with enemy 3
    if ((pX == e3X || pX == e3X + 1 || pX == e3X + 2) &&
        (pY == e3Y || pY == e3Y + 1 || pY == e3Y + 2))
    {
        health -= 3;
        clearGameInfo();
        displayGameInfo();
        return true;
    }

    return false;
}

void clearGameInfo()
{
    gotoxy(WIDTH + 5, 2);
    cout << "                    "; // Clear score line
    gotoxy(WIDTH + 5, 3);
    cout << "                    "; // Clear health line
}

void playGame()
{
    // Initialize game variables
    score = 0;
    health = 5;

    clearGameInfo();
    displayGameInfo();

    bool gameEnded = false;
    while (!gameEnded)
    {
        clearGameInfo();
        displayGameInfo();
        printPlayer();
        handleInputPlayers();

        // Move enemies
        moveEnemy1Level0Forward();
        moveEnemy2Level0Forward();
        moveEnemy3Level0Forward();

        // Check collisions and update score/health
        collectItems();

        if (checkEnemyCollision())
        {
            clearGameInfo();
            displayGameInfo();
        }

        gameEnded = checkWinCondition();
        Sleep(100);
    }

    // Show final score
    gotoxy(WIDTH + 5, 5);
    cout << "Final Score: " << score;
}

void displayGameTitle()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11); // Cyan color

    cout << "\n\n\n";
    cout << "\t\t   ###   #####  #####     ###   #####  #####  ##  ##    ## #####   \n";
    cout << "\t\t  ## ##  ##  #  ##  #    ## ##  ##  #  ##  #  ##  ###   ## ##  #   \n";
    cout << "\t\t ##   ## ##     ##      ##   ## ##     ##     ##  ####  ## ##      \n";
    cout << "\t\t##     ## ###    ###   ##     ## ###    ###   ##  ## ## ##  ###    \n";
    cout << "\t\t#########    ##     ## #########    ##     ## ##  ##  ####     ##  \n";
    cout << "\t\t##     ## #   #  #   # ##     ## #   #  #   # ##  ##   ###  #   #  \n";
    cout << "\t\t##     ##  ###    ###  ##     ##  ###    ###  ##  ##    ##   ###   \n";
    cout << "\n\n";
    
    SetConsoleTextAttribute(h, 14); // Yellow color
    cout << "\t\t\t\t   WELCOME TO THE ASSASSINS PARADOX\n";
    cout << "\t\t\t\t   ==================\n\n";
    
    SetConsoleTextAttribute(h, 10); // Green color
    cout << "\t\t\t\tGet ready for the battle!\n";
    cout << "\t\t\t\tLoading game...\n\n";
    
    SetConsoleTextAttribute(h, 13); // Magenta color
    cout << "\t\t\t\tPress any key to start...";
    
    SetConsoleTextAttribute(h, 7); // Reset to default color
    _getch(); // Wait for key press
    system("cls");
}
void increaseScore()
{
   if (maze[pY][pX] == '*' )
    score++; // Increment the score
    // Clear the previous score display
    gotoxy(0, HEIGHT + 1); // Position below the maze
    cout << "Score: " << score << "   "; // Display updated score
}

