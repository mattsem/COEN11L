

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 


//declare struct

typedef struct reservations{
	char names[20];
	int size;
	struct reservations *next;
}RESERVATIONS;





RESERVATIONS *head = NULL;
RESERVATIONS *tail = NULL;

//prototype methods 



void insert(void);
void fillSeats(void);
void list(void);
void searchSize(void);
int duplicate(char*);



int main(){
	
	int answer;

//print menu

	while(1){
		printf("\n");
		printf("1: Add reservation \n");
		printf("2: Open seats \n");
		printf("3: list reservations \n");
		printf("4: search size \n");
		printf("0: Quit \n");
		printf("Enter a command \n");
		scanf("%d", &answer);
	
//choose options	
		switch(answer){
			case 1:
				insert();
				break;
			case 2:
				fillSeats();
				break;
			case 3: 

				list();
				break;
			case 4:
				searchSize();
				break;
			case 0:
				return 0;
			default:
				printf("invalid entry \n");
				break;	

		}



	}



	return 0;


}




void insert(void){
	
//add info to array
	
	RESERVATIONS *p;
	
	
	
	char name[20];
	int size;
	

	printf("enter name: \n");
	
	scanf("%s",name);
	if(duplicate(name)){
		printf("already taken");
		return;
	}
	
	printf("enter size of party \n");
	scanf("%d",&size);
	
		
	
	//if 0 members entered display an error

	if(size == 0){
		printf("invalid size");
		return;
	}






	if((p= (RESERVATIONS*) malloc(sizeof(RESERVATIONS))) == NULL){
		printf("malloc error\n");
		exit(1);
	}
	if(head == NULL){
		head = p;
		tail = p;
	}
	else{
		tail->next = p;
		tail = p;
	}
	
	
	p->size = size;
	strcpy(p->names,name);
	p->next = NULL;

	






}




//ask how many seats to fill

void fillSeats(void){
	int open,i,j,flag = 0;
	printf("how many open seats? \n");
	scanf("%d",&open);
	
	
	RESERVATIONS *p = head;
	RESERVATIONS *q = head;

//if open seats fill them

	if(head == NULL)
		return;

	while(q!=NULL){
		if(open >= q->size){
			if(head == tail ){
				head = NULL;
				tail = NULL;
				flag = 1;
				open = open - p->size; 
				free(p);
				return;		
			}
		
			else if(head == q){
				printf("reservation deleted %s \n", head->names);
				flag = 1;
				open = open - q->size;
				head = q->next;
				
				free(q);
				p = head;
				q = head;
			
			}
			
			
			else if(q == tail){
				
					printf("reservation deleted %s \n",q->names);
					flag = 1;
					open = open - q->size;				
					tail=p;
					p->next = NULL;
					free(q);
					return;
					
			}
		
			else{
				p->next = q->next;
				printf("reservation deleted %s \n",q->names );
				open = open - q->size;
				flag = 1;
				free(q);
				q = p->next;
			}
		}
		else{
			p=q;
			q = q->next;
			
		}
		
	}
	
	if(flag == 0)
		printf("no open tables");
}







void list(void){
	int i , x;
	RESERVATIONS *p = head;

//traverse array and print out
	if(head == NULL)
		printf("no reservations \n");
	while(p!=NULL){
		x=0;


//print the pointers word
		while(p->names[x] != '\0'){
			printf("%c",p->names[x]);
			x++;
		}
		printf(": %d \n",p->size);
		p=p->next;
	}

}








void searchSize(void){

	int answer,i,flag=0;
//set pointer
	RESERVATIONS *p = head;

	printf("Enter a number \n");
	scanf("%d",&answer);

//traverse and search for num
	
	while(p != NULL){
		if(p->size <= answer){
			printf("%s : %d \n" ,p->names,p->size );
			flag = 1;
		}
		p= p->next;
	}
	
	if(flag == 0){
		printf("No reservations");
	}


}
	
//check for duplicates


	
int duplicate(char *c){
	RESERVATIONS *p = head;
	int i;	


//compare the pointers
	while(p != NULL){
		if(strcmp(c,p->names)==0)
			return 1;

		p =p->next;
	}

	return 0;



}




