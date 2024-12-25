#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>

void plotEllipsePoints(int xc, int yc, int x, int y, int color) {
    putpixel(xc + x, yc + y, color); 
    putpixel(xc - x, yc + y, color); 
    putpixel(xc + x, yc - y, color); 
    putpixel(xc - x, yc - y, color); 
}

int main() {
    int xc, yc, a, b, x, y;
    float p1, p2;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "..\\bgi");

    printf("Midpoint Ellipse Drawing Algorithm\n");
    printf("This Program is coded by Sujan Pandey\n");

    printf("Enter the center of the ellipse (xc, yc): ");
    scanf("%d%d", &xc, &yc);
    printf("Enter the length of semi-major axis (a): ");
    scanf("%d", &a);
    printf("Enter the length of semi-minor axis (b): ");
    scanf("%d", &b);

    x = 0;
    y = b;
    p1 = b * b - a * a * b + (a * a) / 4.0;

    plotEllipsePoints(xc, yc, x, y, WHITE);

    while (2.0 * b * b * x <= 2.0 * a * a * y) {
        x++;
        if (p1 < 0) {
            p1 = p1 + 2 * b * b * x + b * b;
        } else {
            y--;
            p1 = p1 + 2 * b * b * x - 2 * a * a * y + b * b;
        }
        plotEllipsePoints(xc, yc, x, y, WHITE);
        delay(50); 
    }

    p2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y > 0) {
        y--;
        if (p2 > 0) {
            p2 = p2 - 2 * a * a * y + a * a;
        } else {
            x++;
            p2 = p2 + 2 * b * b * x - 2 * a * a * y + a * a;
        }
        plotEllipsePoints(xc, yc, x, y, WHITE);
        delay(50); 
    }

    getch();
    closegraph();
}
