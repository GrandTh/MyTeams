/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** server.h
*/

#ifndef SERVER_H_
#define SERVER_H_

// include lib-C
#include <arpa/inet.h>
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#include <uuid/uuid.h>

// my include
#include "struct.h"
#include "lib.h"
#include "command.h"
#include "data_parsing.h"
#include "managed_data.h"
#include "../libs/myteams/logging_server.h"
#include "../libs/myteams/logging_client.h"

// macro
#define MAX_NAME_LENGTH 32
#define MAX_BODY_LENGTH 512
#define MAX_DESCRIPTION_LENGTH 255
#define HELP \
"101 Help:\n\
    /help: Show help\n\
    /users: Get the list of all users that exist on the domain\n\
    /user [“user_uuid”]: Get information about a user\n\
    /send [“user_uuid”] [“message_body”]: Send a message to a user\n\
    /messages [“user_uuid”]: List all messages exchange with an user\n\
    /subscribe [“team_uuid”]: Subscribe to the event of a team and its sub\n \
    directories (enable reception of all events from a team)\n\
    /unsubscribe [“team_uuid”]: Unsubscribe from a team\n\
    /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”]:\n \
    Use specify a context team / channel / thread\n\
    /subscribed ?[“team_uuid”]: List all subscribed teams or list all\n \
    users subscribed to a team\n\
    /create: Based on what is being used create the sub resources(see below)\n\
    /list: Based on what is being used list all\n \
    the sub resources(see below)\n\
    /info: Based on what is being used list the current(see below)\r\n"

// function pointer
typedef t_data *(*ptr_function)(t_data *, char **, int);
typedef t_data *(*parsing_func)(t_data *, char *);

// prototype

/* ---------- args_handling.c ----------*/
int check_serv_args(int ac, char **av);

/* ---------- close_end.c ----------*/
void close_all(t_data data, t_server serv, fd_set *read_fd_set);

/* ---------- create_client.c ----------*/
t_data *accept_client(t_data *data, int i, t_server serv,
    fd_set *active_fd_set);
t_data *wait_client(t_data *data, t_server serv, fd_set *read_fd_set,
    fd_set *active_fd_set);

/* ---------- create_server.c ----------*/
t_data *init_data_struct(t_data *data);
void end_server(t_data *data, t_server serv, fd_set read_fd_set);
int main_server(t_server serv);
int init_socket(int port, t_server serv);

/* ---------- ctrlc_clientc ----------*/
void free_one_client(t_client *client);
t_client *delete_client(t_client *client, int write_fd);
t_data *ctrlc_client(t_data *data, char **array, int write_fd);

/* ---------- ctrlc_gestion.c ----------*/
bool ctrlc_active(int new);
void inthandler(int sig);

/* ---------- help.c ----------*/
int print_serv_help(void);

/* ---------- init_struct_server.c ----------*/
t_server init_struct(void);

/* ---------- read_command.c ---------------*/
t_data *get_cmd(t_data *data, char **array, int write_fd);
int write_client(t_data data, int fd);
int read_from_client(int fd, t_data *data);

/* ---------- utils_login.c ---------------*/
t_user *add_user(t_user *user, char *username, int write_fd, t_data *data);
bool check_already_connect(t_data data, int write_fd);
bool user_exists(t_data data, char *username);
char *get_my_uuid(t_data data, char *username);

/* ---------- utils_message.c ---------------*/
char *get_sender(t_data data, int write_fd);
int fd_client_receive(t_data data, char *uuid);

/* ---------- utils_subscribe.c ---------------*/
int user_is_already_in(t_data data, int write_fd, char *team_uuid);
int user_is_not_already_in(t_data data, int write_fd, char *team_uuid);

/* ---------- utils.c ----------*/
t_client *add_front_list(t_client *l_a, int n);
int count_lines(char **array);
int count_char(char *str);
char *clean_username(char *username);
int my_exit_failure(char *str);

/* ---------- uuid.c -----------*/
char *generate_uuid(void);

#endif
