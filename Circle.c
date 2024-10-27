#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void circle(int radius, char FILL_CHAR);
void drawPreciseCircle(int radius, char FILL_CHAR);
void plotCirclePoints(int cx, int cy, int x, int y, char display[100][100]);
void drawBresenhamCircle(int radius);


int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s radius [fill_character]\n", argv[0]);
        return 1;
    }

    // radius = 24 best result
    int radius = atoi(argv[1]);
    if (radius <= 0) {
        printf("Error: Radius must be a positive number\n");
        return 1;
    }

    char FILL_CHAR = '0';
    if (argc >= 3 && argv[2][0] != '\0') {
        FILL_CHAR = argv[2][0];
    }

    printf("Using algorithm1 [x^2+y^2 = r^2]:\n");
    circle(radius, FILL_CHAR);

    printf("Using algorithm2 [optimised]:\n");
    drawPreciseCircle(radius, FILL_CHAR);

    printf("Using algorithm3 [Bresenham's algorithm]\n");
    drawBresenhamCircle(radius);

    return  0;
}


// x^2 + y^2 = r^2
void circle(int radius, char FILL_CHAR)
{
    float factor = 2.15;
    int x, y;
    for (y = 0; y <= 2 * radius; y++)
    {
        for (x = 0; x <= 2 * radius; x++)
        {
            int dx = x - radius;
            int dy = (int)((y - radius) * factor);
            if (dx * dx + dy * dy <= radius * radius)
                printf("%c", FILL_CHAR);
            else
                printf(" ");
        }
        printf("\n");
    }
}



// floating-point calculations for better accuracy
void drawPreciseCircle(int radius, char FILL_CHAR)
{
    // Aspect ratio correction for terminal characters
    const float aspectRatio = 2.0;

    // a small padding around the circle
    const int padding = 2;
    int size = 2 * (radius + padding);

    // Calculating boundaries for better centering
    float centerX = size / 2.0f;
    float centerY = size / 2.0f;

    // Threshold for circle edge detection
    const float threshold = 0.5;

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            // Calculating distance from center with aspect ratio correction
            float dx = (x - centerX);
            float dy = (y - centerY) * aspectRatio;
            float distance = sqrt(dx * dx + dy * dy);

            // if point lies on or within circle with anti-aliasing
            if (fabs(distance - radius) < threshold)
                printf("*");
            else if (distance < radius)
                printf("%c", FILL_CHAR);
            else
                printf(" ");
        }
        printf("\n");
    }
}


// fn for Plotting initial points
void plotCirclePoints(int cx, int cy, int x, int y, char display[100][100])
{
    display[cy + y][cx + x] = '*';
    display[cy + y][cx - x] = '*';
    display[cy - y][cx + x] = '*';
    display[cy - y][cx - x] = '*';
    display[cy + x][cx + y] = '*';
    display[cy + x][cx - y] = '*';
    display[cy - x][cx + y] = '*';
    display[cy - x][cx - y] = '*';
}

// circle using Bresenham's algorithm
void drawBresenhamCircle(int radius)
{
    radius /= 2;
    int size = 2 * radius + 4;  // padding
    char display[100][100] = {{0}};  // maximum size 100x100

    // Initializing display array with spaces
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            display[i][j] = ' ';

    int centerX = size / 2;
    int centerY = size / 2;

    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    // Drawing the circle
    while (y >= x) {
        plotCirclePoints(centerX, centerY, x, y, display);

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        x++;
    }

    // Filling circle
    for (int i = centerY - radius; i <= centerY + radius; i++)
    {
        int startX = -1, endX = -1;
        for (int j = 0; j < size; j++)
            if (display[i][j] == '*') {
                if (startX == -1) startX = j;
                endX = j;
            }
        if (startX != -1)
            for (int j = startX + 1; j < endX; j++)
                display[i][j] = '@';
    }

    // Printing
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf(" %c", display[i][j]);
        printf("\n");
    }
}
