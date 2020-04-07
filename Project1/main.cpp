#include "Header.h"
#include "menu.h"
#include "UnitTestSort.h"
#include <iostream>
using namespace std;

int		main()
{
	if (test_array(0) || test_list(0)) //silence mode
	{
		cout << "Please, check sequences realizations\n";
		return (0);
	}

	int temp;
	int type;

	cout << "Do you want to test system?\n";
	cout << "	1 - Yes\n";
	cout << "	0 - No\n";
	cout << "Your answer: ";
	cin >> temp;
	cout << endl;

	if (temp)
	{
		cout << "Test sequences?\n";
		cout << "	1 - Yes\n";
		cout << "	0 - No\n";
		cout << "Your answer: ";
		cin >> temp;
		cout << endl;

		if (temp)
		{
			test_array(1);
			test_list(1);
		}

		cout << "Test sorting methods?\n";
		cout << "	1 - Yes\n";
		cout << "	0 - No\n";
		cout << "Your answer: ";
		cin >> temp;
		cout << endl;

		while (temp)
		{
			cout << "Which one do you prefer: int or double?\n";
			cout << "	0 - INT\n";
			cout << "	1 - DOUBLE\n";
			cout << "Your answer: ";
			cin >> temp;
			cout << endl;

			if (!temp)
				testSorts<int>();
			else if (temp)
				testSorts<double>();

			cout << "\nOne more time?\n";
			cout << "	1 - Yes\n";
			cout << "	0 - No\n";
			cout << "Your answer: ";
			cin >> temp;
			cout << endl;
		}

		cout << "Compare sorts?\n";
		cout << "	1 - Yes\n";
		cout << "	0 - No\n";
		cout << "Your answer: ";
		cin >> temp;
		cout << endl;

		while (temp)
		{
			cout << "Which one do you prefer: int or double?\n";
			cout << "	0 - INT\n";
			cout << "	1 - DOUBLE\n";
			cout << "Your answer: ";
			cin >> temp;
			cout << endl;

			if (!temp)
				compareSorts<int>();
			else if (temp)
				compareSorts<double>();

			cout << "\nOne more time?\n";
			cout << "	1 - Yes\n";
			cout << "	0 - No\n";
			cout << "Your answer: ";
			cin >> temp;
			cout << endl;
		}
	}

	else 
	{
		cout << "Which one do you prefer: int or double?\n";
		cout << "	0 - INT\n";
		cout << "	1 - DOUBLE\n";
		cout << "Your answer: ";
		cin >> temp;
		cout << endl;

		cout << "Which realization: array or list?\n";
		cout << "	0 - ARRAY\n";
		cout << "	1 - LIST\n";
		cout << "Your answer: ";
		cin >> type;
		cout << endl;
		if (!temp)
		{
			if (!type)
			{
				ArraySequence <int> *mySeq = new ArraySequence <int>();
				menu(mySeq);
			}
			else if (type) 
			{
				ListSequence <int> *mySeq = new ListSequence <int>();
				menu(mySeq);
			}
			else cout << "Wrong enter\n";
		}
		else if (type)
		{
			if (!type)
			{
				ArraySequence <int> *mySeq = new ArraySequence <int>();
				menu(mySeq);
			}
			else if (type)
			{
				ListSequence <int> *mySeq = new ListSequence <int>();
				menu(mySeq);
			}
			else cout << "Wrong enter\n";
		}
	}

	return 0;
}
