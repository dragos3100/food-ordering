//
// Created by Dragos on 11/8/2019.
//
# include<stdio.h>
void showfood(int noOffood, char **food)
{
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOffood;i++) {
        putchar('a'+i);
        printf(") %s\n",food[i]);
    };
    printf("%c) Go back\n",'a'+noOffood);

}
void showfoodname(char **food, char ***foodname, int foodChoice, int nofoodname[], double **prices)
{
    printf("Please choose the type of %s:\n",food[foodChoice]);
    for(int i=0;i<nofoodname[foodChoice];i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",foodname[foodChoice][i], prices[foodChoice][i]);
    }
    printf("%c) Go back\n",'a'+nofoodname[foodChoice]);
}
void showdrink(int nodrinks, char **drinks, double*drinksPrices)
{
    printf("Please choose a drink to go with your Pizza:\n");
    for(int i=0;i<nodrinks;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n", drinks[i], drinksPrices[i]);
    }
    printf("%c) Go back\n",'a'+nodrinks);
}
void showcutlery(char cutlery[3][15])
{int j;
    printf("Do you want cutlery?\n");
    for(j=0;j<2;j++) {
        putchar('a' + j);
        printf(") %s\n", cutlery[j]);
    }
    printf("%c) Go back\n",'a'+2);
}
void typeinfo(char info[])
{
    printf("Any aditional info?\n");
    gets(info);
}