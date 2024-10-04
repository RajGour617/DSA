#include<iostream>
using namespace std;

struct node {
    int d;
    node* left;
    node* right;
};

class bst {
    node* root;
  public:
    bst() {
		root=NULL;
	}

    void insert(int num) {
        node* t = new node;
        t->d = num;
        t->left = t->right = NULL;
        if (root == NULL) {
            root = t;
        } else {
            node* temp = root;
            node* prev = NULL;

            while (temp != NULL) {
                prev = temp;
                if (temp->d > num)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            if (prev->d > num)
                prev->left = t;
            else
                prev->right = t;
        }
    }

    void preorder(node* t) {
        if (t != NULL) {
            cout << t->d << " ";
            preorder(t->left);
            preorder(t->right);
        }
    }
    void preorder() {
        preorder(root);
    }
    
    void inorder(node* t) {
        if (t != NULL) {
            inorder(t->left);
            cout << t->d << " ";
            inorder(t->right);
        }
    }
    void inorder() {
        inorder(root);
    }
    
    void postorder(node* t){
    	if(t != NULL){
    		postorder(t->left);
    		postorder(t->right);
    		cout<<t->d<<" ";
    	}
	}
	void postorder(){
		postorder(root);
	}
    
};

int main() {
    bst b;
    b.insert(11);
    b.insert(4);
    b.insert(6);
    b.insert(3);
    b.insert(9);
    b.insert(1);
    b.insert(8);
    b.insert(7);
    b.insert(16);
    b.insert(10);
    cout<<"Preorder=> ";
    b.preorder();
    cout<<endl<<"Inorder => ";
    b.inorder();
    cout<<endl<<"Postorder=>";
    b.postorder();
    return 0;
}

