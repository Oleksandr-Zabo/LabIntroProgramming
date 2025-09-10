#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPLICANTS 100
#define MAX_SPECIALTIES 10
#define MAX_NAME_LEN 50

typedef struct {
    char surname[MAX_NAME_LEN];
    char specialty[10];
    int exam[3];
    float avg;
} Applicant;

typedef struct {
    char specialty[10];
    int passing_score;
    int places;
} Specialty;

Applicant applicants[MAX_APPLICANTS];
Specialty specialties[MAX_SPECIALTIES];
int applicant_count = 0, specialty_count = 0;

void read_applicants(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) { printf("File not found\n"); exit(1); }
    while (fscanf(f, "%49[^,],%9[^,],%d,%d,%d\n",
                  applicants[applicant_count].surname,
                  applicants[applicant_count].specialty,
                  &applicants[applicant_count].exam[0],
                  &applicants[applicant_count].exam[1],
                  &applicants[applicant_count].exam[2]) == 5) {
        applicants[applicant_count].avg =
            (applicants[applicant_count].exam[0] +
             applicants[applicant_count].exam[1] +
             applicants[applicant_count].exam[2]) / 3.0f;
        applicant_count++;
    }
    fclose(f);
}

void get_specialty_info() {
    specialty_count = 0;
    for (int i = 0; i < applicant_count; i++) {
        int found = 0;
        for (int j = 0; j < specialty_count; j++) {
            if (strcmp(applicants[i].specialty, specialties[j].specialty) == 0) {
                found = 1;
                break;
            }
        }
        if (!found && specialty_count < MAX_SPECIALTIES) {
            strcpy(specialties[specialty_count].specialty, applicants[i].specialty);
            specialty_count++;
        }
    }
    for (int i = 0; i < specialty_count; i++) {
        printf("Specialty code: %s\n", specialties[i].specialty);
        printf("Passing score: ");
        scanf("%d", &specialties[i].passing_score);
        printf("Number of places: ");
        scanf("%d", &specialties[i].places);
    }
}

void process_and_save(const char *filename) {
    FILE *f = fopen(filename, "w");
    for (int s = 0; s < specialty_count; s++) {
        
        Applicant eligible[MAX_APPLICANTS];
        int count = 0;
        for (int i = 0; i < applicant_count; i++) {
            if (strcmp(applicants[i].specialty, specialties[s].specialty) == 0 &&
                applicants[i].avg >= specialties[s].passing_score) {
                eligible[count++] = applicants[i];
            }
        }
        
        for (int i = 0; i < count - 1; i++)
            for (int j = i + 1; j < count; j++)
                if (eligible[i].avg < eligible[j].avg) {
                    Applicant tmp = eligible[i]; eligible[i] = eligible[j]; eligible[j] = tmp;
                }
        
        fprintf(f, "Specialty: %s\n", specialties[s].specialty);
        for (int i = 0; i < count && i < specialties[s].places; i++)
            fprintf(f, "%s,%s,%.2f\n", eligible[i].surname, eligible[i].specialty, eligible[i].avg);
    }
    fclose(f);
}

int main() {
    read_applicants("input.csv");
    get_specialty_info();
    process_and_save("result.csv");
    printf("Results saved to result.csv\n");
    return 0;
}