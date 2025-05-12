
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#ifndef HEADER_H
#define HEADER_H

void print_menu();

void print_rules();

int user_choice();

void roll_dice(int dice[]);

void reroll_dice(int dice[]);

int select_combination();

int calculate_score(int combo, int dice[]);

int yahtzee_game(int player);

void clear_screen();

void clear_input_buffer();

int main();

#endif