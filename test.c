#include <stdio.h>
#include <Windows.h>

// malloc函数
// 计算机删数据不会把原始数据删掉
// 写入操作极有可能写到之前的位置
// 释放空间的本质不是把空间删除(清空) 只是置为无效
// 
int main1(){
	int n = 0;
	printf("Please Enter n: ");
	scanf("%d", &n);

	char* p = (char*)malloc(n*sizeof(char));
	if (NULL == p){
		printf("malloc error!\n");
		return 1;
	}

	scanf("%s", p);
	printf("echo# %s\n", p);

	printf("before: %p\n", p);
	free(p);
	printf("after: %p\n", p); // 前后地址值一样 在堆上开辟的空间在p里保存
	// 意义不一样 free断开p指针与目标内存之间的关系(分手) 释放的是两者的关系
	// 非法指向就是野指针(非法惦记) 访问无意义
	// 并没有清除数据 只是断开关系

	system("pause");
	return 0;
}










