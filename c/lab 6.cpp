#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void floodFill(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        
        floodFill(x + 1, y, fill_color, boundary_color); // Right
        floodFill(x - 1, y, fill_color, boundary_color); // Left
        floodFill(x, y + 1, fill_color, boundary_color); // Bottom
        floodFill(x, y - 1, fill_color, boundary_color); // Top
    }
}

int main() {
    int gd = DETECT, gm;  
    int x, y, boundary_color, fill_color;

    initgraph(&gd, &gm, "..\\bgi");  

    printf("Flood-Fill Algorithm\n");
    printf("This Program is coded by Sujan Pandey\n");

    rectangle(100, 100, 300, 300);
    boundary_color = 15;  
    fill_color = WHITE;       

    printf("Enter the seed point (x, y): ");
    scanf("%d%d", &x, &y);

    floodFill(x, y, fill_color, boundary_color);

    getch();  
    closegraph();
}
