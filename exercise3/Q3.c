
/*
A prime integer is any integer greater than 1 that can be divided evenly only by itself and 1.
The Sieve of Eratosthenes is a method of finding prime numbers.
It works as follows:
a) Create an array with all elements initialized to 1 (true).
Array elements with prime indices will remain 1.
All other array elements will eventually be set to zero.
b) Starting with array index 2 (index 1 is not prime), every time an array element is found whose
value is 1, loop through the remainder of the array and set to zero every element whose index is
a multiple of the index for the element with value 1.
For array index 2, all elements beyond 2 in the array that are multiples of 2 will be set to zero (indices 4, 6, 8, 10, and so on.).
For array index 3, all elements beyond 3 in the array that are multiples of 3 will be set to zero (indices 6, 9, 12, 15, and so on.).
When this process is complete, the array elements that are still set to 1 indicate that the index is a prime number.
Write a program that uses an array of 1,000 elements to determine and print the prime numbers between 1 and 999.
Ignore element 0 of the array.
*/
// Sieve of Eratosthenes
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void SieveOfEratosthenes(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{

		if (prime[p] == true)
		{

			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p])
			printf("%d ", p);
}

int main()
{
	int n = 1000;
	printf("Following are the prime numbers smaller than or equal to %d \n", n);
	SieveOfEratosthenes(n);
	return 0;
}
