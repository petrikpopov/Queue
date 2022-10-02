#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

class Queue
{
	char* Wait;
	int MaxQueueLenght;
	int QueueLenght;
public:
	Queue(const char* buf);
	~Queue();
	bool IsEmpty();
	char Extract();
};

Queue::Queue(const char* buf)// макс размер 6, 7 - как ноль символ 
{
	MaxQueueLenght = 6;
	Wait = new char[MaxQueueLenght];
	strcpy_s(Wait, 7, buf);
	QueueLenght = 6;
}

bool Queue::IsEmpty()
{
	return QueueLenght == 0;
}

char Queue::Extract()// смещение элиментов на лево Фифо 
{
	char temp = Wait[0];
	for (int i = 1; i < QueueLenght; i++)
	{
		Wait[i - 1] = Wait[i];
	}
	Wait[QueueLenght - 1] = temp;
	return temp;
}

Queue::~Queue()
{
	delete[]Wait;
}

int main()
{
	srand(time(0));
	HANDLE h;
	Queue Bar1("HUV7TO");
	Queue Bar2("HUV7TO");
	Queue Bar3("HUV7TO");
	char B1c, B2c, B3c;// храняться символы 
	int rand_spin = rand() % (15 - 30) + 15;
	while (true)
	{
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD a{ 0 , 0 };
			c = Bar1.Extract();
			SetConsoleTextAttribute(h, 4);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B1c = c;
			Sleep(50);
		}
		rand_spin = rand() % (15 - 30) + 15;
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD a{ 5 , 0 };
			c = Bar2.Extract();
			SetConsoleTextAttribute(h, 4);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B2c = c;
			Sleep(50);
		}
		rand_spin = rand() % (15 - 30) + 15;
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);// работа с активной кансоллллллююююю
			COORD a{ 10 , 0 };
			c = Bar3.Extract();// роспаковка символа 
			SetConsoleTextAttribute(h, 4);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B3c = c;
			Sleep(50);
		}
		cout << endl;
		if (B1c == B2c == B3c)
		{
			if (B1c = '7')
				cout << "You Win 1000$";
			else if (B1c == 'H')
				cout << "You Win 500$";
			else if (B1c == 'U')
				cout << "You Win 250$";
			else if (B1c == 'V')
				cout << "You Win 150$";
			else if (B1c == 'T')
				cout << "You Win 100$";
		}
		else if (B1c == 'O' || B2c == 'O' || B3c == 'O')
		{
			int count = 0;
			if (B1c == 'O')
				count++;
			if (B2c == 'O')
				count++;
			if (B3c == 'O')
				count++;
			if (count == 1)
				cout << "You Win 102$";
			else if (count == 2)
				cout << "You Win 256$";
			else if (count == 3)
				cout << "You Win 505$";
		}
		else
			cout << "You Lose";
		cout << endl;
		system("pause");
		system("cls");
	}
}