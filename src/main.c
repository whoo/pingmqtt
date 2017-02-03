#include <stdlib.h>
#include <mosquitto.h>
#include "ping.h"





int main(int argc, char **argv)
{
	struct mosquitto *bee;
	int a;
	char *on="alive";
	char *off="down";
	char hostname[80];
	char *host="bberry";
	mosquitto_lib_init();


	bee=mosquitto_new("dd",0,NULL);
	mosquitto_username_pw_set(bee,"dd","capique");
	mosquitto_connect(bee,"192.168.2.30",1883,120);
	sprintf(hostname,"ping/%s",host);
	printf("%s",hostname);

	if (ping(host)==0)
	mosquitto_publish(bee,&a,hostname,strlen(on),on,0,0);
	else
	mosquitto_publish(bee,&a,hostname,strlen(off),off,0,1);

	mosquitto_disconnect(bee);
	mosquitto_lib_cleanup();
	

	return 0;
}
