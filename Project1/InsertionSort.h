#pragma once
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "Sequence.h"
#include "ArraySeq.h"
#include "ListSeq.h"

template <typename T> Sequence<T>* InsertionSort(Sequence<T>* seq)
{
	T		key;
	int		j;

	for (int i = 1; i < this->GetLenght(); i++)
	{
		key = this->Get(i);
		for (j = i - 1; (j >= 0) && (this->Get(j) > key); j--)
			this->InsertAt(j + 1, this->Get(j));
		this->InsertAt(j + 1, key);
	}
}

#endif