#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include "math.h"





#define PI 3.14159265358979323846



void test_switch(int num)
{
	switch (num)
	{
	case 1:
		printf("1");
	case 2:
		printf("2");
	case 3:
		printf("3");
	}
}//测试switch

int absolute_value(int x)
{
	if (x < 0)
	{
		return -x;
	}
	else if (x > 0)
	{
		return x;
	}
}//绝对值

int test_return(int num)
{
	return num + 1;
}//测试return

int factorial(int n)
{
	int recurse = factorial(n - 1);
	int result = n * recurse;
	return result;
}//递归定义的示例

int find_GCD(int a, int b)
{
	int GCD=0;
	if (b != 0)
	{
		if (a % b == 0)
		{
			GCD = b;
		}
		else
		{
			GCD = find_GCD(b, a % b);
		}
	}
	else
	{
		printf("ERROR");
	}

	return GCD;
}//Euclid算法,求最大公约数

int find_fibonacci(int num)
{
	int fibonacci;

	//num = num - 1;


	if (num == 1 || num == 0)
	{
		fibonacci = 1;
	}
	else
	{
		fibonacci = find_fibonacci(num - 1) + find_fibonacci(num - 2);
	}

	return fibonacci;
}//斐波那契数列


int for_turn_plus_behind()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d", i);
	}
	return 0;
}

int for_turn_plus_forward()
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%d", i);
	}
	return 0;
}

void paint_ninenine()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (i >= j)
				printf("%d\t", i * j);
		}
		printf("\n");
	}
}

//void diamond(int num, char a)     不加*号是错的
void diamond(int num, char* a)
{
	if (num % 2 == 1 || num == 1)
	{
		for (int i = 0; i < (num + 1) / 2; i++)
		{
			for (int j = 0; j < num; j++)
			{
				printf("%c", *a);
				/*  printf("%c", a);
					printf("%c", &a);   都是错的*/

			}
			printf("\n");
		}
	}
	else
	{
		printf("ERROR:This is an odd number,we can"
			"not paint a diamond depend on an odd number");
	}
	return 0;
}


void test_goto()
{
	int num;
	printf("请输入一个正整数: ");
	scanf("%d", &num);

	if (num <= 0) {
		printf("输入错误，必须输入一个正整数！\n");
		goto end;
	}
	printf("输入的正整数是: %d\n", num);
end:
	printf("程序结束\n");
	return 0;
}

struct complex_struct
{
	double x;
	double y;
};//the structure initial


struct rational
{
	int up;
	int down;
};

void init_struct()
{


	struct complex_struct z4;//initial some new member after structure initial
	struct complex_struct z5;

	double x = 3.0;
	struct complex_struct z1 = { x, 4.0, }; /* z1.x=3.0, z1.y=4.0 */
	struct complex_struct z2 = { 3.0, 1.786 }; /* z2.x=3.0, z2.y=0.0 */
	struct complex_struct z3 = { 0 }; /* z3.x=0.0, z3.y=0.0 */
	//z4 = { 0 };   /* z3.x=0.0, z3.y=0.0 */   /* It's wrong */
	z4.x = 0;
	z4.y = 0;
	z5 = z4;

	//printf("%f\n%f\n%f\n%f\n", z1.x, z2.x, z3.x, z4.x);
	//printf("%f\n%f\n%f\n%f\n", z1.y, z2.y, z3.y, z4.y);



}

void print_complex(struct complex_struct z)
{
	printf("%f", z.x);
	if (z.y != 0)
	{
		printf("+");
		printf("%fi", z.y);
	}
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	z1.x = z1.x + z2.x;
	z1.y = z1.y + z2.y;
	return z1;
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
	z1.x = z1.x - z2.x;
	z1.y = z1.y - z2.y;
	return z1;
}


struct rational make_rational(int up, int down)
{
	struct rational fraction;
	fraction.up = up;
	fraction.down = down;
	return fraction;
}

struct rational add_rational(struct rational fraction1, struct rational fraction2)
{
	struct rational fraction;
	fraction.up = fraction1.up * fraction2.down + fraction2.up * fraction1.down;
	fraction.down = fraction1.down * fraction2.down;
	return fraction;
}


struct rational sub_rational(struct rational fraction1, struct rational fraction2)
{
	struct rational fraction;
	fraction.up = fraction1.up * fraction2.down - fraction2.up * fraction1.down;
	fraction.down = fraction1.down * fraction2.down;
	return fraction;
}

struct rational mul_rational(struct rational fraction1, struct rational fraction2)
{
	struct rational fraction;
	fraction.up = fraction1.up * fraction2.up;
	fraction.down = fraction1.down * fraction2.down;
	return fraction;
}

struct rational div_rational(struct rational fraction1, struct rational fraction2)
{
	struct rational fraction;
	fraction.up = fraction1.up * fraction2.down;
	fraction.down = fraction1.down * fraction2.up;
	return fraction;
}


void print_rational(struct rational fraction)
{

	if (fraction.down == 0)
	{
		printf("ERROR:The denominator can't be 0\n");
		return 0;
	}
	else
	{
		struct rational simplify_fraction = { fraction.up / find_GCD(fraction.up, fraction.down),
		fraction.down / find_GCD(fraction.up, fraction.down) };
		if (fraction.up == 0)
		{
			printf("%d\n", 0);
		}
		else if (simplify_fraction.down == 1)
		{
			printf("%d\n", fraction.up / find_GCD(fraction.up, fraction.down));
		}
		else if (simplify_fraction.down == -1)
		{
			printf("%d\n", -fraction.up / find_GCD(fraction.up, fraction.down));
		}
		else if (simplify_fraction.down < 0)
		{
			printf("%d/%d\n", -simplify_fraction.up, -simplify_fraction.down);
		}
		else
		{
			printf("%d/%d\n", simplify_fraction.up, simplify_fraction.down);
		}
	}


}

void group_trans_AtoB()
{
	int a;
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int B[10];
	for (int i = 0; i < (sizeof(A))/sizeof(a); i++)
	{
		B[i] = A[i];
		printf("%d ", B[i]);
	}
	printf("\n");
	
}

void str_init()
{
	char str[11] = "hello,world";
	//printf("%zu\n", sizeof(str));
	printf("%s\n", str);
}

void diff_and(unsigned int num1)
{
	printf("%#b\n", num1 + 0b1011);
}


int nmax(double arr[], int n)
{

	int i = 0, MAX = 0, l = 0;
	for (i = 1; i < n; i++)
	{
		if (arr[i] > MAX)
		{
			MAX = arr[i];
			l = i;
		}
	}
	return l;
}
int main()
{
	double Ts = 0.1;            //采样周期
	double Fs = 1 / Ts;           //采样频率
	double T = 8.0;             //信号周期
	double f = 1 / T;             //信号频率
	int n = 6;                  //2的n次方
	int N = 64;           //采样点数
	double F = Fs / N;            //频率分辨率

	double pr[256], pi[256], fr[256], fi[256], t[256];
	for (int i = 0; i < N; i++)
	{
		pr[i] = cos(2 * PI * f * i * Ts);
		pi[i] = 0;
		//printf("%lf\n",pr[i]);
	}




	printf("1\n");
	kfft(pr, pi, 64, n, fr, fi);  //调用FFT函数
	printf("1\n");
	int nMax = N - nmax(pr, N);
	double freq = nMax * F;
	printf("%d,%lf\n", nMax, freq);
	for (int i = 0; i < N; i++)
	{
	    //printf("%lf\n",pr[i]); //输出结果

	}
}