#include <stdio.h>
#include <string.h>

int main() {
    //user input
    char username[30],password[30];

    //Food and drink data
    int NoOfFoods=5;
    char Food[][20]={"Soup","Salad","Pasta","Pizza","Noodles"};
    int NoOfTypes[]={4,5,4,6,4};
    char Types[5][6][40]=
            {
                    {"Gazpacho","Lentil cream soup", "Thai soup","Siitake mushroom cream soup"},
                    {"California Dreams salad", "Thai salad", "Buratta salad", "Cesar salad", "Avocado, tomotoes and mango salad"},
                    {"Veggie Spaghetti Bologanse", "Campanelle with broccoli and pesto", "Parapdelle with boletus and sour cream", "Spaghetti Arrabiata"},
                    {"Margherita Pizza", "Porcini Pizza","Bufala Pizza","Quatro Formaggi Pizza","Kalamata Pizza", "Garden Chesse Pizza"},
                    {"Shiitake Noodles", "Spicy Bamboo Noodles","Singapore Noodles", "Phad Thai"}
            };

    int FoodPrices[5][6]={
            {17, 16, 17, 19},
            {28, 28, 28, 28, 30},
            {29, 30, 32, 25},
            {25, 32, 31, 32, 31,32},
            {28, 28, 28, 28}
    };
    int DrinkPrices[7]={12, 13, 9, 15, 14, 12,10};
    int NoOfDrinks=7;
    char Drink[7][40]={"Banana Smothie", "Mango Smoothie", "Peach Smoothie","Orange Fresh","Green Apple","Ginger Beer","Goji Beer"};

    //Order details
    int CutleryChoice=0;
    char AddInfo[256];

    //Choices
    int choice, FoodChoice, TypeChoice, DrinkChoice;

    //Welcome message
    printf("Welcome to Samasara Foodhouse!\nPlease sign in to continue!\n");

    //Switch
    int state=0;
    int OrderConfirmed=0;

    while(!OrderConfirmed)
    {
        switch(state)
        {
            case 0:
            {
                //Sign in
                printf("---Username:\n>");
                gets(username);
                printf("---Password:\n>");
                gets(password);
                state++;
                break;
            }

            case 1:
                {
                //Choose the food
                printf("Please choose the food you feel like eating today:\n");
                for (int i = 0;i<NoOfFoods;i++)
                {
                    putchar('a'+i);
                    printf(") %s\n", Food[i]);
                }
                printf("%c) Go back\n>", 'a' + NoOfFoods);
                choice = getchar();

                // consume new line
                getchar();
                if (choice == 'a' + NoOfFoods)
                {
                    state--;
                    break;
                }
                FoodChoice = choice - 'a';
                state++;
                break;
            }

            case 2:
            {
                //Choose the food type
                printf("Please choose the type of %s\n",Food[FoodChoice]);
                for(int i=0; i<NoOfTypes[FoodChoice]; i++)
                {
                    putchar('a'+i);
                    printf(") %s (%d)\n",Types[FoodChoice][i], FoodPrices[FoodChoice][i]);
                }
                printf("%c) Go back\n>",'a'+NoOfTypes[FoodChoice]);
                choice = getchar();
                // consume new line
                getchar();
                if(choice=='a'+NoOfTypes[FoodChoice])
                {
                    state--;
                    break;
                }
                TypeChoice=choice-'a';
                state++;
                break;
            }

            case 3:
            {
                //Choose the drink
                printf("Please choose a drink to go with your %s:\n", Types[FoodChoice][TypeChoice]);
                for(int i=0;i<NoOfDrinks;i++)
                {
                    putchar('a' + i);
                    printf(") %s (%d)\n",Drink[i], DrinkPrices[i]);
                }
                printf("%c) Go back\n>",'a'+NoOfDrinks);
                choice = getchar();
                // consume new line
                getchar();
                if(choice=='a'+NoOfDrinks)
                {
                    state--;
                    break;
                }
                DrinkChoice=choice-'a';
                state++;
                break;
            }

            case 4:
            {
                printf("Do you want cutlery?\n");
                printf("a)Yes\n");
                printf("b)No, thanks!\n");
                printf("c)Go back\n>");
                choice = getchar();
                // consume new line
                getchar();
                if(choice==3)
                {
                    state--;
                    break;
                }
                if(choice=='a')
                    CutleryChoice=1;
                state++;
                break;
            }

            case 5:
            {
                printf("Any additional info?\n");
                gets(AddInfo);

                //Display Order
                printf("This is your order:\n");
                printf("-------------------\n");
                printf("Name :%s\n",username);
                printf("Food items: \n");
                printf("-%s: %d \n", Types[FoodChoice][TypeChoice],FoodPrices[FoodChoice][TypeChoice]);
                printf("-%s: %d \n", Drink[DrinkChoice],DrinkPrices[DrinkChoice]);
                printf("Cutlery: ");
                if(CutleryChoice==0)
                    printf("no\n");
                else
                    printf("yes\n");
                if(strcmp(AddInfo,"\0")!=0)
                    printf("Additional info: %s\n", AddInfo);
                printf("Payment amount: %d\n",FoodPrices[FoodChoice][TypeChoice]+DrinkPrices[DrinkChoice]);
                printf("-------------------\n");
                printf("a) Confirm Order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a')
                {
                    OrderConfirmed=1;
                    printf("Order confirmed! Thank you for buying from us, %s!\n", username);
                }
                else
                    state--;

                // consume new line
                getchar();
                break;

            }


        }
    }
    return 0;
}