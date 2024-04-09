#include <stdio.h>
#include <stdlib.h>
// read filename argument from command line
int main(int argc, char *argv[]) {
    FILE *file;
    char *filename;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    // load mapfile
    

    filename = argv[1];
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    // read each line of the file
    char line[100];
        while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    // the first 2 bytes of line are the height and width of the brick
    int height = line[0];
    int width = line[1];
    // the rest of the line defines the brick net
    // store the brick net in a 2D array of size height +2 x width +2
    char brick[height + 2][width + 2];
    // first and last row are blank
    for (int i = 0; i < width + 2; i++) {
        brick[0][i] = ' ';
        brick[height + 1][i] = ' '; 
    }
    // first and last column are blank
    for (int i = 0; i < height + 2; i++) {
        brick[i][0] = ' ';
        brick[i][width + 1] = ' ';
    }
    // fill in the brick net from the rest of the data in the array line
    // the net pattern is encoded in the line array as follows:
    // the next character is the numer of empty spaces (A=0, B=1, etc. ) then the next character is the value of the colour of the net square
    // empty spaces are represented by colour value 0
    // the net is filled in row by row
    int row = 1;
    int col = 1;
    for (int i = 2; i < height * width * 2 + 2; i += 2) {
        int numSpaces = line[i] - 'A';
        char colour = line[i + 1];
        for (int j = 0; j < numSpaces; j++) {
            brick[row][col] = ' ';
            col++;
            if (col == width + 1) {
                row++;
                col = 1;
            }
        }
        brick[row][col] = colour;
        col++;
        if (col == width + 1) {
            row++;
            col = 1;
        }
    }
    

    

    // print the brick net
    for (int i = 0; i < height + 2; i++) {
        for (int j = 0; j < width + 2; j++) {
            printf("%c", brick[i][j]);
        }
        printf("\n");
    }    

    // print a blank line
    printf("\n");
    }
    // repeat until the end of the file


    fclose(file);
    return 0;
}

