#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

struct Node {
	char data;
	Node *left, *right;
};

class Tree {
private:
	Node *root;

public:
	Tree() { root = Creat(root); }

	~Tree() { Release(root); }

	void PreOrder() { PreOrder(root); }

	void InOrder() { InOrder(root); }

	void PostOrder() { PostOrder(root); }

	void LevelOrder();

	void deleteBinode(char c);

	int getNumOfBinode() { return getNumOfBinode(root); }

	int getDepth() { return getDepth(root); };

	void saveInArray(int num, char *str, Node *bt);

	Node * getRoot() { return root; };

private:
	Node *Creat(Node *bt);

	void Release(Node *bt);

	void PreOrder(Node *bt);

	void InOrder(Node *bt);

	void PostOrder(Node *bt);

	int getNumOfBinode(Node *bt);

	int getDepth(Node *bt);

};
Node * Tree::Creat(Node *bt) {
	char ch;
	cin >> ch;
	if (ch == '#') {
		bt = NULL;
	}
	else {
		bt = new Node;
		bt->data = ch;
		bt->left = Creat(bt->left);
		bt->right = Creat(bt->right);
	}
	return bt;
}
void Tree::PreOrder(Node *bt) {
	if (bt == NULL)                 
		return;
	else {
		cout << bt->data;           
		PreOrder(bt->left);     
		PreOrder(bt->right);    
	}
}
void Tree::InOrder(Node *bt) {
	if (bt == NULL) {
		return;
	}
	else {
		InOrder(bt->left);
		cout << bt->data;
		InOrder(bt->right);
	}
}
void Tree::PostOrder(Node *bt) {
	if (bt == NULL) {
		return;
	}
	else {
		PostOrder(bt->left);
		PostOrder(bt->right);
		cout << bt->data;
	}
}
void Tree::LevelOrder() {
	Node * Q[1000];
	Node * q;
	int front = -1;
	int rear = -1;
	if (root == NULL) {
		return;
	}
	Q[++rear] = root;
	while (front != rear) {
		q = Q[++front];
		cout << q->data;
		if (q->left != NULL) {
			Q[++rear] = q->left;
		}
		if (q->right != NULL) {
			Q[++rear] = q->right;
		}
	}
}
void Tree::deleteBinode(char c) {
	Node * Q[1000];
	Node * q;
	int front = -1;
	int rear = -1;
	if (root == NULL) {
		return;
	}
	Q[++rear] = root;
	while (front != rear) {
		q = Q[++front];
		if (q->left != NULL) {
			Q[++rear] = q->left;
		}
		if (q->right != NULL) {
			Q[++rear] = q->right;
		}
		if (q->data == c) {
			q->data = NULL;
		}
	}
}
void Tree::Release(Node *bt) {
	if (bt == NULL) {
		return;
	}
	else {
		Release(bt->left);
		Release(bt->right);
		cout << endl << "??????" << bt->data << " ";
		delete bt;
	}
}
int Tree::getNumOfBinode(Node *bt) {
	if (bt == NULL)
		return 0;
	else {
		int leftcount = getNumOfBinode(bt->left);
		int rightcount = getNumOfBinode(bt->right);
		int cnt = leftcount + rightcount + 1;
		return cnt;
	}
}
int Tree::getDepth(Node *bt) {
	if (bt == NULL)
		return 0;
	else {
		int rightdepth = getDepth(bt->right);
		int leftdepth = getDepth(bt->left);
		int depth = max(leftdepth, rightdepth) + 1;
		return depth;
	}
}
void Tree::saveInArray(int num, char *str, Node *bt) {
	if (bt == NULL)
		return;
	else {
		str[num - 1] = bt->data;
		saveInArray(2 * num, str, bt->left);
		saveInArray(2 * num + 1, str, bt->right);
	}
}
int main() {
	Tree tree;
	char str[10000];
	tree.saveInArray(1, str, tree.getRoot());
	double k = tree.getDepth();
	for (int i = 0; i < pow(2.0, k); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
	}
	//cout << "PreOrder:";
	//tree.PreOrder();
	//cout << endl << "InOrder:";
	//tree.InOrder();
	//cout << endl << "PostOrder:";
	//tree.PostOrder();
	//cout << endl << "LeverlOrder:";
	//tree.LevelOrder();
	//cout << "NumOfNodes";
	//cout << tree.getNumOfBinode();
}
