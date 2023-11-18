/*
Name: Gayathri.k
Date: 13/11/23
Description: WAP to Implement the student record using array of structures
Sample Input & Output:
                    Enter no.of students : 2
                    Enter no.of subjects : 2
                    Enter the name of subject 1 : Maths
                    Enter the name of subject 2 : Science
                    ----------Enter the student datails-------------
                    Enter the student Roll no. : 1
                    Enter the student 1 name : Nandhu
                    Enter Maths mark : 99
                    Enter Science mark : 91
                    ----------Enter the student datails-------------
                    Enter the student Roll no. : 2
                    Enter the student 2 name : Bindhu
                    Enter Maths mark : 88
                    Enter Science mark : 78
                    ----Display Menu----
                    1. All student details
                    2. Particular student details
                    Enter your choice : 2
                    
                    ----Menu for Particular student----
                    1. Name.
                    2. Roll no.
                    Enter you choice : 1
                    Enter the name of the student : Nandhu
                    Roll No.    Name           Maths         Science        Average          Grade
                    1          Nandhu          99               91               95          A
                    Do you want to continue to display(Y/y) : n
*/
#include<stdio.h>
#include<string.h>
struct student
{
    int id;
    char name[20];
    double avg;
    char grade;
};
int main()
{
   int student,subject,flag=0,i,j;
   int roll;
   char name[20];
   char y_n;
   
   
   do{
    printf("Enter no.of students : ");
    scanf("%d",&student);
    
    //memory allocation for struct
   struct student s[student];
   
   
   printf("Enter no.of subjects : ");
   scanf("%d",&subject);
  
   char sub[subject][20];
   int mark[student][subject];

   //to read the subject
   for(int i=0;i<subject;i++){
        printf("Enter the name of subject %d : ",i+1);
       scanf(" %s",sub[i]);
       
   }

   
  
   
   //read the students detail
   
   for(int i=0;i<student;i++){
       printf("----------Enter the student datails-------------\n");
       float sum=0;
       //read roll no
       printf("Enter the student Roll no. : ");
       scanf("%d",&s[i].id);
       //read the name
       printf("Enter the student %d name : ",i+1);
       scanf(" %s",s[i].name);

       //read the marks
       
       for(int j=0;j<subject;j++)
       {
           printf("Enter %s mark : ",sub[j]);
           scanf("%d",&mark[i][j]);
           sum+=mark[i][j];
       }
       s[i].avg=sum/subject;
       
       if((s[i].avg>=91)&&(s[i].avg<=100))
           s[i].grade='A';
       else if((s[i].avg>=81)&&(s[i].avg<=90))
           s[i].grade='B';
       else if((s[i].avg>=71)&&(s[i].avg<=80))
           s[i].grade='C';
       else if((s[i].avg>=61)&&(s[i].avg<=70))
           s[i].grade='D';
       else if((s[i].avg>=51)&&(s[i].avg<=60))
           s[i].grade='E';
       else
           s[i].grade='F';
       
   }

                 //MENU SESSION
    printf("----------------Display Menu---------------\n1.All Student details.\n2.Particular student details.\n");
   int opt,opt2;
   printf("Enter the option: ");
   scanf("%d",&opt);
   
   switch(opt){
       
       case 1:
             //print the students detail
             printf("---------DISPLAY ALL STUDENTS DETAILS-------------\n");
             printf("%s\t%s","Roll No.","Name");
	            for(i = 0; i < subject; i++)
	             printf("\t%s",sub[i]);
	             
	             printf("\t%s\t%s\n","average","grade");
	                for(i = 0; i < student; i++)
	                     {
		                   printf("%d\t\t%s",s[i].id,s[i].name);
		                   
		                   for(j = 0; j < subject; j++)
		                         printf("\t%d",mark[i][j]);
		                         
		                         printf("\t%g\t%c\n",s[i].avg,s[i].grade);
	                     }
	                            break;
     
      
       case 2:
       
         printf("----Menu for Particular student----\n1. Name.\n2. Roll no.\nEnter you choice : ");
         printf("Enter the option: ");
         scanf("%d",&opt2);
         
         //nested switch case
         switch(opt2){
             case 1:
                        printf("Enter the name of the student : ");
                        scanf(" %s",name);
                        printf("%s\t%s","Roll No.","Name");
                        
        	            for(i = 0; i < subject; i++)
        	             printf("\t%s",sub[i]);
        	             
        	             
        	             printf("\t%s\t%s\n","average","grade");
        	                for(i = 0; i < student; i++)
        	                     {
        	                         if(strcmp(name,s[i].name)==0){
        	                         flag=1;
        		                   printf("%d\t\t%s",s[i].id,s[i].name);
        		                   
        		                     for(j = 0; j < subject; j++)
        		                          printf("\t%d",mark[i][j]);
        		                          
        		                          printf("\t%g\t%c\n",s[i].avg,s[i].grade);
        	                            }
        	                            
        	            }
        	            if(flag==0)
                                    printf("Enter valid rollno\n");
                                    break;
                                    
         case 2:
                printf("Enter the Roll no of the student : ");
                scanf(" %d",&roll);
                printf("%s\t%s","Roll No.","Name");
                
            	    for(i = 0; i < subject; i++)
            	     printf("\t%s",sub[i]);
            	     
            	     
            	     printf("\t%s\t%s\n","average","grade");
            	       for(i = 0; i < student; i++)
            	            {
            	              if(roll==s[i].id)
            	              {
            	               flag=1;
            		           printf("%d\t\t%s",s[i].id,s[i].name);
            		           
            		              for(j = 0; j < subject; j++)
            		                    printf("\t%d",mark[i][j]);
            		                    
            		                    printf("\t%g\t%c\n",s[i].avg,s[i].grade);
            	              }
            	                            
            	           }
            	            if(flag==0)
                              printf("Enter valid rollno\n");
                               break;
                     }
                     break;
            }
                   printf("Do you want to continue to display(Y/y) : ");
                   scanf(" %c",&y_n);
            }
            while((y_n=='y')||(y_n=='Y'));

}

