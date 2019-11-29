//
// Created by Andreea on 06-Nov-19.
//

#define MAX_USERNAME 40
#define MAX_PASSWORD 25
#define MAX_NO_FOODS 7
#define MAX_NO_TYPES 10
#define MAX_FOOD_NAME 40
#define MAX_NO_DRINKS 15
#define MAX_ADD_INFO 256

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H

void display_food(int noOfFoods, char **food);

void display_foodtype(int noOfTypes, char **types, double *foodPrices);

void display_drink(int noOfDrinks, char **drink, double *drinkPrices);

void display_cutlery();

void get_info(char addInfo[]);

int get_choice_index(int noOfChoices, int *state);

void cutlery(int cutleryChoice);

void display_order(char addInfo[], char *type, double foodPrice, char *drink, double drinkPrice, int cutleryChoice, char username[]);

void confirm_order(int *orderConfirmed, char username[], int *state);


#endif //FOOD_ORDERING_ORDER_H
