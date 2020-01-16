//
// Created by Dragos on 11/7/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#define MAX_LOGIN 20
login createLogin(){
    login a;
    a.username=(char*)malloc(MAX_LOGIN* sizeof(char));
    a.password=(char*)malloc(MAX_LOGIN* sizeof(char));
return a;
}
void cont(login * a){
    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue!\n");
    printf("---Username\n");
    gets(a->username);
    printf("---Password\n");
    gets(a->password);
}