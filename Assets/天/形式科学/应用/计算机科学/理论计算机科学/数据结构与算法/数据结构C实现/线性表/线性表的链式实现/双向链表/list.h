#ifndef LIST_H
#define LIST_H
typedef int ElemType;
typedef struct LNode{
  ElemType  elem;
  LNode *    prior;
  LNode *    next;
} MList;

const int MAX_SIZE = 100;

// get methods
// -----------------------------------------------------------------------------
bool empty(const MList & list);

int length(const MList  & list);

bool getElem(const MList  & list, const int & i, ElemType &e);

void locateElem(const MList & list, const ElemType & e, int & i);

bool priorElem(const MList & list, const ElemType & cur_e, ElemType &pre_e);

bool nextElem(const MList & list, const ElemType & cur_e, ElemType &next_e);

void traverse(const MList & list);
// -----------------------------------------------------------------------------

// set methods
// -----------------------------------------------------------------------------
bool init(MList & list);

bool destroy(MList & list);

bool insert(MList & list, const int & i, const ElemType & e);

bool deleteElem(MList & list, const int & i);

void insertAtHead(MList & list, const ElemType & e);

void insertAtTail(MList & list, const ElemType & e);
// -----------------------------------------------------------------------------  
#endif // LIST_H
