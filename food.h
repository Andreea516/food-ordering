//
// Created by Andreea on 22-Dec-19.
//
#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H

#include "type.h"

typedef struct
{
    char *name;
    int noOfTypes;
    TYPE *types;
}FOOD;

FOOD createFood();

void readFood(FILE *data, char *foodName, char *p);

void readFoodAndTypes(FILE *data, int *noOfFoodsAddr ,FOOD **foodAddr);

void displayFood(int noOfFoods, FOOD *food);

void freeFood(FOOD* food, int noOfFoods);

#endif //FOOD_ORDERING_FOOD_H
