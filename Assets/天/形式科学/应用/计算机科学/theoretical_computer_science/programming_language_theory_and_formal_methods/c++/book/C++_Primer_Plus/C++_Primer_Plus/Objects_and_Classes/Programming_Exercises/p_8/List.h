#ifndef LIST_H_
#define LIST_H_
typedef unsigned long Item;
class List{
 private:
  enum {MAX = 10};
  Item items[MAX];
  int len;
 public:
  List();
  void add(const Item &);
  bool empty();
  bool full();
  void visit();
};
#endif /* LIST_H_ */
