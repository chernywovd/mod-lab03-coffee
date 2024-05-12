// Copyright 2022 UNN-IASR
// Игорь Чернышов.
#pragma once
#include <iostream>
#include <string>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

using std::string;

class Automata {
public:
    int cash;  // - для хранения текущей суммы
    const string menu[13] = {
        "Espresso (Short Black)",
        "Double Espresso (Doppio)",
        "Short Macchiato",
        "Long Macchiato",
        "Ristretto",
        "Long Black (Americano)",
        "Cafe Latte",
        "Cappuccino",
        "Flat White",
        "Piccolo Latte",
        "Mocha",
        "Affogato",
        "Magic"
    };
    int option;  // - выбор напитка
    const double prices[13] = {
        95, 130, 125, 143, 155, 167.5, 145, 119, 140, 170, 145, 119, 128.5
    };
    STATES state;  // - текущее состояние автомата

public:
    Automata();
    void on();  // - включение автомата;
    void off();  // - выключение автомата;
    void coin(int x);  // - занесение денег на счёт пользователем;
    void getMenu();  // - считывание меню;
    void getState();  // - считывание текущего состояния для пользователя;
    void choice(int x);  // - выбор напитка пользователем;
    bool check();  // - проверка наличия необходимой суммы;
    void cancel();  // - отмена сеанса обслуживания пользователем;
    void cook();  // - имитация процесса приготовления напитка;
    void finish();  // - завершение обслуживания пользователя;
};
