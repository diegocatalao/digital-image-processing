#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @def STATUS_NO_ERROR
 * @brief Indicates successful execution (no error).
 */
#define STATUS_NO_ERROR    0x00

/**
 * @def STATUS_INVALID_ARG
 * @brief Indicates an invalid argument was provided to a function.
 */
#define STATUS_INVALID_ARG 0x01

/**
 * @struct ppm_t
 * @brief Represents an image in the PPM (P3) format.
 *
 * Holds metadata and pixel data for a PPM image:
 * - format: Magic number (e.g., "P3")
 * - max: Maximum pixel intensity
 * - lines: Image height in pixels
 * - columns: Image width in pixels
 * - vector: Pointer to pixel data (row-major order)
 */
typedef struct {
  char format[2]; /**< Magic number (should be "P3") */
  int  max;       /**< Maximum color value */
  int  lines;     /**< Number of rows (image height) */
  int  columns;   /**< Number of columns (image width) */
  int* vector;    /**< Pixel data (R, G, B values as integers) */
} ppm_t;

int generate_random_sequence(int* array, int size, int max) {
  int status = STATUS_NO_ERROR;

  if (array == NULL) {
    printf("Invalid argument array (nil)");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  for (int i = 0; i < size; i++) {
    array[i] = (int)((double)rand() / ((double)RAND_MAX + 1) * (max + 1));
  }

clean_up:
  return status;
}

int write_ppm_random(int x, int y, int max, ppm_t* ppm_ptr) {
  int status = STATUS_NO_ERROR;
  int rnumber = 0;

  if (x <= 0) {
    printf("Invalid argument x (<=0)\n");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  if (y <= 0) {
    printf("Invalid argument y (<=0)\n");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  if (max <= 0) {
    printf("Invalid argument max (<=0)\n");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  if (ppm_ptr == NULL) {
    printf("Invalid argument ppm_ptr (nil)\n");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  ppm_ptr->lines = x;
  ppm_ptr->columns = y;
  ppm_ptr->max = max;

  for (int i = 0; i < y * x; i++) {
    rnumber = (int)((double)rand() / ((double)RAND_MAX + 1) * (max + 1));
    ppm_ptr->vector[i] = rnumber;
  }

clean_up:
  return status;
}

void ppm_printf(ppm_t* ppm_ptr) {
  printf("%d \n", ppm_ptr->vector[0]);
}

int write_ppm_file(char* filepath, ppm_t* ppm_ptr) {
  int status = STATUS_NO_ERROR;

  if (filepath == NULL) {
    printf("Invalid argument filepath (nil)\n");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  if (ppm_ptr == NULL) {
    printf("Invalid argument ppm_ptr (nil)\n");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

clean_up:
  return status;
}

int main(int argc, char** argv) {
  int status = STATUS_NO_ERROR;

  if (argc < 4) {
    printf("Usage: %s [filepath] [lines] [columns] [max]\n", argv[0]);
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  char* filepath = argv[1];
  int   lines = atoi(argv[2]);
  int   columns = atoi(argv[3]);
  int   max = atoi(argv[4]);

  ppm_t ppm;
  memset(&ppm, 0, sizeof(ppm_t));

  if (write_ppm_random(lines, columns, max, &ppm) != STATUS_NO_ERROR) {
    printf("The function write_ppm_random returns a bad status\n");
    goto clean_up;
  }

  if (write_ppm_file(filepath, &ppm) != STATUS_NO_ERROR) {
    printf("The function write_ppm_file returns a bad status\n");
    goto clean_up;
  }

  ppm_printf(&ppm);

clean_up:
  return status;
}
