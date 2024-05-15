#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "student.h"

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender){
    struct student_t siswa;
    strcpy(siswa.id, _id);
    strcpy(siswa.name, _name);
    strcpy(siswa.year, _year);
    siswa.gender = _gender;
    siswa.dorm = NULL; 
    siswa.left = 0; 
    return siswa;
}

void print_student(struct student_t students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].id[0] != '\0')
        {
            if (students[i].gender == GENDER_MALE)
                printf("%s|%s|%s|male\n", students[i].id, students[i].name, students[i].year);
            else
                printf("%s|%s|%s|female\n", students[i].id, students[i].name, students[i].year);
        }
    }
}

void print_student_detail(struct student_t students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].left)
        {
            if (students[i].gender == GENDER_MALE)
                printf("%s|%s|%s|male|left\n", students[i].id, students[i].name, students[i].year);
            else
                printf("%s|%s|%s|female|left\n", students[i].id, students[i].name, students[i].year);
        }
        else if (students[i].dorm == NULL)
        {
            if (students[i].gender == GENDER_MALE)
                printf("%s|%s|%s|male|unassigned\n", students[i].id, students[i].name, students[i].year);
            else
                printf("%s|%s|%s|female|unassigned\n", students[i].id, students[i].name, students[i].year);
        }
        else
        {
            if (students[i].gender == GENDER_MALE)
                printf("%s|%s|%s|male|%s\n", students[i].id, students[i].name, students[i].year, students[i].dorm->name);
            else
                printf("%s|%s|%s|female|%s\n", students[i].id, students[i].name, students[i].year, students[i].dorm->name);
        }
    }
}

void assign_student(struct student_t *mahasiswa, struct dorm_t *dormitories, int student_count, int dormitory_count, char *id, char *dorm_name)
{
    dorm_name[strcspn(dorm_name, "\n")] = 0;
    for (int i = 0; i < student_count; i++)
    {
        if (strcmp(mahasiswa[i].id, id) == 0)
        {
            for (int j = 0; j < dormitory_count; j++)
            {
                if (strcmp(dormitories[j].name, dorm_name) == 0)
                {
                    if (mahasiswa[i].gender == dormitories[j].gender && dormitories[j].residents_num < dormitories[j].capacity)
                    {
                        mahasiswa[i].dorm = &dormitories[j];
                        dormitories[j].residents_num++;
                        return;
                    }
                }
            }
        }
    }
}

void leave_student(struct student_t *mahasiswa, int student_count, char *id){
    id[strcspn(id, "\n")] = 0;
    for (int i = 0; i < student_count ; i++)
    {
        if(strcmp(mahasiswa[i].id, id) == 0)
        {   
            if (mahasiswa[i].dorm != NULL)
            {
                mahasiswa[i].dorm->residents_num--;
                mahasiswa[i].dorm = NULL;
            }
            mahasiswa[i].left = 1;
            return;
        }
    }
}