
//you should do this with the rule of you may not use printf for debugging, only GDB

#include <stdio.h>


int Test_Line(char *line); // using 0 for false and any non zero return for true

#define LINE_LENGTH 256
#define MAX_LINES 1000 //will use this for the NASA standards 

int Test_Line(char *line){
	//printf("hello from Test_Line\n");
	char lastChar;
	lastChar = ' ';
	int current_value, last_value, first_value_found; //these are going to keep the value of 
	current_value = last_value  = first_value_found = 0; //first value found is how I am dealing with comparing to a 0 value; 

	 
	printf("%s",line);

	//
	for(int i = 0 ; i < LINE_LENGTH; i++){

		//printf("%c",line[i]);
	/*
		//this section is usec for preparing the for loop for the next line
		if( line[i] == '\n'){ 
			//printf("End of line char found\n");
			printf("\n");
			first_value_found = 0; //reset first found value before next line; 
			lastChar = ' ';
			
			break;
		}
	
		//is the current value not a space?
		if( line[i] != ' '){ //this logic is bad because the values could be alpha or symbols
			printf("%c",line[i]);
			//printf("the value was not a space");
			current_value = current_value*10; //there is going to be some weird char to int bullshit going on here 
			current_value = current_value + line[i];
			break;
		}
		printf("last_value: %d",last_value);
		printf("current_value: %d",current_value);

		//the current i value is a space and the last value was a number
		if (lastChar != ' '){ 
			last_value = current_value;
			current_value = 0;
		}

		lastChar = line[i];



		if(line[i] == ' '){
			first_value_found = 1; //set value to already found
		}

	*/
	}
	return 1;
	//iterate through the line with the abilty to grab each value and convert it to a char 
	//this will probably require the shift the value up by x10

}



int main(){

	FILE *fp;
	char line[256]; 	//look back. I thought that we should use int up why we use the int for this, its because EOF is bigger than just a char right?
	fp = fopen("smallDay2input.txt", "r");
	if(fp == NULL){ //would this not be better to change to using an assert?
		printf("Error reading in the file");
		return 1;
	}


	//I am going to need to have some variable to is tracking if the values are assending or decending in order
	while(fgets(line, LINE_LENGTH, fp)){ //the end of line is terminated with \0, but is ther a way to step after the last valid value? end of the file returns NULL
		//printf("Start of a new line \n");
		//printf("hello from within while loop\n");
		//printf("%s",line);
		//printf("%c",line);
		Test_Line(line);
	}


}
//first and formast we need to read the file in to the program
//
//then we need to be able to read line by line
//
//then we need to be able to get the value of each number, note that these may be multi char values that you convert to ints
//
//check the following 
//all input lines need to change values at least by 1 AND most by 3
//each input line needs to either be all increasing or all decreasing 
//how may lines are safe
//

