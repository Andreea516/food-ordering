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
#define enc "._!abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQESTUVWXYZ0123456789"
#define key "Atbash Cipher with \"._!abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQESTUVWXYZ0123456789\""
#define MAX_KEY 256

void sign_in_or_up(FILE *user, int *noOfUsers, char username[]);

void encryption(char password[], char newPassword[])
{
    for(int i=0; i<strlen(password); i++)
    {
        for(int j=0; j<strlen(enc); j++)
        {
            if(password[i]==enc[j])
            {
                newPassword[i]=enc[strlen(enc)-j];
                break;
            }
        }
    }
}

void decryption(char password[], char newPassword[])
{
    for(int i=0; i<strlen(password); i++)
    {
        for(int j=strlen(enc); j>0; j--)
        {
            if(password[i]==enc[j])
            {
                newPassword[i]=enc[strlen(enc)-j];
            }

        }
    }
}


void sign_in(FILE *user, int *noOfUsers)
{
    char input_username[50], input_password[50],ok=0,s[256];
    char username[30], password[30], newPassword[30];
    printf("%s\n", SIGNING_IN);
    fopen("user", "r");
    fgets(user,s, MAX_KEY);
    fscanf(user, "%d", noOfUsers);
    while (ok==0)
    {
        int ok1=0;
        printf("---Username:\n>");
        gets(input_username);
        printf("---Password:\n>");
        gets(input_password);
        for(int i=0; i<noOfUsers; )
            {
                fscanf(user, "%s", username);
                fscanf(user, "%s", password);
                getchar();
                if(strcmp(input_username, username)==0)
                {
                    ok1=1;
                    decryption(password,newPassword);
                    if(strcmp(input_password, newPassword)==0)
                        ok=1;
                    else
                        printf("%s\n", INCORRECT_PASSWORD);
                }
                else
                    i++;
            }
        if(ok1==0)
        {
            printf("%s\n", USER_NOT_FOUND);
            ok=1;
            sign_in_or_up(user, &noOfUsers, username);
        }

    }
    fclose(user);
}

int newUser(char input_username[], int *noOfUsers, FILE *user)
{
    char username [30], password[30], s[MAX_KEY];
    fopen("user", "r");
    fgets(user,s, MAX_KEY);
    fscanf(user, "%d", noOfUsers);
    for(int i=0; i<noOfUsers; i++)
    {
        fscanf(user, "%s", username);
        fscanf(user, "%s", password);
        getchar();
        if (strcmp(input_username, username) == 0)
        {
            printf("%s\n", DUPLICATE_USER);
            return 0;
        }
    }
    fclose(user);
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

void sign_up(FILE *user, int *noOfUsers, char username[])
{
    int ok=0; char input_username[30], input_password[30], newPassword[30];
    printf("%s\n", SIGNING_UP);

    while (ok==0) {
        printf("---Username:\n>");
        gets(input_username);
        printf("---Password:\n>");
        gets(input_password);
        if (newUser(input_username, noOfUsers, user)==1)
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
    encryption(input_password, newPassword);
    noOfUsers++;
    fopen("user", "r+");
    fseek(user, 0, SEEK_SET);
    fprintf(user, "%s\n", key);
    fseek(user, 65, SEEK_SET);
    fprintf(user, "%d", noOfUsers);
    fclose(user);
    fopen("user", "a+");
    fprintf(user, "%s %s\n", input_username, newPassword);
    strcpy(username, input_username);
    fclose(user);
}

void sign_in_or_up(FILE *user, int *noOfUsers, char username[])
{
    char c;
    printf("%s\n", SIGN_IN_UP);
    printf("a)%s\n", SIGN_IN);
    printf("b)%s\n", SIGN_UP);
    c=getchar();
    getchar();
    if(c=='a')
    {
        sign_in(user, &noOfUsers);
    }
    else
    {
        if(c=='b')
            sign_up(user, &noOfUsers, username);
    }
}


void display_username(char username[])
{
    printf("Name: %s\n",username);
}


