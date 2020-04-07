#include "Header.h"

using namespace std;

int	test_list(int i)
{
	if (i)
		cout << "\nTEST LIST SEQUENCE		START\n\n";

	ListSequence<int> list;

	if (list.GetLenght() != 0)
	{
		cout << "GetLenght() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLenght() test		SUCCESS\n";

	list.Append(23);

	if (list.GetLenght() != 1)
	{
		cout << "GetLenght() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLenght() test		SUCCESS\n";

	try
	{
		if (list.GetFirst() != 23)
		{
			cout << "GetFirst() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetFirst() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetFirst() test			SUCCESS\n";

	try
	{
		if (list.GetLast() != 23)
		{
			cout << "GetLast() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetLast() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLast() test			SUCCESS\n";

	try
	{
		if (list.Get(0) != 23)
		{
			cout << "Get() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	int flag = 1;

	try
	{
		list.Get(-1);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	flag = 1;
	try
	{
		list.Get(1);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	list.Append(43);

	if (list.GetLenght() != 2)
	{
		cout << "GetLenght() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLenght() test		SUCCESS\n";

	try
	{
		if (list.GetFirst() != 23)
		{
			cout << "GetFirst() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetFirst() test			SUCCESS\n";

	try
	{
		if (list.GetLast() != 43)
		{
			cout << "GetLast() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetLast() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLast() test			SUCCESS\n";

	try
	{
		if (list.Get(0) != 23)
		{
			cout << "Get() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	try
	{
		if (list.Get(1) != 43)
		{
			cout << "Get() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "Get() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	flag = 1;
	try
	{
		list.Get(-1);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	flag = 1;
	try
	{
		list.Get(2);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	list.Prepend(53);

	if (list.GetLenght() != 3)
	{
		cout << "GetLenght() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLenght() test		SUCCESS\n";

	try
	{
		if (list.GetFirst() != 53)
		{
			cout << "GetFirst() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetFirst() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetFirst() test			SUCCESS\n";

	try
	{
		if (list.GetLast() != 43)
		{
			cout << "GetLast() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetLast() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLast() test			SUCCESS\n";

	try
	{
		if (list.Get(0) != 53)
		{
			cout << "Get() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	try
	{
		if (list.Get(1) != 23)
		{
			cout << "Get() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	flag = 1;
	try
	{
		list.Get(-1);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	flag = 1;
	try
	{
		list.Get(3);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	ListSequence<int>* pSub = new ListSequence<int>;

	try
	{
		pSub = list.GetSubsequence(1, 1);
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetSubsequence() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetGetSubsequence() test	SUCCESS\n";

	if (pSub->GetLenght() != 1)
	{
		cout << pSub->GetLenght() << " GetLenght() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GeLenght() test			SUCCESS\n";

	try
	{
		if (pSub->GetFirst() != 23)
		{
			cout << "GetFirst() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetFirst() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetFirst() test			SUCCESS\n";

	try
	{
		if (pSub->GetLast() != 23)
		{
			cout << "GetLast() test failed\n";
			cout << " End List Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetLast() test failed\n";
		cout << " End List Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLast() test			SUCCESS\n";

	if (i)
		cout << "\nTEST LIST SEQUENCE		END\n\n";

	return 0;
}