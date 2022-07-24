#include <stdio.h>
#define Max 50
#define formMax 2
#define resultMax 50
void compressedString(char *str);
void getFormatedInteger(char *format, char *result, int num);
void reverse(char *str);
int main()
{
    int NumOfProgram;               /* this int will help us choose which function to use */
    char letterArray[Max];          /* this array is used to store the letters we type it can hold up to 50 as requested */
    char Getformat[formMax];        /* this array is used to help us know in the function which result to give */
    char Getresult[resultMax];   /* this array is used to help us get the result */
    int Getnum;
    do       /* i used do while because we need to give the option to the customer to choose first so it prints out the words that he can choose and if he chooses 3 to exit the while loop will stop*/
    {
      printf("Please select the function you want to run:\n"); /* lines 18-21 are typed as requested*/
      printf("1 - compressed string\n");
      printf("2 - print formmated integers\n");
      printf("3 - Exit the program\n");
      scanf("%d",&NumOfProgram); /* storing the number */
       if(NumOfProgram<1||NumOfProgram>3)  /* if the user enters something other than 1,2,3 it will print out an error and end the program */
      {
        printf("\nInput Error!");
        return 1;
      }
      if(NumOfProgram==1) /* we have to check which number the user types so we can know which function to go to */
      {
        printf("\nEnter string: ");
        scanf("%s",letterArray);
        printf("\n");
        compressedString(letterArray); /* this is a function to compress the string line 49 is the code for it*/
      }
      if(NumOfProgram==2) /* we have to check which number the user types so we can know which function to go to */
      {
          printf("\nEnter format and number: ");
          scanf("%s",Getformat);
          scanf("%d",&Getnum);
          getFormatedInteger(Getformat,Getresult,Getnum); /* this is a function that receives a char array format,result array format and a number (line 70)  */
          reverse(Getresult); /* this is a function that reveres the array (line 137) */
          printf("\n%d - > %s\n",Getnum,Getresult);
      }


    }while(NumOfProgram!=3); /* if the user inputs the number 3 stop the while and return 0(end the program)*/
    return 0;

}
void compressedString(char *str)
{
    char strforhelp[Max]; /* this str is used to help us transform the result in it and then put whats inside it to the original str*/
    char *help=strforhelp; /* pointer for strforhelp*/
    int countDup=1,strIndex=0,helpIndex=0,PrintIndex=0;/* countDup counts the duplicates of a letter and it is set to 1 by usual, the index helps us navigate the array and it is set to 0*/
    do
    {
       if(*(str+strIndex)!=*(str+1+strIndex))  /* if the letter is not the same as the one next to it*/
       {
           *(help+helpIndex)=*(str+strIndex)-32;/* set the element in help array to the element in str - 32 which is the CAPITAL FORM IN ASCII*/
           *(help+helpIndex+1)=countDup+'0'; /* set the element next to the letter to the countDuplicates number*/
           helpIndex=helpIndex+2; /*go over two times because first element is the letter and the second is a number*/
         countDup=1; /* we have to set the count to 1 because in the second if we keep adding to the countDup*/
       }
       else if(*(str+strIndex)==*(str+1+strIndex)) /* if the letter is the same as the one next to it*/
       {
         countDup++; /* add one to the count and keep counting until the reach of a letter that is not the same as the one next to it*/
       }
       strIndex++; /* we add 1 to the index so we can reach the other letter*/

    }while(*(str+strIndex)!='\0');

    *(help+helpIndex)='\0'; /* set the last element to '\0' so we know when to stop printing*/
    while(*(help+PrintIndex)!='\0')
    {
        *(str+PrintIndex)=*(help+PrintIndex);  /* in this while i gave all the elements in help to str*/
        PrintIndex++;
    }
    *(str+PrintIndex)='\0'; /* set the last element to '\0' so we know when to stop printing*/
    printf("The compressed string is: %s",str); /* printing the str*/
    printf("\n");

}
void getFormatedInteger(char *format, char *result, int num)
{
    int getModule,i=0,temp=0;
    if(*(format+1)=='d')
    {

       while(num!=0) /* this while helps us get the number backwards to result*/
       {
           getModule=num%10; /* gets the last digit of the number*/
           *(result+i)=getModule+'0';
            num=num/10;
            i++;
       }
       *(result+i)='\0';  /* ending the array with the \0 so we know when to stop printing*/
    }
    if(*(format+1)=='b')
    {
        /* the binary system works by base 2 so if we divide by 2 and there is no remainder then the result should b 0*/
        while(num!=0)
        {
             *(result+i)=num%2+'0';
            num=num/2;
            i++;
        }
        *(result+i)='\0'; /* ending the array with the \0 so we know when to stop printing*/
    }
    if(*(format+1)=='o')
    {

     while(num!=0)
        { /* the octal system works by base 8 we should add the remainder by 8 */
            *(result+i)=num%8+'0';
            num=num/8;
            i++;
        }
        *(result+i)='\0'; /* ending the array with the \0 so we know when to stop printing*/
    }
    if(*(format+1)=='x')
    {
       /* the hexadecimal system works by base 16 */
       while(num!=0)
        {
            temp=num%16;
            if(temp<10)
            {
                *(result+i)=temp+48; /* if the result we divided by 16 is less than 10 we put it as it is*/
                i++;
            }
            else
            {
                *(result+i)=temp+55; /* if the result is under 10 then we add 5 to it because the system is 10-15 A-F*/
                i++;
            }
            num=num/16;
        }
        *(result+i)='\0'; /* ending the array with the \0 so we know when to stop printing*/
    }

}
void reverse(char *str)
{
  char *rev_str = str; /* new pointer to help us */
  char temp; /* a temporary char to help us navigate */
  while(*str) /* we need to reach the end of the str so we keep going until the end with the str++*/
      str++;
  --str; /* we go one down */

  while(rev_str < str)/* str is at the end as rev str is at the beginning */
  {
      temp = *rev_str; /* temp is as rev str*/
      *rev_str = *str; /* rev str is as str*/
      *str = temp;/* str is the temp which was rev str*/
      rev_str++;/* go up*/
      str--; /* go down*/
      /* basically we switched the positions of the elements from the top to the bottom*/
  }
}
