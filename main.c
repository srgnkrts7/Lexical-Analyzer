#include<stdio.h>
#include<ctype.h>
#include<string.h>
char anahtarlar[18][10]={"break","case","char","const","continue","do","else","enum","float","for","goto","if","int","long","record","return","static","while"};
void keyw(char *p,FILE * x);
int i=0;
main()
{
    char dosyaAdi[50];
	char karakter;
	int j;
	char kelime[25];
	char operatorler[]="!%^&*-+=~|.<>/?";
	char ayraclar[15]=" \t\n,;(){}[]#\"<>";
    FILE * okunanDosya;
    FILE * yazmaDosya;
    printf("Lutfen Kullanilacak Dosya Ismini Giriniz('girdi.txt' Biciminde): ");
    scanf("%s",dosyaAdi);
    okunanDosya = fopen(dosyaAdi,"r");
    if(okunanDosya==NULL)
	{
	 printf("\n --- Dosya Bulunamadi! ---");
	 exit(0);
	}
    printf("\nLutfen Cikti Yazdirilicak Dosya Ismini Giriniz('cikti.txt' Biciminde): ");
    scanf("%s",dosyaAdi);
    yazmaDosya=fopen(dosyaAdi,"w");
	if(yazmaDosya==NULL)
	{
	 printf("\n --- Dosya Bulunamadi! ---");
	 exit(0);
	}
	printf("\n");
	while((karakter=fgetc(okunanDosya))!=EOF)
	{
         for(j=0;j<=14;j++)
        {
            if(karakter==operatorler[j])
            {
                printf("Operator(%c)\n",karakter);
                fputs("Operator----> ",yazmaDosya);
                fputc(karakter,yazmaDosya);
                fputc(10,yazmaDosya);
                kelime[i]='\0';
                anahtarKelime(kelime,yazmaDosya);
            }
        }
        for(j=0;j<=14;j++)
        {
            if(i==-1)
            break;
            if(karakter==ayraclar[j])
            {
                if(karakter=='"')
                {
                    do
                    {
                        karakter=fgetc(okunanDosya);
                        printf("%c",karakter);
                    }while(karakter!='"');
                    printf("\b is an argument\n");
                    fputs("Argument---> ",yazmaDosya);
                    fputc(karakter,yazmaDosya);
                    fputc(10,yazmaDosya);
                    i=-1;
                    break;
                }
                if(karakter=='#')
                {
                    while(karakter!='>')
                    {
                        printf("%c",karakter);
                        karakter=fgetc(okunanDosya);
                    }
                    printf("HeaderFile(%c)\n",karakter);
                    fputs("HeaderFile--> ",yazmaDosya);
                    fputc(karakter,yazmaDosya);
                    fputc(10,yazmaDosya);
                    i=-1;
                    break;
                }
                kelime[i]='\0';
                anahtarKelime(kelime,yazmaDosya);
                if(ayraclar[j]==';')
                {
                    char s1[] ="EndOfLine";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,yazmaDosya);
                        s++;
                    }
                    fputc(10,yazmaDosya);
                    printf("EndOfLine\n");
                }
                else if(ayraclar[j]=='}')
                {
                    char s1[] ="RightCurlyBracket";
                    char *s;
                    s= &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,yazmaDosya);
                        s++;
                    }
                    fputc(10,yazmaDosya);
                    printf("RightCurlyBracket\n");
                }
                else if(ayraclar[j]=='{')
                {
                    char s1[] ="LeftCurlyBracket";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,yazmaDosya);
                        s++;
                    }
                    fputc(10,yazmaDosya);
                    printf("LeftCurlyBracket\n");
                }
                else if(ayraclar[j]=='[')
                {
                    char s1[] ="LeftSquareBracket";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,yazmaDosya);
                        s++;
                    }
                    fputc(10,yazmaDosya);;
                    printf("LeftSquareBracket\n");
                }
                else if(ayraclar[j]==']')
                {
                    char s1[] ="RightSquareBracket";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,yazmaDosya);
                        s++;
                    }
                    fputc(10,yazmaDosya);
                    printf("RightSquareBracket\n");
                }
                else if(ayraclar[j]==')')
                {
                    char s1[] ="RightParanthesis";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,yazmaDosya);
                        s++;
                    }
                    fputc(10,yazmaDosya);
                    printf("RightParanthesis\n");
                }
                else if(ayraclar[j]=='(')
                {
                    char s1[] ="LeftParanthesis";
                    char *s = &s1;
                    while(*s!='\0')
                    {
                        fputc(*s,yazmaDosya);
                        s++;
                    }
                    fputc(10,yazmaDosya);
                    printf("LeftParanthesis\n");
                }
            }
        }
        if(i!=-1)
        {
            kelime[i]=karakter;
            i++;
        }
        else
            i=0;
	}
	return 0;
}
void anahtarKelime(char *p,FILE * x)
{
    char temp[10];
    int k=0;
    int bayrak=0;
    for(k=0;k<=17;k++)
    {
        if(strcmp(anahtarlar[k],p)==0)
        {
            printf("Keyword(%s)\n",p);
            fputs("Keyword-----> ",x);
            fputs(p,x);
            fputc(10,x);
            bayrak=1;
            break;
        }
    }
    if(bayrak==0)
    {
        if(isdigit(p[0]))
        {
            printf("IntCons(%s)\n",p);
            fputs("IntCons-----> ",x);
            fputs(p,x);
            fputc(10,x);
        }
        else
        {
            if(p[0]!='\0')
            {
                printf("Identifier(%s)\n",p);
                fputs("Identifier--> ",x);
                fputs(p,x);
                fputc(10,x);
            }
        }
    }
    i=-1;
}

                                                                                        //MERT GÜLBAHÇE 05150000684
                                                                                        //SERGEN KARATAÞ 05150000637
