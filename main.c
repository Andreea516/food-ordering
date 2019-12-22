#include <stdio.h>
#include <string.h>
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

    CUSTOMER c = createCustomer();

    int cutleryChoice=0, foodChoice, typeChoice, drinkChoice, state=0, orderConfirmed=0;
    char addInfo[MAX_ADD_INFO];

    int noOfFoods,noOfDrinks; char s[MAX_LINE];

    FOOD *food;

    FILE *data;
    data = fopen(FILE_PATH, "r");
    if(data==NULL)
    {
        printf("%s\n>", LOAD_DATA);
        data=stdin;
    }

    //read food
    /*
    fgets(s,MAX_LINE, data);
    sscanf(s, "%d", &noOfFoodTypes);
    foodTypes = (char**)malloc(noOfFoodTypes * sizeof(char*));
    specificFoodTypes = (char***)malloc(noOfFoodTypes * sizeof(char**));
    specificFoodPrices = (double**)malloc(noOfFoodTypes * sizeof(double*));
    noOfSpecificTypes = (int*)malloc(noOfFoodTypes * sizeof(int));
    for(int i=0; i<=noOfFoodTypes-1; i++) {
        foodTypes[i] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
        fgets(s,MAX_LINE, data);
        p = strtok(s, " ");
        strcpy(foodTypes[i], p);
        p = strtok(NULL, ":");
        sscanf(p,"%d",&noOfSpecificTypes[i]);
        specificFoodTypes[i] = (char **) malloc(noOfSpecificTypes[i] * sizeof(char *));
        specificFoodPrices[i] = (double *) malloc(noOfSpecificTypes[i] * sizeof(double));
        for( int j=0; j<noOfSpecificTypes[i]; j++)
        {
            p = strtok(NULL, "-");
            specificFoodTypes[i][j] = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
            strcpy(specificFoodTypes[i][j], p+2);
            specificFoodTypes[i][j][strlen(p) - 1] = '\0';
            p = strtok(NULL, ")");
            sscanf(p, "%lf", &specificFoodPrices[i][j]);
        }
    }
*/
    readFood(data, &noOfFoods,food);
    //read drink
    /*
    fgets(s,MAX_LINE, data);
    sscanf(s, "%d", &noOfDrinks);
    drinks = (char**)malloc(noOfDrinks * sizeof(char*));
    drinkPrices = (double*)malloc(noOfDrinks * sizeof(double));
    fgets(s,MAX_LINE, data);
    strrev(s);
    p = strtok(s, "-");
    for (int i = noOfDrinks - 1; i >= 0; i--)
    {
        if (i != noOfDrinks - 1)
            p = strtok(NULL, "-");
        sscanf(strrev(p), "%lf", &drinkPrices[i]);
        drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        p = strtok(NULL, "(");
        strcpy(drinks[i], p);
        strrev(drinks[i]);
    }
    */
    DRINK *drink = (DRINK *)malloc(noOfDrinks * sizeof(DRINK));

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
                displayFoodType(food[foodChoice].noOfTypes, food[foodChoice].types, food[foodChoice].name);
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

    fclose(data);
    return 0;
}