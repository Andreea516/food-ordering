//
// Created by Andreea on 22-Dec-19.
//

#ifndef FOOD_ORDERING_TYPE_H
#define FOOD_ORDERING_TYPE_H

typedef struct
{
    char *name;
    double price;
}TYPE;

//read

void readType(FILE *data, int noOfTypes, TYPE **typeAddr, char *p);

//display
void displayFoodType(int noOfTypes, TYPE * types);
//void displayType(TYPE* t);

//free
void freeType(TYPE *t);

#endif //FOOD_ORDERING_TYPE_H
