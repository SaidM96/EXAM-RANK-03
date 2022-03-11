/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:11:25 by smia              #+#    #+#             */
/*   Updated: 2022/03/11 17:25:00 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
    char tmp[800000];
    char buff[0];
    char *line;
    int i = 0;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    tmp[i] = '\0';
    while (read(fd, buff, 1) == 1)
    {
        tmp[i] = buff[0];
        tmp[i + 1] = '\0';
        if (tmp[i] == '\n')
        {
            i++;
            break ;
        }
        i++;
    }
    if (tmp[0] == '\0')
        return (NULL);
    line = malloc (i + 1);
    i = 0;
    while (tmp[i])
    {
        line[i] = tmp[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

#include <stdio.h>
#include <fcntl.h>

int main ()
{
    char *line;
    int  fd;

    fd = open("get_next_line.c", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}