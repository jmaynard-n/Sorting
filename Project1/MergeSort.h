#pragma once
#ifndef MERGE_SORT_H
# define MERGE_SORT_H

#include "Sequence.h"
#include "ArraySeq.h"
#include "ListSeq.h"

template <typename T> void merge(Sequence<T>* seq, int left, int mid, int right)
{
	int l = left;
	int r = mid + 1;
	Sequence<T>* seqSort = new Sequence<T>;

	for (int i = left; i <= right; i++)
	{
		if (l <= mid && r <= right)
		{
			if (seq->Get(l) < seq->Get(r))
				seqSort->InsertAt(i++, seq->Get(l++));
			else
				seqSort->InsertAt(i++, seq->Get(r++));
		}
		else if (l <= mid)
			seqSort->InsertAt(i++, seq->Get(l++));
		else
			seqSort->InsertAt(i++, seq->Get(r++));
	}

	for (int i = 0; i < seq->GetLenght(); i++)
		seq->Append(seqSort->Get(i));
}

template <typename T> void merge_sort(Sequence<T>* seq, int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;

	merge_sort(seq, left, mid);
	merge_sort(seq, mid + 1, right);

	merge(seq, left, mid, right);
}

template <typename T> Sequence<T>* MergeSort(Sequence<T>* seq)
{
	Sequence<T>* seqSort = new Sequence<T>; 
	
	for (int i = 0; i < seq->GetLenght(); i++)
		seqSort->Append(seq->Get(i));

	merge_sort(seqSort, 0, seq->GetLenght() - 1);

	return (seqSort);
}

#endif