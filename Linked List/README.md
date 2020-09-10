This folder contains the implementation of Linked List in C++.

Specifically, it creates a String which is created using the concept of linked list.

The functions implemented are:

linkedString() //Default Constructor

linkedString(const string& str) //Copy Constructor
This implements copy constructor, whenever String type str is passed in, it created the linked list of that content.

linkedString(const linkedString& str) //overlaoded Constructor
When one linkedString of type linkedString is passed in argument while initialization, it creates the linked list of that content.
For example:
If I have:
.......
linkedString str1 = "My string";
Then:
linkedString str2(str1); <-- Here overloaded constructor is called.

const linkedString& operator=(const linkedString& str) //Assignemnt Operator
This overloads the std::Assignment operator(=) for this particular class aka linkedString.

linkedString operator+(const linkedString& str) //Addistion Operator
This operator concatenates the two strings and returns the new string which contains contents of both this.linkedString and Object of linkedString str.
 
friend ostream& operator << (ostream & out, const linkedString& str) // cout Operator overaloaded
This is overloaded operator for printing the string.
 
friend istream& operator>>(istream & in, linkedString& str)
The input operator std::cin is overloaded with respect to linkedString.

int getLength()
It simply returns the length of linkedString.

bool find(const linkedString& str)
To search a linkedString in other linkedString, this function is called. The way it works is, it has three different cases.
First case is it checks if the this.linkedString is greater than linkedString &str, it searches str in this.linkedString.
Seconldy, if it finds out this.linkedString is less than the lenght of &str, then it searches this.linkedString in inputted string str.
And thirdly, if both have the same length.

bool find(const string& str)
It works similiar to bool find(const linkedString& str), but in this function parameter is of type string.

linkedString findAndCopy(const string& str)
 
linkedString findAndCut(const string& str)
 
 void reverse()
 It reverses the complete linkedlist.
 
 void printRecursive(node* curr)
 This function just prints the linkedString in reverse, but does not reverses the linkedString. The linkedString remains unchanged.
 
//TODO
 
void findAndReplace (const string& str1, const string& str2); // TODO
void findAndInsertAfter(const string& ,const string&); // TODO
void findAndInvert(const string&); // TODO
