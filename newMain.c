 /*
 *  Created on: Mar 27, 2017
 *      Author: nlevy
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


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

//int convert210(char tempChar, char *dict, int myBase){
   //     int sum = 0;
  //      int pow;
 //       for (int l = 0; l<myBase; l++) {
          //              char charB = dict[l];
                //      printf("char is %c\n",charA);
                //      printf("dict is %c\n",charB);
           //            // printf("i is %d\n", i);
          //             // printf("l is %d\n" ,l);
         //               if (tempChar == charB) {
        //                        pow = int_pow(myBase, i);
       //                        // printf("pow is %d\n", pow);
      //                          sum += l * pow;
     //                          // printf("sum is %d\n", sum);
    //                    }
   //             }
  //      }
 //       return sum;
//}

void convertFrom10(int sum, char *dict, int newBase, char *result){
        int i, j, index;
        index = 0;
        int end;
        char new_num[20];
        char tempChar;
		while (sum!=0) {
                tempChar = dict[sum%newBase];
//                printf("temp char %c\n",tempChar);
                new_num[index] = tempChar;
                index++;
                sum = sum / newBase;
        }

        //reversing the array
        for (unsigned int i = 0; i<sizeof(new_num);i++) {
                if (isdigit(new_num[i]) || new_num[i] == 'A' || new_num[i] == 'B' ||  new_num[i] == 'C' ||  new_num[i] == 'D' ||  new_num[i] == 'E' ||  new_num[i] == 'F'   ) {
                end = i;
                j = i;
                }
                else {
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
        for (int i = 0;i<end+1;i++) {
  //              printf("result: %c\n",new_num[i]);
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

        //Get second base
        printf ("Please enter the desired base:\n");
        scanf ("%d", &baseB);
        if(baseB>16 && baseB < 2) {
                printf ("Invalid input base\n");
                return 0;
        }
        sum = 0;
        index = 0;
        //Get number to convert
        printf ("Please enter a number in base %d:\n", baseA);
        Char = getchar();
        while (((Char = getchar()) != EOF && index<3) && Char!='\n') {
                for (int i=0; i<baseA; i++) {
                        if (Char==dictA[i]) {
                                //printf("char is not %c\n", dictA[i]);
                                found = 1;
                                myChar = i;
                                i = baseA;
                        }
                }
                if (found == 0) {
                        printf ("Invalid number!\n");
                        break;
                }
                if (index!=0) {
                        sum = sum*baseA;
                }
                sum += myChar;
                index++;
        }
  //      int i = 0;
 //       char tempChar;
  //      int j;
   //     char rWord[20];
//reversing the array
   //     for (unsigned int i = 0; i<sizeof(word);i++) {
             //   if (isdigit(word[i]) || word[i] == 'A' || word[i] == 'B' || word[i] == 'C' || word[i] == 'D' || word[i] == 'E' || word[i] == 'F' ) {
            //            j = i;
           //             rWord[i] = word[i];
          //      }
         //       else {
        //                word[i] = '\0';
       //                 rWord[i] = '\0';
      //          }
     //   }
      //  while (i < j) {
     //           tempChar = rWord[i];
    //            rWord[i] = rWord[j];
   //             rWord[j] = tempChar;
  //              i++;
 //               j--;
//        }


        //convert from decimal to baseB if needed
        if (baseB!=10) {
                convertFrom10(sum, dictB, baseB, result);
                printf("The result is : %s\n", result);
        }
        else {
                printf("The result is : %d\n", sum);
        }

}

