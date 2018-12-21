#include "main.h"


int main(int argc, const char* argv[]) {
    if(argc != 3){
        printf("Not enough arguments, please pass an IP and Port, example: ./server 127.0.0.1 80\n");
        exit(1);
    }
    char* ip_addr = (char *) argv[1];//(char *) "127.0.0.1";
    int port = atoi(argv[2]);
    server = Server(port, ip_addr);
    server.startup();

    while (true){
        server.connect();

        char* data = "T5:50;College Lokaal;11:30 - 13:30;13:30 - 15:30;Engels 2;Engels1;Gidooooo;Tijntje"; 

//        if(data == "\0") printf("Dat nullterminator tho\n");

        server.sendData(data);

        server.disconnect();
    }
    return 0;
}
