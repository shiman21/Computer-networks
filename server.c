#include<sys/types.h> 
#include<sys/socket.h> 
#include<netinet/in.h> 
#include<netdb.h> 
#include<arpa/inet.h> 
#include<string.h> 
intmain(intargc,char*argv[]) 
{ 
intbd,sd,ad; 
charbuff[1024]; 
structsockaddr_incliaddr,servaddr; 
socklen_tclilen;
clilen=sizeof(cliaddr); 
bzero(&servaddr,sizeof(servaddr)); 
/*Socketaddressstructure*/ 
servaddr.sin_family=AF_INET; 
servaddr.sin_addr.s_addr=htonl(INADDR_ANY); 
servaddr.sin_port=htons(1999); 
/*TCPsocketiscreated,anInternetsocketaddressstructureisfilledwithwildcardaddress& server’swellknownport*/ 
sd=socket(AF_INET,SOCK_STREAM,0); 
/*Bindfunctionassignsalocalprotocoladdresstothesocket*/ 
bd=bind(sd,(structsockaddr*)&servaddr,sizeof(servaddr)); 
/*Listenfunctionspecifiesthemaximumnumberofconnectionsthatkernelshouldqueuefor thissocket*/ 
listen(sd,5); 
printf("Serverisrunning….\n"); 
/*Theservertoreturnthenextcompletedconnectionfromthefrontofthe completedconnectionQueuecallsit*/ 
ad=accept(sd,(structsockaddr*)&cliaddr,&clilen); 
while(1) 
{ 
bzero(&buff,sizeof(buff)); 
/*Receivingtherequestmessagefromtheclient*/ 
recv(ad,buff,sizeof(buff),0); 
printf("Messagereceivedis%s\n",buff);
} 
} 
