#pragma once
#ifndef LISTSEQ_H
# define LISTSEQ_H

#include "Sequence.h"
#include "Exception.h"

using namespace std;

template	<typename T>
struct		t_list
{
	T				data;
	t_list <T>		*next;
	t_list <T>		*prev;
};

template	<typename T>
class		ListSequence : public Sequence <T>
{
private:
	t_list <T>	*head;
	t_list <T>	*tail;
public:
	ListSequence();
	~ListSequence();

	T					Get(int index);
	T					GetFirst();
	T					GetLast();
	ListSequence <T>*	GetSubsequence(int startIndex, int endIndex);
	void				Append(T item);
	void				Prepend(T item);
	void				InsertAt(int index, T item);
	void				Remove(T item);
	void				Print();

	void				Replace(int index, T item);
};

template <typename T> void ListSequence <T> ::Replace(int index, T item)
{
	t_list <T> *temp = new t_list <T>;
	int i = 0;

	temp = head;
	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	temp->data = item;
	
}

template <typename T> void ListSequence <T> ::Print()
{
	t_list<T> *temp = new t_list<T>;
	int i = 0;

	temp = head;
	while (temp)
	{
		cout << " " << i << "	" << temp->data << " \n";
		temp = temp->next;
	}

	delete temp;
}

template <typename T> ListSequence <T> ::ListSequence()
{
	head = NULL;
	tail = NULL;
}

template <typename T> ListSequence <T> :: ~ListSequence()
{
	while (head)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
}

template <typename T> void ListSequence <T> ::Append(T item)
{
	t_list <T>	*temp = new t_list <T>;

	temp->next = NULL;
	temp->data = item;
	if (this->size != 0)
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		this->size++;
	}
	else
	{
		temp->prev = NULL;
		head = temp;
		tail = temp;
		this->size++;
		this->empty = 0;
	}
}

template <typename T> void ListSequence <T> ::Prepend(T item)
{
	t_list <T>	*temp = new t_list <T>;

	temp->prev = NULL;
	temp->data = item;
	if (this->size != 0)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
		this->size++;
	}
	else
	{
		temp->next = NULL;
		head = temp;
		tail = temp;
		this->size++;
		this->empty = 0;
	}
}

template <typename T> void ListSequence <T> ::InsertAt(int index, T item)
{
	if (index < 0 || index > this->size)
		throw ExceptionOfSequence(index);
	else if (index == 0)
		Prepend(item);
	else if (index == this->size - 1)
		Append(item);
	else
	{
		t_list <T> *temp = new t_list <T>;

		this->size++;
		temp->data = item;
		temp->next = head->next;
		temp->prev = head;
		while (index - 2 > 0)
		{
			temp->prev = (temp->prev)->next;
			temp->next = (temp->next)->next;
			index--;
		}
		(temp->prev)->next = temp;
		(temp->next)->prev = temp;
	}
}

template <typename T> void ListSequence <T> ::Remove(T item)
{
	int	i;
	int j;

	i = 0;
	while (i < this->size - 1)
	{
		t_list <T>	*temp;

		temp = new t_list <T>;
		j = i;
		temp->next = head;
		while ((temp->next)->data != item && j < this->size - 1)
		{
			temp->next = (temp->next)->next;
			j++;
			i++;
		}
		if ((temp->next)->data == item)
		{
			temp = temp->next;
			if (temp->prev != 0)
				(temp->prev)->next = temp->next;
			else
				head = temp->next;
			if (temp->next != 0)
				(temp->next)->prev = temp->prev;
			else
				tail = temp->prev;
			if (this->size == 0)
				this->empty = 0;
			this->size--;
			delete temp;
		}
	}
}

template <typename T> T ListSequence <T> ::Get(int index)
{
	if (index < 0 || index > this->size - 1)
		throw ExceptionOfSequence(index);
	if (index == 0)
		return (GetFirst());
	else if (index == this->size - 1)
		return(GetLast());
	else
	{
		t_list <T>	*temp = new t_list <T>;

		temp->next = head->next;
		while (index - 1 > 0)
		{
			temp->next = (temp->next)->next;
			index--;
		}
		return ((temp->next)->data);
	}
}

template <typename T> T ListSequence <T> ::GetFirst()
{
	if (!head)
		throw ExceptionOfSequence(0);
	else
		return (head->data);
}

template <typename T> T ListSequence <T> ::GetLast()
{
	if (!tail)
		throw ExceptionOfSequence(0);
	else
		return (tail->data);
}

template <typename T> ListSequence <T>* ListSequence <T>	::GetSubsequence(int startIndex, int endIndex)
{
	if (startIndex < 0 || startIndex > this->size + 1)
		throw ExceptionOfSequence(startIndex);
	else if (endIndex < 0 || endIndex > this->size + 1)
		throw ExceptionOfSequence(endIndex);
	else if (endIndex - startIndex < 0)
		throw ExceptionOfSequence(endIndex - startIndex);
	else
	{
		ListSequence<T>* pSub = new ListSequence <T>;
		t_list <T>* temp = new t_list <T>;
		
		temp = head;

		for (int i = startIndex; i <= endIndex; i++)
			temp = temp->next;
		for (int i = startIndex - 1; i < endIndex; i++)
		{
			pSub->Append(temp->data);
			temp = temp->next;
		}

		return (pSub);
	}
}

#endif