# Automated Testing Program - Version 0.1

**Author:** DSM  
**Release Date:** 2017

## Description

This automated testing program is designed to test one or more programs against a set of test cases. It helps automate the process of testing and evaluating the correctness of your programs. The script compiles your project, runs it with various test cases, and compares the program's output to expected output.

## Prerequisites

Before using this testing program, ensure that you have the following prerequisites installed on your system:

- `make` utility for building the project.
- A list of programs you want to test. You can add them to the `programs` list.
- A list of test cases you want to use. You can add them to the `tests` list.
- Test input and expected output files. Place the test input files in the `./tests` directory and name them as 'programname_testname.in'. Place the expected output files in the same directory and name them as 'programname_testname.cmp'. For example, if you are testing a program called 'hello' with test case 'hello1', you should have 'hello_hello1.in' and 'hello_hello1.cmp' in the `./tests` directory.

## Usage

1. Open your terminal and navigate to the directory containing this testing program.
2. Execute the script by running the following command:

   ```
   python automated_testing.py
   ```

3. The script will perform the following steps:

   - Build the project using the `make` command.
   - Run each program against the specified test cases and compare the output to the expected output.
   - Display the results for each test case.
   - Calculate the final score and percentage of passed tests.

## Configuration

You can configure this testing program by editing the following variables in the script:

- `programs`: A list of program names you want to test.
- `tests`: A list of test case names you want to use.
- Test file location: By default, the script looks for test input and expected output files in the `./tests` directory. You can change this location by modifying the `test_file_list` variable.

## Test Results

After running the script, it will display the results for each test case, indicating whether the program passed or failed. It will also show the program's output and the expected output for comparison.

At the end of the testing process, the script will provide a final score, showing how many tests were passed out of the total tests. It will also calculate the percentage of tests passed.

## Exit Codes

The script returns exit code 0 if all tests pass successfully. If any test fails, it returns exit code 1, indicating that at least one test did not pass.

## Example Usage

Suppose you have a program named 'hello' and two test cases, 'hello1' and 'hello2'. You have the test input and expected output files in the `./tests` directory. You can run the testing program as described in the "Usage" section, and it will provide the test results.

## License

This testing program is provided under the MIT License. Feel free to modify and distribute it as needed, but please retain the original authorship information.

**Note:** This is a basic readme file for the automated testing program. You may need to customize it further based on your specific project and requirements.
