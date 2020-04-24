#include<iostream>
using namespace std;

struct BstNode {
	string data;
	BstNode* left;
	BstNode* right;
};


BstNode* GetNewNode(string data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


BstNode* Insert(BstNode* root,string data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}

	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}

	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

bool Search(BstNode* root,string data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
BstNode* FindMin(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}


struct BstNode* Delete(struct BstNode *root, string data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);

	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL) {
			struct BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct BstNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

void Preorder( BstNode *root) {

	if(root == NULL) return;

	cout<<root->data; // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}
void Inorder(BstNode *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	cout<<root->data;  //Print data
	Inorder(root->right);      // Visit right subtree
}


void Postorder(BstNode *root) {
	if(root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	cout<<root->data; // Print data
}
int main() {
	BstNode* root = NULL;  // Creating an empty tree
	int N,c=0;
	cin>>N;
	string s,s2,x;
	for(int i=0;i<N;i++)
	{
	    getline(cin,s);

	    s2=s[0]+s[1];

	    if(s2=="IN")
	    {x=s[7];

	        root=Insert(root,x);
	       Postorder;
	    }
	    else if(s2=="DE")
	    {
	        x=s[4];
	        root=Delete(root,x);
	    }
	    else if(s2=="DI")
	    {
	        cout<<"preorder:";
	        Preorder(root);
	        cout<<endl;
	        cout<<"inorder:";
	        Inorder(root);
	        cout<<endl;
	        cout<<"postorder:";
	        Postorder(root);


	    }
	}


}
