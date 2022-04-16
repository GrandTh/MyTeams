/*
** EPITECH PROJECT, 2020
** TEAMS
** File description:
** messages_cmd.c
*/

#include "server.h"

int get_num_mess(t_data data, char *my_id, char *exchange_id)
{
    int size = 0;
    t_messages *tmp = data.messages;

    for (;tmp; tmp = tmp->next) {
        if (((strcmp(tmp->from, exchange_id) == 0) &&
            (strcmp(tmp->to, my_id) == 0)) ||
            ((strcmp(tmp->to, exchange_id) == 0) &&
            (strcmp(tmp->from, my_id) == 0)))
            size++;
    }
    return size;
}

void get_message(t_data data, char *my_id, char *exchange_id, int write_fd)
{
    char *message = NULL;
    t_messages *tmp = data.messages;

    for (;tmp; tmp = tmp->next) {
        if (((strcmp(tmp->from, exchange_id) == 0) &&
            (strcmp(tmp->to, my_id) == 0)) ||
            ((strcmp(tmp->to, exchange_id) == 0) &&
            (strcmp(tmp->from, my_id) == 0))) {
            message = strdup(tmp->message);
            sleep(0.2);
            dprintf(write_fd, "%s/%s/%s\r\n", tmp->from, tmp->time, message);
        }
    }
}

t_data *messages_cmd(t_data *data, char **array, int write_fd)
{
    char *my_id = NULL;
    char *exchange_id = NULL;
    int size = 0;

    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 use login before logout\r\n");
        return data;
    }
    if (count_lines(array) != 2 || strlen(array[1]) != 38
        || double_coat(array[1]) == false)
        dprintf(write_fd, "510 Bads arguments\r\n");
    else {
        my_id = get_sender(*data, write_fd);
        exchange_id = clean_username(array[1]);
        if (check_if_user_exists(data, write_fd, exchange_id)) {
            size = get_num_mess(*data, my_id, exchange_id);
            dprintf(write_fd, "241 %d\r\n", size);
            get_message(*data, my_id, exchange_id, write_fd);
        }
    }
    return data;
}
