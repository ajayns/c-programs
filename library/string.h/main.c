#include<stdio.h>
#include"STRING.H"

void main()
{
	int i;
	char a[100],b[100],c;
	printf("Enter string:\n");
	scanf("%s",a);
	printf("Enter another string:\n");
	scanf("%s",b);
	printf("Enter a character:\n");
	scanf("%c",&c);
	printf("\nLength=%d",lengthString(a));
	printf("\nConcat=%s",concatString(a,b));
	printf("\nFirst Occurrence of character=%d",firstOccurrence(a,c));
	printf("\nTotal Occurrence of character=%d",totalOccurrence(a,c));
	printf("\nLast Occurrence of character=%d",lastOccurrence(a,c));
	printf("\nReverse=%s",reverseString(a));
	printf("\nConcat Reverse=%s",concatReverseString(a));
	printf("\nConcat Same String=%s",concatMainString(a));
	printf("\nCompare=%d",compareString(a,b));
	printf("\nCompare without case=%d",compareStringIgnoreCase(a,b));
	printf("\nUppercase=%s",toUpperCaseString(a));
	printf("\nLowercase=%s",toLowerCaseString(a));
	printf("\nTitlecase=%s",toTitleCaseString(a));
	printf("\nReplace substring=%s",replaceString(a,3,b));
	printf("\nFind substring=%d",findSubstring(a,b));
	printf("\nCheck palindrome=%d",isPalindromeString(a));
	printf("\nCount characters=%d, Count words=%d",countCharacters(a),countWords());	
	printf("\nDisplay Vowels:");
	displayVowels(a);
}

