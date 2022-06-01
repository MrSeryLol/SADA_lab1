#include <iostream>
#include<Windows.h>
#include <conio.h>

struct Queue
{
	char data;
	Queue* next;
};

int GetRandomNumber(int min, int max)
{
	int num = min + rand() % (max - min + 1);

	return num;
}

char GetRandomData(int min, int max)
{
	int code = min + rand() % (max - min + 1);
	code = (char)code;
	return code;
}

void Add(Queue*& pFirst, Queue*& pLast, int numOfElements)
{
	if (pFirst->next == nullptr)
	{
		pLast = pFirst;
	}

	std::cout << "\nВыполняется добавление..." << std::endl;
	std::cout << numOfElements << "элемент(а) добавлено!" << std::endl;
 	

	for (int i = 0; i < numOfElements; i++)
	{
		Queue* pTemp;
		pTemp = new Queue();
		pTemp->data = GetRandomData(65, 90);
		pTemp->next = nullptr;
		pLast->next = pTemp;
		pLast = pTemp;
	}
}

 void Remove(Queue*& pFirst, Queue*& pLast, int numOfElements)
{
	std::cout << "\nПопытка удаления...\n";

	if (pFirst->next == nullptr)
	{
		std::cout << "\nПустая очередь!" << std::endl;
		return;
	}

	//int numOfElements = GetRandomNumber(1, 3);

	for (int i = 0; i < numOfElements; i++)
	{
		
		if (pFirst->next == nullptr)
		{
			std::cout << numOfElements << "элемент(а) удалено!" << std::endl;
			std::cout << "\nОчередь пустая... Остановка цикла!" << std::endl;
			return;
		}
		

		Queue* pTemp = new Queue();
		pTemp = pFirst->next;//Присваиваем адрес указателя из pFirst
		pFirst->next = pTemp->next;//Сдвигаем на 1 элемент

		if (pFirst == nullptr)
		{
			pLast = pFirst;
		}

		delete pTemp;//Удаляем старое значение адреса, в котором был 1 элемент очереди
	}
	std::cout << "\nВыполняется удаление..." << std::endl;
	std::cout << numOfElements << "элемент(а) удалено!" << std::endl;
}

void AfterRemove(Queue*& pFirst, Queue*& pLast)
{
	while (pFirst->next != nullptr)
	{
		Queue* pTemp = new Queue();
		pTemp = pFirst->next;
		pFirst->next = pTemp->next;

		if (pFirst == nullptr)
		{
			pLast = pFirst;
		}

		delete pTemp;
	}
	delete pFirst;
}

void Show(Queue* pFirst)
{
	Queue* pTemp = new Queue();
	pTemp = pFirst->next;

	while (pTemp != nullptr)
	{
		std::cout << pTemp->data << " ";
		pTemp = pTemp->next;
	}
}

void Program(int mode, Queue*& pFirst, Queue*& pLast)
{
	if (mode == 1)
	{
		int randNum = GetRandomNumber(1, 100);
		if (randNum % 2 == 0)
		{
			int numOfElements = GetRandomNumber(1, 3);
			Add(pFirst, pLast, numOfElements);
		}
		else
		{
			int numOfElements = GetRandomNumber(1, 3);
			Remove(pFirst, pLast, numOfElements);
		}

		Show(pFirst);
		Sleep(5000);
		return;
	}

	if (mode == 2)
	{
		int randNum = GetRandomNumber(1, 100);
		if (randNum % 2 == 0)
		{
			int numOfElements = GetRandomNumber(1, 4);
			Add(pFirst, pLast, numOfElements);
		}
		else
		{
			int numOfElements = GetRandomNumber(1, 3);
			Remove(pFirst, pLast, numOfElements);
		}

		Show(pFirst);
		Sleep(5000);
		return;
	}

	if (mode == 3)
	{
		int randNum = GetRandomNumber(1, 100);
		if (randNum % 2 == 0)
		{
			int numOfElements = GetRandomNumber(1, 3);
			Add(pFirst, pLast, numOfElements);
		}
		else
		{
			int numOfElements = GetRandomNumber(1, 4);
			Remove(pFirst, pLast, numOfElements);
		}

		Show(pFirst);
		Sleep(5000);
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	Queue* pFirst = new Queue();
	Queue* pLast = new Queue();
	pFirst->next = nullptr;

	int choice = 0;
	int key = 0;
	bool exit = true;
	int mode = 0;

	while (exit)
	{
		std::cout << "Для начала работы программы выберите вариант взаимодействия\n\n";

		std::cout << "Возможности: " << std::endl <<
			"Число добавляемых и удаляемых элементов одинаково - 1" << std::endl <<
			"Число добавляемых элементов больше, чем удаляемых -  2" << std::endl <<
			"Число удаляемых элементов больше, чем добавляемых - 3" << std::endl;

		std::cout << "Ваш вариант: "; std::cin >> choice;
		
		srand(time(NULL));

		std::cout << "Датчик псевдослучайных чисел создан...\n\n";

		switch (choice)
		{
		case 1:
			mode = 1;
			exit = false;
			break;
		case 2:
			mode = 2;
			exit = false;
			break;
		case 3:
			mode = 3;
			exit = false;
			break;
		}

		while (key != 'q')
		{
			Program(mode, pFirst, pLast);

			if (_kbhit()) { key = _getch(); }
		}
	}

	AfterRemove(pFirst, pLast);

	return 0;
}