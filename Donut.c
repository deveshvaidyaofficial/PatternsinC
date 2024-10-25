#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
    --------------
    Best Aspect Ratio and Parameters from my experience:
    WIDTH 70
    HEIGHT 40

    float R1 = 10;
    float R2 = 20;
    float K2 = 10;
    float A = 2.0; // a->1.57rad ~ 90deg : 2d view from a side, a->0rad ~ 0deg : top view
    float B = 1.0; //

    // if seen from z azis,
    // a is rotX
    // b is rotY
    // or vice versa
    --------------
    These are set to default, change as you with with flags.
    --------------
*/

#define DEFAULT_WIDTH 70
#define DEFAULT_HEIGHT 40
#define DEFAULT_R1 10.0
#define DEFAULT_R2 20.0
#define DEFAULT_K2 10.0
#define DEFAULT_A 2.0
#define DEFAULT_B 1.0

void drawDonut(int width, int height, float R1, float R2, float K2, float A, float B);

int main(int argc, char* argv[]) {
    // Default parameter values
    int width = DEFAULT_WIDTH;
    int height = DEFAULT_HEIGHT;
    float R1 = DEFAULT_R1;
    float R2 = DEFAULT_R2;
    float K2 = DEFAULT_K2;
    float A = DEFAULT_A;
    float B = DEFAULT_B;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-w") == 0 && i + 1 < argc) {
            // i+1 < argc cuz if the flag exists, its value should also be present at next index
            width = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-h") == 0 && i + 1 < argc) {
            height = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-r1") == 0 && i + 1 < argc) {
            R1 = atof(argv[++i]);
        } else if (strcmp(argv[i], "-r2") == 0 && i + 1 < argc) {
            R2 = atof(argv[++i]);
        } else if (strcmp(argv[i], "-k2") == 0 && i + 1 < argc) {
            K2 = atof(argv[++i]);
        } else if (strcmp(argv[i], "-a") == 0 && i + 1 < argc) {
            A = atof(argv[++i]);
        } else if (strcmp(argv[i], "-b") == 0 && i + 1 < argc) {
            B = atof(argv[++i]);
        } else if (strcmp(argv[i], "--help") == 0) {
            printf("executable_file[.exe /.out /.sh etc] \n\
                -w [width]\n\
                -h [height]\n\
                -r1 [inner radius of donut]\n\
                -r2 [outer radius of donut]\n\
                -k2 [Distance from viewer]\n\
                -a [Angle for 3D perspective]\n\
                -b [Angle]\n\
                --help [for help]\n");
            return 0;
        }
    }

    drawDonut(width, height, R1, R2, K2, A, B);
    return 0;
}

void drawDonut(int width, int height, float R1, float R2, float K2, float A, float B) {
    // Initializing the display buffer
    char display[height][width];
    memset(display, ' ', height * width);

    const char* shades = ".,-~:;=!*#$@";

    for (float theta = 0; theta < 2 * M_PI; theta += 0.07) {
        for (float phi = 0; phi < 2 * M_PI; phi += 0.02) {
            float costheta = cos(theta), sintheta = sin(theta);
            float cosphi = cos(phi), sinphi = sin(phi);
            float cosA = cos(A), sinA = sin(A);
            float cosB = cos(B), sinB = sin(B);

            float x = R2 + R1 * costheta;
            float y = R1 * sintheta;

            float x1 = x * (cosB * cosphi + sinA * sinB * sinphi) - y * cosA * sinB;
            float y1 = x * (sinB * cosphi - sinA * cosB * sinphi) + y * cosA * cosB;
            float z1 = K2 + cosA * x * sinphi + y * sinA;

            int xp = (int)(width / 2 + x1);
            int yp = (int)(height / 2 - y1 / 2);

            float L = cosphi * costheta * sinB - cosA * costheta * sinphi -
                      sinA * sintheta + sinB * (cosA * sintheta - costheta * sinA * sinphi);

            if (L > 0 && xp >= 0 && xp < width && yp >= 0 && yp < height) {
                int luminance_index = (int)(L * 8);
                if (luminance_index < 0) luminance_index = 0;
                if (luminance_index > 11) luminance_index = 11;
                display[yp][xp] = shades[luminance_index];
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(display[i][j]);
        }
        putchar('\n');
    }
}
