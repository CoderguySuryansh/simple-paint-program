#include <stdio.h>
#include <conio.h> // For getch() function

#define ROWS 20
#define COLS 40

void printCanvas(char canvas[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char canvas[ROWS][COLS];
    char brush = '*'; // Default drawing character
    int x, y;

    // Initialize the canvas with spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            canvas[i][j] = ' ';
        }
    }

    printf("Simple Paint Program\n");
    printf("Use arrow keys to move the cursor.\n");
    printf("Press 'c' to clear the canvas.\n");
    printf("Press 'q' to quit.\n");

    // Infinite loop for the paint program
    while (1) {
        // Clear the screen before printing the canvas
        system("cls");

        // Print the canvas
        printCanvas(canvas);

        // Get the user input
        char input = getch();

        // Move the cursor based on the arrow keys
        if (input == 0xE0) {
            input = getch();
            switch (input) {
                case 72: // Up arrow
                    y = (y - 1 + ROWS) % ROWS;
                    break;
                case 80: // Down arrow
                    y = (y + 1) % ROWS;
                    break;
                case 75: // Left arrow
                    x = (x - 1 + COLS) % COLS;
                    break;
                case 77: // Right arrow
                    x = (x + 1) % COLS;
                    break;
            }
        } else if (input == 'c') {
            // Clear the canvas
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    canvas[i][j] = ' ';
                }
            }
        } else if (input == 'q') {
            // Quit the program
            break;
        } else {
            // Draw with the brush character
            canvas[y][x] = brush;
        }
    }

    return 0;
}
