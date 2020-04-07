#ifndef EXEPTION_H
# define EXEPTION_H
# ifndef IOSTREAM_H
#  define IOSTREAM_H
#  include <iostream> 
# endif

using namespace std;

class ExceptionOfSequence : public exception
{
private:
	int index;

public:
	ExceptionOfSequence(int i)
	{
		index = i;
	}

	void description()
	{
		cout << "Error with element "<< index << endl;
	}
};

#endif