// void	printparser(t_asm *asmb)
// {
// 	t_inst *inst;
// 	t_label *labels;

// 	labels = asmb->labels;
// 	inst = asmb->inst;
// 	// ft_printf("{yellow}<---LABELS--->{reset}\n");
// 	ft_printf("<---LABELS--->\n");
// 	while (labels)
// 	{
// 		ft_printf("name : %s\n", labels->name);
// 		ft_printf("addr : %d\n", labels->addr);
// 		labels = labels->next;
// 	}
// 	ft_printf("|------------|\n");
// 	ft_printf("<---INST--->\n");
// 	// ft_printf("{yellow}|------------|{reset}\n");
// 	// ft_printf("{yellow}<---INST--->{reset}\n");
// 	int i;
// 	int j;
// 	while (inst)
// 	{
// 		i = 0;
// 		j = 0;
// 		// ft_printf("inst->opcode : %d\n", (int)inst->opcode);
// 		// ft_printf("inst->ocp : %d\n", (int)inst->ocp);
// 		// ft_printf("inst->direct_len : %d\n", (int)inst->direct_len);
// 		// ft_printf("inst->param_byte : %d\n", inst->param_byte);
// 		// ft_printf("inst->param_num : %d\n", (int)inst->param_num);
// 		// ft_printf("inst->addr : %d\n", inst->addr);
// 		// ft_printf("inst->len : %d\n", inst->len);
// 		ft_printf("inst->opcode : %c\n", inst->opcode);
// 		ft_printf("inst->ocp : %c\n", inst->ocp);
// 		ft_printf("inst->direct_len : %c\n", inst->direct_len);
// 		ft_printf("inst->param_byte : %d\n", inst->param_byte);
// 		ft_printf("inst->param_num : %c\n", inst->param_num);
// 		ft_printf("inst->addr : %d\n", inst->addr);
// 		ft_printf("inst->len : %d\n", inst->len);
// 		while (inst->param_arr[i])
// 		{
// 			j = 0;
// 			while (inst->param_arr[i][j])
// 			{
// 				ft_printf("inst->param_arr : %c\n", inst->param_arr[i][j]);
// 				j++;
// 			}
// 			i++;
// 		}
// 		inst = inst->next;
// 	}
// }