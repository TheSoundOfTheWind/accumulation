#ifndef LIST_H
#define LIST_H
typedef int ElemType;
typedef struct {
  int length;
  ElemType  * elem;
} MList;

const int MAX_SIZE = 100;

bool init(MList & list);

bool destroy(MList & list);

bool empty(const MList & list);

int length(const MList  & list);

bool getElem(const MList  & list, int i, ElemType &e);

void locateElem(const MList & list, ElemType e, int & i);

bool priorElem(const MList & list, ElemType cur_e, ElemType &pre_e);

bool nextElem(const MList & list, ElemType cur_e, ElemType &pre_e);

bool insert(MList & list, int i, ElemType e);

bool deleteElem(MList & list, int i);

void traverse(const MList & list);

#endif // LIST_H
