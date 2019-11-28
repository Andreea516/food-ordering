//
// Created by Andreea on 06-Nov-19.
//

#ifndef FOOD_ORDERING_CUSTOMER_H
#define FOOD_ORDERING_CUSTOMER_H

//function declaration


void sign_in_or_up(char username[], char password[]);

void sign_in(char username[], char password[]);

int newUser(char input_username[], char username[]);

int isLength(char input_password[]);

int containsUsername(char input_username[], char input_password[]);

int containsSpecChar(char password_char);

int containsDigit(char password_char);

int validate2 (int(*fullFillsCondition)(char), char input_password[], char message[]);

void sign_up(char username[]);

void display_username(char username[]);

#endif //FOOD_ORDERING_CUSTOMER_H
