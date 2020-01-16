//
// Created by Dragos on 11/7/2019.
//

#ifndef FOOD_ORDERING_LOGIN_H
#define FOOD_ORDERING_LOGIN_H
typedef struct _login{
    char *username;
    char *password;
}login;
login createLogin();
void cont(login * a);

#endif //FOOD_ORDERING_LOGIN_H
