#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

constexpr int SIZE_ = 10;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE g = GetStdHandle(STD_OUTPUT_HANDLE);

void Menu()
{
	SetConsoleTextAttribute(h, 3);
	cout << "\n\t" << R"(°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸
	~°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°~  )" << "\n\n";

	SetConsoleTextAttribute(h, 14);

	cout << "\t\tДобро пожаловать в игру морской бой!\n\n";
	cout << "\t\tЯ думаю что все знают правила этой легендарной игры\n"
		<< "\t\tТак что моряки, расставляйте корабли, И В БОЙ!\n\n";
	cout << "\t\tНа всякий случай напомню какие в этой игре есть корабли:\n\n"
		<< "\t\t# - 4 однопалубных.\n"
		<< "\t\t## - 3 двухпалубных.\n"
		<< "\t\t### - 2 трёхпалубных.\n"
		<< "\t\t#### - 1 четырёхпалубный.\n\n";

	SetConsoleTextAttribute(h, 3);
	cout << "\t" << R"(°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸
	~°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°~  )" << "\n\n";
	SetConsoleTextAttribute(h, 14);
}

void ClearBoard()
{
	system("cls");
}

void imageBoard()
{
	SetConsoleTextAttribute(h, 3);
	cout << R"(
  °º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸
  ~°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°~  

    ███╗   ███╗ ██████╗ ██████╗ ███████╗██╗  ██╗ ██████╗ ██╗   ██╗        
    ████╗ ████║██╔═══██╗██╔══██╗██╔════╝██║ ██╔╝██╔═══██╗╚██╗ ██╔╝        
    ██╔████╔██║██║   ██║██████╔╝██║     █████╔╝ ██║   ██║ ╚████╔╝         
    ██║╚██╔╝██║██║   ██║██╔══██╗██║     ██╔═██╗ ██║   ██║  ╚██╔╝          
    ██║ ╚═╝ ██║╚██████╔╝██║  ██║███████╗██║  ██╗╚██████╔╝   ██║           
    ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝    ╚═╝           
                                                                        
		   ██████╗  ██████╗ ██╗   ██╗                                           
		   ██╔══██╗██╔═══██╗╚██╗ ██╔╝                                           
		   ██████╔╝██║   ██║ ╚████╔╝                                            
		   ██╔══██╗██║   ██║  ╚██╔╝                                             
		   ██████╔╝╚██████╔╝   ██║                                              
		   ╚═════╝  ╚═════╝    ╚═╝    
 
  ~°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°~  
  °º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸¸,ø¤º°`°º¤ø,¸                                         

)" << endl;
	SetConsoleTextAttribute(h, 7);
}

void Enter()
{
	string Enter;
	getline(cin, Enter);
}

int InputInt(int min, int max)
{
	while (true) {
		if (cin.peek() == '\n') {
			cin.ignore();
		}

		string s;
		getline(cin, s);

		if (s.empty()) {
			cout << "\n\t\tПустой ввод, повторите: ";
			continue;
		}

		bool prove = true;

		for (int i = 0; i < s.length(), i++) {
			if (!isdigit(s[i])) {
				prove = false;
				break;
			}
		}
		if (!prove) {
			cout << "\t\tВведите число: ";
			continue;
		}
		int value = stoi(s);

		if (value < min || value > max) {
			cout << "\t\tВведите число от " << min << " до " << max << ": ";
			continue;
		}
		return value;
	}
}

int InputLetter(int min, int max)
{
	while (true) {
		if (cin.peek() == '\n') {
			cin.ignore();
		}

		string s;
		const string digits = "abcdefghij";
		getline(cin, s);

		if (s.empty()) {
			cout << "\n\t\tПустой ввод, повторите: ";
			continue;
		}

		if (s.length() > 1) {
			cout << "\t\tВведите 1 символ: ";
			continue;
		}

		char target = tolower(s[0]);
		size_t number = digits.find(target);

		if (number == string::npos) { // проверяем на отсутствие символов
			cout << "\t\tНедопустимый символ!\n";
			cout << "\t\tВведите букву a-j: ";
			continue;
		}

		int value = (int)number;

		if (value < min || value > max) {
			cout << "\t\tВведите букву a-j: ";
			continue;
		}
		return value;
	}
}

void initField(char field[][SIZE_])
{
	for (int i = 0; i < SIZE_; i++) {
		for (int j = 0; j < SIZE_; j++) {

			field[i][j] = '~';
		}
	}
}

void printField(char field[][SIZE_])
{
	SetConsoleTextAttribute(h, 14);
	char letter = 'a';
	int num = 1;
	cout << "\t\t     ";
	for (int i = 0; i < 10; i++) {
		cout << letter << " ";
		letter++;
	}
	cout << "\n";
	cout << "\t\t   @—————————————————————@\n";
	for (int i = 0; i < 10; i++) {
		if (num < 10) { cout << "\t\t " << num << " " << "|"; }
		else cout << "\t\t" << num << " " << "|";

		SetConsoleTextAttribute(h, 3);
		for (int j = 0; j < 10; j++) {
			if (field[i][j] == '#' || field[i][j] == '.') {
				SetConsoleTextAttribute(h, 6);
			} if (field[i][j] == 'X') {
				SetConsoleTextAttribute(h, 12);
			}
			cout << " " << field[i][j];
			SetConsoleTextAttribute(h, 3);
		}
		SetConsoleTextAttribute(h, 14);
		cout << " |";
		cout << " " << "\n";
		num++;
	}
	cout << "\t\t   @—————————————————————@\n" << endl;
}

bool ship(int x, int y, char field[][SIZE_], int choise, int length)
{
	int Dx = 0;
	int Dy = 0;

	if (choise == 1) {
		Dy = -1;
	}
	else if (choise == 2) {
		Dy = 1;
	}
	else if (choise == 3) {
		Dx = -1;
	}
	else if (choise == 4) {
		Dx = 1;
	}

	bool checkPlace = true;

	for (int i = 0; i < length; i++) {
		int Vx = x + (i * Dx);
		int Vy = y + (i * Dy);

		if (Vx < 0 || Vx >= SIZE_ || Vy < 0 || Vy >= SIZE_ || field[Vy][Vx] == '#') {
			checkPlace = false;
			break;
		}
		for (int i = Vy - 1; i <= Vy + 1; i++) {
			for (int j = Vx - 1; j <= Vx + 1; j++) {
				if (i >= 0 && i < SIZE_ && j >= 0 && j < SIZE_) {
					if (field[i][j] == '#') {
						checkPlace = false;
						break;
					}
				}
			}
			if (!checkPlace) break;
		}
		if (!checkPlace) break;
	}
	if (checkPlace) {
		for (int i = 0; i < length; i++) {
			SetConsoleTextAttribute(h, 6);
			field[y + (i * Dy)][x + (i * Dx)] = '#';
		}
		SetConsoleTextAttribute(h, 14);
		return true;
	}
	else {
		cout << "\tКорабль выходит за пределы поля или клетка недоступна!\n";
		Enter();
		return false;
	}
}

bool ship_destroy(int x, int y, char field[][SIZE_], char field2[][SIZE_])
{
	int x1 = x + 1;
	int x2 = x - 1;
	int y1 = y + 1;
	int y2 = y - 1;

	while (x1 < SIZE_ && field[y][x1] != '~' && field[y][x1] != '.') {
		if (field[y][x1] == '#') {
			return false;
		}
		x1++;
	}
	while (x2 >= 0 && field[y][x2] != '~' && field[y][x2] != '.') {
		if (field[y][x2] == '#') {
			return false;
		}
		x2--;
	}
	while (y1 < SIZE_ && field[y1][x] != '~' && field[y1][x] != '.') {
		if (field[y1][x] == '#') {
			return false;
		}
		y1++;
	}
	while (y2 >= 0 && field[y2][x] != '~' && field[y2][x] != '.') {
		if (field[y2][x] == '#') {
			return false;
		}
		y2--;
	}
	cout << "\t\tКорабль уничтожен!\n";

	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {
			if (i >= 0 && i < SIZE_ && j >= 0 && j < SIZE_) {
				if (field[i][j] == '~') {
					field[i][j] = '.';
					field2[i][j] = '.';
				}
			}
		}
	}

	x1 = x + 1;
	x2 = x - 1;
	y1 = y + 1;
	y2 = y - 1;

	while (x1 < SIZE_ && field[y][x1] == 'X') {
		for (int i = y - 1; i <= y + 1; i++) {
			for (int j = x1 - 1; j <= x1 + 1; j++) {
				if (i >= 0 && i < SIZE_ && j >= 0 && j < SIZE_) {
					if (field[i][j] == '~') {
						field[i][j] = '.';
						field2[i][j] = '.';
					}
				}
			}
		}
		x1++;
	}
	while (x2 >= 0 && field[y][x2] == 'X') {
		for (int i = y - 1; i <= y + 1; i++) {
			for (int j = x2 - 1; j <= x2 + 1; j++) {
				if (i >= 0 && i < SIZE_ && j >= 0 && j < SIZE_) {
					if (field[i][j] == '~') {
						field[i][j] = '.';
						field2[i][j] = '.';
					}
				}
			}
		}
		x2--;
	}
	while (y1 < SIZE_ && field[y1][x] == 'X') {
		for (int i = y1 - 1; i <= y1 + 1; i++) {
			for (int j = x - 1; j <= x + 1; j++) {
				if (i >= 0 && i < SIZE_ && j >= 0 && j < SIZE_) {
					if (field[i][j] == '~') {
						field[i][j] = '.';
						field2[i][j] = '.';
					}
				}
			}
		}
		y1++;
	}
	while (y2 >= 0 && field[y2][x] == 'X') {
		for (int i = y2 - 1; i <= y2 + 1; i++) {
			for (int j = x - 1; j <= x + 1; j++) {
				if (i >= 0 && i < SIZE_ && j >= 0 && j < SIZE_) {
					if (field[i][j] == '~') {
						field[i][j] = '.';
						field2[i][j] = '.';
					}
				}
			}
		}
		y2--;
	}
	return true;
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

	while (check < 10) {
		ClearBoard();
		cout << "\t\tВторой игрок расставляет:" << endl;
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
						return;
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
						return;
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
			cout << "\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "\t\t   ~~~~~ИГРА ЗАВЕРШЕНА~~~~~\n";
			cout << "\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~";
			break;
		}
		default:
			break;
		}
	}
	SetConsoleTextAttribute(g, 7);
}
