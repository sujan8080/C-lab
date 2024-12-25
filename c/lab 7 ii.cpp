#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int n, i, gd = DETECT, gm;
    float x[10], y[10], angle, rad;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("2D Rotation\n");
    printf("This Program is coded by Sujan Pandey\n");
    printf("Enter the number of vertices of the object: ");
    scanf("%d", &n);

    printf("Enter the coordinates of the object (x y):\n");
    for (i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]);
    }
    printf("Enter the rotation angle in degrees: ");
    scanf("%f", &angle);

    rad = angle * M_PI / 180;

    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    printf("\nRotated Coordinates:\n");
    setcolor(WHITE);
    for (i = 0; i < n; i++) {
        float x_new = x[i] * cos(rad) - y[i] * sin(rad);
        float y_new = x[i] * sin(rad) + y[i] * cos(rad);
        line(x_new, y_new, x[(i + 1) % n] * cos(rad) - y[(i + 1) % n] * sin(rad),
             x[(i + 1) % n] * sin(rad) + y[(i + 1) % n] * cos(rad));
        printf("Point %d: (%.2f, %.2f)\n", i + 1, x_new, y_new);
    }

    getch();
    closegraph();
    return 0;
}
