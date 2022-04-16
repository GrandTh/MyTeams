/*
** EPITECH PROJECT, 2020
** my_teams
** File description:
** client.h
*/

#ifndef CLIENT_H_
#define CLIENT_H_

//include lib-c
#include <arpa/inet.h>
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>

// my include
#include "../libs/myteams/logging_server.h"
#include "../libs/myteams/logging_client.h"

// function pointer
typedef void (*ptr_reply)(char **, int);

// prototype
// ----- cmd_execute/close_client.c ------ //
void close_client(char **array, int sock);

// ----- cmd_execute/element_doesnt_exists.c.c ------ //
void user_doesnt_exists(char **array, int sock);
void team_doesnt_exists(char **array, int sock);
void channel_doesnt_exists(char **array, int sock);
void thread_doesnt_exists(char **array, int sock);

// ----- cmd_execute/manage_user_print.c ---- //
void print_all_user(char **array, int i);
void print_one_user(char **cmd, int sock);

// ----- cmd_execute/print_all_messages;c ----- //
void print_all_messages(char **array, int sock);

// ----- cmd_execute/print_client_error.c ------ //
void print_user_unauthorized(char **array, int sock);
void print_already_exists(char **array, int sock);

// ----- cmd_execute/print_created_success.c ------ //
void print_team_created(char **array, int sock);
void print_channel_created(char **array, int sock);
void print_thread_created(char **array, int sock);
void print_comment_created(char **array, int sock);

// ----- cmd_execute/print_event_create.c ------ //
void print_event_team_create(char **array, int sock);
void print_event_channel_create(char **array, int sock);
void print_event_thread_create(char **array, int sock);
void print_event_comment_create(char **array, int sock);

// ----- cmd_execute/print_info_cmd.c ------ //
void info_user(char **array, int sock);
void info_team(char **array, int sock);
void info_channel(char **array, int sock);
void info_thread(char **array, int sock);

// ----- cmd_execute/print_list.c ----- //
void print_teams(char **array, int sock);
void print_channels(char **array, int sock);
void print_threads(char **array, int sock);
void print_comments(char **array, int sock);

// ----- cmd_execute/print_message_client.c ------ //
void print_message(char **array, int sock);

// ----- cmd_execute/print_message_subscribe.c ------ //
void print_client_subscribe(char **array, int sock);

// ----- cmd_execute/print_message_unsubscribe.c ------ //
void print_client_unsubscribe(char **array, int sock);

// ----- cmd_execute/print_subscribed.c ------ //
void print_subscribed(char **cmd, int sock);
void print_teams_sub(char **cmd, int sock);

// ----- cmd_execute/print_user_login_out.c ------ //
void print_user_login(char **array, int sock);
void print_user_logout(char **array, int sock);

// ------ args_handling.c ----- //
int check_cli_args(int ac, char **av);
int my_exit_failure(char *str);

// ----- check_reply.c ------ //
int check_reply(char **array, int sock);

// ------ create_client.c -----//
int read_from_server(char *server_reply, int sock);
int init_socket(char *ip, int port, int sock);
void send_mess(fd_set read_fd_set, int sock);
void set_all_fd(fd_set *active_fd_set, int sock);
int create_client(char *ip, int port);

// ------ ctrlc_gestion.c -----//
bool ctrlc_active(int new);
void inthandler(int sig);

// ------ get_next_line.c -----//
int my_strlen(char *str);
char *add_char_to_str(char *str, char c);
char *get_next_line(const int fd);

// ------ help.c ------ //
int print_cli_help(void);

// ------ replace_char_in_str.c ------ //
char *replace_char_in_str(char *str, char current, char replace);

// ----- str_to_timestamp.c ------ //
time_t convert_char_to_time(char *timestamp);

// ----- utils_client.c ------ //
int count_line_client(char **array);
int count_occurences_client(char *str, char separator);
char **str_to_array_client(char *line, char *separator);
char *clean_str_client(char *cmd);

#endif
