#include <stdio.h>
#include <stdlib.h>

int main(){
	char mode[2] = "\0";
	char name[99] = "\0";
	char nameOut[99] = "\0";
	char file[99] = "\0";
	char op[99] = "\0";
	int num;
	int error = 0;

	gets(mode);		

	gets(file);	
	sprintf(op,"gcc %s",file);
	system(op);

	scanf("%d",&num);
	gets(name);
	if(*mode == 'r'){
	printf("You selected read only mode\n");
	for(int i =0;i<num;i++){
		gets(name);
		sprintf(op,"./a.out < %s",name);
		system(op);
		printf("\n");

	}
}
	else if(*mode == 'd'){
	for(int i =0;i<num;i++){
		int checker;
		gets(name);
		sprintf(op,"./a.out < %s > myoutput.txt",name);
		system(op);
		gets(nameOut);
		sprintf(op,"diff %s myoutput.txt",nameOut);
		checker  =system(op);
		if(checker){
			printf("Error in %s\n",name);
			error ++;


		}else continue;
		printf("\n");

	}
	printf("\nTotal error count: %d",error);

}








	return 0;
}
