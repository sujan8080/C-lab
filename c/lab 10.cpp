#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define MAX_POINTS 20

void intersect(int x1, int y1, int x2, int y2, int edge, int xmin, int ymin, int xmax, int ymax, int *ix, int *iy) {
    float m;
    if (x2 != x1)
        m = (float)(y2 - y1) / (x2 - x1);
    else
        m = 0;

    switch (edge) {
        case 0: // Left boundary
            *ix = xmin;
            *iy = y1 + m * (xmin - x1);
            break;
        case 1: // Right boundary
            *ix = xmax;
            *iy = y1 + m * (xmax - x1);
            break;
        case 2: // Bottom boundary
            *iy = ymin;
            *ix = x1 + (ymin - y1) / m;
            break;
        case 3: // Top boundary
            *iy = ymax;
            *ix = x1 + (ymax - y1) / m;
            break;
    }
}

int clipAgainstEdge(int n, int polyX[], int polyY[], int edge, int xmin, int ymin, int xmax, int ymax, int newPolyX[], int newPolyY[]) {
    int i, j = 0;
    int x1, y1, x2, y2, ix, iy;
    for (i = 0; i < n; i++) {
        x1 = polyX[i];
        y1 = polyY[i];
        x2 = polyX[(i + 1) % n];
        y2 = polyY[(i + 1) % n];

        int inside1 = 0, inside2 = 0;

        switch (edge) {
            case 0: inside1 = x1 >= xmin; inside2 = x2 >= xmin; break;
            case 1: inside1 = x1 <= xmax; inside2 = x2 <= xmax; break;
            case 2: inside1 = y1 >= ymin; inside2 = y2 >= ymin; break;
            case 3: inside1 = y1 <= ymax; inside2 = y2 <= ymax; break;
        }

        if (inside1 && inside2) { 
            newPolyX[j] = x2;
            newPolyY[j++] = y2;
        } else if (inside1 && !inside2) { 
            intersect(x1, y1, x2, y2, edge, xmin, ymin, xmax, ymax, &ix, &iy);
            newPolyX[j] = ix;
            newPolyY[j++] = iy;
        } else if (!inside1 && inside2) { 
            intersect(x1, y1, x2, y2, edge, xmin, ymin, xmax, ymax, &ix, &iy);
            newPolyX[j] = ix;
            newPolyY[j++] = iy;
            newPolyX[j] = x2;
            newPolyY[j++] = y2;
        }
    }
    return j;
}

int main() {
    int gd = DETECT, gm;
    int n, polyX[MAX_POINTS], polyY[MAX_POINTS];
    int newPolyX[MAX_POINTS], newPolyY[MAX_POINTS];
    int xmin, ymin, xmax, ymax;

    printf("Sutherland-Hodgeman Polygon Clipping Algorithm\n");
    printf("This Program is coded by Sujan Pandey\n");
    
    printf("Enter the coordinates of the clipping window (xmin ymin xmax ymax):\n");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    printf("Enter the number of vertices in the polygon:\n");
    scanf("%d", &n);
    printf("Enter the coordinates of the polygon vertices (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &polyX[i], &polyY[i]);
    }

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    outtextxy(xmin - 10, ymin - 10, "Clipping Window");

    setcolor(WHITE);
    int points[MAX_POINTS * 2 + 2];
    for (int i = 0; i < n; i++) {
        points[2 * i] = polyX[i];
        points[2 * i + 1] = polyY[i];
    }
    points[2 * n] = polyX[0];
    points[2 * n + 1] = polyY[0];
    drawpoly(n + 1, points);

    for (int edge = 0; edge < 4; edge++) {
        n = clipAgainstEdge(n, polyX, polyY, edge, xmin, ymin, xmax, ymax, newPolyX, newPolyY);
        for (int i = 0; i < n; i++) {
            polyX[i] = newPolyX[i];
            polyY[i] = newPolyY[i];
        }
    }

    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        points[2 * i] = polyX[i];
        points[2 * i + 1] = polyY[i];
    }
    points[2 * n] = polyX[0];
    points[2 * n + 1] = polyY[0];
    drawpoly(n + 1, points);

    outtextxy(10, getmaxy() - 20, "Clipped Polygon (RED) and Original Polygon (YELLOW)");

    getch();
    closegraph();
}
