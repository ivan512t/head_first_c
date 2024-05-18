#include <stdio.h>

#define INFO_SIZE 80

int main()
{
    float lat;
    float lon;
    char info[80];
    int started = 0;

    printf("[\n");
    while (scanf("%f,%f,%79[^\n]", &lat, &lon, info) == 3)
    {
        info[79] = '\0';

        if (started)
        {
            printf(",\n");
        }
        else
        {
            started = 1;
        }

        if (lat < -90 || lat > 90 || lon < -180 || lon > 180)
        {
            fprintf(stderr, "The coordinates lat: %f, lon: %f are out of range\n", lat, lon);
            return 2;
        }

        printf("    { \"latitude\": \"%f\", \"longitude\": \"%f\", \"info\": \"%s\" }", lat, lon, info);
    }

    if (!feof(stdin) && ferror(stdin))
    {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    puts("\n]");
    return 0;
}