//////////////////////////////////////////////////////////////
// CSCE-221 Data Structures & Algorithms
// Lab4 Measuring Time
// Author: Zhipei Yan
// Date: 9/18/2019
// A simple demo of timing on different arithmetic functions
// Add your own functions
//////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <chrono>

void nothing(int n)
{

}

int slowSummation(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n--;
	}
	return sum;
}

//overflow when n>92
long long fibo(int n)
{
	if (n <= 0)
	{
		return 0;
	}

	long long a = 1, b = 1;
	long long temp = 0;
	for (int i = 3; i <= n; i++)
	{
		temp = b;
		b += a;
		a = temp;
	}
	return b;
}

int main()
{
	std::vector<int> testing{ 1, 1000, 1000000 };
	for (int n : testing)
	{
		//Get time before func
		std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

		fibo(n);

		//Get time after func
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

		//Find duration
		std::chrono::nanoseconds elap = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		std::cout << "Elapsed (ns): " << elap.count() << std::endl;
	}

	return 0;
}