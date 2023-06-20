/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>


int isAnagram(char *firstWord, char *secondWord) { // O(n)
    //additional testing assertions
    //change to lower case for both words for simplicity
    
    table_asccii[128] = {0}; //ascii chars
    table_asccii_2[128] = {0}; //ascii chars 
    // optimize for memory using only one table => decrement from the first table in second for loop
    
    int len_firstWord = strlen(firstWord);
    int len_secondWord = strlen(secondWord); 
    //optimize for checking if they have the same len or not => return 0
    
    for (int i = 0; i < len_firstWord); i++) {
        table_asccii[firstWord[i]]++;
    }
    
    for (int i = 0; i < len_secondWord); i++) {
        table_asccii_2[secondWord[i]]++;
    }
    
    for (int i = 0 ; i < 128; i++) {
        if (table_asccii_2[i] != table_asccii[i]){
            return 0; //not anagram
        }
        
    }
    
    return 1;
    
}

int main()
{
    
    
    return 0;
}
