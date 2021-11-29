



#include <stdio.h>
#include <string.h> 


//declare struct




typedef union extra{
	char birthday_name[20];
	int years;
	float average_age;
}EXTRA;



typedef struct reservations{
	char names[20];
	int size;
	int occasion;
	EXTRA extra_info;
}RESERVATIONS;






RESERVATIONS info[10];
int counter;

//prototype methods 



void insert(void);
void fillSeats(void);
void list(void);
void searchSize(void);
int duplicate(char*);



int main(){
	counter = 0;
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
	
	RESERVATIONS *p = &info[counter];
	EXTRA *e = &p->extra_info;
	char name[20];

	printf("enter name: \n");
	
	scanf("%s",name);
	if(duplicate(name)){
		printf("already taken");
		return;
	}
	else{
		strcpy(p->names,name);
		printf("enter size of party \n");
		scanf("%d",&p->size);
	
	}	
	
	printf("Occasion?");
	scanf("%d",&p->occasion);
	switch(p->occasion){
		case 1:
			printf("Name of Birthday Person? \n");
			scanf("%s",e->birthday_name);
			break;
		case 2:
			printf("How many years? \n");
			scanf("%d",&e->years);
			break;
		default:
			printf("Average age? \n");
			scanf("%f",&e->average_age);
			
	}

//if 0 members entered display an error

	if(p->size == 0){
		p->names[0] = '\0';
		printf("invalid size");
		return;
	}
	counter++;

}




//ask how many seats to fill

void fillSeats(void){
	int open,i,j,flag = 0;
	printf("how many open seats? \n");
	scanf("%d",&open);
	
	struct reservations *p = info;
//if open seats fill them

	for(j=0;j<counter;j++){
		if(open >= p->size){
			
				printf("reservation deleted %s \n",p->names);
				flag = 1;
				open = open - p->size;

				for(i=j;i<counter-1; i++){
//move the reservations to the top				
					(p+i)->size = (p+i+1)->size;
					strcpy((p+i)->names,(p+i+1)->names);
					if((p+i+1)->occasion == 1)
						strcpy((p+i)->extra_info.birthday_name,(p+i+1)->extra_info.birthday_name);
					else if((p+i+1)->occasion == 2)
						(p+i)->extra_info.years = (p+i+1)->extra_info.years;
					else
						(p+i)->extra_info.average_age = (p+i+1)->extra_info.average_age;

					(p+i)->occasion = (p+i+1)->occasion;
									
				
//decrement to fix order
				}
				counter--;
				p--;
				j--;
			
		}
		p++;
	}
	if(flag == 0)
		printf("no open tables");
}







void list(void){
	int i , x;
	RESERVATIONS *p = info;
	EXTRA *e = &p->extra_info; 
//traverse array and print out
	if(counter ==0)
		printf("no reservations \n");
	for(i=0;i<counter;i++){
		x=0;


//print the pointers word
		while(p->names[x] != '\0'){
			printf("%c",p->names[x]);
			x++;
		}
		printf(": %d, %d, ",p->size,p->occasion);
		if(p->occasion ==1)
			printf("%s \n",p->extra_info.birthday_name);
		else if(p->occasion == 2)
			printf("%d \n",p->extra_info.years);
		else
			printf("%f \n", p->extra_info.average_age);
		

					
		p++;
	}



}








void searchSize(void){

	int answer,i,flag=0;
//set pointer
	RESERVATIONS *p = info;

	printf("Enter a number \n");
	scanf("%d",&answer);

//traverse and search for num
	
	for(i=0; i<counter;i++){
		if(p->size <= answer){
			printf("%s : %d \n" ,p->names,p->size );
			flag = 1;
		}
		p++;
	}
	
	if(flag == 0){
		printf("No reservations");
	}


}
	
//check for duplicates

	
int duplicate(char *c){
	RESERVATIONS *p = info;
	int i;	


//compare the pointers
	for(i=0; i<counter;i++){
		if(strcmp(c,p->names)==0)
			return 1;

		p++;
	}

	return 0;



}




