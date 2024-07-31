#include <stdio.h>
#include <stdlib.h>
/*
13 向子强 //链表实现栈
*/
typedef struct arr{
	int data;
	struct arr *p;
}Node,*node;
node init(node a){//初始化
	a=NULL;
	return a;
}
int boolun(node p){//判断空栈
	return p==NULL;
}
node push(node a,int val){//入栈
	node p=(node)malloc(sizeof(Node));
	p->data=val;
	p->p=a;
	a=p;
	return a;
}
node fori(node a){//反复入栈
	int val;
	printf("请输入你要输入的数据，999结束");
	scanf("%d",&val);
	while(val!=999){
		a=push(a,val);
		printf("请输入你要输入的数据，999结束");
		scanf("%d",&val);
	}
	printf("\n");
	return a;
}
node foro(node p){//输出栈的所有元素
	if(boolun(p)){
		printf("空栈已结束\n");
		return p;
	}else{
		while(p){
			printf("%d    ",p->data);
			p=p->p;
		}
		printf("输出完毕，一结束\n");
		return p;
	}
}
node erro(node a){
	printf("你输入了个啥");
	return NULL;
}
node pop(node p){//删栈顶
	node a=p;
	p=p->p;
	free(a);
	return p;
}
node pushi(node p){//输出栈顶
	printf("栈顶为%d",p->data);
	return p;
}
int main(){
	node a=(node)malloc(sizeof(node));
	int n;
	printf("请输入你要的功能序号\n1.初始化\n2.输入一组数据\n3.有损输出数据\n4.删除顶栈\n5.输出顶栈\n0.退出\n请开始吧:");
	scanf("%d",&n);
	while(n!=0){
		a=n==1?init(a):n==2?fori(a):n==3?foro(a):n==4?pop(a):n==5?pushi(a):erro(a);
		printf("请输入你要的功能序号\n1.初始化\n2.输入一组数据\n3.有损输出数据\n4.删除顶栈\n5.输出顶栈\n0.退出\n请开始吧\n");
		scanf("%d",&n);
	}
	return 0;
}
