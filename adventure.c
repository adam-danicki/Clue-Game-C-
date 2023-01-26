#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "room.h"
#include "items.h"



int main(){
    //Creation of gameboard and setting up all variables. 
    //Includes randomisation and answer choosing.

    //Creation of rooms
    struct Room Room1 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct Room Room2 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct Room Room3 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct Room Room4 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct Room Room5 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct Room Room6 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct Room Room7 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct Room Room8 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    struct Room Room9 = create_new_room(NULL,NULL,NULL,NULL,NULL,NULL,NULL);

    //Location name shuffler
    char* locations[9] = {
        "Kitchen",
        "Ballroom",
        "Conservatory",
        "Billiard",
        "Library",
        "Study",
        "Hall",
        "Lounge",
        "Dining"
    };

    int rooms = 9;
    srand(time(NULL));
    if(rooms > 1){
        int i;
        for(i = 0; i < rooms - 1; i++){
            int k = rand() % 9;

            char* temp = locations[k];
            locations[k] = locations[i];
            locations[i] = temp;

        }
    }

    //Character name shuffler
    char* name_list[9] = {
        "Cole",
        "Charles",
        "Sean",
        "Mickey",
        "Larry",
        NULL,
        NULL,
        NULL,
        NULL
    };

    int names = 9;
    if(names > 1){
        int i;
        for(i = 0; i < names - 1; i++){
            int k = rand() % 9;

            char* temp = name_list[k];
            name_list[k] = name_list[i];
            name_list[i] = temp;

        }
    }

    //Item shuffler
    char* items[9] = {
        "Pipe",
        "Revolver",
        "Knife",
        "Brick",
        "Stick",
        "Shotgun",
        NULL,
        NULL,
        NULL
    };

    int itemNum = 9;
    if(itemNum > 1){
        int i;
        for(i = 0; i < itemNum - 1; i++){
            int k = rand() % 9;

            char* temp = items[k];
            items[k] = items[i];
            items[i] = temp;

        }
    }

    //Assigning answer of clue, no need to randomise again as answere will always be different due to earlier randomisation.
    char* room_answer = locations[0];
    char* character_answer;
    for(int i = 0; i < 9; i++){
        if(name_list[i] != NULL){
            character_answer = name_list[i];
            break;
        }
    }
    char* item_answer;
    for(int i = 0; i < 9; i++){
        if(items[i] != NULL){
            item_answer = items[i];
            break;
        }
    }
 
    //Assigning of room1
    Room1.name = locations[0];
    Room1.North = NULL;
    Room1.South = &Room4;
    Room1.East = &Room2;
    Room1.West = NULL;
    Room1.itemList = NULL;
    if(items[0] != NULL){
        add_item(&Room1.itemList, items[0]);
    }
    Room1.character = NULL;
    if(name_list[0] != NULL){
        add_item(&Room1.character, name_list[0]);
    }

    //Assigning of room2
    Room2.name = locations[1];
    Room2.North = NULL;
    Room2.South = &Room5;
    Room2.East = &Room3;
    Room2.West = &Room1;
    Room2.itemList = NULL;
    if(items[1] != NULL){
        add_item(&Room2.itemList, items[1]);
    }
    Room2.character = NULL;
    if(name_list[1] != NULL){
        add_item(&Room2.character, name_list[1]);
    }

    //Assigning of room3
    Room3.name = locations[2];
    Room3.North = NULL;
    Room3.South = &Room6;
    Room3.East = NULL;
    Room3.West = &Room2;
    Room3.itemList = NULL;
    if(items[2] != NULL){
        add_item(&Room3.itemList, items[2]);
    }
    Room3.character = NULL;
    if(name_list[2] != NULL){
        add_item(&Room3.character, name_list[2]);
    }

    //Assigning of room4
    Room4.name = locations[3];
    Room4.North = &Room1;
    Room4.South = &Room7;
    Room4.East = &Room5;
    Room4.West = NULL;
    Room4.itemList = NULL;
    if(items[3] != NULL){
        add_item(&Room4.itemList, items[3]);
    }
    Room4.character = NULL;
    if(name_list[3] != NULL){
        add_item(&Room4.character, name_list[3]);
    }

    //Assigning of room5
    Room5.name = locations[4];
    Room5.North = &Room2;
    Room5.South = &Room8;
    Room5.East = &Room6;
    Room5.West = &Room4;
    Room5.itemList = NULL;
    if(items[4] != NULL){
        add_item(&Room5.itemList, items[4]);
    }
    Room5.character = NULL;
    if(name_list[4] != NULL){
        add_item(&Room5.character, name_list[4]);
    }

    //Assigning of room6
    Room6.name = locations[5];
    Room6.North = &Room3;
    Room6.South = &Room9;
    Room6.East = NULL;
    Room6.West = &Room5;
    Room6.itemList = NULL;
    if(items[5] != NULL){
        add_item(&Room6.itemList, items[5]);
    }
    Room6.character = NULL;
    if(name_list[5] != NULL){
        add_item(&Room6.character, name_list[5]);
    }

    //Assigning of room7
    Room7.name = locations[6];
    Room7.North = &Room4;
    Room7.South = NULL;
    Room7.East = &Room8;
    Room7.West = NULL;
    Room7.itemList = NULL;
    if(items[6] != NULL){
        add_item(&Room7.itemList, items[6]);
    }
    Room7.character = NULL;
    if(name_list[6] != NULL){
        add_item(&Room7.character, name_list[6]);
    }

    //Assigning of room8
    Room8.name = locations[7];
    Room8.North = &Room5;
    Room8.South = NULL;
    Room8.East = &Room9;
    Room8.West = &Room7;
    Room8.itemList = NULL;
    if(items[7] != NULL){
        add_item(&Room8.itemList, items[7]);
    }
    Room8.character = NULL;
    if(name_list[7] != NULL){
        add_item(&Room8.character, name_list[7]);
    }

    //Assigning of room9
    Room9.name = locations[8];
    Room9.North = &Room6;
    Room9.South = NULL;
    Room9.East = NULL;
    Room9.West = &Room8;
    Room9.itemList = NULL;
    if(items[8] != NULL){
        add_item(&Room9.itemList, items[8]);
    }
    Room9.character = NULL;
    if(name_list[8] != NULL){
        add_item(&Room9.character, name_list[8]);
    }

    //Creating the player
    struct Room *player = &Room5;
    struct Item *inventory = NULL;

    //Title Screen
    printf("________________________________________\n");
    printf("|                                      |\n");
    printf("|          Welcome to Clue!            |\n");
    printf("|          by Adam Danicki             |\n");
    printf("|  Write help for a list of commands!  |\n");
    printf("|______________________________________|\n");
    
    int clue_attempts = 0;

    //Actual game mechanics and commands
    while(clue_attempts < 10 ){
        //command receiver
        char *commander = malloc(sizeof(char) * ( 20 ));
        printf("|~ ");
        scanf("%s", commander);

        //help input
        if(strcmp(commander, "help") == 0){
            printf("\n");
            printf("                                                            Helper here!\n");
            printf("                                       Here to tell you all about the commands used in my game!\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("list           - allows the player to list the items, rooms, and characters in the game.\n\n");
            printf("look           - allows the player to see what room they are in, including adjacent rooms, and items and characters in the current room.\n\n");
            printf("go             - after inputing go, allows the player to move through rooms using the north, east, south, and west directions.\n\n");
            printf("take           - after inputing take, allows the player pick up items and put them into their inventory.\n\n");
            printf("drop           - after inputting drop, allows the player drop items from their inventory into the current room they are in.\n\n");
            printf("inventory      - allows the player look into their inventory and see what they have.\n\n");
            printf("clue           - after inputting clue, allows player to guess the murderer and item they used to murder with.\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }

        //list input
        if(strcmp(commander, "list") == 0){
            printf("\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("Rooms:           Kitchen, Ballroom, Conservatory, Billiard, Library, Study, Hall, Lounge, Dining\n\n");
            printf("Characters:      Cole, Charles, Sean, Mickey, Larry\n\n");
            printf("Items:           Pipe, Revolver, Knife, Brick, Stick, Shotgun\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }

        //go input
        if(strcmp(commander, "go") == 0){
            char *dir = malloc(sizeof(char) * ( 20 ));
            printf("\n");
            printf("Direction: ");
            scanf("%s", dir);

            //checks if user input is valid
            //if not, they have to type again
            while(strcmp(dir, "North") != 0 && strcmp(dir, "East") != 0 && strcmp(dir, "South") != 0 && strcmp(dir, "West") != 0){
                printf("Not an applicable direction.\n");
                printf("\n");
                printf("Direction: ");
                printf("\n");
                scanf("%s", dir);
                printf("\n");
            }  

            //checks if player hit any walls
            if(strcmp(dir, "North") == 0){
                if(player->North != NULL){
                    player = player->North;
                }else{
                    printf("You hit the North Wall.\n");
                }
            }

            if(strcmp(dir, "East") == 0){
                if(player->East != NULL){
                    player = player->East;
                }else{
                    printf("You hit the East Wall.\n");
                }
            }

            if(strcmp(dir, "South") == 0){
                if(player->South != NULL){
                    player = player->South;
                }else{
                    printf("You hit the South Wall.\n");
                }
            }

            if(strcmp(dir, "West") == 0){
                if(player->West != NULL){
                    player = player->West;
                }else{
                    printf("You hit the West Wall.\n");
                }
            }
        }

        //look input
        if(strcmp(commander, "look") == 0){
            printf("\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("Current location:   %s\n", player->name);
            
            printf("Characters in room: ");
            print_items(player->character);

            printf("Items in room:      ");
            print_items(player->itemList);
            printf("\n");
           
            //prints the name of adjacent rooms unless they are walls
            printf("North location:     ");
            if(player->North != NULL) printf("%s\n", player->North->name);
            else printf("Wall\n");

            printf("East location:      ");
            if(player->East != NULL) printf("%s\n", player->East->name);
            else printf("Wall\n");

            printf("South location:     ");
            if(player->South != NULL) printf("%s\n", player->South->name);
            else printf("Wall\n");

            printf("West location:      ");
            if(player->West != NULL) printf("%s\n", player->West->name);
            else printf("Wall\n");

            printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }

        //inventory input
        if(strcmp(commander, "inventory") == 0){
            printf("\n");
            printf("Inventory: ");
            print_items(inventory);
            printf("\n");
        }

        //take input
        if(strcmp(commander, "take") == 0){
            if(player->itemList == NULL){
                printf("No items in the room.\n");
                continue;
            }
            char *itm =  malloc(sizeof(char) * ( 10 ));
            printf("\n");
            printf("Take: ");
            scanf("%s", itm);

            //checks if user input is valid
            //if not, they have to type again
            while(strcmp(itm, "Pipe") != 0 && strcmp(itm, "Revolver") != 0 && strcmp(itm, "Knife") != 0 && 
                  strcmp(itm, "Brick") != 0 && strcmp(itm, "Stick") != 0 && strcmp(itm, "Shotgun") != 0){
                printf("\n");
                printf("Not an applicable item.\n");
                printf("\n");
                printf("Item: ");
                scanf("%s", itm);
                printf("\n");
            }  
            
            add_item(&inventory, itm);
            remove_item(&player->itemList, itm);
        }

        //drop input
        if(strcmp(commander, "drop") == 0){
            if(inventory == NULL){
                printf("No items in the inventory.\n");
                continue;
            }
            char *itm =  malloc(sizeof(char) * ( 10 ));
            printf("\n");
            printf("Drop: ");
            scanf("%s", itm);

            //checks if user input is valid
            //if not, they have to type again
            while(strcmp(itm, "Pipe") != 0 && strcmp(itm, "Revolver") != 0 && strcmp(itm, "Knife") != 0 && 
                  strcmp(itm, "Brick") != 0 && strcmp(itm, "Stick") != 0 && strcmp(itm, "Shotgun") != 0){
                printf("\n");
                printf("Not an applicable item.\n");
                printf("\n");
                printf("Item: ");
                scanf("%s", itm);
                printf("\n");
            }  
            
            add_item(&player->itemList, itm);
            remove_item(&inventory, itm);
        }

        //clue input
        if(strcmp(commander, "clue") == 0){
            printf("\n");
            char *car =  malloc(sizeof(char) * ( 20 ));
            printf("\n");
            printf("Character: ");
            scanf("%s", car);

            //checks if user input is valid
            //if not, they have to type again
            while(strcmp(car, "Cole") != 0 && strcmp(car, "Charles") != 0 && strcmp(car, "Sean") != 0 && 
                  strcmp(car, "Mickey") != 0 && strcmp(car, "Larry") != 0){
                printf("\n");
                printf("Not an applicable character.\n");
                printf("\n");
                printf("Character: ");
                scanf("%s", car);
                printf("\n");
            }  

            //checks all rooms and removes the character the user inputed
            if(Room1.character != NULL){
                if(contains(&Room1.character, car) == 1){
                    remove_item(&Room1.character, car);
                }
            }
            if(Room2.character != NULL){
                if(contains(&Room2.character, car) == 1){
                    remove_item(&Room2.character, car);
                }
            }
            if(Room3.character != NULL){
                if(contains(&Room3.character, car) == 1){
                    remove_item(&Room3.character, car);
                }
            }
            if(Room4.character != NULL){
                if(contains(&Room4.character, car) == 1){
                    remove_item(&Room4.character, car);
                }
            }
            if(Room5.character != NULL){
                if(contains(&Room5.character, car) == 1){
                    remove_item(&Room5.character, car);
                }
            }
            if(Room6.character != NULL){
                if(contains(&Room6.character, car) == 1){
                    remove_item(&Room6.character, car);
                }
            }
            if(Room7.character != NULL){
                if(contains(&Room7.character, car) == 1){
                    remove_item(&Room7.character, car);
                }
            }
            if(Room8.character != NULL){
                if(contains(&Room8.character, car) == 1){
                    remove_item(&Room8.character, car);
               }
            }
            if(Room9.character != NULL){
                if(contains(&Room9.character, car) == 1){
                    remove_item(&Room9.character, car);
                }
            }
            //adds the character the user inputed into the current room
            add_item(&player->character, car);

            if(inventory == NULL && player->itemList == NULL){
                printf("\n");
                printf("No valid items present.");
                printf("\n");
                continue;
            }

            char *itm1 =  malloc(sizeof(char) * ( 20 ));
            printf("\n");
            printf("Item: ");
            scanf("%s", itm1);

            //checks if user input is valid
            //if not, they have to type again
            while(strcmp(itm1, "Cole") != 0 && strcmp(itm1, "Charles") != 0 && strcmp(itm1, "Sean") != 0 && 
                  strcmp(itm1, "Mickey") != 0 && strcmp(itm1, "Larry") != 0 && contains(&player->itemList, itm1) != 1 && contains(&inventory, itm1) != 1){
                printf("\n");
                printf("Not an applicable item.\n");
                printf("\n");
                printf("Item: ");
                scanf("%s", itm1);
                printf("\n");
            } 

            //checks if the player clue answers are correct or wrong
            if(strcmp(player->name, room_answer) == 0) printf("\nRoom matched!\n");
            else printf("\nRoom wrong.\n");

            if(strcmp(car, character_answer) == 0) printf("\nCharacter matched!\n");
            else printf("\nCharacter wrong.\n");

            if(strcmp(itm1, item_answer) == 0) printf("\nItem matched!\n");
            else printf("\nItem wrong.\n");

            //displays a winning screen if the player guesed the room, character, and item correctly
            //else the player continues playing but has one less attempt.
            if(strcmp(player->name, room_answer) == 0 && strcmp(car, character_answer) == 0 && strcmp(itm1, item_answer) == 0){
                printf("\nYou did it! You caught %s red handed. Good Job!\n\n", car);
                break;
            }else{
                clue_attempts++;
                int attempts_left = 10 - clue_attempts;
                printf("\nSorry, your wrong, but don't give up now, you have %i attempt(s) left.\n\n", attempts_left);
                continue;
            }

        }

    }
    //game over notification if clue attemps exceeds 10
    if(clue_attempts == 10){
        printf("\n\nSorry, you lost! The killer got away! Better luck next time.\n\n");
    }
     
    return 0;
}