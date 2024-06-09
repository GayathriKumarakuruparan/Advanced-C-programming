/*
Name: Gayathri.k
Date: july 9 2024
Description: WAP to find the number of substring in the order string
Sample input: str1="abcabcab" sub="abc"
Sample output: number of substring is 2(abc appreared twice)
*/
#include<stdio.h>
#include<string.h>
int sub_string(char *str,char *sub)
{
    int l1,l2,i,j,count,count1;
    l1=strlen(str);
    l2=strlen(sub);
    for(i=0;i<l1;)
    {
	j=0;
	count=0;
	while(str[i]==sub[j])
	{
	    count++;
	    i++;
	    j++;
	}
	if(count==l2)
	{
	    count1++;
	    count=0;
	}
	else
	    i++;

    }
    return count1;
}
int main()
{
    char str1[100]="abcabcab";
    char str[100]="abc";
    /*printf("Enter the string:\n");
    scanf(" %[^\n]",str1);
    printf("Enter the substring:\n");
    scanf(" %[^\n]",str2);*/
    int result = sub_string(str1,str);
    printf("The count of the substring is %d\n",result);

}

