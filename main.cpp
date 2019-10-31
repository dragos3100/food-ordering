#include <stdio.h>

int main() {
    int noOffood = 3;
    int j;
    char food[][20]={"Pizza","Pasta","Salad"};
    char cutlery[][15]={"Yes","No"};
    int nofoodname[] = {3,2,4};
    char foodname[3][4][20] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
            {"Chicken alfredo", "Mac&cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad","Cobb"}
    };
    double prices[3][4] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}
    };
    double total;
    char username[20];
    char password[20];
    char info[50];
    int nodrinks = 4;
    char drinks[][20] = {"Coca-cola","Fanta","Lipton","Water","No thanks"};
    double drinksPrices[] = {5, 5, 5, 4, 0};
    int choice, foodChoice, foodnameChoice,cutleryChoice,drinkChoice;
    int noAddItemsChosen = 0;
    int state =0;
    int confirmorder = 0;
    while(!confirmorder){
        switch (state) {
            case 0: {
                printf("Welcome to Food Thingies!\n");
                printf("Please sign in to continue!\n");

                printf("---Username\n");
                gets(username);
                printf("---Password\n");
                gets(password);
                state++;
                break;
            }
            case 1: {
                printf("Please choose the food you feel like eating today:\n");
                for(int i=0;i<noOffood;i++) {
                    putchar('a'+i);
                    printf(") %s\n",food[i]);
                };
                printf("%c) Go back\n",'a'+noOffood);
                 choice = getchar();
                 foodChoice = choice - 'a';
                getchar();
                if(choice == 'a' +noOffood) {
                    state--;
                    break;
                }
                foodChoice = choice - 'a';

                state++;

                break;
            }
            case 2: {
                printf("Please choose the type of %s:\n",food[foodChoice]);
                for(int i=0;i<nofoodname[foodChoice];i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n",foodname[foodChoice][i], prices[foodChoice][i]);
                }
                printf("%c) Go back\n",'a'+nofoodname[foodChoice]);
                choice = getchar();
                getchar();
                if(choice == 'a'+nofoodname[foodChoice]) {
                    state--;
                    break;
                }
                foodnameChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                printf("Please choose a drink to go with your Pizza:\n");
                for(int i=0;i<nodrinks;i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n", drinks[i], drinksPrices[i]);
                }
                printf("%c) Go back\n",'a'+nodrinks);
                choice = getchar();
                 drinkChoice=choice-'a';

                if(choice == 'a'+nodrinks) {
                    state--;
                    getchar();
                    break;
                }

                state++;
                break;
            }
            case 4:{
                printf("Do you want cutlery?\n");
                for(j=0;j<2;j++) {
                    putchar('a' + j);
                    printf(") %s\n", cutlery[j]);
                }
                printf("%c) Go back\n",'a'+2);
                    choice = getchar();
                    getchar();
                 cutleryChoice = choice - 'a';
                if(choice == 'a'+2) {
                    state--;
                    getchar();
                    break;
                }
                cutleryChoice = choice - 'a';
                state++;
                break;

            }
            case 5:{
                printf("Any aditional info?\n");
                getchar();
                gets(info);
                state++;
                break;
            }
            case 6:{
                printf("This is your order:\n");
                printf("-------------\n");
                printf("-name: %s\n", username);
                printf("food items:\n");
                printf("--- %s (%.2f)\n", food[foodChoice][foodnameChoice], prices[foodChoice][foodnameChoice]);
                printf("--- %s (%.2f)\n", drinks[drinkChoice], drinksPrices[drinkChoice]);
                printf("Cutlery: %s\n",cutlery[cutleryChoice]);
                printf("Aditional info: %s\n", info);
                total=prices[foodChoice][foodnameChoice]+drinksPrices[drinkChoice];
                printf("Payment amount: %d\n", total);
                printf("-------------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    printf("Order confirmed! Thank you for buying from us, %s\n", username);
                    confirmorder = 1;
                } else {
                    state--;
                }
                getchar();
                break;
            }
        }
    }


    return 0;
}