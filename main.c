#include <stdio.h>
#include "customer.h"
#include "order.h"
#define MAX_USERNAME 40
#define MAX_PASSWORD 25
#define MAX_NO_FOODS 7
#define MAX_NO_TYPES 10
#define MAX_FOOD_NAME 40
#define MAX_NO_DRINKS 15
#define MAX_ADD_INFO 256

int main() {
    char username[MAX_USERNAME],password[MAX_PASSWORD];
    int noOfFoods=5, noOfTypes[]={4, 5, 4, 6, 4}, noOfDrinks=7;
    char food[MAX_NO_FOODS][MAX_FOOD_NAME]={"Soup", "Salad", "Pasta", "Pizza", "Noodles"};
    char types[MAX_NO_FOODS][MAX_NO_TYPES][MAX_FOOD_NAME]={
                    {"Gazpacho","Lentil cream soup", "Thai soup","Siitake mushroom cream soup"},
                    {"California Dreams salad", "Thai salad", "Buratta salad", "Cesar salad", "Avocado, tomotoes and mango salad"},
                    {"Veggie Spaghetti Bologanse", "Campanelle with broccoli and pesto", "Parapdelle with boletus and sour cream", "Spaghetti Arrabiata"},
                    {"Margherita Pizza", "Porcini Pizza","Bufala Pizza","Quatro Formaggi Pizza","Kalamata Pizza", "Garden Chesse Pizza"},
                    {"Shiitake Noodles", "Spicy Bamboo Noodles","Singapore Noodles", "Phad Thai"}
    };
    int foodPrices[MAX_NO_FOODS][MAX_NO_TYPES]={
            {17, 16, 17, 19},
            {28, 28, 28, 28, 30},
            {29, 30, 32, 25},
            {25, 32, 31, 32, 31,32},
            {28, 28, 28, 28}
    };
    int drinkPrices[MAX_NO_DRINKS]={12, 13, 9, 15, 14, 12, 0};
    char drink[MAX_NO_DRINKS][MAX_FOOD_NAME]={"Banana Smoothie", "Mango Smoothie", "Peach Smoothie", "Orange Fresh", "Green Apple", "Ginger Beer", "No, thanks!"};
    int cutleryChoice=0, foodChoice, typeChoice, drinkChoice, state=0, orderConfirmed=0;
    char addInfo[MAX_ADD_INFO];
    printf("Welcome to Samsara Foodhouse!\nPlease sign in to continue!\n");
    while(!orderConfirmed){
        switch(state){
            case 0:{
                sign_in(username, password);
                state++;
                break;
            }
            case 1:{
                printf("Please choose the food you feel like eating today:\n");
                display_food(noOfFoods, food);
                foodChoice=get_choice_index(noOfFoods, &state);
                break;
            }
            case 2:{
                printf("Please choose the type of %s\n", food[foodChoice]);
                display_foodtype(noOfTypes, types, foodPrices[foodChoice], foodChoice);
                typeChoice=get_choice_index(noOfTypes[foodChoice], &state);
                break;
            }
            case 3:{
                printf("Please choose a drink to go with your %s:\n", types[foodChoice][typeChoice]);
                display_drink(noOfDrinks, drink, drinkPrices );
                drinkChoice=get_choice_index(noOfDrinks, &state);
                break;
            }
            case 4:{
               display_cutlery();
                cutleryChoice=get_choice_index(2, &state);
                break;
            }
            case 5:{
                get_info(addInfo);
                display_username(username);
                display_order(addInfo, types, foodPrices, drink, drinkPrices, foodChoice, typeChoice, drinkChoice, cutleryChoice,noOfDrinks);
                confirm_order(&orderConfirmed, username, &state);
                break;
            }}}
    return 0;
}