#pragma once
#ifndef TEST_SORT_H
#define TEST_SORT_H
#include "Header.h"
#include <iomanip>

using namespace std;

template <typename T> void compareSorts()
{
	Sequence<T> *arr_seq1 = new ArraySequence<T>(),
				*arr_seq2 = new ArraySequence<T>(), 
				*lst_seq1 = new ListSequence<T>(), 
				*lst_seq2 = new ListSequence<T>();
	int temp, length;
	T randomValue;

	cout << "Enter length of random sequence: ";
	cin >> length;
	cout << "\nCreating sequences... Please wait\n";

	for (int i = 0; i < length; i++) 
	{
		cout << "\rProcessing: " << i * 100 / length << "%";
		randomValue = ((T)rand() - RAND_MAX / 2) / 19 * 20;
		arr_seq1->Append(randomValue);
		arr_seq2->Append(randomValue);
		lst_seq1->Append(randomValue);
		lst_seq2->Append(randomValue);
	}
	cout << "\nCreated successfully. \n";
	cout << "Print sequence?\n";
	cout << "	1 - Yes\n";
	cout << "	0 - No\n";
	cout << "Your answer: ";
	cin >> temp;
	cout << endl;
	if (temp)
		arr_seq1->Print();
	
	cout << "This sequence was created in 4 instances (2 as ArraySequence, 2 as ListSequence)\n "
		<< "to compare Shell and BinaryInsertion sorts\n";
	cout << setw(15) << "";
	cout << setw(15) << "ArraySequence";
	cout << setw(15) << "ListSequence" << endl;

	cout << setw(15) << "InsertionSort";

	temp = clock();
	arr_seq1->BinaryInsertionSort();
	cout << setw(15) << (clock() - temp) << "s";

	temp = clock();
	lst_seq1->BinaryInsertionSort();
	cout << setw(15) << (clock() - temp) << "s" << endl;

	cout << setw(15) << "ShellSort";

	temp = clock();
	arr_seq2->ShellSort();
	cout << setw(15) << (clock() - temp) << "s";

	temp = clock();
	lst_seq2->ShellSort();
	cout << setw(15) << (clock() - temp) << "s" << endl;

	cout << "Show results?\n";
	cout << "	1 - Yes\n";
	cout << "	0 - No\n";
	cout << "Your answer: ";
	cin >> temp;
	cout << endl;
		
	if (temp)
	{
		cout << "Array | BinaryInsertion |\n";
		arr_seq1->Print();
		cout << "\nList  | BinaryInsertion |\n";
		lst_seq1->Print();
		cout << "\n\nArray | Shell |\n";
		arr_seq2->Print();
		cout << "\nList  | Shell |\n";
		lst_seq2->Print();
	}

	delete arr_seq1;
	delete arr_seq2;
	delete lst_seq1;
	delete lst_seq2;
}


template <typename T> void testSorts()
{
	Sequence<T> *seq = new ArraySequence<T>();
	int length;
	int	temp;
	int time;

	cout << "Enter length of random sequence: ";
	cin >> length;
	cout << "\nCreating sequence... Please wait\n";

	for (int i = 1; i <= length; i++) {
		cout << "\rProcessing: " << i * 100 / length << "%";
		seq->Append((T)(double)((rand() - RAND_MAX / 2) / 19 * 20));
	}

	cout << "\nCreated successfully. Print sequence?\n";
	cout << "	1 - Yes\n";
	cout << "	0 - No\n";
	cout << "Yor answer: ";
	cin >> temp;
	cout << endl;

	if (temp)
		seq->Print();

	cout << "\nPlease, choose sorting method: \n";
	cout << "	0 - BinaryInsertion\n"
		<< "	1 - Shell\n"
		<< "Your answer:  ";
	cin >> temp;

	time = clock();
	if (!temp)
		seq->BinaryInsertionSort();
	else if (temp)
		seq->ShellSort();

	cout << "\nSorted succesfully.\n Time: " << (clock() - temp) / 1000 << " s\n\n";

	cout << "Print sequence?\n";
	cout << "	1 - Yes\n";
	cout << "	0 - No\n";
	cout << "Yor answer: ";
	cin >> temp;
	cout << endl;
	if (temp)
		seq->Print();
}

#endif