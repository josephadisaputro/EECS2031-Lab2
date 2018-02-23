# include <stdio.h>
# include "identifiers.h"

/* you may wish to remove the following lines */
 #pragma GCC diagnostic ignored "-Wpointer-sign" 
 #pragma GCC diagnostic ignored "-Wdangling-else" 
 #pragma GCC diagnostic ignored "-Wempty-body" 
 
 /*This is work was done by Yusuf Adisaputro, 213533088*/

/* Q1.convert a temperature in F to it in C */
float fahrenheit2celsius(const float f) 
{
	float step1 = 32.0f;
	float step2 = 5.0f;
	float step3 = 9.0f;
	float answer;
	
	answer = f - step1;
	answer = answer*step2;
	answer = answer/step3;
  	return answer;
}

/* Q2. convert a temperature in C to F */
float celsius2fahrenheit(const float c) 
{
	float step1 = 9.0f;
	float step2 = 5.0f;
	float step3 = 32.0f;
	float answer;
	
	answer = c * step1;
	answer = answer/step2;
	answer = answer+step3;
	
  	return answer;
}

/* Q3. reverse the elements in an array of int's in place */
void reverse_elements(int vals[], int count)
{

	int i;
	int newCounter = 0;
	int tmp[count];
	for (i = count-1; i >= 0; i = i-1){
		tmp[newCounter] = vals[i];
		newCounter = newCounter+1;
	}
	for (i = 0; i < count; i = i+1){
		vals[i] = tmp[i];
	}
	
}

/* Q4. Count the number of '*' in the string given */
int count_stars(const char *s) 
{
  
	int i;
	int counter;
	counter = 0;
	i = 0;
	while(s[i] != '\0'){
		if(s[i] == '*'){
			counter = counter + 1;
		}
		i = i + 1;
	}
	return counter;
}
