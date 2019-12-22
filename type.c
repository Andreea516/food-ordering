//
// Created by Andreea on 22-Dec-19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "type.h"

#define MAX_TYPE_NAME 40

//read
void readType(FILE *data, int noOfTypes, TYPE **typeAddr)
{
    char *p;
    TYPE * types = (TYPE*)malloc(noOfTypes * sizeof(TYPE));
    char ** names = (char **) malloc(noOfTypes* sizeof(char *));
    double * prices = (double *) malloc(noOfTypes * sizeof(double));

    for (int i = 0; i < noOfTypes; i++) {
        names[i] = (char *) malloc(MAX_TYPE_NAME * sizeof(char));
        p = strtok(NULL, "-");
        strcpy(names[i], p+2);
        names[i][strlen(p) - 1] = '\0';
        p = strtok(NULL, ")");
        sscanf(p, "%lf", prices[i]);
    }

    for(int i=0; i<noOfTypes; i++) {
        types[i].name = names[i];
        types[i].price = prices[i];
    }

    free(names);
    free(prices);
    *typeAddr = types;
}

//display
void displayFoodType(int noOfTypes, TYPE * types, char *food)
{
    for(int i=0; i < noOfTypes; i++)
    {
        putchar('a'+i);
        printf(") %s (%.2f)\n", types[i].name, types[i].price);
    }
    printf("%c) Go back\n>", 'a' + noOfTypes);
}

void displayType(TYPE* t)
{
    printf("%s (%.2f)\n", t->name, t->price);
}

//free
void freeType(TYPE *t)
{
    free(t->name);
}
