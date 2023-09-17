#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node* next;
};

//function to create new node
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp!=NULL){
        temp->data = data;
        temp->next =NULL;
    }
    return temp;
}

//insert at head fucntion
void insertAtHead(struct Node** head,int data){
    struct Node* newNode = createNode(data);
    if(newNode!=NULL){
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtPos(struct Node** head,int element,int position){
    if(position<0)
        printf("Position can't be negative.\n");
    else if(*head == NULL){
        if(position == 0)
            insertAtHead(head,element);
        else    
            printf("Node can't be inserted in EMPTY LIST.\n");
    }
    else if(position == 1){
        struct Node* newNode = createNode(element);
        if(newNode!=NULL){
            newNode->next = (*head)->next;
            (*head)->next = newNode;
        }
    }
    
    else if(position == 0 && *head != NULL)
        insertAtHead(head,element);
    
    else{
        int count = 0;
        struct Node* newNode = createNode(element);
        struct Node* temp = *head;
        while(temp!=NULL && count<position-1){
            temp = temp->next;
            count++;
        }
        if(count == position-1 && temp!=NULL){
            struct Node* NEXT = temp->next;
            temp->next = newNode;
            newNode->next = NEXT;
        }
        else{
            printf("***LIST TOO SHORT***.\n");
        }
        
    }
}

bool element_exit(struct Node** head,int element){
    struct Node* temp = *head;
    while(temp != NULL){
        if(temp->data == element)
            return true;
        temp = temp->next;
    }
    return false;
}

void insertAtEnd(struct Node** head,int data){
    if(*head == NULL)
        insertAtHead(head,data);
    else{
        struct Node* temp = *head;
        struct Node* newNode = createNode(data);
        if(newNode!=NULL){
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
    }
}

void deleteHead(struct Node** head){
    if(*head==NULL)
        printf("***EMPTY LIST***\n");
    else{
        struct Node* del = *head;
        *head = (*head)->next;
        free(del);
    }

}



void print(struct Node** head){
    if(*head == NULL){
        printf("List is empty\n\n");
    }
    struct Node* temp = *head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    struct Node* head = NULL;
    deleteHead(&head);
    insertAtPos(&head,55,1);
    insertAtEnd(&head,4);
    print(&head);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    insertAtEnd(&head,7);
    insertAtEnd(&head,8);
    insertAtHead(&head,1);
    // insertAtHead(&head,0);
    // insertAtHead(&head,7);
    // insertAtHead(&head,2);
    // insertAtHead(&head,1);
    printf("\nAfter Inserting at pos.\n");
    print(&head);
    insertAtPos(&head,121,8);
    print(&head);
    deleteHead(&head);
    printf("\nAfter DELETE\n");
    print(&head);

    return 0;
}