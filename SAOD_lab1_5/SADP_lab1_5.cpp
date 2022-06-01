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

	std::cout << "\n����������� ����������..." << std::endl;
	std::cout << numOfElements << "�������(�) ���������!" << std::endl;
 	

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
	std::cout << "\n������� ��������...\n";

	if (pFirst->next == nullptr)
	{
		std::cout << "\n������ �������!" << std::endl;
		return;
	}

	//int numOfElements = GetRandomNumber(1, 3);

	for (int i = 0; i < numOfElements; i++)
	{
		
		if (pFirst->next == nullptr)
		{
			std::cout << numOfElements << "�������(�) �������!" << std::endl;
			std::cout << "\n������� ������... ��������� �����!" << std::endl;
			return;
		}
		

		Queue* pTemp = new Queue();
		pTemp = pFirst->next;//����������� ����� ��������� �� pFirst
		pFirst->next = pTemp->next;//�������� �� 1 �������

		if (pFirst == nullptr)
		{
			pLast = pFirst;
		}

		delete pTemp;//������� ������ �������� ������, � ������� ��� 1 ������� �������
	}
	std::cout << "\n����������� ��������..." << std::endl;
	std::cout << numOfElements << "�������(�) �������!" << std::endl;
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
		std::cout << "��� ������ ������ ��������� �������� ������� ��������������\n\n";

		std::cout << "�����������: " << std::endl <<
			"����� ����������� � ��������� ��������� ��������� - 1" << std::endl <<
			"����� ����������� ��������� ������, ��� ��������� -  2" << std::endl <<
			"����� ��������� ��������� ������, ��� ����������� - 3" << std::endl;

		std::cout << "��� �������: "; std::cin >> choice;
		
		srand(time(NULL));

		std::cout << "������ ��������������� ����� ������...\n\n";

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