//
// Created by Andreea on 06-Nov-19.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ERROR_PASSWORD_LONG	"The password must be at least 7 chars long"
#define ERROR_PASSWORD_NOT_USERNAME	"The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR	"The password must contain one of the following characters: {'.','_','!'}"
#define ERROR_PASSWORD_DIGITS	"The password must contain digits"
#define SIGN_IN_UP	"Do you want to sign in or sign up?"
#define SIGN_IN	"Sign in"
#define SIGN_UP	"Sign up"
#define SIGNING_IN	"Signing in!"
#define SIGNING_UP	"Signing up!"
#define USER_NOT_FOUND	"Username doesn't exist"
#define DUPLICATE_USER	"Please choose another username!"
#define INCORRECT_PASSWORD	"Incorrect password"

void sign_in_or_up(char username[], char password[]);

void sign_in(char username[], char password[])
{
    char input_username[50], input_password[50],ok=0;
    printf("%s\n", SIGNING_IN);
    while (ok==0)
    {
        printf("---Username:\n>");
        gets(input_username);
        printf("---Password:\n>");
        gets(input_password);
        if(strcmp(input_username, username)==0)
        {
            if(strcmp(input_password, password)==0)
                ok=1;
            else
                printf("%s\n", INCORRECT_PASSWORD);
        }
        else
        {
            printf("%s\n", USER_NOT_FOUND);
            ok=1;
            sign_in_or_up(username, password);
        }

    }
}

int newUser(char input_username[], char username[])
{
    if (strcmp(input_username, username) == 0)
    {
        printf("%s\n", DUPLICATE_USER);
        return 0;
    }
    return 1;
}

int isLength(char input_password[])
{
    if (strlen(input_password) < 7)
    {
        printf("%s\n", ERROR_PASSWORD_LONG);
        return 0;
    }
    return 1;
}

int containsUsername(char input_username[], char input_password[])
{
    if (strstr(input_password, input_username)!=0)
    {
        printf("%s\n", ERROR_PASSWORD_NOT_USERNAME);
        return 0;
    }
    return 1;
}

int containsSpecChar(char password_char)
{
    return (strchr("._!", password_char) != 0);
}

int containsDigit(char password_char)
{
    return isdigit(password_char);

}

int validate2 (int(*fullFillsCondition)(char), char input_password[], char message[])
{
    for (int i = 0; i < strlen(input_password); i++)
    {
        if (fullFillsCondition(input_password[i]))
        {
            return 1;
        }
    }
    printf("%s\n", message);
    return 0;
}

void sign_up(char username[])
{
    int ok=0; char input_username[50], input_password[50];
    printf("%s\n", SIGNING_UP);
    while (ok==0) {
        printf("---Username:\n>");
        gets(input_username);
        printf("---Password:\n>");
        gets(input_password);
        if (newUser(input_username, username)==1)
        {
            if (isLength(input_password)==1)
            {
                if (containsUsername(input_username, input_password)==1)
                {
                    ok=validate2(&containsSpecChar,input_password, ERROR_PASSWORD_SPECIAL_CHAR) && validate2(&containsDigit,input_password, ERROR_PASSWORD_DIGITS);
                }

            }
        }
    }
    strcpy(username, input_username);

}

void sign_in_or_up(char username[], char password[])
{
    char c;
    printf("%s\n", SIGN_IN_UP);
    printf("a)%s\n", SIGN_IN);
    printf("b)%s\n", SIGN_UP);
    c=getchar();
    getchar();
    if(c=='a')
    {
        sign_in(username, password);
    }
    else
    {
        if(c=='b')
            sign_up(username);
    }
}


void display_username(char username[])
{
    printf("Name: %s\n",username);
}


