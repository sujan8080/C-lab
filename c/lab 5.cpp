#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Boundary-Fill Function
void boundaryFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, WHITE); // Fill the pixel with the fill color

        // Recursively call for 4-connected directions
        boundaryFill(x + 1, y, fillColor, boundaryColor); // Right
        boundaryFill(x - 1, y, fillColor, boundaryColor); // Left
        boundaryFill(x, y + 1, fillColor, boundaryColor); // Down
        boundaryFill(x, y - 1, fillColor, boundaryColor); // Up
    }
}

int main() {
    int gd = DETECT, gm;
    int x, y, boundaryColor = 15, fillColor = 4;

    // Initialize graphics mode
    initgraph(&gd, &gm, "..\\bgi");

    printf("Boundary-Fill Algorithm\n");
    printf("This Program is coded by Sujan Pandey\n");

    // Draw a closed shape
    rectangle(100, 100, 300, 300);
    printf("Enter a point inside the rectangle to start filling (x, y): ");
    scanf("%d%d", &x, &y);

    // Call the Boundary-Fill Function
    boundaryFill(x, y, fillColor, boundaryColor);

    getch();
    closegraph();
}
