#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
  int val;
  struct node *left,*right;
};

typedef node Node;
int id = 0;

Node *createNode(int value) {
  Node *newnode = (Node *) malloc(sizeof(Node));
  newnode->val = value;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

int findPosition(int inorder[], int s, int e, int value) {
  for(int i = s;i<=e;i++) {
    if(inorder[i] == value) return i;
  }
  return -1;
}

Node *BuildBinaryTree(int preorder[], int inorder[], int s, int e) {
  if(s>e) return NULL;
  
  Node *newnode = createNode(preorder[id]);
  int pos = findPosition(inorder, s, e, preorder[id]);
  id++;
  
  //cout<<"pos "<<pos<<" s,e "<<s<<" "<<e<<endl;
  
  newnode->left = BuildBinaryTree(preorder,inorder,s,pos-1);
  newnode->right = BuildBinaryTree(preorder,inorder,pos+1,e);
  
  return newnode;
}

void postorder(Node *node) {
  if(node == NULL) return ;
  postorder(node->left);
  postorder(node->right);
  cout<<node->val<<" ";
}

int main() {
    int preorder[] = {1,3,4,8,2,5,6};
    int inorder[] = {4,8,3,1,5,2,6};
    id = 0;
    Node *head = BuildBinaryTree(preorder,inorder,0,6);
    postorder(head);
}
