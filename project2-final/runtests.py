# Testing script

import argparse
import filecmp
import os
import shutil
import subprocess

parser = argparse.ArgumentParser(description='Test all script for compilers')
parser.add_argument('-t', help='Specific test number to run instead of all tests', type=int)
parser.add_argument('-p', help='The program to run', default='../parser')
parser.add_argument('-td', help='The test directory', default='testCases')

args = parser.parse_args()


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'




def run_test(test_num):
    # Run a specific test number
    # Create test.in file
    shutil.copyfile(args.td + '/test' + str(test_num) + '_in', 'test.in')
    # Create test.expected file
    shutil.copyfile(args.td + '/test' + str(test_num) + '_out', 'test.expected')
    # Run the program
    subprocess.call(args.p + ' test.in > test.out 2>&1', shell=True)
    # Compare
    return filecmp.cmp('test.out', 'test.expected', False)


def print_test(test_num, result):
    if result:
        print bcolors.OKGREEN + "Test " + str(test_num) + " Passed" + bcolors.ENDC
    else:
        print bcolors.FAIL + "Test " + str(test_num) + " Failed" + bcolors.ENDC


# Run a specific test
if (args.t):
    passed = run_test(args.t)
    print_test(args.t, passed)
    exit(0)

# Run all tests
files = [f for f in os.listdir(args.td) if os.path.isfile(os.path.join(args.td, f))]
tests = {int(f[4:f.index('_')]) for f in files}


# Run tests
totalTests = 0
passedTests = 0
for test in tests:
    passed = run_test(test)
    print_test(test, passed)
    totalTests += 1
    passedTests += 1 if passed else 0

print
print
# Print summary
print 'SUMMARY'
print (bcolors.OKGREEN if passedTests == totalTests else bcolors.FAIL) + str(passedTests) + '/' + str(totalTests) + ' Tests Passed' + bcolors.ENDC
