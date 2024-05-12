// Copyright 2022 UNN-IASR
// Чернышов Игорь
#include <iostream>
#include <string>
#include <stdexcept>
#include "Automata.h"

using std::invalid_argument;
using std::domain_error;

using std::cout;
using std::endl;




Automata::Automata() {
    state = OFF;
    cash = 0;
    option = 0;
    getState();
}

void Automata::getMenu() {
    for (int i = 0; i < 13; i++) {
        cout << i + 1 << ": " << menu[i] << " - " << prices[i] << endl;
    }
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        cout << "Добро пожаловать!" << endl;
        getMenu();
        getState();
    }    else {
        throw domain_error("Ошибка включения кофе-машины");
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        getState();
    }    else {
        throw domain_error("Ошибка включения кофе-автомата");
    }
}

void Automata::coin(int coinAddValue) {
    if (state == WAIT || state == ACCEPT) {
        if (coinAddValue < 0) {
            throw domain_error("Ошибка кофе-автомата. 
                Обратитесь к администратору.");
        }
        state = ACCEPT;
        cash += coinAddValue;
        getState();
    }
    else {
        throw domain_error("Ошибка кофе-автомата. Обратитесь к администратору.");
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cout << "Баланса недостаточно. Внесите дополнительные монеты в монетоприемник" << endl;
        getState();
    }
    else {
        throw domain_error("Ошибка кофе-автомата. Обратитесь к администратору.");
    }
}

void Automata::choice(int menu_position) {
    if (state == ACCEPT) {
        if (sizeof(menu) < menu_position || menu_position <= 0) {
            cout << "Выберите корректную позицию напитка в меню" << endl;
        }
        state = CHECK;
        option = menu_position;
        cout << "Ваш напиток - " << menu[option - 1] << endl;
        getState();
    }
    else {
        throw domain_error("Ошибка кофе-автомата. Обратитесь к администратору.");
    }
}

bool Automata::check() {
    if (state == CHECK) {
      
        if (cash >= prices[option]) {
            cout << "Баланса достаточно. Начинаем приготовление!" << endl;
            return true;
        }
        else {
            cout << "Баланса недостаточно. Внесите дополнительные монеты в монетоприемник" << endl;
        }

        
        return false;
    }
    else {
        throw domain_error("Ошибка кофе-автомата. Обратитесь к администратору.");
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[option];
        getState();
    }
    else {
        throw domain_error("Ошибка кофе-автомата. Обратитесь к администратору.");
    }
}

void Automata::finish() {
    if (state == COOK) {
        state = WAIT;
        cout << "Спасибо, что выбрали наш напиток! Аккуратно, горячий стаканчик!" << endl;
        getMenu();
        getState();
    }
    else {
        cout << "Ошибка кофе-автомата. Обратитесь к администратору." << endl;
    }
}


void Automata::getState() {
    switch (state) {

    case WAIT:
        cout << "Внесите монеты в монетоприемник" << endl;
        break;

    case ACCEPT:
        cout << "Текущий баланс - " << cash << endl;
        cout << "Выберите Ваш напиток." << endl;
        break;

    case CHECK:
        cout << "Проверяем достаточность внесенных средств" << endl;
        break;

    case COOK:
        cout << "Ваш напиток готовится. Ожидайте..." << endl;
        break;

    case OFF:
        cout << "Кофе-автомат выключен." << endl;
        break;
    }
}
