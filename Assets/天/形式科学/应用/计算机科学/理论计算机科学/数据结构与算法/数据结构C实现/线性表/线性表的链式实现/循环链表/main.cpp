#include "list.h"
#include <stdio.h>
int main()
{
  MList list;
  init(list);
  if (empty(list) == true) {
    printf("list is empty\n");
  }
  for (int i = 1; i <= 10; ++i) {
    insertAtHead(list, i);
  }
  traverse(list);
  printf("\n");

  int get_e = 0;
  if (false == getElem(list, 11, get_e)) {
    printf("get elem faild\n");
  }
  getElem(list, 4, get_e);
  printf("get elem %d\n", get_e);

  int locate = 0;
  locateElem(list, 3, locate);
  printf("locate is %d\n", locate);

  int pre = 0;
  priorElem(list, 7, pre);
  printf("7 pre elem is %d\n", pre);

  traverse(list);
  printf("\n");

  int next = 0;
  nextElem(list, 7, next);
  printf("7 next elem is %d\n", next);

  if (false == insert(list, 12, 12)) {
    printf("insert faild\n");
  }

  insert(list, 4, 17);
  traverse(list);
  printf("\n");


  if (false == deleteElem(list, 12)) {
    printf("delete faild\n");
  }
  deleteElem(list, 7);
  traverse(list);
  printf("\n");

  insertAtHead(list, 12);
  traverse(list);
  printf("\n");

  insertAtTail(list, 21);
  traverse(list);
  printf("\n");

  MList list2;
  init(list2);
  for (int i = 5; i <= 15; ++i) {
    insertAtTail(list2, i);
  }
  traverse(list2);
  printf("\n");
  MList list3;
  init(list3);
  for (int i = 1; i <= 10; ++i) {
    insertAtTail(list3, i);
  }
  traverse(list3);
  printf("\n");
  int len1 = length(list2);
  int len2 = length(list3);

  for (int i = 1; i < len2; ++i) {
    int e = 0;
    getElem(list3, i, e);
    if (true == hasElem(list2, e)) {
      continue;
    }
    insertAtTail(list2, e);
  }
  traverse(list2);
  printf("\n");
  destroy(list);
  destroy(list2);
  printf("test 2\n");
  MList A;
  init(A);
  insertAtTail(A, 3);
  insertAtTail(A, 5);
  insertAtTail(A, 8);
  insertAtTail(A, 11);
  traverse(A);
  printf("\n");

  MList B;
  init(B);
  insertAtTail(B, 2);
  insertAtTail(B, 6);
  insertAtTail(B, 8);
  insertAtTail(B, 9);
  insertAtTail(B, 11);
  insertAtTail(B, 15);
  insertAtTail(B, 20);
  traverse(B);
  printf("\n");
  printf("start\n");
  MList C;
  init(C);
  MList * a1 = A.next;
  MList * b1 = B.next;

  while (a1 != &A and b1 != &B) {
    if (a1->elem < b1->elem) {
      insertAtTail(C, a1->elem);
      a1=a1->next;
    }
    if (b1->elem < a1->elem) {
      insertAtTail(C, b1->elem);
      b1=b1->next;
    }
    if (a1->elem == b1->elem) {
      insertAtTail(C, a1->elem);
      insertAtTail(C, b1->elem);
      a1=a1->next;
      b1=b1->next;
    }
  }
  
  while(a1 != &A) {
    insertAtTail(C, a1->elem);
    a1=a1->next;
  }
  
  while(b1 != &B) {
    insertAtTail(C, b1->elem);
    b1=b1->next;
  }
  
  printf("------end-------\n");    
  traverse(A);
  printf("\n");
  traverse(B);
  printf("\n");
  traverse(C);
  printf("\n");
  destroy(A);
  destroy(B);
  destroy(C);
  return 0;
}
