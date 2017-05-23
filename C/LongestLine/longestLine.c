#include <stdio.h>
#define MAXLINE 4

int getline(char line[], int maxline);
void copy(char to[], char from[], int full);

main() 
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            int full = max > MAXLINE;
            copy(longest, line, full);
        }
    if (max > 0) 
        printf("%s with lenght %i", longest, max-1);
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i=0; (c=getchar()) != EOF && c!='\n'; i++){
        s[i % MAXLINE] = c;
    }

    if (c == '\n') {
        s[i % MAXLINE] = c;
        ++i;
    }

    s[i % MAXLINE] = '\0';

    char fixedline[MAXLINE];
    if (i > MAXLINE){
        int offset = i % MAXLINE;
        for(int j = 0; j < MAXLINE; j++){
            fixedline[(j + offset) % MAXLINE] = s[j];
            printf("%i", (j + offset) % MAXLINE);
        }
        s = fixedline;
    }

    return i;
}

void copy(char to[], char from[], int full)
{
    int i = 0;

    if (full) {
        for(i=0; i < MAXLINE; i++)
            to[i] = from[i];
    } else {
        while ((to[i] = from[i]) != '\0')
            ++i;
    }
}