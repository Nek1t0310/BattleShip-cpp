#include<iostream>
#include<string>
#include<windows.h>
#include"Header.h"
using namespace std;

HANDLE g = GetStdHandle(STD_OUTPUT_HANDLE);

void playGame()
{
	SetConsoleTextAttribute(g, 14);
	char FieldPlayer_1[SIZE_][SIZE_];
	char FieldPlayer_2[SIZE_][SIZE_];
	char FieldPlayerMark_1[SIZE_][SIZE_];
	char FieldPlayerMark_2[SIZE_][SIZE_];
	int player_status = 1;
	int x, y;
	int check = 0;
	int x_1, y_1;
	int choise_vector;
	int length;
	int Battle_Ships[] = { 0, 4, 3, 2, 1 };
	int WinnerPlayer_1 = 0;
	int WinnerPlayer_2 = 0;
	const int WinnerPoints = 20;

	initField(FieldPlayer_1);
	initField(FieldPlayer_2);
	initField(FieldPlayerMark_1);
	initField(FieldPlayerMark_2);

	ClearBoard();

	cout << "Время расставлять корабли!\n";
	cout << "Начинает 1 игрок!\n";

	while (check < 10) {
		ClearBoard();
		cout << "\t\tПервый игрок расставляет:" << endl << endl;
		printField(FieldPlayer_1);
		cout << endl;
		cout << "\tВведите координаты откуда будем устанавливать корабль:\n";
		cout << "\t\tВведите X: ";
		x_1 = InputInt(1, 10);
		cout << "\t\tВведите Y: ";
		y_1 = InputInt(1, 10);
		x_1--; y_1--;
		cout << "\t\tВведите направление корабля:\n";
		cout << "\t\t1 - Вверх; 2 - Вниз; 3 - Влево; 4 - Вправо\n";
		cout << "\t\tВаш выбор: ";
		choise_vector = InputInt(1, 4);
		cout << "\t\tУкажите длину корабля: ";
		length = InputInt(1, 4);

		if (Battle_Ships[length] == 0) {
			cout << "\t\tЭти корабли уже расставлены!\n";
			cout << "\t\tНажмите Enter что бы повторить...";
			Enter();
			ClearBoard();
			continue;
		}

		if (ship(x_1, y_1, FieldPlayer_1, choise_vector, length)) {
			Battle_Ships[length]--;
			check++;
		}
		else {
			cout << "\tКорабль расположен неверно, нажмите любую клавишу что бы повторить:";
			Enter();
		}
		ClearBoard();
		cout << "\t\tПервый игрок расставляет:" << endl;
		printField(FieldPlayer_1);
	}

	cout << "\tНажмите Enter что бы предоставить поле расстановки другому игроку...";
	Enter();
	//Sleep(1500);
	ClearBoard();

	check = 0;
	Battle_Ships[1] = 4;
	Battle_Ships[2] = 3;
	Battle_Ships[3] = 2;
	Battle_Ships[4] = 1;
	ClearBoard();
	cout << "\t\tНастало время для второго игрока!\n";

	while (check < 10) {
		ClearBoard();
		cout << "\t\tВторой игрок расставляет:" << endl;
		printField(FieldPlayer_2);
		cout << endl;
		cout << "\tВведите координаты откуда будем устанавливать корабль:\n";
		cout << "\t\tВведите X: ";
		x_1 = InputInt(1, 10);
		cout << "\t\tВведите Y: ";
		y_1 = InputInt(1, 10);
		x_1--; y_1--;
		cout << "\t\tВведите направление корабля:\n";
		cout << "\t\t1 - Вверх; 2 - Вниз; 3 - Влево; 4 - Вправо\n";
		cout << "\t\tВаш выбор: ";
		choise_vector = InputInt(1, 4);
		cout << "\t\tУкажите длину корабля: ";
		length = InputInt(1, 4);

		if (Battle_Ships[length] == 0) {
			cout << "\t\tЭти корабли уже расставлены!\n";
			cout << "\t\tНажмите Enter что бы повторить...";
			Enter();
			ClearBoard();
			continue;
		}

		if (ship(x_1, y_1, FieldPlayer_2, choise_vector, length)) {
			Battle_Ships[length]--;
			check++;
		}
		else {
			cout << "\tКорабль расположен неверно, нажмите любую клавишу что бы повторить:";
			Enter();
		}
		ClearBoard();
		cout << "\t\tВторой игрок расставляет:" << endl;
		printField(FieldPlayer_2);
	}

	cout << "\t\tНажмите Enter что бы начать игру...";
	Enter();

	while (true) {
		ClearBoard();
		cout << "\t\t   ~~~~~~~~~~~~~~~~~~~~~~" << "\n";
		cout << "\t\t   ~~~ИГРА МОРСКОЙ БОЙ~~~" << endl;
		cout << "\t\t   ~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
		Sleep(1000);

		if (player_status == 1) {
			cout << "\t\tХод 1-го игрока\n";
			cout << "\t\tПоле первого игрока:\n\n";

			printField(FieldPlayer_1);

			cout << "\t\tПоле для отметок 1 игрока:\n\n";

			printField(FieldPlayerMark_1);
		}
		else {
			cout << "\t\tХод 2-го игрока\n";
			cout << "\t\tПоле второго игрока:\n\n";

			printField(FieldPlayer_2);

			cout << "\t\tПоле для отметок 2 игрока:\n\n";

			printField(FieldPlayerMark_2);
		}

		while (true) {
			cout << "\t\tВведите координаты для выстрела:\n";
			cout << "\t\tВведите X: ";
			x = InputInt(1, 10);
			cout << "\t\tВведите Y: ";
			y = InputInt(1, 10);

			x = x - 1;
			y = y - 1;

			if (player_status == 1) {
				if (FieldPlayer_2[y][x] == '.' || FieldPlayer_2[y][x] == 'X') {
					cout << "\t\tВы уже стреляли в эту клетку!\n";
					continue;
				}
				if (FieldPlayer_2[y][x] == '~') {
					FieldPlayerMark_1[y][x] = '.'; FieldPlayer_2[y][x] = '.';
				}
				if (FieldPlayer_2[y][x] == '#') {
					FieldPlayerMark_1[y][x] = 'X'; FieldPlayer_2[y][x] = 'X';
					WinnerPlayer_1++;

					if (WinnerPlayer_1 == WinnerPoints) {
						ClearBoard();
						cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\t~~~Первый игрок победил!~~~" << endl;
						cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\tВзглянем на результаты игры!" << endl << endl;
						cout << "\t\tПервый	игрок:" << endl;
						printField(FieldPlayer_1);
						cout << "\t\tВторой игрок:" << endl;
						printField(FieldPlayer_2);
						cout << "\n\t\tНажмите Enter что бы закончить...";
						Enter();
						return ;
					}
					ClearBoard();
					cout << "\t\tВаш ход:" << endl << endl;
					cout << "\n\t\tВы попали во вражеский корабль!\n";
					ship_destroy(x, y, FieldPlayer_2, FieldPlayerMark_1);
					printField(FieldPlayerMark_1);
					cout << "\t\tВы можете сделать ещё 1 ход!\n";
					cout << "\t\tНажмите на Enter что бы продолжить...";
					Enter();
					continue;
				}
				ClearBoard();
				cout << "\t\tВаш ход:\n\n";
				printField(FieldPlayerMark_1);
			}
			else {
				if (FieldPlayer_1[y][x] == '.' || FieldPlayer_1[y][x] == 'X') {
					cout << "\t\tВы уже стреляли в эту клетку!\n";
					continue;
				}
				if (FieldPlayer_1[y][x] == '~') {
					FieldPlayerMark_2[y][x] = '.'; FieldPlayer_1[y][x] = '.';
				}
				if (FieldPlayer_1[y][x] == '#') {
					FieldPlayerMark_2[y][x] = 'X'; FieldPlayer_1[y][x] = 'X';
					WinnerPlayer_2++;

					if (WinnerPlayer_2 == WinnerPoints) {
						ClearBoard();
						cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\t~~~Второй игрок победил!~~~" << endl;
						cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\tПервый	игрок:" << endl;
						printField(FieldPlayer_1);
						cout << "\t\tВторой игрок:" << endl;
						printField(FieldPlayer_2);
						cout << "\n\t\tНажмите Enter что бы закончить...";
						Enter();
						return ;
					}
					ClearBoard();
					cout << "\t\tВаш ход:" << endl << endl;
					cout << "\n\t\tВы попали во вражеский корабль!\n";
					ship_destroy(x, y, FieldPlayer_1, FieldPlayerMark_2);
					printField(FieldPlayerMark_2);
					cout << "\t\tВы можете сделать ещё 1 ход!\n";
					cout << "\t\tНажмите на Enter что бы продолжить...";
					Enter();
					continue;
				}
				ClearBoard();
				cout << "\t\tВаш ход:\n\n";
				printField(FieldPlayerMark_2);
			}
			break;
		}

		cout << "\tНажмите Enter что бы передать ход другому игроку...";
		Enter();

		if (player_status == 1) { player_status = 2; }
		else player_status = 1;
	}
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int exit = 1;
	int accept;
	
	while (exit) {
		ClearBoard();
		imageBoard();
		SetConsoleTextAttribute(g, 14);
		cout << "\t ╔══════════════════════════════════════════╗\n";
		cout << "\t ║             ВЫБЕРИТЕ ДЕЙСТВИЕ:           ║\n";
		cout << "\t ╠══════════════════════════════════════════╣\n";
		cout << "\t ║~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~║\n";
		cout << "\t ║           [1] НАЧАТЬ ИГРУ                ║\n";
		cout << "\t ║           [2] ПРАВИЛА ИГРЫ               ║\n";
		cout << "\t ║           [3] ВЫЙТИ                      ║\n";
		cout << "\t ║~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~║\n";
		cout << "\t ╚══════════════════════════════════════════╝\n\n";

		cout << "\t\tВведите пункт из меню: ";
		accept = InputInt(1, 3);

		switch (accept) {
		case 1: {
			playGame();
			break;
		}
		case 2: {
			ClearBoard();
			Menu();
			cout << "\t\tНажмите Enter что бы вернуться к меню...";
			Enter();
			ClearBoard();
			break;
		}
		case 3: {
			exit = 0;
			cout << endl;
			cout << "\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "\t\t  ~~~~~ИГРА ЗАВЕРШЕНА~~~~~\n";
			cout << "\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~";
			break;
		}
		default:
			break;
		}
	}
	SetConsoleTextAttribute(g, 7);
}