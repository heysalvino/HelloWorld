# Automated testing program, ver. 0.1
# DSM, 2023

import os
import sys

programs = ['greeting']
tests = ['random_greeting', 'personalized_greeting']

test_file_list = os.listdir('./tests')

num_passed = 0
final_return_code = 0

# Build the project
rc = os.system('make')
if rc != 0:
    print('Build failed. Exiting.')
    sys.exit(1)

num_passed += 1  # A working build is one of the tests

for program in programs:

    print('\n#####  Testing program %s  #####' % program)

    for test in tests:
        print('\n###  Test %s  ###' % test)
        out_file = test + '.out'
        in_file = test + '.in'
        cmp_file = './tests/' + test + '.cmp'

        if in_file in test_file_list:
            run_command = './%s < ./tests/%s > %s' % (program, in_file, out_file)
        else:
            run_command = './%s > %s' % (program, out_file)

        diff_cmd = 'diff -q %s %s' % (out_file, cmp_file)

        os.system(run_command)
        rc = os.system(diff_cmd)

        if rc == 0:
            print('Passed.')
            num_passed += 1
        else:
            final_return_code = 1  # Return 1 if any tests fail

        print('\nYour program\'s output:')
        os.system('cat %s' % out_file)
        print('\nExpected output:')
        os.system('cat %s' % cmp_file)

print('\n#####  Final Score  #####')
print('You passed %d out of %d tests.' % (num_passed, len(tests) + 1))
print('Percentage = %f' % (float(num_passed) / (len(tests) + 1)))

sys.exit(final_return_code)
