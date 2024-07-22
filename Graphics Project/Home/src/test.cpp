#include <graphics.h>
#include <math.h>

void drawcar(int x, int y, int color) {
    int fill_color = color; 

    setcolor(color);
    rectangle(x, y, x + 50, y + 25);
    rectangle(x + 12, y + 6, x + 38, y + 20);
    circle(x + 12, y + 30, 5);
    circle(x + 38, y + 30, 5);

   
    setfillstyle(SOLID_FILL, fill_color);

    
    floodfill(x + 1, y + 1, color);
}




void planetMotion(int xrad, int yrad, int midx, int midy, int pos, int x[70], int y[70]) {
    int i, j = 0;
    for (i = 360; i > 0; i = i - 6) {
        x[j] = midx - (xrad * cos((i * 3.14) / 180));
        y[j++] = midy - (yrad * sin((i * 3.14) / 180));
    }
    return;
}

int main() {
    
    int gdriver = DETECT, gmode, err;
    int i = 0,j=0, midx, midy;
    int xrad[9], yrad[9], x[9][70], y[9][70], color[10];
    int pos[9], planet[9], tmp;

   char *a = "PRASIDDHA(KAT078BCT058)";
   char *b = "NEHA(KAT078BCT050)";
   char *c = "SUDIP(KAT078BCT082)";
   char *d = "SUSAN(KAT078BCT090)";
    initgraph(&gdriver, &gmode, NULL);
    err = graphresult();
    if (err != grOk) {
        printf("Graphics Error: %s", grapherrormsg(err));
        return 0;
    }

  
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    
    planet[0] = 8;
    for (i = 1; i < 9; i++) {
        planet[i] = planet[i - 1] + 1;
    }

    
    for (i = 0; i < 9; i++) {
        pos[i] = i * 6;
    }

    
    xrad[0] = 70, yrad[0] = 40;
    for (i = 1; i < 9; i++) {
        xrad[i] = xrad[i - 1] + 38;
        yrad[i] = yrad[i - 1] + 20;
    }

    
    for (i = 0; i < 9; i++) {
        planetMotion(xrad[i], yrad[i], midx, midy, pos[i], x[i], y[i]);
    }

   
    for (i = 0; i < 9; i++) {
        color[i] = i + 1;
    }

    while (!kbhit()) {
        
        setcolor(WHITE);
        for (i = 0; i < 9; i++) {
            setcolor(CYAN);
            ellipse(midx, midy, 0, 360, xrad[i], yrad[i]);
        }

        outtextxy(5, 10, a);  
        outtextxy(5,25,b);
        outtextxy(5,40,c);
        outtextxy(5,55,d);
        outtextxy(midx, midy, "SUN");
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(midx, midy, 30);
        floodfill(midx, midy, YELLOW);

        // Drawing car
        for (i = 0; i < 9; i++) {
            drawcar(x[i][pos[i]], y[i][pos[i]], color[i]);
            
        }

        // Checking for one complete rotation
        for (i = 0; i < 9; i++) {
            if (pos[i] <= 0) {
                pos[i] = 59;
            } else {
                pos[i] = pos[i] - 1;
            }
        }

        
        delay(100);

        
        cleardevice();
    }

   
    closegraph();

    return 0;
}
