#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "tree.h"

void init(Tree & tree)
{
  tree->parent = nullptr;
  tree->lchild   = nullptr;
  tree->rchild   = nullptr;
  tree->data     = 0;
}

void destroy(Tree  & tree)
{
  if (tree->lchild != nullptr) {
    destroy(tree->lchild);
  }
  if (tree->rchild != nullptr) {
    destroy(tree->rchild);
  }
  delete tree;
  tree = nullptr;
}
void createTree(Tree & tree)
{
  int in = 0;
  cin >> in;
  if (in==-1) {
    tree = nullptr;
  }
  else {
    tree= new Node;
    tree->data = in;
    createTree(tree->lchild);
    createTree(tree->rchild);
  }
}
void clearTree(Tree & tree)
{
  if (tree->lchild != nullptr) {
    destroy(tree->lchild);
    tree->lchild = nullptr;
  }
  if (tree->rchild != nullptr) {
    destroy(tree->rchild);
    tree->rchild = nullptr;
  }
  delete tree;
}
bool empty(const Tree & tree)
{
  return tree->lchild == nullptr and tree->rchild == nullptr;
}

int depth(const Tree & tree)
{
  int l = 0;
  int r = 0;
  if (tree == nullptr)
    return 0;
  else {
    l = depth(tree->lchild);
    r = depth(tree->rchild);
    if (l > r) return l+1;
    if (r > l) return r+1;
  }
}

bool assign(Tree & tree, const ElemType & e1, const ElemType & e2)
{
  bool r_b = false;
  if (tree == nullptr)
    return r_b;
  if (e1 == tree->data) {
    tree->data = e2;
    r_b = true;
  }
  assign(tree->lchild, e1, e2);
  assign(tree->rchild, e1, e2);
}

bool parent(const Tree & tree, ElemType & e)
{
  if (tree ->parent == nullptr)
    return false;

  e = tree->parent->data;
  return true;
}

bool leftChild(const Tree & tree, ElemType & e)
{
  if (tree -> lchild == nullptr)
    return false;
  e = tree->lchild->data;
  return true;
}
bool rightChild(const Tree & tree, ElemType & e)
{
  if (tree->rchild == nullptr)
    return false;
  e = tree->rchild->data;
  return true;
}
bool lefeSibling(const Tree & tree, ElemType & e)
{
  if (tree->rchild == nullptr)
    return false;
  e = tree->rchild->data;
  return true;
}
bool rightSibling(const Tree & tree, ElemType & e)
{
  if (tree -> lchild == nullptr)
    return false;
  e = tree->lchild->data;
  return true;
}
bool deleteChild(const Tree & tree, const int & lr)
{
  if (0 == lr)
    destroy(tree->lchild);
  else
    destroy(tree->rchild);
}
void preOrderTraverse(const Tree & tree)
{
  if (tree == nullptr)
    return;
  cout << tree->data << " ";
  preOrderTraverse(tree->lchild);
  preOrderTraverse(tree->rchild);
}
void inOrderTraverse(const Tree & tree)
{
  if (tree == nullptr)
    return;
  inOrderTraverse(tree->lchild);
  cout << tree->data << " ";
  inOrderTraverse(tree->rchild);
}
void postOrderTraverse(const Tree & tree)
{
  if (tree == nullptr)
    return;
  postOrderTraverse(tree->lchild);
  postOrderTraverse(tree->rchild);
  cout << tree->data << " ";
}
void levelOrderTraverse(const Tree & tree)
{

}

bool isSame(const Tree & left, const Tree & right)
{
  if (left == nullptr and right == nullptr)
    return true;
  if (left == nullptr or right == nullptr)
    return false;
  return left->data == right->data
    and isSame(left->lchild, right->rchild)
    and isSame(left->rchild, right->lchild);
}

bool isSame2(const Tree & tree)
{
  if (nullptr == tree)
    return true;

  return isSame(tree->lchild, tree->rchild);
}
