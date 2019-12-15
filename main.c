#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "preference.h"
#include "print.h"
#include "choice.h"
#include "string.h"

#define MAX_FOOD_NAME 50
#define MAX_DRINK_NAME 50
#define MAX_FOODTYPE_NAME 50
#define MAX_LINE 100
void readFoodTypes(char * model);
void readFoodType(char * model);
int main() {
    int nocutlery=2,choice, foodChoice, foodnameChoice,cutleryChoice,drinkChoice,state =0,confirmorder = 0;
    char  cutlery[3][15]={"Yes","No"};
    char username[20],password[20],info[50];
    char delim[]=" ";
    char delimi[]="(";
    char delims[]=":)-";
    char *token;
    printf("Please load the data \n");
    int noOfFood;
    char line[MAX_LINE];
    gets(line);
    token = strtok(line, delims);
    noOfFood=atoi(token);
    char ** food;
    food = (char**)malloc(noOfFood* sizeof(char*));
    int * noOfFoodTypes= (int*)malloc(noOfFood * sizeof(int));
    char *** FoodTypes = (char***)malloc(noOfFood * sizeof(char**));
    double ** prices = (double**)malloc(noOfFood* sizeof(double*));

    for(int i=0; i<noOfFood; i++) {

        food[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));

        gets(line);
        token=strtok(line, delim);
        strcpy(food[i],token);
        token = strtok(NULL, delims);
        noOfFoodTypes[i]=atoi(token);
        FoodTypes[i] = (char**)malloc(noOfFoodTypes[i]* sizeof(char*));
        prices[i] = (double*)malloc(noOfFoodTypes[i]* sizeof(double));
        for(int j=0; j<noOfFoodTypes[i]; j++)
        {
            FoodTypes[i][j] = (char*)malloc(MAX_FOODTYPE_NAME* sizeof(char));
            token=strtok(NULL, delimi);
            token = strtok(NULL, delims);
            strcpy(FoodTypes[i][j],token);
            token=strtok(NULL, delims);
            prices[i][j]=atoi(token);

        }
    }
    int noOfDrinks;
    gets(line);
    token = strtok(line, delims);
    noOfDrinks=atoi(token);
    char ** drinks = (char**)malloc(noOfDrinks* sizeof(char*));
    double * drinksPrices = (double*)malloc(noOfDrinks* sizeof(double));
    gets(line);

    for(int i=0;i<noOfDrinks;i++) {

        drinks[i] = (char*)malloc(MAX_DRINK_NAME* sizeof(char));
if(i==0)
{
    token=strtok(line, delims);
    strcpy(drinks[i],token+1);
}
else
{
    token=strtok(NULL,delims);
    strcpy(drinks[i],token+2);
}
        token=strtok(NULL, delims);
        drinksPrices[i]=atoi(token);

    }
    // display data
    printf("The food data is:\n");
    for(int i=0;i<noOfFood;i++) {
        // display brand
        printf("%s: ", food[i]);
        for(int j=0;j<noOfFoodTypes[i];j++) {
            printf("%s (%.2lf)",FoodTypes[i][j],prices[i][j]);
            if(j<noOfFoodTypes[i]-1){
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("The drink data is:\n");
    printf("drinks: ");
    for(int i=0;i<noOfDrinks;i++){
        printf("%s (%.2lf)",drinks[i],drinksPrices[i]);
        if(i<noOfDrinks-1){
            printf(", ");
        }
    }
    printf("\n");

    while(!confirmorder){
        switch (state) {
            case 0: {
                cont(username, password);
                state++;
                break;
            }
            case 1: {
                showfood(noOfFood,food);
                foodChoice=getChoiceIndex(noOfFood, &state);
                break;
            }
            case 2: {
                showfoodname(food,FoodTypes,foodChoice,noOfFoodTypes,prices);
                int a=noOfFoodTypes[foodChoice];
                foodnameChoice=getChoiceIndex(a, &state);
                break;
            }
            case 3: {
                showdrink(noOfDrinks,drinks,drinksPrices);
                drinkChoice=getChoiceIndex(noOfDrinks,&state);
                break;
            }
            case 4:{
                showcutlery(cutlery);
                cutleryChoice =getChoiceIndex(nocutlery,&state);
                break;
            }
            case 5:{
                typeinfo(info);
                state++;
                break;
            }
            case 6:{showorder(username,drinks,FoodTypes,foodChoice,foodnameChoice,drinkChoice,cutleryChoice,cutlery,info,prices,drinksPrices);
                choice = getchar();
                if(choice=='a') {
                    printf("Order confirmed! Thank you for buying from us, %s!\n", username);
                    confirmorder = 1;
                } else {
                    state--;
                }
                getchar();
                break;
            }
        }
    }
    for(int i=0;i<noOfFood;i++) {
        for(int j=0;j<noOfFoodTypes[i];j++) {
            free(FoodTypes[i][j]);
        }
        free(FoodTypes[i]);
        free(prices[i]);
        free(food[i]);
    }
    free(FoodTypes);
    free(prices);
    free(food);
    free(noOfFoodTypes);
    for(int i=0;i<noOfDrinks;i++){
        free(drinks[i]);
    }
    free(drinks);
    free(drinksPrices);
    return 0;
}
void readFoodTypes(char * FoodTypes) {
    char c = getchar();
    int i=0;
    while(c!=' ') {
        FoodTypes[i] = c;
        c = getchar();
        i++;
    }
    FoodTypes[i] = '\0';
}
void readFoodType(char * FoodTypes) {
    char c = getchar();
    int i=0;
    while(c!='-') {
        FoodTypes[i] = c;
        c = getchar();
        i++;
    }
    FoodTypes[i] = '\0';
}