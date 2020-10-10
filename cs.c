#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *circle_create(int n);
void count_off(Node *head, int n, int k, int m);

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    Node *head = circle_create(n);
    count_off(head, n, k, m);
    system("pause");
    return 0;
}

Node *circle_create(int n) {
    Node *temp, *new_node, *head;
    int i;

    // 创建第一个链表节点并加数据
    temp = (Node *) malloc(sizeof(Node));
    head = temp;
    head->data = 1;

    // 创建第 2 到第 n 个链表节点并加数据
    for(i = 2; i <= n; i++) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = i;
        temp->next = new_node;
        temp = new_node;
    }

    // 最后一个节点指向头部构成循环链表
    temp->next = head;

    return head;
}
void count_off(Node *head, int n, int k, int m){
    Node *temp;
    Node *temp1;
    temp1 = head;
    for(int i = 1;i < k; i++){
           temp = temp1->next;
            temp1 = temp;
    }
    Node *cur = temp1;
	//结束条件：链表中只剩一个节点
	while (cur->next != cur)
	{
		Node *prev = NULL;
		for (int i = 0; i < m - 1; i++)
		{
			prev = cur;
			cur = cur->next;
		}
        printf("%d",cur->data);
		prev->next = cur->next;
		free(cur);//cur为删除的结点
		cur = prev->next;
	}
	printf("%d",cur->data);
	return ;
}
void count_offs(Node *head, int n, int k, int m) {
    Node *temp;
     Node *temp1;
    temp1 = head;
    for(int i = 1;i < k; i++){
           temp = temp1->next;
            temp1 = temp;
    }
    Node *temp2;
    Node *temp3;
    Node *temp4;
    temp2 = temp1;
    temp3 = temp2;
    while(head->next!=head){
        if(m == 1){
            printf("%d",temp3->data);
            temp3->next = temp3->next->next;
            temp3 = temp3->next;
        }else{
        for(int i = 1;i < m;i++){
            temp3 = temp2;
            temp2 = temp2->next;           
        }
             printf("%d",temp3->next->data);   
             temp3->next = temp3->next->next;
        }
    }
    // for(int i = 1;i < m;i++){
    //     temp3 = temp2;
    //     temp2 = temp2->next;           
    // }
    // printf("%d",temp3->next->data);
        
            
  //  }
    return;
}