//Pass -1 of 2-pass assembler
     
    #include<stdio.h>
   // #include<conio.h>
    #include<string.h>
    void main()
    {
    FILE *f1,*f2,*f3,*f4;
    int lc,sa,l,op1,o,len;
    char m1[20],la[20],op[20],otp[20];
    //clrscr();
    
    //open the files
    f1=fopen("input.dat","r");
    f3=fopen("symtab.dat","w");
    //f4=fopen("output.txt","w");
    //la=label,m1=mnemonic,op1=operand
    //1st line of input
    fscanf(f1,"%s %s %x",la,m1,&op1);
    //if mnemonic is equal to start
    if(strcmp(m1,"START")==0)
    {
        //sa=starting address
     sa=op1;
     //lc=location counter
     lc=sa;
     //print the 1st line to output
     printf("\t%s\t%s\t%x\n",la,m1,op1);
     
     }
     else
      //else initialise location counter to zero i.e its nt fst line
     	lc=0;
      //read next label and mnrmonic   
     fscanf(f1,"%s %s",la,m1);
     //scan till end of the file has been reached
    while(!feof(f1))
    {
     fscanf(f1,"%s",op);// take operand as the string input
     printf("\n%x\t%s\t%s\t%s\n",lc,la,m1,op); //print to output
     if(strcmp(la,"-")!=0)//compare if label is not -
     {
     fprintf(f3,"\n%x\t%s\n",lc,la);//if so then print only lc and label to the symtab i.e alpha beta five dese things
     }
     f2=fopen("optab.dat","r");//now third part this is
     fscanf(f2,"%s %x",otp,&o);//read optab txt
     while(!feof(f2))//scan till end is reached
     {
      if(strcmp(m1,otp)==0)//from line 35 compare mnemonic with optab thingi
      {
        lc=lc+3;//if der den increment
        break;
      }
      fscanf(f2,"%s %x",otp,&o);//see next line
      }
      fclose(f2);//close after scanning all lines
      
      
      
      //now these things for writing last lines i.e those declaration initialisers for dem
      if(strcmp(m1,"WORD")==0)
     
        {
       lc=lc+3;
       }
       else if(strcmp(m1,"RESW")==0)
       {
        op1=atoi(op);
        lc=lc+(3*op1);
        }
        else if(strcmp(m1,"BYTE")==0)
        {
        if(op[0]=='X')
        {
          lc=lc+1;
          }
          else
          {
              //how is dis??????
          len=strlen(op)-3;
          lc=lc+len;}
        }
        else if(strcmp(m1,"RESB")==0)
        {
         op1=atoi(op);
         lc=lc+op1;
         }
        fscanf(f1,"%s%s",la,m1);
        }
        if(strcmp(m1,"END")==0)
        {
        printf("Program length =\n%d",lc-sa);
        }
        fclose(f1);
        fclose(f3);
        //getch();
        }


/*
# include <stdio.h>

//# include <conio.h>

# include <string.h>

void main()

{

char opcode[10],mnemonic[3],operand[10],label[10],code[10];

int locctr,start,length;

FILE *fp1,*fp2,*fp3,*fp4;

//clrscr();

fp1=fopen("input.dat","r");

fp2=fopen("symtab.dat","w");

fp3=fopen("out.dat","w");

fp4=fopen("optab.dat","r");

fscanf(fp1,"%s%s%s",label,opcode,operand);

if(strcmp(opcode,"START")==0){

start=atoi(operand);

locctr=start;

fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);

fscanf(fp1,"%s%s%s",label,opcode,operand);

}

else

locctr=0;

while(strcmp(opcode,"END")!=0)

{

fprintf(fp3,"%d\t",locctr);

if(strcmp(label,"**")!=0)

fprintf(fp2,"%s\t%d\n",label,locctr);

rewind(fp4);

fscanf(fp4,"%s",code);

while(strcmp(code,"END")!=0)

{

if(strcmp(opcode,code)==0)

{

locctr+=3;

break;

}

fscanf(fp4,"%s",code);

}

if(strcmp(opcode,"WORD")==0)

locctr+=3;

else if(strcmp(opcode,"RESW")==0)

locctr+=(3*(atoi(operand)));

else if(strcmp(opcode,"RESB")==0)

locctr+=(atoi(operand));

else if(strcmp(opcode,"BYTE")==0)

++locctr;

fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);

fscanf(fp1,"%s%s%s",label,opcode,operand);

}

fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);

length=locctr-start;

printf("The length of the program is %d",length);

fclose(fp1);

fclose(fp2);

fclose(fp3);

fclose(fp4);

//getch();

}

*/





