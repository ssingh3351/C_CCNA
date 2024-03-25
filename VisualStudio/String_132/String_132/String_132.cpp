// String_132.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void perm(char s[], int k) {
    static int A[10] = { 0 };
    static char Res[10];
    int i;
    if (s[k] == '\0') {
        Res[k] = '\0';
        printf("%s\n", Res);
    }

    else {
        for (i = 0; s[i] != '\0'; i++) {
            if (A[i] == 0) {
                Res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}
//void swap(char* a, char* b) {
//    int temp;
//    temp = *a;
//    *a = *b;
//    *b = temp;
//}
void perm1(char s[], int l, int h) {
    int i;
    if (l == h)
        printf("%s ", s);
    else {
        for (i = l; i <= h; i++) {
            swap(s[l], s[i]);
            perm1(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }
}
int main()
{
    char ch[] = "abc";
    perm1(ch, 0, 2);
    /*char ch1[] = "medical";
    int i, H[26] = { 0 };
    
    for (i = 0; ch[i] != '\0'; i++)
        H[ch[i] - 97] += 1;
    for (i = 0; ch1[i] != '\0'; i++) {
        H[ch1[i] - 97] -= 1;
        if (H[ch1[i] - 97] < 0) {
            printf("the tow strings are not anagrams of eachother!!.." );
            break;
        }

    }
    if (ch1[i] == '\0')
        printf("Anagram");*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
