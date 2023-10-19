#include <iostream>
#define MAX_H 6
#define MAX_W 7

void manipulate(char arr[][MAX_W + 1]) {
    char temp[MAX_H][MAX_W + 1];

    // Copy the original array to a temporary array
    for (int h = 0; h < MAX_H; h++) {
        for (int w = 0; w < MAX_W; w++) {
            temp[h][w] = arr[h][w];
        }
    }

    // Loop through each element in the original array
    for (int h = 0; h < MAX_H; h++) {
        for (int w = 0; w < MAX_W; w++) {
            if (temp[h][w] == 'O') {
                arr[h][w] = 'X'; // Replace 'O' with 'X'
                if (h + 1 < MAX_H)
                    arr[h + 1][w] = 'X';
                if (h - 1 >= 0)
                    arr[h - 1][w] = 'X';
                if (w + 1 < MAX_W)
                    arr[h][w + 1] = 'X';
                if (w - 1 >= 0)
                    arr[h][w - 1] = 'X';
            }
            
           // if(temp[h][w]=='.') arr[h][w] ='O'; 
            //if(temp[h][w]=='X') arr[h][w] ='.'; 
        }
    }
}

void render(char arr[][MAX_W + 1]) {
    // Print the updated array
    for (int h = 0; h < MAX_H; h++) {
        for (int w = 0; w < MAX_W; w++) {
            std::cout << arr[h][w];
        }
        std::cout << std::endl; // Move to the next line after each row
    }
}

int main() {
    char arr[MAX_H][MAX_W + 1] = { // +1 to account for null-terminator
        ".......",
        "...O...",
        "....O..",
        ".......",
        "OO.....",
        "OO....."
    };

    manipulate(arr);
    render(arr);

    return 0;
}
