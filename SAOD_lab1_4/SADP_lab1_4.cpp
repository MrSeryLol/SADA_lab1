#include <iostream>


void Add(int queue[], int& size, int& count, int& last)
{
	if (size == count)
	{
		std::cout << "������� ���������! ���������� ����������! \n";
		return;
	}

	if (size != count && count == 0)
	{
		last = 0;

		std::cout << "������� �����: "; std::cin >> queue[last];
		last++;

		if (last > size - 1)
		{
			last = 0;
		}

		count++;
	}

	else if (size != count)
	{
		std::cout << "������� �����: "; std::cin >> queue[last];
		last++;

		if (last > size - 1)
		{
			last = 0;
		}

		count++;
	}
}

void Remove(int queue[], int& size, int& count, int& first)
{
	if (count == 0)
	{
		std::cout << "������� �����! �������� ����������! \n";
		return;
	}

	else 
	{
		queue[first] = 0;
		first++;

		if (first > size - 1)
		{
			first = 0;
		}

		count--;
	}
}

void Show(int queue[], int& size, int& count, int& first, int& last)
{
	if (count == 0)
	{
		std::cout << "������� �����! ������ ������ �������! \n";
		return;
	}

	int current = 0;
	if (count > 0)
	{
		current = first;
		do
		{
			std::cout << queue[current] << std::endl;
			if (current == size - 1) 
			{
				current = 0; 
			}
			else 
			{ 
				current++; 
			}
		} while (current != last);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	
	int queue[5] = {};
	int size = sizeof(queue) / sizeof(queue[0]);
	int first = 0;
	int last = 0;
	int count = 0;
	bool exit = true;
	int choice = 0;

	while (exit)
	{
		std::cout << "��� ������ ������ ��������� �������� ������� ��������������\n\n";

		std::cout << "�����������: " << std::endl <<
			"����� ��������� � ������� - 1" << std::endl <<
			"���������� �������� � ������� -  2" << std::endl <<
			"�������� �������� �� ������� - 3" << std::endl <<
			"����� �� ��������� - 4" << std::endl;

		std::cout << "��� �������: "; std::cin >> choice;
		switch (choice) 
		{
		case 1:
			Show(queue, size, count, first, last);
			break;
		case 2:
			Add(queue, size, count, last);
			break;
		case 3:
			Remove(queue, size, count, first);
			break;
		case 4:
			exit = false;
			break;
		}
	}
	return 0;
}