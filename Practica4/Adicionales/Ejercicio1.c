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
void addSorted(List *l, int n);

int main()
{
  List l = initList(10);
  addSorted(&l, 1);
  addSorted(&l, 2);
  addSorted(&l, 3);
  addSorted(&l, 4);
  addSorted(&l, 5);
  addSorted(&l, 6);
  addSorted(&l, 7);
  addSorted(&l, 8);
  addSorted(&l, 9);
  printf("Size: %d\n", getSize(l));
  toString(l);
  freeList(&l);
  printf("\n");
  toString(l);
  return 0;
}

List initList(int n)
{
  List aux = (List)malloc(sizeof(Node));
  aux->next = NULL;
  aux->num = n;
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
  List aux = (List)malloc(sizeof(Node));
  aux->num = n;
  aux->next = *l;
  *l = aux;
}

void addEnd(List *l, int n){
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
    l = l->next;
    while (l!=NULL){
      printf(", %d", l->num);
      l = l->next;
    }
  }
  else
    printf("Lista Vacia");
}

void addSorted(List *l, int n){
  List aux = (List)malloc(sizeof(Node));
  aux->num = n;
  List act = *l;
  List ant = act;
  if(act!=NULL){
    while (act!=NULL && act->num<n)
    {
      ant = act;
      act = act->next;
    }
    if (ant==act){
      *l = aux;
    }
    else{
      ant->next = aux;
    }
    aux->next = act;
    return;
  }
  *l = aux;
  return;
}