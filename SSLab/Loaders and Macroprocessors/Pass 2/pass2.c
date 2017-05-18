#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
char label[10],opcode[10],operand[10],mnemonic[10],obj[50][50],temp[20];
printf("hi");
int address,start,len,i,length=0,u,v;
printf("hi");
FILE *fp1,*fp2,*fp3,*fp4,*fp5;
fp1=fopen("assmlist.dat","w");
fp2=fopen("symtab.dat","r");
fp3=fopen("intermediate.dat","r");
fp4=fopen("optab.dat","r");
fp5=fopen("objcode.dat","w");
fprintf(fp1,"Hello");
fscanf(fp3,"%s%s%s",label,opcode,operand);
if(strcmp(opcode,"START")==0)
{	
	fprintf(fp1,"%s\t%s\t%s\t",label,opcode,operand);
	start = atoi(operand);
	strcpy(obj[0],label);
	strcat(obj[1],operand);
	fscanf(fp3,"%x%s%s%s",&address,label,opcode,operand);
}
else 
{
	strcpy(obj[0],"**");
	strcpy(obj[1],"000000");
}
strcpy(obj[2],"null");
int p=3;
while(strcmp(opcode,"END")!=0)
{
	if(strcmp(opcode,"BYTE")==0)
	{
		len=strlen(operand);
		fprintf(fp1,"%x\t%s\t%s\t%s",address,label,opcode,operand);
		for(i=2;i<len-1;i++)
		{
			fprintf(fp1,"%x",operand[i]);
			sprintf(temp,"%x",operand[i]);
			strcat(obj[p],temp);
			length++;
		}
	p++;
	fprintf(fp1,"\n");
	}
	else if(strcmp(opcode,"WORD")==0)
	{
		fprintf(fp1,"%x\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,operand);
		strcpy(obj[p],"00000");
		strcpy(obj[p],operand);
		p++;
		length+=3;
	}
	else if((strcmp(opcode,"RESW")==0)||(strcmp(opcode,"RESB")==0))
	{
		fprintf(fp1,"%x\t%s\t%s\t%s\n",address,label,opcode,operand);
	}
	else
	{
		rewind(fp4);
		fscanf(fp4,"%s%x",mnemonic,&u);
		while(strcmp(mnemonic,opcode)!=0)
			fscanf(fp4,"%s%x",mnemonic,&u);
		rewind(fp2);
		fscanf(fp2,"%s%x",mnemonic,&v);
		if(strchr(operand,','))
		{
			while(strcmp(strtok(operand,","),mnemonic)!=0)
			fscanf(fp2,"%s%x",mnemonic,&v);
			v = v+ 0x8000;
			fprintf(fp1,"%x\t%s\t%s\t%s\t%x%x\n",address,label,opcode,operand,u,v);
		}
		else
		{
			while(strcmp(mnemonic,operand)!=0)
			fscanf(fp2,"%s%x",mnemonic,&v);
			fprintf(fp1,"%x\t%s\t%s\t%s\t%x%x\n",address,label,opcode,operand,u,v);
		}
	length+=3;
	sprintf(obj[p],"%x%x",u,v);
	p++;
	}
fscanf(fp3,"%x%s%s%s",&address,label,opcode,operand);
}
fprintf(fp1,"%x\t%s\t%s\t%s\t%x%x\n",address,label,opcode,operand);
sprintf(obj[2],"%x",address);
start = atoi(obj[2])-start;
sprintf(obj[2],"%d",start);
//print header record
fprintf(fp5,"H\t%s\t%s\t%s\t",obj[0],obj[1],obj[2]);
//print text record
fprintf(fp5,"T\t%s\t%d\t",obj[1],length);
for(i=3;i<p;i++)
fprintf(fp5,"%s\t",obj[i]);
//print end record
fprintf(fp5,"E\t%s\n",obj[1]);
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
fclose(fp5);
}

