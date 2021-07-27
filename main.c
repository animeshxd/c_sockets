#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/* #define BUFFER_SIZE 128 */
#define NEWLINE printf("\n")
int main(){
	int socket_desc; // server description
	struct sockaddr_in server; //servet address and port

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	printf("%d\n",socket_desc);


	server.sin_family = AF_INET;
	server.sin_port = htons(80);
	server.sin_addr.s_addr = inet_addr("52.201.75.114");

	int status = connect(socket_desc, (struct sockaddr *)&server, sizeof(server));
	if (status < 0) return 0;
	else printf("connected\n");

	/* char *message = "POST /post HTTP/1.0\nContent-Type: application/x-www-form-urlencoded\nContent-Length: 27\n\nfield1=value1&field2=value2\n"; */
	char *message = "GET /image/png\n\n";



	status = send(socket_desc, message, strlen(message), 0);
	if (status < 0) return EXIT_FAILURE;
	else printf("message sent\n\n");
	FILE * file = fopen("new.png","a+");
	char buffer[128];
	int buff;
	while (1){buff = recv(socket_desc, buffer,127, 0);
		if (buff <= 0) break;
		puts(buffer);
		NEWLINE;

		fwrite(buffer, buff, 1, file);
		printf(" writting %d ", buff);}
		
	
	fclose(file);




	




}
