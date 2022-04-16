/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** managed_data.h
*/

#ifndef MANAGED_DATA_H_
#define MANAGED_DATA_H_

#include "server.h"

/* ---------- free_comments_list.c ----------*/
t_comments *free_comments_list(t_comments *comments);

/* ---------- free_data.c ----------*/
t_teams *free_teams_list(t_teams *teams);
t_channels *free_channels_list(t_channels *channels);
t_client *free_clients_list(t_client *clients);
void free_all_data(t_data *data);
t_channels *free_channels_list(t_channels *channels);

/* ---------- free_messages_list.c ----------*/
t_messages *free_messages_list(t_messages *messages);

/* ---------- free_threads_list.c ----------*/
void free_thread_occurence(t_threads *threads);
t_threads *free_threads_list(t_threads *threads);

/* ---------- free_users_list.c ----------*/
t_user *free_users_list(t_user *user);

/* ---------- stock_channels.c ----------*/
void print_channels_in_file(t_channels *channels, FILE *fd);
t_channels *save_channels_in_file(t_channels *channels, FILE *fd);

/* ---------- stock_comments.c ----------*/
void print_comments_in_file(t_comments *comments, FILE *fd);
void save_comments_in_file(t_threads *threads, FILE *fd);

/* ---------- stock_data_file.c ----------*/
void stock_data_in_file(t_data *data);

/* ---------- stock_messages.c ----------*/
void print_messages_in_file(t_messages *messages, FILE *fd);
t_messages *save_messages_in_file(t_messages *messages, FILE *fd);

/* ---------- stock_teams.c ----------*/
void print_teams_in_file(t_teams *teams, FILE *fd);
t_teams *save_teams_in_file(t_teams *teams, FILE *fd);

/* ---------- stock_threads.c ----------*/
void print_threads_in_file(t_threads *threads, FILE *fd);
t_threads *save_threads_in_file(t_threads *threads, FILE *fd);

/* ---------- stock_user.c ----------*/
t_user *put_user_status_to_0(t_user *user);
void print_user_in_file(t_user *user, FILE *fd);
t_user *save_user_in_file(t_user *user, FILE *fd);

#endif
