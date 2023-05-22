#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int argc;
    char **argv;
} CommandInfo;

int is_chain(CommandInfo *info, char *buf, char *p);
int check_chain(CommandInfo *info, char *buf, char *p, int i, int len);
int replace_alias(CommandInfo *info);
int replace_vars(CommandInfo *info);
int replace_string(char **old, char *new);

int is_chain(CommandInfo *info, char *buf, char *p) {
    if (*p == '\0') 
	{
	return 1; 
	}

	if (*p == '$')
	{
	return (replace_vars(info));
	}

	if (*p == '!')
{
	return (replace_alias(info));
}
	return (check_chain(info, buf, p, 0, info->argc));
}

int check_chain(CommandInfo *info, char *buf, char *p, int i, int len) {
	int j;

	if (i == len)
	{
	return (0);
	}
	for (j = 0; info->argv[i][j] != '\0'; j++) {
		if (info->argv[i][j] != *p) {
		return check_chain((info, buf, p, i + 1, len));
	}
	p++;
	}

	if (*p != '\0')
	{
		return (check_chain(info, buf, p, i + 1, len));
	}

	strcpy(buf, info->argv[i]);
	return (1);
}

int replace_alias(CommandInfo *info) {
	char buf[256];
	char *p;

	if (info->argc == 0) {
	return 0;
	}
	p = buf;
	if (is_chain(info, buf, p)) 
	{
		replace_string(&info->argv[0], _strdup(buf))
	}

	return (0);
}

int replace_vars(CommandInfo *info) {
	int i;

    for (i = 0; i < info->argc; i++) {
	if (strchr(info->argv[i], '$') == NULL) {
		continue;
	}
		replace_string(&info->argv[i], _strdup(""));
	}

	return (0);
}

int replace_string(char **old, char *new) {
	free(*old);
	*old = new;
	return (1);
}

