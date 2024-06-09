/*
Name: Gayathri.k
Date: 9 july 2024
Description: wap to print the string in alphabetical order, if the character is not existing in the string, replace it with (.)
Sample input: str1 = "TCP is a transport"
Sample output: "a.c.....i....nop.rst......"
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter the string:\n");
    scanf(" %[^\n]",str);
    char abcd[26],ABC[26];
    char result[100];
    int i,j,k,l,flag=0;
    k=0;l=0;
   
	for(i=0;i<26;i++)
      	{
      	    abcd[i]='a'+i;
            ABC[i]='A'+i;
  	}


    l=0;
    for(i=0;i<26;i++)
    {
	for(j=0;j<strlen(str);j++)
	{
	    if(abcd[i]==str[j] || ABC[i]==str[j])
	    {

			result[l++]=abcd[i];
			
	    }

	}
	
    }
    result[l]='\0';
   
    
int count=strlen(result);

    for(i=0;i<strlen(result);i++)
    {
	for(j=i+1;j<strlen(result);j++)
	{
	    if(result[i]==result[j])
	    {
		count++;
		for(k=j;k<(count-i-1);k++)
	
		{
		    result[k]=result[k+1];
		}
		result[k]='\0';
		
	    }
	    
	}
	
    }
    
    
   

   
    int str_len,abcd_len,result_len,len=0;
    str_len=strlen(str);
    abcd_len=strlen(abcd);
    result_len=strlen(result);
    for(i=0;i<26;i++)
    {

	    for(j=0;j<strlen(result);j++)
	    {
	    if(abcd[i]==result[j])
	    {
		len=1;
	    }
	    }
	    if(len==1)
		printf("%c",abcd[i]);
	    else
		printf(".");
	    len=0;
	   }
    printf("\n");
	
	
   
    
}

  



