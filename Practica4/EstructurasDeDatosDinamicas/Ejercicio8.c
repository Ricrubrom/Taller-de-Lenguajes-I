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
void removeMultiple(List *l, int n);

int main()
{
  List l = initList();
  int n = 1;
  while (n!=0){
    printf("Inserte un numero: ");
    scanf("%d", &n);
    if (n!=0)
      addEnd(&l, n);
  }
  printf("\n");
  printf("Size: %d\n\n", getSize(l));
  printf("Inserte un numero: ");
  scanf("%d", &n);
  printf("\n");
  toString(l);
  printf("\n");
  removeMultiple(&l, n);
  toString(l);
  freeList(&l);
  return 0;
}

void removeMultiple(List *l, int n){
  if (*l!=NULL){
    List act = *l;
    List ant = *l;
    while ((act->num)%n==0){
      List aux = act;
      ant = act->next;
      act = act->next;
      free(aux);
    }
    ant = act;
    act = act->next;
    while (act!=NULL){
      if ((act->num)%n==0){
        ant->next = act->next;
        free(act);
        act= ant->next;
        continue;
      }
      ant = act;
      act = act->next;
    }
  }
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