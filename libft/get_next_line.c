/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:00:35 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/16 15:02:35 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The return value can be 1, 0 or -1 depending on whether a line has been read,
** when the reading has been completed, or if an error has happened
** respectively.
*/

#include "includes/libft.h"

/*
** Returns 1 when string save had a line to return, 0 when save is empty
** and reading is complete and -1 in error case.
*/

int		ft_empty_save(int ret, char **save, char **line)
{
	if (ret == -1)
		return (-1);
	else if (*save && *save[0] != '\0')
	{
		if (!(*line = ft_strdup(*save)))
			return (-1);
		ft_strdel(save);
		return (1);
	}
	else
	{
		*line = NULL;
		return (0);
	}
}

/*
** Returns a substring *line of save that is a copy of save until \n character.
** Then forms a new save string that hasn't the get next line to print.
*/

char	*ft_form_next_line(char **line, char *save)
{
	char		*temp;
	size_t		i;

	if (!(*line = ft_strnew(ft_strlen(save))))
		return (NULL);
	i = ft_strccpy(*line, save, 10);
	if (!(temp = ft_strnew(ft_strlen(save))))
	{
		ft_strdel(line);
		return (NULL);
	}
	i = ft_strccpy(temp, &save[++i], '\0');
	ft_strdel(&save);
	if (!(save = ft_strdup(temp)))
	{
		ft_strdel(&temp);
		ft_strdel(line);
		return (NULL);
	}
	ft_strdel(&temp);
	return (save);
}

/*
** Checks weather we have newline character in save and calls
** ft_form next_line when needed. Returns 1, -1 or 0 depending on whether
** a new save string has been formed, smth went wrong or newline was not found.
*/

int		ft_check_save(char **save, char **line)
{
	char		*temp;

	if (*save)
	{
		temp = *save;
		if ((*save = ft_strchr(*save, 10)))
		{
			*save = temp;
			if (!(*save = ft_form_next_line(line, *save)))
				return (-1);
			return (1);
		}
		else
		{
			*save = temp;
			temp = NULL;
			return (0);
		}
	}
	return (0);
}

/*
** Takes the read input from read function and joins it to the static string
** save. Then examines weather save has newline character. Returns 1, -1 or 0
** depending on whether a new save string has been formed, smth went wrong or
** newline was not found.
*/

int		ft_read_buff(char *buff, char **save, char **line)
{
	char		*temp;
	int			ret;

	if (!*save)
	{
		if (!(*save = ft_strdup(buff)))
			return (-1);
	}
	else
	{
		if (!(temp = ft_strdup(*save)))
			return (-1);
		ft_strdel(save);
		if (!(*save = ft_strjoin(temp, buff)))
			return (-1);
		ft_strdel(&temp);
	}
	if ((ret = ft_check_save(save, line)) == -1 || ret == 1)
		return (ret);
	else
		return (0);
}

/*
** Takes a fied descriptor and address of a pointer to a string character.
** Alters the string behind pointer address to include the next line found
** bedind the fd.
*/

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*save;
	int			ret;

	if (fd < 0 || fd > 4864 || !line || BUFF_SIZE < 1)
		return (-1);
	else if ((ret = ft_check_save(&save, line)) == -1 || ret == 1)
		return (ret);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((ret = ft_read_buff(buff, &save, line) == 1 || ret == -1))
			return (ret);
	}
	return (ft_empty_save(ret, &save, line));
}
