#include "../includes/minishell.h"


// START TEST 
void ft_print_env(t_env **env)
{
    t_env *cur;

    cur = *env;
    while (cur)
    {   
        printf("%s\n", cur->str);
        // printf("key = %s\n", cur->key);
        // printf("value = %s\n", cur->value);
        cur = cur->next;
    }
}
// END TEST


void print_token(t_data *data)
{
	t_cmd_line	*command;
	t_token		*current_token;
	int i = 0;
	int j = 1;
	command = data->cmd_list;
	while (command)
	{
        printf("\ncommande -> %d\n", j++);
		current_token = command->token_list;
		while (current_token)
		{
			printf("token[%d] = %s\n", ++i, current_token->token);
			printf("Type = %d\n", current_token->type);
			current_token = current_token->next;
		}
		command = command->next;
	}
}
