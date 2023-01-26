#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h"

//adds an item to the end of a linked list with the specified name
void add_item(struct Item **itemList, char name[]){
    struct Item *newItem = (struct Item *)malloc(sizeof(struct Item));
    newItem->name = name;
    newItem->next_item = NULL;
    struct Item *prev = *itemList;

    if(*itemList == NULL){
        *itemList = newItem;
    }else{
        while(prev->next_item != NULL){
            prev = prev->next_item;
        }

        prev->next_item = newItem;
    }

}

//a simple remove method that goes through a list and removes the desired item or character
//it then frees the item that is to be removed
void remove_item(struct Item **itemList, char name[]){
    struct Item *temp = *itemList;
    struct Item *prev = *itemList;

    if(strcmp((*itemList)->name, name) == 0){
        *itemList = (*itemList)->next_item;
        free(temp);
    }else{
        while(temp->name != NULL){
            if(strcmp(temp->name, name) == 0){
                prev->next_item = temp->next_item;
                free(temp);
            }else{
                prev = temp;
                temp = temp->next_item;
            }
        }
    }
}

//checks if the desired item list or character list has the item or characetr you are looking for
//returns 1 if it does and 0 if the list doesnt 
int contains(struct Item **itemList, char name[]){
    struct Item *temp = *itemList;

    while(temp != NULL){
        if(strcmp(temp->name, name) == 0){
            return 1;
        }
        temp = temp->next_item;
    }
    return 0;
}

//simply goes through a liked list of "items" and prints them all out
void print_items(struct Item *itemList){
    struct Item *temp = itemList;

    while(temp != NULL){
        printf("%s ", temp->name);
        temp = temp->next_item;
    }

    printf("\n");
}


