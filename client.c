#include<stdio.h> 
#include<string.h> 
#include<sys/socket.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<netinet/in.h> 
#include<netdb.h> 
#include<arpa/inet.h> 
intmain(intargc,char*argv[]) 
{ 
intcd,sd,ad; 
charbuff[1024]; 
structsockaddr_incliaddr,servaddr; 
structhostent*h; 
/*Thisfunctionlooksupahostnameanditreturnsapointertoahostent structurethatcontainsalltheIPV4address*/ 
h=gethostbyname(argv[1]); 
bzero(&servaddr,sizeof(servaddr)); 
/*Socketaddressstructure*/ 
servaddr.sin_family=AF_INET; 
memcpy((char*)&servaddr.sin_addr.s_addr,h->h_addr_list[0],h->h_length); servaddr.sin_port=htons(1999); 
/*Creatingasocket,assigningIPaddressandportnumberforthatsocket*/ sd=socket(AF_INET,SOCK_STREAM,0); 
/*ConnectestablishesconnectionwiththeserverusingserverIPaddress*/ cd=connect(sd,(structsockaddr*)&servaddr,sizeof(servaddr));
while(1) 
{ 
printf("Enterthemessage:\n"); 
/*Readsthemessagefromstandardinput*/ 
fgets(buff,100,stdin); 
/*Sendfunctionisusedonclientsidetosenddatagivenbyuseronclient sidetotheserver*/ 
send(sd,buff,sizeof(buff)+1,0); 
printf("\nDataSent"); 
recv(sd,buff,strlen(buff)+1,0); 
printf("%s",buff); 
} 
} 
