#include <stdio.h>
#include <string.h>

void changeString(char str [], int k) {
    int len = strlen(str);
    int i, j;

    for (i = k; i < len; i++) {
        int found = 0;
        for (j = i - k; j < i; j++) {
            if (str[j] == str[i]) {
                found = 1;
                break;
            }
        }

        if (found) {
            str[i] = '-';
        }
    }
}

int main() {
    char str[100];
    int k;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    changeString(str, k);

    printf("Modified string: %s\n", str);

    return 0;
}