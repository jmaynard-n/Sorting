#pragma once
#ifndef COUNTING_SORT_H
# define COUNTING_SORT_H

#include "Sequence.h"
#include "ArraySeq.h"
#include "ListSeq.h"

template <typename T> void boundary(Sequence <T> *seq, T *min, T *max)
{
	*min = seq->GetFirst();
	*max = seq->GetFirst();

	for (int i = 1; i < seq->GetLenght(); i++)
	{
		if (*min > seq->Get(i))
			*min = seq->Get(i);
		if (*max < seq->Get(i))
			*max = seq->Get(i);
	}
}

template <typename T> Sequence <T>* CountingSort(Sequence<T>* seq)
{
	T min;
	T max;
	Sequence<T>* seqSort = new Sequence<T>;

	boundary(seq, &min, &max);

	int *cnt = new int[max - min + 1];

	for (int i = min; i < max + 1; i++)
		cnt[i - min] = 0;
	for (int i = 0; i < seq->GetLenght(); i++)
		++cnt[seq->Get(i) - min];
	for (int i = min; i < max + 1; i++)
		for (int j = cnt[i - min]; j--; )
			seqSort->Append(i);

	return(seqSort);
}

#endif