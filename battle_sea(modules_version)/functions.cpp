#include<iostream>
#include<string>
#include<windows.h>
#include"Header.h"
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

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

		for (char c : s) {
			if (!isdigit(c)) {
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
	} else if (choise == 2) { 
		Dy = 1;
	} else if (choise == 3) { 
		Dx = -1;
	} else if(choise == 4) { 
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
	} else {
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