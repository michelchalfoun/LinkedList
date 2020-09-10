#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node
{
public:
    string data;
    Node* next;
    Node* prev;
    Node();
    Node(string text, Node* next, Node* prev);
};

Node::Node()
{
    data = "";
    next = nullptr;
    prev = nullptr;
}

Node::Node(string text, Node* nextNode, Node* prevNode)
{
    data = text;
    next = nextNode;
    prev = prevNode;
}

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList();
    LinkedList(Node* headNode, Node* tailNode);
    void insertEnd(string text);
    void insertAtLine(int line, string text);
    void deleteLine(int line);
    void editLine(int line, string text);
    void printLines();
    void search(string text);
    int getSize();
};

LinkedList::LinkedList()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(Node* headNode, Node* tailNode)
{
    size = 0;
    head = headNode;
    tail = tailNode;
}

// Takes care of adding node at the end of the list AND adding to empty list
void LinkedList::insertEnd(string text)
{
    Node* newNode = new Node(text, nullptr, nullptr);
    if (size == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void LinkedList::insertAtLine(int line, string text)
{
    Node* curNode = head;

    // Loops until needed node is reached
    for (int i = 2; i < (line + 1); i++)
    {
        curNode = curNode->next;
    }

    // Handles the edge case where the list is initially empty
    if (size == 0)
    {
        if (line == 1)
        {
            insertEnd(text);
        }
    }
    else if (line <= (size + 1))
    {

        // Takes care of updating the head node in case the node was added to the start of the list.
        if (line == 1)
        {
            Node *newNode = new Node(text, head, nullptr);
            head->prev = newNode;
            head = newNode;
            size++;
        }
        else if (line == (size + 1))
        {
            insertEnd(text);
        }
        else
        {
            Node *newNode = new Node(text, curNode, curNode->prev);
            curNode->prev->next = newNode;
            curNode->prev = newNode;
            size++;
        }
    }
}

void LinkedList::deleteLine(int line)
{
    Node* curNode = head;
    for (int i = 2; i < (line + 1); i++)
    {
        curNode = curNode->next;
    }

    // Distinguishes between deleting edge nodes and other nodes.
    if(line == 1)
    {
        curNode->next->prev = nullptr;
        head = curNode->next;
        delete curNode;
        size--;
    }
    else if (line == size)
    {
        curNode->prev->next = nullptr;
        tail = curNode->prev;
        delete curNode;
        size--;
    }
    else if ((line > 1) && (line < size))
    {
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        delete curNode;
        size--;
    }
}

// Edit uses delete and insert to remove redundancy
void LinkedList::editLine(int line, string text)
{
    deleteLine(line);
    insertAtLine(line,text);
}

// Loops through each node and prints the line number and data
void LinkedList::printLines()
{
    Node* curNode = head;
    for (int i = 1; i < (size + 1); i++)
    {
        cout << i << " " << curNode->data << endl;
        curNode = curNode->next;
    }
}

void LinkedList::search(string text)
{
    Node* curNode = head;
    bool found = false;

    // Calculates number of 80-character strings in search term
    int parts = (text.size() / 80) + 1;

    //Distinguishes between smaller than 80 character strings and more
    if (parts == 1)
    {
        for (int i = 1; i < (size + 1); i++)
        {
            if (curNode->data.find(text) != string::npos)
            {
                cout << i << " " << curNode->data << endl;
                found = true;
            }
            curNode = curNode->next;
        }
    }
    else
    {
        for (int i = 0; i < (size + 1 - parts); i++)
        {
            // Merges string in lines to search multiple lines at once
            Node* tempNode = curNode;
            string mergedData;
            for (int j = 0; j < parts; j++)
            {
                mergedData += tempNode->data;
                tempNode = tempNode->next;
            }

            // Use a temporary node to print lines and not change current ode placement
            tempNode = curNode;
            if (mergedData.find(text) != string::npos)
            {
                found = true;
                for (int j = 0; j < parts; j++)
                {
                    cout << (i + j + 1) << " " << tempNode->data << endl;
                    tempNode = tempNode->next;
                }
                if (tempNode != nullptr)
                {
                    tempNode = tempNode->prev;
                }
            }

            // Handles end nodes
            if ((tempNode == tail) or (tempNode == nullptr))
            {
                break;
            }
            else
            {
                curNode = curNode->next;
            }
        }
    }

    if (!found)
    {
        cout << "not found" << endl;
    }
}

// Accessor to get the size of the list
int LinkedList::getSize()
{
    return size;
}

int main()
{

    string input;
    string inputFunction;
    string inputLineString;
    int inputLine;
    string inputText;
    LinkedList list;
    bool quit = false;

    while(!quit)
    {
        getline(cin, input);

        // Extracts function from string
        stringstream inputStream(input);
        inputStream >> inputFunction;

        if (inputFunction == "print")
        {
            list.printLines();
        }
        else if (inputFunction == "insertEnd")
        {
            // Extracts text from the text that was input
            getline(inputStream, inputText);
            if (inputText.size() > 3)
            {
                inputText = inputText.substr(2, inputText.size() - 3);
                if (inputText.size() <= 80)
                {
                    list.insertEnd(inputText);
                }
                else
                {
                    int splits = inputText.size() / 80;
                    for (int i = 0; i < (splits + 1); i++)
                    {
                        list.insertEnd(inputText.substr(i * 80, 80));
                    }
                }
            }
        }
        else if (inputFunction == "insert")
        {
            inputStream >> inputLineString;
            inputLine = stoi(inputLineString);
            getline(inputStream, inputText);

            if (inputText.size() > 3)
            {
                inputText = inputText.substr(2, inputText.size() - 3);
                if (inputText.size() <= 80)
                {
                    list.insertAtLine(inputLine, inputText);
                }
                else
                {
                    int splits = inputText.size() / 80;
                    if (list.getSize() == 0)
                    {
                        for (int i = 0; i < (splits + 1); i++)
                        {
                            list.insertEnd(inputText.substr(i * 80, 80));
                        }
                    }
                    else
                    {
                        for (int i = 0; i < (splits + 1); i++)
                        {
                            // Inserts parts by moving 1 node up every insertion
                            list.insertAtLine(inputLine + i, inputText.substr(i * 80, 80));
                        }
                    }
                }
            }
        }
        else if (inputFunction == "delete")
        {
            inputStream >> inputLineString;
            inputLine = stoi(inputLineString);
            list.deleteLine(inputLine);
        }
        else if (inputFunction == "search")
        {
            getline(inputStream, inputText);
            if (inputText.size() > 3){
                inputText = inputText.substr(2, inputText.size() - 3);
                list.search(inputText);
            }else{
                cout << "not found" << endl;
            }
        }
        else if (inputFunction == "edit")
        {
            inputStream >> inputLineString;
            inputLine = stoi(inputLineString);
            getline(inputStream, inputText);
            inputText = inputText.substr(2, inputText.size() - 3);
            if (inputText.size() <= 80)
            {
                list.editLine(inputLine, inputText);
            }
            else
            {
                int splits = div(inputText.size(), 80).quot;
                for (int i = 0; i < (splits + 1); i++)
                {
                    // The node is edited first, then other nodes are created after it
                    if (i == 0)
                    {
                        list.editLine(inputLine, inputText.substr(0, 80));
                    }
                    else
                    {
                        if (inputLine == list.getSize())
                        {
                            list.insertEnd(inputText.substr(i * 80, 80));
                        }
                        else
                        {
                            list.insertAtLine(inputLine + i, inputText.substr(i * 80, 80));
                        }
                    }
                }
            }
            list.editLine(inputLine, inputText);
        }
        else if (inputFunction == "quit")
        {
            quit = true;
        }
    }
    return 0;
}