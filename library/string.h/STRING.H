// Calculate string length
int lengthString(char* a){
	int final_length=0;
	while(*(a+final_length)!='\0')final_length++;
	return final_length;
}

// Concatenate string
char* concatString(char* a,char* b){
	int length_a=lengthString(a);
	int length_b=lengthString(b);
	int final_length=length_a+length_b;
	char* c=(char*)malloc(sizeof(char)*(final_length+1));
	int i=0;
	for(i=0;i<length_a;i++){
		*(c+i)=*(a+i);
	}
	for(i=length_a;i<length_a+length_b;i++){
		*(c+i) = *(b+i-length_a);
	}
	*(c+final_length)='\0';
	return c;
}

// firstIndex returns -1 if no element is found, else returns first occurence position
int firstOccurrence(char* a,char b){
	int first_Occurrence=-1;
	int i=0;
	while(*(a+i)!='\0'){
		if(*(a+i)==b){
			first_Occurrence=i;
			break;
		}
		i++;
	}
	return first_Occurrence;
}

// Total Occurrence of particular character in the given string
int totalOccurrence(char* a,char b){
	int total_Occurrence=0;
	int i=0;
	while(*(a+i)!='\0'){
		if(*(a+i)==b)total_Occurrence++;
		i++;
	}
	return total_Occurrence;
}

// Returns last occurence postion else -1 if no element is found
int lastOccurrence(char *a,char b){
	int last_Occurrence=-1;
	int i=0;
	while(*(a+i)!='\0'){
		if(*(a+i)==b)last_Occurrence=i;
		i++;
	}
	return last_Occurrence;

}

// Reverse given string
char* reverseString(char *a){
	int length_a=lengthString(a);
	char *b = (char*)malloc(sizeof(char)*(length_a+1));
	int i=length_a-1,j=0;
	while(i>=0){
		*(b+j)=*(a+i);
		i--;j++;
	}
	*(b+length_a)='\0';
	return b;
}

// Concatenate reversed string
char* concatReverseString(char *a){
	return concatString(a,reverseString(a));
}

// Concatenate same string
char* concatMainString(char *a){
	return concatString(a,a);
}

// Compare two strings by alphabetic order
int compareString(char* a,char* b){
	int length_a=lengthString(a);
	int length_b=lengthString(b);
	//base cases
	if(length_a!=length_b)return 0;
	int i=0;
	while(*(a+i)!='\0'){
		if(*(a+i)!=*(b+i))return 0;
		i++;
	}
	return 1;
}

// Functions to check cases and also convert 
int isLowerCase(char a){
	if(a>=97&&a<=122)return 1;
	return 0;
}
int isUpperCase(char a){
	if(a>=65&&a<=90)return 1;
	return 0;
}
char toUpperCase(char a){
	if(a>=97&&a<=122){
		return (char)((int)a-32);
	}
	return a;
}
char toLowerCase(char a){
	if(a>=65&&a<=90){
		return (char)((int)a+32);
	}
	return a;
}


// Ignore case sensitivity and compare
int compareStringIgnoreCase(char* a,char* b){
	int length_a=lengthString(a);
	int length_b=lengthString(b);
	//base cases
	if(length_a!=length_b)return 0;
	int i=0;
	while(*(a+i)!='\0'){
		if(toLowerCase(*(a+i))!=toLowerCase(*(b+i)))return 0;
		i++;
	}
	return 1;
}


// String modify cases
char* toUpperCaseString(char *a){
	int  length_a=lengthString(a),i=0;
	char* b=(char*)malloc(sizeof(char)*(length_a+1));
	while(*(a+i)!='\0'){
		*(b+i)=toUpperCase(*(a+i));
		i++;
	}
	*(b+length_a)='\0';
	return b;
}

char* toLowerCaseString(char *a){
	int  length_a=lengthString(a),i=0;
	char* b=(char*)malloc(sizeof(char)*(length_a+1));
	while(*(a+i)!='\0'){
		*(b+i)=toLowerCase(*(a+i));
		i++;
	}
	*(b+length_a)='\0';

	return b;
}

char* toTitleCaseString(char* a){
	int  length_a=lengthString(a),i=0;
	char* b=(char*)malloc(sizeof(char)*(length_a+1));
	int flag=1;
	while(*(a+i)!='\0'){
		if(flag){
			*(b+i)=toUpperCase(*(a+i));
			flag=0;		
		}else{
			*(b+i)=toLowerCase(*(a+i));
			if(*(b+i)==' ')flag=1;		
		}
		i++;
	}
	*(b+length_a)='\0';
	return b;

}

char* replaceString(char* a , int pos , char* b){
 	int length_b=lengthString(b);
 	int i=pos;
 	while(i-pos<length_b){
 		*(a+pos)=*(b+i-pos);
 		i++;
 	}
 	return a;
 }

// eturns position of substring else -1 if no substring is found
int findSubstring(char* a,char*b){
	int length_a=lengthString(a);
	int length_b=lengthString(b);
	int i,j;
	for(i=0;i<=length_a-length_b;i++){
		for(j=0;j<length_b;j++){
			if(*(a+i+j)!=*(b+j))break;
		}
		if(j==length_b)return i;
	}
	return -1;

}


// Check if string is a palindrome
int isPalindromeString(char* a){
	int length_a=lengthString(a);
	int i=0,j=length_a-1;
	while(i<=length_a/2){
		if(*(a+i)!=*(a+j))return 0;
		i++;j--;
	}
	return 1;
}

// Display just vowels in a string
void displayVowels(char* a){
	int total_vowels=0;
	int i=0;
	while(*(a+i)!='\0'){
		if(*(a+i)=='a'||*(a+i)=='e'||*(a+i)=='i'||*(a+i)=='o'||*(a+i)=='e'|| *(a+i)=='A'||*(a+i)=='E'||*(a+i)=='I'||*(a+i)=='O'||*(a+i)=='U'){
			total_vowels++;
			printf("%c ",*(a+i));
		}
		printf("\n");
		i++;
	}

}

// Count no of characters
int countCharacters(char* a){
	int length_a=lengthString(a);
	int i=0,count=0;
	while(*(a+i)!='\0'){
		if(*(a+i)!=' '&&*(a+i)!='\n' && *(a+i)!='\r' && *(a+i)!='\t')count++;
		i++;
	}
	return count;
}

// Count no of words
int countWords(char* a){
	int length_a=lengthString(a);
	int i=0,count=0;
	for(i=0;*(a+i)!='\0';i++){
		if(*(a+i)!=' '&&*(a+i)!='\n' && *(a+i)!='\r' && *(a+i)!='\t'){
			count++;
			while(*(a+i)!=' ' || *(a+i)!='\n' || *(a+i)!= '\r' || *(a+i)!='\t'){
				i++;
				if(*(a+i)=='\0')break;
			}
		}
	}
	return count;
}
 





