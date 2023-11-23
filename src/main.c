#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

void read_status(char *server_name, const char* filepath)
{
	char status[265];
	FILE *fp = NULL;
	
	printf("Enter Servername: ");
	fflush(stdout);
	scanf("%s", server_name);
	
	printf(server_name);
	printf(" status: ");
	fflush(stdout);
	scanf("%s", status);

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	fp = fopen(filepath, "a");
	if(fp == NULL)
	{
		fprintf(stderr, "Unable to open %s: %s\n", filepath, strerror(errno));
		exit(EXIT_FAILURE);
	}
	fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d %s health: %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,  server_name, status);
	fclose(fp);
	
	return;
}

int main(int argc, char* argv[])
{
	char server_name[256];
	char logger_cmd[1024];
	int ret = 0;

	if(argc != 2)
	{
		fprintf(stderr, "usage: %s <logfile>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	read_status(server_name, argv[1]);
	strcpy(logger_cmd, "/usr/bin/logger ");
	strcat(logger_cmd, server_name);
	strcat(logger_cmd, " healthcheck submitted\0");
	system(logger_cmd);
	exit(EXIT_SUCCESS);
}
