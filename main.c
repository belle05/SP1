/*
 * SP1.c
 *
 *  Created on: Mar 27, 2017
 *      Author: nlevy
 */
#include <stdio.h>
#include <math.h>


int convert210(char word[],char dict[],int myBase) {
	int sum = 0;
	for (int i = 0; i<sizeof(word); i++){
		for (int l = 0; l<sizeof(dict);l++) {
			if (word[i]==dict[l]) {
				sum += l*(pow(myBase,i));
			}
		}
	}
	return sum;
}
void main()
{
	char dict[] = "0123456789ABCDEF";
	char dictA[] = "0123456789ABCDEF";
	char dictB[] = "0123456789ABCDEF";
	int baseA, baseB,sum;
	int found = 0;
	int index = 0;
	char word[20];
	char result[20];
	char Char;
	printf ("Please enter the number's base:\n");
	scanf ("%d", baseA);
	if(baseA>16 && baseA < 2) {
		printf ("Invalid input base\n");
	}
	dictA[baseA] = '\0';
	printf ("Please enter the desired base:\n");
	scanf ("%d", baseB);
	if(baseB>16 && baseB < 2) {
		printf ("Invalid input base\n");
	}
	dictB[baseB] = '\0';
	printf ("Please enter a number in base %d:\n",baseA);
	while ((Char = getchar() != EOF)) {
		for (int i=0; i<sizeof(dictA); i++){
			if (Char==dictA[i]){
				found = 1;
			}
		}
		if (found == 0){
			printf ("Invalid number!\n");
		}

		word[index] = Char;
		index++;
	}
	if (baseA!=10) {
		sum = convert210(word,dictA,baseA);
	} else {
		sum = sscanf(word,"%d",&sum);
	}



	printf ("The result is : %s\n",result);


}
