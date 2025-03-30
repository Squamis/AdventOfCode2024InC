
//you should do this with the rule of you may not use printf for debugging, only GDB
//
//I am going to ignore proformace and just functionize everything fist, lets get our anwers 

#include <stdio.h>
#include <ctype.h> // you need this if you are going to use isdigit
#include <stdlib.h>

#define LINE_LENGTH 256
#define MAX_LINES 1000 //will use this for the NASA standards 

int Test_Line(char *line); // using 0 for false and any non zero return for true
//
int StringToInt( char *line, int Length); //you need to fix all occurances of Length and move them to lowercase length
int FirstTwoStringsToInts(char *line,  int Length);

int IsIntIncreacing( int *numbers, int length);

int IsIntDecreacing( int *numbers, int length);

int IsIntGradually(int *numbers, int length, int min, int max);

char * GetString(char * line, int length);




int FirstTwoStringsToInts(char *line,  int length){
	//this function takes in a string and returns the first two int values as an array 
	//example "135 236" would return 135 and 236 as an array as an int value
    //this will need to be passed an array of two chars to compare, that will be the single memory location that gets reused
	//
	//you still need to go in and do error handling

	int singleValue, secondValue, indexOfSecondInt, secondSpace;
	singleValue = secondValue = indexOfSecondInt = secondSpace = 0;

    //this loop get the first value
	for(int i = 0 ; i < length; i++){
		if(line[i] == '\n'){
		    printf("this is th last value of the larger string/the only value in the string passed to the function %d",singleValue);
            //secondValue = NULL;
			break;
		}
		if(line[i] == ' '){
		    indexOfSecondInt = i+1;
		    printf("the value of the fist int is %d",singleValue);
			break;
            }
		singleValue = singleValue*10;
		singleValue += line[i]-'0'; //remember that the char of a value is an ASCII value

	}
	for( int j = indexOfSecondInt ; j < length; j++){
		if(line[j] == '\n'){
			printf("second value: %d",secondValue);
			//secondValue = NULL;
			break;
		}
		if(line[j] == ' '){
			printf("the second value of the fist int is %d",secondValue);
			break;
		}

		secondValue = secondValue*10;
		secondValue += line[j]-'0'; //remember that the char of a value is an ASCII value
	}
	//printf("single value from within StringToInt %d",singleValue);

	return singleValue;
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
			//currentNumberTest = StringToInt(line[(i - currentNumbersLength)], currentNumbersLength); //I need to pass part 
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
	int secondValueInMain;
	singleValueInMain = 0;
	secondValueInMain = 0;

	//be able to convert a string value into a int	
	fgets(line, LINE_LENGTH, fp);	
	FirstTwoStringsToInts(line, LINE_LENGTH);

	//singleValueInMain = StringToInt(line, LINE_LENGTH);
	//printf("single value from within main %d",singleValueInMain);
	



	
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

