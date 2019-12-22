//
// Created by Andreea on 22-Dec-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "food.h"
#include "type.h"

#define MAX_FOOD_NAME 40
#define MAX_LINE 256

FOOD createFood()
{
    FOOD f;
    f.name = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
    f.types = NULL;
    return f;
}

//read

void readFood(FILE *data, int *noOfFoods, char *foodName)
{
    char s[MAX_LINE], *p;

    fgets(s,MAX_LINE, data);
    p = strtok(s, " ");
    strcpy(foodName, p);
    p = strtok(NULL, ":");
}

void readFoodAndTypes(FILE *data, int *noOfFoodsAddr ,FOOD **foodAddr)
{
    char s[MAX_LINE];
    int noOfFoods;
    fgets(s,MAX_LINE, data);
    sscanf(s, "%d", noOfFoods);
    FOOD *food = (FOOD *) malloc(noOfFoods * sizeof(FOOD));
    for(int i=0; i<noOfFoods; i++)
    {
        food[i]=createFood();
        readFood(data, food[i].name, &(food[i].noOfTypes));
        readType(data, food[i].noOfTypes, &(food[i].types));
    }
    *noOfFoodsAddr = noOfFoods;
    *foodAddr = food;
}


//display
void displayFood(int noOfFoods, FOOD *food)
{
    for (int i = 0; i < noOfFoods; i++)
    {
        putchar('a'+i);
        printf(") %s\n", food[i].name);
    }
    printf("%c) Go back\n>", 'a' + noOfFoods);
}

//void free
void freeFood(FOOD* food, int noOfFoods)
{
    for (int i = 0; i < noOfFoods; i++) {
        for (int j = 0; j < food[i].noOfTypes; j++) {
            freeType(&(food[i].types[j]));
        }
        free(food[i].types);
        free(food[i].name);
    }
    free(food);
}