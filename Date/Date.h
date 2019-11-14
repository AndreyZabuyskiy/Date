#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

	int subtraction_days(int other_day);
	int subtraction_month(int other_month);
	int lend_days();

	int sum_days(int first_day, int second_day, int first_month, int& second_month);
	int sum_month(int first_month, int second_month, int& first_year);

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& other);

	Date operator - (const Date& other);
	Date operator = (const Date& other);
	Date operator + (const Date& other);

	void set_day(int day);
	void set_month(int month);
	void set_year(int year);

	int get_day () const;
	int get_month() const;
	int get_year() const;

	void show();
	int count_number_days();
};