#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_node{
	char *data;
	struct s_node *next;
}		t_node;



int  tell_type(int c, int *type)
{
	if (c == ']' || c == ')') //closer
		*type = -2;
	else
		*type = -3;
	return (c);
}

int ft_strrchr(int i, char *charset, int *type)
{
	int j;
	j = 0;
	while (charset[j])
	{
		if (charset[j] == i)
			return (tell_type(i, type));
		j++;
	}
	return (0);
}

t_node *push_stack(int c)
{
	t_node *new;
	new = malloc(sizeof(t_node));
	new->data = strdup(&c);
	new->next = NULL;
	return (new);
}
int pop_it(t_node **head, int c) // only free, if nothing found return 0
{
	char expected;
	char current_data;
	t_node *new_top;
	t_node *holder;
	new_top = *head;
	if (head == NULL || *head == NULL)
		return (0); // FAIL
	if (c == ']')
		expected = '[';
	if (c == ')')	
		expected = '(';
	if (*(new_top->data) != expected)
		return (0);
	holder = new_top->next;
	free(new_top->data);
	free(new_top);
	*head = holder; //this resets our head.
}
	
int node_checker()
{
	// closer is -2. openeer is -3
	int i = 0;
	int a;	
	int b ;
	int *type = (int *)malloc(4);
	char *str = "helli[[o";
	t_node *head = NULL;
	t_node *prev = NULL;
	char *charset = "[]()";
	while (str[i])
	{
		b = -1;
		*type = 0;
		a = ft_strrchr(str[i], charset, type);
		if (a != 0 && *type == -2)
			b = pop_it(&head, a);
		if (b == 0)
			return (-2);
		if (a != 0 && *type == -3)
		{
			prev = head;
			head = push_stack(a);
			head->next = prev;// would handle the null ?
		}		
		i++;
	}
	if (head != NULL)
		return (-2);
	return (2); //succes
}

int main()
{
	int d = node_checker();
	printf("%d", d);
}
