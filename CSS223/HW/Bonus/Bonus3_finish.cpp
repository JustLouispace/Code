#include <iostream>

using namespace std;

class Node{ 
    public:
        string name;
        int element;
        Node* next;
        Node* prev;
    
       
};



void push(Node **head_ref ,string name, int score){
        Node *temp = new Node();
        temp->element = score;
        temp->name = name;
        temp->next = (*head_ref);
        temp->prev = NULL;

        if ((*head_ref) != NULL)
        {
            (*head_ref)->prev = temp;
        }
        
        (*head_ref)= temp;
    }

void print(Node* node){
        Node *last;
        cout<<"-----------SCOREBORAD Top 10-----------"<<endl;
        while (node != NULL)
        {
            cout<<"Name : "<<node->name <<"\t Score : "<< node->element<<endl;
            last = node;
            node = node->next;
        }


}

void sorting(Node **head_ref, Node *head) {
    Node * temphead = *head_ref;
	int tempscore;
	string tempname;
	int counter = 0;
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	    temphead = head;
	
	for (int j=0; j<counter; j++)
	{
		while (temphead->next)
		{
			if (temphead->element < temphead->next->element)
			{
				    
                tempscore = temphead->element;
				temphead->element = temphead->next->element;
				temphead->next->element = tempscore;

                tempname = temphead->name;
				temphead->name = temphead->next->name;
				temphead->next->name = tempname;
				temphead = temphead->next;

			}
            else{
			    temphead = temphead->next;
                }
		}	
		temphead = head;
	}
}


void pop(Node **head_ref) {
        Node *last = *head_ref;
        while (last->next != NULL)
        {
            last->prev = last ;
            last = last->next;
            
        }
        last->prev->next = NULL; 
};

void removeall(Node *head){
    Node *temp = head;
    while (head)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    cout << "all node delect"<< endl;
        
};

void datainsert(string name, int insert, Node **head_ref, Node *head){
    cout << "\n-----------------UPDATE----------------" <<endl;
    push(&head, name, insert);
    sorting(&head, head);
    pop(&head);
    print(head);

};

int main(){
    Node * head = NULL;
    string name[10] = {"LUFFY", "ACE", "LAW", "SHANKS", "SANJI", "ZORO", "ROBIN", "USOPP", "NAMI", "FRANKY"};
    int score[10] = {44, 57, 61, 64, 59, 50, 83, 56, 61, 72};

    for(int i = 0; i < 10; i++){
       push(&head, name[i], score[i]);
    }
    sorting(&head, head);
    print(head);

    // insert data
    datainsert("Tong", 90, &head, head);
    removeall(head);

    return 0;
};
