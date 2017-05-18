#include<stdio.h>
#include<string.h>
void main()
{
char input[10],length[10],bitmask[10],reloc;
int start,opcode,address,len,i,addr,actaddr,add;
FILE *fp1,*fp2;
printf("Enter actual starting address");
scanf("%d",&start);
fp1 = fopen("input.dat","r");
fp2 = fopen("output.dat","w");
fscanf(fp1,"%s",input);
while(strcmp(input,"E")!=0)
{
if(strcmp(input,"H")==0)
{
fscanf(fp1,"%d",&add);
fscanf(fp1,"%s",length);
fscanf(fp1,"%s",input);
}
if(strcmp(input,"T")==0)
{

fscanf(fp1,"%d",&address);
fscanf(fp1,"%s",bitmask);
address+=(start-add);
len = strlen(bitmask);
for(i=0;i<len;i++)
{
fscanf(fp1,"%d",&opcode);
fscanf(fp1,"%d",&addr);
if(bitmask[i]=='1')
actaddr = addr+start-add;
else 
actaddr = addr;
fprintf(fp2,"%d\t%d%d\n",address,opcode,actaddr);
address+=3;
}
fscanf(fp1,"%s",input);
}
}
fclose(fp1);
fclose(fp2);
printf("Finished");
}
