#include <stdio.h>
#include <stdlib.h>

//header file of struct item and methods
struct Item{
    char *name;
    struct Item *next_item;
};

void add_item(struct Item **itemList, char name[]);

void remove_item(struct Item **itemList, char name[]);

int contains(struct Item **itemList, char name[]);

void print_items(struct Item *itemList);

