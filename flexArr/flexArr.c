#include <stdio.h>
#include <stdlib.h>
struct S1{
    int num;
    double d;
    int arr[];//���������Ա
};
struct S2{
    int num;
    double d;
    int arr[0];//���������Ա��0���Ǵ���0��Ԫ�أ�����ָδ֪��С
};
struct S3{
    int num; // 4
    int arr[];//���������Ա
};
//�ṹ�е����������Աǰ���������һ��������Ա
//sizeof���ص����ֽṹ��С����������������ڴ�
//�������������Ա�Ľṹ��malloc(����)�����ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ �Ĵ�С������Ӧ���������Ԥ�ڴ�С��
int main() {
    //printf("%d\n",sizeof (struct S3));
    struct S3* ps = malloc(sizeof(struct S3)+40);
    if(ps == NULL){
        perror("malloc\n");
        return 1;
    }
    ps->num = 100;
    int i = 0;
    for(i = 0; i < 10; i++){
        ps->arr[i] = i;
    }
    for(i = 0; i < 20; i++){
        //δ��ʼ�����ִ�ӡ���������ֵ
        printf("%d", ps->arr[i]);
    }
    //����
    struct S3* ptr = (struct S3*)realloc(ps, sizeof (struct S3)+80);
    if(ptr == NULL){
        perror("realloc\n");
        return 1;
    } else{
        ps = ptr;
    }
    free(ps);
    ps = NULL;
    return 0;
}
//
