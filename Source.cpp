#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

static int phones = 0;
string anykey = "";



void addEntry(char phoneBook[10][2][50])
{
	if (phones == 10)
	{
		printf("\nThe phonebook is full!\n");
		return;
	}

	printf("Entry %d:\n", phones + 1);

	printf("%d Please enter name: ", phones);
	char name[50];
	gets_s(name);

	for (int index = 0; index < phones; index++)
	{
		if (!strcmp(phoneBook[index][0], name))
		{
			printf("\n%s already exists in the phonebook!\n", name);
			return;
		}
	}

	printf("Please enter phone number: ");
	char phoneNumber[50];
	gets_s(phoneNumber);

	strcpy_s(phoneBook[phones][0], name);
	strcpy_s(phoneBook[phones][1], phoneNumber);

	phones++;
}


void display(char phoneBook[10][2][50])
{
	for (int index = 0; index < phones; index++)
	{
		printf("Entry %d Name: %s Number: %s\n", index + 1, phoneBook[index][0], 
			phoneBook[index][1]);
	}
}


int main()
{
	
	char phoneBook[10][2][50];

	while (true)
	{
		printf("\n-----------------------\n");
		printf("What do you want to do?\n");
		printf("-----------------------\n");
		printf("[A]dd new entry -- enter A\n");
		printf("[D]isplay -- enter D\n");
		printf("[Q]uit -- enter Q\n");

		char choice;
		scanf_s("%c", &choice);
		getchar();

		if (choice == 'A' || choice == 'a')
		{
			addEntry(phoneBook);
		}
		else if (choice == 'D' || choice == 'd')
		{
			display(phoneBook);
		}
		else if (choice == 'Q' || choice == 'q')
		{
			break;
		}
	}
	//this additional string variable prevents the program from closing too soon.
	cin >> anykey;

	return 0;
}