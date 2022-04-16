/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** create_client.c
*/

#include "server.h"

t_data *wait_client(t_data *data, t_server serv, fd_set *read_fd_set,
    fd_set *active_fd_set)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, read_fd_set))
            data = accept_client(data, i, serv, active_fd_set);
    }
    return data;
}

t_data *accept_client(t_data *data, int i, t_server serv,
    fd_set *active_fd_set)
{
    if (i == serv.socket_server) {
        serv.len_socket = sizeof(serv.serv_addr_sec);
        serv.new_client = accept(serv.socket_server,
        (struct sockaddr *)&serv.serv_addr_sec, &serv.len_socket);
        data->client = add_front_list(data->client, serv.new_client);
        (serv.new_client < 0) ? my_exit_failure("accept") : 0;
        FD_SET(serv.new_client, active_fd_set);
    }
    else {
        read_from_client(i, data);
    }
    return data;
}
