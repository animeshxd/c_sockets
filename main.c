#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

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
	char *message = "GET /image/png\nimage/png\n";



	status = send(socket_desc, message, strlen(message), 0);
	if (status < 0) printf("Failed to send");
	else printf("message sent\n\n");

	char buffer[513];
	int buff = recv(socket_desc, buffer,512, 0);
	/* printf("%d",buff); */
	printf(" %c ", buffer[512]);
	printf("%s", buffer);
	memset(buffer, 0, 512);
	recv(socket_desc, buffer, buff, 0);
	printf("\n\n%s",buffer);
		
	recv(socket_desc, buffer, 500, 0);
	puts(buffer);


	




}
