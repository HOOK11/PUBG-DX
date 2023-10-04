#include "stdafx.h"
#include "w3c_u.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	 W3Client w3;
 
	 W3Client client;

 if(client.Connect("https://w.eydata.net")){
	 client.AddPostArgument("UserName","a123456");
	 client.AddPostArgument("UserPwd","a123456");
	 client.AddPostArgument("Version","1.0");
	 client.AddPostArgument("Mac","");
  if(client.Request("/113e19e537af76e0", W3Client::reqPost)){
   char buf[1024]="\0";
   while(client.Response(reinterpret_cast<unsigned char*>(buf), 1024)>0){
    cout << buf << endl;
    memset(buf, 0x00, 1024);
   }
  }
  client.Close();
 }
	return 0;
}