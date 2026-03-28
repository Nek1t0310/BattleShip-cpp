#pragma once

constexpr int SIZE_ = 10;

void Menu();

void ClearBoard();

void imageBoard();

void Enter();

int InputInt(int min, int max);

int InputLetter(int min, int max);

void initField(char field[][SIZE_]);

void printField(char field[][SIZE_]);

bool ship(int x, int y, char field[][SIZE_], int choise, int length);

bool ship_destroy(int x, int y, char field[][SIZE_], char field2[][SIZE_]);
