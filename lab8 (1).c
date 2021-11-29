

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 


//declare struct

typedef struct reservations{
	char names[20];
	int size;
	struct reservations *next;
}RESERVATIONS;


RESERVATIONS nodeList[4];

RESERVATIONS *headList[4]= {NULL};
RESERVATIONS *tailList[4] = {NULL};



//prototype methods 



void insert(char*,int);
void fillSeats(void);
void list(void);
void searchSize(void);
int duplicate(char*);
void clearNodes(void);
void read_file(char*);
void save_file(char*);
void nameBackwards(char*);
void listBackwards(RESERVATIONS*);
void deleteRec(RESERVATIONS*);

int main(int argc, char *argv[] ){
	
	int answer;



	if(argc  == 1){
		printf("The name of the file is missing \n");
		return 1;
	}
	read_file(argv[1]);



//print menu
	
	

	while(1){
		printf("\n");
		printf("1: Add reservation \n");
		printf("2: Open seats \n");
		printf("3: list reservations \n");
		printf("4: search size \n");
		printf("5: list backwards \n");
		printf("6: names backwards \n");
		printf("0: Quit \n");
		printf("Enter a command \n");
		scanf("%d", &answer);
	
//choose options	
		switch(answer){
			case 1:{
				
				char name[20];
				int size;
		

				printf("enter name: \n");
	
				scanf("%s",name);
				if(duplicate(name)){
					printf("already taken");
					break;
				}
	
				printf("enter size of party \n");
				scanf("%d",&size);
	
		
	
				//if 0 members entered display an error

				if(size == 0){
					printf("invalid size");
					break;
				}

				insert(name,size);
				break;
			}
			case 2:
				fillSeats();
				break;
			case 3: 

				list();
				break;
			case 4:
				searchSize();
				break;
			case 5:
				for(int i = 0; i<4;i++){
					RESERVATIONS *p = headList[i];
					
					listBackwards(p);
					
					
				
				}
				break;

			case 6:
				for(int j = 0; j< 4; j++){
					RESERVATIONS *p = headList[j];
					while(p != NULL){
						nameBackwards(p->names);
						printf(" \n");
						p = p->next;
					}		
				}
				break;
			case 0:
				save_file(argv[1]);
				for(int k = 0; k<4; k++){
					deleteRec(headList[k]);
				}
				return 0;
			default:
				printf("invalid entry \n");
				break;	

		}



	}



	return 0;


}




void insert(char *name, int size){
	
//add info to array
	int listSpot;
	RESERVATIONS *p;
	
	

	if((p= (RESERVATIONS*) malloc(sizeof(RESERVATIONS))) == NULL){
		printf("malloc error\n");
		exit(1);
	}
	
	switch(size){

		case 1 ... 2:
			listSpot = 0;
			break;
	


		case 3 ... 4:
			listSpot = 1;
			break;


		case 5 ... 6:

			listSpot = 2;
			break;

		default:

			listSpot = 3;
			
	}	


	
	if(headList[listSpot] == NULL){
		headList[listSpot] = p;
		tailList[listSpot] = p;
	}
	else{
		tailList[listSpot]->next = p;
		tailList[listSpot] = p;
	}
		
	
	p->size = size;
	strcpy(p->names,name);
	p->next = NULL;

	






}




//ask how many seats to fill

void fillSeats(void){
	int open,i,j,flag = 0, listSpot;
	printf("how many open seats? \n");
	scanf("%d",&open);
	RESERVATIONS *q = headList[0];
	RESERVATIONS *p = headList[0];
	
	switch(open){

		case 1 ... 2:
			listSpot = 0;
			break;
	


		case 3 ... 4:
			listSpot = 1;
			break;


		case 5 ... 6:

			listSpot = 2;
			break;

		default:

			listSpot = 3;
			
	}	


	
int a = 0;
	
//if open seats fill them
	while(a<=listSpot){
		p = headList[a];
		q = headList[a];

		while(q!=NULL){

			if(open >= q->size){
				if(headList[a] == tailList[a]){
					headList[a] = NULL;
					tailList[a] = NULL;
					flag = 1;
					open = open - p->size; 
					free(p);
					q = NULL;
							
				}
		
				else if(headList[a] == q){
					printf("reservation deleted %s \n", headList[a]->names);
					flag = 1;
					open = open - q->size;
					headList[a] = q->next;
					
					free(q);
					p = headList[a];
					q = headList[a];
			
				}
			
			
				else if(q == tailList[a]){
				
						printf("reservation deleted %s \n",q->names);
						flag = 1;
						open = open - q->size;				
						tailList[a]=p;
						p->next = NULL;
						free(q);
						q = NULL;
						
					
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
		a++;
	}
	
	if(flag == 0)
		printf("no open tables");
}







void list(void){
	int i , x, flag;
	int listSpot;
	for(listSpot = 0; listSpot<4;listSpot++){


		RESERVATIONS *p = headList[listSpot];
		while (p!= NULL){	
			printf("%s , %d \n", p->names, p->size);
			p = p->next;
		}
	
	}
//traverse array and print out
	


//print the pointers word
		
	

}








void searchSize(void){

	int answer,i,flag=0, listSpot, lim;
	printf("Enter a number \n");
	scanf("%d",&answer);


		switch(answer){

		case 1 ... 2:
			listSpot = 0;
			break;
	


		case 3 ... 4:
			listSpot = 1;
			break;


		case 5 ... 6:

			listSpot = 2;
			break;

		default:

			listSpot = 3;
			
		}




for(lim = 0; lim<listSpot; lim++){
//set pointer
	RESERVATIONS *p = headList[lim];

//traverse and search for num
	
	while(p != NULL){
		if(p->size <= answer){
			printf("%s : %d \n" ,p->names,p->size );
			flag = 1;
		}
		p= p->next;
	}
	
	
}
	if(flag == 0){
		printf("No reservations");
	}




}
	
//check for duplicates


	
int duplicate(char *c){
	RESERVATIONS *p;
	int i, num;	

	for(num = 0; num<4;num++){
//compare the pointers
		p= headList[num];
		while(p != NULL){
			if(strcmp(c,p->names)==0)
				return 1;

			p =p->next;
		}
	}
	return 0;

	

}

void clearNodes(){
	int a;
	RESERVATIONS *q;
	for(a = 0; a<4; a++){
		if(headList[a]!=NULL){
			RESERVATIONS *p = headList[a];
			q = p->next; 
			while(q != NULL){
				free(p);
				p = q;
				q = q->next;


			}
		}	
	
	}
	return;
}


void read_file(char *fileN){
	char readName[20];
	int readSize;

	FILE *fp;
	
	if((fp = fopen(fileN,"r")) ==  NULL){
		printf("can't open %s\n", fileN);
	
	}
	
	else{
		while(fscanf(fp, "%s%d", readName, &readSize) == 2){
			insert(readName, readSize);
		}  

	fclose(fp);
	}
	


}




void save_file(char *fileN){
	int x;
	FILE *fp;

	RESERVATIONS *p;
	fp = fopen(fileN,"w");

	for(x = 0; x<4; x++){
		p = headList[x];
		while(p != NULL){
			fprintf(fp,"%s \t %d \n", p->names, p->size);
			p = p->next;

		}

	}
	fclose(fp);



}

void listBackwards(RESERVATIONS *p){
	if(p == NULL)
		return;
	else{
		listBackwards(p->next);
		printf("%s, %d \n",p->names, p->size );
	}
}


void nameBackwards(char *p){
	if(*p == '\0')
		return;
	else
		nameBackwards(p+1);
	printf("%c",*p);

}


void deleteRec(RESERVATIONS *p){
	if(p == NULL)
		return;
	else
		deleteRec(p->next);
	free(p);

}

