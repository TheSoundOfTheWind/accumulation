#include "list.h"
#include <stdio.h>

bool init(MList & list)
{
  list.length = 0;
  list.elem = new ElemType[MAX_SIZE];
  if (NULL == list.elem)
    return false;
  return true;
}

bool destroy(MList & list)
{
  if (0 == list.length) 
    return true;
  delete  [] list.elem;
  list.elem =  nullptr;
  list.length = 0;
}

bool empty(const MList  & list)
{
  if (0 == list.length) {
    return true;
  }
  return false;
}

int length(const MList & list)
{
  return list.length;
}

bool getElem(const MList & list, int i, ElemType &e)
{
  if (i < 1 or i > list.length)
    return false;
  e = list.elem[i-1];
  return true;
}

void locateElem(const MList & list, ElemType e, int & i)
{
  i = 0;
  if (0 == list.length) {
    return ;
  }
  int j = 0;
  for (; j < list.length; ++j) {
    if (e == list.elem[j]) {
      i = j+1;
      break;
    }
  } // for
}

bool priorElem(const MList & list, ElemType cur_e, ElemType &pre_e)
{
  if (list.length <= 0) {
    return false;
  }
  for (int i = 0; i < list.length; ++i) {
    if (list.elem[i] != cur_e)
      continue;
    if (0 == i) {
      return false;
    }
    pre_e = list.elem[i-1];
    return true;
  } // for
  return false;
}

bool nextElem(const MList & list, ElemType cur_e, ElemType &pre_e)
{
  bool r_b = true;
  do {
    if (list.length <= 0) {
      r_b = false;
      break;
    }
    for (int i = 0; i < list.length; ++i) {
      if (list.elem[i] != cur_e)
	continue;
      if (i == list.length) {
	r_b = false;
	break;
      }
      pre_e = list.elem[i+1];
    }
  }while(0);

  return r_b;
}

bool insert(MList & list, int i, ElemType e)
{
  bool b_r = true;
  do {
    if (i < 1 or i > list.length+1) {
      b_r = false;
      break;
    }
    if (MAX_SIZE == list.length) {
      b_r = false;
      break;
    }
    for (int j = list.length; j > i-1; --j) {
      list.elem[j] = list.elem[j-1];
    }
    list.elem[i-1] = e;
    list.length ++;
  }while(0);
}

bool deleteElem(MList & list, int i)
{
  bool b_r = true;
  do {
    if (i < 0 or i > list.length) {
      b_r = false;
      break;
    }
    for (int j = i-1; j < list.length-1; ++j) {
      list.elem[j] = list.elem[j+1];
    }
    list.length--;
  }while(0);

  return b_r;
}

void traverse(const MList & list)
{
  for (int i = 0; i < list.length; ++i) {
    printf("%d ", list.elem[i]);
  }
}
