/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** struct.h
*/

#ifndef STRUCT_H
#define STRUCT_H

#include "server.h"

typedef struct s_server {
    socklen_t len_socket;
    int socket_server;
    int new_client;
    struct sockaddr_in serv_addr;
    struct sockaddr_in serv_addr_sec;
    int index;
} t_server;

typedef struct s_user {
    char *uuid;
    char *name;
    int connected;
    char **team;
    struct s_user *next;
} t_user;

typedef struct s_teams {
    char *uuid;
    char *name;
    char *description;
    char **users;
    struct s_teams *next;
} t_teams;

typedef struct s_channels {
    char *uuid;
    char *name;
    char *description;
    char *team;
    char **users;
    struct s_channels *next;
} t_channels;

typedef struct s_comments {
    char *user;
    char *message;
    char *time;
    char *team;
    char *thread;
    struct s_comments *next;
} t_comments;

typedef struct s_threads {
    char *uuid;
    char *title;
    char *message;
    char *time;
    char *team;
    char *channel;
    char **users;
    t_comments *comments;
    struct s_threads *next;
} t_threads;

typedef struct s_messages {
    char *message;
    char *from;
    char *to;
    char *time;
    struct s_messages *next;
} t_messages;

typedef struct s_client {
    int fd_client;
    char *associated_user;
    int use;
    char *team_use;
    char *channel_use;
    char *thread_use;
    struct s_client *next;
} t_client;

typedef struct s_data {
    t_client *client;
    t_user *user;
    t_teams *teams;
    t_channels *channels;
    t_threads *threads;
    t_messages *messages;
} t_data;

#endif
