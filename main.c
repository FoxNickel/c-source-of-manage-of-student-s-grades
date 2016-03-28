#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

int flag=0;//纪录删除的学生数，后面排序时需要减去该数

/*结构体用来保存单个学生信息*/
struct students
{
    int stu_number;//学号
    char name[20];//姓名
    char sex[10];//性别
    int score[6];//成绩
    double sum;//总分
    double average;//平均成绩
} stu[40];


/*****************选择菜单，用来选择输入还是读取数据****************************/
int Menu1()//选择菜单
{
    int choice;//选择用的变量
    printf("****************************************************************\n");
    printf("****************************欢迎使用****************************\n");
    printf("***********************学生成绩管理系统*************************\n");
    printf("****************************************************************\n");
    printf("\n");
    printf("**********************请选择您要进行的操作**********************\n");
    printf("\t\t\t1.打开已有数据\n");
    printf("\t\t\t2.输入新的数据\n");
    printf("****************************************************************\n");
    printf("\n");
    scanf("%d",&choice);
    return choice;
}
/********************************菜单结束****************************************/


/*********************主菜单，用来选择要进行的操作******************************/
int Menu2()//主菜单
{
    int choice;//选择用的变量
    printf("****************************************************************\n");
    printf("**********************请选择您要进行的操作**********************\n");
    printf("\t\t\t1.按总分进行排序\n");
    printf("\t\t\t2.按学号进行排序\n");
    printf("\t\t\t3.按姓名进行排序\n");
    printf("\t\t\t4.成绩修改&删除\n");
    printf("\t\t\t5.查询\n");
    printf("\t\t\t6.课程数据统计\n");
    printf("\t\t\t7.保存\n");
    printf("\t\t\t8.退出系统\n");
    printf("****************************************************************\n");
    printf("****************************************************************\n");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}
/********************************菜单结束****************************************/


/**********************查询时用来选择查询方式的菜单*****************************/
int Menu3()//查询菜单
{
    int choice;
    printf("****************************************************************\n");
    printf("**********************请选择您要进行的操作**********************\n");
    printf("\t\t\t1.按学号进行查询\n");
    printf("\t\t\t2.按姓名进行查询\n");
    printf("****************************************************************\n");
    scanf("%d",&choice);
    return choice;
}
/********************************菜单结束****************************************/


/*****************************按总分进行排序*************************************/
void sort1(struct students stu[],int n)//总分排序
{
    int i,j;//循环控制变量
    struct students stu_temp;//排序时交换的临时结构体变量
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
/******************************总分排序结束**************************************/


/*****************************按学号进行排序*************************************/
void sort2(struct students stu[],int n)//学号排序
{
    int i,j;//循环控制变量
    struct students stu_temp;//排序时交换的临时结构体变量
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
/******************************学号排序结束**************************************/


/*****************************按姓名进行排序*************************************/
void sort3(struct students stu[],int n)//姓名排序
{
    int i,j;//循环控制变量
    struct students stu_temp;//排序时交换的临时结构体变量
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
/******************************姓名排序结束**************************************/


/********************处理函数（对应主菜单的所有操作）************************/
/*****************************功能主要包括************************************/
/**************************1.输出总分排序结果*********************************/
/**************************2.输出学号排序结果*********************************/
/**************************3.输出姓名排序结果*********************************/
/**************************4.修改&删除****************************************/
/**************************5.查询*********************************************/
/**************************6.统计课程结果*************************************/
/**************************7.将数据保存到文件*********************************/
/**************************8.退出系统*****************************************/
void Process(int student,int subjects,char subname[8][10])//处理函数
{
    int student_AfterMinus = student - flag;
    int i,j,k;//循环控制变量
    float sub_sum[subjects];//各科总成绩
    int choice;//目录选择变量
    int edit_number;//修改和查找的时候输入的学号
    struct students *p = stu;
    int change;//确定是否修改的变量
    char name_temp[20];//通过姓名查询时用来输入姓名
    int qualify[subjects][5];//判断课程优良数目的数组
    while(1)
    {
        choice = Menu2();
        for(i=0; i<subjects; i++)
            for(j=0; j<5; j++)
                qualify[i][j]=0;//每次统计前清零
        if(choice==1)//总分排序
        {
            printf("按总分排序结果为:\n");
            sort1(p,student);
            printf("姓名\t学号\t性别\t");
            for(i=0; i<subjects; i++)
            {
                printf("%s\t",subname[i]);
            }
            printf("总分\t平均分");
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
        else if(choice==2)//学号排序
        {
            printf("按学号排序结果为:\n");
            sort2(p,student);
            printf("姓名\t学号\t性别\t");
            for(i=0; i<subjects; i++)
            {
                printf("%s\t",subname[i]);
            }
            printf("总分\t平均分");
            printf("\n");//输出表头到控制台
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
        else if(choice==3)//姓名排序
        {
            printf("按姓名排序结果为:\n");
            sort3(p,student);
            printf("姓名\t学号\t性别\t");
            for(i=0; i<subjects; i++)
            {
                printf("%s\t",subname[i]);
            }
            printf("总分\t平均分");
            printf("\n");//输出表头到控制台
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
        else if(choice==4)//输入学号进行修改
        {
            printf("请输入要修改的学生的学号:");
            scanf("%d",&edit_number);
            for(i=0; i<student_AfterMinus; i++)
                {
                    if(edit_number==stu[i].stu_number)
                    {
                        printf("该名同学的成绩信息如下:\n");
                        printf("姓名\t学号\t性别\t");
                        for(j=0; j<subjects; j++)
                        {
                            printf("%s\t",subname[i]);
                        }
                        printf("总分\t平均分");
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
            printf("您确定要修改该学生的成绩？(修改请输入1，删除请输入2，否请输入其他数字):");
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
                            printf("请输入第%s同学的%s成绩：",stu[i].name,subname[j]);
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
        else if(choice==5)//查询
        {
            choice=Menu3();
            if(choice==1)
            {
                printf("请输入要查找的学生学号:");
                scanf("%d",&edit_number);
                for(i=0; i<student_AfterMinus; i++)
                {
                    if(edit_number==stu[i].stu_number)
                    {
                        printf("该名同学的成绩信息如下:\n");
                        printf("姓名\t学号\t性别\t");
                        for(j=0; j<subjects; j++)
                        {
                            printf("%s\t",subname[i]);
                        }
                        printf("总分\t平均分");
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
                printf("请输入要查找的学生姓名:");
                scanf("%s",name_temp);
                for(i=0; i<student_AfterMinus; i++)
                {
                    if(strcmp(name_temp,stu[i].name)==0)
                    {
                        printf("该名同学的成绩信息如下:\n");
                        printf("姓名\t学号\t性别\t");
                        for(j=0; j<subjects; j++)
                        {
                            printf("%s\t",subname[i]);
                        }
                        printf("总分\t平均分");
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
        else if(choice==6)//课程数据统计
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
            printf("课程信息统计如下:\n");
            for(i=0; i<subjects; i++)
            {
                printf("\t%s\t",subname[i]);
            }
            printf("\n");
            printf("优");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][0],((float)qualify[i][0]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("良");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][1],((float)qualify[i][1]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("中");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][2],((float)qualify[i][2]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("及格");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][3],((float)qualify[i][3]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("不及格");
            for(i=0; i<subjects; i++)
            {
                printf("\t%d(%4.2f%%)",qualify[i][4],((float)qualify[i][4]/student_AfterMinus)*100);
            }
            printf("\n");
            printf("总分");
            for(i=0; i<subjects; i++)
            {
                printf("\t%5.2f\t",sub_sum[i]);
            }
            printf("\n");
            printf("平均分");
            for(i=0; i<subjects; i++)
            {
                printf("\t%5.2f\t",sub_sum[i]/student_AfterMinus);
            }
            printf("\n");
        }
        else if(choice==7)//保存到文件
        {
            FILE * fp;
            char filename[20];
            printf("请输入要输出的文件名:");
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
        else if(choice==8)//退出系统
        {
            break;
        }
        else//指令输入错误时的提示
            printf("您输入有误，请重新输入！\n");
    }
}
/******************************处理函数结束**************************************/

/******************************数据输入函数**************************************/
void Input ()//数据读入
{
    int i,j;//循环控制变量
    int student;//保存各班学生总人数
    int student_AfterMinus;
    int subjects;//保存科目总数
    char subname[8][10];//保存科目名称

    printf("请输入班级学生总人数：");
    scanf("%d",&student);
    student_AfterMinus = student - flag;
    printf("请输入科目总数：");
    scanf("%d",&subjects);

    for(i=0; i<subjects; i++)
    {
        printf("请输入第%d门科目名称：",i+1);
        scanf("%s",subname[i]);
    }

    for(i=0; i<student_AfterMinus; i++)
    {
        printf("请输入第%d名学生的姓名：",i+1);
        scanf("%s",stu[i].name);
        printf("请输入第%d名同学的学号：",i+1);
        scanf("%d",&stu[i].stu_number);
        printf("请输入第%d名同学的性别：",i+1);
        scanf("%s",stu[i].sex);
        stu[i].sum=0;
        for(j=0; j<subjects; j++)
        {
            printf("请输入%s同学的%s成绩：",stu[i].name,subname[j]);
            scanf("%d",&stu[i].score[j]);
            stu[i].sum += stu[i].score[j];
        }
        stu[i].average = stu[i].sum/subjects;
    }

    Process(student,subjects,subname);


}
/********************************函数结束****************************************/

/******************************登陆密码函数**************************************/
int passWord()//密码输入
{
    int i,count;
    printf("请输入密码:(密码为student)\n");
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
            else printf("密码错误\n");
        }
        break;
    }
    return count;
}
/********************************函数结束****************************************/

/**********************选择函数（选择输入函数读取数据）*************************/
void Choice()//选择读取还是输入
{
    int choice;//用来选择输入还是读取的变量
    int student;
    int subjects;
    char subname[8][10];
    int i;
    FILE * fp;
    while(1)
    {
        choice = Menu1();
        if(choice==2)//输入
        {
            Input();
            break;
        }
        else if(choice==1)//读取
        {
            char filename[20];
            while(1)
            {
                printf("请输入要读入的文件名:");
                scanf("%s",filename);
                if((fp = fopen(filename,"rb"))==NULL)
                {
                    printf("没有此文件，请重新输入!\n");
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
            printf("您输入有误，请重新输入！\n");
        }
    }
}
/********************************函数结束****************************************/


/*********************************主函数*****************************************/
int main()
{
    int error;
    error = passWord();
    if(error!=3)
        Choice();
    else
        printf("连续三次密码错误，程序退出!!!");
    return 0;
}
