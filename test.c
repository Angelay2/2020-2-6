#include <stdio.h>
#include <Windows.h>

// malloc����
// �����ɾ���ݲ����ԭʼ����ɾ��
// д��������п���д��֮ǰ��λ��
// �ͷſռ�ı��ʲ��ǰѿռ�ɾ��(���) ֻ����Ϊ��Ч
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
	printf("after: %p\n", p); // ǰ���ֵַһ�� �ڶ��Ͽ��ٵĿռ���p�ﱣ��
	// ���岻һ�� free�Ͽ�pָ����Ŀ���ڴ�֮��Ĺ�ϵ(����) �ͷŵ������ߵĹ�ϵ
	// �Ƿ�ָ�����Ұָ��(�Ƿ����) ����������
	// ��û��������� ֻ�ǶϿ���ϵ

	system("pause");
	return 0;
}










