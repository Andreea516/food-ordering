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

void display_food(int noOfFoods, char food[][MAX_FOOD_NAME]);

void display_foodtype(int noOfTypes, char types[][MAX_FOOD_NAME], int foodPrices[]);

void display_drink(int noOfDrinks, char drink[][MAX_FOOD_NAME], int drinkPrices[]);

void display_cutlery();

void get_info(char addInfo[]);

int get_choice_index(int noOfChoices, int *state);

void cutlery(int cutleryChoice);

void display_order(char addInfo[], char type[], int foodPrice, char drink[], int drinkPrice, int cutleryChoice, char username[]);

void confirm_order(int *orderConfirmed, char username[], int *state);


#endif //FOOD_ORDERING_ORDER_H
