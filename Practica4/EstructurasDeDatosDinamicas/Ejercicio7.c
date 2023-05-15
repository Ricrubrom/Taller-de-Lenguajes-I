#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int num;
  struct Node *next;
}Node;

typedef Node *List;

List initList();
void freeList(List *l);
void addStart(List *l, int n);
void addEnd(List *l, int n);
int getSize(List l);
void toString(List l);

int main()
{
  List l1 = initList();
  int n = 1;
  while (n!=0){
    printf("Inserte un numero: ");
    scanf("%d", &n);
    if (n!=0)
      addEnd(&l1, n);
  }
  List l2 = initList();
  List aux= l1;
  while (aux!=NULL){
    addStart(&l2, aux->num);
    aux = aux->next;
  }
  printf("Size: %d\n", getSize(l1));
  toString(l1);
  printf("\n\nSize: %d\n", getSize(l2));
  toString(l2);
  freeList(&l1);
  freeList(&l2);
  return 0;
}


List initList(){
  List aux = (List)malloc(sizeof(Node));
  aux->next = NULL;
  return aux;
}

void freeList(List *l){
  List aux;
  while(*l!=NULL){
    aux = *l;
    *l = (*l)->next;
    free(aux);
  }
}

void addStart(List *l, int n){
  if ((*l)->num==0){
    (*l)->num = n;
    return;
  }
  List aux = (List)malloc(sizeof(Node));
  aux->num = n;
  aux->next = *l;
  *l = aux;
}

void addEnd(List *l, int n){
  if ((*l)->num==0){
    (*l)->num = n;
    return;
  }
  List aux = (List)malloc(sizeof(Node));
  aux->num = n;
  aux->next = NULL;
  if (*l!=NULL){
    List act = *l;
    while (act->next!=NULL){
      act = act->next;
    }
    act->next = aux;
  }
  else
    *l = aux;
}

int getSize(List l){
  int size=1;
  if (l!=NULL){
    while (l->next!=NULL){
      l = l->next;
      size++;
    }
  }
  else
    return 0;
  return size;
}

void toString(List l){
  if (l!=NULL){
    printf("%d", l->num);
    while (l->next!=NULL){
      l = l->next;
      printf(", %d", l->num);
    }
  }
  else
    printf("Lista Vacia");
}