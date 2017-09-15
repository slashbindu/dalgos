/*
 * phnum2keys.c
 *
 *  Created on: Sep 14, 2017
 *      Author: bindus
 */
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <string.h>



#define MAX_KEY_CHARS 9



char * alphabet_map[] = {	"0",	//0
				"1",	//1
				"ABC",	//2
				"DEF",	//3
				"GHI",	//4
				"JKL",	//5
				"MNO",	//6
				"PQRS",	//7
				"TUV",	//8
				"WXYZ"	//9
			 };


void
print_combo(char* psnumber, int curdigit, char * output_buf, int o_ind){

	//base case
	if(psnumber[curdigit] == '\0'){
		assert(curdigit == o_ind);
		printf("%s\t", output_buf);
		return;
	}

	if(psnumber[curdigit] != '\0'){
		int curnum = psnumber[curdigit] - '0';
		int nchars = strlen(alphabet_map[curnum]);
		char *pcharr = alphabet_map[curnum];
		int i;
		for(i = 0; i < nchars; i++){
			output_buf[o_ind] = pcharr[l];
			print_combo(psnumber, curdigit+1, output_buf, o_ind+1);
		}
	}
}

void
print_all_combos(char  *numstr){


	int curdigit = 0;
	char  output_buf[MAX_KEY_CHARS];
	memset(output_buf, 0, MAX_KEY_CHARS);
	int out_ind = 0;
	print_combo(numstr, curdigit, output_buf,  out_ind );
}

void
main(int argc, char *argv[]){

	char  *numstr = argv[1];
	if(!numstr){
		printf("Usage error :Enter  upto 9 digits \n");
		return;
	}
	print_all_combos(numstr);
}
