#include "Sierpinski.h"
#include "error.h"
#include <sys/types.h>
using namespace std;

/**
 * Draws a triangle with the specified corners in the specified window. Feel free
 * to edit this function as you see fit to change things like color, fill style,
 * etc. in whatever way you'd like!
 *
 * @param window The window in which to draw the triangle.
 * @param x0 y0 The first corner of the triangle.
 * @param x1 y1 The second corner of the triangle.
 * @param x2 y2 The third corner of the triangle.
 */
void drawTriangle(GWindow& window,
                  double x0, double y0,
                  double x1, double y1,
                  double x2, double y2) {
    window.setColor("black");
    window.fillPolygon({ x0, y0, x1, y1, x2, y2 });
}

/* TODO: Refer to Sierpinski.h for more information about what this function should do.
 * Then, delete this comment.
 */
void drawSierpinskiTriangle(GWindow& window,
                            double x0, double y0,
                            double x1, double y1,
                            double x2, double y2,
                            int order) {
                            if(order==0){
                                                        drawTriangle(window,x0,y0,x1,y1,x2,y2);
                                                        return;
                            }
                            double Ax0=x0,Ay0=y0;
                            double Ax1=(x0+x1)/2,Ay1=y0;
                            double Ax2=(x0+x2)/2,Ay2=(y0+y2)/2;
                            drawSierpinskiTriangle(window,Ax0,Ay0,Ax1,Ay1,Ax2,Ay2,order-1);

                            double Bx0=Ax1,By0=Ay1;
                            double Bx1=x1,By1=y1;
                            double Bx2=(x1+x2)/2,By2=(y1+y2)/2;
                            drawSierpinskiTriangle(window,Bx0,By0,Bx1,By1,Bx2,By2,order-1);
                            
                            double Cx0=Ax2,Cy0=Ay2;
                            double Cx1=Bx2,Cy1=By2;
                            double Cx2=x2,Cy2=y2;
                            drawSierpinskiTriangle(window,Cx0,Cy0,Cx1,Cy1,Cx2,Cy2,order-1);
                            
                            return;
}
