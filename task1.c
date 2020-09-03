#include <stdio.h>  
#include <stdlib.h> 
//Represent a node of singly linked list  
struct node{  
    char data;  
    struct node *next;  
};      
   
//Represent the head and tail of the singly linked list  
struct node *head, *tail = NULL;  
//insert() will add a new node to the list  
void insert(char*data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data =*data;  
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
}  
   
//display() will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
      
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf(" Nodes of singly linked list: \n");  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%c", current->data);  
        current = current->next;  
    }printf("\n");  
     
}  
void reverse(struct node** head_ref) 
{ 
    struct node* prev   = NULL; 
    struct node* current = *head_ref; 
    struct node* next; 
    while (current != NULL) 
    { 
        next  = current->next;   
        current->next = prev;    
        prev = current; 
        current = next; 
    } 
    *head_ref = prev;
    printf("\nList after reversed\n");
   // display();  
} 

      
int main(int argc, char *argv[]) 
{  
    int i;
    int k;
    char *str;
    char temp;
    if(argc !=2){
        printf("invalid");
        return 1;
    }
   str = argv[1];
  
   int c = 0; 
   while (str[c] != '\0'){ //in order to find length of the strig
       c++;
   }  
   c -= 1;
    
   for(k=0; k<=c; k++)
    {
        insert(&str[k]);
    }
    //Displays the nodes present in the list  
    printf("Link list of each letters of name\n"); 
    display();
    reverse(&head);
    display();// displays the nodes present after reversal
   
    return 0;  
}  
