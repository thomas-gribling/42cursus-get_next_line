/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:56:36 by tgriblin          #+#    #+#             */
/*   Updated: 2023/10/27 10:35:00 by tgriblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

char	*ft_fill_stash(int fd, char *stash)
{
	char	*out;
	char	*tmp;
	int		rd;

	tmp = malloc(BUFFER_SIZE + 1);
	if (stash)
	{
		out = ft_strdup(stash);
		free(stash);
	}
	else
		out = ft_strdup("");
	if (!tmp || !out)
		return (free_null(tmp, out));
	rd = 1;
	while (!ft_strchr(out, '\n') && rd > 0)
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd < 0)
			return (free_null(tmp, out));
		tmp[rd] = '\0';
		out = ft_strjoin(out, tmp);
	}
	free(tmp);
	return (out);
}

char	*ft_get_line(char *stash)
{
	char	*out;
	int		i;

	i = 0;
	if (!stash || !(*stash))
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	out = malloc(i + 2);
	if (!out)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		out[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		out[i] = '\n';
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_del_line(char *stash)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	i++;
	out = malloc(ft_strlen(stash) - i + 2);
	if (!out)
		return (NULL);
	j = 0;
	while (stash[i + j - 1])
	{
		out[j] = stash[i + j];
		j++;
	}
	out[j] = '\0';
	free(stash);
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	stash[fd] = ft_fill_stash(fd, stash[fd]);
	if (!stash[fd] || !(*stash[fd]))
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_del_line(stash[fd]);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int 	file;
	int		file2;
	char	*line;

	file = open("file.txt", O_RDONLY);
	file2 = open("file2.txt", O_RDONLY);
	line = get_next_line(file);
	printf("%s", line);
	free(line);
	line = get_next_line(file2);
	printf("%s", line);
	free(line);
	line = get_next_line(file2);
	printf("%s", line);
	free(line);
	line = get_next_line(file);
	printf("%s", line);
	free(line);
	line = get_next_line(file);
	printf("%s", line);
	free(line);
	line = get_next_line(file2);
	printf("%s", line);
	free(line);
	close(file);
	close(file2);
}*/
