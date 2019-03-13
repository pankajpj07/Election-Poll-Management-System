#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
 FILE *fp,*ft,*fd;
 char another,other,un[]="candidate",pw[]="pankaj",p[15],u[15];
 int choice,choose,vchoose,gid=0,i,a=1,j,y;
 long int recsize,recsize1;
 struct epms
 {
   char name[20],g[10];
   char fname[20];
   char mname[20];
   char add[50];
   char pname[20],mob[10];
   int age,date,month,year,cd,cid;
   
 }ep;    
 struct vot
 {
   int i,j,k,l,max;     
   char vname[20];
   int id;
   char vparty[20];
   
 }ms; 
//system("color 3e");
ms.i=0;
ms.j=0;
ms.k=0;
ms.l=0;
ep.cid=1000;
ms.id=2000;
recsize=sizeof(ep);
recsize1=sizeof(ms);
fp=fopen("EPMS.dat","rb+");
fread(&ep,recsize,1,fp);
if(fp==NULL)
 {
  fp=fopen("EPMS.dat","wb+");
  if(fp==NULL)
    {
      printf("Can't open file..!!");
      exit(1);          
    }          
 }
fd=fopen("EPMS1.dat","rb+");
fread(&ms,recsize1,1,fd);
if(fd==NULL)
 {
  fd=fopen("EPMS1.dat","ab+");
  if(fd==NULL)
    {
      printf("Can't open file..!!");
      exit(1);          
    }          
}  

printf("\n\n\t\t     *----------------------------------*\n");                           
printf("\t\t     |  ELECTION POLL MANAGEMENT SYSTEM |\n");
printf("\t\t     *----------------------------------*\n\n\n");
while(1)
 { 
   
   printf("\n                      ...................................\n");
   printf("\t              ! 1. Add Candidate                !\n");
   printf("\t              ! 2. Modify Candidate information !\n");
   printf("\t              ! 3. Delete Candidate             !\n");
   printf("\t              ! 4. Voting                       !\n");
   printf("\t              ! 5. Poll results                 !\n");
   printf("\t              ! 6. List of candidate            !\n");
   printf("\t              ! 7. See party members            !\n");
   printf("\t              ! 8. Exit                         !\n");
   printf("                      !.................................!\n");
   
   fflush(stdin);     
   scanf("%d",&choice);
   switch(choice)
    {
      case 1:
           fseek(fp,0,SEEK_END);
      another='y';
      while(another=='y')
       { 
         ep.cid++;
         printf("\n1.ID:-\t\t%d\n",ep.cid);
         other='a';
         while(other=='a')
         {
         printf("2.Name\t\t");
         fflush(stdin);
         gets(ep.name);
         for(i=0;ep.name[i]!='\0';i++)
          {
          if((ep.name[i]>64) || (ep.name[i]==32))
            {
             if((ep.name[i]==91) || (ep.name[i]==92) || (ep.name[i]==93) || (ep.name[i]==94) || (ep.name[i]==95) || (ep.name[i]>122))
              {
                printf("\nNumbers and symbols are not allowed...Enter again\n\n");
                printf("\n1.ID:-\t\t%d\n",ep.cid);
             other='a';
             break;                 
              }
              else 
              {                 
             other='b';
             continue;
             }
            }
          else
            {
             printf("\nNumbers and symbols are not allowed...Enter again\n\n");
             printf("\n1.ID:-\t\t%d\n",ep.cid);
             other='a';
             break;
             }
         }
         }
         other='a';
         while(other=='a')
         {
         printf("3.Father name\t");
         fflush(stdin);
         gets(ep.fname);
         for(i=0;ep.fname[i]!='\0';i++)
          {
          if((ep.fname[i]>64) || (ep.fname[i]==32))
            {
             if((ep.fname[i]==91) || (ep.fname[i]==92) || (ep.fname[i]==93) || (ep.fname[i]==94) || (ep.fname[i]==95) || (ep.fname[i]>122))
              {
                printf("\nNumbers and symbols are not allowed...Enter again\n\n");
                printf("\n1.ID:-\t\t%d\n",ep.cid);
                printf("2.Name\t\t%s\n",ep.name);
             other='a';
             break;                 
              }
              else 
              {                 
             other='b';
             continue;
             }
            }
          else
            {
             printf("\nNumbers and symbols are not allowed...Enter again\n\n");
             printf("\n1.ID:-\t\t%d\n",ep.cid);
             printf("2.Name\t\t%s\n",ep.name);
             other='a';
             break;
             }
         }
         }
         other='a';
         while(other=='a')
         {
         printf("4.Mother name\t");
         fflush(stdin);
         gets(ep.mname);
         for(i=0;ep.mname[i]!='\0';i++)
          {
          if((ep.mname[i]>64) || (ep.mname[i]==32))
            {
             if((ep.mname[i]==91) || (ep.mname[i]==92) || (ep.mname[i]==93) || (ep.mname[i]==94) || (ep.mname[i]==95) || (ep.mname[i]>122))
              {
                printf("\nNumbers and symbols are not allowed...Enter again\n\n");
                printf("\n1.ID:-\t\t%d\n",ep.cid);
                printf("2.Name\t\t%s\n",ep.name);
                printf("3.Father name\t%s\n",ep.fname);
             other='a';
             break;                 
              }
              else 
              {                 
             other='b';
             continue;
             }
            }
          else
            {
             printf("\nNumbers and symbols are not allowed...Enter again\n\n");
             printf("\n1.ID:-\t\t%d\n",ep.cid);
             printf("2.Name\t\t%s\n",ep.name);
             printf("3.Father name\t%s\n",ep.fname);
             other='a';
             break;
             }
         }
         }
         printf("5.Address\t");
         gets(ep.add);
         printf("6.Phone number\t");
		   y=0;
		   while(y==0)
		   {  
              y=1;
		      gets(ep.mob);
		      for(j=0;ep.mob[j]!='\0';j++)
		       {
                 if(!isdigit(ep.mob[j]))
		          {  
                    y=0;
			        printf("\nCharacter or symbols are not allowed...Enter again\n\n");
                    printf("\n1.ID:-\t\t%d\n",ep.cid);
                    printf("2.Name\t\t%s\n",ep.name);
                    printf("3.Father name\t%s\n",ep.fname);
                    printf("4.Address\t%s\n",ep.add);
                    printf("5.Phone number\t");
			        break;
                   }
           }
		      if(j!=10&&y==1)
		      {  y=0;
                    printf("\n\nMobile no. should have 10 digits!\n\n");
                    printf("\n1.ID:-\t\t%d\n",ep.cid);
                    printf("2.Name\t\t%s\n",ep.name);
                    printf("3.Father name\t%s\n",ep.fname);
                    printf("4.Address\t%s\n",ep.add);
                    printf("5.Phone number\t");
		      }
		   }
         printf("7.Age\t\t");
         scanf("%d",&ep.age);
         if(ep.age<25 || ep.age>60)
          {ep.cid--;
           printf("Your age should be between 25 and 60");
           break;
          }
         else
          {
           other='a';
         while(other=='a')
         {
         printf("8.Gender\t");
         fflush(stdin);
         gets(ep.g);
           if((strcmp(ep.g,"male")==0)||(strcmp(ep.g,"female")==0)||(strcmp(ep.g,"f")==0)||(strcmp(ep.g,"m")==0)) 
            {
              break;                                                                                            
            } 
           else
           {
             printf("\n\nEnter male or female only\n\n");
             other='a';
           }
         }
           if(strcmp(ep.g,"m")==0)
           strcpy(ep.g,"male");
           else if(strcmp(ep.g,"f")==0)
           strcpy(ep.g,"female");
           printf("9.D.O.B\n");
           printf("\tDate\t");
           scanf("%d",&ep.date);
           printf("\tMonth\t");
           scanf("%d",&ep.month);
           printf("\tYear\t");
           scanf("%d",&ep.year);
           ep.cd=2015-ep.age;
           if((ep.date==0) || (ep.month==0) || (ep.year<1955) || (ep.date>31) || (ep.month>12) || (ep.year>1990))
            {
             ep.cid--;                           
             printf("\n\nDate of Birth is invalid\n\n");
             break;         
            }
           else if(ep.year!=ep.cd)
           {
             ep.cid--;                           
             printf("\n\nDOB and AGE does not match each other \n\n");
             break;         
            }
           printf("\n10.Party to join\n\n");
           printf("\n                   ...........................................\n");
           printf("                   :                                         :\n");
           printf("\t\t   :   1.BJP    2.AAP    3.BSP    4.CONGRESS :\n");  
           printf("                   :                                         :\n"); 
           printf("                   :.........................................:\n");
           scanf("%d",&choose);  
           
            
           switch(choose)
            {
              case 1:   
              strcpy(ep.pname,"BJP");
              printf("\nWelcome to Bhartiya Janta Party");
              break;
        
              case 2:
              strcpy(ep.pname,"AAP");
              printf("\nWelcome to Aam Aadmi Party");
              break;
        
              case 3:
              strcpy(ep.pname,"BSP"); 
              printf("\nWelcome to Bahujan Samaaj Party");
              break;
              
              case 4:
              strcpy(ep.pname,"CONGRESS"); 
              printf("\nWelcome to Congress Party");    
              break;
        
              default:
              printf("Ooops..!! wrong key pressed\n\nPress any key to exit");
              getch();
              exit(1);
              
            }
           fwrite(&ep,recsize,1,fp);
           printf("\nAdd another record ?(Y/N)\n\n");
           fflush(stdin);
           another=getche();
          } 
       }
       break;
       
       
     case 2:
     another='y';
     while(another=='y')
      { 
       ft=fopen("TPMS.dat","wb");
       rewind(fp);
       printf("\nEnter id to modify\t");
       scanf("%d",&gid);
       
       
       
       
       
       while(fread(&ep,recsize,1,fp)==1)
        {
         if(gid!=ep.cid) 
           {     
               fwrite(&ep,recsize,1,ft);                           
           }
         else
          {
            other='a';
         while(other=='a')
         {
         printf("\n1.ID:-\t\t%d\n",ep.cid);
         other='a';
         while(other=='a')
         {
         printf("2.Name\t\t");
         fflush(stdin);
         gets(ep.name);
         for(i=0;ep.name[i]!='\0';i++)
          {
          if((ep.name[i]>64) || (ep.name[i]==32))
            {
             if((ep.name[i]==91) || (ep.name[i]==92) || (ep.name[i]==93) || (ep.name[i]==94) || (ep.name[i]==95) || (ep.name[i]>122))
              {
                printf("\nNumbers and symbols are not allowed...Enter again\n\n");
                printf("\n1.ID:-\t\t%d\n",ep.cid);
             other='a';
             break;                 
              }
              else 
              {                 
             other='b';
             continue;
             }
            }
          else
            {
             printf("\nNumbers and symbols are not allowed...Enter again\n\n");
             printf("\n1.ID:-\t\t%d\n",ep.cid);
             other='a';
             break;
             }
         }
         }
         other='a';
         while(other=='a')
         {
         printf("3.Father name\t");
         fflush(stdin);
         gets(ep.fname);
         for(i=0;ep.fname[i]!='\0';i++)
          {
          if((ep.fname[i]>64) || (ep.fname[i]==32))
            {
             if((ep.fname[i]==91) || (ep.fname[i]==92) || (ep.fname[i]==93) || (ep.fname[i]==94) || (ep.fname[i]==95) || (ep.fname[i]>122))
              {
                printf("\nNumbers and symbols are not allowed...Enter again\n\n");
                printf("\n1.ID:-\t\t%d\n",ep.cid);
                printf("2.Name\t\t%s\n",ep.name);
             other='a';
             break;                 
              }
              else 
              {                 
             other='b';
             continue;
             }
            }
          else
            {
             printf("\nNumbers and symbols are not allowed...Enter again\n\n");
             printf("\n1.ID:-\t\t%d\n",ep.cid);
             printf("2.Name\t\t%s\n",ep.name);
             other='a';
             break;
             }
         }
         }
         other='a';
         while(other=='a')
         {
         printf("4.Mother name\t");
         fflush(stdin);
         gets(ep.mname);
         for(i=0;ep.mname[i]!='\0';i++)
          {
          if((ep.mname[i]>64) || (ep.mname[i]==32))
            {
             if((ep.mname[i]==91) || (ep.mname[i]==92) || (ep.mname[i]==93) || (ep.mname[i]==94) || (ep.mname[i]==95) || (ep.mname[i]>122))
              {
                printf("\nNumbers and symbols are not allowed...Enter again\n\n");
                printf("\n1.ID:-\t\t%d\n",ep.cid);
                printf("2.Name\t\t%s\n",ep.name);
                printf("3.Father name\t%s\n",ep.fname);
             other='a';
             break;                 
              }
              else 
              {                 
             other='b';
             continue;
             }
            }
          else
            {
             printf("\nNumbers and symbols are not allowed...Enter again\n\n");
             printf("\n1.ID:-\t\t%d\n",ep.cid);
             printf("2.Name\t\t%s\n",ep.name);
             printf("3.Father name\t%s\n",ep.fname);
             other='a';
             break;
             }
         }
         }
            
         }

            printf("5.Address\t");
            gets(ep.add);
            printf("6.Phone number\t");
		   y=0;
		   while(y==0)
		   {  
              y=1;
		      gets(ep.mob);
		      for(j=0;ep.mob[j]!='\0';j++)
		       {
                 if(!isdigit(ep.mob[j]))
		          {  
                    y=0;
			        printf("\nCharacter or symbols are not allowed...Enter again\n\n");
                    printf("\n1.ID:-\t\t%d\n",ep.cid);
                    printf("2.Name\t\t%s\n",ep.name);
                    printf("3.Father name\t%s\n",ep.fname);
                    printf("4.Address\t%s\n",ep.add);
                    printf("5.Phone number\t");
			        break;
                   }
           }
		      if(j!=10&&y==1)
		      {  y=0;
                    printf("\n\nMobile no. should have 10 digits!\n\n");
                    printf("\n1.ID:-\t\t%d\n",ep.cid);
                    printf("2.Name\t\t%s\n",ep.name);
                    printf("3.Father name\t%s\n",ep.fname);
                    printf("4.Address\t%s\n",ep.add);
                    printf("5.Phone number\t");
		      }
		   }
            printf("7.Age\t\t");
            scanf("%d",&ep.age);
            if(ep.age<25)
              {
                printf("Your age should be between 25 and 60");
                break;
              }    
                other='a';
         while(other=='a')
         {
         printf("8.Gender\t");
         fflush(stdin);
         gets(ep.g);
           if((strcmp(ep.g,"male")==0)||(strcmp(ep.g,"female")==0)||(strcmp(ep.g,"f")==0)||(strcmp(ep.g,"m")==0)) 
              {
                break;                                                                                            
              } 
           else
              {
               printf("\n\nEnter male or female only\n\n");
               other='a';
              }
         }
                if(strcmp(ep.g,"m")==0)
                strcpy(ep.g,"male");
                else if(strcmp(ep.g,"f")==0)
                strcpy(ep.g,"female");
                printf("9.D.O.B\n");
                printf("\tDate\t");
                scanf("%d",&ep.date);
                printf("\tMonth\t");
                scanf("%d",&ep.month);
                printf("\tYear\t");
                scanf("%d",&ep.year);
                ep.cd=2015-ep.age;
                if((ep.date==0) || (ep.month==0) || (ep.year<1955) || (ep.date>31) || (ep.month>12) || (ep.year>1990))
                {
                ep.cid--;                           
                printf("\n\nDate of Birth is invalid\n\n");
                break;         
                }
                else if(ep.year!=ep.cd)
                {
                ep.cid--;                           
                printf("\n\nDOB and AGE does not match each other \n\n");
                break;         
                }
                printf("\n10.Party to join\n\n");
                printf("\n                   ...........................................\n");
                printf("                   :                                         :\n");
                printf("\t\t   :   1.BJP    2.AAP    3.BSP    4.CONGRESS :\n");  
                printf("                   :                                         :\n"); 
                printf("                   :.........................................:\n");
                scanf("%d",&choose);  
           switch(choose)
            {
              case 1:   
              strcpy(ep.pname,"BJP");
              printf("\nWelcome to Bhartiya Janta Party");
              break;
        
              case 2:
              strcpy(ep.pname,"AAP");
              printf("\nWelcome to Aam Aadmi Party");
              break;
        
              case 3:
              strcpy(ep.pname,"BSP"); 
              printf("\nWelcome to Bahujan Samaaj Party");
              break;
              
              case 4:
              strcpy(ep.pname,"CONGRESS"); 
              printf("\nWelcome to Congress Party");    
              break;
        
              default:
              printf("Ooops..!! wrong key pressed\n\nPress any key to exit");
              getch();
              exit(1);
            }
            
        fwrite(&ep,recsize,1,ft);       
        } 
       }  
      fclose(fp); 
      fclose(ft);
      remove("EPMS.dat");
      rename("TPMS.dat","EPMS.dat");
      fp=fopen("EPMS.dat","rb+"); 
      printf("\nModify another record ?(Y/N)\n");
      fflush(stdin);
      another=getche();
     }
     break;
      
     case 3:   
      
     another='y';
     while(another=='y')
      { 
       ft=fopen("TPMS.dat","wb");
       rewind(fp);
       printf("\nEnter id to delete\t");
       scanf("%d",&gid);
         
           while(fread(&ep,recsize,1,fp)==1)
            {
               if(gid!=ep.cid) 
                 {     
                   fwrite(&ep,recsize,1,ft);                           
                 }                             
            }
             fclose(fp);
             fclose(ft);
             remove("EPMS.dat");
             rename("TPMS.dat","EPMS.dat");
             fp=fopen("EPMS.dat","rb+");
             
          
          
      printf("\nDelete another record ?(Y/N)\n");
      fflush(stdin);
      another=getche();
     }//1st while
     break;
     
     case 4:
     rewind(fd);
     other='a';
         while(other=='a')
         {
         printf("1.Name\t\t");
         fflush(stdin);
         gets(ms.vname);
         for(i=0;ms.vname[i]!='\0';i++)
          {
            if((ms.vname[i]>64) || (ms.vname[i]==32))
            {
             other='b';
             continue;
            }
            else if((ms.vname[i]<65) || (ms.vname[i]==91) || (ms.vname[i]==92) || (ms.vname[i]==93) || (ms.vname[i]==94) || (ms.vname[i]==95) || (ms.vname[i]>122))
            {
             printf("\nNumbers and symbols are not allowed...Enter again\n");
             other='a';
             break;
             }
            
            
         }
         }
     ms.id++;
     printf("Voter ID:-\t%d",ms.id);
     printf("\nVOTE NOW\n");
     printf("\n             *************************************************\n");
     printf("             *                                               *\n");
     printf("             *    1.BJP     2.AAP     3.BSP     4.CONGRESS   *\n");
     printf("             *                                               *\n");  
     printf("             *************************************************\n");
     scanf("%d",&vchoose);
     switch(vchoose)
      {
        case 1:   
        strcpy(ms.vparty,"BJP"); 
        ms.i++;
        break;
        
        case 2:
        strcpy(ms.vparty,"AAP");
        ms.j++;
        break;
        
        case 3:
        strcpy(ms.vparty,"BSP");     
        ms.k++;
        break;
        
        case 4:
        strcpy(ms.vparty,"CONGRESS");     
        ms.l++;
        break;
        
        default:
        printf("Your vote is given to other party\n\nPress any key to exit");
              getch();
              exit(1);
      }
     printf("\n\nYou have voted successfully..!!\n\n");
     fwrite(&ms,recsize1,1,fd);
     break; 
     
     case 5:
     rewind(fd);
     if(fread(&ms,recsize1,1,fd)==1)
     {
     printf("\nBJP\t\t%d",ms.i);
     printf("\nAAP\t\t%d",ms.j);
     printf("\nBSP\t\t%d",ms.k);
     printf("\nCONGRESS\t%d\n\n",ms.l);
     if((ms.i==ms.j)&&(ms.i==ms.k)&&(ms.i==ms.l)&&(ms.j==ms.k)&&(ms.j==ms.l)&&(ms.k==ms.l))
        {
         printf("It's quite surprising that all team have same numbers of votes");
         break;
        }  
     if(ms.i>ms.j)
        ms.max=ms.i;
     else
        ms.max=ms.j;
     if(ms.max>ms.k)
        ms.max=ms.max;
     else
        ms.max=ms.k;
     if(ms.max>ms.l)
        ms.max=ms.max;
     else
        ms.max=ms.l;
     if((ms.max==ms.i)&&(ms.max==ms.j)&&(ms.max==ms.k))
        printf("\nBJP , AAP or BSP %d voton k sath ek hi position par\n",ms.max);
     else if((ms.max==ms.i)&&(ms.max==ms.j)&&(ms.max==ms.l))
        printf("\nBJP , AAP or CONGRESS %d voton k sath ek hi position par\n",ms.max);
     else if((ms.max==ms.i)&&(ms.max==ms.k)&&(ms.max==ms.l))
        printf("\nBJP , BSP or CONGRESS %d voton k sath ek hi position par\n",ms.max); 
     else if((ms.max==ms.j)&&(ms.max==ms.k)&&(ms.max==ms.l))
        printf("\nAAP , BSP or CONGRESS %d voton k sath ek hi position par\n",ms.max);     
     else if((ms.max==ms.i)&&(ms.max==ms.j))
        printf("\nBJP or AAP %d voton k sath ek hi position par\n",ms.max);  
     else if((ms.max==ms.i)&&(ms.max==ms.k))
        printf("\nBJP or BSP %d voton k sath ek hi position par\n",ms.max);
     else if((ms.max==ms.i)&&(ms.max==ms.l))
        printf("\nBJP or CONGRESS %d voton k sath ek hi position par\n",ms.max);
     else if((ms.max==ms.j)&&(ms.max==ms.k))
        printf("\nAAP or BSP %d voton k sath ek hi position par\n",ms.max);
     else if((ms.max==ms.j)&&(ms.max==ms.l))
        printf("\nAAP or CONGRESS %d voton k sath ek hi position par\n",ms.max);
     else if((ms.max==ms.k)&&(ms.max==ms.l))
        printf("\nBSP or CONGRESS %d voton k sath ek hi position par\n",ms.max);   
     else if(ms.max==ms.i)
        printf("\nBJP %d voton se aage...\n",ms.i);
     else if(ms.max==ms.j)
        printf("\nAAP %d voton se aage...\n",ms.j);
     else if(ms.max==ms.k)
        printf("\nBSP %d voton se aage...\n",ms.k);
     else if(ms.max==ms.l)
        printf("\nCongress %d voton se aage...\n",ms.l);
     }  
     else
     {
      printf("\nBJP\t\t%d",ms.i);
      printf("\nAAP\t\t%d",ms.j);
      printf("\nBSP\t\t%d",ms.k);
      printf("\nCONGRESS\t%d\n\n",ms.l);
      if((ms.i==0) && (ms.j==0) && (ms.k==0) && (ms.l==0))
        {
         printf("\nVoting lines are closed now.....\n");
         break;
         }    
     }         
     break;
     
     case 6:
     printf("\nYou have to log in first to check candidate details\n\n");
     another='y';
     while(another=='y')
     {
     printf("Username\t");
     fflush(stdin);
     gets(u);
     printf("Password\t");
     gets(p);
     printf("\n\n");
     if((strcmp(un,u)==0) && (strcmp(pw,p)==0) )
      {
     rewind(fp); 
     while(fread(&ep,recsize,1,fp)==1)
      {
       printf("1.Candidate Id\t%d\n",ep.cid);
       printf("2.Name\t        %s\n",ep.name);
       printf("3.Father name\t%s\n",ep.fname);  
       printf("4.Mother name\t%s\n",ep.mname);
       printf("5.Gender\t%s\n",ep.g);
       printf("6.Phone number\t%s\n",ep.mob);
       printf("7.Address \t%s\n",ep.add);    
       printf("8.Age\t        %d\n",ep.age);
       printf("9.Date of Birth\t%d/%d/%d\n",ep.date,ep.month,ep.year); 
       printf("10.Party name\t%s\n\n",ep.pname); 
       getch();             
      }
     break;
      }
     else
       {
        printf("\nEnter valid username or password\n");
        printf("****Wanna try again..?(Y/N)****");
        fflush(stdin);
        another=getche();
        printf("\n\n");
       }
     }  
     break;
     
     case 7:
     printf("\n\nChoose one of foolowing option to see chosen party's members\n");
     printf("\n\n\t\t\t1.Bhartiya janta party\n");
     printf("\t\t\t2.Aam aadmi party\n");
     printf("\t\t\t3.Bahujan samaj party\n");
     printf("\t\t\t4.Congress\n\n");
     scanf("%d",&vchoose);
     if(vchoose==1)
     {
      rewind(fp); 
      a=1;
     while(fread(&ep,recsize,1,fp)==1)
     {
      if(strcmp(ep.pname,"BJP")==0) 
       {
        printf("\n%d.%s",a,ep.name);
        a++;                            
       }                                
     }   
     } 
     else if(vchoose==2)
     {
      rewind(fp); 
      a=1;
     while(fread(&ep,recsize,1,fp)==1)
     {
      if(strcmp(ep.pname,"AAP")==0) 
       {
        printf("\n%d.%s",a,ep.name);
        a++;                            
       }                                
     }   
     } 
     else if(vchoose==3)
     {
      rewind(fp); 
      a=1;
     while(fread(&ep,recsize,1,fp)==1)
     {
      if(strcmp(ep.pname,"BSP")==0) 
       {
        printf("\n%d.%s",a,ep.name);
        a++;                            
       }                                
     }   
     } 
     else if(vchoose==4)
     {
      rewind(fp); 
      a=1;
     while(fread(&ep,recsize,1,fp)==1)
     {
      if(strcmp(ep.pname,"CONGRESS")==0) 
       {
        printf("\n%d.%s",a,ep.name);
        a++;                            
       }                                
     }   
     } 
     else
     {
      printf("\nSorry..!! There is no such party.\n\n");    
     }
     break;
     
           
     case 8:
     fclose(fp);
     fclose(fd);
     exit(0);
     
     default:
     printf("\n\n\t\t      ...................................\n"); 
     printf("\t\t      :\t\t\t\t\t:\n");                          
     printf("\t\t      :  Ooops! WRONG KEY PRESSED..!!   :\n");
     printf("\t\t      :\t\t\t\t\t:\n");
     printf("\t\t      :.................................:\n\n\n");

     break;

                 
    }//switch case
 }//while loop 
}//int main 
