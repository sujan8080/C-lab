#include <graphics.h>
#include <stdio.h>

void reflectAndDraw(int n, int x[], int y[], char axis) {
    int x_ref[100], y_ref[100];

    for (int i = 0; i < n; i++) {
        switch (axis) {
            case 'x': // Reflection across X-axis
                x_ref[i] = x[i];
                y_ref[i] = -y[i];
                break;

            case 'y': // Reflection across Y-axis
                x_ref[i] = -x[i];
                y_ref[i] = y[i];
                break;

            case 'o': // Reflection across Origin
                x_ref[i] = -x[i];
                y_ref[i] = -y[i];
                break;

            default:
                printf("Invalid axis input! Please use 'x', 'y', or 'o'.\n");
                return;
        }
    }
    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        putpixel(320 + x[i], 240 - y[i], WHITE);
    }
    outtextxy(10, 10, "Original: White");

    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        putpixel(320 + x_ref[i], 240 - y_ref[i], WHITE);
    }
    outtextxy(10, 30, "Reflected: Yellow");
    for (int i = 0; i < n - 1; i++) {
        line(320 + x[i], 240 - y[i], 320 + x[i + 1], 240 - y[i + 1]);
        line(320 + x_ref[i], 240 - y_ref[i], 320 + x_ref[i + 1], 240 - y_ref[i + 1]);
    }
    line(320 + x[n - 1], 240 - y[n - 1], 320 + x[0], 240 - y[0]);
    line(320 + x_ref[n - 1], 240 - y_ref[n - 1], 320 + x_ref[0], 240 - y_ref[0]);
}

int main() {
    int gd = DETECT, gm;
    int n, x[100], y[100];
    char axis;
    initgraph(&gd, &gm, NULL);
    setcolor(WHITE);
    line(320, 0, 320, 480); // Y-axis
    line(0, 240, 640, 240); // X-axis

    printf("2D Reflection\n");
    printf("This Program is coded by Sujan Pandey\n");
    printf("Enter the number of vertices of the object: ");
    scanf("%d", &n);
    printf("Enter the coordinates of the vertices (x y):\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }
    printf("Enter the axis of reflection (x for X-axis, y for Y-axis, o for Origin): ");
    scanf(" %c", &axis);
    reflectAndDraw(n, x, y, axis);
    getch();
    closegraph();

}
