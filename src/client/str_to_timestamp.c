/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** str_to_timestamp.c
*/

#include "client.h"

time_t convert_char_to_time(char *timestamp)
{
    struct tm time = { 0 };
    int dd = 0;
    int mo = 0;
    int nb_day = 0;
    int hh = 0;
    int mm = 0;
    int ss = 0;
    int yy = 0;

    sscanf(timestamp, "%ls %ls %d %d:%d:%d %d", &dd, &mo, &nb_day,
        &hh, &mm, &ss, &yy);
    time.tm_wday = dd;
    time.tm_mon = mo - 1;
    time.tm_mday = nb_day;
    time.tm_hour = hh - 1;
    time.tm_min = mm;
    time.tm_sec = ss;
    time.tm_year = yy - 1906;
    return mktime(&time);
}
