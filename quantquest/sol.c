
#include <stdio.h>

/*

BEGINNING OF PROBLEM STATEMENT:
Mr. S. and Mr. P. are both perfect logicians, being able to correctly deduce
any truth from any set of axioms.  Two integers (not necessarily unique) are
somehow chosen such that each is within some specified range.  Mr. S.
is given the sum of these two integers; Mr. P. is given the product of these
two integers.  After receiving these numbers, the two logicians do not
have any communication at all except the following dialogue:
<<1>>   Mr. P.:  I do not know the two numbers.
<<2>>   Mr. S.:  I knew that you didn't know the two numbers.
<<3>>   Mr. P.:  Now I know the two numbers.
<<4>>   Mr. S.:  Now I know the two numbers.

Given that the above statements are absolutely truthful, what are the two
numbers?

END OF PROBLEM STATEMENT

 */

#define SMALLEST_MIN	2
#define LARGEST_MIN	10
#define SMALLEST_MAX	50
#define LARGEST_MAX	1000

long P[(LARGEST_MAX + 1) * (LARGEST_MAX + 1)];		/* products */
long S[(LARGEST_MAX + 1) + (LARGEST_MAX + 1)];		/*   sums   */

void find(long min, long max)
{
	long i, j;
	/*
	 *	count factorizations in P[]
	 *	all P[n] > 1 satisfy <<1>>.
	 */
	for(i = 0; i <= max * max; ++i)
		P[i] = 0;

	for(i = min; i <= max; ++i)
		for(j = i; j <= max; ++j)
			++P[i * j];

	/*
	 *	decompose possible SUMs and check factorizations
	 *		all S[n] == min - 1 satisfy <<2>>.
	 */
	for(i = min + min; i <= max + max; ++i) {

		for(j = i / 2; j >= min; --j)
			if(P[j * (i - j)] < 2 && j<max && (i-j)<max)
				break;

		S[i] = j;
	}

	for(i=0; i<2*max+1;i++) if(S[i]>0) printf("%ld --- %ld\n", (i-S[i]), S[i]);
	/*
	 *	decompose SUMs which satisfy <<2>> and see which products
	 *	they produce.  All (P[n] / 1000 == 1) satisfy <<3>>.
	 */
	for(i = min + min; i <= max + max; ++i)
		if(S[i] == min - 1)
			for(j = i / 2; j >= min; --j)
				if(P[j * (i - j)] > 1 && j<max && (i-j)<max)
					P[j * (i - j)] += 2*max;
					// P[j * (i - j)] += 1000;

	/*
	 *	decompose SUMs which satisfy <<2>> again and see which products
	 *	satisfy <<3>>.  Any (S[n] == 999 + min) satisfies <<4>>
	 */
	for(i = min + min; i <= max + max; ++i)
		if(S[i] == min - 1)
			for(j = i / 2; j >= min; --j)
				if(P[j * (i - j)] / 1000 == 1 && j<max && (i-j)<max)
					S[i] += 1000;
	/*
	 *	find the answer(s) and print them
	 */
	printf("[%ld,%ld]\n",min,max);
	for(i = min + min; i <= max + max; ++i)
		if(S[i] == 999 + min)
			for(j = i / 2; j >= min; --j)
				if(P[j * (i - j)] / 1000 == 1 && j<max && (i-j)<max)
					printf("{ %ld %ld }: S = %ld, P = %ld\n",
						i - j, j, i, (i - j)  * j);
}

int main()
{
	long min=1, max=1000;
	find(min, max);

	// for (min = SMALLEST_MIN; min <= LARGEST_MIN; min ++)
	//     for (max = SMALLEST_MAX; max <= LARGEST_MAX; max++)
	// 	find(min,max);
	return 0;
}