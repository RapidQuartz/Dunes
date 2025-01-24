	//	new-stack-entry
t_stack	*new_stack_entry(int value);
	//	find-stack-bottom
t_stack	*find_stack_bottom(t_stack *stack);
	//	add-to-bottom
void		add_to_bottom(t_stack **stack, t_stack *new);
	//	give-stack-index
void		give_stack_index(t_stack **stack);
	//	find-stack-position
t_stack	*find_stack_position(t_stack *stack, int	size);
	//	give-stack-position
void		give_stack_position(t_stack **stack, t_stack **high);
	//	give-stack-size
int		give_stack_size(t_stack *stack);