#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>

int main()
{
    int xc, yc, r, x, y, p, gd = DETECT, gm;

    initgraph(&gd, &gm, "..\\bgi");

    printf("Midpoint Circle Drawing Algorithm\n");
    printf("This Program is coded by Sujan Pandey\n");

    printf("Enter the center of the circle (xc, yc): ");
    scanf("%d%d", &xc, &yc);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    x = 0;
    y = r;

    p = 1 - r;

    putpixel(xc + x, yc + y, 5);
    putpixel(xc - x, yc + y, 5);
    putpixel(xc + x, yc - y, 5);
    putpixel(xc - x, yc - y, 5);
    putpixel(xc + y, yc + x, 5);
    putpixel(xc - y, yc + x, 5);
    putpixel(xc + y, yc - x, 5);
    putpixel(xc - y, yc - x, 5);

    while (x < y) {
        x++;

        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }

        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        delay(100); 
    }

    getch();
    closegraph();

}
