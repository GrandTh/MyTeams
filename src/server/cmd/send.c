/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** send.c
*/

#include "server.h"

t_data *send_cmd(t_data *data, char **array, int write_fd)
{
    if (user_associated_null(*data, write_fd) == true) {
        dprintf(write_fd, "420 use login before logout\r\n");
    }
    if (user_associated_null(*data, write_fd) == false &&
    (count_lines(array) != 3 || strlen(array[1]) != 38 ||
    strlen(clean_username(array[2])) > MAX_BODY_LENGTH ||
    double_coat(array[1]) == false || double_coat(array[2]) == false)) {
        dprintf(write_fd, "510 Bads arguments\r\n");
    }
    else if (user_associated_null(*data, write_fd) == false &&
    check_if_user_exists(data, write_fd, clean_username(array[1])) == 1)
        message_to_send(data, array, write_fd);
    return data;
}

t_data *message_to_send(t_data *data, char **array, int write_fd)
{
    char *sender = get_sender(*data, write_fd);
    char *time = generate_time();
    int fd_receive = fd_client_receive(*data, array[1]);
    char *str_fd = itoa(fd_receive);

    char *info[5] = {sender, clean_username(array[1]),
    clean_username(array[2]), time, str_fd};

    data->messages = add_new_messages(data->messages, info, write_fd);
    return data;
}

t_messages *add_new_messages(t_messages *messages, char **infos_messages,
int write_fd)
{
    t_messages *new = calloc(1, sizeof(t_messages));
    t_messages *tmp = messages;

    new->from = strdup(infos_messages[0]);
    new->to = strdup(infos_messages[1]);
    new->message = strdup(infos_messages[2]);
    new->time = strdup(infos_messages[3]);
    new->next = NULL;
    server_event_private_message_sended(new->from, new->to, new->message);
    dprintf(write_fd, "240 message envoyé\r\n");
    print_message(atoi(infos_messages[4]), new->from, new->message);
    if (messages == NULL)
        return new;
    else {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        return messages;
    }
}

void print_message(int write_fd, char *from, char *message)
{
    if (write_fd != 0) {
        dprintf(write_fd, "140\r\n");
        sleep(0.2);
        dprintf(write_fd, "%s|%s\r\n", from, message);
    }
}
