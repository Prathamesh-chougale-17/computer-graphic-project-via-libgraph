#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

void customFloodFill(int x, int y, int oldColor, int newColor)
{
  if (getpixel(x, y) == oldColor)
  {
    putpixel(x, y, newColor);
    customFloodFill(x + 1, y, oldColor, newColor);
    customFloodFill(x - 1, y, oldColor, newColor);
    customFloodFill(x, y + 1, oldColor, newColor);
    customFloodFill(x, y - 1, oldColor, newColor);
  }
}

int main()
{
  initwindow(1200, 800);

  // Draw your shapes here ...
  line(0, 180, 1200, 180);
  line(0, 600, 1200, 450);
  rectangle(100, 350, 350, 500);
  line(75, 350, 375, 350);
  line(100, 275, 350, 275);
  line(75, 350, 100, 275);
  line(375, 350, 350, 275);
  rectangle(200, 410, 250, 500);
  circle(150, 400, 25);
  circle(300, 400, 25);

  int x = 400;
  float a = 0.8;
  // 2nd house
  rectangle((100 + x) * a, 350 * a, (350 + x) * a, 500 * a);
  line((75 + x) * a, 350 * a, (375 + x) * a, 350 * a);
  line((100 + x) * a, 275 * a, (350 + x) * a, 275 * a);
  line((75 + x) * a, 350 * a, (100 + x) * a, 275 * a);
  line((375 + x) * a, 350 * a, (350 + x) * a, 275 * a);
  rectangle((200 + x) * a, 410 * a, (250 + x) * a, 500 * a);

  int x1 = 1330;
  float a1 = 0.7;
  // 3rd house
  rectangle((100 + x1) * a1, 350 * a1, (350 + x1) * a1, 500 * a1);
  line((75 + x1) * a1, 350 * a1, (375 + x1) * a1, 350 * a1);
  line((100 + x1) * a1, 275 * a1, (350 + x1) * a1, 275 * a1);
  line((75 + x1) * a1, 350 * a1, (100 + x1) * a1, 275 * a1);
  line((375 + x1) * a1, 350 * a1, (350 + x1) * a1, 275 * a1);
  rectangle((200 + x1) * a1, 410 * a1, (250 + x1) * a1, 500 * a1);

  // Trees
  line(700, 350, 780, 350);
  line(700, 350, 740, 300);
  line(740, 300, 780, 350);
  line(700, 380, 780, 380);
  line(700, 380, 740, 330);
  line(740, 330, 780, 380);
  rectangle(735, 380, 745, 430);

  line(800, 400 - 60, 860, 400 - 60);
  line(800, 400 - 60, 830, 300 - 60);
  line(830, 300 - 60, 860, 400 - 60);
  rectangle(825, 340, 835, 400);

  // Clouds
  circle(300, 80, 65);
  circle(230, 90, 45);
  circle(380, 85, 45);
  circle(900, 80, 55);
  circle(980, 85, 35);

  // Sun
  circle(100, 80, 70);

  // Boat
  line(950, 625, 1100, 625);
  line(870, 575, 1150, 575);
  line(950, 625, 900, 575);
  line(1100, 625, 1150, 575);
  line(870, 575, 1000, 500);
  line(1000, 500, 1000, 575);
  line(1050, 500, 1050, 575);
  // sky

  // Fill shapes using custom flood fill
  customFloodFill(100, 11, BLACK, YELLOW);
  customFloodFill(0, 0, WHITE, LIGHTBLUE);
  /*  customFloodFill(225, 425, BLACK, LIGHTGRAY); // 1st house
    customFloodFill(225, 450, BLACK, BROWN);     // 1st house door
    customFloodFill(175, 400, BLACK, CYAN);      // 1st house windows
    customFloodFill(325, 400, BLACK, CYAN);

    customFloodFill((225 + x * a), (425 * a), BLACK, LIGHTGRAY); // 2nd house
    customFloodFill((225 + x * a), (450 * a), BLACK, BROWN);     // 2nd house door

    customFloodFill((225 + x1 * a1), (425 * a1), BLACK, LIGHTGRAY); // 3rd house
    customFloodFill((225 + x1 * a1), (450 * a1), BLACK, BROWN);     // 3rd house door*/

  // customFloodFill(770, 365, BLACK, GREEN); // Trees
  // customFloodFill(820, 345, BLACK, GREEN);
  // customFloodFill(800, 380, BLACK, GREEN);
  customFloodFill(850, 340, BLACK, GREEN);
  // customFloodFill(840, 290, BLACK, GREEN);
  // customFloodFill(820, 330, BLACK, GREEN);
  // Fill the tree using custom flood fill
  // Fill the tree shape using custom flood fill
  // Fill the entire tree using custom flood fill
  // customFloodFill(740, 430, BLACK, GREEN); // Start the flood fill from somewhere inside the tree

  customFloodFill(740, 405, BLACK, BROWN);

  // Fill the entire tree using custom flood fill
  customFloodFill(740, 350, BLACK, GREEN); // Start the flood fill from somewhere inside the tree
                                           // You can replace GREEN with the desired color
                                           // Starting point at the base of the trunk

  //    customFloodFill(335, 100, BLACK, LIGHTGRAY); // Clouds
  // customFloodFill(265, 110, BLACK, LIGHTGRAY);
  // customFloodFill(415, 105, BLACK, LIGHTGRAY);
  // customFloodFill(935, 100, BLACK, LIGHTGRAY);
  // customFloodFill(1015, 105, BLACK, LIGHTGRAY);
  setfillstyle(SOLID_FILL, LIGHTCYAN);
  floodfill(0, 0, WHITE); // sky

  customFloodFill(300, 80, BLACK, WHITE);
  customFloodFill(364, 78, BLACK, WHITE);
  customFloodFill(230, 90, BLACK, WHITE);
  customFloodFill(250, 90, BLACK, WHITE);
  customFloodFill(340, 90, BLACK, WHITE);
  customFloodFill(215, 90, BLACK, WHITE);
  customFloodFill(380, 85, BLACK, WHITE);
  customFloodFill(984, 85, BLACK, WHITE);
  customFloodFill(940, 85, BLACK, WHITE);
  customFloodFill(950, 85, BLACK, WHITE);
  customFloodFill(920, 85, BLACK, WHITE);

  setfillstyle(SOLID_FILL, LIGHTGREEN);
  floodfill(467, 441, 15);

  customFloodFill(144, 308, BLACK, BROWN);
  customFloodFill(740, 385, BLACK, BROWN);
  customFloodFill(482, 240, BLACK, BROWN);
  customFloodFill(1167, 213, BLACK, BROWN);
  customFloodFill(135, 426, BLACK, RED);

  customFloodFill(470, 298, BLACK, MAGENTA);
  customFloodFill(1001, 251, BLACK, CYAN);
  customFloodFill(740, 311, BLACK, GREEN);
  customFloodFill(848, 312, BLACK, GREEN);
  customFloodFill(740, 333, BLACK, GREEN);
  customFloodFill(740, 355, BLACK, GREEN);

  // colour
  setfillstyle(SOLID_FILL, BLUE);
  floodfill(1180, 790, WHITE); // WATER

  // boat
  customFloodFill(1025, 620, BLACK, RED);
  customFloodFill(950, 570, BLACK, DARKGRAY);

  delay(3000);

  cleardevice();
  delay(1000);
  // Cliping
  int clipX1 = 150;
  int clipY1 = 150;
  int clipX2 = 800;
  int clipY2 = 800;
  setviewport(clipX1, clipY1, clipX2, clipY2, 1);

  // Draw your shapes here within the clipping window
  line(0, 180, 1200, 180);
  line(0, 600, 1200, 450);
  rectangle(100, 350, 350, 500);
  line(75, 350, 375, 350);
  line(100, 275, 350, 275);
  line(75, 350, 100, 275);
  line(375, 350, 350, 275);
  rectangle(200, 410, 250, 500);
  circle(150, 400, 25);
  circle(300, 400, 25);

  x = 400;
  a = 0.8;
  // 2nd house
  rectangle((100 + x) * a, 350 * a, (350 + x) * a, 500 * a);
  line((75 + x) * a, 350 * a, (375 + x) * a, 350 * a);
  line((100 + x) * a, 275 * a, (350 + x) * a, 275 * a);
  line((75 + x) * a, 350 * a, (100 + x) * a, 275 * a);
  line((375 + x) * a, 350 * a, (350 + x) * a, 275 * a);
  rectangle((200 + x) * a, 410 * a, (250 + x) * a, 500 * a);

  x1 = 1330;
  a1 = 0.7;
  // 3rd house
  rectangle((100 + x1) * a1, 350 * a1, (350 + x1) * a1, 500 * a1);
  line((75 + x1) * a1, 350 * a1, (375 + x1) * a1, 350 * a1);
  line((100 + x1) * a1, 275 * a1, (350 + x1) * a1, 275 * a1);
  line((75 + x1) * a1, 350 * a1, (100 + x1) * a1, 275 * a1);
  line((375 + x1) * a1, 350 * a1, (350 + x1) * a1, 275 * a1);
  rectangle((200 + x1) * a1, 410 * a1, (250 + x1) * a1, 500 * a1);

  // Trees
  line(700, 350, 780, 350);
  line(700, 350, 740, 300);
  line(740, 300, 780, 350);
  line(700, 380, 780, 380);
  line(700, 380, 740, 330);
  line(740, 330, 780, 380);
  rectangle(735, 380, 745, 430);

  line(800, 400 - 60, 860, 400 - 60);
  line(800, 400 - 60, 830, 300 - 60);
  line(830, 300 - 60, 860, 400 - 60);
  rectangle(825, 340, 835, 400);

  // Clouds
  circle(300, 80, 65);
  circle(230, 90, 45);
  circle(380, 85, 45);
  circle(900, 80, 55);
  circle(980, 85, 35);

  // Sun
  circle(100, 80, 70);

  // Boat
  line(950, 625, 1100, 625);
  line(870, 575, 1150, 575);
  line(950, 625, 900, 575);
  line(1100, 625, 1150, 575);
  line(870, 575, 1000, 500);
  line(1000, 500, 1000, 575);
  line(1050, 500, 1050, 575);
  // sky

  // Fill shapes using custom flood fill
  customFloodFill(100, 11, BLACK, YELLOW);
  customFloodFill(0, 0, WHITE, LIGHTBLUE);
  /*  customFloodFill(225, 425, BLACK, LIGHTGRAY); // 1st house
    customFloodFill(225, 450, BLACK, BROWN);     // 1st house door
    customFloodFill(175, 400, BLACK, CYAN);      // 1st house windows
    customFloodFill(325, 400, BLACK, CYAN);

    customFloodFill((225 + x * a), (425 * a), BLACK, LIGHTGRAY); // 2nd house
    customFloodFill((225 + x * a), (450 * a), BLACK, BROWN);     // 2nd house door

    customFloodFill((225 + x1 * a1), (425 * a1), BLACK, LIGHTGRAY); // 3rd house
    customFloodFill((225 + x1 * a1), (450 * a1), BLACK, BROWN);     // 3rd house door*/

  // customFloodFill(770, 365, BLACK, GREEN); // Trees
  // customFloodFill(820, 345, BLACK, GREEN);
  // customFloodFill(800, 380, BLACK, GREEN);
  customFloodFill(850, 340, BLACK, GREEN);
  // customFloodFill(840, 290, BLACK, GREEN);
  // customFloodFill(820, 330, BLACK, GREEN);
  // Fill the tree using custom flood fill
  // Fill the tree shape using custom flood fill
  // Fill the entire tree using custom flood fill
  // customFloodFill(740, 430, BLACK, GREEN); // Start the flood fill from somewhere inside the tree

  customFloodFill(740, 405, BLACK, BROWN);

  // Fill the entire tree using custom flood fill
  customFloodFill(740, 350, BLACK, GREEN); // Start the flood fill from somewhere inside the tree
                                           // You can replace GREEN with the desired color
                                           // Starting point at the base of the trunk

  //    customFloodFill(335, 100, BLACK, LIGHTGRAY); // Clouds
  // customFloodFill(265, 110, BLACK, LIGHTGRAY);
  // customFloodFill(415, 105, BLACK, LIGHTGRAY);
  // customFloodFill(935, 100, BLACK, LIGHTGRAY);
  // customFloodFill(1015, 105, BLACK, LIGHTGRAY);
  setfillstyle(SOLID_FILL, LIGHTCYAN);
  floodfill(0, 0, WHITE); // sky

  customFloodFill(300, 80, BLACK, WHITE);
  customFloodFill(364, 78, BLACK, WHITE);
  customFloodFill(230, 90, BLACK, WHITE);
  customFloodFill(250, 90, BLACK, WHITE);
  customFloodFill(340, 90, BLACK, WHITE);
  customFloodFill(215, 90, BLACK, WHITE);
  customFloodFill(380, 85, BLACK, WHITE);
  customFloodFill(984, 85, BLACK, WHITE);
  customFloodFill(940, 85, BLACK, WHITE);
  customFloodFill(950, 85, BLACK, WHITE);
  customFloodFill(920, 85, BLACK, WHITE);

  setfillstyle(SOLID_FILL, LIGHTGREEN);
  floodfill(467, 441, 15);

  customFloodFill(144, 308, BLACK, BROWN);
  customFloodFill(740, 385, BLACK, BROWN);
  customFloodFill(482, 240, BLACK, BROWN);
  customFloodFill(1167, 213, BLACK, BROWN);
  customFloodFill(135, 426, BLACK, RED);

  customFloodFill(470, 298, BLACK, MAGENTA);
  customFloodFill(1001, 251, BLACK, CYAN);
  customFloodFill(740, 311, BLACK, GREEN);
  customFloodFill(848, 312, BLACK, GREEN);
  customFloodFill(740, 333, BLACK, GREEN);
  customFloodFill(740, 355, BLACK, GREEN);

  // colour
  setfillstyle(SOLID_FILL, BLUE);
  floodfill(1180, 790, WHITE); // WATER

  // boat
  customFloodFill(1025, 620, BLACK, RED);
  customFloodFill(950, 570, BLACK, DARKGRAY);

  getch();
  closegraph();

  return 0;
}