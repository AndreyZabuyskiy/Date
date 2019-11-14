#pragma once
#include "Date.h"
#include<iostream>
using namespace std;

class Application
{
private:
	void menu();
	void date_difference();
	Date fill_date();

	void increase_date();
	Date days_translate_data(int days);
	int days_translate_year(int& year);
	int days_translate_month(int& days);

public:
	void start();
};