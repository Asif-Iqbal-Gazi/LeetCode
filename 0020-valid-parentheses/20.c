#include <string.h>
bool isValid(char *s) {
    /* Approach: Stack -- T.C: O(n), S.C: O(n) */

    int n   = strlen(s);
    int top = -1;

    char *stack = (char *)malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        char c = s[i];
        switch (c) {
        case '(':
            stack[++top] = ')';
            break;
        case '{':
            stack[++top] = '}';
            break;
        case '[':
            stack[++top] = ']';
            break;
        default:
            if (top == -1 || stack[top] != c)
                return false;
            else
                top--;
        }
    }

    free(stack);
    return top == -1;
}
