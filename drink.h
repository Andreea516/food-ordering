//
// Created by Andreea on 22-Dec-19.
//

#ifndef FOOD_ORDERING_DRINK_H
#define FOOD_ORDERING_DRINK_H

typedef struct
{
    char *name;
    double price;
}DRINK;

//read
void readDrink(FILE *data, int *noOfDrinksAddr, DRINK **drinkAddr);

//display
void displayDrink(int noOfDrinks, DRINK *drink);

//free
void freeDrinks(DRINK* drink, int noOfDrinks);

#endif //FOOD_ORDERING_DRINK_H
