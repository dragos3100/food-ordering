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
    int nodrinks = 4;
    char drinks[][20] = {"Coca-cola","Fanta","Lipton","Water","No thanks"};
    double drinksPrices[] = {5, 5, 5, 4, 0};
    int choice, foodChoice, foodnameChoice,cutleryChoice;
    int noAddItemsChosen = 0;
    int state =0;
    int confirmorder = 0;
    while(!confirmorder){
        switch (state) {
            case 0: {
                printf("Welcome to Food Thingies!\n");
                printf("Please sign in to continue!\n");
                char username[20];
                char password[20];
                printf("---Username\n");
                gets(username);
                printf("---Password\n");
                gets(password);
                state++;
                break;
            }
            case 1: {
                // Choose the brand
                printf("Please choose the food you feel like eating today:\n");
                for(int i=0;i<noOffood;i++) {
                    putchar('a'+i);
                    printf(") %s\n",food[i]);
                };

                char choice = getchar();
                int foodChoice = choice - 'a';
                getchar();
                if(choice == 'a'+noOffood) {
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
                if(choice == 'a'+nodrinks) {
                    state--;
                    getchar();
                    break;
                }

                state++;
                break;
            }
            case 4:{
                printf("Do you want cutlery?");
                for(j=0;j<2;j++) {
                    putchar('a' + j);
                    printf(") %s\n", cutlery[j]);
                }
                    choice = getchar();
                    getchar();
                    int cutleryChoice = choice - 'a';
                if(choice == 'a'+2) {
                    state--;
                    break;
                }
                cutleryChoice = choice - 'a';
                state++;
                break;

            }

        }
    }


    return 0;
}