//  Created by Bilal Butt on 04/10/2017.
//  Copyright © 2017 Bilal Butt. All rights reserved.
//
// GitHub: https://github.com/imbilalbutt
//

/*
 Property: Each root node contains: left child and right child.
 Left Child: contain sall numbers (while considering each node in mind)
 Right Child: contain large numbers/ keys
 */


#include <iostream>
#include <vector>
#include <queue>


using namespace std;

//struct Node;

template<class T>
class BST
{
    struct Node{
        T data;
        Node* lchild;
        Node* rchild;
        
        Node(const T& obj) {
            data = obj;
            lchild = nullptr ;
            rchild = nullptr;
        }
    };
    Node* root;
    int size ;
    
    void inOrder(Node* curr, std::vector<Node*>& v)
    {
        if(curr!=nullptr)
        {
            inOrder(curr->lchild, v);
            v.push_back(curr);
            inOrder(curr->rchild, v);
        }
    }
    
    void preOrder(Node* curr, vector<Node*>&v)
    {
        if(curr!=nullptr)
        {
            v.push_back(curr);
            preOrder(curr->lchild, v);
            preOrder(curr->rchild, v);
        }
    }
    
    void postOrder(Node* curr, vector<Node*>&v)
    {
        if(curr!=nullptr)
        {
            postOrder(curr->lchild, v);
            postOrder(curr->rchild, v);
            v.push_back(curr);
        }
    }
    
public:
    BST(){
        root = nullptr;
        size = 0;
    }
    
    BST(const BST& tree)
    {
        root=NULL;
        copy(tree.root);
    }
    
    Node* createNode(const T& obj)
    {
        Node *curr = new Node;
        curr->data = obj;
        curr->lchild=nullptr;
        curr->rchild = nullptr;
        size++;
        return curr;
    }
    
    void copy(Node * N)
    {
        if(N)
        {
            insert(N->data);
            copy(N->lchild);
            copy(N->rchild);
        }
    }
    
    const BST&operator=(const BST & tree)
    {
        if(this != &tree)
        {
            root=NULL;
            copy(tree.root);
        }
        return *this;
    }
    
    bool search(const T& key)
    {
        Node* curr = root;
        while(curr!=nullptr)
        {
            if( curr->data==key ) return true;
            else if (curr->data > key) // means key is lesser
                curr= curr->lchild;
            else curr = curr -> rchild;
        }
        return false;
    }
    
    bool searchRecursively(Node* node, const T& key){
        if (node != nullptr){
            if(node->data == key)
                return true;
            else if (key > node->data)
                searchRecursively(node->rchild, key);
            else
                searchRecursively(node->lchild, key);
        }
        return false;
    }
    
    Node* findNode(Node* & node){
        Node* curr = root;
        
        while(curr!= nullptr){
//            if(curr->data == node->data)
//            {
//                //Node* prev = curr;
//                //node = curr;
//                //return node;
//                return curr;
//            }
            if(curr->data == node->data)
                return curr;
            else if(curr->data > node->data) curr = curr->lchild;
            else curr = curr->rchild;
        }
        return nullptr;
    }
    
    // This is similiar to search() function, but here it is returning the node.
    // But search() true or false.
    Node* findNode(const T& key){
        Node* curr = root;
        
        while(curr!= nullptr){
            //            if(curr->data == node->data)
            //            {
            //                //Node* prev = curr;
            //                //node = curr;
            //                //return node;
            //                return curr;
            //            }
            if(curr->data == key)
                return curr;
            else if(curr->data > key) curr = curr->lchild;
            else curr = curr->rchild;
        }
        return nullptr;
    }
    
    bool insert(const T& obj)
    {
        Node* curr = root;
        Node* prev = nullptr;
        
        while(curr!= nullptr)
        {
            if(curr->data < obj) // Meaning: if obj is greater than lChild
            {
                prev = curr;
                curr = curr->rchild;
            }
            else if( curr -> data > obj) // if obj is less than rChild
            {
                prev = curr;
                curr = curr->lchild;
            }
            else
            {
                return false;
            }
        }
        if(prev == nullptr)
        {
            root = new Node(obj);
            size = 1;
        }
        else
        {
            if(obj < prev->data)
            {
                prev->lchild = new Node(obj);
                size++;
            }
            else
            {
                prev->rchild = new Node(obj);
                size++;
            }
        }
        return true;
    }
    
    bool insertNode( Node*& obj)
    {
        Node* curr = root;
        Node* prev = nullptr;
        
        while(curr!= nullptr)
        {
            if(curr->data < obj->data)
            {
                prev = curr;
                curr = curr->rchild;
            }
            else if( curr -> data > obj->data)
            {
                prev = curr;
                curr = curr->lchild;
            }
            else
            {
                return false;
            }
        }
        if(prev ==nullptr)
        {
            root = new Node(obj->data);
            size = 1;
        }
        else
        {
            if(obj->data < prev->data)
            {
                prev->lchild = new Node(obj->data);
                size++;
            }
            else
            {
                prev->rchild = new Node(obj->data);
                size++;
            }
        }
        return true;
    }
    
    void deleteByMerging(Node* &node)
    {
        Node* curr = node;
        if(node!= nullptr)
        {
            if(node->rchild ==nullptr)
            {
                node = node->lchild;
            }
            else if(node->lchild == nullptr)
            {
                node = node->rchild;
            }
            
            else
            {
                curr = node->lchild; //move left
                while(curr->rchild == nullptr)
                {
                    curr = curr->rchild; // go to right as far as possible
                }
                
                curr->rchild= node->rchild;
                curr = node;
                node = node->lchild;
            }
            delete curr;
        }
        
    }
    
    void remove(const T&obj)
    {
        Node* curr = root;
        Node* prev  = nullptr;
        
        while(curr!= nullptr)
        {
            if(curr->data == obj)
            {
                prev = curr;
                break ;
            }
            
            if(curr->data > obj) //means obj is greater
                curr = curr->lchild;
            else curr = curr->rchild;
            
        }
        
        if(curr!=nullptr && curr->data == obj)
        {
            if(curr ==root)
                deleteByMerging(root);
            else if(prev->lchild== curr)
                deleteByMerging(prev->lchild);
            else deleteByMerging(prev->rchild);
        }
        else if(root != nullptr)
            cout << "Key " << obj << "is not in tree.\n";
        else cout << "Tree is empty.\n";
        
    }
    
    void levelOrder(Node *curr, vector<Node*>&v) //just saving Node* in levelOrder in vector v
    {
        //Node *curr = root;
        if (curr == nullptr)  return;
        
        queue<Node*> q;
        q.push(curr);
        v.push_back(curr);
        
        while (!q.empty()){
            Node *temp = q.front();
            //cout << node->data << " ";
            
            if (temp->lchild != nullptr){
                q.push(temp->lchild);
                v.push_back(temp->lchild);
                // q.pop();
            }
            if (temp->rchild != nullptr){
                q.push(temp->rchild);
                v.push_back(temp->rchild);
                //q.pop();
            }
            q.pop();
        }
    }
    
    void printLevelOrder(vector<T>&v)
    {
        cout << "\n\nPrint Level order Called\n\n";
        
        Node* curr = root;
        
        if (curr == nullptr)  return;
        
        queue<Node*> q;
        q.push(curr);
        //v.push_back(curr->data);
        
        while (!q.empty())
        {
            //q.pop();
            Node *temp = q.front();
            //cout << node->data << " ";
            //q.pop();
            
            if (temp->lchild != nullptr)
            {
                q.push(temp->lchild);
                v.push_back(temp->lchild->data);
                // q.pop();
            }
            if (temp->rchild != nullptr)
            {
                q.push(temp->rchild);
                v.push_back(temp->rchild->data);
                //q.pop();
            }
            // v.push_back(temp->data);
            
            q.pop();
        }
        int i = 0;
        while(i < v.size())
        {
            cout << v[i] << endl;
            // cout << "i = " << i <<endl;
            
            i++;
        }
    }
    
    void printInOrder(vector<T>& v)
    {
//        cout << "\nPrint In order Called\n\n";
        vector<Node* > temp;
        inOrder(root, temp);
        
        int i  =0;
        //
        //        while(i < temp.size())
        //        {
        //            v[i] = temp[i]->data;
        //          //  cout << temp[i]->data<< endl;
        //            i++;
        //        }
        
        i=0;
        while(i < temp.size()){
            cout << temp[i]->data<< " ";
            i++;
        }
        cout << "\n";
    }
    
    bool isLeaf(Node* curr)
    {
        if(curr->lchild == nullptr && curr->rchild == nullptr)
            return true;
        else return false;
    }
    
    bool haveOneChild(Node* curr)
    {
        // if(isLeaf(curr) == false)
        if(curr != nullptr)
        {
            if(curr->lchild != nullptr && curr->rchild == nullptr) return true;
            else if(curr->rchild != nullptr && curr->rchild == nullptr) return true;
        }
        //else return false;
        
        return false;
    }
    
    bool isComplete(Node* curr)
    {
        //if(isLeaf(curr)) return true;
        if(curr == nullptr) return true;
        
        if(haveOneChild(curr) == true) return false;
        if(curr->lchild && curr->rchild)
        {
            if( !isComplete(curr->lchild)) return false;
            if( !isComplete(curr->rchild)) return false;
            //return  (isComplete(root->lchild) && isComplete(root->rchild));
        }
        
        return true;
    }
    
    int getSize()
    {
        return size;
    }
    
    Node* getRoot()
    {
        return root;
    }
    
    int height(Node* curr)
    {
        if (curr == nullptr || isLeaf(curr))  return 0;
        else
        {
            int lheight = height(curr->lchild);
            int rheight = height(curr->rchild);
            
            if (lheight > rheight)
                return(lheight+1);
            
            else return(rheight+1);
        }
    }
    
    int CalculateWidth(Node * ptr, int curr, int level)
    {
        if (ptr == nullptr) return 0;
        else if (curr == level) return 1;
        else
            return (CalculateWidth(ptr->rchild, curr + 1, level)) + (CalculateWidth(ptr->lchild, curr + 1, level));
    }
    
    int Width()
    {
        int wid = 0;
        for (int i = height(root); i > 0; i--)
        {
            if (wid < CalculateWidth(root, 1, i))
            {
                wid = CalculateWidth(root, 1, i);
            }
        }
        return wid;
    }
    
    bool updateKey(const T & findKey, const T& insertKey){
        cout << "\nupdateKey() Called\n\n";
        bool leftChild = false;
        bool rightChild = false;
        bool check  = false;
        Node* curr = root;
        Node* prev = nullptr;
        
        while(curr!=nullptr) {
            if(curr->data==findKey) {
                //               Method 1: Just update the data. (working)
                //                curr->data = insertKey;
                
                //                Method 2: Inset a new node. (working)
                Node* temp = new Node(insertKey);
                temp->lchild = curr->lchild;
                temp->rchild = curr->rchild;
                
                if (leftChild==true && rightChild == false)
                    prev->lchild = temp;
                else if (rightChild == true && leftChild ==false)
                    prev->rchild = temp;
                
                check  = true;
                break;
            }
            else if (curr->data > findKey){ // means key is lesser
                rightChild = false;
                leftChild = true;
                prev = curr;
                curr= curr->lchild;
            } else {
                leftChild = false;
                rightChild = true;
                prev = curr;
                curr = curr -> rchild;
            }
        }
        
        if(check == false) return false;
        return true;
    }
    
    int hightest(int max)
    {
        Node* curr = root;
        
        max = curr->data;
        while(curr->rchild != nullptr)
        {
            max = curr->data ;
            curr= curr->rchild;
        }
        return max;
    }
    
    //Successor of an input node can also be defined as the node with the smallest key greater than the key of input node.
    int successor(const T & key, T & succ) //to do
    {
        Node* curr = root;
        Node* searchNode = nullptr;
        
        while(curr!= nullptr)
        {
            if(curr->data == key)
            {
                searchNode = curr;
                break;
            }
            else if(curr->data < key)
            {
                curr= curr->lchild;
            }
            else
            {
                curr = curr->rchild;
            }
        }
        
        int ret = 0;
        while (searchNode != nullptr && searchNode->data > key)
        {
            searchNode= searchNode ->rchild;
            ret  = searchNode->data;
        }
        
        return ret;
    }
    
    bool isSymmetrical(Node* n1, Node* n2)
    {
        if(isLeaf(n1) && isLeaf(n2)) return true;
        
        return (isSymmetrical(n1->lchild, n2->rchild) == isSymmetrical(n1->rchild, n2->lchild));
        
        // return false;
    }
    
    float experiment_On_BST()
    {
        float h = 0;
        for (int i = 0; i < 1000; i++)	//1000 BSTs
        {
            BST<int> t;
            for (int j = 0; j < 1000; j++) //1000 random numbers
            {
                int num = rand() % 1000 + 1;
                t.insert(num);
            }
            h = h + t.height(root);
        }
        return h / 1000;
    }
    
    class iterator
    {
    private:
        vector<Node*> node; //save node
        int index;
    public:
        friend ostream& operator << (ostream & out, const iterator& obj)
        {
            int i = 0;
            while(i < obj.node.size())
            {
                out << obj.node[i]->data;
                i++;
            }
            
            return out;
        }
        
        const iterator& operator=(const iterator& obj)
        {
            node = obj.node;
            index = obj.index;
            
        }
        
        iterator()
        {
            node.push_back(nullptr);
            index = 0;
        }
        
        iterator(Node* curr) //new node
        {
            if(curr!=nullptr)
            {
                node.push_back(curr);
                index++;
            }
        }
        
        iterator(vector<Node* >v , int i) //vector of new node
        {
            node = v;
            index = i;
        }
        
        iterator(const iterator& obj) // iterator
        {
            //for (int i = 0; i < obj.index.size();i++) //both
            node = obj.node;
            index = obj.index;
        }
        
        bool operator!=(const iterator& obj)
        {
            return (index != obj.index);
        }
        
        iterator& operator++() //pre
        {
            ++index;
            return *this;
        }
        
        iterator& operator++(int)
        {
            iterator temp = *this;
            ++temp.index;
            
            return temp;
            
        }
        
        //    integers& operator++() //Pre Increment
        //    {
        //        x = x+1;
        //        y = y+1;
        //
        //        return  *this;
        //    }
        //
        //    integers operator++(int) //Post Increment
        //    {
        //        integers temp = *this;
        //        x = x + 1;
        //        y = y  + 1;
        //
        //        return  temp;
        //    }
        
        T& operator* () //derefrence operator
        {
            T temp = node[index]->data;
            return temp;
        }
        
    };
    
    /* Level Order Using Iterator */
    // begin
    iterator lbegin()
    {
        vector<Node*> v;
        levelOrder(root, v);
        iterator itr (v,0);
        
        return itr;
    }
    
    // end
    iterator lend()
    {
        vector<Node* > v;
        levelOrder(root, v);
        iterator itr(v,v.size());
        
        return itr;
    }
    
    template <typename R>
    void printBSTinLevelOrder(BST<R> & tree) // In level order using iterators
    {
//        cout << "\n printBSTInLevelOrder called\n";
        iterator it;
        for(BST<int>::iterator itr = tree.lbegin(); itr != tree.lend(); ++itr){
            //cout <<*itr << ",";
            cout << *itr << " , ";
        }
        cout << "\n";
    }
    
    /* In Order */
    iterator inBegin()
    {
        vector<Node*> v;
        inOrder(root, v);
        iterator itr (v,0);
        
        return itr;
    }
    
    iterator inEnd()
    {
        vector<Node* > v;
        inOrder(root, v);
        iterator itr(v, v.size());
        
        return itr;
    }
    
    template <typename S>
    void printBSTInOrder(BST<S>& tree) // inOrder using iterators
    {
        cout << "\nprintBSTInOrder called\n";
        iterator itr;
        for(BST<int>::iterator itr = tree.inBegin(); itr != tree.inEnd(); ++itr)
        {
            //cout <<*itr << ",";
            cout << *itr << " , ";
        }
        cout << endl;
    }
    
};// END of iterator & BST

int main()
{
    vector<int >a ;
    vector<int > b;
    
    BST<int> tree1;
    BST<int> tree2;
    
    
    tree2.insert(70);
    tree2.insert(100);
    tree2.insert(50);
    tree2.insert(40);
    tree2.insert(20);
    tree2.insert(48);
    tree2.insert(80);
    tree2.insert(72);
    tree2.insert(90);
    tree2.insert(150);
    tree2.insert(120);
    tree2.insert(200);
    tree2.insert(35);
    tree2.insert(10);
    tree2.insert(5);
    tree2.insert(55);
    
    /*
                                                                                       70
                                                                                    /       \
                                                                                /               \
                                                                            /                      \
                                                                        /                              \
                                                                 50                                      100
                                                          /          \                             /               \
                                                     40                55                        80                150
                                               /             \                               /        \      /             \
                                           20                48                             72        90    120            200
                                        /       \
                                      5           35
                                       \
                                         10
     
     */
    
    /* Check -1: search() works or not*/
//    cout << tree2.search(37);
    
    /* CHECK 0: Assignment Operator */
//    tree1 = tree2;
//    tree1.printInOrder(a);
    
    
    /* Check 1: If printing correctly or not */
//    tree2.printInOrder(a);
//    tree2.printLevelOrder(a);
    
    
    /* Check 2:  If remove() works */
//    cout << "Before Removing\n\n";
//    tree2.printInOrder(a);
//    cout << "\nAfter removing\n\n";
//    tree2.remove(50);
//    tree2.printInOrder(a);
    
    
    /* Check 3: If function isComplete() works correctly or not */
//    if(tree2.isComplete(tree2.getRoot()) == 0)
//        cout << "\nTree  is not complete.\n";
//    else cout << "\nTree is complete.\n";
    
    
    /* Check 4: printBSTinLevelOrder using Iterator */
//    tree2.printBSTinLevelOrder(tree2);
//    tree2.printBSTInOrder(tree2);
    
    
    /* Check 5: successor() function */
//    int suc ;
//    if(tree2.successor(35  , suc) ==0)
//        cout << "\nNo successor.\n";
//    else cout << tree2.successor(35, suc);
    
    
    //* Check 6: Width() function */
//    cout << endl << endl;
//    cout << "Witdth = " <<  tree2.Width();
    
    
    /* Check 7 */
//    cout << tree2.experiment_On_BST() << endl;
    
    
    /* Check 8: If Key is being updated or not */
    tree2.printInOrder(a);
    tree2.updateKey(80, 81);
    tree2.updateKey(120, 121);
    tree2.printInOrder(a);
    
    
    /* Check 9 : searchRecurively() */
//    tree2.searchRecursively(tree2.getRoot(), 51);
    
    return 0;
}
