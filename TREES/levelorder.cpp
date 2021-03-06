#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
  Node *lchild;
  int data;
  Node *rchild;
  Node(){};
  Node(int data);
};

Node::Node(int data)
{
  lchild = nullptr;
  this->data = data;
  rchild = nullptr;
}

class Tree
{
private:
  Node *root;

public:
  Tree();
  ~Tree();
  void CreateTree();
  void Preorder(Node *p);
  void Preorder() { Preorder(root); } // Passing Private Parameter in Constructor
  void Inorder(Node *p);
  void Inorder() { Inorder(root); }
  void Postorder(Node *p);
  void Postorder() { Postorder(root); }
  void Levelorder(Node *p);
  void Levelorder() { Levelorder(root); }
  void iterativePreorder(Node *p);
  void iterativePreorder() { iterativePreorder(root); }
  void iterativeInorder(Node *p);
  void iterativeInorder() { iterativeInorder(root); }
  void iterativePostorder(Node *p);
  void iterativePostorder() { iterativePostorder(root); }
  Node *generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
  int Height(Node *p);
  int Height() { return Height(root); }
  int Count(Node *p);
  int Count() { Count(root); }
  int Sum(Node *p);
  int Sum() { Sum(root); }
  int deg2NodeCount(Node *p);
  int deg2NodeCount() { deg2NodeCount(root); }
};

Tree::Tree()
{
  root = nullptr;
}

Tree::~Tree()
{
  // TODO
}

void Tree::CreateTree()
{
  Node *p;
  Node *t;
  int x;
  queue<Node *> q;

  root = new Node;
  cout << "Enter root data: " << flush;
  cin >> x;
  root->data = x;
  root->lchild = nullptr;
  root->rchild = nullptr;
  q.emplace(root);

  while (!q.empty())
  {
    p = q.front();
    q.pop();

    cout << "Enter left child data of " << p->data << ": " << flush;
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->lchild = nullptr;
      t->rchild = nullptr;
      p->lchild = t;
      q.emplace(t);
    }

    cout << "Enter right child data of " << p->data << ": " << flush;
    cin >> x;
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->lchild = nullptr;
      t->rchild = nullptr;
      p->rchild = t;
      q.emplace(t);
    }
  }
}

void Tree::Levelorder(Node *p)
{
  queue<Node *> q;
  cout << p->data << ", " << flush;
  q.emplace(p);

  while (!q.empty())
  {
    p = q.front();
    q.pop();

    if (p->lchild)
    {
      cout << p->lchild->data << ", " << flush;
      q.emplace(p->lchild);
    }

    if (p->rchild)
    {
      cout << p->rchild->data << ", " << flush;
      q.emplace(p->rchild);
    }
  }
}

int main()
{

  Tree bt;

  return 0;
}