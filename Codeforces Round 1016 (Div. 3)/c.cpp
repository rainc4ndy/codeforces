#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long num1, time;
		cin >> num1 >> time;
		if (time >= 2)
		{
			if (num1 == 1 && time == 2)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else
		{
			long long j = 2;
			int k = 0;
			if (num1 == 1)
			{
				k = 2;
			}
			else
			{
				while (j < sqrt(num1))
				{
					if (num1 % j == 0)
					{
						k = 2;
						break;
					}
					j++;
				}
			}
			if (k != 2)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
	system("pause");
	return 0;
}