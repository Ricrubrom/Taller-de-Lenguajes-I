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
  List l = initList();
  addStart(&l, 1);
  addStart(&l, 2);
  addStart(&l, 3);
  addStart(&l, 4);
  addEnd(&l, 5);
  addEnd(&l, 6);
  addEnd(&l, 7);
  addEnd(&l, 8);
  addEnd(&l, 9);
  printf("Size: %d\n", getSize(l));
  toString(l);
  freeList(&l);
  printf("\n");
  toString(l);
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
    while (l->next!=NULL){
      l = l->next;
      printf(", %d", l->num);
    }
  }
  else
    printf("Lista Vacia");
}