//
// Created by Dragos on 11/8/2019.
//
#include <stdio.h>
#include "login.h"

void showorder(login * a,char **drinks,char ***foodname,int foodChoice, int foodnameChoice,int drinkChoice, int cutleryChoice, char cutlery[3][15],char info[],double **prices, double *drinksPrices)
{   printf("This is your order:\n");
    printf("-------------\n");
    printf("-name: %s\n", a->username);
    printf("food items:\n");
    printf("dish--- %s (%.2f)\n", foodname[foodChoice][foodnameChoice], prices[foodChoice][foodnameChoice]);
    printf("drink--- %s (%.2f)\n", drinks[drinkChoice], drinksPrices[drinkChoice]);
    printf("Cutlery: %s\n",cutlery[cutleryChoice]);
    printf("Aditional info: %s\n", info);
    printf("Payment amount: %.2f\n", prices[foodChoice][foodnameChoice] + drinksPrices[drinkChoice]);
    printf("-------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}