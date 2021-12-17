#include "list.h"
#include <stdio.h>
// get methods
// -----------------------------------------------------------------------------
bool empty(const MList  & list)
{
  const MList * h = &list;
  return (list.next == h);
}

int length(const MList & list)
{
  int len = 0;
  MList * p = list.next;
  const MList * h = &list;
  while(p != h) {
    len++;
    p = p->next;
  }
  return len;
}

bool getElem(const MList & list, const int & i, ElemType &e)
{
  int len = 0;
  MList * p = list.next;
  const MList * h = &list;
  while(p  != h) {
    len ++;
    if (len == i) {
      e = p->elem;
      break;
    }
    p = p->next;
  }
}

void locateElem(const MList & list, const ElemType & e, int & i)
{
  int len = 0;
  MList * p = list.next;
  const MList * h = &list;
  while(p  != h) {
    len ++;
    if (e == p->elem) {
      i = len;
      break;
    }
    p = p->next;
  }
}

bool priorElem(const MList & list, const ElemType & cur_e, ElemType &pre_e)
{
  bool b_r = false;
  const MList * h = &list;
  MList * p = list.next;
  while(p != h) {
    if (p->elem == cur_e and p->prior != h) {
      pre_e = p->prior->elem;
      b_r = true;
      break;
    }
    p = p->next;
  } // while
  return b_r;
}

bool nextElem(const MList & list, const ElemType & cur_e, ElemType &next_e)
{
  bool b_r = false;
  const MList * h = &list;
  MList * p = list.next;
  while(p != h) {
    if (p->elem == cur_e and p->next != h) {
      next_e = p->next->elem;
      b_r = true;
      break;
    }
    p = p->next;
  }
  return b_r;
}

void traverse(const MList & list)
{
  const MList * h = &list;
  MList * p = list.next;
  while(p != h) {
    printf("%d ", p->elem);
    p = p->next;
  }
}
// -----------------------------------------------------------------------------

// set methods
// -----------------------------------------------------------------------------
bool init(MList & list)
{
  list.elem = 0;
  list.prior = &list;
  list.next = &list;
}

bool destroy(MList & list)
{
  MList * p = list.next;
  MList * q = list.next;
  while(p != &list) {
    q = p->next;
    delete p;
    p = q;
  }
  list.next = &list;
  list.prior = &list;
}

bool insert(MList & list, const int & i, const ElemType & e)
{
  bool b_r = false;
  MList * p = list.next;
  int len = 0;
  while (p != &list){
    len ++;
    if (len == i) {
      MList * n = new MList;
      n->elem = e;
      n->next = p;
      n->prior = p->prior;
      p->prior->next = n;
      p->prior = n;
      b_r = true;
      break;
    }
    p = p->next;
  }
  return b_r;
}

bool deleteElem(MList & list, const int & i)
{
  bool b_r = false;
  int len = 0;
  MList * p = list.next;
  while (p != &list) {
    len ++;
    if (i == len)  {
      MList * q = p->prior;
      q->next = p->next;
      delete p;
      b_r = true;
      break;
    }
    p = p->next;
  }

  return b_r;
}

void insertAtHead(MList & list, const ElemType & e)
{
  MList * n = new MList;
  n->elem = e;
  n->next = list.next;
  n->prior = &list;
  list.next->prior = n;
  list.next = n;
}

void insertAtTail(MList & list, const ElemType & e)
{
  MList * n = new MList;
  n->elem = e;
  n->next = &list;
  n->prior = list.prior;
  list.prior->next = n;
  list.prior = n;
}
// -----------------------------------------------------------------------------
