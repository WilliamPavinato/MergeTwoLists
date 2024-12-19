#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {


    //ponteiro de atribuição da lista
    struct ListNode *finalList = (struct ListNode*) malloc(sizeof(struct ListNode));

    //ponteiro auxiliar apontando para a cabeça da lista
    struct ListNode *head = finalList; 

    //inicialização do próx elemento da cabeça como NULL
    finalList->next = NULL; 

    
    //enquanto os ponteiros das listas forem diferentes de NULL, analisa qual lista tem um nodo com valor maior
    while (list1 != NULL && list2 != NULL) {

        //caso o nodo da lista1 for menor ou igual que o da lista2
        if (list1->val <= list2->val) {

            //insere o nodo da lista1 como nodo da lista final
            finalList->next = list1;  

            //atualiza o ponteiro da lista1
            list1 = list1->next;  

        } else {

            //insere o nodo da lista2 como nodo da lista final
            finalList->next = list2;  

            //atualiza o ponteiro da lista2
            list2 = list2->next;  

        }
        
        //atualiza o ponteiro da lista final
        finalList = finalList->next; 
    }


    //caso sobrarem elementos, são inseridos no final da lista
    if (list1 != NULL) {

        finalList->next = list1;

    } else {

        finalList->next = list2;
    }

    //retorna o primeiro elemento real da lista
    return head->next;  

}

struct ListNode* CreateList() {
    return NULL; 
}


void InsertOnEnd(int val, struct ListNode **node) {

    struct ListNode *newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (*node == NULL) {

        *node = newNode;  

    } else {

        struct ListNode *current = *node;

            while (current->next != NULL) {
                current = current->next;  
            }

        current->next = newNode;  

    }
}


void PrintList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode *list1 = CreateList();
    InsertOnEnd(1, &list1);
    InsertOnEnd(2, &list1);
    InsertOnEnd(3, &list1);
    InsertOnEnd(4, &list1);

    struct ListNode *list2 = CreateList();
    InsertOnEnd(1, &list2);
    InsertOnEnd(2, &list2);
    InsertOnEnd(7, &list2);
    InsertOnEnd(8, &list2);

    struct ListNode *finalList = mergeTwoLists(list1, list2);

    PrintList(finalList);

    return 0;
}
