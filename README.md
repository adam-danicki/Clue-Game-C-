# Clue-Game-C-
# Game Created for UMass Amherst CS 230.
1) How to compile the game
 - In order to compile the game you must be in the folder with all required files, this being "adventure.c", 
   "items.c", "items.h", "room.c", and "room.h". If you are reding this then you are most likely in the correct folder.

 - In order to play the game you must create an executable by using the gcc command. All you have to write is 
    "gcc adventure.c items.c room.c" in the terminal and an executable will be created most likely called a.out.

 - Afterwards all you have to do is type "./a.out" or "./(name of executable)" in orer to get the game running.
   You will know you have done this correctly if the game welcome screen shows up in your terminal.

2) Overview of structure of the game board with pointers
 - As you can see the game is made by creating 9 room struct and pointing them to one another. The image below displayes how 
   the board is theoretically set up. 
                                                    
                                    | 1 || 2 || 3 |
                                    | 4 || 5 || 6 |
                                    | 7 || 8 || 9 |
    
 - The room struct has pointers North, East, West, and South thus each room has pointers to adjacent rooms thus creating the board.
   If there is no room adjacent to the room then the pointer points to NULL or , in the game, a wall. For example room 2 in the
   example above has the pointers as follow, (North = NULL) (East = room 3) (West = room 1) (South = room 5). This allows for easy 
   navigation of the rooms as all that we need to create is a player pointer that points the the current room the player is in.
   Then changing the player pointer to whatever adjacent room they desire to go into.

3) How to manage user input
 - In order to actually play the game, you must first compile and run the created executable as explained in part 1).

 - Once you are on the welcome screen of the game I recommend typing "help" in order to get a list of commands to play the game.

 - All commands are run by one word inputs, meaning that if you desire to "go North", do not type "go north", but rather type "go"
   press enter and then type "North".

 - All commands that you should type in the game will be lowercase. On the other hand all directions, items, and characters you 
   should type starting with an upercase letter.

