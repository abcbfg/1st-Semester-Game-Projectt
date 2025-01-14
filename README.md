# 1st-Semester-Game-Projectt
Assassins Paradox is a thrilling console-based maze game where players navigate through obstacles, collect items, and avoid enemies to achieve victory. With dynamic gameplay and interactive features, players must strategize to maintain health and score while progressing through the maze.
Assassins Paradox
Features

Player Mechanics:

Movement: Navigate the maze using arrow keys.

Item Collection:

Stars (*): Increases score by 1.

Health Boosters (( or )): Increases health by 5.

Health Management: Initial health is 5 points, and collisions with enemies reduce it.

Win Conditions:

Score > 20.

Health > 10.

Reach the maze's end.

Enemy Dynamics:

Three enemies move in straight lines and reverse direction upon hitting obstacles:

Enemy 1 (*): Reduces health by 1 on collision.

Enemy 2 (<): Reduces health by 2 on collision.

Enemy 3 (S): Reduces health by 3 on collision.

Game Info:

Real-time updates for health and score displayed on the screen.

Color-coded visuals for players, enemies, and items.

How to Play

Launch the game and select an option from the main menu:

1: Start Game.

2: Game Instructions.

3: Exit Game.

Use the arrow keys to move your character (O) through the maze.

Collect stars and health boosters while avoiding enemy collisions.

Reach the maze's end while meeting the winning conditions.

Controls

Arrow Keys: Move the player.

Spacebar: Fire (future feature).

Technical Details

Programming Concepts Used:

Modular Programming: Functions for specific tasks like movement, collision, and score updates.

Dynamic Gameplay: Enemy movement and item collection.

Color and Graphics: Enhanced visuals using SetConsoleTextAttribute and gotoxy() for positioning.

Real-Time Updates: Health and score dynamically displayed.

Code Highlights:

Global Maze Design: Flexible maze stored as a 2D array.

Collision Detection: Ensures players interact correctly with enemies and items.

Menu System: Provides clear navigation for starting the game, reading instructions, and exiting.

Installation & Execution

Prerequisites:

A Windows-based system with a C++ compiler (e.g., GCC, Visual Studio).

Steps:

Compile the code using a C++ compiler.

Run the generated executable file.

Commands:

g++ assassins_paradox.cpp -o assassins_paradox
./assassins_paradox

Future Enhancements

Player Shooting Mechanic: Allow players to fire projectiles at enemies.

Advanced Levels: Introduce more complex mazes with additional obstacles.

Enhanced Enemy AI: Make enemy movement more dynamic and challenging.

Save/Load Feature: Save progress for continued gameplay.

