// proje contact /term1 mabani /ostad abbasi/ mojtaba alehoseini/ yousef rastgoo/ 28/9/1396
// 1st bug: vaghti bejaye adad ya shomare enter ro mizani miofte too halghe
//licence key :    MojtabaC++Yousef

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>
using namespace std;
void sort();
void full_version();
void about(int);
void contact_us();
char name[100][50], number[100][13];
int i = 0, j, counter = 0;

int repeat_check(int r)
{
	if (r == 0)
	{
		for (i = 100 - counter; i < 100; i++)
			if (_strcmpi(number[99 - counter], number[i]) == 0)
				return 1;
		if (i == 100)
			return 0;

	}
	else
	{
		for (i = 100 - counter; i < 100; i++)
			if (_strcmpi(name[99 - counter], name[i]) == 0)
				return 1;
		if (i == 100)
			return 0;
	}
}

void add_contact()
{
	cout << "  -Enter number(#):\t";
	cin.ignore();
	cin.get(number[99 - counter], 12);
	while (repeat_check(0) == 1)
	{
		cout << "\n The number already exists! ; Enter again#:\n";
		cin.ignore();
		cin.get(number[99 - counter], 12);
	}
	cin.ignore();
	cout << "  -Enter name \t :\t";
	cin.get(name[99 - counter], 49);
	while (repeat_check(1) == 1)
	{
		cout << "\n The name already exists! ; Enter again#:\n";
		cin.ignore();
		cin.get(name[99 - counter], 49);
	}
	counter++;
	sort();
}

void sort()
{
	char t[50];
	for (i = 0; i < 100; i++)
		for (j = i + 1; j < 100; j++)
			if (_strcmpi(name[i], name[j]) > 0)
			{
				strcpy_s(t, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], t);
				strcpy_s(t, number[i]);
				strcpy_s(number[i], number[j]);
				strcpy_s(number[j], t);
			}
}

int search()
{
	int k = 1, f, l;
	char c[50];
	cin.ignore();
	cin.get(c, 49);
	for (l = 0; l < 100; l++)
	{
		for (i = 0; name[l][i] != '\0'; i++)
		{
			f = 1;
			if (name[l][i] != c[0])
				f = 0;
			else
				for (j = 1, k = i + 1; c[j] != '\0'; j++, k++)
					if (name[l][k] != c[j])
					{
						f = 0;
						break;
					}
			if (c[j] == '\0')
				break;
		}
		if (f == 1)
			return l;
	}
	for (l = 0; l < 100; l++)
	{
		for (i = 0; number[l][i] != '\0'; i++)
		{
			f = 1;
			if (number[l][i] != c[0])
				f = 0;
			else
				for (j = 1, k = i + 1; c[j] != '\0'; j++, k++)
					if (number[l][k] != c[j])
					{
						f = 0;
						break;
					}
			if (c[j] == '\0')
				break;
		}
		if (f == 1)
			return l;
	}
	if (l == 100)
		return 200;
}

void remove_contact(int r)
{
	for (i = 0; i < 50; i++)
		name[r][i] = '\0';
	for (i = 0; i < 13; i++)
		number[r][i] = '\0';
	counter--;
	sort();
}

void edit_contact()
{
	int r;
	char z;
	if (counter == 0)
		cout << "\n\tPhoneBook is Empty!\n";
	else
	{
		cout << "\n   Enter a name or number to edit:\n";
		r = search();
		if (r == 200)
			cout << "\t\tNo contact found!\n";
		else
		{
			cout << "\tDo you want to edit  (" << name[r] << "\t:\t" << number[r] << ") ?\n\tEnter ' y ' to yes, and another to no :\t";
			cin >> z;
			if (z == 'y' || z == 'Y')
			{
				remove_contact(r);
				add_contact();
				cout << "\n\t\tContact Edited Seccessfully.\n";
			}
		}
	}
}

void check_licence()
{
	char c[31];
	int i, s = 0, a;
	cin.ignore();
	//MojtabaC++Yousef
	cout << "\nEnter licence key:\nif you dont have licence key, you can buy it from contact us part\n";
	cin.get(c, 30);
	cin.ignore();
	for (i = 0; i < 30 && c[i] != '\0'; i++)
	{
		a = int(c[i]);
		s += a;
	}
	if (s == 1490)
	{
		cout << "thanks for buy\n";
		full_version();
	}
	else
		cout << "invalid licence key, to buy a licence key --> contact : alehoseini.mojtaba@gmail.com or make call with +989120211520\n";
}

void demo()
{
	int r;
	char func;
	cout << "\t\t\t\t\t PHONEBOOK *Demo Mode* ";
	for (;;)
	{
		cout << "\nto have more options please buy a full version\n*Demo Function list:,\n0 = register,\n1 = Add a new contact,\n2 = Show all contacts,\n3 = about,\n4 = contact with us.\n\nEnter a function number:\t";
		cin >> func;
		switch (func)
		{
			char z;
		case '0':
			// register
		{
			check_licence();
			break;
		}
		case '1':
			// add
		{
			if (counter == 100)
				cout << "Capacity is full!";
			else
			{
				add_contact();
				cout << "\n\tContact Added Successfully.\n";
			}
			break;
		}

		case '2':
			// show all
		{
			if (counter == 0)
				cout << "\n\tPhoneBook is Empty!";
			else
				for (i = 100 - counter; i < 100; i++)
					cout << "\n\t" << i + counter - 99 << " -\t" << name[i] << "\t:\t" << number[i];
			cout << '\n';
			break;
		}
		case '3':
			//about
		{
			about(0);
			break;
		}
		case '4':
			//contact with us
		{
			contact_us();
			break;
		}
		default:
			cout << "\n\t\t\tInvalid Function!\n";
		}
	}
}

void full_version()
{
	int r;
	char func;
	cout << "\t\t\t\t\t PHONEBOOK full version ";
	for (;;)
	{
		cout << "\n*Function list:\n0 = Search a contact,\n1 = Add a new contact,\n2 = Delete a contact,\n3 = Edit a contact,\n4 = Show all contacts,\n5 = About\n6 = contact with us.\n\nEnter a function number:\t";
		cin >> func;
		switch (func)
		{
			char z;
		case '0':
			// 0=search
		{
			if (counter == 0)
				cout << "\n\tPhoneBook is Empty!\n";
			else
			{
				cout << "\n\tEnter a part of name or number:\n";
				r = search();
				if (r == 200)
					cout << "No contact found!\n";
				else
					cout << name[r] << "\t:\t" << number[r];
			}
			break;
		}
		case '1':
			// add
		{
			if (counter == 100)
				cout << "Capacity is full!";
			else
			{
				add_contact();
				cout << "\n\tContact Added Successfully.\n";
			}
			break;
		}
		case '2':
			// delete
		{
			if (counter == 0)
				cout << "\n\tPhoneBook is Empty!\n";
			else
			{
				cout << "\n\tEnter a name or number to remove:\n";
				r = search();
				if (r == 200)
					cout << "\t\tNo contact found!\n";
				else
				{
					cout << "\tDo you want to remove  (" << name[r] << "\t:\t" << number[r] <<
						") ?\n\tEnter ' y ' to yes, and another to no :\t";
					cin >> z;
					if (z == 'y' || z == 'Y')
					{
						remove_contact(r);
						cout << "\n\t\tContact removed seccessfully.\n";
					}
					else
						cout << "\tcontact not removed";
				}
			}
			break;
		}
		case '3':
			// edit
		{
			edit_contact();
			break;
		}
		case '4':
			// show all
		{
			if (counter == 0)
				cout << "\n\tPhoneBook is Empty!";
			else
				for (i = 100 - counter; i < 100; i++)
					cout << "\n\t" << i + counter - 99 << " -\t" << name[i] << "\t:\t" << number[i];
			cout << '\n';
			break;
		}
		case '5':
			//about
		{
			about(1);
			break;
		}
		case '6':
			// contact with us
		{
			contact_us();
			break;
		}
		default:
			cout << "\n\t\t\tInvalid Function!\n";
		}
	}
}

void about(int d)
{
	if (d == 0)
		cout << "\n\t\t\t    Demo Mode\n\t\t     please buy a full version\n";
	else
		cout << "\n\t\t\t   Full Version\n\t\t  Thanks for buy a full version\n";
	cout << "\n \t\t\t PhonBook Project\n\t\t\t    Supervisor:\n\t\t\t Dr Elham Abbasi\n\t\t\t   developed by:\n\t\tMojtaba Alehoseini & Yousef Rastgoo\n\t\t\t    28/9/1396\n";
}

void contact_us()
{
	cout << "\n\tways to contact with us:\n\n\t     Email:     alehoseini.mojtaba@gmail.com\n\t Phone Number:  +989120211520\n";
}

int main()
{
	demo();
	return 0;
}
