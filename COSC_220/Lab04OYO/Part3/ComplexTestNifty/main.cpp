#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Complex.h"

#include "bitmap_image.hpp"

/*
Interesting values of c
c = -0.52 + 0.57i
c = 0.295 + 0.55i
c = -0.624 + 0.435i
c = i
c = -1.25
c = 0.285 + 0.01i 
c = -0.70176 - 0.3842i 
c = -0.835 - 0.2321i 
c = -0.8 + 0.156i 
c = -0.8i 
*/

int main()
{
    int size;
    double cr;
    double ci;
    unsigned int maxiter = 1000;
    double boarderRatio;
    double colorExponent;
    double bailout;
    
    cout << "Input the image size (in pixels): ";
    cin >> size;
    cout << "Input the real value of c: ";
    cin >> cr;
    cout << "Input the imaginary value of c: ";
    cin >> ci;
    cout << "Input the maximum iteration (100-1,000): ";
    cin >> maxiter;
    cout << "Input the boarder ratio (0-1): ";
    cin >> boarderRatio;
    cout << "Input the color exponent (0-1): ";
    cin >> colorExponent;
    cout << "Input the bailout radius (>= 4): ";
    cin >> bailout;
    
    const unsigned int width  = size;
    const unsigned int height = size;

    bitmap_image pic(width, height);
    pic.clear();

    Complex z, c(cr, ci);

    cout << "Creating Image" << endl;
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            double zr = (4.0 * x / width - 2.0);
            double zi = (4.0 * y / height - 2.0);
            z.set(zr, zi);

            unsigned int n = 0;
            while (n < maxiter)
            {
                z = (z ^ 2) + c;
                
                if (z.mod() > bailout)
                {
                    int index = 0;
                                        
                    if (n > maxiter*boarderRatio)
                        index = 255;
                    else if (maxiter != n)
                        index = (int)(pow(1.0 * n / maxiter, colorExponent) * 255);

                    pic.set_pixel(x, y, index, index, index);
                    n = maxiter;
                }
                n++;
            }
        }
    }

    pic.save_image("image.bmp");

    cout << "Done" << endl;
    return 0;
}

