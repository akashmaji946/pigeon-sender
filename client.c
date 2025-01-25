#include "pigeon.h"


bool sendEmail(Email* email, Server* server){

    int8 buf[256];
    zero(buf, 256);

    // establish TCP connection
    struct sockaddr_in sock;

    signed int tmp;
    int16 s;

    tmp = socket(AF_INET, SOCK_STREAM, 0);
    assert(tmp > 0);

    s = (int16)tmp;

    sock.sin_family = AF_INET;
    sock.sin_port = htons(587);
    sock.sin_addr.s_addr = server->ip;

    tmp = connect($i s, (struct sockaddr*)&sock, sizeof(struct sockaddr));
    assert(tmp == 0);

    // check
    printf("Connected to %s...\n", server->server);

    zero(buf, 256);
    tmp = read($i s, $c buf, 255);

    dprintf($i s, "EHLO %s\n", email->domain);

    zero(buf, 256);
    tmp = read($i s, $c buf, 255);
    printf("From Server: %s\n", $c buf);

    // close
    close(s);

    return true;


}

bool sendMailHelper(char* from_addr, char* server_addr, char* server_ip){
    
    Email* email;
    Server* server;

    email = malloc(sizeof(Email));
    server = malloc(sizeof(Server));

    memset(email, 0, sizeof(Email));
    memset(server, 0, sizeof(Server));

    strncpy(email->src, from_addr, 63);
    email->domain = email->src + 13;
    strncpy(server->server, server_addr, 63);
    server->ip = inet_addr(server_ip);

    printf("______________Calling_______________\n");
    bool ret = sendEmail(email, server);
    printf("______________Success_______________\n");

    // free 
    free(email);
    free(server);

    return ret;

}

// we will connect to this email server at port and with the ip
// telnet smtp.gmail.com 587
// host -t a smtp.gmail.com

// will be removed later
int main(int argc, char* argv[]){

    sendMailHelper("akashmaji945@gmail.com", 
                   "smtp.gmail.com", 
                   "142.251.12.109");

    

    return 0;
}