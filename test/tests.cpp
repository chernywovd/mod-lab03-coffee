// Copyright 2022 GHA Test Team
// Чернышов Игорь
#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include "Automata.h"

using std::invalid_argument;
using std::domain_error;

TEST(test1, incorrect_operation) {
    Automata coffeeAutomata;
    coffeeAutomata.state = COOK;
    try {
        coffeeAutomata.finish();
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test2, incorrect_operation) {
    Automata coffeeAutomata;
    coffeeAutomata.state = ACCEPT;
    try {
        coffeeAutomata.choice(8);
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test3, incorrect_operation) {
    Automata coffeeAutomata;
    coffeeAutomata.state = OFF;
    try {
        coffeeAutomata.on();
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test4, incorrect_operation) {
    Automata coffeeAutomata;
    coffeeAutomata.state = WAIT;
    try {
        coffeeAutomata.coin(245);
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}


TEST(test5, incorrect_operation) {
    Automata coffeeAutomata;
    coffeeAutomata.state = CHECK;
    try {
        coffeeAutomata.cook();
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test6, incorrect_operation) {
    Automata coffeeAutomata;
    coffeeAutomata.state = ACCEPT;
    try {
        coffeeAutomata.choice(3);
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test7, incorrect_operation) {
    Automata coffeeAutomata;
    coffeeAutomata.state = WAIT;
    try {
        coffeeAutomata.off();
    }
    catch (domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test8, states) {
    Automata coffeeAutomata;
    coffeeAutomata.on();
    coffeeAutomata.coin(200);
    coffeeAutomata.choice(13);
    EXPECT_EQ(CHECK, coffeeAutomata.state);
}

TEST(test9, states) {
        Automata coffeeAutomata;
        coffeeAutomata.on();
        coffeeAutomata.coin(177);
        coffeeAutomata.choice(5);
        coffeeAutomata.cancel();
        EXPECT_EQ(WAIT, coffeeAutomata.state);
}

TEST(test10, states) {
    Automata coffeeAutomata;
    coffeeAutomata.on();
    coffeeAutomata.coin(500);
    EXPECT_EQ(ACCEPT, coffeeAutomata.state);
}



