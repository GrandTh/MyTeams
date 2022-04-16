/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** lib.h
*/

#ifndef LIB_H_
#define LIB_H_

#include "server.h"

/* ---------- add_value_in_array.c ----------*/
char **add_value_in_empty_array(char **tmp, char *str);
char **add_value_in_array(char **array, char *str);

/* ---------- check_doule_coat.c ----------*/
bool double_coat(char *username);

/* ---------- check_element_exists.c ----------*/
int check_if_user_exists(t_data *data, int fd, char *user_uuid);
int check_if_team_exists(t_data *data, int fd, char *team_uuid);
int check_if_channel_exists(t_data *data, t_client *client);
int check_if_thread_exists(t_data *data, t_client *client);

/* ---------- check_team_in_user.c ----------*/
int check_if_team_in_user(t_data *data, char *team_uuid, char *user_uuid);

/* ---------- check_user_in_team.c ----------*/
int check_if_user_in_team(t_data *data, char *team_uuid, char *user_uuid);

/* ---------- clean_str.c ----------*/
char *clean_str(char *buffer);

/* ---------- free_array.c ----------*/
void free_array(char **array);

/* ---------- generate_timestamp.c ----------*/
char *generate_time(void);

/* ---------- get_next_line.c ----------*/
char *get_next_line(const int fd);

/* ---------- itoa.c ----------*/
void reverse(char s[]);
char *itoa(int n);

/* ---------- list_size.c ------------*/
int get_size_teams(t_data data);
int get_size_channels(t_data data, t_client *cli);
int get_size_threads(t_data data, t_client *cli);
int get_size_comments(t_data data, t_client *cli);

/* ---------- parse_args_client.c ----------*/
int count_args(char *str);
char *fill_array_with_coat(char *line, int *j, int *i, int *x);
char **parse_args_client(char *line);

/* ---------- print_clients_list.c ----------*/
void print_clients_list(t_client *clients);

/* ---------- print_event_element_create.c ----------*/
void print_event_team_create(t_data *data);
void print_event_channel_create(t_data *data);
void print_event_thread_create(t_data *data);
void print_event_comment_create(t_data *data, char *uuid_thread);

/* ---------- print_list.c ----------*/
void print_users_list(t_user *users);
void print_teams_list(t_teams *teams);
void print_channels_list(t_channels *channels);
void print_messages_list(t_messages *messages);
void print_all(t_data *data);

/* ---------- print_threads_list.c ----------*/
void print_threads_list(t_threads *threads);
void print_comments_list(t_comments *comments);

/* ---------- remove_value_in_array.c ----------*/
char **remove_value_in_array(char **array, char *str);

/* ---------- replace_char_in_str.c ----------*/
char *replace_char_in_str(char *str, char current, char replace);

/* ---------- str_to_array.c ----------*/
int count_occurences(char *str, char separator);
char **str_to_array(char *line, char *separator);

/* ---------- user_associated_exists.c ----------*/
bool user_associated_null(t_data data, int write_fd);

#endif
