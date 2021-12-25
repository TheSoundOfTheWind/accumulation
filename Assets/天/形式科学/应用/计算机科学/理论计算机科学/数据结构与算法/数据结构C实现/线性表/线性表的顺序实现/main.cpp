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
    insert(list, i, i);
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
  destroy(list);
  return 0;
}
