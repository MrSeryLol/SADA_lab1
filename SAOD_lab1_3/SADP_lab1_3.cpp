#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int data;
	Stack* next;
};

void Push(Stack*& mainStack, Stack*& deletedStack)
{
	bool newOrNot = false;
	std::cout << "Добавить новое значение(1) или добавить из стека удалённых значений(0)? \n"; std::cin >> newOrNot;

	if (deletedStack == nullptr && (!newOrNot))
	{
		std::cout << "Невозможная операция, так как стек удаляемых элементов пустой! \n" << std::endl;
		return;
	}

	if (newOrNot)
	{
		int count = 0;
		std::cout << "Сколько элементов вы хотите добавить в стек? \n"; std::cin >> count;

		for (int i = 0; i < count; i++)
		{
			Stack* pTemp;
			pTemp = new Stack();
			pTemp->data = rand();
			pTemp->next = mainStack;
			mainStack = pTemp;
		}
	}

	else 
	{
		Stack* pTemp;//Создаём временный стек
		pTemp = deletedStack;//Копируем адрес стека с удалёнными элементами во временный стек
		deletedStack = deletedStack->next;//"Передвигаем" стек с удалёнными элементами на 1 элемент
		pTemp->next = mainStack;//"Объединяем" адрес временного стека с основным стеком
		mainStack = pTemp;//Приравниваем адрес основного стека со временным
	}

	std::cout << "Данные были успешно добавлены. \n";
}

void Pop(Stack*& mainStack, Stack*& deletedStack)
{
	if (mainStack == nullptr)
	{
		std::cout << "Невозможная операция, так как стек пустой! \n" << std::endl;
		return;
	}

	bool deleteOrNot = false;	
	std::cout << "Удалить элемент (1) или поместить его в стек удалённых элементов (0)? \n"; std::cin >> deleteOrNot;

	if (deleteOrNot)
	{
		Stack* pTemp;
		pTemp = mainStack;
		mainStack = mainStack->next;
		delete pTemp;
		std::cout << "Данные были успешно удалены. \n";
	}

	else
	{
		Stack* pTemp;//Создаём временный стек
		pTemp = mainStack;//Копируем адрес основного стека во временный
		mainStack = mainStack->next;//"Передвигаем" основной стек на 1 элемент
		pTemp->next = deletedStack;//"Обрываем" все связи, оставшиеся от основного стека, связывая временный стек со стеком удалённых элементов
		deletedStack = pTemp;//После обрзовавшейся связи можем спокойно приравнять адреса обоих стеков, избавляясь тем самым от временного
	}
}

void ShowMain(Stack* mainStack)
{
	if (mainStack == nullptr)
	{
		std::cout << "Невозможная операция, так как стек пустой! \n" << std::endl;
	}

	else
	{
		Stack* pCurrent = mainStack;
		while (pCurrent != nullptr)
		{
			std::cout << pCurrent->data << std::endl << std::endl;
			pCurrent = pCurrent->next;
		}
	}
}

void ShowExtra(Stack* deletedStack)
{
	if (deletedStack == nullptr)
	{
		std::cout << "Невозможная операция, так как стек пустой! \n" << std::endl;
	}

	else
	{
		Stack* pCurrent = deletedStack;
		while (pCurrent != nullptr)
		{
			std::cout << pCurrent->data << std::endl << std::endl;
			pCurrent = pCurrent->next;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Stack* mainStack = nullptr;
	Stack* deletedStack = nullptr;
	bool exit = true;
	int choice = 0;

	while (exit)
	{
		std::cout << "Для начала работы программы выберите вариант взаимодействия\n\n";

		std::cout << "Возможности: " << std::endl <<
			"Вывод элементов основного стека в консоль - 1" << std::endl <<
			"Добавление элемента в основной стек -  2" << std::endl <<
			"Удаление элемента из основного стека - 3" << std::endl <<
			"Вывод элементов вспомогательного стека в консоль - 4" << std::endl <<
			"Выход из программы - 5" << std::endl;

		std::cout << "Ваш вариант: "; std::cin >> choice;
		switch (choice)
		{
		case 1:
			ShowMain(mainStack);
			break;
		case 2:
			Push(mainStack, deletedStack);
			break;
		case 3:
			Pop(mainStack, deletedStack);
			break;
		case 4:
			ShowExtra(deletedStack);
			break;
		case 5:
			exit = false;
			break;
		}
	}
	return 0;
}
