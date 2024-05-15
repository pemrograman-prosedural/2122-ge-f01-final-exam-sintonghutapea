#include "dorm.h"
#include <string.h>
#include <stdio.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t asrama;
    strcpy(asrama.name, _name);
    asrama.capacity = _capacity;
    asrama.gender = _gender;
    asrama.residents_num = 0;
    return asrama;
}

void print_dorm(struct dorm_t *_dorm, int count){
    char type1[10];
    strcpy(type1, "|male");
    char type2[10];
    strcpy(type2, "|female");
    
    for (int i = 0; i < count; i++)
    {
        if(_dorm[i].name[0]== '\0')
        {
        }
        if (_dorm[i].gender == GENDER_MALE){
            printf("%s|%d%s\n", _dorm[i].name, _dorm[i].capacity, type1);
        }else if(_dorm[i].gender == GENDER_FEMALE){
            printf("%s|%d%s\n", _dorm[i].name, _dorm[i].capacity, type2);
        }
    }
}

void print_dorm_detail(struct dorm_t *_dorm, int count){
    char type1[50];
    strcpy(type1, "male");
    char type2[50];
    strcpy(type2, "female");

    int i= 0;
    while(i < count)
    {
        if (_dorm[i].gender == GENDER_MALE){
            printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity, type1, _dorm[i].residents_num);}
        else if(_dorm[i].gender == GENDER_FEMALE){
            printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity, type2, _dorm[i].residents_num);
            }
        i++;
    }
}
