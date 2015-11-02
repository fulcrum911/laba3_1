#include<iostream>
#include<iomanip>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<locale>
using namespace std;
struct Node {
	int value;
	Node *left;
	Node *right;
};
void InsertTree(Node **aNode, int data) {
	if (!(*aNode)) {
		(*aNode) = new Node;
		(*aNode)->value = data;
		(*aNode)->left = NULL;
		(*aNode)->right = NULL;
	}
	else {
		if (data < (*aNode)->value) InsertTree(&(*aNode)->left, data);
		else InsertTree(&(*aNode)->right, data);
	}
	return;
}
void PrintTree(Node *aNode) {
	if (aNode) {
		PrintTree(aNode->left);
		cout << aNode->value << " ";
		PrintTree(aNode->right);
	}
	return;
}
void Del(Node **r, Node **q)
{
	Node *s;
	if (!(*r)->right)
	{
		(*q)->value = (*r)->value;
		*q = *r;
		s = *r; *r = (*r)->left; delete s;
	}
	else  Del(&((*r)->right), q);
}
void Delete(Node **p, int data)
{
	Node *q;

	if (!p) cout << "??????? ?? ??????? ?????? ?? ????????!" << endl;
	else
		if (data<(*p)->value) Delete(&((*p)->left), data);
		else
			if (data>(*p)->value) Delete(&((*p)->right), data);
			else
			{
				q = *p;
				if (!q->right)
				{
					*p = q->left; delete q;
				}
				else
					if (!q->left) { *p = q->right; delete q; }
					else  Del(&(q->left), &q);
			}
	return;
}
int getMax(Node *aNode, int maximum) { //функцыя поверта максимальний елемент
	if (aNode == NULL) {
		return maximum;
	}
	return max(getMax(aNode->left, aNode->value),
		getMax(aNode->right, aNode->value));
}

int getMin(Node *aNode, int minimum) { //функція поверта мінімальний елемент дерева
	if (aNode == NULL) {
		return minimum;
	}
	return min(getMin(aNode->left, aNode->value),
		getMin(aNode->right, aNode->value));
}

int getSum(Node *aNode, int max, int min) { //функція що поверта суму

	return max + min;

}


void main()
{
	setlocale(LC_ALL, "Russian");
	Node *root = new Node;
	root = NULL;
	InsertTree(&root, 97);
	InsertTree(&root, 8);
	InsertTree(&root, 9);
	InsertTree(&root, 53);
	InsertTree(&root, 49);
	cout << "Åëåìåíòè áiíàðíîãî äåðåâà" << endl;
	PrintTree(root);
	cout << endl;
	cout << "Ìàêñèìàëüíèé åëåìåíò =" << getMax(root, -1000) << endl;
	cout << "Ìiíiìàëüíèé  åëåìåíò =" << getMin(root, 1000) << endl;
	cout << "Ñóìà çàäàíèõ åëåìåíòiâ = " << getSum(root, getMax(root, -1000), getMin(root, 1000)) << endl;
	Delete(&root, 97);
	Delete(&root, 8);
	Delete(&root, 9);
	Delete(&root, 53);
	Delete(&root, 49);
	system("pause");
}
