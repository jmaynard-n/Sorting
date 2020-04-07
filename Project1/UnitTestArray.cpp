#include "Header.h"

using namespace std;

int	test_array(int i)
{
	if(i)
		cout << "\nTEST ARRAY SEQUENCE		START\n\n";

	ArraySequence<int> arr;

	if (arr.GetLenght() != 0)
	{
		cout << "GetLenght() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLenght() test		SUCCESS\n";

	arr.Append(23);

	if (arr.GetLenght() != 1)
	{
		cout << "GetLenght() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLenght() test		SUCCESS\n";

	try
	{
		if (arr.GetFirst() != 23)
		{
			cout << "GetFirst() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << arr.GetFirst() << "GetFirst() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetFirst() test			SUCCESS\n";

	try
	{
		if (arr.GetLast() != 23)
		{
			cout << "GetLast() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetLast() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLast() test			SUCCESS\n";

	try
	{
		if (arr.Get(0) != 23)
		{
			cout << "Get() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
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

	int flag = 1;
	
	try
	{
		arr.Get(-1);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	flag = 1;
	try
	{
		arr.Get(1);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	arr.Append(43);
	
	if (arr.GetLenght() != 2)
	{
		cout << "GetLenght() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLenght() test		SUCCESS\n";

	try
	{
		if (arr.GetFirst() != 23)
		{
			cout << "GetFirst() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetFirst() test			SUCCESS\n";

	try
	{
		if (arr.GetLast() != 43)
		{
			cout << "GetLast() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetLast() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLast() test			SUCCESS\n";

	try
	{
		if (arr.Get(0) != 23)
		{
			cout << "Get() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
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

	try
	{
		if (arr.Get(1) != 43)
		{
			cout << "Get() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
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
		arr.Get(-1);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	flag = 1;
	try
	{
		arr.Get(2);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	arr.Prepend(53);

	if (arr.GetLenght() != 3)
	{
		cout << "GetLenght() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLenght() test		SUCCESS\n";

	try
	{
		if (arr.GetFirst() != 53)
		{
			cout << "GetFirst() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetFirst() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetFirst() test			SUCCESS\n";

	try
	{
		if (arr.GetLast() != 43)
		{
			cout << "GetLast() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetLast() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLast() test			SUCCESS\n";

	try
	{
		if (arr.Get(0) != 53)
		{
			cout << "Get() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
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

	try
	{
		if (arr.Get(1) != 23)
		{
			cout << "Get() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
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
		arr.Get(-1);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	flag = 1;
	try
	{
		arr.Get(3);
	}
	catch (ExceptionOfSequence error)
	{
		flag = 0;
	}
	if (flag)
	{
		cout << "Get() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "Get() test			SUCCESS\n";

	ArraySequence<int>* pSub = new ArraySequence<int>;

	try
	{
		pSub = arr.GetSubsequence(1, 1);
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetSubsequence() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetGetSubsequence() test	SUCCESS\n";

	if (pSub->GetLenght() != 1)
	{
		cout << pSub->GetLenght() << " GetLenght() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GeLenght() test			SUCCESS\n";

	try
	{
		if (pSub->GetFirst() != 23)
		{
			cout << "GetFirst() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetFirst() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetFirst() test			SUCCESS\n";

	try
	{
		if (pSub->GetLast() != 23)
		{
			cout << "GetLast() test failed\n";
			cout << " End Array Test: FAILED with one error\n";
			return 1;
		}
	}
	catch (ExceptionOfSequence error)
	{
		error.description();
		cout << "GetLast() test failed\n";
		cout << " End Array Test: FAILED with one error\n";
		return 1;
	}
	if (i)
		cout << "GetLast() test			SUCCESS\n";

	if (i)
		cout << "\nTEST ARRAY SEQUENCE		END\n\n";

	return 0;
}