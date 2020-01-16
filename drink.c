//
// Created by Andreea on 22-Dec-19.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "drink.h"

#define MAX_LINE 256
#define MAX_DRINK_NAME 40



//read
void readDrink(FILE *data, int *noOfDrinksAddr, DRINK **drinkAddr)
{
    char s[MAX_LINE], *p;
    int noOfDrinks;
    DRINK *drink = (DRINK *) malloc(noOfDrinks * sizeof(DRINK));
    char ** names = (char **) malloc(noOfDrinks* sizeof(char *));
    double * prices = (double *) malloc(noOfDrinks* sizeof(double));
    fgets(s,MAX_LINE, data);
    for (int i = 0; i < noOfDrinks; i++) {
        names[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        p = strtok(NULL, "-");
        strcpy(names[i], p+2);
        names[i][strlen(p) - 1] = '\0';
        p = strtok(NULL, ")");
        sscanf(p, "%lf", prices[i]);
    }
    for(int i=0; i<noOfDrinks; i++) {
        drink[i].name = names[i];
        drink[i].price = prices[i];
    }

    *noOfDrinksAddr = noOfDrinks;
    *drinkAddr = drink;
}

void displayDrink(int noOfDrinks, DRINK *drink)
{
    for(int i=0; i < noOfDrinks-1; i++)
    {
        putchar('a' + i);
        printf(") %s (%.2f)\n", drink[i].name, drink[i].price);

    }
    printf("%c) No, thanks! \n", 'a' + noOfDrinks-1);
    printf("%c) Go back\n>", 'a' + noOfDrinks);
}

void freeDrinks(DRINK* drink, int noOfDrinks)
{
    for (int i = 0; i < noOfDrinks; i++) {
        free(drink[i].name);
    }
    free(drink);
}