#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customer.h"
#include "order.h"

#define MAX_USERNAME 40
#define MAX_PASSWORD 25
#define MAX_NO_TYPES 10
#define MAX_FOOD_NAME 40
#define MAX_DRINK_NAME 40
#define MAX_NO_DRINKS 15
#define MAX_ADD_INFO 256
#define MAX_LINE 256
#define LOAD_DATA "Please load the data"

int main() {
    char username[MAX_USERNAME]="admin",password[MAX_PASSWORD]="admin";

    int cutleryChoice=0, foodChoice, typeChoice, drinkChoice, state=0, orderConfirmed=0;
    char addInfo[MAX_ADD_INFO];

    int noOfFoodTypes,noOfDrinks,*noOfSpecificTypes; char s[MAX_LINE],**foodTypes,***specificFoodTypes,**drinks, *p;
    double **specificFoodPrices,*drinkPrices;

     FILE *data;
     data = fopen("..//data.txt", "r");
     if(data==NULL)
     {
         printf("%s\n>", LOAD_DATA);
         data=stdin;
     }

    //read food
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

    //read drink
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

    printf("Welcome to Samsara Foodhouse!\nPlease sign in to continue!\n");
    while(!orderConfirmed){
        switch(state){
            case 0:{
                sign_in_or_up(username,password);
                state++;
                break;
            }
            case 1:{
                printf("Please choose the food you feel like eating today:\n");
                display_food(noOfFoodTypes, foodTypes);
                foodChoice=get_choice_index(noOfFoodTypes, &state);
                break;
            }
            case 2:{
                printf("Please choose the type of %s\n", foodTypes[foodChoice]);
                display_foodtype(noOfSpecificTypes[foodChoice], specificFoodTypes[foodChoice], specificFoodPrices[foodChoice]);
                typeChoice=get_choice_index(noOfSpecificTypes[foodChoice], &state);
                break;
            }
            case 3:{
                printf("Please choose a drink to go with your %s:\n", specificFoodTypes[foodChoice][typeChoice]);
                display_drink(noOfDrinks, drinks, drinkPrices );
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
                display_order(addInfo, specificFoodTypes[foodChoice][typeChoice], specificFoodPrices[foodChoice][typeChoice], drinks[drinkChoice], drinkPrices[drinkChoice], cutleryChoice,username);
                confirm_order(&orderConfirmed, username, &state);
                break;
            }}}

    //free memory

    for(int i=0;i<noOfFoodTypes;i++) {
        for(int j=0;j<noOfSpecificTypes[i];j++) {
            free(specificFoodTypes[i][j]);
        }
        free(specificFoodTypes[i]);
        free(specificFoodPrices[i]);
        free(foodTypes[i]);
    }
    free(specificFoodTypes);
    free(specificFoodPrices);
    free(noOfSpecificTypes);
    free(foodTypes);
    for(int i=0;i<noOfDrinks;i++)
        free(drinks[i]);
    free(drinks);
    free(drinkPrices);

    // fclose(data);
    return 0;
}