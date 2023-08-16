#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int red;
    int green;
    int blue;
} Pixel_Data;

typedef struct {
    Pixel_Data *data;
    int row;
    int col;
} PPM_Image_Buffer;

void filter_color_component(PPM_Image_Buffer *buf, unsigned int rgb_mask) {
    for (int i = 0; i < buf->row * buf->col; i++) {
        if (rgb_mask & 1) {
            buf->data[i].red = 0;
        }
        if (rgb_mask & 2) {
            buf->data[i].green = 0;
        }
        if (rgb_mask & 4) {
            buf->data[i].blue = 0;
        }
    }
}

int read_ppm_color_bitmap(char *filename, PPM_Image_Buffer *buf) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char format[3];
    int max_value;
    fscanf(file, "%2s\n", format);
    if (format[0] != 'P' || format[1] != '3') {
        fclose(file);
        return -1;
    }

    fscanf(file, "%d %d\n", &buf->col, &buf->row);
    fscanf(file, "%d\n", &max_value);

    buf->data = (Pixel_Data *)malloc(buf->row * buf->col * sizeof(Pixel_Data));
    if (buf->data == NULL) {
        fclose(file);
        return -1;
    }

    for (int i = 0; i < buf->row * buf->col; i++) {
        fscanf(file, "%d %d %d", &buf->data[i].red, &buf->data[i].green, &buf->data[i].blue);
    }

    fclose(file);
    return 0;
}

int write_ppm_color_bitmap(char *filename, PPM_Image_Buffer *buf) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", buf->col, buf->row);
    fprintf(file, "255\n");

    for (int i = 0; i < buf->row * buf->col; i++) {
        fprintf(file, "%d %d %d\n", buf->data[i].red, buf->data[i].green, buf->data[i].blue);
    }

    fclose(file);
    return 0;
}


int main() {
    PPM_Image_Buffer image_buffer;

    int read_result = read_ppm_color_bitmap("PPM.ppm", &image_buffer);
    if (read_result == -1) {
        printf("Error reading PPM file.\n");
        return 1;
    }

    // Извикване на функцията за филтриране на компонентите
    filter_color_component(&image_buffer, 3); // Нулиране на червената и зелената компонента

    int write_result = write_ppm_color_bitmap("output.ppm", &image_buffer);
    if (write_result == -1) {
        printf("Error writing PPM file.\n");
        return 1;
    }

    printf("PPM files read, filtered, and written successfully.\n");

    return 0;
}