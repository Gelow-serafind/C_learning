# 《Linux C编程一站式学习》-练习

## 1.1.1解释执行的语言相比编译执行的语言有什么优缺点？

程序由语句或指令组成，计算机只能执行低级语言中的指令（汇编语言的指令要先转成机器码才能执行），高级语言要执行就必须先翻译成低级语言，翻译的方法有两种－－编译和解释，虽然有这样的不便，但高级语言有一个好处是平台无关性。什么是平台？一种平台，就是一种体系结构，就是一种指令集，就是一种机器语言，这些都可看作是一一对应的，上文并没有用“一一对应”这个词，但读者应该能推理出这个结论，而高级语言和它们不是一一对应的，因此高级语言是平台无关的，概念之间像这样的数量对应关系尤其重要。那么编译和解释的过程有哪些不同？主要的不同在于什么时候翻译和什么时候执行。
现在回答这个思考题，根据编译和解释的不同原理，你能否在执行效率和平台无关性等方面做一下比较？

## 1.2.1请读者用`printf`语句试试这几个控制字符的作用。

![Untitled](%E3%80%8ALinux%20C%E7%BC%96%E7%A8%8B%E4%B8%80%E7%AB%99%E5%BC%8F%E5%AD%A6%E4%B9%A0%E3%80%8B-%E7%BB%83%E4%B9%A0%2088f2e28aa93f4c1cb6fd5dd0459ba226/Untitled.png)

```c
/*  */
```

## 1.2.2 总结前面介绍的转义序列的规律，想想在`printf`的格式化字符串中怎么表示一个%字符？写个小程序试验一下。

```c
/*使用"%%"符号就可以打出%字符*/
#include <stdio.h>
int main()
{
	printf("%%");
	return 0;
}
/*---------------------结果-------------------*/

%
```

## 1.2.5假设变量x和n是两个正整数，我们知道x/n这个表达式的结果要取Floor，例如x是17，n是4，则结果是4。如果希望结果取Ceiling应该怎么写表达式呢？例如x是17，n是4，则结果是5；x是16，n是4，则结果是4。

```c
/**/
#include <stdio.h>
#include <math.h>
int main()
{
	float x, n,result;
	x = 17, n = 4;
	result = floor(x / n);
	printf("%f\n",result);
	result = ceil(x / n);
	printf("%f\n", result);
	return 0;
}
/*---------------------结果-------------------*/

4.000000
5.000000
```

## 1.3.3如果在一个程序中调用了`printf`函数却不包含头文件，例如`int main(void) { printf("\n"); }`编译时会报警告：`warning: incompatible implicit declaration of built-in function ‘printf’`。请分析错误原因。

在C语言中，当我们调用一个函数时，编译器需要知道该函数的返回值类型以及参数类型和数量等信息。如果我们没有包含该函数的头文件，编译器就无法确定这些信息，只能根据默认规则来猜测。如果编译器猜测的函数原型与实际函数原型不一致，就会导致编译错误或警告。在本例中，我们调用了printf函数，但是没有包含stdio.h头文件，所以编译器无法确定printf函数的原型。根据默认规则，编译器会假定printf函数的返回值类型为int，参数类型和数量也不确定。然而，实际上printf函数的返回值类型为int，参数类型和数量也是确定的。因此，编译器会发出警告，提示我们可能存在错误。为了避免这种警告，我们应该在程序中包含所调用函数的头文件。在C语言中，如果没有包含函数的头文件，编译器会根据默认规则来猜测该函数的原型。如果猜测的原型与实际函数原型不一致，编译器会发出警告，但是仍然会生成可执行文件。如果在程序中调用了这个函数，可能会导致运行时错误。所以即使没有包含头文件，编译器仍然可以编译通过，但是会发出警告，提示我们可能存在问题。因此，我们应该始终包含所调用函数的头文件，以确保程序的正确性和可移植性。

```c
~~#include <stdio.h>~~

int main()
{
	printf("test");
	return 0;
}

/*尝试编译后的报错内容*/
>
main.c: In function 'main':
main.c:4:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
  printf("test");
  ^~~~~~
main.c:4:2: warning: incompatible implicit declaration of built-in function 'printf'
main.c:4:2: note: include '<stdio.h>' or provide a declaration of 'printf'

/*尝试运行程序后的内容*/
>
test

/*这段程序可以编译通过，但是不推荐这样做，因为在没有包含头文件的情况下，编译器无法识别printf函数，会导致编译警告或错误。正确的做法是在程序开头包含头文件#include <stdio.h>，以确保编译器能够识别printf函数。运行可以成功是因为在编译时，编译器会默认使用一些标准库函数，包括printf函数。虽然没有包含头文件，但是编译器会在编译过程中自动搜索标准库函数并将其链接到程序中，因此程序可以正常运行。但是这种写法不可靠，因为不同的编译器可能会有不同的行为，而且在复杂的程序中，可能会出现未定义的行为或错误。因此，在编写程序时，应该始终包含所需的头文件，以确保程序的正确性和可靠性。*/
```

## 1.4.2(1)写两个表达式，分别取整型变量`x`的个位和十位。

```c
/**/
int find_dec(int num)
{
	int dec;
	dec = (num - (num % 10)) / 10;
	return dec;
}
int find_byte(int num)
{
	int byte;
	byte = num % 10;
	return byte;
}
```

## 1.4.2(2)写一个函数，参数是整型变量`x`，功能是打印`x`的个位和十位。

```c
/**/
int print_dec_and_byte(int num)
{
	printf("the dec of this num is %d\n",find_dec(num));
	printf("the byte of this num is %d\n",find_byte(num));
}
```

## 1.5.1(1)编写一个布尔函数`int is_leap_year(int year)`，判断参数`year`是不是闰年。如果某年份能被4整除，但不能被100整除，那么这一年就是闰年，此外，能被400整除的年份也是闰年。

```c
/**/
int if_leap_year(int num)
{
	if ((num % 4 == 0) && (num % 100 != 0))
	{
		return 1;
	}
	else if (num % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
```

## 1.5.1(2)编写一个函数`double myround(double x)`，输入一个小数，将它四舍五入。例如`myround(-3.51)`的值是-4.0，`myround(4.49)`的值是4.0。可以调用`math.h`中的库函数`ceil`和`floor`实现这个函数。

```c
/**/
```

## 1.5.3(1)编写递归函数求两个正整数`a`和`b`的最大公约数（GCD，Greatest Common Divisor），使用Euclid算法：如果`a`除以`b`能整除，则最大公约数是`b`；否则，最大公约数等于`b`和`a%b`的最大公约数。

```c
int find_GCD(int a , int b)
{
	int GCD;
	if (a % b == 0)
	{
		GCD = b;
	}
	else
	{
		GCD = find_GCD(b, a % b);
	}
	return GCD;
}
```

## 1.5.3(2)编写递归函数求Fibonacci数列的第`n`项，这个数列是这样定义的：`fib(0)=1`；`fib(1)=1`；`fib(n)=fib(n-1)+fib(n-2)`

```c
int find_fibonacci(int num)
{
	int fibonacci;

	if (num == 1 || num == 0)
	{
		fibonacci = 1;
	}
	else
	{
		fibonacci = find_fibonacci(num - 1) + find_fibonacci(num - 2);
	}
	return fibonacci;
}
```

## 1.6.4(1)求素数这个程序只是为了说明`break`和`continue`的用法才这么写的，其实完全可以不用`break`和`continue`，请读者修改一下控制流程，去掉`break`和`continue`而保持功能不变。

```c
//例子：
#include <stdio.h>

int is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			break;
	if (i == n)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i;
	for (i = 1; i <= 100; i++) {
		if (!is_prime(i))
			continue;
		printf("%d\n", i);
	}
	return 0;
}
```

```c
/**/
```

## 1.6.4(2)上一节讲过怎样把`for`循环改写成等价的`while`循环，但也提到如果循环体中有`continue`语句这两种形式就不等价了，想一想为什么不等价了？

```c
/**/
```

## 1.6.5(1)打印小九九

```c
void paint_ninenine()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if(i>=j)
			printf("%d\t",i*j);
		}
		printf("\n");
	}
}
```

## 1.6.5(2)编写函数`diamond`打印一个菱形。如果调用`diamond(3, '*')`则打印：

![Untitled](%E3%80%8ALinux%20C%E7%BC%96%E7%A8%8B%E4%B8%80%E7%AB%99%E5%BC%8F%E5%AD%A6%E4%B9%A0%E3%80%8B-%E7%BB%83%E4%B9%A0%2088f2e28aa93f4c1cb6fd5dd0459ba226/Untitled%201.png)

```c

```

## 1.6.5(3)如果调用`diamond(5, '+')`则打印：

![Untitled](%E3%80%8ALinux%20C%E7%BC%96%E7%A8%8B%E4%B8%80%E7%AB%99%E5%BC%8F%E5%AD%A6%E4%B9%A0%E3%80%8B-%E7%BB%83%E4%B9%A0%2088f2e28aa93f4c1cb6fd5dd0459ba226/Untitled%202.png)

```c

```

## 1.7.2在本节的基础上实现一个打印复数的函数，打印的格式是x+yi，如果实部或虚部为0则省略，例如：`1.0`、`-2.0i`、`-1.0+2.0i`、`1.0-2.0i`。最后编写一个`main`函数测试本节的所有代码。想一想这个打印函数应该属于上图中的哪一层？

```c
void print_complex(struct complex_struct z)
{
	printf("%f", z.x);
	if (z.y != 0)
	{
		printf("+");
		printf("%fi", z.y);
	}
}
```

## 1.7.2(2)实现一个用分子分母的格式来表示有理数的结构体`rational`以及相关的函数，`rational`结构体之间可以做加减乘除运算，运算的结果仍然是`rational`。测试代码如下：

```c
/*--------示例代码----------*/

int main(void)
{
	struct rational a = make_rational(1, 8); /* a=1/8 */
	struct rational b = make_rational(-1, 8); /* b=-1/8 */
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));

	return 0;
}

/*--------示例代码----------*/

int find_GCD(int a , int b)
{
	int GCD;
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
```