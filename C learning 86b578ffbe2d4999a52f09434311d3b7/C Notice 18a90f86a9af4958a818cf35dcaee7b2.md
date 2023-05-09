# C Notice

## `#include`必须独占一行

在C语言中，#include指令用于将头文件包含到源代码中。这个指令必须独占一行，因为C语言编译器是按行处理源代码的。如果#include指令与其他代码放在同一行，编译器可能会将其解释为另一种指令或语句，导致编译错误或意外的行为。因此，为了确保编译器正确解释#include指令，它必须独占一行。除了#include指令外，其他语句可以与其他代码放在同一行或多行。这是因为C语言编译器在处理代码时，会根据语法规则将代码分解成不同的标记和语句，不受行数的限制。对于#include指令，编译器必须确保它独占一行，以便正确解释头文件的包含。

## 表达式`a = b = c`是合法的,而表达式`(a=b)=c`是不合法的

等号左边的表达式要求表示一个**存储位置**而不是一个值，这是等号运算符和+ - * /运算符的又一个显著不同。有的表达式既可以表示一个存储位置也可以表示一个值，而有的表达式只能表示值，不能表示存储位置，例如`minute + 1`这个表达式就不能表示存储位置，放在等号左边是语义错误。表达式所表示的存储位置称为左值（lvalue）（允许放在等号左边），而以前我们所说的表达式的值也称为右值（rvalue）如果定义三个变量`int a, b, c;`，表达式`a = b = c`是合法的，先求`b = c`的值，再把这个值赋给`a`，而表达式`(a = b) = c`是不合法的，先求`(a = b)`的值没问题，但`(a = b)`这个表达式不能再做左值了，因此放在`= c`的等号左边是错的。

## 定义变量时可以把相同类型的变量列在一起，而定义参数却不可以，例如下面这样的定义是错的：

```c
void print_time(int hour, ~~minute~~)    //错误定义 
{
	printf("%d:%d\n", hour, minute);
}

//正确应该是：
void print_time(int hour, int minute)
{
	printf("%d:%d\n", hour, minute);
}
```

## 局部变量在不同函数下用相同的变量名定义变量是允许的，他们处在不同的物理空间中：

```c
//局部变量的例子
#include <stdio.h>
void print_time(int hour, int minute)
{
	printf("%d:%d\n", hour, minute);
}
int main(void)
{
	int hour = 23, minute = 59;
	print_time(hour, minute);
	return 0;
}
/*---------------------------------------------------------*/
//全局变量的例子
#include <stdio.h>
int hour = 23, minute = 59;
void print_time(void)
{
	printf("%d:%d in print_time\n", hour, minute);
}
int main(void)
{
	print_time();
	printf("%d:%d in main\n", hour, minute);
	return 0;
}
```

与全局变量不同，局部变量在每次函数调用时分配存储空间，在每次函数返回时释放存储空间，例如调用`print_time(23, 59)`时分配`hour`和`minute`两个变量的存储空间，在里面分别存上23和59，函数返回时释放它们的存储空间，下次再调用`print_time(12, 20)`时又分配`hour`和`minute`的存储空间，在里面分别存上12和20。全局变量定义在所有的函数体之外，它们在程序开始运行时分配存储空间，在程序结束时释放存储空间，在任何函数中都可以访问全局变量

## 全局变量不初始化初值为0，局部变量不初始化初值为不确定

## 语句块内可以定义局部变量

## C语言规定`%`运算符的两个操作数必须是整型的，**`%`运算符的结果总是与被除数同号**

## 在`switch`语句中：`case`后面跟表达式的必须是常量表达式；浮点型不适合做精确比较，所以C语言规定`case`后面跟的必须是整型常量表达式。

```c
/*将switch传入参数里修改成float型的变量编译时候的报错*/
void test(int num)
{
	int a, b;
	a = 1, b = 2;
	switch (num)
	{
	case 1:
		printf("1");
	case 2:
		printf("2");
	~~case a+b:~~
		printf("3");
	}
}
/*尝试编译程序后的报错内容*/
main.c: In function 'test':
main.c:13:2: error: case label does not reduce to an integer constant
  case a+b:

/*---------------------------------------------------------*/
/*将switch传入参数里修改成float型的变量编译时候的报错*/
void test(~~float~~ num)
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
}
/*尝试编译程序后的报错内容*/
>
main.c: In function 'test':
main.c:5:10: error: switch quantity not an integer
  switch (num)
```

## 在一个有返回值的函数里面若未执行到确切的`return`语句，它的返回值将是随机的。

```c
/*这是一个求绝对值的函数*/
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
}

int main()
{
	printf("%d", absolute_value(0));
	return 0;
}
/*运行程序后的内容*/
>
1
```

这个函数被定义为返回`int`类型的数，就应该在任何情况下都返回`int`，但是上面这个程序在`x==0`时安静地退出函数，什么也不返回，C语言对于这种情况会返回什么结果是未定义的，这个结果是随机的，在程序有所改动后输出的结果会不一样

## 在一个有返回值的函数里面若未执行到确切的`return`语句，在利用gcc编译器进行编译时可以加上-Wall让编译器对不正常的没有返回值的函数进行报警告

```c
>
gcc -Wall main.c
/*尝试编译程序后的警告内容*/
main.c: In function 'absolute_value':
main.c:26:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
```

## 在C语言中如果函数内出现递归调用，则不可以将函数名和函数内的变量命名为同一个，会导致编译报错

```c
int repeat(int num)
{
	int repeat=0;
	repeat = repeat(1);
	return repeat;
}
/*尝试编译程序后的报错内容*/
>
main.c: In function 'repeat':
main.c:74:11: error: called object 'repeat' is not a function or function pointer
  repeat = repeat(1);

//上面程序是个死循环，但是只是举例说明，如果出现了递归调用，不可将变量名与函数名重复。
```

## `for`语句执行的顺序

```c
for(int i;)
```

## `sizeof()`函数可以用来计算数组的长度，所计算的单位为字节，是占用内存的长度

```c
int a;
printf("the sizeof int is %d byte",sizeof(a));

/*运行程序后的内容*/
>
the sizeof int is 4 bytesh
```

## 在对字符串进行初始化的时候，注意纳入`\0`字符

```c
/*尝试错误定义字符串长度*/
char str[11] = "hello,world";
printf("%s\n", str);

/*用gcc编译器编译程序，运行程序后的内容*/
>
hello,world

/*用Visual Studio编译器编译程序，运行程序后的内容*/
>
hello,world烫烫烫烫烫烫烫烫烫烫烫烫烫烫?
```

不难发现在使用vs的集成开发环境编译运行后，字符串出现了乱码。这是因为字符串`”hello,world”`的长度刚刚好为`11`，而如果以字符串作为右值去初始化字符型数组，要在其后面加入结束符`\0`，否则使用`printf("%s")`去打印字符串的时候函数无法找到结束符，会造成**越界**。但是使用gcc编译器的时候却没有出现这个问题，所以也体现了不同的编译器对同一段代码的处理也会有所不同。