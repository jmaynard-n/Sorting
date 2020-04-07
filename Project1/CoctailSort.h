#pragma once
#ifndef COCTAIL_SORT_H
#define COCTAIL_SORT_H

#include "Sequence.h"
#include "ArraySeq.h"
#include "ListSeq.h"

template <typename T> Sequence<T>* CoctailSort(Sequence<T>* seq)
{
	Sequence<T>* seqSort = new Sequence<T>;

	for (int i = 0; i < seq->GetLenght(); i++)
		seqSort->Append(seq->Get(i));

	for (int left = 0, right = seq->GetLenght() - 1; left < right; )
	{
		for (int i = left; i < right; i++)
			if (seqSort->Get(i + 1) < seqSort->Get(i))
			{
				T temp = seqSort->Get(i);
				seqSort->InsertAt(i, seqSort->Get(i + 1));
				seqSort->InsertAt(i + 1, temp);
			}
		right--;

		for (int i = right; i > left; i--)
			if (seqSort->Get(i - 1) > seqSort->Get(i))
			{
				T temp = seqSort->Get(i);
				seqSort->InsertAt(i, seqSort->Get(i - 1));
				seqSort->InsertAt(i - 1, temp);
			}
		left++;
	}

	return (seqSort);
}

#endif