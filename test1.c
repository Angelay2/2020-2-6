#include <stdio.h>
#include <Windows.h>
#include <malloc.h>

#pragma warning(disable: 4996)
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
	p[0] = 'A';
	free(p);
	p[0] = 'A';// ���� �Ƿ��޸� ����ϵͳ��������쳣�޸�

	printf("after: %p\n", p); // ǰ���ֵַһ�� �ڶ��Ͽ��ٵĿռ���p�ﱣ��
	// ���岻һ�� free�Ͽ�pָ����Ŀ���ڴ�֮��Ĺ�ϵ(����) �ͷŵ������ߵĹ�ϵ
	// �Ƿ�ָ�����Ұָ��(�Ƿ����) ����������
	// ��û��������� ֻ�ǶϿ���ϵ p������ݻ��� ��ָ��֮ǰ�ĵ�ַ
	// �հѶѿռ�һ�ͷ� ���ܾͻᱻ�����õ�

	system("pause");
	return 0;
}

// ����ռ䲻�ͷ�
// �ᵼ�¿�����Դ���Խ��Խ�� => ���������ڴ�й© => ��(��ѭ�� malloc)
// �����˳� �ڴ�й©������Ȼ��ʧ => �ص��Ͳ�������ڴ�й© => ɱ����������ڴ�й©

// 
int main(){
	// ����1
	int num = 0;
	scanf("%d", &num);
	int arr[num] = { 0 };// ���� ���ܱ䳤
	// ����2
	int* ptr = NULL;
	ptr = (int*)malloc(num*sizeof(int));
	if (NULL == ptr){// �ж�ptrָ���Ƿ�Ϊ��
		int i = 0;
		for (i = 0; i < num; i++){
			*(ptr + i) = 0;
		}
	}
	free(ptr);// �ͷ�֮��ptr���ڴ治�� ����ָ�� ָ��֮ǰ�Ŀռ� ����ΪҰָ��
	ptr = NULL;// �б�Ҫ��Ϊ��

	system("pause");
	return 0;
}










