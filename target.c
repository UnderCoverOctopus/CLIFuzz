#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
double add(double num1, double num2);
double sub(double num1, double num2);
double mul(double num1, double num2);
double divi(double num1, double num2);
void equation_processor(char *operation, double num1, double num2);
void parse_args(int argc, char **argv);
void parse_input(char *input);

// Main function
int main(int argc, char **argv) {
    if (argc == 2) {
        // Read input from file
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("fopen");
            return 1;
        }

        char line[256];
        while (fgets(line, sizeof(line), file)) {
            parse_input(line);
        }

        fclose(file);
    } else if (argc == 4) {
        // Read input from command-line arguments
        parse_args(argc, argv);
    } else {
        fprintf(stderr, "Usage: %s <input_file> or %s <operation> <num1> <num2>\n", argv[0], argv[0]);
        return 1;
    }

    return 0;
}

// Function to parse arguments and call appropriate operation
void parse_args(int argc, char **argv) {
    char operation[10]; // Ensure this array is declared
    double num1 = atof(argv[2]);
    double num2 = atof(argv[3]);
    double result = 0; // Unused variable

    // Intentional bug: potential buffer overflow
    strcpy(operation, argv[1]);

    // Intentional bug: off-by-one error
    if (argv[4] != NULL) {
        printf("Accessing out-of-bounds index\n");
    }

    // Intentional bug: memory leak
    char *leak = (char *)malloc(100);
    strcpy(leak, "This memory is not freed");

    equation_processor(operation, num1, num2);
}

// Function to parse input from file and call appropriate operation
void parse_input(char *input) {
    char operation[10];
    double num1, num2;

    // Read operation and numbers from input
    if (sscanf(input, "%9s %lf %lf", operation, &num1, &num2) != 3) {
        fprintf(stderr, "Invalid input format\n");
        return;
    }

    equation_processor(operation, num1, num2);
}

// Function to process the equation and print the result if it's less than 10000
void equation_processor(char *operation, double num1, double num2) {
    double result = 0;

    if (strcmp(operation, "add") == 0) {
        result = add(num1, num2);
    } else if (strcmp(operation, "sub") == 0) {
        result = sub(num1, num2);
    } else if (strcmp(operation, "mul") == 0) {
        result = mul(num1, num2);
    } else if (strcmp(operation, "div") == 0) {
        result = divi(num1, num2);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        return;
    }

    printf("Result: %.2f\n", result);
    
}

// Addition function
double add(double num1, double num2) {
    return num1 + num2;
}

// Subtraction function
double sub(double num1, double num2) {
    return num1 - num2;
}

// Multiplication function
double mul(double num1, double num2) {
    return num1 * num2;
}

// Division function
double divi(double num1, double num2) {
    // Intentional bug: no check for division by zero
    return num1 / num2;
}