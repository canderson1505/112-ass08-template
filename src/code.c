//char *AUTHOR_NAME        = (char *) "Your Name";
//char *AUTHOR_AUTHORSHIP  = (char *) "I acknowledge that I have worked on this
// assignment independently, except where explicitly noted and referenced.
// Any collaboration or use of external resources has been properly cited.
// I am fully aware of the consequences of academic dishonesty and agree to
// abide by the university's academic integrity policy.";

// code.c — student implementation only
/* * code.c - Implementation file for Lab 8  */


#include "code.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * code.c - Assignment 8: File Access and Math Functions
 *
 * TODO: Include <stdio.h> (file functions), <stdlib.h> (abs),
 *       <math.h> (all other math functions) and your own "code.h".
 *
 * GENERAL RULES (apply to EVERY function below):
 *   - Check the arguments FIRST. If they are invalid, return false
 *     immediately, BEFORE calling fopen(), so the file is never touched.
 *   - Always check whether fopen() succeeded. If it did not, return false
 *     (or -1 for the functions that return int / long).
 *   - Always close every file you open, including on error paths
 *     that happen AFTER a successful fopen().
 *   - Text files: doubles are written as "%.2f\n", integers as "%d\n",
 *     one value per line.
 *   - Binary files: raw bytes only, no separators, no extra data.
 *   - Return true only if the write/read AND the close succeeded.
 *
 * OPTIONAL TIP: Many functions differ only in the math function and the
 * file mode. You may write small `static` helper functions (for example
 * "write one double as a text line using a given mode" and
 * "write an array of doubles as raw bytes using a given mode")
 * and reuse them. Helpers are not tested, and they do not go into code.h.
 */


/* ========================= PART A: Text mode ========================= */

/*
 * 1. create_abs_txt (returns bool; parameters: filename, int value)
 *    - Open the file for writing (it is created or overwritten).
 *    - Compute the absolute value of the integer with abs().
 *    - Write it as an integer followed by a newline.
 *    - Close the file and report success only if writing and closing worked.
 */
// TODO]
bool create_abs_txt (const char *filename, int value)
{
if (filename == NULL)
    return false;

     FILE *file = fopen(filename, "w"); 

    if (file == NULL) 

        return false; 

    int result = abs(value); 

    bool success = fprintf(file, "%d\n", result) >= 0; 

    if (fclose(file) != 0) 

        success = false; 

    return success; 

}

/*
 * 2. create_fabs_txt (returns bool; parameters: filename, double value)
 *    - Same idea as the previous function, but for a double:
 *      use fabs() and write with exactly two digits after the decimal point.
 *    - Open mode: write (create / overwrite).
 */
// TODO
bool create_fabs_txt(const char *filename, double value)
{

  if (filename == NULL) 

        return false; 

    FILE *file = fopen(filename, "w"); 

    if (file == NULL) 

        return false; 

    double abs_value = fabs(value); 

    bool success = fprintf(file, "%.2f\n", abs_value) >= 0; 

    if (fclose(file) != 0) 

        success = false; 

    return success;
}

/*
 * 3. append_sqrt_txt (returns bool; parameters: filename, double value)
 *    - Invalid input: negative value -> return false, do not touch the file.
 *    - Open the file in APPEND mode, so older content stays.
 *    - Write sqrt(value) as a new line with two decimal digits.
 *    - Close and report success.
 */
// TODO
bool append_sqrt_txt(const char *filename, double value)
{
if (filename == NULL || value < 0)
    
    return false;


    FILE *file = fopen(filename, "a");

        if (file == NULL)
        return false;


    bool success = fprintf(file, "%.2f\n", sqrt(value)) >= 0;
    
    if (fclose(file) != 0)
        success = false;

    return success;

}
/*
 * 4. append_pow_txt (returns bool; parameters: filename, double base, double exponent)
 *    - Invalid input: base equal to zero AND exponent negative
 *      (division by zero) -> return false, do not touch the file.
 *    - Open in APPEND mode, write pow(base, exponent) as a new line
 *      with two decimal digits, close, report success.
 */
// TODO
bool append_pow_txt(const char *filename, double base, double exponent)
{
    if (filename == NULL || (base == 0.0 && exponent < 0.0))
        return false;

    FILE *file = fopen(filename, "a");

        if (file == NULL)
            return false;

    bool success = fprintf(file, "%.2f\n", pow(base, exponent)) > 0;
    if (fclose(file) != 0)

        success = false;

        return success;
}
/*
 * 5. create_ceil_floor_txt (returns bool; parameters: filename, double value)
 *    - Open in WRITE mode (create / overwrite).
 *    - Write TWO lines: first ceil(value), then floor(value),
 *      both with two decimal digits.
 *    - Success requires that both writes AND the close worked.
 */
// TODO
bool create_ceil_floor_txt (const char *filename, double value)
{
    if (filename == NULL) 

        return false; 

    FILE *file = fopen(filename, "w"); 

    if (file == NULL) 

        return false; 

    bool success = fprintf(file, "%.2f\n%.2f\n", ceil(value), floor(value)) > 0; 

    if (fclose(file) != 0) 

        success = false; 

    return success; 

}

/*
 * 6. append_round_txt (returns bool; parameters: filename, double value)
 *    - Open in APPEND mode, write round(value) as a new line
 *      with two decimal digits, close, report success.
 *    - No invalid input exists for this function.
 */
// TODO
bool append_round_txt(const char *filename, double value)

{
  if (filename == NULL) 

        return false; 

    FILE *file = fopen(filename, "a"); 

    if (file == NULL) 

        return false; 

    bool success = fprintf(file, "%.2f\n", round(value)) >= 0; 

    if (fclose(file) != 0) 

        success = false; 

    return success; 

}
/*
 * 7. append_fmod_txt (returns bool; parameters: filename, double x, double y)
 *    - Invalid input: y equal to zero -> return false, do not touch the file.
 *    - Open in APPEND mode, write fmod(x, y) as a new line
 *      with two decimal digits, close, report success.
 */
// TODO
bool append_fmod_txt(const char *filename, double x, double y)
{

        if (filename == NULL)
            return false;

        if (y == 0)
            return false;

        FILE *file = fopen(filename, "a");
        
        if (file == NULL)
            return false;
 
        bool success = fprintf(file, "%.2f\n", fmod(x,y)) >= 0;

        if (fclose(file) != 0)
            success = false;


    return success;
}
/*
 * 8. load_txt_values (returns int; parameters: filename, double array, int max_count)
 *    - Open the file for reading. If it cannot be opened, return -1.
 *    - Keep a counter of values read, starting at 0.
 *    - Repeat while the counter is below max_count: read one number
 *      with the formatted-input function. Remember that a double needs
 *      the "long float" conversion specifier. The input function returns
 *      the number of items it successfully read; stop the loop when
 *      that is not exactly 1 (end of file or bad data).
 *    - Store each value into the next slot of the array and increase the counter.
 *    - Close the file and return the counter.
 */
// TODO
int load_txt_values(const char *filename, double array[], int max_count)
{
    if (filename == NULL || max_count < 0 || 

        (array == NULL && max_count > 0)) 

        return -1; 


    FILE *file = fopen(filename, "r"); 

    if (file == NULL) 

        return -1; 

    int count = 0; 


    while (count < max_count && 

           fscanf(file, "%lf", &array[count]) == 1) 

    { 
        count++; 
    } 

    fclose(file); 

    return count; 
}


/*
 * 9. clear_file (returns bool; parameters: filename)
 *    - Think: which open mode removes all existing content
 *      and creates the file when it does not exist?
 *    - You do not need to write anything. Just open and close.
 *    - Report success only if both the open and the close worked.
 */
// TODO
bool clear_file(const char *filename)
{
    if (filename == NULL)

    return false;


    FILE *file = fopen(filename, "w");
    
    if (file == NULL)
        return false;

    return fclose(file) == 0;

}


/* ========================= PART B: Binary mode ========================= */

/*
 * 10. create_abs_bin (returns bool; parameters: filename, int value)
 *     - Open in BINARY WRITE mode (create / overwrite).
 *     - Compute abs(value) and keep it in an int variable
 *       (you need its address to write it).
 *     - Write exactly ONE element whose size is the size of an int.
 *     - Success: fwrite reported 1 element written AND the close worked.
 */
// TODO

bool create_abs_bin(const char *filename, int value)
{
    if (filename == NULL)

    return false;

    FILE *file = fopen(filename, "wb");
   
    if (file == NULL)

    return false;


    int result = abs(value);

    bool success = fwrite(&result, sizeof(int), 1, file) == 1;

    if (fclose(file) != 0)
        success = false;

    return success;
}

/*
 * 11. create_fabs_bin (returns bool; parameters: filename, double value)
 *     - Same idea as above, but the stored value is a double (fabs of the input).
 *     - Open in BINARY WRITE mode.
 *     - Keep the result in a double variable and write ONE element
 *       of size sizeof(double).
 */
// TODO
bool create_fabs_bin(const char *filename, double value)
{
    if (filename == NULL)
    return false;

    FILE *file = fopen(filename, "wb");
    if (file == NULL)
        return false;

    double result = fabs(value);
    
    bool success = fwrite(&result, sizeof(double), 1, file) == 1;

    if (fclose(file) != 0)
        success = false;

    return success;

}

/*
 * 12. append_sqrt_bin (returns bool; parameters: filename, double value)
 *     - Invalid input: negative value -> return false BEFORE opening the file.
 *     - Open in BINARY APPEND mode, so older content stays.
 *     - Store sqrt(value) in a double variable and write ONE double.
 *     - Close and report success.
 */
// TODO
bool append_sqrt_bin(const char *filename, double value)
{
if (filename == NULL || value < 0) 

        return false; 

    FILE *file = fopen(filename, "ab"); 

    if (file == NULL) 

        return false; 


    double result = sqrt(value); 

    bool success = fwrite(&result, sizeof(double), 1, file) == 1; 

    if (fclose(file) != 0) 

        success = false; 

    return success;
}



/*
 * 13. append_pow_bin (returns bool; parameters: filename, double base, double exponent)
 *     - Invalid input: base equal to zero AND exponent negative
 *       -> return false, do not touch the file.
 *     - Open in BINARY APPEND mode, write pow(base, exponent) as ONE double,
 *       close, report success.
 */
// TODO
bool append_pow_bin(const char *filename, double base, double exponent)
{
    if (filename == NULL || (base == 0 && exponent < 0))
        return false;

    FILE *file = fopen(filename, "ab");
    if (file == NULL)
        return false;

    double result = pow(base, exponent);
    
    bool success = fwrite(&result, sizeof(double), 1, file) == 1;

    if (fclose(file) != 0)
        success = false;

    return success;

}


/*
 * 14. create_ceil_floor_bin (returns bool; parameters: filename, double value)
 *     - Open in BINARY WRITE mode (create / overwrite).
 *     - Write TWO doubles: first ceil(value), then floor(value).
 *     - Hint: put both results in a small double array of size 2
 *       and write both elements with a SINGLE write call
 *       (count = 2), or use two separate calls.
 *     - Success requires that all writes AND the close worked.
 */
// TODO
bool create_ceil_floor_bin(const char *filename, double value)
 {
    if (filename == NULL) 

        return false; 
   
        FILE *file = fopen(filename, "wb"); 

    if (file == NULL) 

        return false; 

    double results[2] = {ceil(value), floor(value)}; 

    bool success = fwrite(results, sizeof(double), 2, file) == 2; 

     if (fclose(file) != 0) 

        success = false; 

    return success; 

}
/*
 * 15. append_round_bin (returns bool; parameters: filename, double value)
 *     - Open in BINARY APPEND mode, write round(value) as ONE double,
 *       close, report success.
 *     - No invalid input exists for this function.
 */
// TODO
bool append_round_bin(const char *filename, double value)
{

    if (filename == NULL)
        return false;

    FILE *file = fopen(filename, "ab");

    if (file == NULL)
        return false;

    double result = round(value);

    bool success = fwrite(&result, sizeof(double), 1, file) == 1;

    if (fclose(file) != 0)
        success = false;

    return success;
}


 /* 16. append_fmod_bin (returns bool; parameters: filename, double x, double y)
 *     - Invalid input: y equal to zero -> return false, do not touch the file.
 *     - Open in BINARY APPEND mode, write fmod(x, y) as ONE double,
 *       close, report success.
 */
// TODO
bool append_fmod_bin (const char *filename, double x, double y)
{
  if (filename == NULL || y == 0) 

        return false; 

    FILE *file = fopen(filename, "ab"); 

    if (file == NULL) 

        return false; 

    double result = fmod(x, y); 

    bool success = fwrite(&result, sizeof(double), 1, file) == 1; 

 
    if (fclose(file) != 0) 

        success = false; 

    return success; 

}

/*
 * 17. load_abs_bin (returns bool; parameters: filename, int pointer out)
 *     - Open in BINARY READ mode. If it cannot be opened, return false.
 *     - Read ONE element of size sizeof(int) directly into *out
 *       (the pointer already holds the address, so do not use & here).
 *     - Close the file (always, also when the read failed).
 *     - Return true only if exactly 1 element was read.
 *       A file that is too short makes the read function return 0.
 */
// TODO
bool load_abs_bin (const char *filename, int *out)
{
 if (filename == NULL || out == NULL) 
        return false; 

    FILE *file = fopen(filename, "rb"); 

    if (file == NULL) 
        return false; 

  bool success = fread(out, sizeof(int), 1, file) == 1; 

    if (fclose(file) != 0) 
         success = false; 

     return success;
}
/*
 * 18. load_bin_values (returns int; parameters: filename, double array, int max_count)
 *     - Open in BINARY READ mode. If it cannot be opened, return -1.
 *     - Keep a counter starting at 0.
 *     - Repeat while the counter is below max_count: read ONE double
 *       into the next array slot. Stop the loop when the read function
 *       does not return 1 (end of file).
 *     - Increase the counter after every successful read.
 *     - Close the file and return the counter.
 */
// TODO
int load_bin_values(const char *filename, double *arr, int max_count)
{
    if (filename == NULL || max_count < 0 || (arr == NULL && max_count > 0))
        return -1;

    FILE *file = fopen(filename, "rb");
    if (file == NULL)
        return -1;

        int count = 0;

    while (count < max_count && fread(&arr[count], sizeof(double), 1, file) == 1)
    {
        count++;

    }

    fclose(file);
    
    return count;
}



/*
 * 19. load_bin_value_at (returns bool; parameters: filename, int index, double pointer out)
 *     - Invalid input: negative index -> return false BEFORE opening the file.
 *     - Open in BINARY READ mode. If it cannot be opened, return false.
 *     - Calculate the byte offset: index multiplied by the size of a double.
 *       Convert it to long to match the type expected by the seek function.
 *     - Jump there from the BEGINNING of the file.
 *       If the seek fails, close the file and return false.
 *     - Read ONE double into *out. Close the file.
 *     - Return true only if exactly 1 element was read
 *       (a file that is too short gives 0).
 */
// TODO
bool load_bin_value_at(const char *filename, int index, double *out)
{
 if (filename == NULL || index < 0 || out == NULL) 

        return false; 

    FILE *file = fopen(filename, "rb"); 

    if (file == NULL) 

        return false; 

    long offset = (long)index * (long)sizeof(double); 

    if (fseek(file, offset, SEEK_SET) != 0) 

    { 
        fclose(file); 

        return false; 
    } 

    bool success = fread(out, sizeof(double), 1, file) == 1; 

    if (fclose(file) != 0) 

        success = false; 

    return success;
}
/*
 * 20. get_file_size (returns long; parameters: filename)
 *     - Open in BINARY READ mode. If it cannot be opened, return -1.
 *     - Jump to the END of the file (offset 0, origin = end).
 *       If the seek fails, close the file and return -1.
 *     - Ask for the current position: at the end of the file it equals
 *       the size in bytes. Store it in a long variable.
 *     - Close the file and return the stored size.
 */
// TODO
long get_file_size(const char *filename)
{
  if (filename == NULL) 

        return -1; 

    FILE *file = fopen(filename, "rb"); 

    if (file == NULL) 

        return -1; 

    if (fseek(file, 0, SEEK_END) != 0) 

    { 
        fclose(file); 

        return -1; 
    } 

    long size = ftell(file); 

    if (fclose(file) != 0) 

        return -1; 

    return size;
}