// Copyright 2022 UNN-IASR
// Чернышов Игорь
#include <iostream>
#include <string>
#include "Automata.h"
#include <clocale>


int main() {
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали для русского языка
    Automata coffeeAutomata;
    coffeeAutomata.on();
    coffeeAutomata.coin(1000);
    coffeeAutomata.choice(10);  
    if (coffeeAutomata.check()) {
        coffeeAutomata.cook();
        coffeeAutomata.finish();
    }
    else {
        coffeeAutomata.cancel();
    }
    coffeeAutomata.off();
    return 0;
}
