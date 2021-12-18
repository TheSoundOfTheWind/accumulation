#include <stdio.h>
#include "tree.h"
int main()
{
  Tree tree;
  init(tree);
  if (true == empty(tree))
    printf("tree is empty\n");
  createTree(tree);
  printf("pre\n");
  preOrderTraverse(tree);
  printf("\n");
  printf("in\n");
  inOrderTraverse(tree);
  printf("\n");
  printf("post\n");
  postOrderTraverse(tree);
  printf("\n");
  assign(tree, 2, 1);
  printf("pre\n");
  preOrderTraverse(tree);
  printf("\n");
  if (true == isSame2(tree)){
    printf("is same\n");
  }
  
  return 0;
}
