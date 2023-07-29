#include "StDb.h"




SStudent* GPfirstStudent=NULL;


void fill_record(SStudent*PNewStudent)
{

char text[40];
int id;

printf("Enter the id: ");
scanf_s("%d", &id, sizeof(id));
PNewStudent->Student.id = id;

printf("Enter the Name: ");
getchar(); // consume the newline character left by scanf_s
fgets(PNewStudent->Student.Name, sizeof(PNewStudent->Student.Name), stdin);
PNewStudent->Student.Name[strcspn(PNewStudent->Student.Name, "\n")] = '\0'; // remove the trailing newline character

printf("Enter the Height: ");
fgets(text, sizeof(text), stdin);
PNewStudent->Student.height = atof(text);


}


void add_Student() {
	SStudent* PLastStudent;
	SStudent* PNewStudent;

	if (GPfirstStudent == NULL) {
		// create first student
		PNewStudent = (SStudent*)malloc(sizeof(SStudent));

		// assign the new one
		GPfirstStudent = PNewStudent;
	}
	else { // we already have records
		// to make it start from the first until the null
		PLastStudent = GPfirstStudent;

		// while the last is not pointing at null keep looping
		while (PLastStudent->PNextStudent != NULL) {
			// then address Plast to the last address
			PLastStudent = PLastStudent->PNextStudent;
		}

		// create the space for the new student
		PNewStudent = (SStudent*) malloc(sizeof(SStudent));

		// address new to the next
		PLastStudent->PNextStudent = PNewStudent;
	}

	// fill new record
	fill_record(&PNewStudent->Student);

	// address the next student to null
	PNewStudent->PNextStudent = NULL;
}

void delete_Student() {
	char text[40];
	int selected_id;

	printf("Enter the id to be deleted: ");
	scanf_s("%d", &selected_id, sizeof(selected_id));

	if (GPfirstStudent) { // it has records
		SStudent* PpreviousStudent = NULL;
		SStudent* PTargetStudent = GPfirstStudent;

		while (PTargetStudent) {
			if (PTargetStudent->Student.id == selected_id) {
				if (PpreviousStudent) {
					PpreviousStudent->PNextStudent = PTargetStudent->PNextStudent;
				}
				else {
					GPfirstStudent = PTargetStudent->PNextStudent;
				}
				free(PTargetStudent);
				return;
			}
			PpreviousStudent = PTargetStudent;
			PTargetStudent = PTargetStudent->PNextStudent;
		}
		printf("Cannot find that id");
	}
}

void view_Students() {
	int count = 0;
	int selected_id;

	
	SStudent* Pview = GPfirstStudent;
	if (GPfirstStudent == NULL) 
		printf("empty");

		while (Pview) {
			
				printf("\n The student number in the list is: %d\n", count + 1);
				printf("\n The student id: %d\n", Pview->Student.id);
				printf("\n The student Name: %s\n", Pview->Student.Name);
				printf("\n The student height: %f\n", Pview->Student.height);
			
				Pview = Pview->PNextStudent;
			count++;
		}
	
}


void deleteAll_Students() {
    SStudent* PCurrentStudent = GPfirstStudent;

    if (GPfirstStudent == NULL) {
        printf("NO STUDENTS RECORDS\n");
        return;
    }

    while (PCurrentStudent != NULL) {
        SStudent* Ptemp = PCurrentStudent;
		PCurrentStudent = PCurrentStudent->PNextStudent;
        free(Ptemp);
		printf("all deleted succefully");
    }
    GPfirstStudent = NULL;
}

void GetNth()
{
	SStudent* PGET = GPfirstStudent;
	int number, count = 1;
	if (GPfirstStudent == NULL)
		{
			printf("no list avaliable");
			return 0;
		}
	printf("enter the node index you want: \n");
	scanf_s("%d", &number);

	while(PGET !=NULL)
	{
		if (number == count) {
			printf("the index :%d", number );
			printf("\n The student id: %d\n", PGET->Student.id);
			printf("\n The student Name: %s\n", PGET->Student.Name);
			printf("\n The student height: %f\n", PGET->Student.height);
			return;
		}
		
		count++;
		PGET = PGET->PNextStudent;

	}

	printf("not found");

}

void GetNthFromEnd()
{
	SStudent* pGet = GPfirstStudent;
	int number, count = 0;
	if (GPfirstStudent == NULL)
	{
		printf("No list available\n");
		return;
	}
	printf("Enter the node index from the end you want: \n");
	scanf_s("%d", &number);

	// Find the length of the list
	int length = 0;
	while (pGet != NULL)
	{
		length++;
		pGet = pGet->PNextStudent;
	}

	// Check if the index is within range
	if (number <= 0 || number > length)
	{
		printf("Invalid index\n");
		return;
	}

	// Traverse to the node from the end
	int targetIndex = length - number;
	pGet = GPfirstStudent;
	count = 1;
	while (count <= targetIndex)
	{
		pGet = pGet->PNextStudent;
		count++;
	}

	printf("The index: %d\n", number);
	printf("The student id: %d\n", pGet->Student.id);
	printf("The student Name: %s\n", pGet->Student.Name);
	printf("The student height: %f\n", pGet->Student.height);
	
}

void DetectLoop()
{
	SStudent* pSlow = GPfirstStudent;
	SStudent* pFast = GPfirstStudent;

	while (pFast != NULL && pFast->PNextStudent != NULL)
	{
		pSlow = pSlow->PNextStudent;

		pFast = pFast->PNextStudent;
		pFast = pFast->PNextStudent;
		
		if (pSlow == pFast)
		{
			printf("Loop detected in the linked list\n");
			return 1;
		}
	}

	printf("No loop detected in the linked list\n");
	return 0;
}