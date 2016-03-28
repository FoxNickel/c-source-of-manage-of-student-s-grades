#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

int flag=0;//��¼ɾ����ѧ��������������ʱ��Ҫ��ȥ����

/*�ṹ���������浥��ѧ����Ϣ*/
struct students
{
    int stu_number;//ѧ��
    char name[20];//����
    char sex[10];//�Ա�
    int score[6];//�ɼ�
    double sum;//�ܷ�
    double average;//ƽ���ɼ�
} stu[40];


/*****************ѡ��˵�������ѡ�����뻹�Ƕ�ȡ����****************************/
int Menu1()//ѡ��˵�
{
    int choice;//ѡ���õı���
    printf("****************************************************************\n");
    printf("****************************��ӭʹ��****************************\n");
    printf("***********************ѧ���ɼ�����ϵͳ*************************\n");
    printf("****************************************************************\n");
    printf("\n");
    printf("**********************��ѡ����Ҫ���еĲ���**********************\n");
    printf("\t\t\t1.����������\n");
    printf("\t\t\t2.�����µ�����\n");
    printf("****************************************************************\n");
    printf("\n");
    scanf("%d",&choice);
    return choice;
}
/********************************�˵�����****************************************/


/*********************���˵�������ѡ��Ҫ���еĲ���******************************/
int Menu2()//���˵�
{
    int choice;//ѡ���õı���
    printf("****************************************************************\n");
    printf("**********************��ѡ����Ҫ���еĲ���**********************\n");
    printf("\t\t\t1.���ֽܷ�������\n");
    printf("\t\t\t2.��ѧ�Ž�������\n");
    printf("\t\t\t3.��������������\n");
    printf("\t\t\t4.�ɼ��޸�&ɾ��\n");
    printf("\t\t\t5.��ѯ\n");
    printf("\t\t\t6.�γ�����ͳ��\n");
    printf("\t\t\t7.����\n");
    printf("\t\t\t8.�˳�ϵͳ\n");
    printf("****************************************************************\n");
    printf("****************************************************************\n");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}
/********************************�˵�����****************************************/


/**********************��ѯʱ����ѡ���ѯ��ʽ�Ĳ˵�*****************************/
int Menu3()//��ѯ�˵�
{
    int choice;
    printf("****************************************************************\n");
    printf("**********************��ѡ����Ҫ���еĲ���**********************\n");
    printf("\t\t\t1.��ѧ�Ž��в�ѯ\n");
    printf("\t\t\t2.���������в�ѯ\n");
    printf("****************************************************************\n");
    scanf("%d",&choice);
    return choice;
}
/********************************�˵�����****************************************/


/*****************************���ֽܷ�������*************************************/
void sort1(struct students stu[],int n)//�ܷ�����
{
    int i,j;//ѭ�����Ʊ���
    struct students stu_temp;//����ʱ��������ʱ�ṹ�����
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(stu[i].sum>stu[j].sum)
            {
                stu_temp = stu[j];
                stu[j]=stu[i];
                stu[i] = stu_temp;
            }
        }
    }
}
/******************************�ܷ��������**************************************/


/*****************************��ѧ�Ž�������*************************************/
void sort2(struct students stu[],int n)//ѧ������
{
    int i,j;//ѭ�����Ʊ���
    struct students stu_temp;//����ʱ��������ʱ�ṹ�����
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(stu[i].stu_number<stu[j].stu_number)
            {
                stu_temp = stu[j];
                stu[j]=stu[i];
                stu[i] = stu_temp;
            }
        }
    }
}
/******************************ѧ���������**************************************/


/*****************************��������������*************************************/
void sort3(struct students stu[],int n)//��������
{
    int i,j;//ѭ�����Ʊ���
    struct students stu_temp;//����ʱ��������ʱ�ṹ�����
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(strcmp(stu[i].name,stu[j].name)<0)
            {
                stu_temp = stu[j];
                stu[j]=stu[i];
                stu[i] = stu_temp;
            }
        }
    }
}
/******************************�����������**************************************/


/********************����������Ӧ���˵������в�����************************/
/*****************************������Ҫ����************************************/
/**************************1.����ܷ�������*********************************/
/**************************2.���ѧ��������*********************************/
/**************************3.�������������*********************************/
/**************************4.�޸�&ɾ��****************************************/
/**************************5.��ѯ*********************************************/
/**************************6.ͳ�ƿγ̽��*************************************/
/**************************7.�����ݱ��浽�ļ�*********************************/
/**************************8.�˳�ϵͳ*****************************************/
void Process(int student,int subjects,char subname[8][10])//������
{
    int student_AfterMinus = student - flag;
    int i,j,k;//ѭ�����Ʊ���
    float sub_sum[subjects];//�����ܳɼ�
    int choice;//Ŀ¼ѡ�����
    int edit_number;//�޸ĺͲ��ҵ�ʱ�������ѧ��
    struct students *p = stu;
    int change;//ȷ���Ƿ��޸ĵı���
    char name_temp[20];//ͨ��������ѯʱ������������
    int qualify[subjects][5];//�жϿγ�������Ŀ������
    while(1)
    {
        choice = Menu2();
        for(i=0; i<subjects; i++)
            for(j=0; j<5; j++)
                qualify[i][j]=0;//ÿ��ͳ��ǰ����
        if(choice==1)//�ܷ�����
        {
            printf("���ܷ�������Ϊ:\n");
            sort1(p,student);
            printf("����\tѧ��\t�Ա�\t");
            for(i=0; i<subjects; i++)
            {
                printf("%s\t",subname[i]);
            }
            printf("�ܷ�\tƽ����");
            printf("\n");
            for(i=0; i<student - flag; i++)
            {
                printf("%s\t%d\t%s\t",stu[i].name,stu[i].stu_number,stu[i].sex);
                for(j=0; j<subjects; j++)
                {
                    printf("%d\t",stu[i].score[j]);
                }
                printf("%5.2f\t%5.2f",stu[i].sum,stu[i].average);
                printf("\n");
            }
        }
        else if(choice==2)//ѧ������
        {
            printf("��ѧ��������Ϊ:\n");
            sort2(p,student);
            printf("����\tѧ��\t�Ա�\t");
            for(i=0; i<subjects; i++)
            {
                printf("%s\t",subname[i]);
            }
            printf("�ܷ�\tƽ����");
            printf("\n");//�����ͷ������̨
            for(i=0; i<student - flag; i++)
            {
                printf("%s\t%d\t%s\t",stu[i].name,stu[i].stu_number,stu[i].sex);
                for(j=0; j<subjects; j++)
                {
                    printf("%d\t",stu[i].score[j]);
                }
                printf("%5.2f\t%5.2f",stu[i].sum,stu[i].average);
                printf("\n");
            }
        }
        else if(choice==3)//��������
        {
            printf("������������Ϊ:\n");
            sort3(p,student);
            printf("����\tѧ��\t�Ա�\t");
            for(i=0; i<subjects; i++)
            {
                printf("%s\t",subname[i]);
            }
            printf("�ܷ�\tƽ����");
            printf("\n");//�����ͷ������̨
            for(i=0; i<student - flag; i++)
            {
                printf("%s\t%d\t%s\t",stu[i].name,stu[i].stu_number,stu[i].sex);
                for(j=0; j<subjects; j++)
                {
                    printf("%d\t",stu[i].score[j]);
                }
                printf("%5.2f\t%5.2f",stu[i].sum,stu[i].average);
                printf("\n");
            }
        }
        else if(choice==4)//����ѧ�Ž����޸�
        {
            printf("������Ҫ�޸ĵ�ѧ����ѧ��:");
            scanf("%d",&edit_number);
            for(i=0; i<student_AfterMinus; i++)
                {
                    if(edit_number==stu[i].stu_number)
                    {
                        printf("����ͬѧ�ĳɼ���Ϣ����:\n");
                        printf("����\tѧ��\t�Ա�\t");
                        for(j=0; j<subjects; j++)
                        {
                            printf("%s\t",subname[i]);
                        }
                        printf("�ܷ�\tƽ����");
                        printf("\n");
                        printf("%s\t%d\t%s\t",stu[i].name,stu[i].stu_number,stu[i].sex);
                        for(k=0; k<subjects; k++)
                        {
                            printf("%d\t",stu[i].score[k]);
                        }
                        printf("%5.2f\t%5.2f",stu[i].sum,stu[i].average);
                        printf("\n");
                    }
                }
            printf("��ȷ��Ҫ�޸ĸ�ѧ���ĳɼ���(�޸�������1��ɾ��������2������������������):");
            scanf("%d",&change);
            if(change==1)
            {
                for(i=0; i<student_AfterMinus; i++)
                {
                    if(edit_number==stu[i].stu_number)
                    {
                        stu[i].sum=0;
                        for(j=0; j<subjects; j++)
                        {
                            printf("�������%sͬѧ��%s�ɼ���",stu[i].name,subname[j]);
                            scanf("%d",&stu[i].score[j]);
                            stu[i].sum += stu[i].score[j];
                        }
                        stu[i].average = stu[i].sum/subjects;
                    }
                }
            }
            else if(change==2)
            {
                flag++;
                for(i=0;i<student_AfterMinus;i++)
                {
                    if(edit_number==stu[i].stu_number)
                    {
                        for(j=0;j<20;j++)
                            stu[i].name[j] = 'z';
                        stu[i].stu_number = 999999;
                        stu[i].sum = -1;
                        sort1(p,student);
                    }
                }
            }
            else
                continue;
        }
        else if(choice==5)//��ѯ
        {
            choice=Menu3();
            if(choice==1)
            {
                printf("������Ҫ���ҵ�ѧ��ѧ��:");
                scanf("%d",&edit_number);
                for(i=0; i<student_AfterMinus; i++)
                {
                    if(edit_number==stu[i].stu_number)
                    {
                        printf("����ͬѧ�ĳɼ���Ϣ����:\n");
                        printf("����\tѧ��\t�Ա�\t");
                        for(j=0; j<subjects; j++)
                        {
                            printf("%s\t",subname[i]);
                        }
                        printf("�ܷ�\tƽ����");
                        printf("\n");
                        printf("%s\t%d\t%s\t",stu[i].name,stu[i].stu_number,stu[i].sex);
                        for(k=0; k<subjects; k++)
                        {
                            printf("%d\t",stu[i].score[k]);
                        }
                        printf("%5.2f\t%5.2f",stu[i].sum,stu[i].average);
                        printf("\n");
                    }
                }
            }
            else if(choice==2)
            {
                printf("������Ҫ���ҵ�ѧ������:");
                scanf("%s",name_temp);
                for(i=0; i<student_AfterMinus; i++)
                {
                    if(strcmp(name_temp,stu[i].name)==0)
                    {
                        printf("����ͬѧ�ĳɼ���Ϣ����:\n");
                        printf("����\tѧ��\t�Ա�\t");
                        for(j=0; j<subjects; j++)
                        {
                            printf("%s\t",subname[i]);
                        }
                        printf("�ܷ�\tƽ����");
                        printf("\n");
                        printf("%s\t%d\t%s\t",stu[i].name,stu[i].stu_number,stu[i].sex);
                        for(k=0; k<subjects; k++)
                        {
                            printf("%d\t",stu[i].score[k]);
                        }
                        printf("%5.2f\t%5.2f",stu[i].sum,stu[i].average);
                        printf("\n");
                    }
                }
            }
        }
        else if(choice==6)//�γ�����ͳ��
        {
            for(i=0; i<subjects; i++)
            {
                sub_sum[i]=0;
                for(j=0; j<student_AfterMinus; j++)
                {
                    sub_sum[i] += stu[j].score[i];
                    if(stu[j].score[i]/10>=9&&stu[j].score[i]/10<=10)
                        qualify[i][0]++;
                    else if(stu[j].score[i]/10<6)
                        qualify[i][4]++;
                    else
                        qualify[i][9-(stu[j].score[i]/10)]++;
                }
            }
            printf("�γ���Ϣͳ������:\n");
            for(i=0; i<subjects; i++)
            {
                printf("\t%s\t",subname[i]);
            }
            printf("\n");
            printf("��");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][0],((float)qualify[i][0]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("��");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][1],((float)qualify[i][1]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("��");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][2],((float)qualify[i][2]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("����");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][3],((float)qualify[i][3]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("������");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][4],((float)qualify[i][4]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("�ܷ�");
            for(i=0; i<subjects; i++)
            {
                printf("\t%5.2f\t",sub_sum[i]);
            }
            printf("\n");
            printf("ƽ����");
            for(i=0; i<subjects; i++)
            {
                printf("\t%5.2f\t",sub_sum[i]/student_AfterMinus);
            }
            printf("\n");
        }
        else if(choice==7)//���浽�ļ�
        {
            FILE * fp;
            char filename[20];
            printf("������Ҫ������ļ���:");
            scanf("%s",filename);
            fp = fopen(filename,"wb+");
            fwrite(&flag,sizeof(flag),1,fp);
            fwrite(&student,sizeof(student),1,fp);
            fwrite(&subjects,sizeof(subjects),1,fp);
            for(i=0; i<subjects; i++)
            {
                fwrite(&subname[i],sizeof(subname[i]),1,fp);
            }
            for(i=0; i<student; i++)
            {
                fwrite(&stu[i],sizeof(struct students),1,fp);
            }
            fclose(fp);
        }
        else if(choice==8)//�˳�ϵͳ
        {
            break;
        }
        else//ָ���������ʱ����ʾ
            printf("�������������������룡\n");
    }
}
/******************************����������**************************************/

/******************************�������뺯��**************************************/
void Input ()//���ݶ���
{
    int i,j;//ѭ�����Ʊ���
    int student;//�������ѧ��������
    int student_AfterMinus;
    int subjects;//�����Ŀ����
    char subname[8][10];//�����Ŀ����

    printf("������༶ѧ����������");
    scanf("%d",&student);
    student_AfterMinus = student - flag;
    printf("�������Ŀ������");
    scanf("%d",&subjects);

    for(i=0; i<subjects; i++)
    {
        printf("�������%d�ſ�Ŀ���ƣ�",i+1);
        scanf("%s",subname[i]);
    }

    for(i=0; i<student_AfterMinus; i++)
    {
        printf("�������%d��ѧ����������",i+1);
        scanf("%s",stu[i].name);
        printf("�������%d��ͬѧ��ѧ�ţ�",i+1);
        scanf("%d",&stu[i].stu_number);
        printf("�������%d��ͬѧ���Ա�",i+1);
        scanf("%s",stu[i].sex);
        stu[i].sum=0;
        for(j=0; j<subjects; j++)
        {
            printf("������%sͬѧ��%s�ɼ���",stu[i].name,subname[j]);
            scanf("%d",&stu[i].score[j]);
            stu[i].sum += stu[i].score[j];
        }
        stu[i].average = stu[i].sum/subjects;
    }

    Process(student,subjects,subname);


}
/********************************��������****************************************/

/******************************��½���뺯��**************************************/
int passWord()//��������
{
    int i,count;
    printf("����������:(����Ϊstudent)\n");
    while(1)
    {
        char password[20]= {"student"},input[20];
        for(count=0; count<3; count++)
        {
            for(i=0; i<20; i++)
            {
                input[i] = getch();
                if(input[i]=='\r')
                {
                    input[i]='\0';
                    break;
                }
                printf("*");
            }
            printf("\n");
            if(strcmp(input,password)==0)break;
            else printf("�������\n");
        }
        break;
    }
    return count;
}
/********************************��������****************************************/

/**********************ѡ������ѡ�����뺯����ȡ���ݣ�*************************/
void Choice()//ѡ���ȡ��������
{
    int choice;//����ѡ�����뻹�Ƕ�ȡ�ı���
    int student;
    int subjects;
    char subname[8][10];
    int i;
    FILE * fp;
    while(1)
    {
        choice = Menu1();
        if(choice==2)//����
        {
            Input();
            break;
        }
        else if(choice==1)//��ȡ
        {
            char filename[20];
            while(1)
            {
                printf("������Ҫ������ļ���:");
                scanf("%s",filename);
                if((fp = fopen(filename,"rb"))==NULL)
                {
                    printf("û�д��ļ�������������!\n");
                    continue;
                }
                else break;
            }
            fread(&flag,sizeof(flag),1,fp);
            fread(&student,sizeof(student),1,fp);
            fread(&subjects,sizeof(subjects),1,fp);
            for(i=0; i<subjects; i++)
            {
                fread(&subname[i],sizeof(subname[i]),1,fp);
            }
            for(i=0; i<student; i++)
            {
                fread(&stu[i],sizeof(struct students),1,fp);
            }
            fclose(fp);
            Process(student,subjects,subname);
            break;
        }
        else
        {
            printf("�������������������룡\n");
        }
    }
}
/********************************��������****************************************/


/*********************************������*****************************************/
int main()
{
    int error;
    error = passWord();
    if(error!=3)
        Choice();
    else
        printf("��������������󣬳����˳�!!!");
    return 0;
}
