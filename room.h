#include <stdio.h>
#include <stdlib.h>

//header file of struct room and methods
struct Room{
    char* name;
    struct Room * North;
    struct Room * South;
    struct Room * East;
    struct Room * West;
    struct Item * itemList;
    struct Item *character;
};

struct Room create_new_room(char* name, struct Room *North, 
                            struct Room *South, struct Room *East, 
                            struct Room *West, struct Item *itemList, 
                            struct Item *character);