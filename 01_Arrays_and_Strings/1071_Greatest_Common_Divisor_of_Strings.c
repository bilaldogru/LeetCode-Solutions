/*
1071. Greatest Common Divisor of Strings
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"

Output: "ABC"

Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"

Output: "AB"

Example 3:

Input: str1 = "LEET", str2 = "CODE"

Output: ""

Example 4:

Input: str1 = "AAAAAB", str2 = "AAA"

Output: ""

*/

#include <string.h>
#include <stdlib.h>

char* gcdOfStrings(char* str1, char* str2) 
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    char* concat1 = malloc(len1 + len2 + 1);
    char* concat2 = malloc(len1 + len2 + 1);
    
    strcpy(concat1, str1);
    strcat(concat1, str2);
    
    strcpy(concat2, str2);
    strcat(concat2, str1);
    
    int isEqual = (strcmp(concat1, concat2) == 0);

    if (!isEqual) 
    {
        char* emptyResult = malloc(1);
        emptyResult[0] = '\0';
        return emptyResult;
    }
    int a = len1;
    int b = len2;

    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd_length = a; 
    
    char* result = malloc(gcd_length + 1);
    strncpy(result, str1, gcd_length);
    result[gcd_length] = '\0';
    
    return result;
}