#include <stdio.h>
#include <stdlib.h>
struct S1{
    int num;
    double d;
    int arr[];//柔性数组成员
};
struct S2{
    int num;
    double d;
    int arr[0];//柔性数组成员，0并非代表0个元素，而是指未知大小
};
struct S3{
    int num; // 4
    int arr[];//柔性数组成员
};
//结构中的柔性数组成员前面必须至少一个其他成员
//sizeof返回的这种结构大小不包括柔性数组的内存
//包含柔性数组成员的结构用malloc(函数)进行内存的动态分配，并且分配的内存应该大于结构 的大小，以适应柔性数组的预期大小。
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
        //未初始化部分打印出来是随机值
        printf("%d", ps->arr[i]);
    }
    //扩容
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
