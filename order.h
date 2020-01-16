//
// Created by Andreea on 06-Nov-19.
//

#include "food.h"
#include "type.h"
#include "drink.h"
#include "customer.h"

#define MAX_USERNAME 40
#define MAX_PASSWORD 25
#define MAX_NO_FOODS 7
#define MAX_NO_TYPES 10
#define MAX_FOOD_NAME 40
#define MAX_NO_DRINKS 15
#define MAX_ADD_INFO 256

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H

void display_cutlery();

void get_info(char addInfo[]);

int get_choice_index(int noOfChoices, int *state);

void cutlery(int cutleryChoice);

void display_order(char addInfo[], TYPE type, DRINK drink, int cutleryChoice, CUSTOMER c);

void confirm_order(int *orderConfirmed, CUSTOMER c, int *state);


#endif //FOOD_ORDERING_ORDER_H
