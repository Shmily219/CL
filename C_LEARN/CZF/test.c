//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //ios功能库
#include <string.h> //提供strlen功能函数

/*
算数操作符
加	减	乘	除	取模
+	-	*	/	%

移位操作符
左移	右移
<<		>>

位操作符

&	^	|

*/

//static修饰的变量会被放入静态栈，在其定义时所处的“局部区域”运行结束时不会被自动销毁，会继续留在栈中以方便后续处理
//不用Static修饰的变量会被放入静态区，“局部区域”运行结束后会自动销毁
//简而言之，static静态变量只对未被定义的变量进行赋值，只要该变量有定义，则不做处理。
//默认的变量是具有外部属性的，其他源文件可以通过extern函数来引用该变量，但是static可以将该外部属性修改为内部属性，其他源文件无法引用。
void TE(){
	static int a = 0;
	a++;
	printf("%d\n", a);
	//return 0;
}

int main()
{
	//for (int a = 0; a < 10; a++) {
	//	TE();
	//	printf("%d\n",a);
	//}
	int a = 0;
	while (a < 10) {
		TE();
		a++;
	}

	return 0;
}