/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** create_server.c
*/

#include "server.h"

t_data *init_data_struct(t_data *data)
{
    data = malloc(sizeof(t_data));
    data->client = NULL;
    data->user = NULL;
    data->teams = NULL;
    data->channels = NULL;
    data->threads = NULL;
    data->messages = NULL;
    return data;
}

void end_server(t_data *data, t_server serv, fd_set read_fd_set)
{
    stock_data_in_file(data);
    close_all(*data, serv, &read_fd_set);
    free_all_data(data);
}

int main_server(t_server serv)
{
    t_data *data = NULL;
    fd_set read_fd_set;
    fd_set active_fd_set;
    fd_set write_fd_set;

    data = init_data_struct(data);
    data = parsing_data(data);
    ctrlc_active(1);
    signal(SIGINT, inthandler);
    FD_ZERO(&active_fd_set);
    FD_SET(serv.socket_server, &active_fd_set);
    while (ctrlc_active(-1) == true) {
        read_fd_set = active_fd_set;
        write_fd_set = active_fd_set;
        if (select(FD_SETSIZE, &read_fd_set, &write_fd_set, NULL, NULL) < 0)
            break;
        data = wait_client(data, serv, &read_fd_set, &active_fd_set);
    }
    end_server(data, serv, read_fd_set);
    return 0;
}

int init_socket(int port, t_server serv)
{
    serv.socket_server = socket(AF_INET, SOCK_STREAM, 0);
    (serv.socket_server == -1) ? my_exit_failure("socket") : 0;
    serv.serv_addr.sin_family = AF_INET;
    serv.serv_addr.sin_port = htons(port);
    serv.serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    (bind(serv.socket_server, (struct sockaddr *)&serv.serv_addr,
    sizeof(serv.serv_addr)) == -1) ? my_exit_failure("bind") : 0;
    (listen(serv.socket_server, 5) == true) ? my_exit_failure("listen") : 0;
    return main_server(serv);
}
