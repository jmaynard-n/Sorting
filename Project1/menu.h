#pragma once
#ifndef MENU_H
#define MENU_H
#include "Header.h"

using namespace std;

static void printMenu()
{
	std::cout << "--------------------" << std::endl;
	std::cout << "Menu:" << std::endl;
	std::cout << "-1. closeProgram" << std::endl;
	std::cout << "0. printMenu" << std::endl;
	std::cout << "1. getLength" << std::endl;
	std::cout << "2. getIsEmpty" << std::endl;
	std::cout << "3. get" << std::endl;
	std::cout << "4. getFirst" << std::endl;
	std::cout << "5. getLast" << std::endl;
	std::cout << "6. getSubsequence" << std::endl;
	std::cout << "7. append" << std::endl;
	std::cout << "8. prepend" << std::endl;
	std::cout << "9. insertAt" << std::endl;
	std::cout << "10. remove" << std::endl;
	std::cout << "11. print" << std::endl;
	std::cout << "12. insertionSort" << std::endl;
	std::cout << "13. shellSort" << std::endl;
	std::cout << "--------------------" << std::endl;
}

template<typename T> void menu(Sequence<T> *mySeq)
{
	printMenu();
	while (true) 
	{
		int opt, index, index1;
		T temp;

		cout << "Your entry: ";
		cin >> opt;
		switch (opt)
		{
		case -1:
			return;
		case 0:
			printMenu();
			break;
		case 1:
			cout << "Result: " << mySeq->GetLenght() << endl;
			break;
		case 2:
			cout << "Result: " << mySeq->getIsEmpty() << endl;
			break;
		case 3:
			cout << "Length is " << mySeq->GetLenght() << endl << "Enter index of element: ";
			cin >> index;
			try
			{
				cout << "Result: " << mySeq->Get(index) << endl;
			}
			catch (int errCode)
			{
				cout << errCode << "Element doesn't exist" << endl;
			}
			break;
		case 4:
			try
			{
				cout << "Result: " << mySeq->GetFirst() << endl;
			}
			catch (int errCode) 
			{
				cout << errCode << "Element doesn't exist" << endl;
			}
			break;
		case 5:
			try {
				cout << "Result: " << mySeq->GetLast() << endl;
			}
			catch (int errCode) 
			{
				cout << errCode << "Element doesn't exist" << endl;
			}
			break;
		case 6:
			cout << "Length is " << mySeq->GetLenght() << endl << "\nEnter startIndex: ";
			cin >> index;
			cout << "Enter endIndex: ";
			cin >> index1;
			cout << "Result:" << endl;
			mySeq->GetSubsequence(index, index1)->Print();
			break;
		case 7:
			cout << "Enter value: ";
			cin >> temp;
			mySeq->Append(temp);
			break;
		case 8:
			cout << "Enter value: ";
			cin >> temp;
			mySeq->Prepend(temp);
			break;
		case 9:
			cout << "Enter value: ";
			cin >> temp;
			cout << "Enter index: ";
			cin >> index;
			mySeq->InsertAt(index, temp);
			break;
		case 10:
			cout << "Enter value: ";
			cin >> temp;
			mySeq->Remove(temp);
			break;
		case 11:
			mySeq->Print();
			break;
		case 12:
			cout << "Before:" << endl;
			mySeq->Print();
			cout << "BinaryInsertionSort" << endl;
			opt = clock();
			mySeq->BinaryInsertionSort();
			cout << "After:" << endl;
			mySeq->Print();
			cout << "Time: " << clock() - opt << " ms\n";;
			break;
		case 13:
			cout << "Before" << endl;
			mySeq->Print();
			cout << "shellSort" << endl;
			opt = clock();
			mySeq->ShellSort();
			cout << "After" << endl;
			mySeq->Print();
			cout << "Time: " << clock() - opt << " ms\n";
			break;
		}
	}
}

#endif