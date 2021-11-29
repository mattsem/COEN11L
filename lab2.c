


#include <stdio.h>
#include <string.h> 

char names[10][20];
int size[10];
int counter;



//prototype methods 

void insert(void);
void fillSeats(void);
void list(void);

int main(){
	counter = 0;
	int answer;

//print menu

	while(1){
		printf("\n");
		printf("1:Add reservation \n");
		printf("2: Open seats \n");
		printf("3: list reservations \n");
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
	printf("enter name: \n");
	scanf("%s",&names[counter][0]);
	printf("Enter size of party \n");
	scanf("%d",&size[counter]);
	

//if 0 members entered display an error

	if(size[counter]==0){
		names[counter][0] = '\0';
		printf("invalid size");
		return;
	}
	counter++;

}

void fillSeats(void){
	int open,i,j,flag = 0;
	printf("how many open seats? \n");
	scanf("%d",&open);
	

//if open seats fill them

	for(j=0;j<counter;j++){
		if(open >= size[j]){
			
				printf("reservation deleted %s \n",names[j]);
				flag = 1;
				open = open - size[j];
				for(i=j;i<counter; i++){
//move the reservations to the top				
					size[i] = size[i+1];
					strcpy(names[i],names[i+1]);
					
									
				

				}
				counter--;
			
		}
	
	}
	if(flag == 0)
		printf("no open tables");
}

void list(void){
	int i , x;
	

//traverse array and print out
	if(counter ==0)
		printf("no reservations \n");
	for(i=0;i<counter;i++){
		x=0;
		while(names[i][x] != '\0'){
			printf("%c",names[i][x]);
			x++;
		}
		printf(": %d \n",size[i]);

	}

}



	
	





