#include <stdio.h>
#include <stdlib.h>
#include "room.h"
#include "items.h"

//this method creates a new room struct and assigns initial pointer, items, and characetrs
struct Room create_new_room(char* name, struct Room *North, 
                            struct Room *South, struct Room *East, 
                            struct Room *West, struct Item *itemList, 
                            struct Item *character){
    struct Room ret;
    ret.name = name;
    ret.North = North;
    ret.South = South;
    ret.East = East;
    ret.West = West;
    ret.itemList = itemList;
    ret.character = character;
    return ret;
}





