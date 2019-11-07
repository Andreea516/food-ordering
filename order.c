#include <stdio.h>
#include <string.h>
#define MAX_USERNAME 40
#define MAX_PASSWORD 25
#define MAX_NO_FOODS 7
#define MAX_NO_TYPES 10
#define MAX_FOOD_NAME 40
#define MAX_NO_DRINKS 15
#define MAX_ADD_INFO 256

void display_food(int noOfFoods, char food[][MAX_FOOD_NAME])
{
    for (int i = 0; i < noOfFoods; i++)
    {
        putchar('a'+i);
        printf(") %s\n", food[i]);
    }
    printf("%c) Go back\n>", 'a' + noOfFoods);
}

void display_foodtype(int noOfTypes[], char types[][MAX_NO_TYPES][MAX_FOOD_NAME], int foodPrices[], int foodChoice)
{
    for(int i=0; i < noOfTypes[foodChoice]; i++)
    {
        putchar('a'+i);
        printf(") %s (%d)\n", types[foodChoice][i], foodPrices[i]);
    }
    printf("%c) Go back\n>", 'a' + noOfTypes[foodChoice]);
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

void display_order(char addInfo[], char type[][MAX_NO_TYPES][MAX_FOOD_NAME], int foodPrice[][MAX_NO_TYPES], char drink[][MAX_FOOD_NAME], int drinkPrice[], int foodChoice, int typeChoice, int drinkChoice, int cutleryChoice,int noOfDrinks)
{
    printf("Food items: \n");
    printf("-%s: %d \n", type[foodChoice][typeChoice], foodPrice[foodChoice][typeChoice]);
    if(drinkChoice<noOfDrinks-1)
    printf("-%s: %d \n", drink[drinkChoice], drinkPrice[drinkChoice]);
    cutlery(cutleryChoice);
    if(strcmp(addInfo, "\0") != 0)
        printf("Additional info: %s\n", addInfo);
    printf("Payment amount: %d\n", foodPrice[foodChoice][typeChoice] + drinkPrice[drinkChoice]);
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


