/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** itoa.c
*/

#include "server.h"

void reverse(char s[])
{
    char c;

    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char *itoa(int n)
{
    int i;
    int sign;
    char *s = malloc(sizeof(char) * 255);

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
        s[i++] = n % 10 + '0';
    while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    return s;
}
