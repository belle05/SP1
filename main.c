/*
 * SP1.c
 *
 *  Created on: Mar 27, 2017
 *      Author: nlevy
 */
#include <stdio.h>
#include <math.h>
#include <string.h>


int int_pow(int base, int exp) {
    int result = 1;
    while (exp)
    {
        if (exp & 1)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

int convert210(char *word, char *dict, int myBase) {
	int sum=0;
	int pow;
	for (unsigned int i = 0; i<sizeof(word); i++) {
		for (int l = 0; l<myBase; l++) {
			if (word[i]==dict[l]) {
				pow = int_pow(myBase, i);
				printf("pow is %d\n", pow);
				sum += l * pow;
				printf("sum is %d\n", sum);
			}
		}
	}
	return sum;
}

void convertFrom10(int sum, char *dict, int newBase, char *result){
	int i, j, index;
	char new_num[20];
	char tempChar;
	while (sum!=1) {
		tempChar = dict[sum%newBase];
		new_num[index] = tempChar;
		index++;
		sum = sum / newBase;
	}

	//reversing the array
	j = sizeof(new_num)-1;
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
	char dictA[] = "0123456789ABCDEF";
	char dictB[] = "0123456789ABCDEF";
	int baseA, baseB,sum;
	int found = 0;
	int index = 0;
	char word[20];
	char result[20];
	char Char;

	//Get first base
	printf ("Please enter the number's base:\n");
	scanf ("%d", &baseA);
	if(baseA>16 || baseA < 2) {
		printf ("Invalid input base\n");
		return 0;
	}

	//Get second base
	printf ("Please enter the desired base:\n");
	scanf ("%d", &baseB);
	if(baseB>16 && baseB < 2) {
		printf ("Invalid input base\n");
		return 0;
	}

	//Get number to convert
	printf ("Please enter a number in base %d:\n", baseA);
	Char = getchar();
	while ((Char = getchar()) != EOF && index<3) {
		for (int i=0; i<baseA; i++) {
			if (Char==dictA[i]) {
				//printf("char is not %c\n", dictA[i]);
				found = 1;
				i = baseA;
			}
		}
		if (found == 0) {
			printf ("Invalid number!\n");
			return 0;
		}
		word[index] = Char;
		index++;
	}

	//convert to decimal base if needed
	if (baseA!=10) {
		sum = convert210(word,dictA,baseA);
	} else {
		sum = sscanf(word,"%d",&sum);
	}

	//convert from decimal to baseB if needed
	if (baseB!=10) {
		convertFrom10(sum, dictB, baseB, result);
	} else {
		printf("base is 10 and sum is %d\n", sum);
		sprintf(result, "%d", sum);
	}

	//print result
	printf ("The result is : %s\n", result);

}
