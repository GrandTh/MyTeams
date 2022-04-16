/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** create_client.c
*/

#include "client.h"

int read_from_server(char *server_reply, int sock)
{
    char *reply = NULL;
    char **array = NULL;

    if (!server_reply || !strlen(server_reply))
        return 0;
    reply = clean_str_client(server_reply);
    array = str_to_array_client(reply, " ");
    check_reply(array, sock);
    return 0;
}

int init_socket(char *ip, int port, int sock)
{
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return -1;
    }
    printf("220 Service ready for new user.\r\n");
    return sock;
}

void send_mess(fd_set read_fd_set, int sock)
{
    char *message = NULL;
    char *server_reply = NULL;

    if (FD_ISSET(STDIN_FILENO, &read_fd_set)) {
        message = get_next_line(0);
        dprintf(sock, "%s\n", message);
    } else if (FD_ISSET(sock, &read_fd_set)) {
        server_reply = get_next_line(sock);
        if (!server_reply) {
            close(sock);
            return;
        }
        dprintf(0, "%s\n", server_reply);
        read_from_server(server_reply, sock);
    }
    if (server_reply && strlen(server_reply))
        free(server_reply);
    if (message && strlen(message))
        free(message);
}

void set_all_fd(fd_set *active_fd_set, int sock)
{
    FD_ZERO(active_fd_set);
    FD_SET(STDIN_FILENO, active_fd_set);
    FD_SET(sock, active_fd_set);
}

int create_client(char *ip, int port)
{
    int sock = 0;
    fd_set read_fd_set;
    fd_set active_fd_set;
    fd_set write_fd_set;

    if ((sock = init_socket(ip, port, sock)) < 0)
        return 1;
    ctrlc_active(1);
    signal(SIGINT, inthandler);
    while (ctrlc_active(-1) == true) {
        set_all_fd(&active_fd_set, sock);
        read_fd_set = active_fd_set;
        write_fd_set = active_fd_set;
        if (select(FD_SETSIZE, &read_fd_set, &write_fd_set, NULL, NULL) < 0)
            break;
        send_mess(read_fd_set, sock);
    }
    dprintf(sock, "Goodbye\r\n");
    close(sock);
    return 0;
}
