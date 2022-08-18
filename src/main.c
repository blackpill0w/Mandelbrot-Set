#include <stdio.h>
#include <math.h>
#include <complex.h>

int mandelbrot(double complex c);

const int     MANDERLBROT_CONST = 5;
const int     MAX_ITER = 255;
const char*   COLOR_PALETTE[] = { // RGB
	 "255 255 255",
	 "0 0 0",
	 "100 0 255",
	 "60 60 60",
	 "90 90 90",
	 "130 130 130",
	 "180 180 180",
};

enum { BG = 0, BODY, L1, L2, L3, L4, L5 };

int main() {
   const unsigned int imgWidth = 900;
   const unsigned int imgHeight = 600;

   FILE *fp = fopen("img.ppm", "w");
   fprintf(fp, "P3\n"); // RGB colors
   fprintf(fp, "%d %d\n", imgWidth, imgHeight);
   fprintf(fp, "255\n\n"); // Max value for colors

	for (double y=0; y < imgHeight; ++y) {
		for (double x=0; x < imgWidth; ++x) {
         double a = -2.5 + (x / imgWidth) * (1. - -2.5);
         double b = -1.2 + (y / imgHeight) * (1.6 - -1.2);
			double complex c = a + b*I;
         int iter = mandelbrot( c );

         if (iter == MAX_ITER) {
				fprintf(fp, "%s\n", COLOR_PALETTE[BODY]); // The bog circles in the middle
         }
			else if (iter > 20) {
				fprintf(fp, "%s\n", COLOR_PALETTE[L1]); // The layer surrounding the body
			}
			else if (iter > 10) {
				fprintf(fp, "%s\n", COLOR_PALETTE[L2]); // The layer surrounding the previous layer,
				                                             // and the same for other layers
			}
			else if (iter == 7) {
				fprintf(fp, "%s\n", COLOR_PALETTE[L3]);
			}
			else if (iter == 6) {
				fprintf(fp, "%s\n", COLOR_PALETTE[L4]);
			}
			else if (iter > 5) {
				fprintf(fp, "%s\n", COLOR_PALETTE[L5]);
			}
         else {
				fprintf(fp, "%s\n", COLOR_PALETTE[BG]);
         }
      }
   }
	fclose(fp);
}

int mandelbrot(double complex c) {
   double complex z = 0;
   int i = 0;
   while (cabs(z) <= MANDERLBROT_CONST && ++i < MAX_ITER) {
      z = z*z + c;
   }
   return i;
}
