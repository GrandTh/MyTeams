/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** command.h
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include "server.h"

/* ---------- choose_what_use.c ----------*/
void use_thread(char **array, int fd, t_client *client);
void use_channel(char **array, int fd, t_client *client);
void use_team(char **array, int fd, t_client *client);
void use_nothing(int fd, t_client *client);

/* ---------- create_new_channel.c ----------*/
void print_server_event_create_channel(t_client *client, t_channels *channel);
t_channels *add_new_channel(t_channels *channels, char **array,
    t_client *client);
int error_gestion_create_channel(t_data *data, char **array, t_client *cli);
t_data *create_new_channel(t_data *data, char **array, t_client *client);

/* ---------- create_new_comment.c ----------*/
void print_server_event_create_comment(t_client *cli, t_comments *new);
void add_new_comment(t_comments **comments, char **array, t_client *cli);
t_data *create_new_comment(t_data *data, char **array, t_client *cli);

/* ---------- create_new_team.c ----------*/
t_teams *add_new_team(t_teams *teams, char **array, t_client *client);
int error_gestion_create_team(t_data *data, char **array, t_client *client);
t_data *create_new_team(t_data *data, char **array, t_client *client);

/* ---------- create_new_thread.c ----------*/
void print_server_event_create_thread(t_client *cli, t_threads *threads);
t_threads *add_new_thread(t_threads *threads, char **array, t_client *cli);
int error_gestion_create_thread(t_data *data, char **array, t_client *cli);
t_data *create_new_thread(t_data *data, char **array, t_client *client);

/* ---------- create.c ----------*/
t_data *create_gestion_next(t_data *data, char **array, t_client *tmp);
t_data *create_gestion(t_data *data, char **array, t_client *tmp);
t_data *create_command(t_data *data, char **array, int write_fd);

/* ---------- info_cmd.c ----------*/
void print_info_user(t_data data, t_client *cli);
void print_info_team(t_data data, t_client *cli);
void print_info_channel(t_data data, t_client *cli);
void print_info_threads(t_data data, t_client *cli);

/* ---------- info_handler.c ----------*/
void check_info_env(t_data data, t_client *tmp);
int args_handling(char **array, t_data data, int write_fd);
t_data *info_cmd(t_data *data, char **array, int write_fd);

/* ---------- list_cmd.c ----------*/
void print_list_team(t_data data, int write_fd);
void print_list_channel(t_data data, t_client *cli);
void print_list_thread(t_data data, t_client *cli);
void print_list_replies(t_data data, t_client *cli);

/* ---------- list_handler.c ----------*/
void check_env_next(t_data data, t_client *tmp);
void check_env(t_data data, t_client *tmp);
t_data *list_cmd(t_data *data, char **array, int write_fd);

/* ---------- login.c ----------*/
t_data *connect_user(t_data *data, char *username, int write_fd);
t_data *create_user(t_data *data, int write_fd, char **array);
t_data *login_user(t_data *data, char **array, int write_fd);
t_data *add_associated_user(t_data *data, char *username, int write_fd);

/* ---------- logout.c ----------*/
t_data *logout_user(t_data *data, char **array, int write_fd);
t_data *disconnect_user(t_data *data, int write_fd);
void print_event_logout(char *uuid, char *name, int write_fd, t_data data);

/* ---------- messages_cmd.c ----------*/
int get_num_mess(t_data data, char *my_id, char *exchange_id);
void get_message(t_data data, char *my_id, char *exchange_id, int write_fd);
t_data *messages_cmd(t_data *data, char **array, int write_fd);

/* ---------- my_help.c ----------*/
int check_help_args(t_client *client, char **array);
t_data *print_my_help(t_data *data, char **array, int write_fd);

/* ---------- print_event_login.c ----------*/
void print_event_created(t_data data, int write_fd, char *uuid, char *name);
void print_event_login(t_data data, char *uuid, char *name);

/* ---------- print_subs_info.c ----------*/
void print_user_info(t_data data, char *user_uuid, int write_fd);

/* ---------- send.c ----------*/
t_data *send_cmd(t_data *data, char **array, int write_fd);
t_data *message_to_send(t_data *data, char **array, int write_fd);
t_messages *add_new_messages(t_messages *messages, char **infos_messages,
int write_fd);
void print_message(int write_fd, char *from, char *message);

/* ---------- subscribe.c ----------*/
t_data *subscribe_to_team(t_data *data, char **array, t_client *cli);
t_data *subscribe_user(t_data *data, char **array, int write_fd);
t_data *add_user_to_team(t_data *data, t_client *cli, char *team_uuid);
t_data *add_team_to_user(t_data *data, t_client *cli, char *team_uuid);

/* ---------- subscribed_cmd.c ----------*/
int how_much_is_sub(t_data data, char *uuid_team);
void print_subs(t_data data, char *uuid_team, int write_fd);
void print_teams(t_data data, int write_fd);
t_data *subscribed_cmd(t_data *data, char **array, int write_fd);

/* ---------- unsubscribe.c ----------*/
t_data *remove_user_to_team(t_data *data, int write_fd, char *team_uuid);
t_data *remove_team_to_user(t_data *data, int write_fd, char *team_uuid);
t_data *unsubscribe_cmd(t_data *data, char **array, int write_fd);

/* ---------- use.c ----------*/
void error_handling_use_args_next(char **array, int write_fd,
    t_client *client);
void error_handling_use_args(char **array, int write_fd, t_client *client);
t_data *use_command(t_data *data, char **array, int write_fd);

/* ---------- user.c ----------*/
void print_all_users(t_data data, int write_fd);
void print_one_user(t_user *user, char *uuid, int write_fd);
t_data *users_cmd(t_data *data, char **array, int write_fd);
t_data *user_cmd(t_data *data, char **array, int write_fd);

#endif
