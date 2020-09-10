//
//  Created by Bilal Butt on 11/09/2017.
//  Copyright © 2017 Bilal Butt. All rights reserved.
//
// GitHub : https://github.com/imbilalbutt/BasicProblems
//

#include <iostream>
#include <string>
using namespace std;

// Remove comments in main() to run the code.

class linkedString
{
    struct node
    {
        char ch;
        node* next;
        
        void printRecursive() {
            cout <<  this->ch;
            if (next) next->printRecursive();
        }
        
        void printRecursiveReverse() {
            if (next) next->printRecursive();
            cout <<  this->ch;
        }
        
        //        int len(node* curr){
        //            if (curr == nullptr)
        //                return 0;
        //
        //            return 1+len(curr->next);
        //        }
        
        int len(){
            if (next == nullptr)
                return 1;
            return 1+ next->len();
        }
    };
    node* strHead, *strTail;
    int length;
    
public:
    linkedString() //Default Constructor
    {
        strHead=nullptr;
        strTail=nullptr;
        length=0;
    }
    
    linkedString(const string& str) //Copy Constructor
    {
        for(int i=0;i<str.length();i++){
            node * newnode=new node;
            newnode->ch=str.at(i);
            if(i ==0){
                strHead=newnode;
                strTail=newnode;
                newnode->next=nullptr;
            } else {
                strTail->next=newnode;
                newnode->next=nullptr;
                strTail=newnode;
            }
            length++;
        }
    }
    
    linkedString(const linkedString& str) //overlaoded Constructor
    {
        node * curr=str.strHead;
        while (curr != nullptr ){
            node * tempnode = new node;
            tempnode->ch = curr->ch;
            
            if (curr == str.strHead){
                strHead =tempnode;
                strTail = tempnode;
                tempnode->next = nullptr;
            } else {
                strTail->next = tempnode;
                tempnode->next = nullptr;
                strTail = tempnode;
            }
            curr = curr->next;
            length++;
        }
    }
    
    const linkedString& operator=(const linkedString& str) //Assignemnt Operator
    {
        node * curr=str.strHead;
        while (curr != nullptr){
            node * tempNode = new node;
            tempNode->ch = curr->ch;
            
            if (curr == str.strHead)   {
                tempNode->next = nullptr;
                strHead =  tempNode;
                strTail = tempNode;
            } else {
                strTail->next = tempNode;
                tempNode->next = nullptr;
                strTail = tempNode;
                //strTail -> next = nullptr
                // strTail = strTail->next;
            }
            curr = curr->next;
            length++;
        }
        
        return *this;
    }
    
    linkedString operator+(const linkedString& str) //Addistion Operator
    {
        linkedString linkedTemp ;
        
        if(strHead != nullptr) {
            node* curr = strHead;
            
            //linkedTemp.strHead = strHead;
            while(curr != nullptr)  {
                node* temp = new node;
                temp->ch = curr->ch;
                
                if(curr == strHead)  {
                    linkedTemp.strHead =temp;
                    linkedTemp.strTail = temp;
                    temp->next = nullptr;
                } else {
                    temp->next = nullptr;
                    linkedTemp.strTail->next = temp;
                    //linkedTemp.strTail = linkedTemp.strTail->next;
                    linkedTemp.strTail = temp;
                }
                curr = curr->next;
                linkedTemp.length++;
            }
        }
        
        if(str.strHead != nullptr) {
            node* prev = linkedTemp.strTail;
            node* curr = str.strHead;
            
            while(curr != nullptr) {
                prev->next = new node;
                prev = prev->next;
                prev->ch = curr->ch;
                prev->next = nullptr;
                linkedTemp.strTail = prev;
                curr = curr->next;
            }
        }
        return linkedTemp;
    }
    
    friend ostream& operator << (ostream & out, const linkedString& str) {
        node* temp = str.strHead;
        while(temp != nullptr) {
            out << temp->ch;
            temp = temp-> next;
        }
        return out;
    }
    
    friend istream& operator>>(istream & in, linkedString& str)
    {
        string tempStr;
        in >> tempStr;
        
        for(int i=0; i < tempStr.length() ;i++) {
            node * newnode=new node;
            newnode->ch=tempStr.at(i);
            if(i == 0) {
                newnode->next=nullptr;
                str.strHead=newnode;
                str.strTail=newnode;
            } else {
                str.strTail->next=newnode;
                newnode->next=nullptr;
                str.strTail=newnode;
            }
            str.length++;
        }
        node* temp =str.strHead;
        while(temp!= nullptr) {
            str.length++;
        }
        return in;
    }
    
    int getLength()
    {
        node* curr = new node;
        curr = strHead;
        int len = 0;
        while(curr != NULL) {
            len++;
            curr = curr-> next;
        }
        return len;
    }
    
    bool find(const linkedString& str)
    {
        node* temp = strHead;
        node* temp2 = str.strHead;
        bool found  =true; //assume that we have found the strings
        
        if(temp == nullptr || temp2 == nullptr) {
            return false;
        } else {
            if(length < str.length) { // "bilal"     // "my name is bilal"
                while(temp2 != nullptr) {
                    if(temp->ch != temp2-> ch) {
                        if(temp2->next == nullptr) {//checks last element, then changes found
                            found =false;
                        }
                    } else {
                        temp = temp->next;
                    }
                    
                    if(temp->next == nullptr) {
                        break;
                    }
                    temp2 = temp2->next;
                }
            }
            
            else if(length > str.length) {                                // if input like this  // "my name is bilal"    //"bilal"
                while(temp != nullptr) {
                    if(temp-> ch != temp2->ch) {
                        if(temp->next == nullptr) {
                            found = false;
                        }
                    }  else {
                        //temp = temp->next;
                        temp2 = temp2->next;
                    }
                    
                    if(temp2->next == nullptr){
                        break;
                    }
                    temp = temp->next;
                }
                
            }
            
            //else if(length == str.length) //both are equal in length
            else{
//                if(temp->ch != temp2->ch)
                    if(strcmp(&temp->ch, &temp2->ch) != 0){
                    found = false;
//                    cout << "\nFoundS = " << found;
                    return found;
                }
                
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
//        cout << "\nFound : " << found;
        return found;
    }
    
    bool find(const string& str)
    {
        bool found = true ;
        //parameter = "my name"
        node* curr = strHead;
        if(curr == nullptr)
        {
            return false;
        }
        else if(length < str.size()) // if builtin is less
        {
            //found = true;
            // node* temp = curr;
            int i =0; char c;
            while(i < str.size())
            {
                c = str.at(i);
                if(curr->ch != c)
                {
                    //found = false;
                    if(curr->next== nullptr || i == str.size()) //checks if next element is last, if NOT found and next is last returns false
                    {
                        found  = false;
                        // break;
                    }
                }
                else
                {
                    curr= curr->next;
                }
                
                i++;
            }
            //return false;
        }
        else if(length> str.size()) /////my name is bilal       //bilal
        {
            // node* temp = curr;
            int i =0; char c;
            //cout << "\n Length = " << length;
            //cout << "\nStrSize = " << str.size();
            while(curr != nullptr && i < str.size())
            {
                //cout << "\ni = " << i;
                c = str.at(i);
                if(curr->ch != c)
                {
                    if(curr->next == nullptr || i == str.size() )
                    {
                        found = false;
                        //   break;
                    }
                    /// curr = curr->next;
                }
                //else if(curr->ch !=c)
                else
                {
                    ///curr= curr->next;
                    ++i;
                }
                curr = curr->next;
            }
        }
        
        else
        {
            int i = 0;
            ///////Now let assume lengths are same
            while(curr != nullptr)
            {
                char c;
                c = str.at(i);
                if(curr ->ch != c) //if does not find anywhere then returns false;
                {
                    found = false;
//                    cout << "FoundTh = " << found;
                    return found;
                }
                ++i;
                curr = curr->next;
            }
            //            found = true; //means found
            //
            //            // for(int i=0;i<str.length() ;  i++)
            //            int i =0;
            //            while(curr != nullptr)
            //            {
            //                char c = str.at(i); //first element from string
            //                if(curr->ch == c)
            //                {
            //                    //  node* temp = curr->next;
            //                    curr= curr->next;
            //                    for(int j = i+1; j < str.length() ;j++)
            //                    {
            //                        c = str.at(j);
            //                        //if(temp->ch != c)
            //                        if(curr->ch != c)
            //                        {
            //                            curr = curr->next;
            //
            //                            found= false;
            //                            break;
            //                        }
            //                        else
            //                        {
            //                            //temp = temp-> next;
            //                            curr = curr -> next;
            //                        }
            //                    }
            //                    // break;
            //                }
            //                //  curr = curr-> next;
            //            }
            
        }
//        cout << "\nFound" << found;
        return found;
    }
    
    linkedString findAndCopy(const string& str)
    {
        linkedString ls ;
        int i = 0;
        node* curr = strHead;
        
        while(curr != nullptr && i < str.size())
        {
            if(curr->ch == str.at(i))
            {
                node* temp = new node;
                temp->ch = str.at(i);
                
                if(ls.strHead == nullptr)
                {
                    temp->next = nullptr;
                    ls.strHead = temp;
                    ls.strTail = temp;
                }
                else
                {
                    ls.strTail->next = temp;
                    temp->next = nullptr;
                    ls.strTail = temp;
                }
                i++;
                ls.length++;
            }
            else
            {
                if(curr->next ==nullptr)
                {
                    cout << "\nNot Found in findAndCopy().\n";
                }
            }
            
            curr = curr->next;
        }
        
        return ls;
    }
    
    linkedString findAndCut(const string& str)
    {
        linkedString ls ;
        int i = 0;
        node* curr = strHead;
        
        while(curr != nullptr && i < str.size())
        {
            if(curr->ch == str.at(i))
            {
                node* temp = new node;
                temp->ch = str.at(i);
                
                if(ls.strHead == nullptr)
                {
                    temp->next = nullptr;
                    ls.strHead = temp;
                    ls.strTail = temp;
                }
                else
                {
                    ls.strTail->next = temp;
                    temp->next = nullptr;
                    ls.strTail = temp;
                }
                i++;
                ls.length++;
            }
            else
            {
                if(curr->next ==nullptr)
                {
                    cout << "\nNot Found in findAndCopy().\n";
                }
            }
            
            curr = curr->next;
        }
        
        return ls;
        
    }
    
    void findAndReplace (const string& str1, const string& str2); // TODO
    void findAndInsertAfter(const string& ,const string&); // TODO
    void findAndInvert(const string&); // TODO
    
    node* getHead(){
        return strHead;
    }
    
    void reverse()
    {
        node *new_head = nullptr;
        node* current = strHead;
        while(current != nullptr)
        {
            node* temp =new node;
            temp = current;                                             //keep temp pointer one step behind
            current = current->next;                                    //goes through each element in the list
            temp->next = new_head;                                      //scrolls through backwards from new head
            new_head = temp;
        }
        
        strHead = new_head;                                                //assign head to new head
        
    }
    
    void printReverseOrder(node* curr){
        if(curr != nullptr){
            printReverseOrder(curr->next);
            cout << curr->ch;
        }
    }
    
    void printRecursive(node* curr){
        if(curr == nullptr)
            return;
        cout << curr->ch;
        printRecursive(curr->next);
    }
    
    void printIterative(){
        node* curr  = strHead;
        while(curr != nullptr){
            cout << curr->ch;
            curr = curr->next;
        }
    }
    
    //~linkedString();
    
};

int main()
{
//    string temp1 = "hello ", temp2 = "world";
    //string temp3 = "goli";
    
    cout << "ALERT!!! While inputting DO NOT press space.";
    cout << "\ni.e.:Enter 'helloworld'" << " DO NOT enter 'hello world'";
    string temp1,temp2;
    cout << "\nEnter string 1 = " ;
    cin >> temp1;
    cout<< "\nEnter String 2 = " ;
    cin >> temp2;
    
    
    /* Check 1: Copy and Overloaded Constructor */
    linkedString str1(temp1), str2(temp2);
    linkedString str3("bad");
    str1.printReverseOrder(str1.getHead());
    //linkedString str4(temp3) ;
    
    
    /* Check 2: find() function */
//    if(str1.find(str2)==true){
//        cout << "\nSuccessfully found linkedString str2";
//    }
//    if(str1.find(temp2)==true){ //DONE
//        cout << "\nSucessfully found temp2";
//    }
    
    
     /*Check 3: Concatenation and Operator overloaded*/
//    cout << "\nStr3 = " << str3;
    //str3= str1+str3+str2;
//    cout << "\nStr3 = " << str3;
//    str1 = str3;
    
    // TODO
    /* Check 4: findAndReplace() function */
//    str3.findAndReplace("mer", "bad");
   //"hello my world" becomes "hello bad world"
    
    
    /* Check 5: findAndCut() function*/
    //str1 contains "bad ", str3 becomes "hello world"
//    str1 = str3.findAndCut(("bad"));
//    cout << str1;
    
    
    
    /* Check 6: "<<" Output Operator overloaded */
//    cout << "\n\nStr1: " << str1;
//    cout << "\n\nStr2: "  << str2;
    
    
    /* Check 7: find() function */
    str3.find("bad");
    str2= str1.findAndCopy("ba");
    cout << str2;
    
    
    /* Check 8: Reverse function */
//    str3.reverse();
//    cout << str3;
    //    cout << "\n\nStr1: " << str1;
    //    cout << "\n\nStr2: " << str2;
    //    cout << endl;
    
    
    /* Check 9 : ">>"cin operator check*/
//    cout << "Enter A strinng for input : \n" ;
//    cin >> str1;
//    cout << str1;
    
    return 0;
}

