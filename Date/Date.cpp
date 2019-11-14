#include "Date.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& other)
{
	set_day(other.get_day());
	set_month(other.get_month());
	set_year(other.get_year());
}

Date Date::operator-(const Date& other)
{
	int difference_days = subtraction_days(other.get_day());
	int difference_month = subtraction_month(other.get_month());
	int difference_year = year - other.get_year();

	return { difference_days, difference_month, difference_year };
}

Date Date::operator=(const Date& other)
{
	return { other.get_day(), other.get_month(), other.get_year() };
}

Date Date::operator+(const Date& other)
{
	int first_day = this->day;
	int first_month = this->month;
	int first_year = this->year;

	int second_day = other.get_day();
	int second_month = other.get_month();
	int second_year = other.get_year();

	int third_day = sum_days(first_day, second_day, first_month, second_month);
	int third_month = sum_month(first_month, second_month, first_year);
	int third_year = first_year + second_year;;

	return {third_day, third_month, third_year};
}

void Date::set_day(int day)
{
	this->day = day;
}

void Date::set_month(int month)
{
	this->month = month;
}

void Date::set_year(int year)
{
	this->year = year;
}

int Date::get_day() const
{
	return day;
}

int Date::get_month() const
{
	return month;
}

int Date::get_year() const
{
	return year;
}

void Date::show()
{
	cout << day << "." << month << "." << year << endl;
}

int Date::count_number_days()
{
	int day_number_year[12]
	{ 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

	if (month >= 0)
	{
		return day + day_number_year[month - 1] + year * 365;
	}
	else
	{
		return day + year * 365;
	}
}

int Date::subtraction_days(int other_day)
{
	if (day >= other_day)
	{
		return day - other_day;
	}
	else
	{
		this->day += lend_days();
		return day - other_day;
	}
}

int Date::subtraction_month(int other_month)
{
	if (month >= other_month)
	{
		return month - other_month;
	}
	else
	{
		year--;
		month += 12;
		return month - other_month;
	}
}

int Date::lend_days()
{
	int number_days_month[12]
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 1)
	{
		year--;
		month = 12;
		return number_days_month[month - 1];
	}
	
	month--;
	return number_days_month[month - 1];
}

int Date::sum_days(int first_day, int second_day, int first_month, int& second_month)
{
	int number_days_month[12]
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int third_day = first_day + second_day;
	if (third_day > number_days_month[first_month - 1])
	{
		third_day -= number_days_month[first_month - 1];
		second_month++;
	}
	return third_day;
}

int Date::sum_month(int first_month, int second_month, int& first_year)
{
	int third_month = first_month + second_month;

	if (third_month > 12)
	{
		third_month -= 12;
		first_year++;
	}

	return third_month;
}
