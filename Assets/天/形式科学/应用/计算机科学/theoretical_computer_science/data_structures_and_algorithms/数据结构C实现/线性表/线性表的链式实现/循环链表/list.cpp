#include "list.h"
#include <stdio.h>
bool init(MList & list)
{
  list.elem = 0;
  list.next = &list;
}

bool destroy(MList & list)
{
  MList * p = list.next;
  MList * q = nullptr;
  while(p != &list) {
    q = p->next;
    delete p;
    p = q;
  }
}

bool empty(const MList  & list)
{
  const MList * h = &list;
  return (list.next == h);
}

int length(const MList & list)
{
  int len = 0;
  const MList * h = &list;
  MList * p = list.next;
  while (p != h) {
    len++;
    p = p->next;
  }
  return len;
}

bool getElem(const MList & list, int i, ElemType &e)
{
  int len = 0;
  const MList * h = & list;
  MList * p = list.next;
  while(p != h) {
    len++;
    if (len == i) {
      e = p->elem;
    }
    p = p->next;
  } // while
}

void locateElem(const MList & list, ElemType e, int & i)
{
  MList * p = list.next;
  const MList * h = &list;
  int len = 0;
  while(p != h){
    len ++;
    if (e == p->elem) {
      i = len;
    }
    p = p->next;
  } // while
}

bool priorElem(const MList & list, ElemType cur_e, ElemType &pre_e)
{
  MList * p = list.next;
  MList * q = list.next;
  const MList * h = &list;
  while(q != h) {
    if (q->elem == cur_e and p != list.next) {
      pre_e = p->elem;
    }
    p = q;
    q = q->next;
  } // while
}

bool nextElem(const MList & list, ElemType cur_e, ElemType &next_e)
{
  MList * p = list.next;
  const MList * h = &list;
  while(p != list.next) {
    if (cur_e == p->elem and p->next != h) {
      next_e = p->next->elem;
      break;
    }
    p = p->next;
  } // while
}

bool hasElem(const MList & list, const ElemType & e)
{
  bool r_b = false;
  const MList * h = &list;
  MList * p = list.next;
  while(p != h) {
    if (e == p->elem) {
      r_b = true;
      break;
    }
    p = p->next;
  }

  return r_b;
}

bool insert(MList & list, int i, ElemType e)
{
  int len = 0;
  const MList * h = &list;
  MList * p = list.next;
  MList * q = &list;
  while(p != h) {
    len++;
    if (len == i) {
      MList * t = q -> next;
      MList * n = new MList;
      n->elem = e;
      q->next = n;
      n->next = t;
    }
    q = p;
    p = p->next;
  }
}

bool deleteElem(MList & list, int i)
{
  MList * p = list.next;
  MList * q = &list;
  const MList * h = &list;
  int len = 0;
  while(p != h) {
    len ++;
    if (len == i) {
      MList * t = p->next;
      q ->next = t;
      delete p;
      break;
    }
    q = p;
    p = p->next;
  } // while
}

void traverse(const MList & list)
{
  MList * p = list.next;
  const MList * h = &list;
  while(p != h) {
    printf("%d ", p->elem);
    p = p->next;
  }
}

void insertAtHead(MList & list, ElemType e)
{
  MList * n = new MList;
  n->elem = e;
  MList * p = list.next;
  list.next = n;
  n->next = p;
}

void insertAtTail(MList & list, ElemType e)
{
  MList * n = new MList;
  n->elem = e;
  MList * h = &list;
  n->next = h;
  MList * p = h;
  while(p->next != h) {
    p = p->next;
  }
  p->next = n;
}
