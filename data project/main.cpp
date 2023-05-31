#include <iostream>
#include <string>
using namespace std;
class node{
public:
    string name,id,gender,type;
    int age;
    node *next,*prev;

    node(string name,string id,string gender,string type, int age){
        this->name=name;
        this->id=id;
        this->gender=gender;
        this->type=type;
        this->age=age;
        this->next=NULL;
        this->prev=NULL;
    }
};
class linkedlist{
public:
    node *head;
    int ListSize;
    linkedlist(){
        head=NULL;
        ListSize=0;
    }
    void traversal(){
        node *temp=head;
        cout<<"List elements are: "<<endl;
        while(temp!=NULL){
           cout<<temp->name<<" "<<temp->id<<" "<<temp->gender<<" "<<temp->type<<" "<<temp->age<<endl;
            temp=temp->next;
        }
    }
    void AddBeg(string name,string id,string gender,string type, int age){
        node* new_node=new node(name, id, gender, type,  age);
        if(head==NULL){
            head=new_node;
            return;
        }
        else{
            new_node->next=head;
            head=new_node;
        }
        ListSize++;
    }
    void AddEnd(string name,string id,string gender,string type, int age){
        node*new_node=new node(name, id, gender, type,  age);
        if(head==NULL){
            head=new_node;
            return;
        }
        else{
            node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new_node;
            new_node->next=NULL;
            ListSize++;
        }
    }
    void AddAfter(string name,string id,string gender,string type, int age,int pos){
        int counter=0;
        node*new_node=new node(name, id, gender, type,  age);
        node*temp=head;
        if(pos==ListSize){
            this->AddEnd(name, id, gender, type,  age);
            return;
        }
        while(counter<ListSize){
            if(counter==pos){
                new_node->next=temp->next;
                temp->next=new_node;
                break;
            }
            temp=temp->next;
            counter++;
        }
        ListSize++;
    }
    void delete_from_beggin(){
        if(head==NULL){
            cout<<"Linked list is empty"<<endl;
        }
        head = head->next;
    }

    void delete_from_end(){
        if(head==NULL){
            cout<<"Linked list is empty"<<endl;
        }
         node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
    }
    void delete_from_position(int position){
        node *temp=head;
        if(head==NULL){
            return;
        }
        for(int i=0; i< position-1; i++) {

                temp = temp->next;

        }

        temp->next = temp->next->next;
    }
    bool searchNode(  string key) {
         node* current =head;

        while (current != NULL) {
            if (current->name==key || current->id==key ){ return true;

            }
            current = current->next;
        }
        return false;
    }
    void sortlist(){
        node *current=head,*next_node=NULL;
        string temp;
        if(head==NULL){
            cout<<"linked list is empty"<<endl;
            return;
        }
        else{

            while(current!=NULL){
                next_node=current->next;

                while(next_node!=NULL){
                    if(current->id>next_node->id){
                        temp=current->id;
                        current->id=next_node->id;
                        next_node->id=temp;
                    }
                    next_node=next_node->next;
                }
                current=current->next;
            }
        }

    }
    void update(string oldname,string oldid,string oldgender,string oldtype, int oldage ,string new_name,string new_id,string new_gender,string new_type,int new_age) {
        node *current = head;
        if (head == NULL) {
            cout << "linked list is empty" << endl;
            return;
        }
            while (current != NULL) {
                if (current->name == oldname || current->id == oldid || current->gender == oldgender ||
                    current->type == oldtype || current->age == oldage) {
                    //to find the node containing the data required to be updated(old)
                    current->name = new_name;
                    current->id = new_id;
                    current->gender = new_gender;
                    current->type = new_type;
                    current->age = new_age;
                    return;
                }
                if (current->next != NULL) {
                    current = current->next;
                } else {
                    break;
                }
            }


             cout  << "The entered information does not exist in the list"<<endl;

    }

};
class Stack {
    node* top;

public:
    Stack() { top = NULL; }

    void push(string name,string id,string gender,string type, int age)
    {
        node* temp = new node(name, id, gender, type,  age);

        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }

        temp->name = name;
        temp->id=id;
        temp->gender=gender;
        temp->type=type;
        temp->age=age;
        temp->next = top;

        top = temp;

    }

    bool isEmpty()
    {
        if(top==NULL){

        return true;
        }
        else{
            return false;
        }

    }


    int peek()
    {

        if (!isEmpty())
            return top->name ,top->id,top->gender,top->type,top->age;
        else
            exit(1);
    }


    void pop()
    {

        node* temp;

        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            temp = top;
            top = top->next;


            free(temp);
        }
    }

    void display()
    {
        node* temp;

        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {


                cout<<temp->name<<" "<<temp->id<<" "<<temp->gender<<" "<<temp->type<<" "<<temp->age<<endl;


                temp = temp->next;
                if (temp != NULL)
                    cout << " -> ";
            }
        }

    }
};

int main(){
Stack s;
linkedlist *l=new linkedlist();
int x;
    string name, id, gender, type;string res;
    int age;

        do {
            cout << "***************W E L C O M E***************" << endl;
            cout << "Diabetes Analysis Software" << endl;
            cout << "Please enter 1 to insert a new node at the beginning" << endl;
            cout << "Please enter 2 to insert a new node after a certain position" << endl;
            cout << "Please enter 3 to insert a new node at the end" << endl;
            cout << "Please enter 4 to delete a node at the beginning" << endl;
            cout << "Please enter 5 to delete a  node after certain position" << endl;
            cout << "Please enter 6 to delete a  node at the end" << endl;
            cout << "Please enter 7 to search a  node at the linked list" << endl;
            cout << "Please enter 8 to sort the linked list" << endl;
            cout << "Please enter 9 to update a  node" << endl;
            cout << "Please enter 10 to display all information saved" << endl;
            cout << "Please enter 11 to implement the linked list as a stack" << endl;
            cout <<"Exit: enter 12 "<<endl;
            cin >> x;


            switch (x) {
                case 1: {

                    cout << "Please enter your name " << endl;
                    cin >> name;
                    cout << "Please enter your id " << endl;
                    cin >> id;
                    cout << "Please enter your gender(Female/Male) " << endl;
                    cin >> gender;
                    cout << "Please enter your type (onr/two/three)" << endl;
                    cin >> type;
                    cout << "Please enter your age " << endl;
                    cin >> age;
                    l->AddBeg(name, id, gender, type, age);;
                    break;
                }
                case 2: {
                    cout << "Please enter your name " << endl;
                    cin >> name;
                    cout << "Please enter your id " << endl;
                    cin >> id;
                    cout << "Please enter your gender(Female/Male) " << endl;
                    cin >> gender;
                    cout << "Please enter your type (onr/two/three)" << endl;
                    cin >> type;
                    cout << "Please enter your age " << endl;
                    cin >> age;
                    cout << "Please enter the position that you want the node to be inserted after" << endl;
                    int pos;
                    cin >> pos;

                    l->AddAfter(name, id, gender, type, age, pos);
                    break;
                }
                case 3: {
                    cout << "Please enter your name " << endl;
                    cin >> name;
                    cout << "Please enter your id " << endl;
                    cin >> id;
                    cout << "Please enter your gender(Female/Male) " << endl;
                    cin >> gender;
                    cout << "Please enter your type (onr/two/three)" << endl;
                    cin >> type;
                    cout << "Please enter your age " << endl;
                    cin >> age;
                    l->AddEnd(name, id, gender, type, age);
                    break;
                }
                case 4: {
                    l->delete_from_beggin();
                    break;
                }
                case 5: {
                    cout << "Please enter the position that you want the node to be deleted from" << endl;
                    int pos;
                    cin>>pos;
                    l->delete_from_position(pos);
                    break;
                }
                case 6: {
                    l->delete_from_end();
                }
                    break;
                case 7: {
                    cout << "Please enter the name or the id that you want to be searched" << endl;
                    string name_or_id;
                    cin >> name_or_id;
                    cout<<l->searchNode(name_or_id)<<endl;
                    break;
                }

                case 8: {
                    l->sortlist();
                    l->traversal();
                    break;
                }
                case 9: {
                    cout << "Please enter the information required to be updated" << endl;
                    cout << "Please enter old name " << endl;
                    cin >> name;
                    cout << "Please enter old id " << endl;
                    cin >> id;
                    cout << "Please enter old gender(Female/Male) " << endl;
                    cin >> gender;
                    cout << "Please enter old type " << endl;
                    cin >> type;
                    cout << "Please enter old age " << endl;
                    cin >> age;
                    string new_name, new_id, new_gender, new_type;
                    int new_age;
                    cout << "Please enter the new information" << endl;
                    cout << "Please enter new name " << endl;
                    cin >> new_name;
                    cout << "Please enter new id " << endl;
                    cin >> new_id;
                    cout << "Please enter new gender(Female/Male) " << endl;
                    cin >> new_gender;
                    cout << "Please enter new type " << endl;
                    cin >> new_type;
                    cout << "Please enter new age " << endl;
                    cin >> new_age;
                    l->update(name, id, gender, type, age, new_name, new_id, new_gender, new_type, new_age);
                    l->traversal();
                    break;
                }
                case 10: {
                    l->traversal();
                    break;
                }
                case 11:{
                    int x;
                  cout<<"         Please choose one from below options...."<<endl;
                  cout<<"1.Push\n2.Pop\n3.Display\n4.Display whether empty or not\n5.Exit"<<endl;
                  cout<<"         Enter your choice"<<endl;cin>>x;
                 switch(x) {
                     case 1: {
                         s.push(name, id, gender, type, age);
                         break;
                     }

                     case 2: {
                         s.pop();
                         break;
                     }
                     case 3:{
                         s.display();
                         break;
                     }
                     case 4:{
                         cout<<s.isEmpty()<<endl;
                     break;
                     }
                     default:{
                         break;
                     }

                 }

                }
                default: {
                    break;
                }

            }

            cout<<"If you want to continue enter yes"<<endl;
            cin>>res;
        }while(res=="yes");




 return 0;
}