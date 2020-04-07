#pragma once
#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include "Sequence.h"
#include "ArraySeq.h"
#include "ListSeq.h"

template <typename T> Sequence <T>* BinaryInsertionSort(Sequence<T>* seq)
{
	T		key;
	int		left;
	int		right;
	int		mid;

	Sequence<T>* seqSort = new Sequence<T>;

	for (int i = 0; i < seq->GetLenght(); i++)
		seqSort->Append(seq->Get(i));

	for (int i = 1; i < seq->GetLenght(); i++)
		if (seqSort->Get(i - 1) > seqSort->Get(i))
		{
			key = seqSort->Get(i);
			left = 0;
			right = i - 1;
			do {
				mid = (left + right) / 2;
				if (seqSort->Get(mid) < key)
					left = mid + 1;
				else  
					right = mid - 1;
			} while (left <= right);
			for (int j = i - 1; j >= left; j--)
				seqSort->InsertAt(j + 1, seqSort->Get(j));
			seqSort->InsertAt(left, key);
		}

	return (seqSort);
}

#endif