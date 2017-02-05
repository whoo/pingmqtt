#include <stdlib.h>
#include <mosquitto.h>
#include "ping.h"
#include "json.h"
#include "tcp.h"




int mainloop()
{

	struct mosquitto *bee;
	int ret;
	int tm_wait;
	char *on="alive";
	char *off="down";
	char **tb;
	char hostname[20];


	json_object * jobj = json_tokener_parse(readfile("param.json"));

	mosquitto_lib_init();



	tm_wait=(int)get((char *[]){"sleep",NULL},jobj);
	
	bee=mosquitto_new("elementDD",0,NULL);
	mosquitto_username_pw_set(bee,
			(char*) get((char *[]){"server","user",NULL},jobj),
			(char*) get((char *[]){"server","password",NULL},jobj));


	mosquitto_connect(bee,
			(char*) get((char *[]){"server","mosquitto",NULL},jobj),
			(int)  get((char *[]){"server","port",NULL},jobj),
			120);

	tb=(char **) get((char *[]){"hosts",NULL},jobj);

	while (1)
	{

		for(int a=0; tb[a];a++) {

			sprintf(hostname,"ping/%s",tb[a]);

			if (pingTCP(tb[a]))
			{
	//			printf("host [%s] ok\n",hostname); 
				mosquitto_publish(bee,&ret,hostname,strlen(on),on,0,0);
			}
			else
				mosquitto_publish(bee,&ret,hostname,strlen(off),off,0,0);

			alarm(0);
			//	usleep(250*1000);

		}

		sleep(tm_wait);
	}




	mosquitto_disconnect(bee);
	mosquitto_lib_cleanup();

	return 0;
}


int main(int argc, char **argv)
{



int pid = fork();


  if (pid == -1)  
        return -1;  
    else if (pid != 0)  
        exit (EXIT_SUCCESS);

open ("/dev/null", O_RDWR);
dup (0);  
dup (0);  


return mainloop();
}

