#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**
 * @brief Reads a PPM image file and loads its contents into a ppm_t structure.
 *
 * Opens a PPM file in ASCII format (P3), parses the header and pixel data,
 * and stores the result in a dynamically allocated ppm_t structure.
 * Skips comment lines starting with '#'.
 *
 * @param filepath Path to the PPM file.
 * @param ppm_ptr Pointer to a ppm_t pointer to be allocated and filled.
 *               Must be NULL before calling.
 *
 * @return STATUS_NO_ERROR on success, STATUS_INVALID_ARG on failure.
 */
int read_ppm_file(char* filepath, ppm_t** ppm_ptr) {
  int status = STATUS_NO_ERROR;

  FILE*  fptr = NULL;
  char*  cursor = NULL;  // the current line
  size_t length = 0;     // the line length of current cursor

  if (filepath == NULL) {
    printf("Invalid filepath (nil)");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  if (*ppm_ptr != NULL) {
    printf("Invalid argument ppm_ptr (not nil)\n");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  if ((fptr = fopen(filepath, "r")) == NULL) {
    printf("Unable to open file %s\n", filepath);
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  *ppm_ptr = (ppm_t*)malloc(sizeof(ppm_t));
  memset(*ppm_ptr, 0, sizeof(ppm_t));

  // the first line is the version-format of this file
  getline(&cursor, &length, fptr);
  memcpy((*ppm_ptr)->format, cursor, length);

  // ignore all comments until the # ends
  while (getline(&cursor, &length, fptr) != -1) {
    if (cursor[0] != '#')
      break;
  }

  // get the width and height
  sscanf(cursor, "%d %d", &(*ppm_ptr)->columns, &(*ppm_ptr)->lines);

  // the max color of pixels represented by ascii chars (i'm not sure)
  getline(&cursor, &length, fptr);
  sscanf(cursor, "%d", &(*ppm_ptr)->max);

  // load all the payload into image content
  (*ppm_ptr)->vector = malloc((*ppm_ptr)->lines * (*ppm_ptr)->columns * sizeof(uint8_t));

  for (int i = 0; i < (*ppm_ptr)->lines * (*ppm_ptr)->columns; i++) {
    fscanf(fptr, "%d", &(*ppm_ptr)->vector[i]);
  }

clean_up:
  return status;
}

/**
 * @brief Lazy print ppm_t struct.
 *
 * Prints the ppm_t struct vector and no other information.
 */
void ppm_printf(ppm_t* ppm_ptr) {
  for (int i = 0; i < ppm_ptr->lines; i++) {
    printf("\n");
    for (int j = 0; j < ppm_ptr->lines; j++) {
      printf("%d ", ppm_ptr->vector[ppm_ptr->columns * i + j]);
    }
  }
}

int main(int argc, char** argv) {
  int    status = STATUS_NO_ERROR;
  ppm_t* ppm_ptr = NULL;

  if (argc < 2) {
    printf("Invalid input arguments.\n");
    printf("Usage:\t%s [input] [output]\n", argv[0]);

    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  if ((status = read_ppm_file(argv[1], &ppm_ptr)) != STATUS_NO_ERROR) {
    printf("An error ocurred when trying to parse PPM file\n");
    printf("Function read_ppm_file returned a status %d\n", status);
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  ppm_printf(ppm_ptr);

clean_up:
  if (ppm_ptr != NULL) {
    free(ppm_ptr);
  }

  return status;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
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
  int  max;       /**< Maximum color value */
  int  lines;     /**< Number of rows (image height) */
  int  columns;   /**< Number of columns (image width) */
  int* vector;    /**< Pixel data (R, G, B values as integers) */
} ppm_t;

/**
 * @brief Reads a PPM image file and loads its contents into a ppm_t structure.
 * Opens a PPM file in ASCII format (P3), parses the header and pixel data,
 * and stores the result in a dynamically allocated ppm_t structure.
 * Skips comment lines starting with '#'.
 *
 * @param filepath Path to the PPM file.
 * @param ppm_ptr Pointer to a ppm_t pointer to be allocated and filled.
 *
 * @return STATUS_NO_ERROR on success, STATUS_INVALID_ARG on failure.
 */
int read_ppm_file(char* filepath, ppm_t** ppm_ptr) {
  int status = STATUS_NO_ERROR;

  FILE*  fptr = NULL;
  char*  cursor = NULL;  // the current line

  if (filepath == NULL) {
    printf("Invalid filepath (nil)");
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

  if (*ppm_ptr != NULL) {
    printf("Invalid argument ppm_ptr (not nil)\n");
    goto clean_up;
  }

  if ((fptr = fopen(filepath, "r")) == NULL) {
    printf("Unable to open file %s\n", filepath);
    status = STATUS_INVALID_ARG;
    goto clean_up;
  }

