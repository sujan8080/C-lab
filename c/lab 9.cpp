#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Defining region codes
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin, ymin, xmax, ymax;

int computeCode(int x, int y) {
    int code = 0;
    if (x < xmin) code |= LEFT;  
    if (x > xmax) code |= RIGHT;  
    if (y < ymin) code |= BOTTOM; 
    if (y > ymax) code |= TOP;    
    return code;
}

void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;
            break;
        }
        else if (code1 & code2) {
            break;
        }
        else {
            int code_out, x, y;

            code_out = code1 ? code1 : code2;

            if (code_out & TOP) { 
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code_out & BOTTOM) { 
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code_out & RIGHT) { 
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code_out & LEFT) { 
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        // Draw the clipped line
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Cohen-Sutherland Line Clipping Algorithm\n");
    printf("This Program is coded by Sujan Pandey\n");

    printf("Enter the clipping window (xmin, ymin, xmax, ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    rectangle(xmin, ymin, xmax, ymax);

    printf("Enter the line coordinates (x1, y1, x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    setcolor(WHITE);
    line(x1, y1, x2, y2);

    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
}
