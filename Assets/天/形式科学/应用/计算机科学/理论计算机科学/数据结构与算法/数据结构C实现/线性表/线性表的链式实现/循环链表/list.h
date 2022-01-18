#ifndef LIST_H
#define LIST_H
typedef int ElemType;
typedef struct LNode{
  ElemType  elem;
  LNode *    next;
} MList;

const int MAX_SIZE = 100;

bool init(MList & list);

bool destroy(MList & list);

bool empty(const MList & list);

int length(const MList  & list);

bool getElem(const MList  & list, int i, ElemType &e);

void locateElem(const MList & list, ElemType e, int & i);

bool priorElem(const MList & list, ElemType cur_e, ElemType &pre_e);

bool nextElem(const MList & list, ElemType cur_e, ElemType &next_e);

bool hasElem(const MList & list, const ElemType & e);
bool insert(MList & list, int i, ElemType e);

bool deleteElem(MList & list, int i);

void traverse(const MList & list);

void insertAtHead(MList & list, ElemType e);

void insertAtTail(MList & list, ElemType e);


#endif // LIST_H
