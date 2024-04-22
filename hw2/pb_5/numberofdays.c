#include <assert.h>
#include <stdio.h>

// Function used to determine whether input year is a leap year. Returns 1 for leap year, 0 for standard year.
int isleapyear(int year) {
    
    // Following Leap Year logic found on Mathisfun page
    
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}

int numberofdays(int year, int month, int *days) {
    
    // Checking for each month and modifying the days variable to match the according days.
	if (year < 1582) {
		return -1;
	}

    if (month == 1) {
        *days = 31;
    }
    
    // Using the isleapyear function to choose between 28 or 29 days in February.
    if (month == 2 && isleapyear(year) == 1) {
        *days = 29;
    }
    
    if (month == 2 && isleapyear(year) == 0) {
        *days = 28;
    }
    
    if (month == 3) {
        *days = 31;
    }
    
    if (month == 4) {
        *days = 30;
    }
    
    if (month == 5) {
        *days = 31;
    }
    
    if (month == 6) {
        *days = 30;
    }
    
    if (month == 7) {
        *days = 31;
    }
    
    if (month == 8) {
        *days = 31;
    }
    
    if (month == 9) {
        *days = 30;
    }
    
    if (month == 10) {
        *days = 31;
    }
    
    if (month == 11) {
        *days = 30;
    }
    
    if (month == 12) {
        *days = 31;
    }
    
    // Error Checking if days was not changed
    if (*days == 0) {
        return -1;
    }
    
    return 0;
}

int main() {
    int days = 0;
    
    int fnreturn = 0;
    
    //Test Cases for February
    
    //---------------------------------------------------------
    fnreturn = numberofdays(1582, 2, &days);
    printf("Input: year: 1582, month: 2, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 28);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(2000, 2, &days);
    printf("Input: year: 2000, month: 2, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 29);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(2023, 2, &days);
    printf("Input: year: 2023, month: 2, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 28);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(2024, 2, &days);
    printf("Input: year: 2024, month: 2, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 29);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(2100, 2, &days);
    printf("Input: year: 2100, month: 2, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 28);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(3000, 2, &days);
    printf("Input: year: 3000, month: 2, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 28);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(10000, 2, &days);
    printf("Input: year: 10000, month: 2, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 29);
    assert(fnreturn == 0);
    days = 0;
    //----------------------------------------------------------
    
    // Test Cases for 2023
    
    //----------------------------------------------------------
    fnreturn = numberofdays(2023, 1, &days);
    printf("Input: year: 2023, month: 1, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 31);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(2023, 4, &days);
    printf("Input: year: 2023, month: 4, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 30);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(2023, 8, &days);
    printf("Input: year: 2023, month: 8, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 31);
    assert(fnreturn == 0);
    days = 0;
    
    fnreturn = numberofdays(2023, 9, &days);
    printf("Input: year: 2023, month: 9, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 30);
    assert(fnreturn == 0);
    days = 0;
    //----------------------------------------------------------
    
    // Edge Case Tests
    
    //----------------------------------------------------------
    fnreturn = numberofdays(1518, 2, &days);
    printf("Input: year: 1518, month: 2, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 0);
    assert(fnreturn == -1);
    days = 0;
    
    fnreturn = numberofdays(2023, 0, &days);
    printf("Input: year: 2023, month: 0, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 0);
    assert(fnreturn == -1);
    days = 0;
    
    fnreturn = numberofdays(-2023, 12, &days);
    printf("Input: year: -2023, month: 12, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 0);
    assert(fnreturn == -1);
    days = 0;
    
    fnreturn = numberofdays(2023, -12, &days);
    printf("Input: year: 2023, month: -12, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 0);
    assert(fnreturn == -1);
    days = 0;
    
    fnreturn = numberofdays(2023, 13, &days);
    printf("Input: year: 2023, month: 13, Output: %d Function Return: %d\n", days, fnreturn);
    assert(days == 0);
    assert(fnreturn == -1);
    days = 0;
    //----------------------------------------------------------
    
}
