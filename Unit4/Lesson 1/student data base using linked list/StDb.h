#ifndef _STDB_H_
#define _STDB_H_


#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "string.h"

struct SDate
{
	int id;
	char Name[40];
	float height;
};

typedef struct
{
	struct SDate Student;
	struct SStudent* PNextStudent;

}SStudent;



void fill_record(SStudent*PNewStudent);
void add_Student();
void delete_Student();
void view_Students();
void deleteAll_Students();
void GetNth();
void GetNthFromEnd();
void DetectLoop();























#endif // !_STDB_H_