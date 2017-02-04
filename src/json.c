#include "json.h"

#define S	json_object_get_string
#define I	json_object_get_int
#define G	json_object_object_get_old
#define A	json_object_array_get_idx

json_object * json_object_object_get_old(json_object * obj, const char * name) {
    json_object * sub;
    return json_object_object_get_ex(obj, name, & sub) ? sub : NULL;
}



char  *readfile(char *name)
{
FILE  *file = fopen( name , "r");
char *buf;

buf=(char *)malloc(MAX);

if (file) {
	fread(buf, 1, MAX, file);
	fclose(file);
	return buf;
}
return NULL;
}


void*	get(char *tb[],json_object *obj)
{

	json_object *tmp;
//	int type;
	tmp=obj;

					int a=0;
					char **ret;

	for (a=0;tb[a];a++)
	{
		tmp=G(tmp,tb[a]);
	}


	switch (json_object_get_type(tmp))
	{
		case json_type_string: return (void*)S(tmp); break;
		case json_type_int: return (void*)I(tmp); break;
		case json_type_array: 
					ret=malloc(sizeof(char)*20*20);
					for (a=0;a<json_object_array_length(tmp);a++)
					{
					ret[a]=(char *)S(A(tmp,a));
					
					}
					ret[a]=NULL;
					return (void*)ret;

					 break;
		default:
		return (void*)S(tmp);


	}
}


/*
int main(int argc,char **argv)
{
 
json_object * jobj = json_tokener_parse(readfile("param.json"));

char **tb;

//printf("%s",S(G(G(jobj,"server"),"mosquitto")));
printf("port :%d\n", (int *) get((char *[]){"server","port",NULL},jobj) );
printf("server: %s\n", (char *) get((char *[]){"server","user",NULL},jobj) );
printf("password: %s\n", (char *) get((char *[]){"server","password",NULL},jobj) );


//printf("table: %d\n", (int *) get((char *[]){"hosts",NULL},jobj) );

tb=(char **) get((char *[]){"hosts",NULL},jobj);
for(int a=0; tb[a];a++) { printf("host %s\n",tb[a]); }


return 0;
}

*/




