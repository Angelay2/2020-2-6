#include <stdio.h>
#include <Windows.h>
#include <malloc.h>

#pragma warning(disable: 4996)
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
	p[0] = 'A';
	free(p);
	p[0] = 'A';// 崩掉 非法修改 操作系统发现这个异常修改

	printf("after: %p\n", p); // 前后地址值一样 在堆上开辟的空间在p里保存
	// 意义不一样 free断开p指针与目标内存之间的关系(分手) 释放的是两者的关系
	// 非法指向就是野指针(非法惦记) 访问无意义
	// 并没有清除数据 只是断开关系 p里的内容还在 还指向之前的地址
	// 刚把堆空间一释放 可能就会被别人用掉

	system("pause");
	return 0;
}

// 申请空间不释放
// 会导致可用资源变得越来越少 => 进而导致内存泄漏 => 卡(死循环 malloc)
// 程序退出 内存泄漏问题自然消失 => 关掉就不会存在内存泄漏 => 杀毒软件存在内存泄漏

// 
int main(){
	// 代码1
	int num = 0;
	scanf("%d", &num);
	int arr[num] = { 0 };// 不对 不能变长
	// 代码2
	int* ptr = NULL;
	ptr = (int*)malloc(num*sizeof(int));
	if (NULL == ptr){// 判断ptr指针是否为空
		int i = 0;
		for (i = 0; i < num; i++){
			*(ptr + i) = 0;
		}
	}
	free(ptr);// 释放之后ptr里内存不变 还是指针 指向之前的空间 但是为野指针
	ptr = NULL;// 有必要置为空

	system("pause");
	return 0;
}










