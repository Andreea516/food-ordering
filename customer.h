//
// Created by Andreea on 06-Nov-19.
//

#ifndef FOOD_ORDERING_CUSTOMER_H
#define FOOD_ORDERING_CUSTOMER_H

//function declaration

typedef struct
{
    char *username;
    char *password;
}CUSTOMER;

CUSTOMER createCustomer();

void sign_in_or_up(CUSTOMER c);

void sign_in(CUSTOMER c);

int newUser(char input_username[], CUSTOMER c);

int isLength(char input_password[]);

int containsUsername(char input_username[], char input_password[]);

int containsSpecChar(char password_char);

int containsDigit(char password_char);

int validate2 (int(*fullFillsCondition)(char), char input_password[], char message[]);

void sign_up(CUSTOMER c);

void display_username(CUSTOMER c);

#endif //FOOD_ORDERING_CUSTOMER_H
