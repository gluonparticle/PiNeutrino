#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[50], pat[50], rep[50], ans[50];
int i, j, k, m, c, flag = 0;

void stringmatch() {
    i = m = c = j = 0;
    while (str[c] != '\0') {
        if (str[m] == pat[i]) {
            i++;
            m++;
            if (pat[i] == '\0') {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++)
                    ans[j++] = rep[k];
                c = m;
                i = 0;
            }
        } else {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0'; // Null-terminate the resultant string
}

void main() {
    printf("\nEnter a main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    printf("\nEnter a Pattern String: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0'; // Remove newline character

    printf("\nEnter a Replacement String: ");
    fgets(rep, sizeof(rep), stdin);
    rep[strcspn(rep, "\n")] = '\0'; // Remove newline character

    stringmatch();

    if (flag == 1)
        printf("\nThe resultant string is: %s\n", ans);
    else
        printf("\nPattern String not found!!\n");
}