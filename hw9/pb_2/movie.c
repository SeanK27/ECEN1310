#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


/**********************************************************************
 * API
 *********************************************************************/

typedef struct _movie {
    char* title;
    int release_year;
    char* lead_actor;
    char* lead_actress;
    int total_ratings;
    float avg_rating;
} movie;

/* Creates a new Movie with the specified title, release_year (in the range 1900-2030), lead actor and lead actress. The total number of ratings and the average audience rating is initialized to zero. Function returns NULL if any of the pointer parameters are NULL or if release_year is not in the correct format/range. */
movie * newMovie(char *title, int release_year, char *lead_actor, char *lead_actress); 


/* Update the total number of ratings and average audience rating based on the parameter "rating" (which is an integer from 1 to 10) for the movie "mov". Returns 0 if successful and -1 for malformed input */
int updateRating(movie *mov, int rating); //user submits rating from 1-10, avg can still be float


/*Returns 1 if mov1 has higher audience rating, 2 is mov2 has higher audience rating and 0 if both have same audience rating. Returns -1 for malformed input.*/
int whichMovieShouldIWatch(movie *mov1, movie *mov2); 


/*Prints out a one line summary of the movie (similar to the first line on the wikipedia page for any movie) that includes all the info contained in the structure. Returns 0 if successful or -1 if input is malformed. */
int printSummary(movie *mov);



/* Deletes the movie pointed to by mov. Returns 0 if successful or -1 if input malformed */
int deleteMovie(movie *mov);



/**********************************************************************
 * Application
 *********************************************************************/

int main(void) {
    movie* mov1 = newMovie("Despicable Me", 2010, "Steve Carrel", "Kristen Wiig");
    movie* mov2 = newMovie("Despicable Me 2", 2013, "Pierre Coffin", "Miranda Cosgrove");

    assert(mov1 != NULL && mov2 != NULL);

    updateRating(mov1, 9);
    updateRating(mov1, 10);
    updateRating(mov2, 8);
    updateRating(mov2, 10);
    updateRating(mov2, 9);

    int choice = whichMovieShouldIWatch(mov1, mov2);
    printf("You should watch: ");
    if (choice == 1) {
        printSummary(mov1);
    } else if (choice == 2) {
        printSummary(mov2);
    } else {
        printf("Both movies have the same rating.\n");
    }

    deleteMovie(mov1);
    deleteMovie(mov2);

    return 0;
}


/**********************************************************************
 * Library implementation
 *********************************************************************/

movie* newMovie(char* title, int release_year, char* lead_actor, char* lead_actress) {
    if (title == NULL || lead_actor == NULL || lead_actress == NULL || release_year < 1900 || release_year > 2030) {
        return NULL;
    }

    movie* mov = (movie*)malloc(sizeof(movie));
    if (mov == NULL) {
        return NULL;
    }

    mov->title = (char*)malloc(strlen(title) + 1);
    strcpy(mov->title, title);

    mov->release_year = release_year;

    mov->lead_actor = (char*)malloc(strlen(lead_actor) + 1);
    strcpy(mov->lead_actor, lead_actor);

    mov->lead_actress = (char*)malloc(strlen(lead_actress) + 1);
    strcpy(mov->lead_actress, lead_actress);

    mov->total_ratings = 0;
    mov->avg_rating = 0.0;

    return mov;
}

int updateRating(movie* mov, int rating) {
    if (mov == NULL || rating < 1 || rating > 10) {
        return -1;
    }

    mov->total_ratings++;
    mov->avg_rating = (mov->avg_rating * (mov->total_ratings - 1) + rating) / mov->total_ratings;

    return 0;
}

int whichMovieShouldIWatch(movie* mov1, movie* mov2) {
    if (mov1 == NULL || mov2 == NULL) {
        return -1;
    }

    if (mov1->avg_rating > mov2->avg_rating) {
        return 1;
    } else if (mov2->avg_rating > mov1->avg_rating) {
        return 2;
    } else {
        return 0;
    }
}

int printSummary(movie* mov) {
    if (mov == NULL) {
        return -1;
    }

    printf("%s (%d) - Lead Actor: %s, Lead Actress: %s, Average Rating: %.2f\n",
           mov->title, mov->release_year, mov->lead_actor, mov->lead_actress, mov->avg_rating);

    return 0;
}

int deleteMovie(movie* mov) {
    if (mov == NULL) {
        return -1;
    }

    free(mov->title);
    free(mov->lead_actor);
    free(mov->lead_actress);
    free(mov);

    return 0;
}