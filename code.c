#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    int id,age;
    char name[25];
    float marks;
};
void addStudent(){
    struct Student s;
    FILE *file=fopen("StudentRec.DAT","ab");
    if(file==NULL){
        printf("Error opening File!\n");
        return;
    }
    printf("Enter Student ID:");
    scanf("%d",&s.id);
    fflush(stdin);
    printf("Enter Student Name:");
    scanf("%[^\n]",s.name);
    printf("Enter Student Age:");
    scanf("%d",&s.age);
    printf("Enter Student Marks:");
    scanf("%f",&s.marks);
    fwrite(&s,sizeof(s),1,file);
    fclose(file);
    printf("Student Record Added Successfully!\n");
}
void displayStudent(){
    struct Student s;
    FILE *file=fopen("StudentRec.DAT","rb");
    if(file==NULL){
        printf("No Records!\n");
        return;
    }
    printf("===Student Records===\n");
    while(fread(&s,sizeof(s),1,file)==1)
        printf("ID:%d\nName:%s\nAge:%d\nMarks:%.2f\n",s.id,s.name,s.age,s.marks);
    fclose(file);
}
void searchStudent(){
    struct Student s;
    FILE *file=fopen("StudentRec.DAT","rb");
    int searchID,found=0;
    printf("Enter Student ID:");
    scanf("%d",&searchID);
    if(file==NULL){
        printf("Error opening File!\n");
        return;
    }
    while(fread(&s,sizeof(s),1,file)==1){
        if(searchID==s.id){
            printf("ID:%d\nName:%s\nAge:%d\nMarks:%f",s.id,s.name,s.age,s.marks);
            found=1;
            break;
        }
    }
    fclose(file);
    if(!found)
    printf("Student Not Found\n!");
}
void updateStudent(){
    struct Student s;
    FILE *file=fopen("StudentRec.DAT","rb");
    FILE *temp=fopen("temp.DAT","wb");
    int searchID,found=0;
    printf("Enter Student ID:");
    scanf("%d",&searchID);
    fflush(stdin);
    if(file==NULL||temp==NULL)
    printf("Error opening File!");
    while(fread(&s,sizeof(s),1,file)==1){
        if(searchID==s.id){
            printf("Enter Student Name:");
            scanf("%[^\n]",s.name);
            printf("Enter Student Age:");
            scanf("%d",&s.age);
            printf("Enter Student Marks:");
            scanf("%f",&s.marks);
            found=1;
        }
        fwrite(&s,sizeof(s),1,temp);
    }
    fclose(file);
    fclose(temp);
    remove("StudentRec.DAT");
    rename("temp.DAT","StudentRec.DAT");
    if(found)
    printf("Student Update Successfully!\n");
    else
    printf("Student Not Found!\n");
}
void deleteStudent(){
    struct Student s;
    FILE *file=fopen("StudentRec.DAT","rb");
    FILE *temp=fopen("temp.DAT","wb");
    int searchID,found=0;
    printf("Enter Student ID:");
    scanf("%d",&searchID);
    fflush(stdin);
    if(file==NULL||temp==NULL)
    printf("Error opening File!");
    while(fread(&s,sizeof(s),1,file)==1){
        if(searchID==s.id){
            found=1;
            continue;
        }
        fwrite(&s,sizeof(s),1,temp);
    }
    fclose(file);
    fclose(temp);
    remove("StudentRec.DAT");
    rename("temp.DAT","StudentRec.DAT");
    if(found)
    printf("Student Deleted Successfully!\n");
    else
    printf("Student Not Found!\n");
}
int main()
{
    int choice;
    do{
          printf("\n=== Student Managment System ====\n");
          printf("1.Add Student\n");
          printf("2.Display Students\n");
          printf("3.Search Students\n");
          printf("4.Update Students\n");
          printf("5.Delete Students\n");
          printf("6.Exit\n");
          printf("Enter your choice:");
          scanf("%d",&choice);
          switch(choice){
            case 1: addStudent();break;
            case 2: displayStudent();break;
            case 3: searchStudent();break;
            case 4: updateStudent();break;
            case 5: deleteStudent();break;
            case 6:printf("Exiting program. Thank you!\n");break;
        
            default: printf("Invaid Choice! Try again.\n");
          }
      } while(choice!= 6);
      return 0;
}