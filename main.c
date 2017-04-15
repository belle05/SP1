 /*
 *  Created on: Mar 27, 2017
 *      Author: nlevy
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void convertFrom10(int sum, char *dict, int newBase, char *result){
	int i, j, index;
	index = 0;
	char new_num[32];
	char tempChar;
	for (unsigned int i = 0; i<sizeof(new_num);i++) {
		new_num[i] = '\0';
	}
	while (sum!=0) {
		tempChar = dict[sum%newBase];
		new_num[index] = tempChar;
		index++;
		sum = sum / newBase;
	}

	//reversing the array
	for (unsigned int i = 0; i<sizeof(new_num);i++) {
		if (isdigit(new_num[i]) || new_num[i] == 'A' || new_num[i] == 'B' ||  new_num[i] == 'C' ||  new_num[i] == 'D' ||  new_num[i] == 'E' ||  new_num[i] == 'F'   ) {
			j = i;
		} else {
			new_num[i] = '\0';
		}
	}
	i = 0;
	while (i < j) {
		tempChar = new_num[i];
		new_num[i] = new_num[j];
		new_num[j] = tempChar;
		i++;
		j--;
	}
	sprintf(result, "%s", new_num);
}



int main()
{
	char dict[] = "0123456789ABCDEF";
	int baseA, baseB, sum;
	int found = 0;
	int index = 0;
	char result[20];
	char Char;
	char myChar;

	//Get first base
	printf ("Please enter the number's base:\n");
	scanf ("%d", &baseA);
	if(baseA>16 || baseA < 2) {
			printf ("Invalid input base\n");
			return 0;
	}

	char dictA[baseA];
	memcpy(dictA, dict, baseA);

	//Get second base
	printf ("Please enter the desired base:\n");
	scanf ("%d", &baseB);
	if(baseB>16 || baseB < 2) {
			printf ("Invalid input base\n");
			return 0;
	}

	char dictB[baseB];
	memcpy(dictB, dict, baseB);

	Char = 0;
	sum = 0;
	index = 0;
	//Get number to convert
	printf ("Please enter a number in base %d:\n", baseA);
	Char = getchar();
	Char = toupper(Char);
	while (((Char = getchar()) != EOF && index<32) && Char!='\n') {
		Char = toupper(Char);
		if (Char=='0') {
			found = 1;
			myChar = 0;
		} else {
			for (int i=0; i<baseA; i++) {
				if (Char==dictA[i]) {
					found = 1;
					myChar = i;
					i = baseA;
				}
			}
		}
		if (found == 0) {
				printf ("Invalid number!\n");
				return 0;
		}
		if (index!=0) {
				sum = sum*baseA;
		}
		sum += myChar;
		index++;
		found = 0;
	}

	//convert from decimal to baseB if needed
	if (sum==0) {
		printf("The result is : 0\n");
	} else if (baseB!=10) {
		convertFrom10(sum, dictB, baseB, result);
		printf("The result is : %s\n", result);
	}
	else {
		printf("The result is : %d\n", sum);
	}

}


