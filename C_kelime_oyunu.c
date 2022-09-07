#include <stdio.h>
#include <stdlib.h>

int main()
{
    int boyutSatir,boyutSutun;
    char arayan[100];
    srand(time(NULL));
    int i=0,j=0,x,y,rasgele;
    int cntrol1=0, cntrol2=0, cntrol3=0, cntrol4=0;

    printf("\tSatir sayisini giriniz: ");
    scanf("%d",&boyutSatir);
    printf("\tSutun sayisini giriniz: ");
    scanf("%d",&boyutSutun);
    char *kelimeler[boyutSatir][boyutSutun];

    for(x=0;x<boyutSatir;x++)
    {
        for(y=0;y<boyutSutun;y++)
        {
            don:
            rasgele=rand()%122;
            if(rasgele<122 && rasgele>97)
            {
                *(*(kelimeler+x)+y)=rasgele;
                printf("%c\t",*(*(kelimeler+x)+y));
            }
            else
            {
                goto don;
            }
        }
        printf("\n");
    }

    printf("\n--------------------------------\n");
    printf("Aranacak olan cumleyi giriniz: ");
    scanf("%s",&arayan);

    while(arayan[j]!='\0')
        j++;


    for(x=0;x<boyutSatir;x++)
    {
        for(y=0;y<boyutSutun;y++)
        {
            if(*(*(kelimeler+x)+y)== *(arayan))
            {
                while(*(*(kelimeler+x)+y+i)== *(arayan+i) && y+i<boyutSutun)
                {
                    i++;
                    if(i==j)
                    {
                        cntrol1+=1;
                        i=0;
                        printf("\nSoldan Saga Koordinatlari--> %d.satir , %d.sutun",x+1,y+1);
                        break;
                    }
                }
            }
        }
    }
//----------------
    i=0;
    for(x=0;x<boyutSatir;x++)
    {
        for(y=0;y<boyutSutun;y++)
        {
            if(*(*(kelimeler+x)+y)== *(arayan))
            {
                while(*(*(kelimeler+x+i)+y)== *(arayan+i) && x+i<boyutSutun)
                {
                    i++;
                    if(i==j)
                    {
                        cntrol2+=1;
                        i=0;
                        printf("\nYukaridan Asagiya Koordinatlari--> %d.satir , %d.sutun",x+1,y+1);
                        break;
                    }
                }
            }
        }
    }

//----------------
    i=0;
    for(x=0;x<boyutSatir;x++)
    {
        for(y=boyutSutun;y>=0;y--)
        {
            if(*(*(kelimeler+x)+y)== *(arayan))
            {
                while(*(*(kelimeler+x)+y-i)== *(arayan+i) && y-i<boyutSutun)
                {
                    i++;
                    if(i==j)
                    {
                        cntrol3+=1;
                        i=0;
                        printf("\nSagdan Sola Koordinatlari--> %d.satir , %d.sutun",x+1,y+1);
                        break;
                    }
                }
            }
        }
    }

//----------------
    i=0;
    for(x=boyutSatir;x>=0;x--)
    {
        for(y=boyutSutun;y>=0;y--)
        {
            if(*(*(kelimeler+x)+y)== *(arayan))
            {
                while(*(*(kelimeler+x-i)+y)== *(arayan+i) && x-i<boyutSutun)
                {
                    i++;
                    if(i==j)
                    {
                        cntrol4+=1;
                        i=0;
                        printf("\nAsagidan Yukariya Koordinatlari--> %d.satir , %d.sutun",x+1,y+1);
                        break;
                    }
                }
            }
        }
    }

    printf("\n-----------------------------------");
    printf("\n %d tane SOLDAN SAGA var.",cntrol1);
    printf("\n %d tane YUKARIDAN ASAGIYA var.",cntrol2);
    printf("\n %d tane SAGDAN SOLA var.",cntrol3);
    printf("\n %d tane ASAGIDAN YUKARIYA var.",cntrol4);
    printf("\n-----------------------------------");

    return 0;
}
