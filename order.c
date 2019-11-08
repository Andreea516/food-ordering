#include <stdio.h>
#include <string.h>
#include "customer.h"
#define MAX_FOOD_NAME 40

void display_food(int noOfFoods, char food[][MAX_FOOD_NAME])
{
    for (int i = 0; i < noOfFoods; i++)
    {
        putchar('a'+i);
        printf(") %s\n", food[i]);
    }
    printf("%c) Go back\n>", 'a' + noOfFoods);
}

void display_foodtype(int noOfTypes, char types[][MAX_FOOD_NAME], int foodPrices[])
{
    for(int i=0; i < noOfTypes; i++)
    {
        putchar('a'+i);
        printf(") %s (%d)\n", types[i], foodPrices[i]);
    }
    printf("%c) Go back\n>", 'a' + noOfTypes);
}

void display_drink(int noOfDrinks, char drink[][MAX_FOOD_NAME], int drinkPrices[])
{
    for(int i=0; i < noOfDrinks-1; i++)
    {
        putchar('a' + i);
        printf(") %s (%d)\n", drink[i], drinkPrices[i]);

    }
    printf("%c) No, thanks! \n", 'a' + noOfDrinks-1);
    printf("%c) Go back\n>", 'a' + noOfDrinks);
}

void display_cutlery()
{
    printf("Do you want cutlery?\n");
    printf("a)Yes\n");
    printf("b)No, thanks!\n");
    printf("c)Go back\n>");
}

int get_choice_index(int noOfChoices, int *state)
{
    char choice; int choiceIndex;
    choice = getchar();
    getchar();
    if (choice == 'a' + noOfChoices)
    {
        (*state)--;
    }
    else
    {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

void get_info(char addInfo[])
{
    printf("Any additional info?\n");
    gets(addInfo);
}
void cutlery(int cutleryChoice)
{
    printf("Cutlery: ");
    if(cutleryChoice == 0)
        printf("no\n");
    else
        printf("yes\n");
}

void display_order(char addInfo[], char type[], int foodPrice, char drink[], int drinkPrice, int cutleryChoice, char username[])
{
    printf("This is your order:\n");
    printf("-------------------\n");
    display_username(username);
    printf("Food items: \n");
    printf("-%s: %d \n", type, foodPrice);
    if(strcmp(drink,"No, thanks!"))
        printf("-%s: %d \n", drink, drinkPrice);
    cutlery(cutleryChoice);
    if(strcmp(addInfo, "\0") != 0)
        printf("Additional info: %s\n", addInfo);
    printf("Payment amount: %d\n", foodPrice + drinkPrice);
    printf("-------------------\n");

}

void confirm_order(int *orderConfirmed, char username[], int *state)
{
    char choice;
    printf("a) Confirm Order\n");
    printf("b) Go back\n");
    choice = getchar();
    if(choice=='a')
    {
        (*orderConfirmed)=1;
        printf("Order confirmed! Thank you for buying from us, %s!\n", username);
    }
    else
        (*state)--;
}


