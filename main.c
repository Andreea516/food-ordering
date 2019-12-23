#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "order.h"
#include "type.h"
#include "food.h"
#include "drink.h"

#define MAX_USERNAME 40
#define MAX_PASSWORD 25
#define MAX_FOOD_NAME 40
#define MAX_DRINK_NAME 40
#define MAX_ADD_INFO 256
#define MAX_LINE 256
#define LOAD_DATA "Please load the data"
#define FILE_PATH "D:\\Faculta\\An1\\CP\\food-ordering\\cmake-build-debug\\data.txt"

int main() {

    FILE *data;
    data = fopen(FILE_PATH, "r");
    if(data==NULL)
    {
        printf("%s\n>", LOAD_DATA);
        data=stdin;
    }

    CUSTOMER c = createCustomer();

    int cutleryChoice=0, foodChoice=0, typeChoice=0, drinkChoice=0, state=0, orderConfirmed=0;
    char addInfo[MAX_ADD_INFO];

    int noOfFoods,noOfDrinks;

    FOOD *food;
    readFoodAndTypes(data, &noOfFoods,&food);

    DRINK *drink;
    readDrink(data, &noOfDrinks, &drink);
    enum State {
        SIGN_IN_UP, CHOOSE_FOOD, CHOOSE_TYPE, CHOOSE_DRINK, CHOOSE_CUTLERY, ADD_INFO
    };
    printf("Welcome to Samsara Foodhouse!\nPlease sign in to continue!\n");
    while(!orderConfirmed){
        switch(state){
            case SIGN_IN_UP:{

                sign_in_or_up(c);
                state++;

                break;
            }
            case CHOOSE_FOOD:{
                printf("Please choose the food you feel like eating today:\n");
                displayFood(noOfFoods, food);
                foodChoice=get_choice_index(noOfFoods, &state);
                break;
            }
            case CHOOSE_TYPE:{
                printf("Please choose the type of %s\n", food[foodChoice]);
                displayFoodType(food[foodChoice].noOfTypes, food[foodChoice].types);
                typeChoice=get_choice_index(food[foodChoice].noOfTypes, &state);
                break;
            }
            case CHOOSE_DRINK:{
                printf("Please choose a drink to go with your %s:\n", &(food[foodChoice].types[typeChoice]));
                displayDrink(noOfDrinks,  drink);
                drinkChoice=get_choice_index(noOfDrinks, &state);
                break;
            }
            case CHOOSE_CUTLERY:{
                display_cutlery();
                cutleryChoice=get_choice_index(2, &state);
                break;
            }
            case ADD_INFO:{
                get_info(addInfo);
                display_order(addInfo, food[foodChoice].types[typeChoice], drink[drinkChoice], cutleryChoice,c);
                confirm_order(&orderConfirmed, c, &state);
                break;
            }}}
    freeFood(food,noOfFoods);
    freeDrinks(drink, noOfDrinks);
    fclose(data);
    return 0;
}