# C knowledge

# 指针(point)

每一个变量都有一个内存位置，每一个内存位置都定义了可使用 ”**&”**运算符访问的地址，它表示了在内存中的一个地址。

### 数据类型的意义(The meaning of this data types)

每个变量都存在与内存的某一个位置，即为地址，当然指针也有地址。不仅如此，指针变量与别的变量不一样的地方在于，指针变量是带有指向性的，它的内容是指向内存中的某一个地址。

![Untitled](C%20knowledge%20c4ddcde8e4514ec5ac681f08e43d4852/Untitled.png)

### 初始化方法(The method of initial)

```c
//type *var_name;
//例如：
int *p;
double *p;
...
p = NULL; /*这句很有必要，在指针使用之前必须对它所指向的内存进行确定*/
```

### 实验(experiment)

**1.变量的意义**

```c
#include <stdio.h>
int main()
{
	int  var = 20;   /* 实际变量的声明 */
	int* p;        /* 指针变量的声明 */
	p = &var;  /* 在指针变量中存储 var 的地址 */
	printf("var 变量的地址: %p\n", &var);
	printf("\n");
	printf("p的地址: %p\n", p);
	printf("*p的地址: %p\n", *p);
	printf("p的值: %d\n", p);
	printf("*p的值: %d\n", *p);
	return 0;
}

------运行结果------

 var 变量的地址: 000000980876F524
 p的地址: 000000980876F524
*p的地址: 0000000000000014  //错误的
 p的值: 142013732           //错误的
*p的值: 20
```

从上不难看出：***“只有*p才有值，只有p才有地址”***，其余的两个是无意义的随机数，按道理来说其实是错误的语法。

因为在C语言中，“%d”是输出十进制类型数值的，”%p”是输出指针地址的。

**2.指针的简单使用**

```c
#include <stdio.h>
int main()
{
	char hello[5] = {'h','e','l','l','o'};
	char* p;
	p = &hello[0];//指针的赋值语句
	for (int i = 0; i <= 4; i++)
	{
		printf("%c", *p);
		p++;
	}
	return 0;
}

------运行结果------

hello
```

在指针的一般使用下，令其指向一个内存，便可以利用指针 *间接访问* 变量。在上述例子中，利用指针间接访问了hello[ ]数组中的每个元素，对他们进行了遍历输出。在赋值的时候，使用的是 *将目标变量的地址赋值给指针变量的内容* 的形式，即`p = &hello[0]`。当在间接调用变量的值的时候，调用的则是 *带星号的指针变量* ，即`printf("%c", *p);`

# 指针函数(point function)

# 枚举(enumeration)

# 结构体(structure)

C 数组允许定义可存储相同类型数据项的变量，**结构** 是 C 编程中另一种用户自定义的可用的数据类型，它允许您存储不同类型的数据项。

### 初始化方法(The method of initial)

```c
struct tag { 
    member-list
    member-list 
    member-list  
    ...
} variable-list ;
```

**tag** 是结构体标签。**member-list** 是标准的变量定义，比如 **int i;** 或者 **float f;**，或者其他有效的变量定义。**variable-list** 结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量。

例如：

```c
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;
```

在一般情况下，**tag、member-list、variable-list**这 3 部分至少要出现 2 个。

### 遇到的错误