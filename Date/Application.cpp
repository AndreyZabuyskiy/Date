#include "Application.h"

void Application::menu()
{
	int choice;
	do
	{
		cout << "Выбирите действие:" << endl
			<< "[1] разница двух дат;" << endl
			<< "[2] увеличение даты на определенное количество дней;" << endl
			<< "[0] выход" << endl;
		cout << "-> ";
		cin >> choice;

		system("cls");

		switch (choice)
		{
			case 1:
				date_difference();
				break;

			case 2:
				increase_date();
				break;
			}
	} while (choice != 0);
}

void Application::date_difference()
{
	cout << "Дата 1:" << endl;
	Date first_date = fill_date();

	cout << "-----------------------------------------------" << endl;

	cout << "Дата 2:" << endl;
	Date second_date = fill_date();

	cout << "-----------------------------------------------" << endl;

	Date third_date = first_date - second_date;

	cout << third_date.count_number_days() << endl;

	system("pause");
	system("cls");
}

Date Application::fill_date()
{
	int day, month, year;

	cout << "день-> ";
	cin >> day;
	cout << "месяц-> ";
	cin >> month;
	cout << "год->";
	cin >> year;

	return { day, month, year };
}

void Application::increase_date()
{
	cout << "Введите дату:" << endl;
	Date initial_date = fill_date();

	cout << "-----------------------------------------------" << endl;

	int days;
	cout << "Введите количество дней: ";
	cin >> days;

	Date calculated_date = initial_date + days_translate_data(days);
	calculated_date.show();

	system("pause");
	system("cls");
}

Date Application::days_translate_data(int days)
{
	int year = 0;
	int month = 0;
	int day = 0;

	if (days > 31)
	{
		year = days_translate_year(days);
		month = days_translate_month(days);
	}
	day = days;

	return { day, month, year };
}

int Application::days_translate_year(int& days)
{
	int year = 0;
	if (days > 365)
	{
		while (true)
		{
			if (days < 365)
			{
				break;
			}
			days -= 365;
			year++;
		}
	}
	return year;
}

int Application::days_translate_month(int& days)
{
	int month = 0;
	int day_number_year[12]
	{ 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

	for (int i = 0; i < 12; i++)
	{
		if (days > day_number_year[i])
		{
			month++;
		}
		else
		{
			days -= day_number_year[i - 1];
			break;
		}
	};

	return month;
}

void Application::start()
{
	menu();
}
