#include <stdio.h>
#include <graphics.h>

int main() {
    int n, i, gd = DETECT, gm;
    float x[10], y[10], shx, shy;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("2D Shearing\n");
    printf("This Program is coded by Sujan Pandey\n");
    printf("Enter the number of vertices of the object: ");
    scanf("%d", &n);
    printf("Enter the coordinates of the object (x y):\n");
    for (i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]);
    }
    printf("Enter the shear factor along X-axis (shx): ");
    scanf("%f", &shx);
    printf("Enter the shear factor along Y-axis (shy): ");
    scanf("%f", &shy);
    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
    printf("\nSheared Coordinates:\n");
    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        float x_new = x[i] + shx * y[i];
        float y_new = y[i] + shy * x[i];
        line(x_new, y_new, x[(i + 1) % n] + shx * y[(i + 1) % n],
             y[(i + 1) % n] + shy * x[(i + 1) % n]);
        printf("Point %d: (%.2f, %.2f)\n", i + 1, x_new, y_new);
    }
    getch();
    closegraph();
}
