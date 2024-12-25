#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>

int main()
{
    int x, y, x1, y1, x2, y2, dx, dy, p, xinc, yinc, gd = DETECT, gm;

    initgraph(&gd, &gm, "..\\bgi");

    printf("Bresenham's Line Drawing Algorithm\n");
    printf("This Program is coded by Sujan Pandey\n");
    printf("Enter the value of x1 and y1: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the value of x2 and y2: ");
    scanf("%d%d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    xinc = (x2 > x1) ? 1 : -1;
    yinc = (y2 > y1) ? 1 : -1;

    x = x1;
    y = y1;

    if (dx >= dy) {
        // x-driven line
        p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            putpixel(x, y, WHITE);
            x += xinc;
            if (p >= 0) {
                y += yinc;
                p += 2 * dy - 2 * dx;
            } else {
                p += 2 * dy;
            }
            delay(100);
        }
    } else {
        // y-driven line
        p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            putpixel(x, y, WHITE);
            y += yinc;
            if (p >= 0) {
                x += xinc;
                p += 2 * dx - 2 * dy;
            } else {
                p += 2 * dx;
            }
            delay(100);
        }
    }

    getch();
    closegraph();

}
