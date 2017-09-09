#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <deque>
#include <complex>
#include <string>
#include <sstream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::setw;

void sort(int[], const int, bool(*)(int, int));
void swap(int * const, int * const);
bool ascending(int, int);
bool descending(int, int);
void primeNumGen(int cnt);
int check_prime(int a);
void insertNode(struct Node** ptr_head, struct Node* new_node);
struct Node *newNode(int new_data);
void printList(struct Node *headNode);
void deleteNode(struct Node** ptr_head, int value);
const char mystr[] = { "Was it a car or a cat I saw" };
void myString(const std::string& in);
int anagram(char str1[], char str2[]);


struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    const int arraySize = 16;
    int order = 1;
    int ctr;
    int iArray[arraySize] = { 27,75,2,676,333,6,99,106,11,46,9,756,29,255,5,234};
    struct Node* headNode = NULL;
    struct Node *new_node = NULL;
    complex <double> cx1;
    string  input = "";

    while (order >= 1)
    {
        cout << "Enter 1 to sort ascending, \n" << "Enter 2 to sort in decending order,\n";
        cout << "Enter 3 to generate prime numbers, \n" << "Enter 4 to check if integer is prime,\n";
        cout << "Enter 5 to create sorted linked list, \n" << "Enter 6 to insert node in linked list,\n";
        cout << "Enter 7 to delete node in linked list, \n" << "Enter 8 for reverse string, \n";
        cout << "Enter 9 for complex number operations, \n" << "Enter 10 for anagram check: ";
        while (true) 
        {
            getline(cin, input);
            // convert from string to number safely.
            stringstream myStream(input);
            if (myStream >> order)
                break;
            else
                cout << endl << "Enter number. Number not supported exits:  ";
        }
        switch (order)
        {
            case 1:
                cout << "\nData items before sort: \n";

                for (ctr = 0; ctr < arraySize; ctr++)
                    cout << setw(4) << iArray[ctr];

                sort(iArray, arraySize, ascending);
                cout << "\nSorted in ascending order\n";
                for (ctr = 0; ctr < arraySize; ctr++)
                    cout << setw(4) << iArray[ctr];
                cout << endl << endl;
                break;
            case 2:
 
                cout << "\nData items before sort: \n";

                for (ctr = 0; ctr < arraySize; ctr++)
                    cout << setw(4) << iArray[ctr];

                sort(iArray, arraySize, descending);
                cout << "\nSorted in descending order\n";
                for (ctr = 0; ctr < arraySize; ctr++)
                    cout << setw(4) << iArray[ctr];
                cout << endl << endl;

                break;

            case 3:

                int count;
                cout << "\nEnter the number of prime numbers to generate (1 - 199): ";
                cin >> count;
                if (count && (count < 200)) 
                {
                    primeNumGen(count);
                    cout << endl << endl;
                }
                else
                    cout << "\nEnter prime number count between 0 - 199\n\n";

                break;

            case 4:

                int num, result;

                cout << "\nEnter an integer to check whether it is prime or not: ";
                cin >>num;

                result = check_prime(num);

                if (result == 1)
                    cout << num <<" is prime.\n\n" ;
                else
                    cout << num << " is not prime.\n\n";
                break;

            case 5:
                if (headNode == nullptr) 
                {
                    new_node = newNode(7);
                    insertNode(&headNode, new_node);
                    new_node = newNode(16);
                    insertNode(&headNode, new_node);
                    new_node = newNode(47);
                    insertNode(&headNode, new_node);
                    new_node = newNode(3);
                    insertNode(&headNode, new_node);
                    new_node = newNode(14);
                    insertNode(&headNode, new_node);
                    new_node = newNode(64);
                    insertNode(&headNode, new_node);
                    new_node = newNode(8);
                    insertNode(&headNode, new_node);
                    new_node = newNode(24);
                    insertNode(&headNode, new_node);
                    new_node = newNode(256);
                    insertNode(&headNode, new_node);
                    new_node = newNode(17);
                    insertNode(&headNode, new_node);
                    new_node = newNode(9);
                    insertNode(&headNode, new_node);
                    cout << "\nCreated Linked List\n";
                }
                else
                    cout << "\nCurrent sorted linked list: \n";

                printList(headNode);
                break;

            case 6:
                if (headNode == nullptr)
                    cout << "\nCreate Linked List first!\n";
                else
                {
                    int insert_node;
                    cout << "\nSelect node to insert:  ";
                    cin >> insert_node;
                    new_node = newNode(insert_node);
                    insertNode(&headNode, new_node);
                    printList(headNode);
                    cout << endl;
                }
                break;
            case 7:
                if (headNode == nullptr)
                    cout << "\nCreate Linked List first!\n";
                else
                {
                    int delNode;
                    cout << "\nSelect node to delete:  ";
                    cin >> delNode;
                    deleteNode(&headNode, delNode);
                    printList(headNode);
                    cout << endl;
                }
                break;
            case 8:
                cout << "\nString before reverse:  " << mystr << endl;
                cout << "\nString after reverse:  " ;
                myString(mystr);

                break;
            case 9:
            {
                double a, b, x, y;
                cout << "\nEnter complex numbers: 4 floats with spaces between, then enter  : " << endl;
                cin >> a >> b >> x >> y ;
                cout << "First Number: " << a << " + " << b << "i  " << endl;
                cout << "Second Number:  " << x << " + " << y << "i  " << endl;
                complex <double> cx1(a, b);
                complex <double> cx2(x, y);

                complex <double> cs1 = cx1 + cx2;
                cout << "The sum of the two complex numbers is:  " << cs1.real() << " + " << cs1.imag() <<"i" << endl;
                cs1 = cx1 * cx2;
                cout << "The product of the two complex numbers is:  " << cs1.real() << " + " << cs1.imag() << "i" << endl;
                cs1 = cx1 - cx2;
                cout << "The difference of the two complex numbers is:  " << cs1.real() << " + " << cs1.imag() << "i" << endl;
                cs1 = cx1 / cx2;
                cout << "The quotient of the two complex numbers is:  " << cs1.real() << " + " << cs1.imag() << "i" << endl << endl;
            }
                break;
            case 10:
            {
                char str1[32] = { "Listen" };
                char str2[32] = { "silent" };
                char str3[32] = { "triangle" };
                char str4[32] = { "integral" };
                int iFlag;

                iFlag = anagram(str1, str2);

                if (iFlag == 1)
                    cout << endl << str1 << " and " << str2 << " are anagrams. " << endl;
                else
                    cout << str1 << " and " << str2 << " are not anagrams. " << endl;

                iFlag = anagram(str1, str3);

                if (iFlag == 1)
                    cout << str1 << " and " << str3 << " are anagrams. " << endl;
                else
                    cout << str1 << " and " << str3 << " are not anagrams. " << endl;

                iFlag = anagram(str1, str4);

                if (iFlag == 1)
                    cout << str1 << " and " << str4 << " are anagrams. " << endl;
                else
                    cout << str1 << " and " << str4 << " are not anagrams. " << endl;

                iFlag = anagram(str2, str3);

                if (iFlag == 1)
                    cout << str2 << " and " << str3 << " are anagrams. " << endl;
                else
                    cout << str2 << " and " << str3 << " are not anagrams. " << endl;

                iFlag = anagram(str3, str4);

                if (iFlag == 1)
                    cout << str3 << " and " << str4 << " are anagrams. " << endl;
                else
                    cout << str3 << " and " << str4 << " are not anagrams." << endl;
                cout << endl;

                break;
            }
            default:
 
                return 0;
        } //switch
    }// while
    return 0;
}

void sort(int i_array[], const int size, bool(*func_ptr)(int, int))
{
    int compare2Nums;
    for (int i = 0; i < size; i++)
    {
        compare2Nums = i;
        for (int index = i + 1; index < size; index++)
            if (!(*func_ptr)(i_array[compare2Nums], i_array[index]))
                compare2Nums = index;

        swap(&i_array[compare2Nums], &i_array[i]);
    }
}

void swap(int * const num1, int * const num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
bool ascending(int x, int y ) 
{
    return x < y;
}
bool descending(int x, int y) 
{
    return x > y;
}
void primeNumGen(int cnt) {
    int n, i = 3, count, c;

    n = cnt;

    if (n >= 1)
    {
        cout << "First " << n <<" prime numbers are :\n";
        cout << "2  ";
    }

    for (count = 2; count <= n; )
    {
        for (c = 2; c <= i - 1; c++)
        {
            if (i%c == 0)
                break;
        }
        if (c == i)
        {
            if (!(count % 10))
                cout << i << "\n";
            else
                cout << i << "  ";

            count++;
        }
        i++;
    }
}

int check_prime(int a)
{
    int c;

    for (c = 2; c <= a - 1; c++)
    {
        if (a%c == 0)
            return 0;
    }
    if (c == a)
        return 1;
}

//Linked list functions
void insertNode(struct Node** ptr_head, struct Node* new_node)
{

    //empty list                //new headNode 
    if (*ptr_head == NULL || (*ptr_head)->data >= new_node->data)
    {
        new_node->next = *ptr_head; //assigns pointer to old head node, in new node next element, or stays Null if first in empty list
        *ptr_head = new_node;  //makes new node the new head - passed by ref
    }
    else
    {
        struct Node* current;
        // Locate the node before the point of insertion 
        current = *ptr_head;
        while ((current->next != NULL) && (current->next->data < new_node->data)) //is new node data greater than next node data?
        {
            current = current->next;  //keep looking. Not the last node, and greater than next node data
        }

        //either last node, or insert position
        new_node->next = current->next;   //current next pointer to new node, which was NUL
        current->next = new_node;         //Pointer to new node struc goes in current node "next" element
    }
}

struct Node *newNode(int new_data)
{
    // allocate node 
    struct Node* new_Node =
        (struct Node*) malloc(sizeof(struct Node));

    // Insert date in node, null ptr
    new_Node->data = new_data;
    new_Node->next = NULL;

    return new_Node;
}

void printList(struct Node *headNode)
{
    struct Node *temp = headNode;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl << endl;
}

void deleteNode(struct Node** ptr_head, int value)
{
    struct Node* current;
    // Locate the node to delete 
    current = *ptr_head;
    while((current->next != NULL) && (current->next->data != value) && (current->data != value)) //is this node to delete?
    {
        current = current->next;  //keep looking. 
    }
    if (current->data == value) //deleting head node
    {
        struct Node *temp = current;
        *ptr_head = temp->next;
        free(temp);
    }
    else if ((current->next != NULL) && (current->next->data == value))
    {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    else
        cout << "Can't find that node" << endl;
}

//reverse string functions
void myString(const std::string& in)
{
    std::istringstream iss(in);
    std::deque<std::string> words;
    std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(),std::front_inserter(words));
    std::copy(std::begin(words), std::end(words), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << endl << endl;
}

//anagram
int anagram(char str1[], char str2[])
{
    int array1[26] = { 0 }, array2[26] = { 0 }, i = 0;

    while (str1[i] != '\0')
    {
        if (str1[i] < 'a')  //Cap check
            str1[i] += 32;
        array1[str1[i] - 'a']++;
        i++;
    }

    i = 0;

    while (str2[i] != '\0')
    {
        if (str2[i] < 'a')  //Cap check
            str2[i] += 32;
        array2[str2[i] - 'a']++;
        i++;
    }

    for (i = 0; i < 26; i++)
    {
        if (array1[i] != array2[i])
            return 0;
    }

    return 1;
}
