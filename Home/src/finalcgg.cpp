#include <stdio.h>
#include <graphics.h>

// flood fill
void flood(int x, int y, int new_col, int old_col)
{

    if (getpixel(x, y) == old_col)
    {

        putpixel(x, y, new_col);

        flood(x + 1, y, new_col, old_col);

        flood(x - 1, y, new_col, old_col);

        flood(x, y + 1, new_col, old_col);

        flood(x, y - 1, new_col, old_col);
    }
}

// Region codes for the Cohen-Sutherland algorithm
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Function to compute the region code for a point (x, y)
int computeRegionCode(int x, int y, int xmin, int ymin, int xmax, int ymax)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

// Function to clip a line using the Cohen-Sutherland algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax)
{
    int code1, code2;
    int accept = 0;
    int done = 0;

    while (!done)
    {
        code1 = computeRegionCode(x1, y1, xmin, ymin, xmax, ymax);
        code2 = computeRegionCode(x2, y2, xmin, ymin, xmax, ymax);

        if ((code1 == 0) && (code2 == 0))
        {
            // Both endpoints are inside the window; accept the line
            accept = 1;
            done = 1;
        }
        else if (code1 & code2)
        {
            // Both endpoints are outside the same region; reject the line
            done = 1;
        }
        else
        {
            // Line partially inside; calculate the intersection point
            int x, y;

            // Pick the endpoint that is outside the window
            int codeOut = code1 ? code1 : code2;

            // Calculate the intersection point
            if (codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1, xmin, ymin, xmax, ymax);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeRegionCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept)
    {

        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // house
    line(200, 200, 400, 200);
    line(400, 200, 400, 400);
    line(200, 200, 200, 400);
    line(200, 400, 400, 400);
    // top cross lines
    line(200, 200, 300, 100);
    line(400, 200, 300, 100);
    circle(300, 160, 25);

    // door border
    line(275, 300, 325, 300);
    line(275, 300, 275, 400);
    line(325, 300, 325, 400);

    // door
    line(275, 300, 320, 310);
    line(275, 400, 320, 390);
    line(320, 310, 320, 390);
    // circle(313,350,4);

    // window
    rectangle(220, 240, 260, 280);
    rectangle(340, 240, 380, 280);

    int x[8] = {300, 300, 210, 240, 360, 310, 310, 313};
    int y[8] = {110, 160, 210, 250, 260, 305, 320, 350};

    int newcolor[8] = {6, 7, 4, 9, 9, 9, 8, 4};

    int oldcolor = 0;

    for (int i = 0; i < 8; i++)
    {
        flood(x[i], y[i], newcolor[i], oldcolor);
    }

    // delay(5000);

    int xmin, ymin, xmax, ymax;
    printf("Enter the clipping window coordinates (xmin ymin xmax ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    rectangle(xmin, ymin, xmax, ymax);

    cleardevice();

    rectangle(xmin, ymin, xmax, ymax);

    cohenSutherlandClip(200, 200, 400, 200, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(400, 200, 400, 400, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(200, 200, 200, 400, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(200, 400, 400, 400, xmin, ymin, xmax, ymax);

    cohenSutherlandClip(200, 200, 300, 100, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(400, 200, 300, 100, xmin, ymin, xmax, ymax);
    circle(300, 160, 25);
    cohenSutherlandClip(275, 300, 325, 300, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(275, 300, 275, 400, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(325, 300, 325, 400, xmin, ymin, xmax, ymax);

    cohenSutherlandClip(275, 300, 320, 310, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(275, 400, 320, 390, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(320, 310, 320, 390, xmin, ymin, xmax, ymax);

    // rectangle
    cohenSutherlandClip(220, 240, 260, 240, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(260, 240, 260, 280, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(220, 280, 260, 280, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(220, 240, 220, 280, xmin, ymin, xmax, ymax);

    cohenSutherlandClip(340, 240, 380, 240, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(380, 240, 380, 280, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(340, 280, 380, 280, xmin, ymin, xmax, ymax);
    cohenSutherlandClip(340, 240, 340, 280, xmin, ymin, xmax, ymax);

    int x1[2] = {300, 300};
    int y1[2] = {110, 160};

    int newcolor1[2] = {6, 7};

    int oldcolor1 = 0;

    for (int i = 0; i < 2; i++)
    {
        flood(x[i], y[i], newcolor1[i], oldcolor1);
    }

    // //house
    // cohenSutherlandClip(300,300,400,300, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(400,300,400,400, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(300,300,300,400, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(300,400,400,400, xmin, ymin, xmax, ymax);

    // cohenSutherlandClip(350,250,450,250, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(450,250,500,300, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(400,300,500,300, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(500,300,500,400, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(400,400,500,400, xmin, ymin, xmax, ymax);

    // //top cross lines
    // cohenSutherlandClip(300,300,350,250, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(400,300,350,250, xmin, ymin, xmax, ymax);

    // //door
    // cohenSutherlandClip(337,350,362,350, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(337,350,337,400, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(362,350,362,400, xmin, ymin, xmax, ymax);

    // //window

    // //rectangle(425,325,475,375);
    // cohenSutherlandClip(425,325,475,325, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(425,325,425,375, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(425,375,475,375, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(475,325,475,375, xmin, ymin, xmax, ymax);

    // //car
    // cohenSutherlandClip(80,300,175,300, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(80,300,80,400, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(80,400,250,400, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(250,350,250,400, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(175,300,212,350, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(212,350,250,350, xmin, ymin, xmax, ymax);

    // //car window
    // cohenSutherlandClip(85,305,135,305, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(85,305,85,350, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(85,350,135,350, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(135,305,135,350, xmin, ymin, xmax, ymax);

    // cohenSutherlandClip(140,305,170,305, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(140,305,140,350, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(140,350,207,350, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(207,350,170,305, xmin, ymin, xmax, ymax);

    // //wheels

    // circle(115,400,20);
    // circle(185,400,20);

    // //sun

    // circle(250,150,25);
    // cohenSutherlandClip(250,115,250,90, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(250,185,250,210, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(190,150,215,150, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(285,150,310,150, xmin, ymin, xmax, ymax);

    // cohenSutherlandClip(285,115,310,90, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(285,185,310,210, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(215,185,190,210, xmin, ymin, xmax, ymax);
    // cohenSutherlandClip(215,115,190,90, xmin, ymin, xmax, ymax);

    delay(500000); // Pause to view the result

    closegraph();

    return 0;
}