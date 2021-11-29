#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int division(int,int);

int main(void){
	int i, quotient, divisor, count = 0;
//set rand seed
	srand((int) time(NULL));
	for(i=0;i<10; i++){
//ensure numbers are the right size	
		divisor = rand() % 12 +1;
		quotient = rand() % 13;
		printf("%d / %d", divisor*quotient, divisor);
		printf("\n");
//count correct answers
		if(division(divisor, quotient) == 1)
			count++;
		
	}
	printf("You got %d %% correct", count*10); //output %
	printf("\n");
	return 0;


}


int division(int divisor, int quotient){
	int answer;
//read answer
	scanf("%d", &answer);
//if answer is right its right	
	if(answer == quotient){
		printf("Correct!");
		printf("\n");
		return 1;
	}
//wrong	
	printf("Sorry! Answer: %d",quotient);
	printf("\n");
	return 0;

}


