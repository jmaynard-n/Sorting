#pragma once
#ifndef SEQUENCE_H
# define SEQUENCE_H

using namespace std;

template<typename T> 
class	Sequence
{
protected:
	int		size;
	int		empty;

public:
	Sequence();
	~Sequence();

	int		GetLenght()
	{
		return size;
	}
	void	SetLenght(int i)
	{
		size = i;
	}
	int		getIsEmpty()
	{
		return empty;
	}
	void	setEmpty(int i)
	{
		empty = i;
	}

	virtual T				Get(int index) = 0;
	virtual T				GetFirst() = 0;
	virtual T				GetLast() = 0;
	virtual Sequence <T>*	GetSubsequence(int startIndex, int endIndex) = 0;
	virtual void			Append(T item) = 0;
	virtual void			Prepend(T item) = 0;
	virtual void			InsertAt(int index, T item) = 0;
	virtual void			Remove(T item) = 0;
	virtual void			Print() = 0;

	void					BinaryInsertionSort();
	void					ShellSort();
	virtual void			Replace(int index, T item) = 0;
};

template <typename T> void Sequence <T> ::BinaryInsertionSort()
{
	T		key;
	int		left;
	int		right;
	int		mid;

	for (int i = 1; i < this->GetLenght(); i++)
		if (this->Get(i - 1) > this->Get(i))
		{
			key = this->Get(i);
			left = 0;
			right = i - 1;
			do
			{
				mid = (left + right) / 2;
				if (this->Get(mid) < key)
					left = mid + 1;
				else
					right = mid - 1;
			} while (left <= right);
			for (int j = i - 1; j >= left; j--)
				this->Replace(j + 1, this->Get(j));
			this->Replace(left, key);
		}
}

template <typename T> void Sequence <T> ::ShellSort()
{
	int i, j, k;
	T temp;

	for (k = this->GetLenght() / 2; k > 0; k /= 2)
		for (i = k; i < this->GetLenght(); i++)
		{
			temp = this->Get(i);
			for (j = i; j >= k; j -= k)
			{
				if (temp < this->Get(j - k))
					this->Replace(j, this->Get(j - k));
				else
					break;
			}
			this->Replace(j, temp);
		}
}

template <typename T> Sequence <T> :: Sequence()
{
	size = 0;
	empty = 1;
}

template <typename T> Sequence <T> :: ~Sequence()
{
}


#endif