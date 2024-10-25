#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false; // Not a leap year if not divisible by 4.
    } else if (year % 100 != 0) {
        return true; // Leap year if divisible by 4 but not by 100.
    } else if (year % 400 == 0) {
        return true; // Leap year if divisible by 100 and 400.
    }
    return false; // Not a leap year if divisible by 100 but not by 400.
}

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    // Array to hold the number of days in each month
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February for leap years
    if (is_leap_year(*yy)) {
        days_in_month[1] = 29; // February has 29 days in a leap year
    }

    // Variable to track the days left in the current month
    int days_left_in_month = days_in_month[*mm - 1] - *dd;

    // Loop to add days
    while (days_left_to_add > 0) {
        if (days_left_to_add > days_left_in_month) {
            // Move to the next month
            days_left_to_add -= (days_left_in_month + 1); // Update days left to add
            *dd = 1; // Reset day to the first of the next month
            (*mm)++; // Move to the next month

            // Check if we need to move to the next year
            if (*mm > 12) {
                *mm = 1; // Reset to January
                (*yy)++; // Move to the next year
            }

            // Update days left in the current month for the new month
            days_left_in_month = days_in_month[*mm - 1] - *dd;
            // Adjust for leap year if applicable
            if (is_leap_year(*yy) && *mm == 2) {
                days_left_in_month++; // February in a leap year
            }
        } else {
            // Just add the remaining days
            *dd += days_left_to_add; // Add remaining days
            days_left_to_add = 0; // All days added
        }
    }
}

int main() {
    // Commenting out previous code
    // int year, month, day, days_to_add;

    // New variable declarations
    int mm, dd, yy, days_left_to_add;

    // Prompt the user for input
    printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date: ");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);

    // Validate the input range
    if (yy < 1800 || yy > 10000) {
        printf("Error: The year must be between 1800 and 10000.\n");
        return 1; // Exit with an error code.
    }

    // Validate month and day inputs
    if (mm < 1 || mm > 12 || dd < 1 || dd > 31) {
        printf("Error: Invalid month or day.\n");
        return 1; // Exit with an error code.
    }

    // Add days to the date
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    
    printf("New date: %02d/%02d/%d\n", mm, dd, yy);

    // Check if the new year is a leap year
    if (is_leap_year(yy)) {
        printf("%d is a leap year.\n", yy);
    } else {
        printf("%d is not a leap year.\n", yy);
    }

    return 0;
}
