	close(1);
	fflush(stdout);
	char *s = "sdsd";
	int len = printf("ff %s    yff\n", s);
	int real_len = ft_printf("ff %s    yff\n", s);
	fflush(stdout);
	dup2(2, 1);
	printf("\nlen : %d\nreal len : %d\n", len, real_len);
	return (0);