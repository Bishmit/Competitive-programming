#include <iostream>
#include <string>

// Function to convert hours to words
std::string convertHoursToWords(int hours) {
    const std::string hourWords[] = {
        "Midnight", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Noon"
    };

    if (hours >= 0 && hours <= 12) {
        return hourWords[hours];
    }
    return "Invalid Hour";
}

// Function to convert minutes to words
std::string convertMinutesToWords(int minutes) {
    const std::string minuteWords[] = {
        "O'Clock", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Quarter", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
        "Twenty", "Twenty-One", "Twenty-Two", "Twenty-Three", "Twenty-Four", "Twenty-Five", "Twenty-Six", "Twenty-Seven", "Twenty-Eight", "Twenty-Nine",
        "Half"
    };

    if (minutes == 0) {
        return minuteWords[0];
    } else if (minutes == 15 || minutes == 30) {
        return minuteWords[minutes];
    } else if (minutes == 45) {
        return "Quarter to";
    } else if (minutes < 30) {
        if (minutes == 1) {
            return minuteWords[minutes] + " minute past";
        } else {
            return minuteWords[minutes] + " minutes past";
        }
    } else {
        if (minutes == 59) {
            return minuteWords[60 - minutes] + " minute to";
        } else {
            return minuteWords[60 - minutes] + " minutes to";
        }
    }
}

int main() {
    int hours, minutes;
    
    std::cout << "Enter the hour (0-23): ";
    std::cin >> hours;

    if (hours < 0 || hours > 23) {
        std::cout << "Invalid hour input." << std::endl;
        return 1;
    }

    std::cout << "Enter the minute (0-59): ";
    std::cin >> minutes;

    if (minutes < 0 || minutes > 59) {
        std::cout << "Invalid minute input." << std::endl;
        return 1;
    }

    std::string hourWords = convertHoursToWords(hours);
    std::string minuteWords = convertMinutesToWords(minutes);

    if (minutes == 0) {
        std::cout << hourWords << " " << minuteWords << std::endl;
    } else if (minutes <= 30) {
        std::cout << minuteWords << " " << hourWords << std::endl;
    } else {
        std::cout << minuteWords << " " << convertHoursToWords((hours + 1) % 24) << std::endl;
    }

    return 0;
}
