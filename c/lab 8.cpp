#include <graphics.h>
#include <stdio.h>

void windowToViewportMapping(float wx[], float wy[], int n, float wx_min, float wy_min, float wx_max, float wy_max, 
                             float vx_min, float vy_min, float vx_max, float vy_max) {
    float vx[100], vy[100];
    float sx, sy;

    sx = (vx_max - vx_min) / (wx_max - wx_min);
    sy = (vy_max - vy_min) / (wy_max - wy_min);

    for (int i = 0; i < n; i++) {
        vx[i] = vx_min + (wx[i] - wx_min) * sx;
        vy[i] = vy_min + (wy[i] - wy_min) * sy;
    }
    setcolor(WHITE);
    for (int i = 0; i < n - 1; i++) {
        line(wx[i], wy[i], wx[i + 1], wy[i + 1]);
    }
    line(wx[n - 1], wy[n - 1], wx[0], wy[0]);

    outtextxy(10, 10, "Window (White)");
    setcolor(WHITE);
    for (int i = 0; i < n - 1; i++) {
        line(vx[i], vy[i], vx[i + 1], vy[i + 1]);
    }
    line(vx[n - 1], vy[n - 1], vx[0], vy[0]);

    outtextxy(300, 10, "Viewport (WHITE)");
}

int main() {
    int gd = DETECT, gm;
    float wx_min, wy_min, wx_max, wy_max; // Window coordinates
    float vx_min, vy_min, vx_max, vy_max; // Viewport coordinates
    float wx[100], wy[100];               // Points in the window
    int n;                                // Number of vertices

    initgraph(&gd, &gm, NULL);
    printf("Window-Viewport Mapping\n");
    printf("This Program is coded by Sujan Pandey\n");    
    printf("Enter the minimum and maximum window coordinates (wx_min wy_min wx_max wy_max): ");
    scanf("%f %f %f %f", &wx_min, &wy_min, &wx_max, &wy_max);
    printf("Enter the minimum and maximum viewport coordinates (vx_min vy_min vx_max vy_max): ");
    scanf("%f %f %f %f", &vx_min, &vy_min, &vx_max, &vy_max);
    printf("Enter the number of vertices of the object: ");
    scanf("%d", &n);
    printf("Enter the coordinates of the object in the window (wx wy):\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%f %f", &wx[i], &wy[i]);
    }
    line(320, 0, 320, 480); // Y-axis
    line(0, 240, 640, 240); // X-axis
    windowToViewportMapping(wx, wy, n, wx_min, wy_min, wx_max, wy_max, vx_min, vy_min, vx_max, vy_max);

    getch();
    closegraph();

}
