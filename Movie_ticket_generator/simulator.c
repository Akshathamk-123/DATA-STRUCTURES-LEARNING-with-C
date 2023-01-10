#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Structure to hold movie details
struct Movie {
    char name[MAX_LEN];
    char venue[MAX_LEN];
    int no_of_seats;
    float price;
    char time[MAX_LEN];
    struct Movie *next;
};

// Function to read movie details from a text file
void read_movies_from_file(const char *filename, struct Movie **head) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char name[MAX_LEN], venue[MAX_LEN], time[MAX_LEN];
    int no_of_seats;
    float price;
    struct Movie *current, *new_movie;

    while (fscanf(file, "%s %s %d %f %s", name, venue, &no_of_seats, &price, time) != EOF) {
        new_movie = (struct Movie*) malloc(sizeof(struct Movie));
        strcpy(new_movie->name, name);
        strcpy(new_movie->venue, venue);
        new_movie->no_of_seats = no_of_seats;
        new_movie->price = price;
        strcpy(new_movie->time, time);
        new_movie->next = NULL;

        if (*head == NULL) {
            *head = new_movie;
            current = new_movie;
        } else {
            current->next = new_movie;
            current = new_movie;
        }
    }

    fclose(file);
}

void sort_movies_by_price(struct Movie *head) {
    struct Movie *i, *j, *min;

    for (i = head; i->next != NULL; i = i->next) {
        min = i;

        for (j = i->next; j != NULL; j = j->next) {
            if (j->price < min->price) {
                min = j;
            }
        }

        if (min != i) {
            float temp_price = min->price;
            min->price = i->price;
            i->price = temp_price;

            char temp_name[MAX_LEN], temp_venue[MAX_LEN], temp_time[MAX_LEN];
            int temp_seats;

            strcpy(temp_name, min->name);
            strcpy(temp_venue, min->venue);
            temp_seats = min->no_of_seats;
            strcpy(temp_time, min->time);

            strcpy(min->name, i->name);
            strcpy(min->venue, i->venue);
            min->no_of_seats = i->no_of_seats;
            strcpy(min->time, i->time);

            strcpy(i->name, temp_name);
            strcpy(i->venue, temp_venue);
            i->no_of_seats = temp_seats;
            strcpy(i->time, temp_time);
        }
    }
}

// Function to print the sorted list of movies
void print_sorted_list(struct Movie *head) {
    struct Movie *current;

    for (current = head; current != NULL; current = current->next) {
        printf("Name: %s\n", current->name);
        printf("Venue: %s\n", current->venue);
        printf("Seats: %d\n", current->no_of_seats);
        printf("Price: %.2f\n", current->price);
        printf("Time: %s\n", current->time);
        printf("\n");
    }
}

void generate_ticket(struct Movie *head) {
    char movie_name[MAX_LEN], venue[MAX_LEN];
    int seat_no;

    printf("Enter movie name: ");
    scanf("%s", movie_name);
    printf("Enter venue: ");
    scanf("%s", venue);
    printf("Enter seat number: ");
    scanf("%d", &seat_no);

    struct Movie *current;
    int found = 0;

    for (current = head; current != NULL; current = current->next) {
        if (strcmp(current->name, movie_name) == 0 && strcmp(current->venue, venue) == 0 && seat_no <= current->no_of_seats) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Ticket for %s at %s at seat %d:\n", current->name, current->venue, seat_no);
        printf("Price: $%.2f\n", current->price);
        printf("Time: %s\n", current->time);
    } else {
        printf("Invalid movie or venue or seat number\n");
    }
}

int main() {

    struct Movie *head = NULL;

    read_movies_from_file("movies.txt", &head);
    sort_movies_by_price(head);
    print_sorted_list(head);
    generate_ticket(head);

    return 0;
}
