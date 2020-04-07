#pragma once
#ifndef ARRAYSEQ_H
# define ARRAYSEQ_H

#include <iostream>
#include <random>
#include "Exception.h"
#include "Sequence.h"

using namespace std;

template	<typename T>
class		ArraySequence : public Sequence <T>
{
private:
	T *pArr;

public:
	ArraySequence();
	~ArraySequence();

	T					Get(int index);
	T					GetFirst();
	T					GetLast();
	ArraySequence <T>*	GetSubsequence(int startIndex, int endIndex);
	void				Append(T item);
	void				Prepend(T item);
	void				InsertAt(int index, T item);
	void				Remove(T item);
	void				Print();

	void				AutoFill(int lenght);
	void				ManFill(int lenght);

	void				Replace(int index, T item);
};


template <typename T> void ArraySequence <T> ::Replace(int index, T item)
{
	pArr[index] = item;
}

template <typename T> ArraySequence <T> ::ArraySequence()
{
	pArr = new T;
}

template <typename T> ArraySequence <T> :: ~ArraySequence()
{
	delete pArr;
}

template <typename T> void ArraySequence <T> ::AutoFill(int lenght)
{
	random_device rd;
	mt19937 mersenne(rd());

	for (int i = 0; i < lenght; i++)
		this->Append((T) mersenne());
}

template <typename T> void ArraySequence <T> ::ManFill(int lenght)
{
	T item;

	for (int i = 0; i < lenght; i++)
	{
		cin >> item;
		this->Append(item);
	}
}

template <typename T> void ArraySequence <T> ::Append(T item)
{
	
	if (!(this->size))
	{
		this->size++;
		this->empty = 0;
		pArr[0] = item;
	}
	else
	{
		this->size++;
		T *newArr = new T[this->size];
		for (int i = 0; i < this->size - 1; i++)
			newArr[i] = pArr[i];
		newArr[this->size - 1] = item;
		pArr = newArr;
	}
}

template <typename T> void ArraySequence <T> ::Prepend(T item)
{
	if (this->size == 0)
	{
		this->size++;
		this->empty = 0;
		pArr[0] = item;
	}
	else
	{
		this->size++;
		T *newArr = new T[this->size];
		newArr[0] = item;
		for (int i = 0; i < this->size - 1; i++)
			newArr[i + 1] = pArr[i];
		pArr = newArr;
	}
}

template <typename T> void ArraySequence <T> ::InsertAt(int index, T item)
{
	if (index < 0 || index > this->size - 1)
		throw ExceptionOfSequence(index);
	if (index == 0)
		this->Prepend(item);
	else if (index == this->size - 1)
		this->Append(item);
	else
	{
		this->size++;
		T *newArr = new T[this->size];
		for (int i = 0; i < index; i++)
			newArr[i] = pArr[i];
		newArr[index] = item;
		for (int i = index + 1; i <= this->size; i++)
			newArr[i] = pArr[i - 1];
		pArr = newArr;
	}
}

template <typename T> void ArraySequence <T> ::Remove(T item)
{
	for (int i = 0; i < this->size; i++)
	{
		if (pArr[i] == item)
		{
			this->size--;
			T *newArr = new T[this->size];
			for (int j = 0; j < i; j++)
				newArr[j] = pArr[j];
			for (int k = i; k < this->size; k++)
				newArr[k] = pArr[k + 1];
			pArr = newArr;
			i--;
		}
	}
}

template <typename T> T ArraySequence <T> ::Get(int index)
{
	if (index < 0 || index >(this->size) - 1)
		throw ExceptionOfSequence(index);
	return (pArr[index]);
}

template <typename T> T ArraySequence <T> ::GetFirst()
{
	if (this->empty)
		throw ExceptionOfSequence(0);
	return (pArr[0]);
}

template <typename T> T ArraySequence <T> ::GetLast()
{
	if (this->empty)
		throw ExceptionOfSequence(0);
	return (pArr[this->size - 1]);
}

template <typename T> void ArraySequence <T> ::Print()
{
	for (int i = 0; i < this->GetLenght(); i++)
		cout << i << "\t" << pArr[i] << endl;
}

template <typename T> ArraySequence<T>* ArraySequence <T> ::GetSubsequence(int startIndex, int endIndex)
{
	if (startIndex < 0 || startIndex > this->size + 1)
		throw ExceptionOfSequence(startIndex);
	else if (endIndex < 0 || endIndex > this->size + 1)
		throw ExceptionOfSequence(endIndex);
	else if (endIndex - startIndex < 0)
		throw ExceptionOfSequence(endIndex - startIndex);
	else
	{
		ArraySequence<T>* pSub = new ArraySequence <T>;

		for (int i = startIndex; i <= endIndex; i++)
			pSub->Append(pArr[i]);

		return (pSub);
	}
}

#endif