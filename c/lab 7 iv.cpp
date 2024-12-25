#include <stdio.h>
#include <graphics.h>

int main() {
    int n, i, gd = DETECT, gm;
    float x[10], y[10], sx, sy;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("2D Scaling\n");
    printf("This Program is coded by Sujan Pandey\n");
    printf("Enter the number of vertices of the object: ");
    scanf("%d", &n);
    printf("Enter the coordinates of the object (x y):\n");
    for (i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]);
    }
    printf("Enter the scaling factor along X-axis (sx): ");
    scanf("%f", &sx);
    printf("Enter the scaling factor along Y-axis (sy): ");
    scanf("%f", &sy);
    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
    printf("\nScaled Coordinates:\n");
    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        float x_new = x[i] * sx;
        float y_new = y[i] * sy;
        line(x_new, y_new, x[(i + 1) % n] * sx, y[(i + 1) % n] * sy);
        printf("Point %d: (%.2f, %.2f)\n", i + 1, x_new, y_new);
    }
    getch();
    closegraph();
}
