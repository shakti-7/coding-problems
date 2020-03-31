#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the formingMagicSquare function below.
int formingMagicSquare(int s_rows, int s_columns, int** s) 
{
    int i,j,diff,corr;
    int a[3][3]={{8,1,6},{3,5,7},{4,9,2}};
    int b[3][3]={{6,1,8},{7,5,3},{2,9,4}};
    int c[3][3]={{4,9,2},{3,5,7},{8,1,6}};
    int d[3][3]={{2,9,4},{7,5,3},{6,1,8}};
    int e[3][3]={{8,3,4},{1,5,9},{6,7,2}};
    int f[3][3]={{4,3,8},{9,5,1},{2,7,6}};
    int g[3][3]={{6,7,2},{1,5,9},{8,3,4}};
    int h[3][3]={{2,7,6},{9,5,1},{4,3,8}};
    diff=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        diff+=abs(a[i][j]-*(*(s+i)+j));
    }
    corr=diff;
    diff=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        diff+=abs(b[i][j]-*(*(s+i)+j));
    }
    if(diff<corr)
    corr=diff;
    diff=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        diff+=abs(c[i][j]-*(*(s+i)+j));
    }
    if(diff<corr)
    corr=diff;
    diff=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        diff+=abs(d[i][j]-*(*(s+i)+j));
    }
    if(diff<corr)
    corr=diff;
    diff=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        diff+=abs(e[i][j]-*(*(s+i)+j));
    }
    if(diff<corr)
    corr=diff;
    diff=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        diff+=abs(f[i][j]-*(*(s+i)+j));
    }
    if(diff<corr)
    corr=diff;
    diff=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        diff+=abs(g[i][j]-*(*(s+i)+j));
    }
    if(diff<corr)
    corr=diff;
    diff=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        diff+=abs(h[i][j]-*(*(s+i)+j));
    }
    if(diff<corr)
    corr=diff;
    return corr;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(readline());

        for (int j = 0; j < 3; j++) {
            char* s_item_endptr;
            char* s_item_str = *(s_item_temp + j);
            int s_item = strtol(s_item_str, &s_item_endptr, 10);

            if (s_item_endptr == s_item_str || *s_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(s + i) + j) = s_item;
        }
    }

    int s_rows = 3;
    int s_columns = 3;

    int result = formingMagicSquare(s_rows, s_columns, s);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
