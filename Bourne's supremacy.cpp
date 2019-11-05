#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

int container[20][1000];
bool output[20];
int constraint[20][2];

bool recursive(int _test, int _index, int _element);

int main()
{
	int test, element[20];

	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> element[i];

		for (int j = 0; j < element[i]; j++)
			cin >> container[i][j];

		cin >> constraint[i][0] >> constraint[i][1];
	}

	/*for (int i = 0; i < test; i++)
	{
		for (int j = 0; j < element[i]; j++)
			cout << container[i][j] << " ";

		cout << constraint[i][0] << constraint[i][1] << endl;
	}*/

	for (int i = 0; i < test; i++)
	{
		recursive(i, constraint[i][0], element[i]);
	}

	return 0;
}

bool recursive(int _test, int _index, int _element)
{
	
	static int counter;
	counter++;

	if (container[_test][_index] == constraint[_test][1])
	{
		cout << "Yes" << endl;
		return true;
	}

	else
	{
		if (counter >= _element - 1)
		{
			counter = 0;
			cout << "No" << endl;
			return false;
		}

		else return recursive(_test, container[_test][_index], _element);
	}

}
