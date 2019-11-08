//
// Created by Dragos on 11/7/2019.
//

#include <stdio.h>

void cont(char username[20],char password[20]){
    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue!\n");
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    gets(password);
}