//
// Created by Andreea on 06-Nov-19.
//
#include <stdio.h>

void sign_in(char username[], char password[])
{
    printf("---Username:\n>");
    gets(username);
    printf("---Password:\n>");
    gets(password);
}

void display_username(char username[])
{
    printf("Name: %s\n",username);
}


