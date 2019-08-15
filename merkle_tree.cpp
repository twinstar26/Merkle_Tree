#include "merkle_tree.h"
#include <cstring>
#include<string>

using namespace std;

int main() {
  Node root = Node();

  Node left = Node("this is left");
  Node right = Node("this is right");

  root.child.push_back(&left);
  root.child.push_back(&right);

  root.hash = MDString(left.hash+right.hash);


  Node new_root = Node();

  Node new_left = Node("this is left");
  Node new_right = Node("this is right");

  new_root.child.push_back(&new_left);
  new_root.child.push_back(&new_right);

  new_root.hash = MDString(new_left.hash+new_right.hash);

  if(root.hash==new_root.hash)
  {
    cout<<"Successfully implemented Merkle Tree"<<endl;
    cout<<"Left node's hash: ";MDPrint(left.hash);cout<<" "<<"New Left node's hash: ";MDPrint(new_left.hash);cout<<endl;
    cout<<"Right node's hash: ";MDPrint(right.hash);cout<<" "<<"New Right node's hash: ";MDPrint(new_right.hash);cout<<endl;
    cout<<"Root node's hash: ";MDPrint(root.hash);cout<<" "<<"New Root node's hash: ";MDPrint(new_root.hash);cout<<endl;
  }
  /* unsigned char *val=new unsigned char[left.hash.length()+1];
	strcpy((char *)val,left.hash.c_str());
  MDPrint(val);*/
  return 0;
}