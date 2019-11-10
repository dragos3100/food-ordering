#include <stdio.h>
#include "login.h"
#include "preference.h"
#include "print.h"
#include "choice.h"

int main() {
    int noOffood = 3,nocutlery=2, nofoodname[] = {3,2,4},nodrinks = 5,choice, foodChoice, foodnameChoice,cutleryChoice,drinkChoice,state =0,confirmorder = 0;
    char food[][20]={"Pizza","Pasta","Salad"}, cutlery[3][15]={"Yes","No"};
    char foodname[3][4][20] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},{"Chicken alfredo", "Mac&cheese"},{"Tuna Salad", "Chicken Salad", "Greek Salad","Cobb"}};
    double prices[3][4] = {{21, 23, 19},{23, 21},{23, 22, 19, 21}},drinksPrices[] = {5, 5, 5, 4, 0};
    char username[20],password[20],info[50],drinks[][20] = {"Coca-cola","Fanta","Lipton","Water","No thanks"};;
    while(!confirmorder){
        switch (state) {
            case 0: {
                cont(username, password);
                state++;
                break;
            }
            case 1: {
                showfood(noOffood,food);
                foodChoice=getChoiceIndex(noOffood, &state);
                break;
            }
            case 2: {
                showfoodname(food,foodname,foodChoice,nofoodname,prices);
                int a=nofoodname[foodChoice];
                foodnameChoice=getChoiceIndex(a, &state);
                break;
            }
            case 3: {
                showdrink(nodrinks,drinks,drinksPrices);
                drinkChoice=getChoiceIndex(nodrinks,&state);
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
            case 6:{showorder(username,drinks,foodname,foodChoice,foodnameChoice,drinkChoice,cutleryChoice,cutlery,info,prices,drinksPrices);
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
    return 0;
}