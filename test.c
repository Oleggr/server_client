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

	printf("\n");

	char Request[200] = {0};
	snprintf(Request, sizeof Request, "%s%s%s%s%c", http_header, auth_header, auth_token, int_header, num);

	printf(Request);
	printf("\n---\n");

	char auth_h[] = "Authenfication:";
	int auth_h_len = strlen(auth_h);
	printf("%s\n",auth_h);
	printf("%d\n", auth_h_len);
 
	char param1_h[] = "Int_param:";
	int param1_h_len = strlen(param1_h);
	
	int i;
	int j;
	int counter = 0;

	int token_start;
	int token_end;

	for (i = 0; i < strlen(Request); ++i) {

		// Поиск начала токена
		counter = 0;

		if (Request[i] == auth_h[0]) {

			++counter;
			printf("%c\n", Request[i]);

			for (j = 1; j < auth_h_len; ++j) {

				if (Request[i + j] != auth_h[j]) 
					break;

				else {
					++counter;
					printf("%d", counter);
					printf("%c\n", Request[i + j]);
				}
			}
		}

		if (counter == auth_h_len) {
			printf("%s: %d\n%c\n", "first i", i, Request[i]);
			printf("%s: %d\n%c\n", "last i", i + auth_h_len - 1, Request[i + auth_h_len - 1]);
			token_start = i + auth_h_len;
			break;
		}
	}


	for (i = token_start; i < strlen(Request); ++i) {

		// Поиск конца токена
		counter = 0;

		if (Request[i] == param1_h[0]) {

			++counter;
			printf("%c\n", Request[i]);

			for (j = 1; j < param1_h_len; ++j) {

				if (Request[i + j] != param1_h[j]) 
					break;

				else {
					++counter;
					printf("%d", counter);
					printf("%c\n", Request[i + j]);
				}
			}
		}

		if (counter == param1_h_len) {
			printf("%s: %d\n%c\n", "first i", i, Request[i]);
			printf("%s: %d\n%c\n", "last i", i + param1_h_len - 1, Request[i + param1_h_len - 1]);
			token_end = i;
			break;
		}
	}

	char *token_s;
	char *token_e;


	// for (i = token_start; i <= token_end; ++i) {
	// 	token = Request[token_start];
	// 	// printf("%c", Request[i]);
	// }

	token_s = Request + token_start;
	token_e = Request + token_end;

	// token_e -= token_s;
	printf("token:%s", token_s);
	printf("token:%s", token_e);


	printf("\n");
}