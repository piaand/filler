/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:15:43 by pandersi          #+#    #+#             */
/*   Updated: 2020/07/16 11:39:41 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

int main(int argc, char **argv) {
	if (argc == 2)
	{
		char *file_name;
		char ch;
   		FILE *fp;

		file_name = argv[1];

		fp = fopen(file_name, "r"); // read mode
		if (fp == NULL)
		{
			perror("Error while opening the file.\n");
			exit(EXIT_FAILURE);
		}

		printf("Plateau 14 30:\n");
		printf("012345678901234567890123456789\n");
		
		while((ch = fgetc(fp)) != EOF)
			printf("%c", ch);

		fclose(fp);
		printf("Piece 3 6:\n");
		printf(".****.\n");
		printf("**....\n");
		printf("*.....\n");
	} else {
		ft_putendl("Gimme a map in file");
	}

	return (0);
}