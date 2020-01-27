/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaouil <ztaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 07:58:39 by ztaouil           #+#    #+#             */
/*   Updated: 2019/11/02 20:38:51 by ztaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int             last_line(char **str, char *buff, char *temp,
		char **line)
{
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	free(buff);
	return (0);
}

int             gotcha(char **str, char *temp, char **line, char *buff)
{
	int len;

	len = ft_strchr(*str, '\n') - *str;
	temp = *str;
	*line = ft_substr(*str, 0, len);
	*str = ft_strdup(*str + len + 1);
	free(temp);
	free(buff);
	return (1);
}

int             test(int fd, char **line)
{
	int             a;
	char    c;

	a = read(fd, &c, 0);
	if (a < 0 || fd < 0 || line == NULL)
		return (0);
	return (1);
}

int             exit(char *buff)
{
	free(buff);
	return (-1);
}

int             get_next_line(int fd, char **line)
{
	char                    *buff;
	char                    *temp;
	static char             *str;
	int                             re;

	if (test(fd, line) == 0)
		return (-1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(str, '\n') == NULL)
	{
		temp = str;
		if ((re = read(fd, buff, BUFFER_SIZE)) < 0)
			return (exit(buff));
		buff[re] = '\0';
		str = ft_strjoin(str, buff);
		free(temp);
		if (re == 0)
			return(last_line(&str, buff, temp, line ));
	}
	if (ft_strchr(str, '\n'))
		return (gotcha(&str, temp, line, buff));
}
