typedef int ElemType;
typedef struct Node {
  ElemType data;
  struct Node * lchild,* rchild,*parent;
} Node, * Tree;

void init(Tree &);
void destroy(Tree &);
void createTree(Tree &);
void clearTree(Tree &);
bool empty(const Tree &);
int    depth(const Tree &);
bool assign(Tree &, const ElemType &, const ElemType &);
bool parent(const Tree &, ElemType & e2);
bool leftChild(const Tree &, ElemType &);
bool rightChild(const Tree &, ElemType &);
bool lefeSibling(const Tree &, ElemType &);
bool rightSibling(const Tree &, ElemType &);
bool deleteChild(const Tree &, const ElemType &, int );
void preOrderTraverse(const Tree &);
void inOrderTraverse(const Tree &);
void postOrderTraverse(const Tree &);
void levelOrderTraverse(const Tree &);
bool isSame(const Tree & left, const Tree & right);
bool isSame2(const Tree & tree);
