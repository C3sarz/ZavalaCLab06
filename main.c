#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int item;
    struct list *next;
}List;

void nodeDelete(List **nodePtrtoPtr, int data){

    while(nodePtrtoPtr != NULL){
        if((*nodePtrtoPtr)->next != NULL && (*nodePtrtoPtr)->next->item == data){
            if((*nodePtrtoPtr)->next->next == NULL){
                (*nodePtrtoPtr)->next = NULL;
            }
            else (*nodePtrtoPtr)->next = (*nodePtrtoPtr)->next->next;
            return;
        }
        else {*nodePtrtoPtr = (*nodePtrtoPtr)->next;}
    }
}


int main() {
    List *node3 = malloc(sizeof(List));
    node3->item = 3;
    node3->next = NULL;

    List *node2 = malloc(sizeof(List));
    node2->item = 2;
    node2->next = node3;

    List *node1 = malloc(sizeof(List));
    node1->item = 1;
    node1->next = node2;

    int i = 2;

    nodeDelete(&node1,i);

    List * current = node1;
    while(current != NULL){
        printf("%d\n",current->item);
        current = current->next;
    }
return 0;
}