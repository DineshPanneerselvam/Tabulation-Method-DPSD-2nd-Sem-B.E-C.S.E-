//PROGRAM FOR TABULATION BY DINESH P(B.E - C.S.E) Saveetha Engineering College at 25-02-2017
#include<stdio.h>
void main()
{
    FILE *save;
    int b[16],a[16][4],n,i,j,t[6],x,y,ans[100][6],f=0,k,din[30][2],u=0,l,m,res=0,shrt[100][8],fin[10][8],h,extra,c,result[10][8],tr;
    save=fopen("answer.txt","w+");
    printf("\t\t\tTABULATON METHOD\n\t\t\t\tby DINESH\n");
    printf("Enter The Number of Values:");
    scanf("%d",&n);
    printf("\nEnter The Minterms:\n");
    fprintf(save,"\t\t\t\tANSWER\n\n");
    fprintf(save,"The Minterms : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        fprintf(save,"%d,",b[i]);
    }
    fprintf(save,"\nThe Dont Care : ");
    printf("Enter the Number of DONT CARE's:\n");
    scanf("%d",&extra);
    printf("Enter The DON'T CARES:\n");
    for(i=n;i<(extra+n);i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=n;i<(extra+n);i++)
    {
        fprintf(save,"%d,",b[i]);
    }
    fprintf(save,"\nSTEP 1:\n\t\t");
    c=n;
    n=n+extra;
    for(i=0;i<n;i++)
    {
        switch(b[i])
        {
        case 0:
            a[i][0]=0; a[i][1]=0; a[i][2]=0; a[i][3]=0;break;
        case 1:
            a[i][0]=0; a[i][1]=0; a[i][2]=0; a[i][3]=1;break;
        case 2:
            a[i][0]=0; a[i][1]=0; a[i][2]=1; a[i][3]=0;break;
        case 3:
            a[i][0]=0; a[i][1]=0; a[i][2]=1; a[i][3]=1;break;
        case 4:
            a[i][0]=0; a[i][1]=1; a[i][2]=0; a[i][3]=0;break;
        case 5:
            a[i][0]=0; a[i][1]=1; a[i][2]=0; a[i][3]=1;break;
        case 6:
            a[i][0]=0; a[i][1]=1; a[i][2]=1; a[i][3]=0;break;
        case 7:
            a[i][0]=0; a[i][1]=1; a[i][2]=1; a[i][3]=1;break;
        case 8:
            a[i][0]=1; a[i][1]=0; a[i][2]=0; a[i][3]=0;break;
        case 9:
            a[i][0]=1; a[i][1]=0; a[i][2]=0; a[i][3]=1;break;
        case 10:
            a[i][0]=1; a[i][1]=0; a[i][2]=1; a[i][3]=0;break;
        case 11:
            a[i][0]=1; a[i][1]=0; a[i][2]=1; a[i][3]=1;break;
        case 12:
            a[i][0]=1; a[i][1]=1; a[i][2]=0; a[i][3]=0;break;
        case 13:
            a[i][0]=1; a[i][1]=1; a[i][2]=0; a[i][3]=1;break;
        case 14:
            a[i][0]=1; a[i][1]=1; a[i][2]=1; a[i][3]=0;break;
        case 15:
            a[i][0]=1; a[i][1]=1; a[i][2]=1; a[i][3]=1;break;
        }
    }
        for(i=0;i<n;i++)
        {
            for(j=0;j<4;j++)
           {
             fprintf(save,"%d  ",a[i][j]);
           }
        fprintf(save,"  -%d",b[i]);
        fprintf(save,"\n\t\t");
        }
        fprintf(save,"\n");
        for(i=1;i<n;i++)
        {
            for(j=0;j<(n-i);j++)
            {
                x=a[j][0]+a[j][1]+a[j][2]+a[j][3];
                y=a[j+1][0]+a[j+1][1]+a[j+1][2]+a[j+1][3];
                if(x>y)
                {
                    t[0]=a[j][0]; t[1]=a[j][1]; t[2]=a[j][2]; t[3]=a[j][3];
                    a[j][0]=a[j+1][0]; a[j][1]=a[j+1][1]; a[j][2]=a[j+1][2]; a[j][3]=a[j+1][3];
                    a[j+1][0]=t[0]; a[j+1][1]=t[1]; a[j+1][2]=t[2]; a[j+1][3]=t[3];
                }
            }
        }
        fprintf(save,"STEP 2:\n\t\t");
        for(i=0;i<n;i++)
        {
            for(j=0;j<4;j++)
           {
             fprintf(save,"%d  ",a[i][j]);
           }
            fprintf(save,"\n\t\t");
        }
        for(i=0;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                x=0;
                for(k=0;k<4;k++)
                {
                    if(a[i][k]==a[j][k])
                        x++;
                }
                if(x==3)
                {
                    res++;
                    for(l=0;l<4;l++)
                    {
                    if(a[i][l]==a[j][l])
                        ans[f][l]=a[i][l];
                    else
                        ans[f][l]=5;
                    }
                    f++;
                    if(a[i][0]==0&&a[i][1]==0&&a[i][2]==0&&a[i][3]==0)
                        din[u][0]=0;
                    else if(a[i][0]==0&&a[i][1]==0&&a[i][2]==0&&a[i][3]==1)
                        din[u][0]=1;
                    else if(a[i][0]==0&&a[i][1]==0&&a[i][2]==1&&a[i][3]==0)
                        din[u][0]=2;
                    else if(a[i][0]==0&&a[i][1]==0&&a[i][2]==1&&a[i][3]==1)
                        din[u][0]=3;
                    else if(a[i][0]==0&&a[i][1]==1&&a[i][2]==0&&a[i][3]==0)
                        din[u][0]=4;
                    else if(a[i][0]==0&&a[i][1]==1&&a[i][2]==0&&a[i][3]==1)
                        din[u][0]=5;
                    else if(a[i][0]==0&&a[i][1]==1&&a[i][2]==1&&a[i][3]==0)
                        din[u][0]=6;
                    else if(a[i][0]==0&&a[i][1]==1&&a[i][2]==1&&a[i][3]==1)
                        din[u][0]=7;
                    else if(a[i][0]==1&&a[i][1]==0&&a[i][2]==0&&a[i][3]==0)
                        din[u][0]=8;
                    else if(a[i][0]==1&&a[i][1]==0&&a[i][2]==0&&a[i][3]==1)
                        din[u][0]=9;
                    else if(a[i][0]==1&&a[i][1]==0&&a[i][2]==1&&a[i][3]==0)
                        din[u][0]=10;
                    else if(a[i][0]==1&&a[i][1]==0&&a[i][2]==1&&a[i][3]==1)
                        din[u][0]=11;
                    else if(a[i][0]==1&&a[i][1]==1&&a[i][2]==0&&a[i][3]==0)
                        din[u][0]=12;
                    else if(a[i][0]==1&&a[i][1]==1&&a[i][2]==0&&a[i][3]==1)
                        din[u][0]=13;
                    else if(a[i][0]==1&&a[i][1]==1&&a[i][2]==1&&a[i][3]==0)
                        din[u][0]=14;
                    else if(a[i][0]==1&&a[i][1]==1&&a[i][2]==1&&a[i][3]==1)
                        din[u][0]=15;


                    if(a[j][0]==0&&a[j][1]==0&&a[j][2]==0&&a[j][3]==0)
                        din[u][1]=0;
                    else if(a[j][0]==0&&a[j][1]==0&&a[j][2]==0&&a[j][3]==1)
                        din[u][1]=1;
                    else if(a[j][0]==0&&a[j][1]==0&&a[j][2]==1&&a[j][3]==0)
                        din[u][1]=2;
                    else if(a[j][0]==0&&a[j][1]==0&&a[j][2]==1&&a[j][3]==1)
                        din[u][1]=3;
                    else if(a[j][0]==0&&a[j][1]==1&&a[j][2]==0&&a[j][3]==0)
                        din[u][1]=4;
                    else if(a[j][0]==0&&a[j][1]==1&&a[j][2]==0&&a[j][3]==1)
                        din[u][1]=5;
                    else if(a[j][0]==0&&a[j][1]==1&&a[j][2]==1&&a[j][3]==0)
                        din[u][1]=6;
                    else if(a[j][0]==0&&a[j][1]==1&&a[j][2]==1&&a[j][3]==1)
                        din[u][1]=7;
                    else if(a[j][0]==1&&a[j][1]==0&&a[j][2]==0&&a[j][3]==0)
                        din[u][1]=8;
                    else if(a[j][0]==1&&a[j][1]==0&&a[j][2]==0&&a[j][3]==1)
                        din[u][1]=9;
                    else if(a[j][0]==1&&a[j][1]==0&&a[j][2]==1&&a[j][3]==0)
                        din[u][1]=10;
                    else if(a[j][0]==1&&a[j][1]==0&&a[j][2]==1&&a[j][3]==1)
                        din[u][1]=11;
                    else if(a[j][0]==1&&a[j][1]==1&&a[j][2]==0&&a[j][3]==0)
                        din[u][1]=12;
                    else if(a[j][0]==1&&a[j][1]==1&&a[j][2]==0&&a[j][3]==1)
                        din[u][1]=13;
                    else if(a[j][0]==1&&a[j][1]==1&&a[j][2]==1&&a[j][3]==0)
                        din[u][1]=14;
                    else if(a[j][0]==1&&a[j][1]==1&&a[j][2]==1&&a[j][3]==1)
                        din[u][1]=15;

                    u++;
                }
            }

        }

        for(i=0;i<res;i++)
        {
            f=0;
            for(j=4;j<6;j++)
            {
                ans[i][j]=din[i][f];
                f++;
            }
        }

         for(i=1;i<res;i++)
        {
            for(j=0;j<(res-i);j++)
            {
                x=ans[j][4]+ans[j][5];
                y=ans[j+1][4]+ans[j+1][5];
                if(x>y)
                {
                    t[0]=ans[j][0]; t[1]=ans[j][1]; t[2]=ans[j][2]; t[3]=ans[j][3]; t[4]=ans[j][4]; t[5]=ans[j][5];
                    ans[j][0]=ans[j+1][0]; ans[j][1]=ans[j+1][1]; ans[j][2]=ans[j+1][2]; ans[j][3]=ans[j+1][3]; ans[j][4]=ans[j+1][4]; ans[j][5]=ans[j+1][5];
                    ans[j+1][0]=t[0]; ans[j+1][1]=t[1]; ans[j+1][2]=t[2]; ans[j+1][3]=t[3]; ans[j+1][4]=t[4]; ans[j+1][5]=t[5];
                }
            }
        }
        fprintf(save,"\nSTEP 3:\n\t\t");
        for(i=0;i<res;i++)
        {
            for(j=0;j<4;j++)
           {
             fprintf(save,"%d  ",ans[i][j]);
           }
        fprintf(save,"\t\t%d,%d\n\t\t",ans[i][4],ans[i][5]);
        }
        f=0;u=0;
         for(i=0;i<res;i++)
        {
            for(j=1;j<res;j++)
            {
                x=0;
                for(k=0;k<4;k++)
                {
                    if(ans[i][k]==ans[j][k])
                        x++;
                }
            if(x==3)
                {
                    u++;
                    for(l=0;l<4;l++)
                    {
                    if(ans[i][l]==ans[j][l])
                        shrt[f][l]=ans[i][l];
                    else
                        shrt[f][l]=5;
                    }
                    shrt[f][4]=ans[i][4];
                    shrt[f][5]=ans[i][5];
                    shrt[f][6]=ans[j][4];
                    shrt[f][7]=ans[j][5];
                    f++;
                }

        }
        }
        printf("\n\n\t\t");
        fprintf(save,"\nSTEP 4:\n\t\t");
        for(i=0;i<u;i++)
        {
            for(j=0;j<4;j++)
           {
             fprintf(save,"%d  ",shrt[i][j]);
           }
        fprintf(save,"\t\t%d,%d,%d,%d\n\t\t",shrt[i][4],shrt[i][5],shrt[i][6],shrt[i][7]);
        }
        f=0;
    for(i=0;i<u;i++)
    {
        x=5;
        for(j=(i+1);j<u;j++)
        {
            if(shrt[i][0]==shrt[j][0]&&shrt[i][1]==shrt[j][1]&&shrt[i][2]==shrt[j][2]&&shrt[i][3]==shrt[j][3])
            {
                x=0;
            }
        }
        if(x!=0)
        {
            for(k=0;k<8;k++)
            {
                fin[f][k]=shrt[i][k];
            }
            f++;
        }
    }
        y=0;
        for(i=0;i<c;i++)
        {   x=5;
            for(j=0;j<f;j++)
            {
                for(k=4;k<8;k++)
                {
                   if(b[i]==fin[j][k])
                   {
                       x=0;
                   }
                }
            }
            if(x!=0)
            {
                t[y]=b[i];y++;
            }
        }
        for(i=0;i<y;i++)
        {
            for(j=0;j<res;j++)
            {x=5;
            for(k=4;k<6;k++)
            {
                if(t[i]==ans[j][k])
                {
                    x=0;
                }
            }
            if(x==0)
            {
                for(l=0;l<6;l++)
                {
                    fin[f][l]=ans[j][l];
                }
                fin[f][6]=500;
                fin[f][7]=500;
                f++;
            }
           }
        }
        u=0;
        for(i=0;i<f;i++)
        {
        x=5;
        for(j=(i+1);j<f;j++)
        {
            if(fin[i][0]==fin[j][0]&&fin[i][1]==fin[j][1]&&fin[i][2]==fin[j][2]&&fin[i][3]==fin[j][3])
            {
                x=0;
            }
        }
        if(x!=0)
        {
            for(k=0;k<8;k++)
            {
                fin[u][k]=fin[i][k];
            }
            u++;
        }
    }
    tr=u;
    fprintf(save,"\nSTEP 5:\t\tPRIME IMPLICANTS\n\t\t");
        for(i=0;i<u;i++)
        {
            for(j=0;j<4;j++)
            {
               fprintf(save,"%d   ",fin[i][j]);
            }
            fprintf(save,"\t\t");
            for(k=4;k<8;k++)
            {
                if(fin[i][k]<=16)
                {
                    fprintf(save,"%d,",fin[i][k]);
                }
            }
            fprintf(save,"\n\t\t");
        }
        h=0;
        for(i=0;i<u;i++)
        {
            for(j=4;j<8;j++)
            {
                x=0;
                for(k=0;k<u;k++)
                {
                    for(l=4;l<8;l++)
                    {
                        if(fin[i][j]==fin[k][l]&&fin[i][j]!=500)
                        {
                           x++;
                        }
                    }
                }
                if(x==1)
                {
                    for(m=0;m<8;m++)
                    {
                        result[h][m]=fin[i][m];
                    }
                    h++;
                }
            }
        }
        u=0;
        for(i=0;i<h;i++)
        {
        x=5;
            if(result[i][0]==result[i+1][0]&&result[i][1]==result[i+1][1]&&result[i][2]==result[i+1][2]&&result[i][3]==result[i+1][3])
            {
                x=0;
            }
        if(x!=0)
        {
            for(k=0;k<8;k++)
            {
                result[u][k]=result[i][k];
            }
            u++;
        }
        }
        fprintf(save,"\nSTEP 6:\t\tESSENTIAL PRIME IMPLICANTS\n\t\t");
        for(i=0;i<u;i++)
        {
            for(j=0;j<4;j++)
            {
               fprintf(save,"%d   ",result[i][j]);
            }
            fprintf(save,"\t\t");
            for(k=4;k<8;k++)
            {
                if(result[i][k]<=16)
                {
                    fprintf(save,"%d,",result[i][k]);
                }
            }
            fprintf(save,"\n\t\t");
        }
        fprintf(save,"\nANSWER : ");
        for(i=0;i<u;i++)
        {
            if(i==0)
                fprintf(save,"(");
            else
                fprintf(save," + (");
            for(j=0;j<4;j++)
            {
                if(j==0)
                {
                    if(result[i][j]==0)
                        fprintf(save,"A'");
                    else if(result[i][j]==1)
                        fprintf(save,"A");
                }if(j==1)
                {
                    if(result[i][j]==0)
                        fprintf(save,"B'");
                    else if(result[i][j]==1)
                        fprintf(save,"B");
                }if(j==2)
                {
                    if(result[i][j]==0)
                        fprintf(save,"C'");
                    else if(result[i][j]==1)
                        fprintf(save,"C");
                }if(j==3)
                {
                    if(result[i][j]==0)
                        fprintf(save,"D'");
                    else if(result[i][j]==1)
                        fprintf(save,"D");
                }
            }
            fprintf(save,")");
        }
        f=h;
        y=0;
         for(i=0;i<c;i++)
        {   x=5;
            for(j=0;j<u;j++)
            {
                for(k=4;k<8;k++)
                {
                   if(b[i]==result[j][k])
                   {
                       x=0;
                   }
                }
            }
            if(x!=0)
            {
                t[y]=b[i];y++;
            }
        }
        fprintf(save,"\n\nREMAINING MINTERMS : ");
        for(i=0;i<y;i++)
        {
            fprintf(save,"%d,",t[i]);
        }
        for(i=0;i<y;i++)
        {
            for(j=0;j<tr;j++)
            {
                x=0;
                for(k=4;k<8;k++)
                {
                  if(t[i]==fin[j][k])
                  {
                      x=5;
                  }
                }
                if(x==5)
                {
                   for(l=0;l<8;l++)
                   {
                        result[h][l]=fin[j][l];
                   }
                    h++;
                    i++;
                    j=0;
                }
            }
            fprintf(save,"\n\n\t\t");
            for(i=f;i<u;i++)
            {
                for(j=0;j<4;j++)
                {
                    fprintf(save,"%d ",result[i][j]);
                }
                fprintf(save,"\t\t");
                for(k=4;k<8;k++)
                {
                    if(result[i][k]<=16)
                    {
                        fprintf(save,"%d,",result[i][k]);
                    }
                }
                fprintf(save,"\n\t\t");
            }
        fprintf(save,"\n\nUrs Options : ");
        x=0;
        for(i=f;i<u;i++)
        {
            if(x==0)
                fprintf(save,"or (");
            else
                fprintf(save,"(");
            for(j=0;j<4;j++)
            {
                if(j==0)
                {
                    if(result[i][j]==0)
                        fprintf(save,"A'");
                    else if(result[i][j]==1)
                        fprintf(save,"A");
                }if(j==1)
                {
                    if(result[i][j]==0)
                        fprintf(save,"B'");
                    else if(result[i][j]==1)
                        fprintf(save,"B");
                }if(j==2)
                {
                    if(result[i][j]==0)
                        fprintf(save,"C'");
                    else if(result[i][j]==1)
                        fprintf(save,"C");
                }if(j==3)
                {
                    if(result[i][j]==0)
                        fprintf(save,"D'");
                    else if(result[i][j]==1)
                        fprintf(save,"D");
                }
            }
            fprintf(save,") ");
        }

        }
        fprintf(save,"\n\nIF ANY ADDITIONAL MAPPING IS PRESENT REMOVE IT MANUALLY!!!!!!!!\n\n\n");
        printf("\n\nEight Mapping is Not Possible!!!!!!!!!\nSO DON'T EXPECT EIGHT MAPPING:-)\nTHANK YOU FOR USING THIS\n\n");
        getch();
}







