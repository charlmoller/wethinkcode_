/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:27:03 by cmoller           #+#    #+#             */
/*   Updated: 2018/11/24 16:27:05 by cmoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"
#include <stdio.h>

t_labels	*new_label(char *str, int i)
{
	t_labels	*label;

	label = (t_labels*)malloc(sizeof(t_labels));
	label->name = ft_strdup(str);
	ft_strchr(label->name, ':')[0] = '\0';
	label->index = i;
	label->next = NULL;
	return (label);
}

void		add_label(char *str, int i, t_labels **list)
{
	t_labels	*label;
	t_labels	*head;

	label = new_label(str, i);
	if (*list)
	{
		head = *list;
		while (head->next)
			head = head->next;
		head->next = label;
	}
	else
		*list = label;
}

int			create_labels(t_parser *parser, char *asml, int i, t_labels **list)
{
	char	**instructions;
	int		j;
	int		k;

	instructions = ft_strsplit(asml, ' ');
	if (((j = 0) + 1) && instructions && is_label(instructions[j]))
		add_label(instructions[j++], i, list);
	if (instructions && instructions[1] && (k = -1))
	{
		while (++k < 17)
		{
			if (ft_strequ(instructions[j], parser->op_tab[k].name))
			{
				i += (parser->op_tab[k].acb ? 2 : 1);
				break ;
			}
		}
		if (k >= 17)
			asm_parse_err(parser, "Invalid instruction\n");
		while (instructions[++j])
			i += instruction_val(parser, instructions[j], k);
	}
	free_split(instructions);
	return (i);
}

int			first_pass(t_parser *parser, t_labels **list)
{
	char	*r;
	int		i;
	char	*asml;

	parser->line = 0;
	parser->pos = 0;
	parser->pc = 0;
	i = 0;
	while ((asml = get_asm_line(parser)))
	{
		if (!(asml[0] == '.' || ft_strlen(asml) == 0))
		{
			while ((r = ft_strchr(asml, SEPARATOR_CHAR)))
				*r = ' ';
			i = create_labels(parser, asml, i, list);
		}
		FREEIF(asml);
	}
	return (i);
}

int			get_label_index(t_labels *list, char *label)
{
	t_labels	*curr;

	curr = list;
	while (curr)
	{
		if (ft_strequ(curr->name, label))
			return (curr->index);
		curr = curr->next;
	}
	ft_putstr("Found invalid label! ");
	ft_putstr(label);
	ft_putstr("\n");
	exit(0);
}
