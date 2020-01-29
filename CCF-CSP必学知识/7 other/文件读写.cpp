#include<stdio.h>
main()
{
    FILE *fp1,*fp2;
    fp1=fopen("data.in","r");
    fp2=fopen("data.out","w");
    int a,b;
    fscanf(fp1,"%d%d",&a,&b);
    fprintf(fp2,"%d\n",a+b);
    fclose(fp1);
    fclose(fp2);
return 0;
}
