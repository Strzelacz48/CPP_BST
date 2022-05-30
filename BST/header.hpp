#include<iostream>
#include<fstream>
#include"trejt.hpp"
using namespace std;
template <typename T>//możliwe że niepotrzebne
T maks(const T &a, const T &b)
{
return a < b ? b : a;
}
template<typename T>
struct node {
        T data;
        node* left;
        node* right;
    };
template<class T, class Trait = compare_types<T>>
class BST {
private:
    node<T>* root;

    node<T>* makeEmpty(node<T>* t);
    node<T>* insert(T x, node<T>* t);
    node<T>* findMin(node<T>* t);
    node<T>* findMax(node<T>* t);
    node<T>* remove(T x, node<T>* t);
    void inorder(node<T>* t);
    void inorder2(std::ostream &wy, node<T>* t) const ;
    node<T>* find(node<T>* t, T x);

    //pole compare
    static Trait P;
public:
    //konstruktory
    BST<T,Trait>() {
        root = nullptr;
    }
    BST<T,Trait>(std::initializer_list<T> lista)
    {
     root=nullptr;
        for(T x: lista)
        {
            root=insert(x,root);
        }
    }
    BST<T,Trait>(const BST<T> &tree){
    root=pomkon(tree.root);
    }
    node<T>* pomkon(node<T>* tree)
    {
        node<T>* t= new node<T>;
        t->data=tree->data;
        if(tree->left!=nullptr)
        {
            t->left=pomkon(tree->left);
        }
        else
            t->left=nullptr;
        if(tree->right!=nullptr)
        {
            t->right=pomkon(tree->right);
        }
        else
            t->right=nullptr;
        return t;
    }
    BST<T,Trait>(const BST<T> &&tree) {
    swap(root,tree.root);
}
const BST<T>& operator = (const BST<T> &tree) {
    if (this == &tree) return *this;
    this->~BST<T>();
    root = pomkon(tree.root);
    return *this;
}
const BST<T>& operator = (BST<T> &&tree) {
    if (this == &tree) return *this;
    swap(root, tree->root);
    return *this;
}

    ~BST() {
        root = makeEmpty(root);
    }
//koniec konstruktorów
    void insert(T x) {
        root = insert(x, root);
    }

    void remove(T x) {
        if(root==nullptr)
            throw std::string("Drzewo jest puste.");
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
    void display2(std::ostream &wy) const {
        inorder2(wy, root);
        wy << endl;
    }

    node<T>* search(T x) {
        node<T> *temp=find(root, x);
        if(temp==nullptr)
            throw std::string("Nie ma tego elementu w drzewie");
        return temp;
    }
    friend std::ostream& operator << (std::ostream &wy, const BST<T, Trait> &tree) {
            if(tree.root == nullptr) wy<<"Puste drzewo.\n";
            else  tree.display2(wy);
            wy<<"\n";
            return wy;
        }
};
template<class T, class Trait>
void BST<T,Trait>::inorder2(std::ostream &wy, node<T>* t) const {
    if(t)
    {
        inorder2(wy, t->left);
        wy << t->data << " ";
        inorder2(wy, t->right);
    }
}
template<class T, class Trait>
node<T>* BST<T, Trait>::makeEmpty(node<T>* t) {
        if(t == nullptr)
            return nullptr;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return nullptr;
    }
template<class T, class Trait>
node<T>* BST<T,Trait>::insert(T x, node<T>* t)
{
    if(t == nullptr)
    {
        t = new node<T>;
        t->data = x;
        t->left = t->right = nullptr;
    }
    else if(P.compare(x, t->data))
        t->left = insert(x, t->left);
    else if(P.compare(t->data,x))
        t->right = insert(x, t->right);
    return t;
}
template<class T, class Trait>
node<T>* BST<T,Trait>::findMin(node<T>* t)
{
    if(t == nullptr)
        return nullptr;
    else if(t->left == nullptr)
        return t;
    else
        return findMin(t->left);
}
template<class T, class Trait>
node<T>* BST<T,Trait>::findMax(node<T>* t) {
    if(t == nullptr)
        return nullptr;
    else if(t->right == nullptr)
        return t;
    else
        return findMax(t->right);
}
template<class T, class Trait>
node<T>* BST<T,Trait>::remove(T x, node<T>* t) {
    node<T>* temp;
    if(t == nullptr)
        return nullptr;
    else if(P.compare(x,t->data))
        t->left = remove(x, t->left);
    else if(P.compare(t->data,x))
        t->right = remove(x, t->right);
    else if(t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    else
    {
        //temp = t;
        if(t->left == nullptr)
            t = t->right;
        else if(t->right == nullptr)
            t = t->left;
        //delete temp;
    }

    return t;
}
template<class T, class Trait>
void BST<T,Trait>::inorder(node<T>* t) {
    if(t == nullptr)
        return;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}

template<class T, class Trait>
node<T>* BST<T,Trait>::find(node<T>* t, T x) {
    if(t == nullptr)
        return nullptr;
    else if(P.compare(x,t->data))
        return find(t->left, x);
    else if(P.compare(t->data,x))
        return find(t->right, x);
    else
        return t;
}
template<class T, class Trait>
Trait BST<T,Trait>::P
{
};
