
//you should do this with the rule of you may not use printf for debugging, only GDB
//
//I am going to ignore proformace and just functionize everything fist, lets get our anwers 

#include <stdio.h>
#include <ctype.h> // you need this if you are going to use isdigit
#include <stdlib.h>


int Test_Line(char *line); // using 0 for false and any non zero return for true
//
int StringToInt( char *line, int Length); //you need to fix all occurances of Length and move them to lowercase length

int IsIntIncreacing( int *numbers, int length);

int IsIntDecreacing( int *numbers, int length);

int IsIntGradually(int *numbers, int length, int min, int max);

char * GetString(char * line, int length);




int IsIntGradually(int *numbers, int length, int min, int max){
	//this checks if an array of ints is either increasing or decreasing in a gaudual manner in which the change must be at least min change between values at consetive indexs, and at most the max change.
	
	//should check to see if the inputs are all safe. is the list at least two values, all that jazz
	//
	for( int i = 1 ; i < length  ; i++){

		if(abs(numbers[i-1] - numbers[i]) < min){
			return 0; //change in values was too small
		}
		else if(abs(numbers[i-1] - numbers[i]) > max){
			return 0; //change in values was too big 
		}


	}

	return 1;
}

int IsIntDecreacing( int *numbers, int length){
	for( int i = 0 ; i < length  ; i++){

	}

	
{


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
	return 1;

}

int StringToInt( char *line, int length){
	//this function takes in a string and returns the Int value of that string
	//example "135" would return 135 as an int value
	//
	//you still need to go in and do error handling

	int singleValue;
	singleValue = 0;


	for(int i = 0 ; i < length; i++){
		if(line[i] == '\n'){
			break;
		}
		if(line[i] == ' '){
			break;
		}
		singleValue = singleValue*10;
		singleValue += line[i]-'0'; //remember that the char of a value is an ASCII value
	}
	//printf("single value from within StringToInt %d",singleValue);

	return singleValue;
}

char * GetStrings(char * line, int length){
	//this function will pick out each of the strings that are numarical only
	

	int currentNumbersLength;
	int currentNumbersIndex;
	
	int currentNumberTest;

	currentNumbersLength = currentNumbersIndex = 0;
	//this is the loop for holding the individual values, this is a memory inefficet way of doing things 
	char currentNumbers[length];
	for (int j = 0 ; j < length ; j++){
		currentNumbers[j] = 0;
	}

	//this is the loop that the actually iterates through the line
	for (int i = 0 ; i < length ; i++){ 
		
		//if(!(line[i] >= '0' && line[i] <= '9') && line[i] != ' ' && line[i] != '\n' && line[i] != EOF){ //this is just a version of the comparision that does not use isdigit
		if(!isdigit(line[i]) && line[i] != ' ' && line[i] != '\n' && line[i] != EOF){
			printf("error, input does not match required formate"); // change this to a real error and handle it 
		}

		if(line[i] == '\n'){
			//need to do a dump of the current string "buffer" to the convert to Int functiono
			//currentNumberTest = StringToInt(line[(i - currentNumbersLenght)], currentNumbersLength); //I need to pass part 
			break;
		}
		else if (line[i] == ' ' && line[i-1] == ' '){ //this handles the case of if there is multible spaces between numbers
			continue;
		}

		else if (line[i] == ' '){
			//currentNumbers[currentNumbersIndex] = StringToInt(line[i - currentNumbersLenght], currentNumbersLength); //I need to pass part 
			currentNumberTest = StringToInt(line[(i - currentNumbersLength)], currentNumbersLength); //I need to pass part 
			printf("current number test: %d", currentNumberTest);

			currentNumbersLength = 0;	
		}

		else if(line[i] != ' '){
			currentNumbersLength++;
			printf("currentNumberLength++");
		}

	}
	return 0;

}



int main(){

	FILE *fp;
	char line[256]; 	//look back. I thought that we should use int up why we use the int for this, its because EOF is bigger than just a char right?
	fp = fopen("smallDay2input.txt", "r");


	if(fp == NULL){ //would this not be better to change to using an assert?
		printf("Error reading in the file");
		return 1;
	}

	int singleValueInMain;
	singleValueInMain = 0;
	//be able to convert a string value into a int	
	fgets(line, LINE_LENGTH, fp);	
	singleValueInMain = StringToInt(line, LINE_LENGTH);
	printf("single value from within main %d",singleValueInMain);
	
	GetString(line, LINE_LENGTH);



	
	//be able to turn a string of values into an array of ints
	//be able to tell if the array is assending 
	//
	//for decending

	//while(fgets(line, LINE_LENGTH, fp)){ //the end of line is terminated with \0, but is ther a way to step after the last valid value? end of the file returns NULL
		//printf("Start of a new line \n");
		//printf("%c",line);
		//Test_Line(line);
	//}


}
//

