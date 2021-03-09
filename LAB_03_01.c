#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    int key;
    struct nod* next;
}NodeT;


NodeT *new_node(int key){
    NodeT *p = malloc(sizeof (NodeT));
    p->next = NULL;
    p->key = key;
    return p;
}

void push(NodeT **head,int key){
    NodeT *p = new_node(key);
    if(*head==NULL){
        *head = p;
    }
    else{
        p->next=*head;
        *head=p;
    }
}

void print(NodeT *head){
    printf("Stiva este [ ");
    for(NodeT *p=head;p!=NULL;p=p->next){
        printf("%d ",p->key);
    }
    printf("]\n");
}

int pop(NodeT** head){
    if(*head!=NULL){
        int key = (*head)->key;
        NodeT *temp = (*head)->next;
        free(*head);
        *head = temp;
        return key;
    }
    return 0;
}

int main() {
    NodeT* first=NULL;
    push(&first,5);
    push(&first,6);
    push(&first,7);
    push(&first,8);
    print(first);
    printf("%d ",pop(&first));
    printf("%d ",pop(&first));
    printf("%d ",pop(&first));
    printf("%d ",pop(&first));
    printf("%d ",pop(&first));
    printf("%d ",pop(&first));
    return 0;
}
