#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node{
	char data;
	struct s_node *next;
}		t_node;

t_node *new_node(int c)
{
	t_node *new;
	
	new = malloc(sizeof(t_node));
	new->data = c;
	new->next = NULL;
	return (new);
}
void ft_lstclear(t_node **head)
{
	t_node *temp;
	t_node *holder;

	temp = *head;
	while (temp)
	{
		holder = temp->next;
		free(temp);
		temp = holder;
	}
	*head = NULL;
}

int check_it(t_node **head, int c, int *lent)
{
	int i ;
	t_node *temp;
	t_node *new;

	temp = *head;
	i = 0;
	new = new_node(c);
	while (temp->next)
	{
		if (c == temp->data) // element was found.
		{
			ft_lstclear(head);
			*head = new;
			*lent = 0;// tell our main function
			return (0);
		}
		temp = temp->next; // it shoudlnt end at null.
	}
	// here we are the last node;
	if (c == temp->data) // element was found.
	{
		ft_lstclear(head);
		*head = new;
		*lent = 0;
		return (0);
	}
	else
	{
		temp->next = new;
		return (1);
	}
}

int main()
{
	// should keep count of longest previous string, the problem is that i reset the count.
	int c = 97;
	t_node *head;
	char *str = "abaea";
	int i = 1;
	int max_len = 1;
	int len = 1;
	head = new_node(str[0]);
	int *lent = (int *)malloc(4);
	while (str[i])
	{
		*lent = 1;
		len += check_it(&head, str[i], lent); // if is not in len++
		if (*lent == 0)// else store max_len.
		{
			if (len > max_len)
				max_len = len;
			len = 1;
		}
		i++;
	}
	printf("%d", max_len);
	ft_lstclear(&head);
}
