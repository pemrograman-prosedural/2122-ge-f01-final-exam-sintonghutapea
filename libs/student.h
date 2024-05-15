#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */

struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
    int left;
};

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender);
void print_student(struct student_t mahasiswa[], int count);
void print_student_detail(struct student_t mahasiswa[], int count);
void assign_student(struct student_t *mahasiswa, struct dorm_t *dormitories, int student_count, int dormitories_count, char *id, char *dorm_name);
void move_student(struct student_t *mahasiswa, struct dorm_t *dormitories, struct dorm_t *old_dorm, char *id, char *dorm_name);
void leave_student(struct student_t *mahasiswa, int student_count, char *id);
#endif
