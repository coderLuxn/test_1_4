#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//预处理
// 
//预定义符号
//int main()
//{
//	FILE* pf = fopen("log.txt", "w");
//	//printf("%s\n", __TIME__);
//	fprintf(pf,"file:%s date:%s time:%s", __FILE__, __DATE__, __TIME__);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//(1) #define 定义标识符
//(2) #define 定义宏
//#define SQUARE(X) (X)*(X)
//int main()
//{
//	int a = 10;
//	printf("%d ",SQUARE(a));
//	return 0;
//}

//#和##
//# "#X"->""a""
//#define PRINT(X) printf("the value of "#X" is %d\n",X )
//                       //the value of ""a"" is 10
//int main()
//{
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}

//## 连接的作用
//#define CAT(X,Y) X##Y
//        //CAT(Class2023)
//int main()
//{
//	int Class20 = 2023;
//	printf("%d ",CAT(Class,20));
//	return 0;
//}

//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int max = MAX(a++, b++);
//	max = ((a++) > (b++) ? (a++) : (b++));
////a先使用10 a=11 b先使用 b=12  a先使用11 a=12 b先使用12 b=13 
//	printf("%d\n", max);
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}

//函数和宏
//#define MAX1(X,Y) ((X)>(Y)?(X):(Y))
//
//int MAX2(int X, int Y)
//{
//	return (X > Y ? X : Y);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	float c = 3.0f;
//	float d = 4.0f;
//	int max = MAX1(c, d);
//	// max = MAX2(a, b);
//	// printf("%d\n", max);
//	// printf("%d\n", max);
//	max = MAX2(c,d);
//	printf("%d\n", max);
//	printf("%d\n", max);
//	return 0;
//}

//undef 移除宏定义
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 20;
//#undef MAX
//	int max = MAX(a, b);
//	printf("%d ", max);
//	return 0;
//}

//宏的参数可以出现类型，但是函数不可以
//#define SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);
//	printf("%d ", ret);
//	return 0;
//}

//用宏开辟空间
//#include <stdlib.h> 
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	//开辟一个空间
//	int* p = malloc(10 * sizeof(int));
//	int* p = MALLOC(20, int);
////  int* p = malloc(10 * sizeof(int));
//	return 0;
//}

//条件编译 
// 1.ifdef 表达式
//   endif
// 
//#define DEBUG
//int main()
//{
//	int arr[10] = { 1,12,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = 0;
//#ifdef DEBUG //如果定义就打印, 如果没有定义就不打印
//		printf("%d ", arr[i]);
//#endif
//	}
//	return 0;
//}

// if 表达式(1 0)
//  endif
// 
//int main()
//{
//	int arr[10] = { 1,12,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = 0;
//#if 0
//		printf("%d ", arr[i]);
//#endif
//	}
//	return 0;
//}

//2.多分支的条件编译
//  #if 表达式
//  #elif 表达式
//  #else 
//  #endif
// 
//int main()
//{
//#if 0==1
//     printf("hahaha" );
//#elif 2==2
//	printf("hehe");
//#else
//	printf("heiihei");
//#endif
//	return 0;
//}

//3.判断是否被定义
//#if defined ()  反面//#if !defined ()
//#ifdef              //#ifndef 

//#define DEBUG
//int main()
//{
////#if defined (DEBUG)//如果定义DEBUG就执行
////	printf("hehe");
////#endif
//
//#ifdef DEBUG
//	printf("hehe");
//#endif
//	return 0;
//}

//#define DEBUG
//int main()
//{
////#if !defined (DEBUG)//如果没有定义DEBUG就执行
////	printf("hehe");
////#endif
//#ifndef DEBUG
//	printf("hehhe");
//#endif
//	return 0;
//}

//4.嵌套指令
//#if defined()
//   #ifdef
//   #endif
//#elif defined()
//   #ifdef
//   #endif
//#endif

//文件包含
#include <stdio.h> //库文件包含
//#include "add.h" //本地头文件
//int main()
//{
//	int a = 10, b = 20;
//	int ret = add(a, b);
//	printf("%d", ret);
//	return 0;
//}

//用宏计算偏移量
#include <stddef.h>
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//
//#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
//int main()
//{
//	//printf("%d\n", offsetof(struct S, c1));
//	//printf("%d\n", offsetof(struct S, a));
//	//printf("%d\n", offsetof(struct S, c2));
//	printf("%d\n", OFFSETOF(struct S, c1));
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, c2));
//	return 0;
//}