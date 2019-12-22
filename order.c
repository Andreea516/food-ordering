#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "food.h"
#include "type.h"
#include "drink.h"

#define MAX_FOOD_NAME 40

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

void display_order(char addInfo[], TYPE type, DRINK drink, int cutleryChoice, CUSTOMER c)
{
    printf("This is your order:\n");
    printf("-------------------\n");
    display_username(c);
    printf("Food items: \n");
    printf("-%s: %.2f \n", type.name, type.price);
    if(strcmp(drink.name,"No, thanks!"))
        printf("-%s: %.2f \n", drink.name, drink.price);
    cutlery(cutleryChoice);
    if(strcmp(addInfo, "\0") != 0)
        printf("Additional info: %s\n", addInfo);
    printf("Payment amount: %.2f\n", type.price + drink.price);
    printf("-------------------\n");

}

void confirm_order(int *orderConfirmed, CUSTOMER c, int *state)
{
    char choice;
    printf("a) Confirm Order\n");
    printf("b) Go back\n");
    choice = getchar();
    if(choice=='a')
    {
        (*orderConfirmed)=1;
        printf("Order confirmed! Thank you for buying from us, %s!\n", c.username);
    }
    else
        (*state)--;
}


