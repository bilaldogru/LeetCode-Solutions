/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
*/

#include <string.h>
#include <stdlib.h>

char * mergeAlternately(char * word1, char * word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int sum = len1 + len2;
    
    char *word3 = (char*)malloc(sizeof(char) * (sum + 1));
    
    int i = 0;  
    int j = 0; 
    int k = 0; 
    
    while (i < len1 || j < len2) {
        
        if (i < len1) 
        {
            word3[k] = word1[i];
            i++; 
            k++; 
        }
        
        if (j < len2) 
        {
            word3[k] = word2[j];
            j++; 
            k++; 
        }
    }
    
    word3[k] = '\0';
    
    return word3;
}