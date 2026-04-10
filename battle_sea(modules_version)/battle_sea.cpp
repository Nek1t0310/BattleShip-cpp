#include<iostream>
#include<string>
#include<windows.h>
#include"Header.h"
using namespace std;

HANDLE g = GetStdHandle(STD_OUTPUT_HANDLE);

void playBot() {
	char FieldHuman[SIZE_][SIZE_];
	char FieldBot[SIZE_][SIZE_];
	char FieldHumanMark[SIZE_][SIZE_];
	char FieldBotMark[SIZE_][SIZE_];
	int player_status = 1;
	int x, y;
	int check = 0;
	int x_1, y_1;
	int choice_vector;
	int length;
	int choice_arrangements;
	int Battle_Ships[] = {0, 4, 3, 2, 1};
	int WinnerPlayer = 0;
	int WinnerBot = 0;
	const int WinnerPoints = 20;
	bool bot_hit = false;
	int temporary_X = 0;
	int temporary_Y = 0;

	initField(FieldHuman);
	initField(FieldHumanMark);
	initField(FieldBot);
	initField(FieldBotMark);

	srand(time(NULL));

	ClearBoard();

	cout << "\n\n\t\tРежим игры с ботом..." << endl;
	cout << "\t\tРасстановку начинает игрок..." << endl;

	bool arrangementOption = false; // флаг для выхода из основного цикла
	while (arrangementOption == false) { // цикл выбора расстановки из предложенных(1 игрок)
		string s;
		cout << "\t\tХотите выбрать расстановку из предложенных 10 вариантов? [y/n] \n\n";
		cout << "\t\t";

		while (true) {
			getline(cin, s);
			if (s != "y" && s != "n") {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\t\tВведите либо y(yes), либо n(no): ";
				continue;
			}
			else {
				break;
			}
		}

		if (s == "y") {
			int flag = 0; // флаг для выхода из цикла выбора расстановки
			while (flag < 2) {
				ClearBoard();
				cout << "Выберите расстановку из предложенных(1 - 10): ";
				choice_arrangements = InputInt(1, 10);
				ready_arrangements(FieldHuman, choice_arrangements);
				cout << "Нажмите 1 что бы продолжить выбор, и 2 что бы выбрать расстановку: ";
				flag = InputInt(1, 2);
				ClearBoard();
			}
			arrangementOption = true;
		}
		else {
			arrangementOption = true;
			break;
		}
		check = 10; // засчитываем все корабли игроку
	}

	while (check < 10) { // цикл расстановки игрока
		ClearBoard();
		cout << "\t\tИгрок расставляет:\n\n";
		printField(FieldHuman);
		cout << endl;
		cout << "\tВведите координаты откуда будем устанавливать корабль:\n";
		cout << "\t\tВведите горизонталь: ";
		x_1 = InputLetter(0, 9);
		cout << "\t\tВведите вертикаль: ";
		y_1 = InputInt(1, 10);
		y_1--;
		cout << "\t\tВведите направление корабля:\n";
		cout << "\t\t1 - Вверх; 2 - Вниз; 3 - Влево; 4 - Вправо\n";
		cout << "\t\tВаш выбор: ";
		choice_vector = InputInt(1, 4);
		cout << "\t\tУкажите длину корабля: ";
		length = InputInt(1, 4);

		if (Battle_Ships[length] == 0) {
			cout << "\t\tЭти корабли уже расставлены!\n";
			cout << "\t\tНажмите Enter что бы повторить...";
			Enter();
			ClearBoard();
			continue;
		}

		if (ship(x_1, y_1, FieldHuman, choice_vector, length)) {
			Battle_Ships[length]--;
			check++;
		}
		else {
			cout << "\tКорабль расположен неверно, нажмите любую клавишу что бы повторить:";
			Enter();
		}
		ClearBoard();
		cout << "\t\tИгрок расставляет:" << endl;
		printField(FieldHuman);
	}

	cout << "\tНажмите Enter что бы предоставить поле расстановки другому игроку...";
	Enter();

	cout << "Расстановка бота: ";
	int bot_choice = 1 + rand() % 10;
	ready_arrangements(FieldBot, bot_choice);
	// чистим, что бы игрок не видел расстановку бота
	ClearBoard();

	cout << "\n";

	cout << "Расстановка игрока: \n\n";
	printField(FieldHuman);

	cout << "Бот готов к игре и ждёт вас\n";
	cout << "Нажмите Enter что бы продолжить...";
	Enter();

	while (true) {
		ClearBoard();
		ClearBoard();
		cout << "\t\t   ~~~~~~~~~~~~~~~~~~~~~~" << "\n";
		cout << "\t\t   ~~~ИГРА МОРСКОЙ БОЙ~~~" << endl;
		cout << "\t\t   ~~~~~~~~~~~~~~~~~~~~~~" << "\n\n";
		Sleep(400);

		if (player_status == 1) {
			cout << "\t\tХод игрока\n";
			cout << "\t\tПоле игрока: \n\n";

			printField(FieldHuman);

			cout << "\t\tПоле для отметок игрока: \n\n";

			printField(FieldHumanMark);
		}
		else {
			cout << "ХОД БОТА\n";
			cout << "Атака на поле игрока: \n\n";

			printField(FieldHuman);
		}

		while (true) {
			if (player_status == 1) { // если ход игрока

				cout << "\t\tВведите координаты для выстрела:\n";
				cout << "\t\tВведите горизонталь: ";
				x = InputLetter(0, 9);
				cout << "\t\tВведите вертикаль: ";
				y = InputInt(1, 10);

				y = y - 1;

				if (FieldBot[y][x] == '.' || FieldBot[y][x] == 'X') {
					cout << "\t\tВы уже стреляли в эту клетку!\n";
					continue;
				}
				else if (FieldBot[y][x] == '~') {
					FieldHumanMark[y][x] = '.';
					FieldBot[y][x] = '.';
				}
				else if (FieldBot[y][x] == '#') {
					FieldHumanMark[y][x] = 'X';
					FieldBot[y][x] = 'X';
					WinnerPlayer++;

					if (WinnerPlayer == WinnerPoints) {
						ClearBoard();
						cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\t~~~~~~Игрок победил!~~~~~~~" << endl;
						cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\tВзглянем на результаты игры!" << endl << endl;
						cout << "\t\tПервый	игрок:" << endl;
						printField(FieldHuman);
						cout << "\t\tБот:" << endl;
						printField(FieldBot);
						cout << "\n\t\tНажмите Enter что бы закончить...";
						Enter();
						return;
					}
					ClearBoard();
					cout << "\t\tВаш ход:" << endl << endl;
					cout << "\n\t\tВы попали во вражеский корабль!\n";
					ship_destroy(x, y, FieldBot, FieldHumanMark);
					printField(FieldHumanMark);
					cout << "\t\tВы можете сделать ещё 1 ход!\n";
					cout << "\t\tНажмите на Enter что бы продолжить...";
					Enter();
					continue;
				}
				ClearBoard();
				cout << "\t\tВаш ход:\n\n";
				printField(FieldHumanMark);
			}
			else { // если ход бота

				if (bot_hit == true) {
					int attempts = 0; // счётчик попыток бота попасть в корабль

					while (true) {
						attempts++;

						int radius = 1;
						if (attempts > 30) radius = 2;
						if (attempts > 60) radius = 3;

						// rand() % 2 выдаст либо 0, либо 1
						int axis = rand() % 2; // переменная которая отвечает за рандом оси по которой стреляет бот
						// тут либо +1, либо -1
						int delta = (rand() % (radius * 2 + 1)) - radius; // переменная которая отвечает за рандом стрельбы по оси (+1/-1)
						if (delta == 0) continue; // исключаем попытку стрельбы по опорной координате, от которой идёт рандом

						if (axis == 0) {
							x = temporary_X + delta;
							y = temporary_Y;
						}
						else {
							x = temporary_X;
							y = temporary_Y + delta;
						}

						if (x < 0 || x > 9 || y < 0 || y > 9 || FieldHuman[y][x] == '.' || FieldHuman[y][x] == 'X') {
							continue;
						}
						else break;
					}
				}
				else {
					while (true) {
						x = rand() % 10;
						y = rand() % 10;

						if (FieldHuman[y][x] == '.' || FieldHuman[y][x] == 'X') {
							continue;
						}
						else break;
					}
				}
				if (FieldHuman[y][x] == '~') {
					FieldHuman[y][x] = '.';
					FieldBotMark[y][x] = '.';
				}
				else if (FieldHuman[y][x] == '#') {
					FieldHuman[y][x] = 'X';
					FieldBotMark[y][x] = 'X';
					WinnerBot++;

					// фиксируем попадание для дальнейших атак бота
					temporary_X = x;
					temporary_Y = y;

					if (WinnerBot == WinnerPoints) {
						ClearBoard();
						cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\t~~~~~~~~Бот победил!~~~~~~~" << endl;
						cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\tВзглянем на результаты игры!" << endl << endl;
						cout << "\t\tИгрок:" << endl;
						printField(FieldHuman);
						cout << "\t\tБот:" << endl;
						printField(FieldBot);
						cout << "\t\tПоле отметок бота:" << endl;
						printField(FieldBotMark);
						cout << "\n\t\tНажмите Enter что бы закончить...";
						Enter();
						return;
					}
					ClearBoard();
					cout << "\n\t\tБот попал по вашему кораблю!\n";
					if (ship_destroy(x, y, FieldHuman, FieldBotMark) == false) {
						bot_hit = true;
					}
					else {
						bot_hit = false;
					}
					printField(FieldHuman);
					cout << "\t\tБот продолжает атаковать!\n";
					cout << "\t\tНажмите на Enter что бы продолжить...";
					Enter();
					continue;
				}
				ClearBoard();
				cout << "\t\tХод бота\n\n";
				printField(FieldHuman);
				cout << "\n\t\tНажмите Enter что бы ходить...";
				Enter();
			}
			break;
		}

		if (player_status == 1) {
			cout << "\tНажмите Enter что бы передать ход боту...";
			Enter();
		}

		// передаём статус 
		if (player_status == 1 ) {
			player_status = 2;
		} else {
			player_status = 1;
		}
	}
}

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
	int choice_arrangements;
	int Battle_Ships[] = { 0, 4, 3, 2, 1 };
	int WinnerPlayer_1 = 0;
	int WinnerPlayer_2 = 0;
	const int WinnerPoints = 20;

	initField(FieldPlayer_1);
	initField(FieldPlayer_2);
	initField(FieldPlayerMark_1);
	initField(FieldPlayerMark_2);

	ClearBoard();

	cout << "\t\tВремя расставлять корабли!\n";
	cout << "\t\tНачинает 1 игрок!\n";

	bool arrangementOption = false; // флаг для выхода из основного цикла
	while (arrangementOption == false) { // цикл выбора расстановки из предложенных(1 игрок)
		string s;
		cout << "\t\tХотите выбрать расстановку из предложенных 10 вариантов? [y/n] \n\n";
		cout << "\t\t";

		while (true) {
			getline(cin, s);
			if (s != "y" && s != "n") {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\t\tВведите либо y(yes), либо n(no): ";
				continue;
			}
			else {
				break;
			}
		}

		if (s == "y") {
			int flag = 0; // флаг для выхода из цикла выбора расстановки
			while (flag < 2) {
				ClearBoard();
				cout << "Выберите расстановку из предложенных(1 - 10): ";
				choice_arrangements = InputInt(1, 10);
				ready_arrangements(FieldPlayer_1, choice_arrangements);
				cout << "Нажмите 1 что бы продолжить выбор, и 2 что бы выбрать расстановку: ";
				flag = InputInt(1, 2);
				ClearBoard();
			}
			arrangementOption = true;
		}
		else {
			break;
		}
		check = 10; // засчитываем все корабли игроку
	}

	while (check < 10) { // цикл расстановки первого игрока
		ClearBoard();
		cout << "\t\tПервый игрок расставляет:\n\n";
		printField(FieldPlayer_1);
		cout << endl;
		cout << "\tВведите координаты откуда будем устанавливать корабль:\n";
		cout << "\t\tВведите горизонталь: ";
		x_1 = InputLetter(0, 9);
		cout << "\t\tВведите вертикаль: ";
		y_1 = InputInt(1, 10);
		y_1--;
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

	arrangementOption = false;
	while (arrangementOption == false) { // цикл выбора расстановки из предложенных(1 игрок)
		string s;
		cout << "\t\tХотите выбрать расстановку из предложенных 10 вариантов? [y/n] \n\n";
		cout << "\t\t";

		while (true) {
			getline(cin, s);
			if (s != "y" && s != "n") {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\t\tВведите либо y(yes), либо n(no): ";
				continue;
			}
			else {
				break;
			}
		}

		if (s == "y") {
			int flag = 0;
			while (flag < 2) {
				ClearBoard();
				cout << "Выберите расстановку из предложенных(1 - 10): ";
				choice_arrangements = InputInt(1, 10);
				ready_arrangements(FieldPlayer_2, choice_arrangements);
				cout << "Нажмите 1 что бы продолжить выбор, и 2 что бы выбрать расстановку: ";
				flag = InputInt(1, 2);
				ClearBoard();
			}
			arrangementOption = true;
		}
		else {
			break;
		}
		check = 10; // засчитываем все корабли игроку
	}

	while (check < 10) { // цикл расстановки второго игрока
		ClearBoard();
		cout << "\t\tВторой игрок расставляет:\n\n";
		printField(FieldPlayer_2);
		cout << endl;
		cout << "\tВведите координаты откуда будем устанавливать корабль:\n";
		cout << "\t\tВведите горизонталь: ";
		x_1 = InputLetter(0, 9);
		cout << "\t\tВведите вертикаль: ";
		y_1 = InputInt(1, 10);
		y_1--;
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
			cout << "\t\tВведите горизонталь: ";
			x = InputLetter(0, 9);
			cout << "\t\tВведите вертикаль: ";
			y = InputInt(1, 10);

			//x = x - 1;
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
		cout << "\t ║           [2] ИГРАТЬ С БОТОМ             ║\n";
		cout << "\t ║           [3] ПРАВИЛА ИГРЫ               ║\n";
		cout << "\t ║           [4] ВЫЙТИ                      ║\n";
		cout << "\t ║~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~║\n";
		cout << "\t ╚══════════════════════════════════════════╝\n\n";

		cout << "\t\tВведите пункт из меню: ";
		accept = InputInt(1, 4);

		switch (accept) {
		case 1: {
			playGame();
			break;
		}
		case 2: {
			ClearBoard();
			playBot();
			break;
		}
		case 3: {
			ClearBoard();
			Menu();
			cout << "\t\tНажмите Enter что бы вернуться к меню...";
			Enter();
			ClearBoard();
			break;
		}
		case 4: {
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
