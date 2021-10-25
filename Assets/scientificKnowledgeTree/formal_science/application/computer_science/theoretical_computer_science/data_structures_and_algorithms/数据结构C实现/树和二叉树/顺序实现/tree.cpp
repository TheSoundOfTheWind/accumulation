#include <math.h>
#include <string.h>
#include "tree.h"

void init(Tree & tree)
{
  memset(tree, 0, MIXSIZE);
}

void destroy(Tree & tree)
{
  memset(tree, 0, MIXSIZE);
}
void createTree(Tree & tree)
{
  memset(tree, 0, MIXSIZE);  
}
void clearTree(Tree & tree)
{
  memset(tree, 0, MIXSIZE);  
}
bool empty(const Tree & tree)
{
  return strlen(tree)==0;
}
int depth(const Tree & tree)
{
  return int(log(strlen(tree))) + 1 ;
}

bool assign(Tree & tree, const ElemType & e1, const ElemType & e2)
{
  bool r_b = false;
  int len = strlen(tree);
  for (int i = 0; i < len; ++i) {
    if (e1 != tree[i])
      continue;
    tree[i] = e2;
    r_b = true;
  }
  return r_b;
}

bool parent(const Tree & tree, ElemType & e)
{
  bool r_b = true;
  int len = strlen(tree);
  if (strlen(tree) <= 1) {
    r_b = false;
    return r_b;
  }
  int k = log(len);
  int n = pow(2, k);
  n = n+ (len-n)/2;
  e = tree[n-1];
  
  return r_b;
}

bool leftChild(const Tree & tree, const ElemType & e1, ElemType & e2)
{
  const int len = strlen(tree);
  if (0 == len) {
    return false;
  }
  int i = 0;
  for (; i < len; ++i) {
    if (e1 == tree[i]) {
      break;
    }
  }
  if (len == i) {
    return false;
  }
  int k = log(i);
  int n = pow(2, k);
  int w = i - n;
  int s  = n + pow(2, k+1) + 2*w -1;
  if (s > len) {
    return false;
  }
  e2=tree[s];
}
bool rightChild(const Tree &, ElemType &)
{
  const int len = strlen(tree);
  if (0 == len) {
    return false;
  }
  int i = 0;
  for (; i < len; ++i) {
    if (e1 == tree[i]) {
      break;
    }
  }
  if (len == i) {
    return false;
  }
  int k = log(i);
  int n = pow(2, k);
  int w = i - n;
  int s  = n + pow(2, k+1) + 2*w;
  if (s > len) {
    return false;
  }
  e2=tree[s];
}
bool lefeSibling(const Tree & tree, const ElemType &e1, ElemType & e2)
{
  int len = strlen(tree);
  int i = 0;
  for (; i < len; ++i) {
    if (e1 == tree[i]) {
      break;
    }
  }
  int r = i%2;
  if (0 == r) {
    return false;
  }
  e = tree[i-1];
  return true;
}
bool rightSibling(const Tree & tree, ElemType & e)
{
  int len = strlen(tree);
  int i = 0;
  for (; i < len; ++i) {
    if (e1 == tree[i]) {
      break;
    }
  }
  int r = i%2;
  if (1 == r or i+1 > len) {
    return false;
  }
  e = tree[i+1];
  return true;
}
bool deleteChild(const Tree & tree, const ElemType & e, const int & lr)
{
}
void preOrderTraverse(const Tree &)
{
  
}
void inOrderTraverse(const Tree &)
{

}
void postOrderTraverse(const Tree &)
{

}
void levelOrderTraverse(const Tree &)
{

}
