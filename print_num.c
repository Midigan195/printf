#include"main.h"
#include<stdio.h>

/**
 * power - cacculates the power of number to base
 * @b: base
 * @p: power
 * Return: power of base
*/
int power(int b, int p)
{
	long int n = b;
	int i = 0;
	int j = 0;

	if(b == 0)
		return(0);
	if (p == 0)
		return(1);
	while (i < (p - 1))
	{
		i++;
		n = n*b;
	}
	j = (int)n;

	return (j);
}
/**
 * get_num - gets an integer and returns specified digit
 * @n: integer
 * @p: position of digit
 * Return: converted integer;
*/

char get_num(int n ,int p)
{
	int value = 0;
	int fact1 = power(10,p);
	int fact2 = power(10,p - 1);

	if (p == 1)
		value = (n % 10);
	else 
		value = ((n % fact1) - (n % fact2)) / (fact2);
	return ('0' + value);
}
/**
 * print_num - prints number to terminal
 * @n: integer to be prinmted
 * Return: number of characters printed
*/

int print_num(int n)
{
	int i = 1;
	int dup = n;
	int num = 0;
	int j = 0;

	if (n < 0)
	{
		print_char('-');
		dup = (n * -1);
	}
	num = dup;
	while ((num / 10)> 0)
	{
		num = num / 10;
		i++;
	}
	while (j < i)
	{
		print_char(get_num(dup,i - j));
		j++;
	}
	if (n < 0)
		i++;

	return (i);
}
