/*
** EPITECH PROJECT, 2020
** B-NWP-400-LYN-4-1-myteams-maxime.simon
** File description:
** data_parsing.h
*/

#ifndef DATA_PARSING_H_
#define DATA_PARSING_H_

#include "server.h"

/* ---------- channels_parsing.c ----------*/
t_channels *add_channels_in_list(t_channels *channels, char **array);
t_data *parse_channels(t_data *channels, char *line);

/* ---------- comments_parsing.c ----------*/
void add_comments_in_list(t_comments **comments, char **array);
t_data *parse_comments(t_data *data, char *line);

/* ---------- messages_parsing.c ----------*/
t_messages *add_message_in_list(t_messages *message, char **array);
t_data *parse_messages(t_data *data, char *line);

/* ---------- parsing_data_file.c ----------*/
char **retrieve_clean_value(char **array);
t_data *parsing_data(t_data *data);

/* ---------- teams_parsing.c ----------*/
t_teams *add_teams_in_list(t_teams *teams, char **array);
t_data *parse_teams(t_data *data, char *line);

/* ---------- threads_parsing.c ----------*/
t_threads *add_threads_in_list(t_threads *threads, char **array);
t_data *parse_threads(t_data *data, char *line);

/* ---------- users_parsing.c ----------*/
t_user *add_user_in_list(t_user *user, char **array);
t_data *parse_user(t_data *data, char *line);

#endif/* DATA_PARSING_H_ */
