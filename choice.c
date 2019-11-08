//
// Created by Dragos on 11/8/2019.
//
#include <stdio.h>
int getChoiceIndex(int noOfChoices, int *state) {
    int choiceIndex;
    char choice = getchar();
    // consume new line
    getchar();
    if(choice == 'a'+noOfChoices) {
        (*state)--;
    }
    else
    {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}