#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 15

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

struct {
	char *cmd_name;
	void (*cmd_pointer)(void);
} file_cmd[] = {
	{"new", &new_cmd},
	{"open", &open_cmd},
	{"close", &close_cmd},
	{"close all", &close_all_cmd},
	{"save as", &save_as_cmd},
	{"save all", &save_all_cmd},
	{"print", &print_cmd},
	{"exit", &exit_cmd}
};

int num_cmd = sizeof(file_cmd) / sizeof(file_cmd[0]);

void run_cmd(char *str);
int read_line(int n, char str[n]);

int main(void)
{
	char str[MAX_LEN + 1];

	read_line(MAX_LEN, str);
	run_cmd(str);

	return 0;
}

void new_cmd(void)
{
	printf("new_cmd\n");
}

void open_cmd(void)
{
	printf("open_cmd\n");
}

void close_cmd(void)
{
	printf("close_cmd\n");
}

void close_all_cmd(void)
{
	printf("close_all_cmd\n");
}

void save_as_cmd(void)
{
	printf("save_as_cmd\n");
}

void save_all_cmd(void)
{
	printf("save_all_cmd\n");
}

void print_cmd(void)
{
	printf("print_cmd\n");
}

void exit_cmd(void)
{
	printf("exit_cmd\n");
}

void run_cmd(char *str)
{
	for (int i = 0; i < num_cmd; i++) {
		if (strcmp(str, file_cmd[i].cmd_name) == 0) {
			(*file_cmd[i].cmd_pointer)();
			return;
		}
	}
}

int read_line(int n, char str[n])
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		/* empty loop body */ ;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';

	return i;
}
