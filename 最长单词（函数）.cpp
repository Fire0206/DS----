#include <stdio.h>
#include <string.h>
int compareWordLength(const char* word1, const char* word2);
void MaxLenWord(char s[]);
int main() {
    int t;
    scanf("%d", &t);
    getchar();
    for(int j=0;j<t;j++) {
        char s[1000]; 
        fgets(s, 1000, stdin);
        s[strcspn(s, "\n")] = '\0';
        MaxLenWord(s);
        if(j!=t-1){
    		printf("\n");
   	 	}
	}
	return 0;
}
int compareWordLength(const char* word1, const char* word2) {
    return strlen(word1) > strlen(word2)? strlen(word1) : strlen(word2);
}
void MaxLenWord(char s[]) {
    int len = strlen(s);
    int i;
    int maxLen = 0;
    char maxWords[10][100]; 
    int maxWordCount = 0;
    int start = 0;
    int currentWordIndex = 0;
    for (i = 0; i <= len; i++) {
        if (s[i] ==' ' || s[i] == '\0') {
            char word[100]; 
            strncpy(word, &s[start], i - start);
            word[i - start] = '\0';
            int currentLen = strlen(word);
            if (currentLen > maxLen) {
                maxLen = currentLen;
                maxWordCount = 0;
                strcpy(maxWords[maxWordCount], word);
                maxWordCount++;
            } else if (currentLen == maxLen) {
                strcpy(maxWords[maxWordCount], word);
                maxWordCount++;
            }
            start = i + 1;
        }
    }
    for (i = 0; i < maxWordCount; i++) {
        printf("%s", maxWords[i]);
    	if(i!=maxWordCount-1){
    		printf(" ");
		}
	}
}


