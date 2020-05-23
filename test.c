#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>	

int main(void)
{
	const char *http_header = "GET / HTTP/1.1";	
	const char *auth_header = "\nAuthenfication:";
	const char *auth_token  = "Ae*%$3s8ac"; // 10 characters

	// const char *str_header = "Str_param:";
	const char *int_header = "\nInt_param:";

	char num; 
	// char ch;

	printf("Enter the integer: ");
	scanf("%c", &num);

	char Request[200] = {0};
	snprintf(Request, sizeof Request, "%s%s%s%s%c", http_header, auth_header, auth_token, int_header, num);

	printf(Request);
	printf("\n---\n");


	printf(Request[0]);
	// int i;
	// for (i = 0; i<200; ++i) {
	// 	printf(Request[i]);
	// 	printf(" ");
	// }
	printf("\n");
}