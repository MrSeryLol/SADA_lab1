#include <iostream>

struct Stack
{
    int data;
    Stack* next;
};

void Push(Stack*& a)
{
    Stack* pTemp;
    pTemp = new Stack();
    std::cout << "Enter a number: "; std::cin >> pTemp->data;
    pTemp->next = a;
    a = pTemp;

	std::cout << "Данные были успешно добавлены. \n";
}

void Pop(Stack*& a)
{
	if (a == nullptr)
	{
		std::cout << "Невозможная операция, так как стек пустой! \n" << std::endl;
	}
	
	else
	{
		Stack* pTemp;
		pTemp = a;
		a = a->next;
		delete pTemp;
		std::cout << "Данные были успешно удалены. \n";
	}
}

void Show(Stack* a)
{
	if (a == nullptr)
	{
		std::cout << "Невозможная операция, так как стек пустой! \n" << std::endl;
	}

	else
	{
		Stack* pCurrent = a;
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

	Stack* a = nullptr;
	bool exit = true;
	int choice = 0;

	while (exit)
	{
		std::cout << "Для начала работы программы выберите вариант взаимодействия\n\n";

		std::cout << "Возможности: " << std::endl <<
			"Вывод элементов в консоль - 1" << std::endl <<
			"Добавление элемента в стек -  2" << std::endl <<
			"Удаление элемента из стека - 3" << std::endl <<
			"Выход из программы - 4" << std::endl;

		std::cout << "Ваш вариант: "; std::cin >> choice;
		switch (choice)
		{
		case 1:
			Show(a);
			break;
		case 2:
			Push(a);
			break;
		case 3:
			Pop(a);
			break;
		case 4:
			exit = false;
			break;
		default:
			std::cout << "Нет такого выбора!" << std::endl;
			break;
		}
	}
	return 0;
}
